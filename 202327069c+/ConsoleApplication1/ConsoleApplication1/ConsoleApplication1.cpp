#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <algorithm> 

const double gravity = 9.8;
const double velocityMax = 1.0;

struct Player 
{
    float x, y;       
    float vy;        
} player;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}


void drawPlayer(const Player& player)
{
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.8f, 0.85f);
    glVertex2f(player.x, player.y);
    glVertex2f(player.x, player.y + 0.3f);
    glVertex2f(player.x - 0.2f, player.y + 0.3f);
    glVertex2f(player.x - 0.2f, player.y);
    glEnd();
}

void drawGround()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
}

// 메인 함수
int main(void) 
{
    // GLFW 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);

    player.x = 0.0f;
    player.y = 0.0f;
    player.vy = 0.0f;

    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        player.vy -= gravity * 0.01f; 
        player.vy = std::min(player.vy, static_cast<float>(velocityMax)); 
        player.y += player.vy * 0.01f; 


        if (player.y < -0.7f) 
        {
            player.y = -0.7f;
            player.vy = 0.0f;
        }

        drawPlayer(player);
        drawGround();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
