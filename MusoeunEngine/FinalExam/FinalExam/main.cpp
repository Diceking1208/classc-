#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"

void errorCallback(int error, const char* description)
{
    printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Key callback 함수 내용
}

int Physics()
{
    return 0;
}

int Initialize()
{
    return 0;
}

int Update()
{
    return 0;
}

void Render(Floor& floor, Player& player, EnemyBlock& enemy)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the floor object
    floor.Draw();

    // Draw the player object
    player.Draw();

    enemy.Draw();
    enemy.Draw2();



    // Swap buffers
    glfwSwapBuffers(glfwGetCurrentContext());
}

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Initialize GLFW library
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    glClearColor(0.0f, 30.0f / 255.0f, 100.0f / 255.0f, 1.0f);
    Initialize();

    // Create floor and player objects
    Floor floor;
    Player player;
    EnemyBlock enemy;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        Physics();
        Update();
        Render(floor, player,enemy); // Pass floor and player objects by reference
    }

    glfwTerminate();
    return 0;
}
