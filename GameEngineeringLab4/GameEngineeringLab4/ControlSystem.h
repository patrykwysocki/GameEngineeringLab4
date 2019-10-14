#pragma once
#include "Entity.h"
class ControlSystem
{
public:
	ControlSystem();
	~ControlSystem();
	void addEntity(Entity e);
	void update();
private:
	std::vector<Entity> m_entities;
};