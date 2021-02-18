
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

#include "EntityTask.hpp"
#include "Entity.hpp"

namespace engine 
{
	EntityTask::EntityTask()
	{
	}

	void EntityTask::Update()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update();
		}
	}
	void EntityTask::AddEntity(Entity* entity)
	{
		entities.push_back(entity);
	}
}

