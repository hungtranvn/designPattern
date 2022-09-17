/*!
  \file   logging_Handler.cpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/

#include "logging_Handler.hpp"

namespace reactor {

	logging_Handler::logging_Handler (net::SockStream &cs) : peer_stream_ (cs) {

		// Registrar con el despachador para eventos READ.
		initiation_Dispatcher::instance ()-> register_Handler (this, READ_EVENT);
	    //register_handler (this, ACCEPT_EVENT);
	}

	void logging_Handler::handle_Event(int et) {
		LOG("handl event,type: %d", et);
		if (et == READ_EVENT) {
			LOG("client %d's  message is comming", peer_stream_.get_handle());
			int count = peer_stream_.recv_stream();
			if (count == 0)
				handle_Event(CLOSE_EVENT);
		} 
		else if (et == CLOSE_EVENT) {
			LOG("client close");
			initiation_Dispatcher::instance()->remove_Handler(this, READ_EVENT);
			//peer_stream_.close_stream();
		}
	}
}
