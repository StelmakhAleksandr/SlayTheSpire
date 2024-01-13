#include "TakeArmorCardBehavior.h"

#include <iostream>

TakeArmorCardBehavior::TakeArmorCardBehavior()
{
}

void TakeArmorCardBehavior::execute()
{
    std::cout << "TakeArmorCardBehavior" << std::endl;
}

std::unique_ptr<CardBehavior> TakeArmorCardBehavior::clone()
{
    return std::make_unique<TakeArmorCardBehavior>();
}
