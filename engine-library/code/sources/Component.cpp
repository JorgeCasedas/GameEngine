
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

#include "..\headers\Component.hpp"

namespace engine
{

	Component::Component()
	{
		linkedEntity = nullptr;
	}
	void Component::SetEntity(Entity* entity)
	{
		linkedEntity = entity;
	}
	void Component::Update()
	{
	}
}

