#include "components.hpp"

using namespace Component;

void Data::Integer::operator+=(Data::Integer i)
{
    _value += i.Get();
}
void Data::Integer::operator+=(long i)
{
    _value += i;
}
void Data::Integer::operator-=(Data::Integer i)
{
    _value -= i.Get();
}
void Data::Integer::operator-=(long i)
{
    _value -= i;
}
void Data::Integer::operator*=(Data::Integer i)
{
    _value *= i.Get();
}
void Data::Integer::operator*=(long i)
{
    _value *= i;
}
void Data::Integer::operator/=(Data::Integer i)
{
    _value /= i.Get();
}
void Data::Integer::operator/=(long i)
{
    _value /= i;
}

void Data::Floating::operator+=(Data::Floating i)
{
    _value += i.Get();
}
void Data::Floating::operator+=(long i)
{
    _value += i;
}
void Data::Floating::operator-=(Data::Floating i)
{
    _value -= i.Get();
}
void Data::Floating::operator-=(long i)
{
    _value -= i;
}
void Data::Floating::operator*=(Data::Floating i)
{
    _value *= i.Get();
}
void Data::Floating::operator*=(long i)
{
    _value *= i;
}
void Data::Floating::operator/=(Data::Floating i)
{
    _value /= i.Get();
}
void Data::Floating::operator/=(long i)
{
    _value /= i;
}

Modificator::ClickArea::ClickArea(const Core::Coursor &cours,
                                  const Component::Data::Floating &x,
                                  const Component::Data::Floating &y,
                                  const Component::Data::Integer &w,
                                  const Component::Data::Integer &h) : x_pos(x),
                                                                       y_pos(y),
                                                                       width(w),
                                                                       height(h),
                                                                       mouse(cours)
{
}

Modificator::ClickArea::~ClickArea()
{
}

bool Modificator::ClickArea::Update()
{
    // m - mouse
    int mx = mouse.GetX();
    int my = mouse.GetY();

    // a - area
    int ax = x_pos.Get();
    int ay = y_pos.Get();
    int aw = width.Get();
    int ah = width.Get();

    if (mx > ax && mx < ax + aw && my > ay && my < ay + ah)
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

bool Modificator::ClickArea::isClecked() const
{
    return clicked;
}

bool Modificator::ClickArea::isHovered() const
{
    return hovered;
}

bool Modificator::ClickArea::isHold() const
{
    return holded;
}
