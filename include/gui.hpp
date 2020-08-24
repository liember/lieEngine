#pragma once

#include <string>

#include "core.hpp"
#include "components.hpp"

namespace GUI
{
    class Text : public Core::Object
    {
    protected:
        Component::Data::Floating pos_x;
        Component::Data::Floating pos_y;
        Component::Data::String value;

    private:
        TTF_Font *f;

        SDL_Renderer *renderer;
        SDL_Color color = {0, 0, 0};
        SDL_Texture *texture;
        SDL_Rect dstrect;

        void getTextureText(const char *t);
        void correctTexture();

    public:
        void Update() override;
        void Draw() override;

        void ChangeColor(int r, int g, int b);
        void ChangeSize(int w, int h);
        void ChangeText(std::string);

        Text(std::string font_file, SDL_Renderer *ren, std::string val);
        ~Text();
    };

} // namespace GUI
