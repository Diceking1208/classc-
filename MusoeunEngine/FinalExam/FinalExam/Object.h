#pragma once

#include <GLFW/glfw3.h>

// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {}
    virtual void Draw() {}
    virtual void Draw2() {}
};

// Derived classes
class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {}

    void Draw() override {
        // 플레이어 색상 설정 (빨간색: R=255, G=0, B=0)
        glColor3f(1.0f, 0.0f, 0.0f);

        // 플레이어 크기 및 위치 설정
        float playerSize = 50.0f / 400.0f; // 플레이어 한 변 길이 (50cm / 800px)
        float halfSize = playerSize / 2.5f;
        float borderWidth = 1.0f / 400.0f; // 테두리 두께 (1cm / 800px)
        float floorHeight = 80.0f / 300.0f; // 바닥에서 플레이어 높이

        // 플레이어 사각형 그리기
        glBegin(GL_QUADS);
        glVertex2f(-halfSize, -1.0f+floorHeight); // 좌하단
        glVertex2f(halfSize, -1.0f +floorHeight); // 우하단
        glVertex2f(halfSize, -1.0f +floorHeight + playerSize); // 우상단
        glVertex2f(-halfSize, -1.0f +floorHeight + playerSize); // 좌상단
        glEnd();

        // 플레이어 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검은색 테두리 설정
        glLineWidth(borderWidth * 400); // 테두리 두께 설정
        glBegin(GL_LINE_LOOP);
        glVertex2f(-halfSize, -1.0f + floorHeight); // 좌하단
        glVertex2f(halfSize, -1.0f + floorHeight); // 우하단
        glVertex2f(halfSize, -1.0f + floorHeight + playerSize); // 우상단
        glVertex2f(-halfSize, -1.0f + floorHeight + playerSize); // 좌상단
        glEnd();
    }
};


class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {}

    void Draw() override {
        glColor3f(0.0f, 1.0f, 0.0f);

        // 에너미 블록 크기 및 위치 설정
        float enemyWidth = 50.0f / 400.0f; // 가로 길이 (50cm / 800px)
        float enemyHeight = 80.0f /300.0f; // 세로 길이 (100cm / 600px)
        float halfWidth = enemyWidth / 2.5f;
        float halfHeight = enemyHeight / 2.0f;
        float floorHeight = 80.0f / 300.0f;

        // 에너미 블록 X 좌표 (플레이어보다 약간 오른쪽)
        float enemyX = 0.3f; // X 좌표 (플레이어의 오른쪽으로 약간 이동)

        // 에너미 블록 사각형 그리기 (바닥 위로 약간 띄우기)
        glBegin(GL_QUADS);
        glVertex2f(enemyX - halfWidth, -1.0f + floorHeight); // 좌하단
        glVertex2f(enemyX + halfWidth, -1.0f + floorHeight); // 우하단
        glVertex2f(enemyX + halfWidth, -1.0f + floorHeight + enemyHeight); // 우상단
        glVertex2f(enemyX - halfWidth, -1.0f + floorHeight + enemyHeight); // 좌상단
        glEnd();

    }

    void Draw2() override {
        glColor3f(0.0f, 1.0f, 0.0f);

        // 두 번째 에너미 블록 X 좌표
        float enemyX2 = 0.6f; // X 좌표 (첫 번째 에너미 블록의 오른쪽으로 약간 이동)
        float enemyWidths = 50.0f / 400.0f; // 가로 길이 (50cm / 400px)
        float enemyHeights = 250.0f / 300.0f; // 세로 길이 (300cm / 600px)
        float halfWidths = enemyWidths / 2.5f;
        float halfHeights = enemyHeights / 2.0f;
        float floorHeight = 80.0f / 300.0f;

        // 두 번째 에너미 블록 사각형 그리기 (바닥 위로 약간 띄우기)
        glBegin(GL_QUADS);
        glVertex2f(enemyX2 - halfWidths, -1.0f + floorHeight); // 좌하단
        glVertex2f(enemyX2 + halfWidths, -1.0f + floorHeight); // 우하단
        glVertex2f(enemyX2 + halfWidths, -1.0f + floorHeight + enemyHeights); // 우상단
        glVertex2f(enemyX2 - halfWidths, -1.0f + floorHeight + enemyHeights); // 좌상단
        glEnd();
    }
};


class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {}

    void Draw() override {
        glColor3f(1.0f, 0.784f, 0.0588f); // 노란색 (RGB: 255, 200, 15)
        float floorHeight = 80.0f / 300.0f; // 세로 길이 (100cm / 600px)

        // 사각형으로 바닥 그리기
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); // 좌하단
        glVertex2f(1.0f, -1.0f); // 우하단
        glVertex2f(1.0f, -1.0f+floorHeight); // 우상단
        glVertex2f(-1.0f, -1.0f+floorHeight); // 좌상단
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {}
};

int PhysicsAABB(Object A, Object B) {
    return 0;
}
