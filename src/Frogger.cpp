#include "Engine.hpp"
#include "Frogger.hpp"

Frogger::Frogger(std::string image) : Sprite(image)
{
}

void Frogger::update(double delta)
{
  // So we stop getting the compiler warning for now.
  position.setX(position.getX() + velocity.getX() * delta);
  position.setY(position.getY() + velocity.getY() * delta);
  if (position.getX() > 1024 - rect->w || position.getX() < 0)
  {
    velocity.setX(-velocity.getX());
  }
  if (position.getY() > 768 - rect->h || position.getY() < 0)
  {
    velocity.setY(-velocity.getY());
  }
}

// void Frogger::left(double delta)
// {
//   if (velocity.getX() > -200)
//   {
//     velocity.setX(velocity.getX() - 10);
//   }
// }
// void Frogger::right(double delta)
// {
//   if (velocity.getX() < 200)
//   {
//     velocity.setX(velocity.getX() + 10);
//   }
// }
// void Frogger::up(double delta)
// {
//   if (velocity.getY() > -200)
//   {
//     velocity.setY(velocity.getY() - 10);
//   }
// }
// void Frogger::down(double delta)
// {
//   if (velocity.getY() < 200)
//   {
//     velocity.setY(velocity.getY() + 10);
//   }
// }
