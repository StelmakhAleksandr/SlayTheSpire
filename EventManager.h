#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

enum class Key
{
    Up = 72,
    Left = 75,
    Down = 80,
    Right = 77,
    KeyW = 119,
    KeyA = 97,
    KeyS = 115,
    KeyD = 100,
    Enter = 13,
};

class EventManager
{
public:
    EventManager();
    void run();
    void processEvents();
    void addEvent(std::string group, Key key, std::function<void()> func);
    void clearEventsByGroup(std::string group);

private:
    std::unique_ptr<std::thread> m_thread;
    std::mutex m_mutex;
    std::map<std::string, std::map<int, std::function<void()>>> m_functions;
    std::vector<std::function<void()>> m_futureFunctions;
};
