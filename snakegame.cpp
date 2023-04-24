#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Window dimensions
const int WIDTH = 640;
const int HEIGHT = 480;

// Snake dimensions
const int SNAKE_WIDTH = 10;
const int SNAKE_HEIGHT = 10;

// Fruit dimensions
const int FRUIT_WIDTH = 10;
const int FRUIT_HEIGHT = 10;

// Direction enumeration
enum class Direction { UP, DOWN, LEFT, RIGHT };

// Snake part structure
struct SnakePart {
    int x, y;
};

// Game variables
bool gameRunning = true;
int score = 0;
Direction direction = Direction::RIGHT;
std::vector<SnakePart> snake = { { 0, 0 } };
int fruitX, fruitY;

// Random number generator
int random(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        std::srand(std::time(nullptr));
        initialized = true;
    }
    return std::rand() % (max - min + 1) + min;
}

// Initialize the game
void init() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Initialize TTF
    TTF_Init();

    // Create the window
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load the font
    TTF_Font* font = TTF_OpenFont("arial.ttf", 16);

    // Generate the fruit position
    fruitX = random(0, WIDTH / FRUIT_WIDTH - 1) * FRUIT_WIDTH;
    fruitY = random(0, HEIGHT / FRUIT_HEIGHT - 1) * FRUIT_HEIGHT;
}

// Draw a rectangle
void drawRect(SDL_Renderer* renderer, int x, int y, int w, int h) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_RenderFillRect(renderer, &rect);
}

// Draw the game
void draw(SDL_Renderer* renderer, TTF_Font* font) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the snake
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto& part : snake) {
        drawRect(renderer, part.x, part.y, SNAKE_WIDTH, SNAKE_HEIGHT);
    }

    // Draw the fruit
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    drawRect(renderer, fruitX, fruitY, FRUIT_WIDTH, FRUIT_HEIGHT);

    // Draw the score
    SDL_Color color = { 255, 255, 255 };
    std::string scoreText = "Score: " + std::to_string(score);
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    SDL_Texture* texture
