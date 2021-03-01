#include "Engine.hpp"
#include "Frogger.hpp"

Frogger::Frogger(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(400);
}

void Frogger::update(double delta)
{
  // So we stop getting the compiler warning for now.
  position.setX(position.getX() + velocity.getX());
  position.setY(position.getY() + velocity.getY());
  if (position.getX() > 1024 - rect->w || position.getX() < 0)
  {
    position.setX(-position.getX());
  }
  if (position.getY() > 768 - rect->h || position.getY() < 0)
  {
    position.setY(-position.getY());
  }
}

void Frogger::left(double delta)
{

  position.setX(position.getX() - 10);
}
void Frogger::right(double delta)
{

  position.setX(position.getX() + 10);
}
void Frogger::up(double delta)
{

  position.setY(position.getY() - 10);
}
void Frogger::down(double delta)
{

  position.setY(position.getY() + 10);
}
