#include "core.hpp"

using namespace lieEngine;

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

std::vector<Object *> *Core::GetDrawList()
{
    // list of objects what may will rendered
    std::vector<Object *> *draw = new std::vector<Object *>();
    if (draw == nullptr)
    {
        throw Exception("nullptr draw list");
    }

    for (auto &&i : objects)
    {
        if (i->draw)
        {
            draw->push_back(i);
        }
    }
    return draw;
}

void Core::Add(Object *p)
{
    objects.push_back(p);
}

void Core::clean()
{
    for (auto &&i : objects)
    {
        delete i;
    }
}

void Core::Update()
{
    for (auto &&i : objects)
    {
        if (cur_update % i->getUpdatePrior() == 0)
        {
            i->Update();
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
