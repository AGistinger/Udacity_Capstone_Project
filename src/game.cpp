#include "game.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <functional>
#include <math.h>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : fish(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, fish);
    Update();
    renderer.Render(fish, food, fish_food);

    frame_end = SDL_GetTicks();

    //If food has not been eaten spawn new food (allows user to avoid eating food larger than yourself)
    update_time += (frame_end - frame_start);
    if(update_time >= 2000)
    {
      PlaceFood();
      update_time = 0;
    }

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }

    //End the game if fish is no longer alive
    if(!fish.alive)
    {
      std::this_thread::sleep_for(std::chrono::seconds(3));
      running = false;
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    fish_food.set_size(std::rand() % ((50 - 10) +1) + 10);
    food.x = x - (ConvPxGrid(fish_food.get_size()));
    food.y = y - (ConvPxGrid(fish_food.get_size()));
    return;
  }
}

//Convert Pixels to Grid
double Game::ConvPxGrid(double px)
{
  return px / px_grid_ratio;
}

void Game::Update() {
  if (!fish.alive) return;

  fish.Update();

  int new_x = static_cast<int>(fish.head_x);
  int new_y = static_cast<int>(fish.head_y);

  // Check if there's food over here
  if(SDL_HasIntersection(&fish.head_rect, &fish_food.food_rect)) {  //checks collision between 2 SDL_Rect
    if(fish.size >= fish_food.get_size())
    {
      score++;
      PlaceFood();
      update_time = 0;
      fish.speed += 0.02;
      fish.size += 2;
    }
    else
    {
      {
        fish.alive = false;
        std::cout << "Game Over!\n";
      }
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return fish.size; }