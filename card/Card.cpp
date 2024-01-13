#include "Card.h"

Card::Card()
{
}

std::string Card::title() const
{
    return m_title;
}

void Card::setTitle(const std::string& title)
{
    m_title = title;
}

int Card::cost() const
{
    return m_cost;
}

void Card::setCost(const int cost)
{
    m_cost = cost;
}

void Card::setBehavior(std::unique_ptr<CardBehavior> behavior)
{
    m_behavior = std::move(behavior);
}

void Card::play()
{
    if (m_behavior) {
        m_behavior->execute();
    }
}

std::shared_ptr<Card> Card::clone()
{
    auto card = std::make_shared<Card>();
    card->setTitle(title());
    card->setCost(cost());
    card->setBehavior(m_behavior->clone());
    return card;
}
