#include "FAnimationClip.h"

FAnimationClip::FAnimationClip(const char *fileName, int frame, int width, int height, int speed, bool inverse)
{
	this->speed = speed;
	this->frame = frame;
	this->counter = 0.f;
	this->height = height;
	this->width = width;

	this->tileset = LoadTexture(fileName);

	for (size_t i = 0; i < frame; i++)
	{
		if (inverse)
		{
			clip.insert(clip.begin(), {float(i * width), 0.0f, float(width), float(height)});
		}
		else
		{
			clip.push_back({float(i * width), 0.0f, float(width), float(height)});
		}
	}
}

FAnimationClip::~FAnimationClip()
{
	// TODO
}

void FAnimationClip::Play(Vector2 position, float dt)
{
	// DrawTexturePro(anim.m_tileset, anim.m_clip[anim.counter], {this->position.x, this->position.y, 96.f, 80.f}, {0.f, 0.f}, 0, WHITE);
	counter += speed * dt;
	if (counter >= frame)
	{
		counter = 0.f;
	}
	DrawTexturePro(tileset, clip[int(counter)], {position.x, position.y, float(width), float(height)}, {0.f, 0.f}, 0, WHITE);
}
