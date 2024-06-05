#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

const int width = 1280;
const int height = 1024;
const float g = 9.8f;
const float dt = 1.0f / 60.0f; // 프레임 시간 간격

float y_position = 1.0f; 
float velocity = 0.0f; // 초기 속도

void drawSquare(float x, float y, float size)
{
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.8f, 0.85f);

    glVertex2f(x - size / 2, y - size / 2); 
    glVertex2f(x + size / 2, y - size / 2); 
    glVertex2f(x + size / 2, y + size / 2); 
    glVertex2f(x - size / 2, y + size / 2); 
    glEnd();
}

int main() 
{
    if (!glfwInit()) 
    {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(width, height, "Gravity Simulation", NULL, NULL);
    if (!window) 
    {
        std::cerr << "윈도우 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) 
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // 중력 가속도 적용
        velocity += g * dt;
        y_position -= velocity * dt;

        drawSquare(0.0f, y_position, 0.3f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
