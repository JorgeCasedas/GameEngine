
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

#include "InputTask.hpp"
#include <Keyboard.hpp>
#include <MessageBus.hpp>
#include <Message.hpp>
#include <SDL.h>

namespace engine
{
	InputTask::InputTask(MessageBus* bus)
	{
		messageBus = bus;
	}

	void InputTask::Update()
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_A])
		{
			messageBus->AddMessage(new Message("a"));
		}
		if (state[SDL_SCANCODE_D])
		{
			messageBus->AddMessage(new Message("d"));
		}
		if (state[SDL_SCANCODE_W])
		{
			messageBus->AddMessage(new Message("w"));
		}
		if (state[SDL_SCANCODE_S])
		{
			messageBus->AddMessage(new Message("s"));
		}

	/*	SDL_Event sdlEvent;
		if (SDL_PollEvent(&sdlEvent) > 0)
		{
			if (sdlEvent.type == SDL_EventType::)
			{
				if (keyboard->translate_sdl_key_code(sdlEvent.key.keysym.sym) == Keyboard::Key_Code::KEY_A)
					messageBus->AddMessage(new Message("a"));
				if (keyboard->translate_sdl_key_code(sdlEvent.key.keysym.sym) == Keyboard::Key_Code::KEY_D)
					messageBus->AddMessage(new Message("d"));
			}
				
			
		}*/
	}

}

