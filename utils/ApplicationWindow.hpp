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

	/*	EventHandler:
	 *	Callback for the event handler.
	 */
	typedef AppStatusEnum(*EventHandler)(SDL_Event* eventHandler);

	/*	RenderHandler:
	 *	Callback for the render handler.
	 */
	typedef void(*RenderHandler)(SDL_Renderer* renderHandler);

	/*	Loop:
	 *	This is the main loop of the application.
	 */
	void Loop(EventHandler eventHandler, RenderHandler renderHandler);

private:
	// Fields : they have the `a` prefix to distinguish them as a part of "application"
	SDL_Window* aWindow;		// SDL window instance
	SDL_Renderer* aRenderer;	// SDL renderer instance
	bool aRunning;				// Condition for the main loop
};
