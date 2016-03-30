#include "Cube.h"
#include "FreeGLUT.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "Texture2D.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

Cube::Cube(TexturedMesh* tMesh, float x, float y, float z, Texture2D* texture) : SceneObject(tMesh->Mesh) 
{
	_rotation = 0.0f;
	_position = new Vector3(x, y, z);
	_tMesh = tMesh;
	_texture = texture;
}


Cube::~Cube()
{
}

void Cube::Draw()
{
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTranslatef(_position->x, _position->y, _position->z);
	glRotatef(_rotation, 0.5f, 1.5f, 1.0f);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < _tMesh->Mesh->IndexCount; i++)
	{
		glTexCoord2fv(&_tMesh->TexCoords[_tMesh->Mesh->Indices[i]].u);
		glColor3fv(&_tMesh->Mesh->Colors[_tMesh->Mesh->Indices[i]].r);
		glVertex3fv(&_tMesh->Mesh->Vertices[_tMesh->Mesh->Indices[i]].x);
	}
	glEnd();

	glPopMatrix();
}

void Cube::Update()
{
	_rotation += 50.0f;
	_position->z -= 15.0f;
	if (_position->z < -300)
	{
		_position->z = 250.0f;
	}
}

