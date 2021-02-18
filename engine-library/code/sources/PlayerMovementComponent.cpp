
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

#include "PlayerMovementComponent.hpp"
#include <MessageBus.hpp>
#include <Message.hpp>
#include <Entity.hpp>

#include <SFML/Audio.hpp>

namespace engine 
{
	using namespace sf;

	PlayerMovementComponent::PlayerMovementComponent(MessageBus& bus, float _speed, string _soundFile):MessageListener(bus), Component()
	{
		speed = _speed;
		fLimit = 0;
		bLimit = 0;
		rLimit = 0;
		lLimit = 0;
		soundFile = _soundFile;
	}

	void PlayerMovementComponent::UseMessage(Message* message)
	{
		if(linkedEntity!=nullptr)
			if (message->getEvent() == "w")
			{
				Forward();
			}
			else if(message->getEvent() == "d")
			{
				Right();
			}
			else if (message->getEvent() == "s")
			{
				BackWards();
			}
			else if (message->getEvent() == "a")
			{
				Left();
			}
	}

	void PlayerMovementComponent::SetMovementLimits(float forward, float backwards, float right, float left)
	{
		fLimit = forward;
		bLimit = backwards;
		rLimit = right;
		lLimit = left;
	}

	void PlayerMovementComponent::Forward()
	{
		float movement = -0.01f * speed;
		if(OutOfLimits(Direction::Forward, movement))
			linkedEntity->Translate(0.f, 0.f, movement);
	}

	void PlayerMovementComponent::BackWards()
	{
		float movement = 0.01f * speed;
		if (OutOfLimits(Direction::Backwards, movement))
			linkedEntity->Translate(0.f, 0.f, movement);
	}

	void PlayerMovementComponent::Right()
	{
		float movement = 0.01f * speed;
		if (OutOfLimits(Direction::Right, movement))
			linkedEntity->Translate(movement, 0.f, 0.f);
	}

	void PlayerMovementComponent::Left()
	{
		float movement = -0.01f * speed;
		if (OutOfLimits(Direction::Left, movement))
			linkedEntity->Translate(movement, 0.f, 0.f);
	}

	bool PlayerMovementComponent::OutOfLimits(Direction dir, float movement)
	{
		float x;
		float y;
		float z;
		linkedEntity->GetPosition(x, y, z);

		if (dir == Direction::Forward)
		{
			if (fLimit > z + movement)
			{
				return false;
				PlayAudio();
			}
		}
		else if (dir == Direction::Backwards)
		{
			if (bLimit < z + movement)
			{
				return false;
				PlayAudio();
			}
		}
		else if (dir == Direction::Right)
		{
			if (rLimit < x + movement)
			{
				return false;
				PlayAudio();
			}
		}
		else if (dir == Direction::Left)
		{
			if (lLimit > x + movement)
			{
				return false;
				PlayAudio();
			}
		}
		
		return true;
	}

	void PlayerMovementComponent::PlayAudio()
	{
		//This part is commented because i havent been able to use SFML audio lib when building for the demo project, a lot of LNK2019 errors popped up, and I havent been able to solve them

	/*	SoundBuffer buffer;
		if (buffer.loadFromFile(soundFile))
		{
			Sound sound;
			sound.setBuffer(buffer);
			sound.play();
		}*/
	}

}
