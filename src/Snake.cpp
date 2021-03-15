#include "Engine.hpp"
#include "Sprite.hpp"
#include "Snake.hpp"
#include <string>

//Hard coded construtor
Snake::Snake(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(300);
  direction = -10;
}

//Constructor with positioning
Snake::Snake(std::string image, float x, float y, float speed) : Sprite(image)
{
  b.x = x;
  b.y = y;
  direction = -speed;
}

//Setting body
void Snake::setBody(b2Body *body)
{
  this->body = body;
}

//Updating the snakes
void Snake::update(double delta)
{

  //Having the snakes bounce between the screen
  position.setX(position.getX() + velocity.getX() * delta + direction);
  b.x += direction;
  if (position.getX() > 1024 - rect->w)
  {
    //Moving left
    direction = -1.0;
    surface = IMG_Load("./assets/snake.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
  }
  if (position.getX() < 0)
  {
    //Moving right
    direction = 1.0;
    surface = IMG_Load("./assets/snake-right.png");
    texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
  }
  body->SetTransform(b, body->GetAngle());
}
