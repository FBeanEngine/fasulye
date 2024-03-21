#include "FObject.h"

FObject::FObject()
{
	isDestroyed = false;
	canMove = {true, true, true, true};
	enableBoundingBox = false;
	tag = "FObject";
}

FObject::~FObject()
{
	// TODO
}

void FObject::Update(float dt)
{
	// TODO
}

void FObject::Draw(float dt)
{
	// TODO
}

void FObject::Physics(std::string tag, Rectangle collisionBox)
{
	// TODO
}

void FObject::SetMousePosition(Vector2 mousePosition)
{
	m_mousePosition = mousePosition;
}

void FObject::ActivateBoundingBox()
{
	enableBoundingBox = true;
}

void FObject::DeactivateBoundingBox()
{
	enableBoundingBox = false;
}

void FObject::SetBoundingBox(float x, float y, float width, float height)
{
	boundingBox = {x, y, width, height};
}

void FObject::UpdateBoundingBox(Rectangle nboundingBox)
{
	boundingBox.x = nboundingBox.x;
	boundingBox.y = nboundingBox.y;
	boundingBox.width = nboundingBox.width;
	boundingBox.height = nboundingBox.height;
}

Rectangle FObject::GetBoundingBox()
{
	return boundingBox;
}

std::string FObject::GetTag()
{
	return tag;
}

void FObject::ShowBoundingBox()
{
	if (enableBoundingBox)
	{
		DrawRectangleLines(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height, BLUE);
	}
}