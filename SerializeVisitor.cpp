#include "SerializeVisitor.h"

#include "card/Card.h"

SerializeVisitor::SerializeVisitor()
{
}

void SerializeVisitor::visit(Card& card)
{
    m_json.emplace("title", card.title());
}

std::string SerializeVisitor::result()
{
    return m_json.dump(4);
}
