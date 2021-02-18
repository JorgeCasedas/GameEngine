
/**********************************************************************
*Project           : EngineTask
*
*Author : Jorge Cásedas
*
*Starting date : 24/06/2020
*
*Ending date : 03/07/2020
*
*Purpose : Creating a 3D engine that can be used later on for developing a playable demo, with the engine as static library
*
**********************************************************************/

#include "Message.hpp"

namespace engine
{
	Message::Message(string message)
	{
		messageEvent = message;
	}
	Message::~Message()
	{
	}
	string Message::getEvent()
	{
		return messageEvent;
	}
}

