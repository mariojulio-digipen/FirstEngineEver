#ifndef InputComponent_H
#define InputComponent_H

// interface for any kind of Inputs
class InputComponent
{
	public:
		InputComponent(){};

		virtual void Update(){}; // bc is a pointer (vpointer)

		virtual ~InputComponent(){};
};

#endif