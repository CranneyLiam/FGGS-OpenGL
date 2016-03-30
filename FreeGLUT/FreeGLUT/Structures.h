#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL/freeglut.h" //freeglut library

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3()
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};
struct Color
{
	GLfloat r, g, b;
};
struct Vertex
{
	GLfloat x, y, z;
};
struct Mesh
{
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;

	int VertexCount, ColourCount, IndexCount;
}; 
struct TexCoord
{
	GLfloat u, v;
};
struct TexturedMesh
{
	Mesh* Mesh;
	TexCoord* TexCoords;

	int TexCoordCount;
};




