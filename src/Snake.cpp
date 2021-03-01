#include "Engine.hpp"
#include "Snake.hpp"

Snake::Snake(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(300);
  direction = -10;
}

void Snake::update(double delta)
{
  // So we stop getting the compiler warning for now.
  position.setX(position.getX() + velocity.getX() * delta + direction);
  //position.setY(position.getY() + velocity.getY() * delta + 10);
  if (position.getX() > 1024 - rect->w)
  {
    direction = -10;
    surface = IMG_Load("./assets/snake.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
    //position.setX(position.getX() - 10);
  }
  if (position.getX() < 0)
  {
    direction = 10;
    surface = IMG_Load("./assets/snake-right.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);

    //position.setX(position.getX() + 10);
  }
}

// void Snake::update(double delta)
// {
//   // So we stop getting the compiler warning for now.
//   position.setX(position.getX() + velocity.getX() * delta);
//   position.setY(position.getY() + velocity.getY() * delta);
//   if (position.getX() > 1024 - rect->w || position.getX() < 0)
//   {
//     velocity.setX(-velocity.getX());
//   }
//   if (position.getY() > 768 - rect->h || position.getY() < 0)
//   {
//     velocity.setY(-velocity.getY());
//   }
// }
