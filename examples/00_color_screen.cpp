#include <ApplicationWindow.hpp>

static ApplicationWindow::AppStatusEnum eventHandler(SDL_Event* event) {
	while (SDL_PollEvent(event)) {
		switch (event->type) {
		case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
			return ApplicationWindow::APPLICATION_END;
		default:
			break;
		}
	}

	return ApplicationWindow::APPLICATION_CONTINUE;
}

void iterate(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xBB, 0xFF);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
	int width = 640, height = 480;	// Window dimensions
	ApplicationWindow app("My window", width, height, SDL_WINDOW_RESIZABLE);

	app.Loop(eventHandler, iterate);

	return 0;
}
