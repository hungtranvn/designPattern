/*!
  \file   logging_Acceptor.hpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/
 
#ifndef __LOGGING_ACCEPTOR_HPP__
#define __LOGGING_ACCEPTOR_HPP__

#include "net.hpp"
#include "event_Handler.hpp"
#include "logging_Handler.hpp"
#include "log.hpp"

namespace reactor{

	//!  Maneja las solicitudes de conexión de los clientes.

	class logging_Acceptor : public event_Handler{
		
		private:
			//Socket que acepta conexiones de clientes.
			net::SockAcceptor acceptor_;
			~logging_Acceptor();
			
		public:

			/*!         
			    \fn     Logging_Acceptor (const int port);
			    \brief  Inicializa el punto final acceptor_ y regístrese con el Initiation_Dispatcher. 
			    \param  port puerto de conexión
			*/
			logging_Acceptor (const int port);
			
			/*!         
			    \fn     virtual void handle_event (int et);
			    \brief  Método por defecto que acepta una nueva conexión SOCK_Stream y +
			   			crea un objeto Logging_Handler para manejar los registros de 
			   			registro enviados a través de la conexión. 
			    \param  et int
			*/
			virtual void handle_Event (int et);

			/*!         
			    \fn     virtual int get_handle (void) const
			    \brief  Obtener el Manejador de E/S.
				\return HANDLE
			*/
			virtual int get_Handle (void) const {
				return acceptor_.get_handle ();
			} 
	};

}
#endif