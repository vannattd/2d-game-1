#ifndef __HPP__SNAKE__
#define __HPP__SNAKE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.hpp"
#include "Utility.hpp"

class Snake : public Sprite
{
public:
  Snake(std::string image);
  Snake(SDL_Surface *surface);
  void update(double delta);

private:
  Vector3 velocity;
  Scene *scene;
  int direction;
};

#endif
