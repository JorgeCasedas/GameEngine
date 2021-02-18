
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

#include <queue>

namespace engine
{
	
	class Message;
	class MessageListener;

	using namespace std;

	///
	/// Manager of the messaging system
	///
	class MessageBus
	{
		vector<MessageListener*> listeners;
		queue<Message*> messages;

	public:

		MessageBus();

		void AddMessage(Message* message);
		///
		/// Add an object that will be taken in count when checking the messages recieved
		///
		void AddListener(MessageListener* listener);
		///
		/// Send the messages recieved to all listeners so they can manage them
		///
		void SendToListeners();

	};
}