
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

#include "Kernel.hpp"
#include "EntityTask.hpp"
#include "RenderTask.hpp"
#include "InputTask.hpp"
#include "MessageBus.hpp"

namespace engine 
{
	Kernel::Kernel( EntityTask* _entityTask, RenderTask* _renderTask, InputTask* _inputTask, MessageBus* _messageBus)
	{
		entityTask = _entityTask;
		renderTask = _renderTask;
		inputTask = _inputTask;
		messageBus = _messageBus;
	}
	void Kernel::Update()
	{
		inputTask->Update();
		entityTask->Update();

		messageBus->SendToListeners();

		renderTask->Update();
	}
}

