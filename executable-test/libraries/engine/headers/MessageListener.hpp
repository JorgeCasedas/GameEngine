
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

#pragma once

namespace engine
{
	class Message;
	class MessageBus;

	///
	/// Base class for creating objects that will be waiting for messages
	///
	class MessageListener
	{

		MessageBus* messageBus;

	public:
		MessageListener(MessageBus& bus);
		
		virtual void UseMessage(Message* message);
	};
}