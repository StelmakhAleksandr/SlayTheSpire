#include "ChoosePlayerGameState.h"

#include "ChooseRoomGameState.h"

ChoosePlayerGameState::ChoosePlayerGameState(std::shared_ptr<EventManager> manager, Game* game)
    : GameState(manager, game, "ChoosePlayerGameState")
{
    manager->addEvent(group(), Key::Down, [this]() {
        m_active = (m_active + 1) % m_maxPlayers;
        setDirty(true);
    });

    manager->addEvent(group(), Key::Up, [this]() {
        m_active = (m_active - 1 + m_maxPlayers) % m_maxPlayers;
        setDirty(true);
    });

    manager->addEvent(group(), Key::Enter, [this]() {
        addFunctionToHandle([this]() {
            setState(std::make_unique<ChooseRoomGameState>(this->manager(), this->game()));
        });
        setDirty(true);
    });
}

void ChoosePlayerGameState::handle()
{
    if (!runHandleFunctions()) {
        return;
    }
    system("cls");
    std::cout << m_active << std::endl;
    std::cout << (m_active + 1) % m_maxPlayers << std::endl;
    std::cout << "ChoosePlayerGameState" << std::endl;
    for (int i = 0; i < m_maxPlayers; i++) {
        std::cout << i << " player" << (i == m_active ? " (active)" : " ") << std::endl;
    }
    setDirty(false);
}
