#pragma once

class Card;

class Visitor {
public:
    Visitor();
    virtual void visit(Card&) = 0;
};
