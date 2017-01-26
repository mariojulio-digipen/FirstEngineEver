#include "FGraphics.h"


FGraphics::FGraphics(void)
{
}

FGraphics::Update(FSprite& fSprite, Graphics& graphics)
{
	Sprite* sprite = &spriteStand;
	
	if (fSprite.velocity < 0)
	{
		sprite = &spriteWalkLeft;
	}
	else if (velocity_ > 0)
	{
		sprite = &spriteWalkRight;
	}

	graphics.draw(*sprite, fSprite.x, fSprite.y);
}


FGraphics::~FGraphics(void)
{
}
