#ifndef __HPP__SPRITE__
#define __HPP__SPRITE__

//@authors Dylan Vannatter, Korey Stamper and Jessica Ricksgers
//Start of a basic Sprite Class for CIS 380

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <string>

class Sprite : public DUGameObject
{
public:
  Sprite(std::string image);
  Sprite(SDL_Surface *surface);
  void operator++();
  void setScene(Scene *scene);
  ~Sprite();
  void draw();

private:
  Vector3 velocity;
  Scene *scene;
};

#endif
