#pragma once
#include "Entity.h"
class AISystem
{
public:
	AISystem();
	~AISystem();
	void addEntity(Entity e);
	void update();
private:
	std::vector<Entity> m_entities;
};