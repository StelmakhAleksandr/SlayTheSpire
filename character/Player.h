#pragma once

#include "Character.h"
#include "Item.h"
#include "card/Card.h"
#include <deque>
#include <vector>

class Player : public Character {
public:
    Player();

private:
    std::deque<Card> m_hand;
    std::deque<Card> m_addiction;
    std::vector<Item> m_items;
    int m_mp;
    int m_gold;
};
