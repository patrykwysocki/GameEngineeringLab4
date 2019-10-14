#pragma once
#include "Component.h"
class PositionComponent : Component
{
public:
	PositionComponent();
	~PositionComponent();
	int getPositionX();
	int getPositionY();
	void setPosition(int t_x, int t_y);
private:
	int m_currentX;
	int m_currentY;
};