#include "Engine.hpp"
#include "Frogger.hpp"

Frogger::Frogger(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(400);
}

void Frogger::update(double delta)
{
  b2Vec2 b(0.0, 0.0);
  // So we stop getting the compiler warning for now.
  position.setX(position.getX() + velocity.getX());
  position.setY(position.getY() + velocity.getY());
  if (position.getX() > 1024 - rect->w || position.getX() < 0)
  {
    position.setX(-position.getX());
    b.x = -position.getX();
  }
  if (position.getY() > 768 - rect->h || position.getY() < 0)
  {
    position.setY(-position.getY());
    b.y = -position.getY();
  }
}

void Frogger::setBody(b2Body *body)
{
  this->body = body;
}

void Frogger::left(double delta)
{

  position.setX(position.getX() - 10);
  surface = IMG_Load("./assets/frog_left.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::right(double delta)
{

  position.setX(position.getX() + 10);
  surface = IMG_Load("./assets/frog_right.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::up(double delta)
{

  position.setY(position.getY() - 10);
  surface = IMG_Load("./assets/frog.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::down(double delta)
{

  position.setY(position.getY() + 10);
  surface = IMG_Load("./assets/frog_down.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
