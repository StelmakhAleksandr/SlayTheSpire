#include "CompositeCardBehavior.h"

CompositeCardBehavior::CompositeCardBehavior()
{
}

void CompositeCardBehavior::execute()
{
    for (auto& behavior : m_behaviors) {
        behavior->execute();
    }
}

void CompositeCardBehavior::addBehavior(std::unique_ptr<CardBehavior> behavior)
{
    m_behaviors.push_back(std::move(behavior));
}

std::unique_ptr<CardBehavior> CompositeCardBehavior::clone()
{
    auto compositeBehavior = std::make_unique<CompositeCardBehavior>();
    for (auto& behavior : m_behaviors) {
        compositeBehavior->addBehavior(behavior->clone());
    }
    return compositeBehavior;
}
