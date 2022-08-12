/*!
  \file   initiation_Dispatcher.cpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/
 
#include "initiation_Dispatcher.hpp"

#define MAX(a, b) ((a) < (b) ? (b):(a))

namespace reactor{

	initiation_Dispatcher* initiation_Dispatcher::instance_ = 0;

	initiation_Dispatcher::initiation_Dispatcher() : fd_max_(0) {
		event_map_.clear();
		FD_ZERO(&read_fds_);
	}

	int initiation_Dispatcher::register_Handler(event_Handler *_event_handler, int et) {

		if (!_event_handler) {
			LOG("_event_handler is NULL");
			return -1;
		}

		int handle = _event_handler->get_Handle();

		EventMapIter iter = event_map_.find(handle);

		if (iter == event_map_.end()) {
			LOG("handle:%d, insert map", handle);
			event_map_.insert(EventPair(handle, EventInfo(_event_handler, et)));
		} 
		else {
	    	iter->second.event_Types_ |= et;
	  	}
	  
	  	if (et & ACCEPT_EVENT || et & READ_EVENT) {
	    	LOG("handle:%d, fd_set handle", handle);
	    	FD_SET(handle, &read_fds_);
	    	fd_max_ = MAX(handle, fd_max_);
	  	}

	  	LOG("handle:%d added,handle count:%d.", handle, event_map_.size());

	  	return 0;
	}

	int initiation_Dispatcher::remove_Handler(event_Handler *_event_handler, int et) {

		if (!_event_handler){
			LOG("_event_handler is NULL");
			return -1;
		}

		int handle = _event_handler->get_Handle();

		EventMapIter iter = event_map_.find(handle);

		if (iter == event_map_.end()){
			LOG("no such event, event type:%d", et);
			return -1;
		}

		// clear bit 
		iter->second.event_Types_ &= ~et;

		// remove from map if it has no more types
		if (iter->second.event_Types_ == 0) {
			delete iter->second.handler_;
			event_map_.erase(iter);
			LOG("remove from event map,handle count:%d.", event_map_.size());
		}

		// remove from read_fds_
		if (et & READ_EVENT || et & ACCEPT_EVENT)
			FD_CLR(handle, &read_fds_);

		return 0;
	}

	int initiation_Dispatcher::handle_Events(int _timeout) {
		struct timeval tv;
		struct timeval *ptv = _timeout ? &tv : NULL;
		tv.tv_sec = _timeout;

		fd_set old_set = read_fds_;
		int trigger_cnt = 0;

		if ((trigger_cnt = select(fd_max_ + 1, &old_set, NULL, NULL, ptv)) == -1) {
			LOG("select failed");
			perror("select");
			return -1;
		}

		LOG("trigger cnt:%d", trigger_cnt);

		for (int i = 0; i <= fd_max_; i++) {
			if (FD_ISSET(i, &old_set)) {
				EventMapIter iter = event_map_.find(i);
				if (iter == event_map_.end()) {
					LOG("fd doesn't corresponding to event map");
					return -1;
				}
			event_Handler* event_handler = iter->second.handler_;
			event_handler->handle_Event(iter->second.event_Types_);
			}
		}				
		return 0;
	}

	initiation_Dispatcher* initiation_Dispatcher::instance() {
		if (instance_ == 0)
			instance_ = new initiation_Dispatcher();
		
		return instance_;
	}

}