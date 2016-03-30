#pragma once

#include "Structures.h"

namespace MeshLoader
{
	Mesh* Load(char* path);
	TexturedMesh* TLoad(char* path);

};
