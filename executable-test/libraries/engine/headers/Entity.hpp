
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
#include <vector>

namespace engine 
{
	class Transform;
	class GraphicsComponent;
	class Level;
	class EntityTask;
	class Component;

	using namespace std;
	///
	/// Class used for making entities
	///
	class Entity
	{
		Transform* transform;
		GraphicsComponent* gfx;

		Level* level;
		///
		/// Vector that contains all non-essential components
		///
		vector<Component*> components;

		vector <Entity*> children;
		Entity* parent;

	public:
		///
		/// Constructor
		///
		Entity(const std::string& EntityName, Level& level, const std::string& obj_file_path, EntityTask& task);

		void Update();

		void SetScale(float x, float y, float z);

		void Translate(float x, float y, float z);
		void SetPosition(float x, float y, float z);
		void GetPosition(float& x, float& y, float& z);
		///
		/// Add Component to vector of components
		///
		void AddComponent(Component* comp);

		void AddChild(Entity& child);
		void RemoveChild(Entity& child);
		void SetParent(Entity& _parent);
		///
		/// Set parent as null
		///
		void UnSetParent();
	};
}

