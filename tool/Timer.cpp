#include "Timer.h"

Timer::Timer()
{
    restart();
}

void Timer::restart()
{
    m_point = clock::now();
}

long long Timer::elapsed()
{
    auto elapsed = clock::now() - m_point;
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}
