#pragma once

#include "behavior/CardBehavior.h"
#include <iostream>
#include <memory>
#include <string>

class Card {
public:
    Card();
    std::string title() const;
    void setTitle(const std::string&);
    int cost() const;
    void setCost(const int cost);
    void setBehavior(std::unique_ptr<CardBehavior> behavior);
    void play();

    std::shared_ptr<Card> clone();
    virtual void display()
    {
        std::cout << "title " << title() << std::endl;
        std::cout << "cost " << cost() << std::endl;
    }

private:
    std::unique_ptr<CardBehavior> m_behavior;
    std::string m_title;
    int m_cost;
};
