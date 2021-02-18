
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
namespace engine
{

	class Entity;
	
	///
	/// Base class for components used on entities
	///
	class Component
	{
	protected:
		Entity* linkedEntity;
	public:
		///
		/// Constructor
		///
		Component();
		///
		/// Set the entity this component is attached to
		///
		void SetEntity(Entity* entity);
		///
		/// Update overridable method
		///
		virtual void Update();
	};
}