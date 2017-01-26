#include "TextureUnitFactory.h"
#include "SARendererComponent.h"
#include "Entity.h"


TextureUnitFactory::TextureUnitFactory()
{
}


TextureUnitFactory::~TextureUnitFactory()
{
}


int TextureUnitFactory::GetTextureUnit(Entities::SARendererComponent* renderer)
{
	Entities::Entity* rendererOwer = renderer->GetOwner();
	switch (rendererOwer->ArcheType)
	{
	case Entities::EntityType::BULLET:
		return 1;
	case Entities::EntityType::CHECKER:
		return 2;
	case Entities::EntityType::CONTROLS_SCREEN:
		return 3;
	case Entities::EntityType::DUST:
		return 4;
	case Entities::EntityType::ENEMY:
		return 5;
	case Entities::EntityType::ENEMY_ALIEN:
		return 6;
	case Entities::EntityType::GENERAL:
		return 7;
	case Entities::EntityType::ORB:
		return 8;
	case Entities::EntityType::SHOOTER_LEFT:
		return 9;
	case Entities::EntityType::SHOOTER_RIGHT:
		return 10;
	default:
		break;
	}
	return 0;
}