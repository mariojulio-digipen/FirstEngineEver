#include "PlayerHitEvent.h"

namespace Events
{
	PlayerHitEvent::PlayerHitEvent()
	{
		Type = Events::EventType::PLAYERHIT;
	}


	PlayerHitEvent::~PlayerHitEvent()
	{

	}
}


