#include <chrono>

#ifndef __CORE_EVENT_H__
#define __CORE_EVENT_H__

namespace lieEngine::event::time {
    static double getCurrentTime() {
        using Duration = std::chrono::duration<double>;
        return std::chrono::duration_cast<Duration>(
                std::chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    }

    static bool timeout(double source, double delay) {
        if (source + delay < getCurrentTime())
            return true;
        return false;
    }
} // namespace lieEngine
#endif // __CORE_EVENT_H__