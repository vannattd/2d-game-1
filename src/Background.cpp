#include "Engine.hpp"
#include "Background.hpp"
#include <SDL2/SDL_ttf.h>

//Constructor
Background::Background()
{
  surface = IMG_Load("./assets/bg.png");
  if (surface == NULL)
  {
    SDL_Log("Unable to load image.");
    exit(1);
  }
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
  if (texture == NULL)
  {
    SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
    SDL_Log("Unable to create texture. %s", SDL_GetError());
  }
  rect->x = 0;
  rect->y = 0;
  rect->w = surface->w;
  rect->h = surface->h;
}

//Destructor
Background::~Background()
{
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}

//Update incase for updating bg in the future
void Background::update(double delta)
{
}

//Drawing background
void Background::draw()
{
  SDL_Rect *dst = new SDL_Rect();
  dst->x = position.getX();
  dst->y = position.getY();
  dst->w = rect->w;
  dst->h = rect->h;
  SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
