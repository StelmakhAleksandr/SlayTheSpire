#include "ChooseRoomGameState.h"

#include "tool/Animation.h"

ChooseRoomGameState::ChooseRoomGameState(std::shared_ptr<EventManager> manager, Game* game)
    : GameState(manager, game, "ChooseRoomGameState")
{
    manager->addEvent(group(), Key::Down, [this]() {
        std::cout << "Yeah!!!";
        //        setDirty(true);
    });

    m_test = 0;

    addAnimation(std::make_shared<Animation<int>>([this](int value) {
        m_test = value;
        setDirty(true);
    },
        0,
        1000,
        10000));
}

void ChooseRoomGameState::handle()
{
    if (!isDirty()) {
        return;
    }
    system("cls");
    std::cout << "ChooseRoomGameState" << std::endl;

    std::cout << m_test;

    setDirty(false);
}
