#ifndef KeyManager_H
#define KeyManager_H

#include "IKeyManager.h"

namespace Input
{
	class KeyManager : public IKeyManager
	{
	public:
		int GetKeyFor(int action) const;
	};

}

#endif