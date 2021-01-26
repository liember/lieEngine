#include <chrono>

#ifndef __CORE_EVENT_H__
#define __CORE_EVENT_H__

namespace lieEngine::core::event::time {
    double getCurrentTime() {
        using Duration = std::chrono::duration<double>;
        return std::chrono::duration_cast<Duration>(
                std::chrono::high_resolution_clock::now().time_since_epoch())
                .count();
    }

    bool timeout(double source, double delay) {
        if (source + delay < getCurrentTime())
            return true;
        return false;
    }
} // namespace lieEngine
#endif // __CORE_EVENT_H__