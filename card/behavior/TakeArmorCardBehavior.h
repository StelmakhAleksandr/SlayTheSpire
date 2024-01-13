#pragma once

#include "CardBehavior.h"

class TakeArmorCardBehavior : public CardBehavior {
public:
    TakeArmorCardBehavior();
    void execute() override;
    std::unique_ptr<CardBehavior> clone() override;
};
