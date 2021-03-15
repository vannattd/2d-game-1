#ifndef __HPP__BACKGROUND__
#define __HPP__BACKGROUND__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <random>

class Background : public DUGameObject
{
public:
  Background();
  ~Background();
  void update(double delta);
  void draw();

private:
};

#endif
