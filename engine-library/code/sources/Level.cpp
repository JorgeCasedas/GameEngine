
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

#include <Light.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>
#include <Node.hpp>
#include <Window.hpp>

#include "Level.hpp"
#include "Entity.hpp"

namespace engine
{
	Level::Level(Window& given_window)
	{
		window = &given_window;
		CreateScene();		
	}

	void Level::CreateScene()
	{

		shared_ptr< Render_Node > _scene(new Render_Node);
		shared_ptr< Camera      > camera(new Camera(20.f, 1.f, 500.f, 1.f));
		shared_ptr< Light       > light(new Light);

		// Se añaden los nodos a la escena:

		_scene->add("camera", camera);
		_scene->add("light", light);

		scene = _scene;

		(*scene)["light"]->translate(glt::Vector3(10.f, 10.f, 10.f));
		(*scene)["camera"]->translate(Vector3(0.f, 0.f, 5.f));

	}

	void Level::ResetViewport()
	{
		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());

		scene->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}

	void Level::Add(const std::string& name, std::shared_ptr<Node> node)
	{
		scene->add(name, node);
	}

	Node* Level::GetEntity(const std::string& name)
	{
		return scene->get(name);
	}

	void Level::Update()
	{
		/*int i = 0;
		while (i < levelEntities.size())
		{
			levelEntities[i]->Update();
			i++;
		}*/

		ResetViewport();

		window->clear();

		scene->render();

		window->swap_buffers();

	}

	void Level::TranslateCamera(float x, float y, float z)
	{
		(*scene)["camera"]->translate(Vector3(x, y, z));
	}

	void Level::RotateCamerta(float x, float y, float z)
	{
		(*scene)["camera"]->rotate_around_x(x);
		(*scene)["camera"]->rotate_around_y(y);
		(*scene)["camera"]->rotate_around_z(z);
	}

	void Level::DebugMethod()
	{
		return; //Method use for checking if things work adding a breakpoint, if the project enters here, it means the test works
	}
}



