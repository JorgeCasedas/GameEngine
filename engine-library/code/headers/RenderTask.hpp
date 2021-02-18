
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
	class Level;

	///
	/// Task in charge of rendering everything in the scene
	///
	class RenderTask
	{
		Level* level;
	public:
		RenderTask(Level& _level);
		void Update();
	};
}