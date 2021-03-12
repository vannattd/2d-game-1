#include "Engine.hpp"
#include "Frogger.hpp"

Frogger::Frogger(std::string image) : Sprite(image)
{
  position.setX(400);
  position.setY(400);
  b.x = 50.0;
  b.y = 50.0;
}

void Frogger::update(double delta)
{
  //b2Vec2 b(50.0, 50.0);
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
  //body->ApplyLinearImpulseToCenter(b, true);
  body->SetTransform(b, body->GetAngle());
}

void Frogger::setBody(b2Body *body)
{
  this->body = body;
}

void Frogger::left(double delta)
{
  b.x -= 1;
  body->SetTransform(b, body->GetAngle());
  //position.setX(position.getX() - 10);
  surface = IMG_Load("./assets/frog_left.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::right(double delta)
{
  b.x += 1;
  body->SetTransform(b, body->GetAngle());
  //position.setX(position.getX() + 10);
  surface = IMG_Load("./assets/frog_right.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::up(double delta)
{
  b.y -= 1;
  body->SetTransform(b, body->GetAngle());
  //position.setY(position.getY() - 10);
  surface = IMG_Load("./assets/frog.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
void Frogger::down(double delta)
{
  b.y += 1;
  body->SetTransform(b, body->GetAngle());
  //body->SetTransform(b2Vec2(position.getX(), position.getY() + 10), body->GetAngle());
  //position.setY(position.getY() + 10);
  surface = IMG_Load("./assets/frog_down.png");
  texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
}
