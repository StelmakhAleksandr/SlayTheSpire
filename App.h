#pragma once

#include "EventManager.h"
#include "Game.h"

class App
{
public:
    App();
    void run();

private:
    std::shared_ptr<EventManager> m_manager;
    std::unique_ptr<Game> m_game;
};
