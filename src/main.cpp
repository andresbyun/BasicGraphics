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

void iterate() {
	// TODO: Add a fps counter
}

int main(int argc, char** argv) {
	ApplicationWindow app("My window", 640, 480, SDL_WINDOW_RESIZABLE);

	app.Loop(eventHandler, iterate);

	return 0;
}
