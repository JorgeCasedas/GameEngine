
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
#include <MessageListener.hpp>
#include <Component.hpp>
#include <string>

using namespace std;

namespace engine
{
	// I have to use the include above instead the forward declaration for inheritance
	//class MessageListener;

	class Entity;

	///
	/// Component made as a simple in game object control by keyboard inputs, it is attached to Entity classes
	///
	class PlayerMovementComponent : public MessageListener, public Component
	{
		float speed;

		///
		/// Forward limit
		///
		float fLimit;
		///
		/// Backwards limit
		///
		float bLimit;
		///
		/// Right limit
		///
		float rLimit;
		///
		/// Left limit
		///
		float lLimit;
		///
		/// Path to the audio clip that will be played
		///
		string soundFile;

		enum class Direction
		{
			Right,
			Left,
			Backwards,
			Forward
		};

	public:
		PlayerMovementComponent(MessageBus& bus, float _speed, string _soundFile);
		void UseMessage(Message* message) override;
		///
		/// Set the limits coordinates for the entity movement
		///
		void SetMovementLimits(float forward, float backwards, float right, float left);

	private:
		///
		/// Move forward
		///
		void Forward();
		///
		/// Move backwards
		///
		void BackWards();
		///
		/// Move right
		///
		void Right();
		///
		/// Move left
		///
		void Left();
		///
		/// Check if the entity is trying to move out of the given limits
		///
		bool OutOfLimits(Direction dir, float movement);
		///
		/// Play an audio clip, this part is commented because i havent been able to use SFML audio lib when building for the demo project, a lot of LNK2019 errors popped up, and I havent been able to solve them
		///
		void PlayAudio();
		
	};
}