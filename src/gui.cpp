#include "gui.hpp"

using namespace GUI;

void Text::correctTexture()
{
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = {0, 0, texW, texH};
}

void Text::getTextureText(const char *t)
{
    if (texture == nullptr)
    {
        texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(f, t, color));
    }
    else
    {
        SDL_DestroyTexture(texture);
        texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(f, t, color));
    }
}

void Text::ChangeColor(int r, int g, int b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}

void Text::ChangeSize(int w, int h)
{
    dstrect.w = w;
    dstrect.h = h;
}

void Text::Update() {}

void Text::Draw()
{
    SDL_Rect buf;
    buf.x = pos_x.Get();
    buf.y = pos_y.Get();
    buf.w = dstrect.w;
    buf.h = dstrect.h;
    if (texture)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &buf);
    }
}

Text::Text(std::string font_file, SDL_Renderer *ren, std::string val) : pos_x(0), pos_y(0)
{
    value.swap(val);
    renderer = ren;
    f = TTF_OpenFont(font_file.c_str(), 25);
    texture = nullptr;

    getTextureText(value.c_str());
    correctTexture();
}

Text::~Text()
{
    TTF_CloseFont(f);
}
