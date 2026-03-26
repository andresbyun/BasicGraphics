#include "ApplicationWindow.hpp"

ApplicationWindow::ApplicationWindow(char* title, int width, int height, SDL_WindowFlags flags) :
	aWindow(NULL), aRunning(true)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("[ERROR] Failed to initialize: : %s", SDL_GetError());
		return;
	}

	// Create the window and set the field
	ApplicationWindow::aWindow = SDL_CreateWindow(title, width, height, flags);
}

ApplicationWindow::~ApplicationWindow() {
	// Clean up
	SDL_DestroyWindow(ApplicationWindow::aWindow);
	SDL_Quit();
}

// Main loop of the application
void ApplicationWindow::Loop(AppStatusEnum(*eventHandlerCallback)(SDL_Event*), void(*iterateCallback)()) {
	SDL_Event event;
	int prevTime = 0, frames = 0;
	const int ONE_SECOND = 1000;

	while (ApplicationWindow::aRunning) {
		Uint64 currTime = SDL_GetTicks();

		// Keep running the loop until the event handler returns APPLICATION_END
		if (eventHandlerCallback(&event) == APPLICATION_END) {
			ApplicationWindow::aRunning = false;
		}

		// Draw the next frame
		iterateCallback();
		frames++;

		if (currTime > prevTime + ONE_SECOND) {
			prevTime = currTime;

			SDL_Log("FPS: %d\n", frames);

			frames = 0;
		}
	}

	return;
}
