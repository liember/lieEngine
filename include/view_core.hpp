#pragma once
/*
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "core.hpp"

    namespace lieEngine
{
    namespace View
    {
        class Window
        {
        private:
            SDL_Event event;
            SDL_Window *win;
            SDL_Renderer *renderer;

            int screen_w;
            int screen_h;

            bool isrunning;

        public:
            void Render(std::vector<Object *> *list);
            void EventUpdate();

            SDL_Renderer *getRenderer() { return renderer; }

            bool running() { return isrunning; }

            explicit Window(const char *title, int xpos, int ypos, int width, int height,
                            bool windowed);
            ~Window();
        };

        namespace Eventor
        {
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

        namespace Component
        {
            class Label
            {
            protected:
                double &pos_x;
                double &pos_y;

                double x_mv, y_mv;

                std::string value;

            private:
                TTF_Font *f;

                SDL_Renderer *renderer;
                SDL_Color color = {0, 0, 0};
                SDL_Texture *texture;
                SDL_Rect dstrect;

                void getTextureText(const char *t);
                void correctTexture();

            public:
                void Draw();
                void Move(double x, double y);

                void ChangeColor(int r, int g, int b);
                void ChangeSize(int w, int h);
                void ChangeText(std::string);

                Label(std::string font_file, SDL_Renderer *ren, std::string val, double &x, double &y);
                ~Label();
            };

            class ClickArea
            {
            private:
                const double &x_pos;
                const double &y_pos;
                const int &width;
                const int &height;

                const Eventor::Coursor &mouse;

                bool clicked;
                bool holded;
                bool hovered;

            public:
                bool isClecked() const;
                bool isHovered() const;
                bool isHold() const;

                bool Update();

                ClickArea(const Eventor::Coursor &cours,
                          const double &x,
                          const double &y,
                          const int &w,
                          const int &h);
                ~ClickArea();
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
                Texture(SDL_Texture *textur, SDL_Renderer *rend);
                ~Texture();
            };

        } // namespace Component

    } // namespace View

} // namespace lieEngine

*/