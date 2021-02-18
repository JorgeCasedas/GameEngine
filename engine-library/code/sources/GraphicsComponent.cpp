
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

#include "GraphicsComponent.hpp"
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Level.hpp>
#include <Transform.hpp>


namespace engine
{
	void GraphicsComponent::Translate(float x, float y, float z)
	{
		model->translate(glt::Vector3(x, y, z));
	}

	void GraphicsComponent::Scale(float x, float y, float z)
	{
		model->scale(x, y, z);
	}

	GraphicsComponent::GraphicsComponent(const string& EntityName, Level& _level, const string& obj_file_path, Transform& _transform)
	{
		shared_ptr<Model> _model(new Model_Obj(obj_file_path));
		_level.Add(EntityName, _model);
		model = _level.GetEntity(EntityName);
		transform = &_transform;
	}
	void GraphicsComponent::Update(float x, float y, float z)
	{	
		Translate(x, y, z);
	}
}


