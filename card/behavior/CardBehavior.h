#pragma once

#include <memory>

class CardBehavior {
public:
    CardBehavior();
    virtual void execute() = 0;
    virtual std::unique_ptr<CardBehavior> clone() = 0;
};
