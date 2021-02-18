
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
#include<internal/declarations.hpp>

using namespace glt;
using namespace std;

namespace engine
{
	class Level;
	class Transform;

	///
	/// Component that manages the graphic aspect of every entity
	///
	class GraphicsComponent
	{

		Node* model;
		Transform* transform;

	private:
		void Translate(float x, float y, float z);		

	public:
		///
		/// Constructor
		///
		GraphicsComponent(const string& EntityName, Level& _level, const string& obj_file_path, Transform& _transform);
		void Update(float x, float y, float z);
		///
		/// Set model scale
		///
		void Scale(float x, float y, float z);
	};
}

