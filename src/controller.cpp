#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Fish &fish, Fish::Direction input,
                                 Fish::Direction opposite) const {
  if (fish.direction != opposite || fish.size == 1) fish.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Fish &fish) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(fish, Fish::Direction::kUp,
                          Fish::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(fish, Fish::Direction::kDown,
                          Fish::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(fish, Fish::Direction::kLeft,
                          Fish::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(fish, Fish::Direction::kRight,
                          Fish::Direction::kLeft);
          break;
      }
    }
  }
}