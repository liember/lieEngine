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
