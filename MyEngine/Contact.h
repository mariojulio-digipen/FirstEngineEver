#ifndef CONTACT_H
#define CONTACT_H

namespace Entities
{
	class PhysicsComponent;
}

namespace Physics
{
	class Contact
	{
	public:
		Contact();
		~Contact();

		Entities::PhysicsComponent* Bodies[2];

	};
}

#endif

