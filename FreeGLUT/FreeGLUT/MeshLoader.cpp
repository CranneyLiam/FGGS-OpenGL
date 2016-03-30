#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, TexturedMesh& tMesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.ColourCount;

		if (mesh.ColourCount > 0)
		{
			mesh.Colors = new Color[mesh.ColourCount];

			for (int i = 0; i < mesh.ColourCount; i++)
			{
				inFile >> mesh.Colors[i].r;
				inFile >> mesh.Colors[i].g;
				inFile >> mesh.Colors[i].b;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0)
		{
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}
	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		MeshLoader::LoadVertices(inFile, *mesh);
		MeshLoader::LoadColours(inFile, *mesh);
		MeshLoader::LoadIndices(inFile, *mesh);

		return mesh;
	}
	void LoadTexCoords(ifstream& inFile, TexturedMesh& tMesh)
	{
		inFile >> tMesh.TexCoordCount;

		if (tMesh.TexCoordCount > 0)
		{
			tMesh.TexCoords = new TexCoord[tMesh.TexCoordCount];

			for (int i = 0; i < tMesh.TexCoordCount; i++)
			{
				inFile >> tMesh.TexCoords[i].u;
				inFile >> tMesh.TexCoords[i].v;
			}
		}

	}
	TexturedMesh* MeshLoader::TLoad(char* path)
	{
		TexturedMesh* tMesh = new TexturedMesh();
		tMesh->Mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		MeshLoader::LoadVertices(inFile, *tMesh->Mesh);
		MeshLoader::LoadColours(inFile, *tMesh->Mesh);
		MeshLoader::LoadTexCoords(inFile, *tMesh);
		MeshLoader::LoadIndices(inFile, *tMesh->Mesh);

		return tMesh;
	}

}


