#pragma once

#include <chrono>

class Timer
{
    using clock = std::chrono::high_resolution_clock;

public:
    Timer();
    void restart();
    long long elapsed();

private:
    clock::time_point m_point;
};
