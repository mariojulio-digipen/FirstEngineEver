#include "FInputComponent.h"


FInputComponent::FInputComponent(void)
{
}

void Update(FSprite& fSprite)
{
	switch (Controller::getJoystickDirection())
    {
      case DIR_LEFT:
        fSprite.velocity -= WALK_ACCELERATION;
        break;

      case DIR_RIGHT:
        fSprite.velocity += WALK_ACCELERATION;
        break;
    }
}

FInputComponent::~FInputComponent(void)
{
}
