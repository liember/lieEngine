#include "clickAreaProperty.hpp"

clickAreaProperty::clickAreaProperty(PropertyControlSystem *pcs) : paddingX(10), paddingY(60)
{
  GPosUse = false;
  delay = 0.5;
  time = 0;
  click = false;
  setID(PROPERTY_BUTTON);
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  m = static_cast<mouse *>(pcs->getProperty(PROPERTY_MOUSE));
  text = static_cast<textProperty *>(pcs->getProperty(PROPERY_TEXT));
  pos->setGUsing(GPosUse);
  but.h = 0;
  but.w = 0;
  but.x = 0;
  but.y = 0;
}

clickAreaProperty::~clickAreaProperty() {}

void clickAreaProperty::setDelay(double d)
{
  delay = d;
}

void clickAreaProperty::setGPosUsing(bool v)
{
  GPosUse = v;
}

void clickAreaProperty::setSize(int w, int h)
{
  but.w = w;
  but.h = h;
}

bool clickAreaProperty::isPressed()
{
  return click;
}

bool clickAreaProperty::isHovered()
{
  return hover;
}

void clickAreaProperty::setPos(double x, double y)
{
  pos->setX(x);
  pos->setY(y);
}

void clickAreaProperty::draw()
{
  SDL_Rect b;
  b.x = pos->getOnlyX() - paddingX;
  b.y = pos->getOnlyY() - paddingY;
  b.w = but.w;
  b.h = but.h;

  if (hover)
  {
    if (click)
    {
      SDL_SetRenderDrawColor(game::getRenderer(), ClickColor.r, ClickColor.g, ClickColor.b, ClickColor.a);
      SDL_RenderFillRect(game::getRenderer(), &b);
    }
    else
    {
      SDL_SetRenderDrawColor(game::getRenderer(), HoverColor.r, HoverColor.g, HoverColor.b, HoverColor.a);
      SDL_RenderFillRect(game::getRenderer(), &b);
    }
  }
  else
  {
    if (bg)
    {
      SDL_SetRenderDrawColor(game::getRenderer(), NormalColor.r, NormalColor.g, NormalColor.b, NormalColor.a);
      SDL_RenderDrawRect(game::getRenderer(), &b);
    }
    else
    {
      SDL_SetRenderDrawColor(game::getRenderer(), BorderColor.r, BorderColor.g, BorderColor.b, BorderColor.a);
      SDL_RenderDrawRect(game::getRenderer(), &b);
    }
  }
}

void clickAreaProperty::update()
{
  but.x = pos->getOnlyX() - paddingX;
  but.y = pos->getOnlyY() - paddingY;
  if (m->getx() > but.x && m->getx() < but.x + but.w)
  {
    if (m->gety() > but.y && m->gety() < but.y + but.h)
    {
      if (m->isClicked())
      {
        if (timer::timeout(time, delay))
        {
          time = timer::GetCurrentTime();
          click = !click;
        }
      }
      else
      {
        hover = true;
      }
    }
  }
  else
  {
    hover = false;
  }
}

void clickAreaProperty::press()
{
  click = !click;
}

void clickAreaProperty::setPaddingX(int v)
{
  paddingX = v;
}

void clickAreaProperty::setPaddingY(int v)
{
  paddingY = v;
}

void clickAreaProperty::setHoverColor(int r, int g, int b, int a)
{
  HoverColor.r = r;
  HoverColor.g = g;
  HoverColor.b = b;
  HoverColor.a = a;
}

void clickAreaProperty::setClickColor(int r, int g, int b, int a)
{
  ClickColor.r = r;
  ClickColor.g = g;
  ClickColor.b = b;
  ClickColor.a = a;
}

void clickAreaProperty::setNormalColor(int r, int g, int b, int a)
{
  NormalColor.r = r;
  NormalColor.g = g;
  NormalColor.b = b;
  NormalColor.a = a;
}

void clickAreaProperty::setBorderColor(int r, int g, int b, int a)
{
  BorderColor.r = r;
  BorderColor.g = g;
  BorderColor.b = b;
  BorderColor.a = a;
}