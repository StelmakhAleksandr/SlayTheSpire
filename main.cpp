#include "json.hpp"
#include <iostream>

using namespace std;

int main()
{
    nlohmann::json json;

    nlohmann::json cardsJson;

    nlohmann::json cardJson;
    cardJson.emplace("type", "red");
    cardJson.emplace("title", "Hero");

    nlohmann::json cardJson2;
    cardJson2.emplace("type", "blue");
    cardJson2.emplace("title", "Hero");

    cardsJson.push_back(cardJson);
    cardsJson.push_back(cardJson2);

    json.emplace("key", "value");
    json.emplace("key2", "value2");

    json.emplace("cards", cardsJson);

    cout << json.dump(4) << endl;
    return 0;
}

/*

Object - abstract
    id

Card: object - abstract


AttackCard : Card

SkillCard : Card

Deck : object
    vector<Card>;


Visitor

SerializeVisitor
    visit(Deck)
    visit(Card)

SerializeCardVisitor
    visit(AttackCard)
    visit(SkillCard)
    -> json

*/
