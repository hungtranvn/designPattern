/*!
  \file   logging_Handler.hpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/
 
#ifndef __LOGGING_HANDLER_HPP__
#define __LOGGING_HANDLER_HPP__

#include "log.hpp"
#include "event_Handler.hpp"
#include "net.hpp"

namespace reactor {

	//!  Recibir y procesar registros de registro enviados por una aplicación cliente.

	class logging_Handler : public event_Handler {
		
		private:
	        // Recibe registros de registro de un cliente. 
	        net::SockStream peer_stream_;

		public:
			~logging_Handler();
			/*!         
			    \fn     logging_Handler (net::SockStream &);;
			    \brief  Inicializar el flujo del cliente.
			    \param  &cs SOCK_Stream
			*/
			logging_Handler (net::SockStream &);
			
			/*!         
			    \fn     virtual void handle_event (int et);
			    \brief  Método por defecto que maneja la recepción de los registros de registro de los clientes.
			    \param  et int
			*/
			virtual void handle_Event (int et);

			/*!         
			    \fn     virtual int get_handle () const
			    \brief  Obtener el Manejador de E/S.
				\return HANDLE
			*/
			virtual int get_Handle () const {
				return this->peer_stream_.get_handle ();
			} 
	};

}
#endif