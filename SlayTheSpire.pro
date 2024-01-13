TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        App.cpp \
        EventManager.cpp \
        Game.cpp \
        SerializeVisitor.cpp \
        Visitor.cpp \
        card/Card.cpp \
        Item.cpp \
        card/behavior/CardBehavior.cpp \
        card/behavior/CompositeCardBehavior.cpp \
        card/behavior/DealDamageCardBehavior.cpp \
        card/behavior/TakeArmorCardBehavior.cpp \
        character/Character.cpp \
        character/Enemy.cpp \
        character/Player.cpp \
        main.cpp \
        state/BattleGameState.cpp \
        state/ChoosePlayerGameState.cpp \
        state/ChooseRoomGameState.cpp \
        state/GameState.cpp \
        tool/Timer.cpp

HEADERS += \
    App.h \
    EventManager.h \
    Game.h \
    SerializeVisitor.h \
    Visitor.h \
    card/Card.h \
    Item.h \
    card/behavior/CardBehavior.h \
    card/behavior/CompositeCardBehavior.h \
    card/behavior/DealDamageCardBehavior.h \
    card/behavior/TakeArmorCardBehavior.h \
    character/Enemy.h \
    character/Player.h \
    character/Character.h \
    state/BattleGameState.h \
    state/ChoosePlayerGameState.h \
    state/ChooseRoomGameState.h \
    state/GameState.h \
    tool/Animation.h \
    tool/Timer.h

