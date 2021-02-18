
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
#include <vector>

namespace engine 
{
	class Entity;

	using namespace std;

	///
	/// Task in charge of updating all the entities created
	///
	class EntityTask
	{

		vector<Entity*> entities;

	public:
		EntityTask();
		void Update();
		void AddEntity(Entity* entity);
	};
}
