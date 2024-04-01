#pragma comment(lib, "OpenGL32.lib")
#include <GLFW/glfw3.h>
#include <iostream>


void errorCallBack(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, 1);
	}
}



void MouseCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		}
		else if (action == GLFW_RELEASE)
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		}
		else if (action == GLFW_RELEASE)
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}
	}
}

void PositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	int leftButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	int rightButton = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

	if (leftButton == GLFW_PRESS)
	{
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	}
	else if (rightButton == GLFW_PRESS)
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	}
}

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(1280, 768, "HoHoHo HimNae", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallBack);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, MouseCallback);
	glfwSetCursorPosCallback(window, PositionCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}