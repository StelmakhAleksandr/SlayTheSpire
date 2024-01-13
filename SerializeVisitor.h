#pragma once

#include "Visitor.h"

#include "json.hpp"
#include <string>

class SerializeVisitor : public Visitor {
public:
    SerializeVisitor();
    void visit(Card&) override;
    std::string result();

private:
    nlohmann::json m_json;
};
