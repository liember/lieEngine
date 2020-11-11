#include "core_view.hpp"

using namespace lieEngine::View;
/*
void Component::Label::correctTexture()
{
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = {0, 0, texW, texH};
}

void Component::Label::getTextureText(const char *t)
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

void Component::Label::ChangeColor(int r, int g, int b)
{
    color.r = r;
    color.g = g;
    color.b = b;
    getTextureText(value.c_str());
}

void Component::Label::ChangeSize(int w, int h)
{
    dstrect.w = w;
    dstrect.h = h;
}

void Component::Label::Move(double x, double y)
{
    x_mv = x;
    y_mv = y;
}

void Component::Label::Draw()
{
    SDL_Rect buf;
    buf.x = pos_x + x_mv;
    buf.y = pos_y + y_mv;
    buf.w = dstrect.w;
    buf.h = dstrect.h;
    if (texture)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &buf);
    }
}

Component::Label::Label(std::string font_file, SDL_Renderer *ren, std::string val, double &x, double &y) : pos_x(x), pos_y(y)
{
    value.swap(val);
    renderer = ren;
    f = TTF_OpenFont(font_file.c_str(), 25);
    texture = nullptr;

    getTextureText(value.c_str());
    correctTexture();
}

Component::Label::~Label()
{
    TTF_CloseFont(f);
}

// CLICK AREA

Component::ClickArea::ClickArea(const Eventor::Coursor &cours,
                                const double &x,
                                const double &y,
                                const int &w,
                                const int &h) : x_pos(x),
                                                y_pos(y),
                                                width(w),
                                                height(h),
                                                mouse(cours)
{
}

Component::ClickArea::~ClickArea()
{
}

bool Component::ClickArea::Update()
{
    int x = mouse.GetX();
    int y = mouse.GetY();

    if (x > x_pos && x < x_pos + width && y > y_pos && y < y_pos + height)
    {
        clicked = mouse.isClecked();
        holded = mouse.isHold();
        hovered = true;
        return true;
    }
    else
    {
        return false;
    }
}

bool Component::ClickArea::isClecked() const
{
    return clicked;
}

bool Component::ClickArea::isHovered() const
{
    return hovered;
}

bool Component::ClickArea::isHold() const
{
    return holded;
}

// TEXTURE

Component::Texture::Texture(std::string file_name, SDL_Renderer *rend)
{
    renderer = rend;
    CheckFile(file_name.c_str());
    SDL_Surface *tempSurf = IMG_Load(file_name.c_str());
    _texture = SDL_CreateTextureFromSurface(renderer, tempSurf);
    SDL_FreeSurface(tempSurf);
};

Component::Texture::Texture(SDL_Texture *textur, SDL_Renderer *rend)
{
    renderer = rend;
    _texture = textur;
}

Component::Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

void Component::Texture::CheckFile(const char *file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (!file)
        throw new std::exception();
}

void Component::Texture::Draw(int x, int y, int width, int height)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = width;
    dest.h = height;
    SDL_RenderCopy(renderer, _texture, nullptr, &dest);
}

// COURSOR

Eventor::Coursor::Coursor(SDL_Event *events, SDL_Window *window)
{
    ev = events;
    win = window;

    hold = false;
    move = false;
    clicked = false;

    SetPos(0, 0);
}

Eventor::Coursor::~Coursor() {}

bool Eventor::Coursor::Update()
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

void Eventor::Coursor::SetPos(int x, int y)
{
    SDL_WarpMouseInWindow(win, x, y);
}

int Eventor::Coursor::GetX() const { return xmp; }
int Eventor::Coursor::GetY() const { return ymp; }
bool Eventor::Coursor::isClecked() const { return clicked; }
bool Eventor::Coursor::isMoved() const { return move; }
bool Eventor::Coursor::isHold() const { return hold; }

*/
// WINDOW

Window::Window(const char *title, int width, int height)
{
    if (!glfwInit())
        throw Exception("GLFW init error");

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        throw Exception("GLFW window init error");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        throw Exception("GLAD init error");
    }

    glViewport(0, 0, width, height);
    glClearColor(0, 1, 0, 1);

    isrunning = true;
}

Window::~Window()
{
    glfwTerminate();
}

void Window::EventUpdate()
{
    isrunning = !glfwWindowShouldClose(window);
    glfwPollEvents();
}

// void Window::Render()
// {
//     /* Render here */
//     //glClear(GL_COLOR_BUFFER_BIT);
//     /* Swap front and back buffers */
//     //glfwSwapBuffers(window);
//     /* Poll for and process events */
// }
