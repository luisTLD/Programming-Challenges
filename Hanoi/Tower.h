#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <limits>
#include "Disk.h"

class Tower
{
private:
    Disk* top;
    int num_tower;

public:
    Tower() : top(nullptr) {}
    ~Tower()
    {
        while (top != nullptr)
        {
            Disk* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

    // Getters
    Disk* getTop() const {return this->top;}
    // Setter
    void setTop(Disk* next) {this->top = next;}
    void setNumTower(int num_tower) {this->num_tower = num_tower;}
    
    // Push, the new size need to be larger than current
    void towerPush(Disk* disk_to_push)
    {
        if (this->top == nullptr || disk_to_push->getSize() < this->top->getSize())
        {
            disk_to_push->setNext(this->top);
            this->top = disk_to_push;
        }
        else
        {
            std::cout << "Try to push disk of size  "<< disk_to_push->getSize() << " to tower " << this->num_tower << std::endl;
            this->showTower();
            throw std::runtime_error("\nPush error: new size is larger than current");
        }
    }

    // Pop
    Disk* towerPop()
    {
        Disk* disk_to_pop = nullptr;
        if (this->top != nullptr)
        {
            disk_to_pop = this->top;
            this->top = this->top->getNext();
            disk_to_pop->setNext(nullptr);
        }
        else
        {
            std::cout << "Try to pop tower: " << this->num_tower << std::endl;
            this->showTower();
            throw std::runtime_error("Pop error: empty tower, returning nullptr");
        }

        return disk_to_pop;
    }

    // showTower
    void showTower() const
    {
        if (this->top != nullptr)
        {
            std::cout << "Tower " << this->num_tower << " : ";
            showTowerCall(this->top);
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Tower " << this->num_tower << " : Empty" << std::endl;
        }
    }
    
private:
    // Recursive Call
    void showTowerCall(Disk* disk) const 
    {
        if (disk != nullptr)
        {
            showTowerCall(disk->getNext());
            std::cout << disk->getSize() << " ";
        }
    }
};

#endif