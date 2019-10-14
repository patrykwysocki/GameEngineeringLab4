#include "PositionComponent.h"

PositionComponent::PositionComponent():m_currentX(100),m_currentY(200)
{
}

PositionComponent::~PositionComponent()
{
}

int PositionComponent::getPositionX()
{
	return m_currentX;
}
int PositionComponent::getPositionY()
{
	return m_currentY;
}

void PositionComponent::setPosition(int t_x, int t_y)
{
	m_currentX = t_x;
	m_currentY = t_y;
}
