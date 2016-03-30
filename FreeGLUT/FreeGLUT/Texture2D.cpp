#include "FreeGLUT.h"
#include "Texture2D.h"
#include "Structures.h"
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int filesize;
	ifstream inFile;

	_width = width;
	_height = height;

	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		cerr << "Can't open texture file " << path << endl;
		return false;
	}

	inFile.seekg (0, ios::end);
	filesize = (int)inFile.tellg();
	tempTextureData = new char[filesize];
	inFile.seekg (0, ios::beg);
	inFile.read(tempTextureData, filesize);
	inFile.close();

	cout << path << " loaded." << endl;

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	delete[] tempTextureData;
	return true;

}