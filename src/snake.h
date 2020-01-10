#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"

class Fish {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Fish(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  double size {20};
  bool alive{true};
  float head_x;
  float head_y;
  SDL_Rect head_rect;  //variable used to pass info to game functionality

 private:
  void UpdateHead();

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif