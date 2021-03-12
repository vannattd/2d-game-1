#include "Engine.hpp"
#include "Sprite.hpp"
#include "Snake.hpp"
#include <string>

Snake::Snake(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(300);
  direction = -10;
}

Snake::Snake(std::string image, float x, float y, float speed) : Sprite(image)
{
  //position.setX(x);
  //position.setY(y);
  b.x = x;
  b.y = y;
  direction = -speed;
}

void Snake::setBody(b2Body *body)
{
  this->body = body;
}

void Snake::update(double delta)
{
  // So we stop getting the compiler warning for now.
  position.setX(position.getX() + velocity.getX() * delta + direction);
  b.x += direction;
  //position.setY(position.getY() + velocity.getY() * delta + 10);
  if (position.getX() > 1024 - rect->w)
  {
    direction = -1.0;
    surface = IMG_Load("./assets/snake.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
    //position.setX(position.getX() - 10);
  }
  if (position.getX() < 0)
  {
    direction = 1.0;
    surface = IMG_Load("./assets/snake-right.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);

    //position.setX(position.getX() + 10);
  }
  body->SetTransform(b, body->GetAngle());
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
