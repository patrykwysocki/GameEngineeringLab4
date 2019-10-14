#pragma once
#include <SDL.h>
#include <functional>
#include <stdio.h>
#include <string>
#include <SDL_image.h>

#include "Entity.h"

#include "Component.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "InputComponent.h"

#include "AISystem.h"
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();
	bool init();
	bool loadMedia();
	SDL_Texture* loadTexture(std::string path);
	void close();
	void draw();
	void update();
private:
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 800;
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gXOut = NULL;
	SDL_Renderer* gRenderer = NULL;
	SDL_Texture* gTexture= NULL;
	SDL_Texture* gTexture2 = NULL;




};