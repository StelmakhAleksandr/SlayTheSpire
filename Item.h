#pragma once

#include <iostream>
#include <memory>
#include <vector>

class Item {

public:
    Item();
    int cost() const
    {
        return m_cost;
    }
    void setCost(const int cost)
    {
        m_cost = cost;
    }

    virtual void play()
    {
        std::cout << "play item " << cost() << std::endl;
    }

private:
    int m_cost;
};

class CompositeItem : public Item {
public:
    void addItem(std::unique_ptr<Item> item)
    {
        m_items.push_back(std::move(item));
    }

    void play() override
    {
        for (auto& item : m_items) {
            item->play();
        }
    }

private:
    std::vector<std::unique_ptr<Item>> m_items;
};
