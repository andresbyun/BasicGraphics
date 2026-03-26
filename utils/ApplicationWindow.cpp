#define ONE_SECOND 1000	// One second in milliseconds
#define FRAME_CAP 60	// Max fps

#include "ApplicationWindow.hpp"

ApplicationWindow::ApplicationWindow(char* title, int width, int height, SDL_WindowFlags flags) :
	aWindow(nullptr), aRenderer(nullptr), aRunning(true)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("[ERROR] Failed to initialize: %s", SDL_GetError());
		return;
	}

	aWindow = SDL_CreateWindow(title, width, height, flags);
	aRenderer = SDL_CreateRenderer(aWindow, nullptr);

	if (aWindow == nullptr || aRenderer == nullptr) {
		SDL_Log("[ERROR] Failed to create window/renderer: %s", SDL_GetError());
	}
}

ApplicationWindow::~ApplicationWindow() {
	// Clean up
	SDL_DestroyRenderer(aRenderer);
	SDL_DestroyWindow(aWindow);
	SDL_Quit();
}

// Main loop of the application
void ApplicationWindow::Loop(AppStatusEnum(*eventHandlerCallback)(SDL_Event*), void(*iterateCallback)(SDL_Renderer*)) {
	SDL_Event event;
	Uint64 prevTime = 0, deltaTime = 0;
	int fps = 0;	// Frames Per Second

	while (aRunning) {
		Uint64 currTime = SDL_GetTicks();
		deltaTime = currTime - prevTime;

		// Keep running the loop until the event handler returns APPLICATION_END
		if (eventHandlerCallback(&event) == APPLICATION_END) {
			aRunning = false;
		}

		// Draw the next frame as long as we haven't hit the frame cap
		if (fps < FRAME_CAP) {
			iterateCallback(aRenderer);
			fps++;
		}

		if (deltaTime >= ONE_SECOND) {
			prevTime = currTime;	// Set previous time to the current time

			SDL_Log("FPS: %d\n", fps);

			fps = 0; // Reset the fps counter
		}
	}
}
