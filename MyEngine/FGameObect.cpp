//#include "FGameObject.h"
//
//
//FGameObject::FGameObject(FInputComponent* input, 
//				 FPhysicsComponent* physics, 
//				 FGraphics* graphics) : 
//					input(input), 
//					physics(physics), 
//					graphics(graphics);
//{
//}
//
//
//FGameObject::~FGameObject(void)
//{
//}
//
//void FGameObject::Update(World& world, Graphics& graphLib)
//{
//	// Apply user input to hero's velocity.
//	input.Update(*this);
//
//	// Modify position by velocity.
//	physics.Update(*this, world);
//	
//	// Draw the appropriate sprite.
//	graphics.Update(*this, graphLib);
//}