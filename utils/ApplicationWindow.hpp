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
	 *	The first argument is the state of the application used to communicate between the event handler and the render handler.
	 */
	typedef AppStatusEnum(*EventHandler)(void** appState, SDL_Event* eventHandler);

	/*	RenderHandler:
	 *	Callback for the render handler.
	 *	The first argument is the state of the application used to communicate between the event handler and the render handler.
	 */
	typedef void(*RenderHandler)(void** appState, SDL_Renderer* renderHandler);

	/*	Loop:
	 *	This is the main loop of the application.
	 *	We pass down the application state, the event handler, and a render handler.
	 */
	void Loop(void** appState, EventHandler eventHandler, RenderHandler renderHandler);

private:
	// Fields : they have the `a` prefix to distinguish them as a part of "application"
	SDL_Window* aWindow;		// SDL window instance
	SDL_Renderer* aRenderer;	// SDL renderer instance
	bool aRunning;				// Condition for the main loop
};
