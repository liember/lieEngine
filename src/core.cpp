#include "core.hpp"

using namespace Core;

Eventor::Timer::Timer()
{
    creationTime = GetCurrentTime();
}

Eventor::Timer::~Timer() {}

double Eventor::Timer::GetCurrentTime()
{
    using Duration = std::chrono::duration<double>;
    return std::chrono::duration_cast<Duration>(
               std::chrono::high_resolution_clock::now().time_since_epoch())
        .count();
}

bool Eventor::Timer::Timeout(double source, double delay)
{
    if (source + delay < GetCurrentTime())
    {
        return true;
    }
    return false;
}

// MIN CORE

std::vector<Object *> *MinimalCore::GetDrawList()
{
    if (draw == nullptr)
    {
        throw Exception("nullptr draw list");
    }

    std::vector<Object *> *tmp_draw = draw;
    draw = new std::vector<Object *>();

    return tmp_draw;
}

void MinimalCore::Add(Object *p)
{
    objects.push_back(p);
}

void MinimalCore::clean()
{
    for (auto &&i : objects)
    {
        delete i;
    }
}

void MinimalCore::Update()
{
    for (auto &&i : objects)
    {
        if (cur_update % i->update_prior == 0)
        {
            i->Update();
        }

        if (i->draw)
        {
            draw->push_back(i);
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
