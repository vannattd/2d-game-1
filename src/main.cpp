//@authors Dylan Vannatter, Korey Stamper and Jessica Ricksgers
#include "Engine.hpp"
#include "Frogger.hpp"
#include "Snake.hpp"
#include "Collision.hpp"
#include "Background.hpp"
#include <SDL2/SDL.h>
#include <box2d/box2d.h>

int main(int argc, char **argv)
{
	SDL_Log("Starting up, with following arguments:");
	for (int i = 0; i < argc; ++i)
	{
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);

	//Creating collision
	Collision c(b2Vec2(0.0, 0.0));

	//Stuff for creating snakes
	int num_enenmies = 6;
	float offset = 9.0;
	float prev_location = 1.0;

	//Creating and adding background
	Background *b = new Background();
	one.addDrawable(b);

	//Creating frog
	Frogger *f = new Frogger("./assets/frog.png");

	//Creating snakes and adding them
	for (int i = 0; i <= num_enenmies; i++)
	{
		Snake *s = new Snake("./assets/snake.png", rand() % 80 + 1, prev_location + offset, rand() % 10 + 1);
		prev_location = prev_location + offset;
		one.addUpdateable(s);
		one.addDrawable(s);
		b2Body *body = c.addObject(s);
		s->setBody(body);
	}

	//Adding frog to collisons
	b2Body *body = c.addObject(f);
	f->setBody(body);
	one.addUpdateable(f);
	one.addDrawable(f);

	//Adding collisons
	one.addUpdateable(&c);

	//Loading in Key events
	auto f_up = [f](double delta) { f->up(delta); };
	auto f_down = [f](double delta) { f->down(delta); };
	auto f_left = [f](double delta) { f->left(delta); };
	auto f_right = [f](double delta) { f->right(delta); };
	one.addKeyEvent(SDLK_w, f_up);
	one.addKeyEvent(SDLK_a, f_left);
	one.addKeyEvent(SDLK_d, f_right);
	one.addKeyEvent(SDLK_s, f_down);

	engine.setScene(&one);

	// Get the engine running.
	engine.run();
}
