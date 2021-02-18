
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
	class MessageBus;

	///
	/// Task in charge of detecting key board inputs and sending this inputs as messages to the message bus
	///
	class InputTask
	{
		MessageBus* messageBus;
	public:
		InputTask(MessageBus* bus);

		void Update();
	};
}