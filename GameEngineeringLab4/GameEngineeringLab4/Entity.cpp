#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::addComponent(Component c)
{
	components.push_back(c);
}

void Entity::removeComponent(Component c)
{
}

std::vector<Component> Entity::getComponents()
{
	return components;
}
