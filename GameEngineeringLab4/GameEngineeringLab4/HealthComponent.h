#pragma once
#include "Component.h"
class HealthComponent : Component
{
public:
	HealthComponent();
	~HealthComponent();
	int getHealth();
	void setHealth(int t_health);
private:
	int m_currentHealth;
};