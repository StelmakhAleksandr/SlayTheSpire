#include "EventManager.h"

#include <conio.h>
#include <iostream>

EventManager::EventManager()
{
}

void EventManager::run()
{
    m_thread = std::make_unique<std::thread>([this] {
        while (true) {
            if (_kbhit() != 0) {
                int keyCode = _getch();
                std::lock_guard<std::mutex> lock(m_mutex);
                for (auto& group : m_functions) {
                    auto it = group.second.find(keyCode);
                    if (it != group.second.end()) {
                        m_futureFunctions.push_back(it->second);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
}

void EventManager::processEvents()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& func : m_futureFunctions) {
        func();
    }
    m_futureFunctions.clear();
}

void EventManager::addEvent(std::string group, Key key, std::function<void()> func)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_functions.find(group);
    if (it == m_functions.end()) {
        m_functions.emplace(group, std::map<int, std::function<void()>>());
    }
    m_functions.at(group).emplace((int)key, func);
}

void EventManager::clearEventsByGroup(std::string group)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_functions.find(group);
    if (it != m_functions.end()) {
        m_functions.erase(it);
    }
}
