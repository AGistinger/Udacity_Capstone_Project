#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "SDL.h"
#include "snake.h"
#include "fish_food.h"
#include "SDL_image.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Fish &fish, SDL_Point const &food, Fish_Food &fish_food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture* load_image(const std::string &img_path, SDL_Renderer* sdl_renderer);

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  SDL_Texture* background;
};

#endif