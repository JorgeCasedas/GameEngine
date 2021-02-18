
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

#include "Entity.hpp"
#include "Transform.hpp"
#include "GraphicsComponent.hpp"
#include "Level.hpp"
#include "EntityTask.hpp"
#include "Component.hpp"
#include <string>

namespace engine 
{

	Entity::Entity(const std::string& EntityName, Level& _level, const std::string& obj_file_path, EntityTask& task)
	{
		task.AddEntity(this);
		level = &_level;
		transform = new Transform();
		gfx = new GraphicsComponent(EntityName, _level, obj_file_path, *transform);

		_level.levelEntities.push_back(this); //Save entity in a vector for final shrink animation

		parent = nullptr;
	}

	void Entity::Update()
	{
		float x;
		float y;
		float z;

		float xSize;
		float ySize;
		float zSize;

		transform->GetLastTransformation(x, y, z);
		transform->GetScale(xSize, ySize, zSize);
		
		gfx->Update(x/xSize, y/ySize, z/zSize);

		for (int i = 0; i < children.size(); i++)
		{
			children[i]->Translate(x, y, z);
			children[i]->Update();
		}

		for (int i = 0; i < components.size(); i++)
		{
			components[i]->Update();
		}
	}

	void Entity::SetScale(float x, float y, float z)
	{
		transform->SetScale(x, y, z);
		gfx->Scale(x, y, z);
	}

	void Entity::Translate(float x, float y, float z)
	{
		transform->Translate(x,y,z);
	}

	void Entity::SetPosition(float x, float y, float z)
	{
		transform->SetPosition(x, y, z);
	}

	void Entity::GetPosition(float& x, float& y, float& z)
	{
		transform->GetPosition(x, y, z);
	}

	void Entity::AddComponent(Component* comp)
	{
		comp->SetEntity(this);
		components.push_back(comp);
	}

	void Entity::AddChild(Entity& child)
	{
		children.push_back(&child);
		child.parent = this;
	}

	void Entity::RemoveChild(Entity& child)
	{
		for (int i = 0; i < children.size(); i++)
		{
			if (children[i] == &child)
			{
				children[i] = nullptr;
				break;
			}
		}

		children.erase(remove(children.begin(), children.end(), nullptr), children.end());
	}

	void Entity::SetParent(Entity& _parent)
	{
		if (parent != nullptr)
		{
			parent->RemoveChild(*this);
		}
		
		parent->AddChild(*this);
	}
	void Entity::UnSetParent()
	{
		if (parent != nullptr)
		{
			parent->RemoveChild(*this);
		}
	}
}