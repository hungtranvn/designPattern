/*!
  \file   logging_Acceptor.cpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/

#include "logging_Acceptor.hpp"

namespace reactor {

	logging_Acceptor::logging_Acceptor(int port) : acceptor_ (port) { 
		//Registre el aceptador con el Despachador de Iniciación, que "despacha doblemente" 
		//el método Logging_Acceptor::get_handle() para obtener el método HANDLE. 
		initiation_Dispatcher::instance () -> register_Handler (this, ACCEPT_EVENT);

	}

	void logging_Acceptor::handle_Event (int et) { 
		if (!(et & ACCEPT_EVENT)) {
			LOG("logging acceptor must be ACCEPT_EVENT");
			return;
		}

		net::SockStream new_connection;
		if (acceptor_.accept_sock(new_connection) == -1) {
			LOG("accept error");
			return;
		}

		LOG("client %d is comming", new_connection.get_handle());
		// Create a new Logging Handler. 
		logging_Handler *handler = new logging_Handler(new_connection);
	}
}