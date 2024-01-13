#include "Game.h"
#include "state/ChoosePlayerGameState.h"

Game::Game(std::shared_ptr<EventManager> manager)
{
    setState(std::make_unique<ChoosePlayerGameState>(manager, this));
}

void Game::setState(std::unique_ptr<GameState> state)
{
    m_currentState = std::move(state);
}

void Game::run()
{
    m_currentState->handle();
    m_currentState->proccessAnimation();
}
