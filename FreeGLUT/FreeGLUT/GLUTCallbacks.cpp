#include "GLUTCallbacks.h" 
#include "FreeGLUT.h"

namespace GLUTCallbacks 
{
	namespace
	{
		FreeGLUT * freeGLUT = nullptr;
	}
	void Init(FreeGLUT * gl) 
	{
		freeGLUT = gl; 
	}
	void Display() 
	{ 
		if (freeGLUT != nullptr) freeGLUT->Display();
	}
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		freeGLUT->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
	void Keyboard(unsigned char Key, int x, int y)
	{
		freeGLUT->Keyboard(Key, x, y);
	}
}