#include "BattleGameState.h"

BattleGameState::BattleGameState(std::shared_ptr<EventManager> manager, Game* game)
    : GameState(manager, game)
{
}

void BattleGameState::handle()
{
}
