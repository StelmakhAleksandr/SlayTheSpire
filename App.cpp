#include "App.h"

App::App()
    : m_manager(std::make_shared<EventManager>())
    , m_game(std::make_unique<Game>(m_manager))
{
}

void App::run()
{
    m_manager->addEvent("App", Key::KeyW, []() {
        std::cout << "we pressed W key" << std::endl;
    });
    m_manager->addEvent("App", Key::KeyD, []() {
        std::cout << "we pressed D key" << std::endl;
    });
    m_manager->run();

    while (true) {
        m_game->run();
        m_manager->processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
