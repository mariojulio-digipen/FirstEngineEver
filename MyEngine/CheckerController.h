#ifndef CheckerController_H
#define CheckerController_H

#include "Component.h"
#include "RollingTabletData.h"

namespace Entities
{

	class CheckerController : public Component
	{
	public:

		int CellId;
		DataType Status;

		CheckerController();
		~CheckerController();

		void Update(float deltaTime);
		bool Initialize();
		bool ShutDown();
		bool Serialize(FILE** pfile);
		void HandleEvent(Events::Event* pEvent);
	};

}
#endif