﻿#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		moveFactor += 0.01f;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		scaleFactor += 0.1f;
	}
}

int render()
{
	glBegin(GL_TRIANGLES);
	
	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(0.0f, 0.3f);
	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(-0.2f, -0.6f);
	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(0.2f, -0.6f);

	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(-0.3f, 0.0f);
	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(0.3f, 0.0f);
	glColor3f(0.7f, 0.8f, 0.85f);
	glVertex2f(0.0f, -0.5f);
	
	glEnd();

	return 0;
}


int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}