#include "HealthComponent.h"

HealthComponent::HealthComponent(): m_currentHealth(100)
{
}

HealthComponent::~HealthComponent()
{
}

int HealthComponent::getHealth()
{
	return m_currentHealth;
}

void HealthComponent::setHealth(int t_health)
{
	this->m_currentHealth = t_health;
}
