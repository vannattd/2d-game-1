#include "Engine.hpp"
#include "Frogger.hpp"
#include <stdlib.h>

//Constructor to hard code frog positon
Frogger::Frogger(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(400);
  b.x = 50.0;
  b.y = 71.0;
}

void Frogger::update(double delta)
{
  //Keeping frog in border
  if (position.getX() > 1024)
  {
    b.x -= 1;
  }
  else if (position.getX() < 0)
  {
    b.x += 1;
  }
  else if (position.getY() < 0)
  {
    b.y += 1;
  }
  else if (position.getY() > 768)
  {
    b.y -= 1;
  }
  //Checking if won
  if (position.getY() <= 35)
  {
    SDL_Log("You escaped! Awesome job!");
    exit(1);
    SDL_Quit();
  }
  //Actual update
  body->SetTransform(b, body->GetAngle());
}

//Setting collision body
void Frogger::setBody(b2Body *body)
{
  this->body = body;
}

//Moving left and updating image
void Frogger::left(double delta)
{
  b.x -= 1;
  body->SetTransform(b, body->GetAngle());
  surface = IMG_Load("./assets/frog_left.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
//Moving right and updating image
void Frogger::right(double delta)
{
  b.x += 1;
  body->SetTransform(b, body->GetAngle());
  surface = IMG_Load("./assets/frog_right.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
//Moving up and updating image
void Frogger::up(double delta)
{
  b.y -= 1;
  body->SetTransform(b, body->GetAngle());
  surface = IMG_Load("./assets/frog.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
//Moving down and updating image
void Frogger::down(double delta)
{
  b.y += 1;
  body->SetTransform(b, body->GetAngle());
  surface = IMG_Load("./assets/frog_down.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
