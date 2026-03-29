#include <ApplicationWindow.hpp>
#include <glm/vec3.hpp>

struct AppState {
	glm::ivec3 color = { 0x80, 0x00, 0x80 };
} appState;

static ApplicationWindow::AppStatusEnum eventHandler(SDL_Event* event) {
	while (SDL_PollEvent(event)) {
		switch (event->type) {
		case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
			return ApplicationWindow::APPLICATION_END;
		case SDL_EVENT_KEY_DOWN:
			switch (event->key.key) {
			case SDLK_ESCAPE:
				// Close application
				return ApplicationWindow::APPLICATION_END;
			case SDLK_RETURN:
				// Turn background black
				appState.color = { 0x00, 0x00, 0x00 };
				break;
			case SDLK_SPACE:
				// Reset to original color
				appState.color = { 0x80, 0x00, 0x80 };
				break;
			default:
				break;
			}

		default:
			break;
		}
	}

	return ApplicationWindow::APPLICATION_CONTINUE;
}

static void renderHandler(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, appState.color.r, appState.color.g, appState.color.b, 0xFF);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
	int width = 640, height = 480;	// Window dimensions
	ApplicationWindow app("My window", width, height, SDL_WINDOW_RESIZABLE);

	app.Loop(eventHandler, renderHandler);

	return 0;
}
