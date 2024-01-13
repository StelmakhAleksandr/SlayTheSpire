#pragma once

#include "CardBehavior.h"

class DealDamageCardBehavior : public CardBehavior {
public:
    DealDamageCardBehavior();
    void execute() override;
    std::unique_ptr<CardBehavior> clone() override;
};
