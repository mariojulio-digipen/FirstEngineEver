#include "FPhysicsComponent.h"


FPhysicsComponent::FPhysicsComponent(void)
{
}


void FPhysicsComponent::Update(FSprite& fSprite, World& world)
{
	fSprite.x += fSprite.velocity;
	world.resolveCollision(volumen, fSprite.x, fSprite.y, fSprite.velocity);
}

FPhysicsComponent::~FPhysicsComponent(void)
{
}
