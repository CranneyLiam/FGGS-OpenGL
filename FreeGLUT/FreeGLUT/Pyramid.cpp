#include "Pyramid.h"
#include "FreeGLUT.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_rotation = 0.0f;
	_position = new Vector3(x, y, z);

	_mesh = mesh;

}


Pyramid::~Pyramid()
{
}

void Pyramid::Draw()
{
	glPushMatrix();

	glTranslatef(_position->x, _position->y, _position->z);
	
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < _mesh->IndexCount; i++)
	{
		glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
		glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
	}
	glEnd();

	glPopMatrix();
}

void Pyramid::Update()
{

}