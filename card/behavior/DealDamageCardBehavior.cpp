#include "DealDamageCardBehavior.h"

#include <iostream>

DealDamageCardBehavior::DealDamageCardBehavior()
{
}

void DealDamageCardBehavior::execute()
{
    std::cout << "DealDamageCardBehavior" << std::endl;
}

std::unique_ptr<CardBehavior> DealDamageCardBehavior::clone()
{
    return std::make_unique<DealDamageCardBehavior>();
}
