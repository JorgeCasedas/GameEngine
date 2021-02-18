
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

#include <string>

namespace engine
{
	using namespace std;

	///
	/// Base class for creating messages
	///
	class Message
	{
		string messageEvent;

	public:
		Message(string event);
		~Message();
		string getEvent();
	};
}