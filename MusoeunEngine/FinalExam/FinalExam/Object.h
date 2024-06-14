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
        // �÷��̾� ���� ���� (������: R=255, G=0, B=0)
        glColor3f(1.0f, 0.0f, 0.0f);

        // �÷��̾� ũ�� �� ��ġ ����
        float playerSize = 50.0f / 400.0f; // �÷��̾� �� �� ���� (50cm / 800px)
        float halfSize = playerSize / 2.5f;
        float borderWidth = 1.0f / 400.0f; // �׵θ� �β� (1cm / 800px)
        float floorHeight = 80.0f / 300.0f; // �ٴڿ��� �÷��̾� ����

        // �÷��̾� �簢�� �׸���
        glBegin(GL_QUADS);
        glVertex2f(-halfSize, -1.0f+floorHeight); // ���ϴ�
        glVertex2f(halfSize, -1.0f +floorHeight); // ���ϴ�
        glVertex2f(halfSize, -1.0f +floorHeight + playerSize); // ����
        glVertex2f(-halfSize, -1.0f +floorHeight + playerSize); // �»��
        glEnd();

        // �÷��̾� �׵θ� �׸���
        glColor3f(0.0f, 0.0f, 0.0f); // ������ �׵θ� ����
        glLineWidth(borderWidth * 400); // �׵θ� �β� ����
        glBegin(GL_LINE_LOOP);
        glVertex2f(-halfSize, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(halfSize, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(halfSize, -1.0f + floorHeight + playerSize); // ����
        glVertex2f(-halfSize, -1.0f + floorHeight + playerSize); // �»��
        glEnd();
    }
};


class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {}

    void Draw() override {
        glColor3f(0.0f, 1.0f, 0.0f);

        // ���ʹ� ��� ũ�� �� ��ġ ����
        float enemyWidth = 50.0f / 400.0f; // ���� ���� (50cm / 800px)
        float enemyHeight = 80.0f /300.0f; // ���� ���� (100cm / 600px)
        float halfWidth = enemyWidth / 2.5f;
        float halfHeight = enemyHeight / 2.0f;
        float floorHeight = 80.0f / 300.0f;

        // ���ʹ� ��� X ��ǥ (�÷��̾�� �ణ ������)
        float enemyX = 0.3f; // X ��ǥ (�÷��̾��� ���������� �ణ �̵�)

        // ���ʹ� ��� �簢�� �׸��� (�ٴ� ���� �ణ ����)
        glBegin(GL_QUADS);
        glVertex2f(enemyX - halfWidth, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(enemyX + halfWidth, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(enemyX + halfWidth, -1.0f + floorHeight + enemyHeight); // ����
        glVertex2f(enemyX - halfWidth, -1.0f + floorHeight + enemyHeight); // �»��
        glEnd();

    }

    void Draw2() override {
        glColor3f(0.0f, 1.0f, 0.0f);

        // �� ��° ���ʹ� ��� X ��ǥ
        float enemyX2 = 0.6f; // X ��ǥ (ù ��° ���ʹ� ����� ���������� �ణ �̵�)
        float enemyWidths = 50.0f / 400.0f; // ���� ���� (50cm / 400px)
        float enemyHeights = 250.0f / 300.0f; // ���� ���� (300cm / 600px)
        float halfWidths = enemyWidths / 2.5f;
        float halfHeights = enemyHeights / 2.0f;
        float floorHeight = 80.0f / 300.0f;

        // �� ��° ���ʹ� ��� �簢�� �׸��� (�ٴ� ���� �ణ ����)
        glBegin(GL_QUADS);
        glVertex2f(enemyX2 - halfWidths, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(enemyX2 + halfWidths, -1.0f + floorHeight); // ���ϴ�
        glVertex2f(enemyX2 + halfWidths, -1.0f + floorHeight + enemyHeights); // ����
        glVertex2f(enemyX2 - halfWidths, -1.0f + floorHeight + enemyHeights); // �»��
        glEnd();
    }
};


class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {}

    void Draw() override {
        glColor3f(1.0f, 0.784f, 0.0588f); // ����� (RGB: 255, 200, 15)
        float floorHeight = 80.0f / 300.0f; // ���� ���� (100cm / 600px)

        // �簢������ �ٴ� �׸���
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); // ���ϴ�
        glVertex2f(1.0f, -1.0f); // ���ϴ�
        glVertex2f(1.0f, -1.0f+floorHeight); // ����
        glVertex2f(-1.0f, -1.0f+floorHeight); // �»��
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
