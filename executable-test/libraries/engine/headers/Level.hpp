
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

#include <memory>
#include <string>
#include <vector>
#include <internal/declarations.hpp>


namespace engine
{

	class Window;
	class Entity;
	using namespace glt;
	using namespace std;
	
	///
	/// Class for the scene all entities, cameras, and lights will be in
	///
	class Level
	{
	private:

		shared_ptr< Render_Node > scene;
		Window* window;

	public:
		vector<Entity*> levelEntities;

	public:

		Level(Window& given_window);

		void CreateScene();
		void ResetViewport();

		///
		/// Add a new object to the scene
		///
		void Add(const std::string& name, std::shared_ptr< Node > node);
		///
		/// Get an object that has been previously added to the scene
		///
		Node* GetEntity(const std::string& name);

		void Update();

		void TranslateCamera(float x, float y, float z);
		void RotateCamerta(float x, float y, float z);

		///
		/// Method use for debugging with a breakpoint
		///
		void DebugMethod();

	};
}



