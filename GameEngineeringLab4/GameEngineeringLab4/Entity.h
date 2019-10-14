#pragma once
#include <vector>
#include "Component.h"
class Entity
{
public:
	Entity();
	~Entity();
	int id;
	void addComponent(Component c);
	void removeComponent(Component c);
	std::vector<Component> getComponents();
private:
	std::vector<Component> components;
};