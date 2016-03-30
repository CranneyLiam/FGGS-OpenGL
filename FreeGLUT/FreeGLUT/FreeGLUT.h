#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL/freeglut.h" //freeglut library
#include "Structures.h"
#include "Cube.h"
#include "Texture2D.h"

#define REFRESHRATE 16
#define CUBENUMBER 2500.

class FreeGLUT
{
public:
	FreeGLUT(int argc, char* argv[]);
	~FreeGLUT(void);
	void Display();
	void Update();
	void Keyboard(unsigned char Key, int x, int y);
	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void rotationRect();
	void rotationSquare();
	void rotationTriangle();

	void drawRect();
	void drawSquare();
	void drawTriangle();
	
	void DrawCube();

	Camera* camera;
	SceneObject* objects[2000];


	void DrawCubeArray();

	void DrawPyramidArray();

	void DrawTriangularPrismArray();


private:
	
	float rectRotation;
	float squareRotation;
	float triangleRotation;
};

