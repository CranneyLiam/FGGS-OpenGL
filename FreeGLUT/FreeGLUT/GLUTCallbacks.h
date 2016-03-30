#pragma once

class FreeGLUT; //Forward declare HelloGL

namespace GLUTCallbacks 
{
	void Init(FreeGLUT * gl);
	void Display();
	void Timer(int prefferedRefresh);
	void Keyboard(unsigned char Key, int x, int y);

};