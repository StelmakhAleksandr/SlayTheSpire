#pragma once

#include "CardBehavior.h"
#include <memory>
#include <vector>

class CompositeCardBehavior : public CardBehavior {
public:
    CompositeCardBehavior();
    void execute() override;
    void addBehavior(std::unique_ptr<CardBehavior> behavior);
    std::unique_ptr<CardBehavior> clone() override;

private:
    std::vector<std::unique_ptr<CardBehavior>> m_behaviors;
};
