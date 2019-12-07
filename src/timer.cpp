#include <iostream>
#include <chrono>

#include "include/timer.hpp"

double timer::deltaTime(0);

timer::timer(double d) : delay(d)
{
    creationTime = GetCurrentTime();
}

timer::timer() : delay(FPS60)
{
    creationTime = GetCurrentTime();
}

timer::~timer()
{
}

void timer::deltaUpdate()
{
    const double current_time = GetCurrentTime();
    deltaTime = current_time - last_render;
}

double timer::GetDelta()
{
    return deltaTime;
}

double timer::GetCurrentTime()
{
    using Duration = std::chrono::duration<double>;
    return std::chrono::duration_cast<Duration>(
               std::chrono::high_resolution_clock::now().time_since_epoch())
        .count();
}

bool timer::FrameTimeout()
{
    const double current_time = GetCurrentTime();
    if ((current_time - last_render) >= delay)
    {
        last_render = current_time;
        return true;
    }
    return false;
}

bool timer::timeout(double source, double delay)
{
    if (source + delay < GetCurrentTime())
    {
        return true;
    }
    return false;
}