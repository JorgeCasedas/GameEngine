
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

#include "Transform.hpp"

namespace engine
{
	Transform::Transform()
	{
		lastXPos = 0;
		lastYPos = 0;
		lastZPos = 0;

		xPos = 0;
		yPos = 0;
		zPos = 0;

		xSize = 1;
		ySize = 1;
		zSize = 1;
	}
	void Transform::SetScale(float x, float y, float z)
	{
		xSize = x;
		ySize = y;
		zSize = z;
	}
	void Transform::GetScale(float& x, float& y, float& z)
	{
		x = xSize;
		y = ySize;
		z = zSize;
	}
	void Transform::SetPosition(float x, float y, float z)
	{
		ResetLastPos();

		xPos = x;
		yPos = y;
		zPos = z;
	}
	void Transform::GetPosition(float& x, float& y, float& z)
	{
		x = xPos;
		y = yPos;
		z = zPos;
	}
	void Transform::Translate(float x, float y, float z)
	{
		//SetPosition(xPos+x, yPos+y, zPos+z);
		xPos += x;
		yPos += y;
		zPos += z;
	}
	void Transform::GetLastTransformation(float& x, float& y, float& z)
	{
		x = xPos - lastXPos;
		y = yPos - lastYPos;
		z = zPos - lastZPos;
		ResetLastPos();
	}
	void Transform::ResetLastPos()
	{
		lastXPos = xPos;
		lastYPos = yPos;
		lastZPos = zPos;
	}
}
