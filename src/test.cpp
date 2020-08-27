#include "core.hpp"
#include "view_core.hpp"

#include <iostream>

class obj : public lieEngine::Object
{
private:
  double pos_x;
  double pos_y;

  lieEngine::View::Component::Texture tex;
  lieEngine::View::Component::Label lab;

public:
  void Update() override
  {
    pos_x += 0.01;
  }
  void Draw() override
  {
    tex.Draw(pos_x, pos_y, 50, 50);
    lab.Draw();
  }

  obj(std::string file, SDL_Renderer *ren, std::string name, std::string font);
  ~obj();
};

obj::obj(std::string file,
         SDL_Renderer *ren,
         std::string name,
         std::string font) : tex(file, ren),
                             lab(font, ren, name, pos_x, pos_y)
{
  pos_x = 200;
  pos_y = 200;

  lab.Move(0, -50);
  lab.ChangeColor(255, 255, 255);
  lab.ChangeSize(42, 22);
}

obj::~obj()
{
}

int main()
{
  lieEngine::Core gae;
  lieEngine::View::Window *win = new lieEngine::View::Window("LieEngine v2.3", 300, 200, 1200, 700, false);

  gae.Add(new obj("assets/images/birds/b2.png", win->getRenderer(), "Flosier", "assets/fonts/font.ttf"));

  int counter = 1;
  int update_draw_list_delay = 30;
  std::vector<lieEngine::Object *> *draw = gae.GetDrawList();

  while (gae.running() && win->running())
  {
    win->EventUpdate();
    gae.Update();

    if (counter >= update_draw_list_delay)
    {
      counter = 1;
      delete draw;
      draw = gae.GetDrawList();
    }
    else
    {
      counter++;
    }

    win->Render(draw);
  }
}