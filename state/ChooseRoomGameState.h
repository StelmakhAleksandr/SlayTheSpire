#pragma once

#include "GameState.h"
#include "tool/Timer.h"

class ChooseRoomGameState : public GameState
{
public:
    ChooseRoomGameState(std::shared_ptr<EventManager> manager, Game* game);
    void handle() override;

private:
    int m_test;
};
