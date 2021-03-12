#ifndef __HPP__SNAKE__
#define __HPP__SNAKE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <box2d/box2d.h>
#include "Sprite.hpp"
#include "Utility.hpp"

class Snake : public Sprite
{
public:
  Snake(std::string image);
  Snake(std::string image, float x, float y, float speed);
  Snake(SDL_Surface *surface);
  void update(double delta);
  void setBody(b2Body *body);

private:
  Vector3 velocity;
  Scene *scene;
  float direction;
  b2Body *body;
  b2Vec2 b;
};

#endif
