#pragma once 
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "Structures.h"
#include "SceneObject.h"
#include "Texture2D.h"

class Cube : public SceneObject
{
private: 
	TexturedMesh* _tMesh;
	GLfloat _rotation;
	Vector3* _position;
	Texture2D* _texture;

public:
	Cube(TexturedMesh* tMesh, float x, float y, float z, Texture2D* texture);
	~Cube(void);

	void Draw();
	void Update();
	static bool Load(char* path);
};

