#pragma once

#include <string>

#include "core.hpp"

namespace Core
{
    namespace View
    {
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
        } // namespace Component

    } // namespace View

} // namespace Core
