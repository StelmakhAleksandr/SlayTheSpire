#include "GameState.h"

#include "Game.h"

GameState::GameState(std::shared_ptr<EventManager> manager, Game* game, std::string group)
    : m_manager(std::move(manager))
    , m_game(game)
    , m_group(group)
{
}

GameState::~GameState()
{
    manager()->clearEventsByGroup(group());
}

bool GameState::isDirty()
{
    return m_dirty;
}

void GameState::proccessAnimation()
{
    for (const auto& animation : m_animations) {
        animation->run();
    }
}

std::shared_ptr<EventManager> GameState::manager()
{
    return m_manager;
}

void GameState::setDirty(bool dirty)
{
    m_dirty = dirty;
}

Game* GameState::game()
{
    return m_game;
}

void GameState::setState(std::unique_ptr<GameState> state)
{
    game()->setState(std::move(state));
}

void GameState::addFunctionToHandle(std::function<void()> func)
{
    m_functions.push_back(func);
}

bool GameState::runHandleFunctions()
{
    for (auto& func : m_functions) {
        func();
    }
    m_functions.clear();
    if (!isDirty() || !active())
        return false;
    return true;
}

const std::string& GameState::group() const
{
    return m_group;
}

void GameState::setActive(bool active)
{
    m_active = active;
}

bool GameState::active() const
{
    return m_active;
}

void GameState::addAnimation(std::shared_ptr<IAnimation> animation)
{
    m_animations.push_back(animation);
}
