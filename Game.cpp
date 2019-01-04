#include "Game.h"

#define FIRST_CAPABLE_DRIVER -1

Game::Game():
    mIsRunning(true),
    mWindow(nullptr),
    mRenderer(nullptr),
    mGameWidth(0),
    mGameHeight(0)
{

}

Game::~Game()
{
    mRenderer = 0;
    mWindow = 0;
}

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    mGameWidth = width;
    mGameHeight = height;

    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // attempt to initialise SDL subsystems
    // only need to initialise video and audio for now
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // create an SDL window
    mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(!mWindow)
    {
    	SDL_Log("%s: Failed to create window: %s\n", __func__, SDL_GetError());
        return false;
    }

    // create renderer
    mRenderer = SDL_CreateRenderer(mWindow, FIRST_CAPABLE_DRIVER, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer)
    {
        SDL_Log("%s: Failed to create renderer: %s\n", __func__, SDL_GetError());
        return false;
    }

    // now render
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    /***************************
    ********Load data***********
    ***************************/
    // perhaps a load data function here?

    // assuming all goes well, return true
    return true;

}

void Game::RunLoop()
{
    while(mIsRunning)
    {
        ProcessInput();
        Update();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                mIsRunning = false;
            break;
            
            default:
            break;
        }
    }
}

void Game::Update()
{

}

void Game::GenerateOutput()
{
    SDL_RenderClear(mRenderer);

    SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
    // have to quit SDL IMG
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}