#include "../Interfaces/Item.hpp"

#include <iostream>
#include <sstream>

Item::Item() : id(0), weight(0), value(0) {}
Item::Item(int id, int weight, int value) : id(id), weight(weight), value(value) {}

int Item::getId() const {return id;}
void Item::setId(int new_id) {id = new_id;}

int Item::getWeight() const {return weight;}
void Item::setWeight(int w) {weight = w;}

int Item::getValue() const {return value;}
void Item::setValue(int v) {value = v;}

void Item::printItem() const
{
    std::cout << "\nItem ID: " << id << "   Item weight: " << weight << "   Item value: " << value << std::endl;
}

std::string Item::stringItem() const
{
    std::stringstream ss;
    ss << "\nItem ID: " << id << "   Item weight: " << weight << "   Item value: " << value << std::endl;
    return ss.str();
}


bool Item::operator<(const Item& other) const {return this->id < other.id;}