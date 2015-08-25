#include "Player.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

Player::Player()
{
	m_fX = 0.0f;
	m_fY = 0.0f;
	m_fAngle = 0.0f;
	m_fVec = 0.0f;
	m_fTime = 0.0f;
}


Player::~Player()
{
}


void Player::Draw()
{
	glPushMatrix();
	auto ftime = glfwGetTime();
	m_dTime = ftime - m_fTime;
	m_fTime = ftime;

	glColor3f(0.65f, 0.65f, 0.65f);
	
	glTranslatef(m_fX, m_fY, 3.0f);
	glRotatef(m_fAngle, 0.f, 0.f, 1.f);
	GLUquadricObj *qobj = gluNewQuadric();
	gluSphere(qobj, 3, 16, 16);

	glPopMatrix();
}


void Player::MoveUp()
{
	float dv = 10.0f * m_dTime;

	float dx = dv *cos(m_fAngle * 0.0174532f);
	float dy = dv *sin(m_fAngle * 0.0174532f);

	m_fX += dx;
	m_fY += dy;
}


void Player::MoveDown()
{
	float dv = -10.0f * m_dTime;

	float dx = dv *cos(m_fAngle * 0.0174532f);
	float dy = dv *sin(m_fAngle * 0.0174532f);

	m_fX += dx;
	m_fY += dy;
}


void Player::TurnLeft()
{
	m_fAngle += 0.1f;
}


void Player::TrunRight()
{
	m_fAngle -= 0.1f;
}


void Player::StopMove()
{
	m_fVec = 0.0f;
}