#pragma once 
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "Structures.h"
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:
	Mesh* _mesh;


	GLfloat _rotation;
	Vector3* _position;

public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid(void);

	void Draw();
	void Update();
	static bool Load(char* path);
};