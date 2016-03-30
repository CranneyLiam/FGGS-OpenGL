#include "FreeGLUT.h"
#include "GLUTCallbacks.h"
#include "Cube.h"
#include "Pyramid.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "Texture2D.h"
#include <ctime>

FreeGLUT::FreeGLUT(int argc, char* argv[])
{
	srand(time(NULL));
	GLUTCallbacks::Init(this);
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}

void FreeGLUT::InitObjects()
{
	camera = new Camera();
	
	//Mesh* pyramidMesh = MeshLoader::Load("pyramid.txt");


	Texture2D* texture = new Texture2D();
	texture->Load("stars.raw", 512, 512);
	
	TexturedMesh* cubeMesh = MeshLoader::TLoad("cube.txt");

	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = -300.0f;


	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;


	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;


	for (int i = 0; i < 2000; i++)
	{
		objects[i] = new Cube(cubeMesh, rand() % 500 - 250, rand() % 500 - 250, rand() % 500 - 250, texture);
	}
	/*for (int i = 1000; i < 2000; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, rand() % 500 - 250, rand() % 500 - 250, rand() % 500 - 250);
	}*/
}
void FreeGLUT::InitGL(int argc, char* argv[])
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("FreeGLUT"); 
	glutDisplayFunc(GLUTCallbacks::Display); 
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
}


FreeGLUT::~FreeGLUT()
{
}

void FreeGLUT::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene so we start a fresh each time
	
	for (int i = 0; i < 2000; i++)
	{
		objects[i]->Draw();
	}

	glFlush(); //Flushes the scene we just drew to the graphics card
	glutSwapBuffers();
}
void FreeGLUT::Update()
{
	glLoadIdentity();

	for (int i = 0; i < 2000; i++)
	{
		objects[i]->Update();
	}

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void FreeGLUT::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		camera->up.x += 0.5f;
	}
	else if (key == 'e')
	{
		camera->up.x -= 0.5f;
	}
	else if (key == 'a')
	{
		camera->up.y += 0.5f;
	}
	else if (key == 'q')
	{
		camera->up.y -= 0.5f;
	}
	else if (key == 's')
	{
		camera->up.z += 0.5f;
	}
	else if (key == 'w')
	{
		camera->up.z -= 0.5f;
	}
}
