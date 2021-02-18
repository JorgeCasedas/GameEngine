
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

#include "MessageBus.hpp"
#include "Message.hpp"
#include "MessageListener.hpp"

namespace engine
{
	MessageBus::MessageBus()
	{
	}
	void MessageBus::AddMessage(Message* message)
	{
		messages.push(message);
	}
	void MessageBus::AddListener(MessageListener* listener)
	{
		listeners.push_back(listener);
	}
	void MessageBus::SendToListeners()
	{
		while (!messages.empty())
		{
			for (int i = 0; i < listeners.size(); i++)
			{
				listeners[0]->UseMessage(messages.front());
			}
			messages.pop();
		}
	}
}
