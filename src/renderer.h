#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <random>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void UpdateWindow();
  void Render(Snake const snake, Snake const dumbEnemy,  SDL_Point const &food, SDL_Point const &power);
  void UpdateWindowTitle(int score, int fps);

 private:
  std::mt19937 engine;
  std::random_device dev;
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif