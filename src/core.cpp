#include "core.hpp"

using namespace Core;

Texture::Texture(std::string file_name, SDL_Renderer *rend)
{
    renderer = rend;
    CheckFile(file_name.c_str());
    SDL_Surface *tempSurf = IMG_Load(file_name.c_str());
    _texture = SDL_CreateTextureFromSurface(renderer, tempSurf);
    SDL_FreeSurface(tempSurf);
};

Texture::Texture(SDL_Texture *textur, SDL_Renderer *rend)
{
    renderer = rend;
    _texture = textur;
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

void Texture::CheckFile(const char *file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (!file)
        throw new std::exception();
}

void Texture::Draw(int x, int y, int width, int height)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = width;
    dest.h = height;
    SDL_RenderCopy(renderer, _texture, nullptr, &dest);
}

Timer::Timer()
{
    creationTime = GetCurrentTime();
}

Timer::~Timer() {}

double Timer::GetCurrentTime()
{
    using Duration = std::chrono::duration<double>;
    return std::chrono::duration_cast<Duration>(
               std::chrono::high_resolution_clock::now().time_since_epoch())
        .count();
}

bool Timer::Timeout(double source, double delay)
{
    if (source + delay < GetCurrentTime())
    {
        return true;
    }
    return false;
}

ObjectsManager::ObjectsManager() : draw(new std::queue<Object *>())
{
}

ObjectsManager::~ObjectsManager()
{
    DestroyAll();
}

void ObjectsManager::Update()
{
    for (auto &&i : update_list)
    {
        if (cur_update % i->update_prior == 0)
        {
            i->Update();
        }

        if (i->draw)
        {
            draw->push(i);
        }
    }

    if (cur_update < max_update_prior)
    {
        cur_update++;
    }
    else
    {
        cur_update = 0;
    }
}

void ObjectsManager::Draw()
{
    std::unique_ptr<std::queue<Object *>> draw_tmp = std::move(draw);
    std::unique_ptr<std::queue<Object *>> new_draw(new std::queue<Object *>());
    draw.swap(new_draw);

    while (!draw_tmp->empty())
    {
        draw_tmp->front()->Draw();
        draw_tmp->pop();
    }
}

void ObjectsManager::Add(Object *p)
{
    update_list.push_back(p);
}

void ObjectsManager::DestroyAll()
{
    for (auto &&i : update_list)
    {
        delete i;
    }
}

MinimalCore::MinimalCore(/* args */) {}

MinimalCore::~MinimalCore()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
}

void MinimalCore::initEngine(const char *title, int xpos, int ypos, int width,
                             int height, bool windowed)
{

    screen_h = height;
    screen_w = width;

    int flags = 0;

    if (windowed)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        TTF_Init();
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        isrunning = true;
    }
    else
    {
        isrunning = false;
    }
}

void MinimalCore::handleevents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;

    default:
        break;
    }
}

int i = 0;

void MinimalCore::update()
{
    objecs.Update();
}

void MinimalCore::render()
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 30, 0);
    SDL_RenderClear(renderer);
    objecs.Draw();
    SDL_RenderPresent(renderer);
}

void MinimalCore::clean()
{
    objecs.DestroyAll();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

// COURSOR

Coursor::Coursor(SDL_Event *events, SDL_Window *window)
{
    ev = events;
    win = window;

    hold = false;
    move = false;
    clicked = false;

    SetPos(0, 0);
}

Coursor::~Coursor() {}

bool Coursor::Update()
{
    bool news = false;
    clicked = false;
    move = false;
    if (ev->type == SDL_MOUSEMOTION)
    {
        news = true;
        move = true;
        SDL_GetMouseState(&xmp, &ymp);
    }
    if (ev->type == SDL_MOUSEBUTTONDOWN)
    {
        news = true;
        hold = true;
    }
    if (ev->type == SDL_MOUSEBUTTONUP)
    {
        news = true;
        hold = false;
        clicked = true;
    }
    return news;
}

void Coursor::SetPos(int x, int y)
{
    SDL_WarpMouseInWindow(win, x, y);
}

int Coursor::GetX() const { return xmp; }
int Coursor::GetY() const { return ymp; }
bool Coursor::isClecked() const { return clicked; }
bool Coursor::isMoved() const { return move; }
bool Coursor::isHold() const { return hold; }
