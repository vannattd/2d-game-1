#ifndef __HPP__FROGGER__
#define __HPP__FROGGER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <box2d/box2d.h>
#include "Sprite.hpp"
#include "Utility.hpp"

class Frogger : public Sprite
{
public:
  Frogger(std::string image);
  Frogger(SDL_Surface *surface);
  void update(double delta);
  void left(double delta);
  void right(double delta);
  void up(double delta);
  void down(double delta);
  void setBody(b2Body *body);

private:
  Vector3 velocity;
  Scene *scene;
  b2Body *body;
  b2Vec2 b;
};

#endif
