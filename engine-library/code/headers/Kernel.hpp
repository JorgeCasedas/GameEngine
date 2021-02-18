
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
	class EntityTask;
	class RenderTask;
	class InputTask;
	class MessageBus;

	///
	/// Class in charge of managing all the tasks
	///
	class Kernel
	{

		EntityTask* entityTask;
		RenderTask* renderTask;
		InputTask* inputTask;
		MessageBus* messageBus;

	public:

		Kernel(EntityTask* _entityTask, RenderTask* _renderTask, InputTask* _inputTask, MessageBus* _messageBus);
		void Update();

	};
}
