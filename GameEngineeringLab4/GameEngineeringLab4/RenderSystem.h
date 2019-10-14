#pragma once
#include "Entity.h"
class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();
	void addEntity(Entity e);
	void update();
private:
	std::vector<Entity> m_entities;
};