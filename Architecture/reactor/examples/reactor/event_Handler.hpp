/*!
  \file   event_Handler.hpp
  \brief   
  \author Francisco Jesus Arcos Romero
  \date   21/06/2018
*/
 
#ifndef __EVENT_HANDLER_HPP__
#define __EVENT_HANDLER_HPP__

#include "initiation_Dispatcher.hpp"

//!  Clase base abstracta que sirve como objetivo del Initiation_Dispatcher. 

namespace reactor {

	class event_Handler {

		public:
			/*!         
			    \fn     virtual void handle_event (int et) = 0;
			    \brief  Método de enganche que es llamado de nuevo por el Initiation_Dispatcher para manejar eventos.
			    \param  g referencia de la clase GraphMatrix
			    \param  origen referencia de tipo entero para indicar el comienzo de la busqueda
			    \return Nada
			*/
			virtual void handle_Event (int et) = 0;

			/*!
			    \fn     virtual int get_handle (void) const = 0;
			    \brief  Método de gancho que devuelve el mango de E/S subyacente.
			    \param  g referencia de la clase GraphMatrix
			    \param  origen referencia de tipo entero para indicar el comienzo de la busqueda
			    \return Nada
			*/
			virtual int get_Handle (void) const = 0;

			// C++ abstract base class illustrates the multi- method interface:
			// Hook methods that are called back by the Initiation 
			// Dispatcher to handle particular types of events. 
			//virtual int handle_accept (void) = 0;
			//virtual int handle_input (void) = 0;
			//virtual int handle_output (void) = 0;
			//virtual int handle_timeout (void) = 0;
			//virtual int handle_close (void) = 0;
			// Hook method that returns the underlying // I/O Handle.
			//virtual Handle get_handle (void) const = 0;

	};
}
#endif