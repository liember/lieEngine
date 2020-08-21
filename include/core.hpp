#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <chrono>
#include <queue>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace Core
{

    class Timer
    {
    private:
        double creationTime;
        double criticalTime;

    public:
        Timer();
        ~Timer();

        double GetCurrentTime();
        // returns true if went more time than <dealy>, count from <source>
        bool Timeout(double source, double delay);
    };

    class Object
    {
    public:
        int draw_id;
        bool isLife;
        bool update;
        bool draw;
        bool update_prior; // high - true / low - false

        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual ~Object(){};
    };

    class Texture
    {
    private:
        void CheckFile(const char *file_name);

        SDL_Texture *_texture;
        SDL_Renderer *renderer;

    public:
        void Draw(int x, int y, int width, int height);

        Texture(std::string file_name, SDL_Renderer *rend);
        ~Texture();
    };

    class ObjectsManager
    {
    private:
        std::vector<Object *> update_list;

        // queue on draw
        std::unique_ptr<std::queue<Object &>> draw;

        // contains while updates update list (every frame)
        std::vector<Object &> objects;

        int max_update_prior; // set automaticly
        int cur_update;       // from 0 up to max_update_prior

    public:
        // update objects and fill draw queue
        void Update();

        // draw all elements in queue
        void Draw();

        // add element to update list
        void Add(Object *p);

        // delete all elements in update list
        void DestroyAll();

        ObjectsManager();
        ~ObjectsManager();
    };

    class Game
    {
    private:
        bool isrunning;
        int screen_w, screen_h;

        ObjectsManager objecs;
        Timer timer;

        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;

        void updateGame();
        void initGame();
        void specificRenderBefore();
        void specificRenderAfter();

    public:
        void initEngine(const char *title, int xpos, int ypos, int width, int height,
                        bool windowed);
        void handleevents();

        void update();
        void render();
        void clean();

        bool running();

        Game(/* args */);
        ~Game();
    };

} // namespace Core
