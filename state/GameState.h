#pragma once

#include "EventManager.h"
#include "tool/Animation.h"
#include <functional>
#include <iostream>
#include <vector>

class Game;

class GameState
{
public:
    GameState(std::shared_ptr<EventManager> manager, Game* game, std::string group = "");
    virtual ~GameState();
    bool isDirty();
    virtual void handle() = 0;
    void proccessAnimation();

protected:
    std::shared_ptr<EventManager> manager();
    void setDirty(bool dirty);
    Game* game();
    void setState(std::unique_ptr<GameState> state);
    void addFunctionToHandle(std::function<void()>);
    bool runHandleFunctions();
    const std::string& group() const;
    void setActive(bool);
    bool active() const;
    void addAnimation(std::shared_ptr<IAnimation> animation);

private:
    std::shared_ptr<EventManager> m_manager;
    Game* m_game;
    bool m_dirty = true;
    std::vector<std::function<void()>> m_functions;
    std::string m_group;
    bool m_active = true;
    std::vector<std::shared_ptr<IAnimation>> m_animations;
};
