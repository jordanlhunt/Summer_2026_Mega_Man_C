#include <SDL3/SDL.h>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL! SDL_Error: %s", SDL_GetError());
    return 1;
  }
  SDL_Window *sdlWindow = SDL_CreateWindow("Mega SDL", 640, 480, 0);
  if (sdlWindow == NULL) {
    SDL_Log("Could not create window: %s", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, NULL);
  if (sdlRenderer == NULL) {
    SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
    {
      SDL_DestroyWindow(sdlRenderer);
      SDL_Quit();
      return 1;
    }
  }

  bool isRunning = true;
  SDL_Event sdlEvent;
  while (isRunning) {
    while (SDL_PollEvent(&sdlEvent)) {
      if (sdlEvent.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }
    SDL_SetRenderDrawColor(sdlRenderer, 100, 149, 237, 255);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);
  }
  SDL_DestroyWindow(sdlWindow);
  SDL_DestroyRenderer(sdlRenderer);
  SDL_Quit();
  return 0;
}