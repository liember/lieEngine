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
    namespace Eventor
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

        class Coursor
        {
        private:
            int xmp, ymp;
            int deltaX, deltaY;

            bool clicked;
            bool move;
            bool hold;

            bool block;

            SDL_Event *ev;
            SDL_Window *win;

        public:
            Coursor(SDL_Event *events, SDL_Window *window);
            ~Coursor();

            void SetPos(int x, int y);

            int GetX() const;
            int GetY() const;

            bool isClecked() const;
            bool isMoved() const;
            bool isHold() const;

            // returns true if mouse have new state
            bool Update();
        };
    } // namespace Eventor

    class Exception : virtual public std::exception
    {

    protected:
        const std::string error_message;

    public:
        explicit Exception(const std::string &msg) : error_message(msg)
        {
        }
        virtual ~Exception() throw() {}

        virtual const char *what() const throw()
        {
            return error_message.c_str();
        }
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

    class ObjectsManager
    {
    private:
        std::vector<Object *> update_list;

        // queue on draw
        std::unique_ptr<std::queue<Object *>> draw;

        // contains while updates update list (every frame)
        std::vector<Object *> objects;

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

    class MinimalCore
    {
    private:
        bool isrunning;

        int screen_w;
        int screen_h;

        ObjectsManager objecs;
        Eventor::Timer timer;

        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        void initEngine(const char *title, int xpos, int ypos, int width, int height,
                        bool windowed);
        void handleevents();

        void update();
        void render();
        void clean();

        bool running() { return isrunning; }

        MinimalCore(/* args */);
        ~MinimalCore();
    };

} // namespace Core
