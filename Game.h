#ifndef __SDLGame__
#define __SDLGame__

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <vector>


class Game
{
public:

    Game();
    ~Game();
    
    bool Init(const char* title = "SDL_Template", int xpos = 100, int ypos = 100, int width = 640, int height = 480, bool fullscreen = false);
    void RunLoop();
    void Shutdown();

private:

    void ProcessInput();
    void Update();
    void GenerateOutput();

    bool mIsRunning;
    static Game * sInstance;

    SDL_Window * mWindow;
    SDL_Renderer * mRenderer;

    SDL_Texture * mTexture;
    SDL_Rect mSrcRect, mDestRect;

    int mGameWidth, mGameHeight;

    Game(const Game&);
    Game& operator=(const Game&);
};

#endif