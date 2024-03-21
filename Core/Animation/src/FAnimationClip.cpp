#include "FAnimationClip.h"

FAnimationClip::FAnimationClip(const char *fileName, int frame, int width, int height, int speed, bool inverse, bool wihoutBlock)
{
	scale = 1;
	offset = {0, 0};
	this->speed = speed;
	this->frame = frame;
	this->counter = 0.f;
	this->height = height;
	this->width = width;
	this->withoutBlock = wihoutBlock;
	this->isFinished = true;

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
	if (!withoutBlock)
	{
		isFinished = true;
	}
	if (counter >= frame)
	{
		if (withoutBlock)
		{
			isFinished = true;
		}
		counter = 0.f;
	}
	DrawTexturePro(tileset, clip[int(counter)], {position.x + offset.x * scale, position.y + offset.y * scale, float(width) * scale, float(height) * scale}, {0.f, 0.f}, 0, WHITE);
}

void FAnimationClip::setScale(int scale)
{
	this->scale = scale;
}

void FAnimationClip::setOffset(Vector2 offset)
{
	this->offset = offset;
}
