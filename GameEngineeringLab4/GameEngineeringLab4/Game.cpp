#include "Game.h"

Game::Game()
{
	if (!init())
	{
		printf("failed to initialise\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("failed to load media\n");
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					switch (e.type)
					{
						case SDL_KEYDOWN:
							if (e.key.keysym.sym == SDL_KEYDOWN)
							{

							}
							break;
						default:
							break;
					}
				}
				update();
				draw();
			}
		}
	}
	close();
}

Game::~Game()
{
}

bool Game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("sdl couldnt initialise! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("warning: linear texture filtering not enabled");
		}
		gWindow = SDL_CreateWindow("SDL TUTORIAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(gRenderer, 125, 125, 125, 125);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("sdl_image couldnt initialise! SDL_Image error:%s\n", IMG_GetError());
				success = false;
			}
		}
	}
	return true;
}

bool Game::loadMedia()
{
	bool success = true;
	gTexture = loadTexture("test.png");
	if (gTexture == NULL)
	{
		printf("fail to load texture image! SDL_Image error:%s\n");
		success = false;
	}
	//gTexture2 = loadTexture("test2.png");
	//if (gTexture2 == NULL)
	//{
	//	printf("fail to load texture image! SDL_Image error:%s\n");
	//	success = false;
	//}
	return success;
}

SDL_Texture* Game::loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadSurface = IMG_Load(path.c_str());
	if (loadSurface == NULL)
	{
		printf("unable to load image! SDL_Image error:%s\n",path.c_str(),IMG_GetError());
		
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadSurface);
		if (newTexture == NULL)
		{
			printf("unable to create new tecture from! SDL error:%s\n", path.c_str(), SDL_GetError());

		}
		SDL_FreeSurface(loadSurface);
	}
	return newTexture;

}

void Game::close()
{
	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(gTexture2);
	gTexture = NULL;
	gTexture2 = NULL;
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void Game::draw()
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 100;
	rect->w = 200;
	rect->x = 300;
	rect->y = 200;
	SDL_RenderCopy(gRenderer, gTexture2, NULL, rect);

	SDL_RenderPresent(gRenderer);

}

void Game::update()
{
}
