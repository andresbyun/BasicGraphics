#pragma once
#include <SDL3/SDL.h>

class ApplicationWindow {
public:
	ApplicationWindow(char* title, int width, int height, SDL_WindowFlags flags);
	~ApplicationWindow();

	enum AppStatusEnum {
		APPLICATION_CONTINUE,
		APPLICATION_END
	};

	void Loop(AppStatusEnum(*eventHandlerCallback)(SDL_Event*), void(*iterateCallback)(SDL_Renderer*));

private:
	// Fields : they have the `a` prefix to distinguish them as a part of "application"
	SDL_Window* aWindow;		// SDL window instance
	SDL_Renderer* aRenderer;	// SDL renderer instance
	bool aRunning;				// Condition for the main loop
};
