#ifndef IKeyManager_H
#define IKeyManager_H


namespace Input
{
	class IKeyManager
	{
	public:
		virtual int GetKeyFor(int action) const = 0; 
	};

}

#endif