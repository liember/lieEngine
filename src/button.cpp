#include "includer.hpp"

button::button(int x, int y, const char *t) : positionary(false)
{

    pos = new positionProperty(this);
    pos->setX(x);
    pos->setY(y);
    connectProperty(pos);
    text = new textProperty(this);
    text->setColorRGB(255, 255, 255);
    text->init(t);
    connectProperty(text);
    area = new clickAreaProperty(this);
    area->setSize(200, 60);
    area->setGPosUsing(positionary);
    connectProperty(area);
}

button::~button()
{
}

bool button::isClecked()
{
    return area->isPressed();
}
bool button::isHovered()
{
    return area->isHovered();
}

void button::setSize(int x, int y)
{
    area->setSize(x, y);
}

void button::setPaddings(int x, int y)
{
    area->setPaddingX(x);
    area->setPaddingY(y);
}

void button::setPos(int x, int y)
{
    area->setPos(x, y);
}

void button::setBorederColor(int r, int g, int b)
{
    area->setBorderColor(r, g, b);
}

void button::setBgColor(int r, int g, int b)
{
    area->setNormalColor(r, g, b);
}

void button::setClickColor(int r, int g, int b)
{
    area->setClickColor(r, g, b);
}
void button::setHoverColor(int r, int g, int b)
{
    area->setHoverColor(r, g, b);
}

void button::setTextColor(int r, int g, int b)
{
    text->setColorRGB(r, g, b);
}

void button::setDelay(double d)
{
    area->setDelay(d);
}

void button::press()
{
    area->press();
}