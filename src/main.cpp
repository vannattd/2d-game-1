#include "Engine.hpp"
#include "Banana.hpp"
#include "Frogger.hpp"
#include "Snake.hpp"
#include "HUD.hpp"
#include <SDL2/SDL.h>

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

	// Make a banana and add to scene. Should update and draw.
	Frogger *f = new Frogger("./assets/frog.png");
	Snake *s = new Snake("./assets/snake.png");

	one.addUpdateable(f);
	one.addDrawable(f);
	one.addUpdateable(s);
	one.addDrawable(s);
	auto f_up = [f](double delta) { f->up(delta); };
	auto f_down = [f](double delta) { f->down(delta); };
	auto f_left = [f](double delta) { f->left(delta); };
	auto f_right = [f](double delta) { f->right(delta); };
	one.addKeyEvent(SDLK_w, f_up);
	one.addKeyEvent(SDLK_a, f_left);
	one.addKeyEvent(SDLK_d, f_right);
	one.addKeyEvent(SDLK_s, f_down);

	// Add the HUD
	// HUD *h = new HUD();
	// one.addUpdateable(h);
	// one.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&one);

	// Get the engine running.
	engine.run();
}
