#pragma once
#include "Entity.h"
class HealthSystem
{
public:
	HealthSystem();
	~HealthSystem();
	void addEntity(Entity e);
	void update();
private:
	std::vector<Entity> m_entities;
};