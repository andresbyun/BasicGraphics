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

	while (ApplicationWindow::aRunning) {
		if (eventHandlerCallback(&event) == APPLICATION_END) {
			ApplicationWindow::aRunning = false;
		}
		iterateCallback();
	}

	return;
}
