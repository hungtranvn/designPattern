/*!
  \file   initiation_Dispatcher.hpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/
 
#ifndef __INITIATION_DISPATCHER_HPP__
#define __INITIATION_DISPATCHER_HPP__

#include <sys/select.h>

#include <stdint.h>
#include <map>

#include "event_Handler.hpp"
#include "log.hpp"


namespace reactor{

	//Tipos de eventos manejados por el Initiation_Dispatcher. 
	//Estos valores son potencias de dos, por lo que sus bits pueden ser eficientemente "or'd'" 
	//juntos para formar valores compuestos
	enum EventType {
		ACCEPT_EVENT = 01,
		READ_EVENT = 02,
		WRITE_EVENT = 04,
		TIMEOUT_EVENT = 010,
		SIGNAL_EVENT = 020,
		CLOSE_EVENT = 040
	};

	class event_Handler;
	/*****************************
	 * Demultiplex and dispatch 
	 * Event_Handlers.
	 */

	//!  Demultiplex y envío de Event_Handlers en respuesta a las peticiones del cliente.

	class initiation_Dispatcher {

		public:
			struct EventInfo {

				event_Handler* handler_;

				int event_Types_;

				public:
					EventInfo(event_Handler* _handler, int _types) : handler_(_handler) {
						event_Types_ = static_cast<int>(_types);
					}
			};

			typedef std::map<int, EventInfo> EventMap;
			typedef std::map<int, EventInfo>::iterator EventMapIter;
			typedef std::pair<int, EventInfo> EventPair;

			static initiation_Dispatcher* instance();

			/*!         
			    \fn     int register_Handler(Event_Handler *eh, int et)
			    \brief  Registrar un Event_Handler de un Event_Type en particular.
			    \param  *eh Event handler
			    \param  et Event Type
			    \return int
			*/
			int register_Handler(event_Handler *eh, int et);

			/*!         
			    \fn     int remove_Hander(Event_Handler *eh, int et)
			    \brief  Eliminar un Event_Handler de un Event_Type en particular.
			    \param  *eh Event handler
			    \param  et Event Type
			    \return int
			*/
			int remove_Handler(event_Handler *eh, int et);

			/*!         
			    \fn     int handle_events(int _timeout = 0)
			    \brief  Punto de entrada en el bucle de eventos reactivos.
			    \param  *timeout Time out
			    \return int
			*/
			int handle_Events(int _timeout = 0); 
		
		private:
			initiation_Dispatcher();
			static initiation_Dispatcher *instance_;
			int fd_max_;
			// event map and fd sets of select
			EventMap event_map_;
			fd_set read_fds_;

	};
}
#endif