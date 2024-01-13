#pragma once

#include "GameState.h"

class ChoosePlayerGameState : public GameState
{
public:
    ChoosePlayerGameState(std::shared_ptr<EventManager> manager, Game* game);
    void handle() override;

private:
    int m_active = 0;
    int m_maxPlayers = 4;
};
