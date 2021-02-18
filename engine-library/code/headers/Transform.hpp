
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

	///
	/// Component that keep track of the position and scale of an object, use for Entity classes
	///
	class Transform
	{
		float lastXPos;
		float lastYPos;
		float lastZPos;

		float xPos;
		float yPos;
		float zPos;

		float xSize;
		float ySize;
		float zSize;

	public:
		Transform();

		void SetScale(float x, float y, float z);
		void GetScale(float& x, float& y, float& z);

		void SetPosition(float x, float y, float z);
		void GetPosition(float &x, float &y, float &z);
		void Translate(float x, float y, float z);
		void GetLastTransformation(float& x, float& y, float& z);

	private:
		void ResetLastPos();
	};
}

