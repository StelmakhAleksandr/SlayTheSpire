#pragma once

#include "GameState.h"

class BattleGameState : public GameState
{
public:
    BattleGameState(std::shared_ptr<EventManager> manager, Game* game);
    void handle() override;
};
