#pragma once

#include "EventManager.h"
#include "character/Player.h"
#include "state/GameState.h"
#include <map>
#include <memory>

class Game
{
public:
    enum class State
    {
        ChoosePlayerState,
        BattleState,
        ChooseRoomState
    };
    Game(std::shared_ptr<EventManager> manager);
    void setState(std::unique_ptr<GameState> state);
    void run();

private:
    Player m_player;
    std::unique_ptr<GameState> m_currentState;
};

/* 1) вибір гравця
    2) битва
    3) вибір кімнати
    4) покупка карт
    5) апгрейд карт

*/
