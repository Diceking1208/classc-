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
void MouseCallback(GLFWwindow* window, int button,int action, int mods)
{
	static bool Dragging = false;
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			Dragging = true; 
		}
		else if (action == GLFW_RELEASE)
		{
			Dragging = false; 
		}
		if (Dragging)
		{
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f); 
		}
		else
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	
	if (button == GLFW_MOUSE_BUTTON_2 && action == GLFW_PRESS)
	{
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
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

	glfwSetErrorCallback(errorCallBack);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, MouseCallback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	glfwTerminate();	
	return 0;
}