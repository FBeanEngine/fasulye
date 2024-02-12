#include <iostream>
#include "FAnimation.h"

FAnimation::FAnimation()
{
	// TODO
}

FAnimation::~FAnimation()
{
	// TODO
}

void FAnimation::AddAnimation(std::string animationName, FAnimationClip clip)
{
	m_animationsNames.push_back(animationName);
	m_animations.push_back(clip);
}

void FAnimation::Animate(Vector2 position, float dt)
{
	if (m_currentAnimation == "")
	{
		return;
	}

	int animationID = -1;
	for (size_t i = 0; i < m_animationsNames.size(); i++)
	{
		if (m_currentAnimation == m_animationsNames[i])
		{
			animationID = i;
			break;
		}
	}
	if (animationID == -1)
	{
		std::cout << "Animation Not Found: " << m_currentAnimation << std::endl;
		return;
	}

	m_animations[animationID].Play(position, dt);
}

void FAnimation::BindAnimation(std::string animationName)
{
	m_currentAnimation = animationName;
}