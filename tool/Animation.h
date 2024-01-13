#pragma once

#include "tool/Timer.h"
#include <functional>

class IAnimation
{
public:
    virtual void run() = 0;
    virtual bool isFinished() = 0;
};

template <class C>
class Animation : public IAnimation
{
public:
    Animation(std::function<void(C value)>, C start, C end, long long duration);
    void run() override;
    bool isFinished() override;

private:
    std::function<void(C value)> m_propertySetter;
    C m_start;
    C m_end;
    C m_current;
    long long m_duration;
    Timer m_timer;
    long long m_timeChange;
    float m_change;
    bool m_finished = false;
};

template <class C>
Animation<C>::Animation(std::function<void(C)> propertySetter, C start, C end, long long duration)
    : m_propertySetter(propertySetter)
    , m_start(start)
    , m_end(end)
    , m_duration(duration)
{
    m_timeChange = duration / (end - start);
    m_change = (end - start) / (duration / m_timeChange);
    m_current = m_start;
    propertySetter(m_current);
}

template <class C>
void Animation<C>::run()
{
    if (m_finished) {
        return;
    }
    if (m_timer.elapsed() > m_timeChange) {
        m_current += m_change;
        if (m_current >= m_end) {
            m_current = m_end;
            m_finished = true;
        }
        m_propertySetter(m_current);
    }
}

template <class C>
bool Animation<C>::isFinished()
{
    return m_finished;
}
