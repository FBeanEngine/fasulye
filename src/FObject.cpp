#include "FObject.h"

FObject::FObject()
{
	isDestroyed = false;
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

void FObject::SetMousePosition(Vector2 mousePosition)
{
	m_mousePosition = mousePosition;
}