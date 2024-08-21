#ifndef HANOI_H
#define HANOI_H

#include <thread>
#include <chrono>

#include "Tower.h"

class Hanoi
{
private:
    Tower towers[3];
    int num_disks;

public:
    Hanoi(int num_disks) : num_disks(num_disks) 
    {
        for (int i = num_disks; i > 0; i--)
        {
            towers[0].towerPush(new Disk(i));
        }

        towers[0].setNumTower(1);
        towers[1].setNumTower(2);
        towers[2].setNumTower(3);
    }

    // Show All Towers
    void showTowers() const
    {
        for (int i = 0; i < 3; i++)
        {
            towers[i].showTower();
        }

        std::cout << std::endl;
    }

    // Move Disks
    void moveDisks(Tower* source, Tower* target)
    {
        target->towerPush(source->towerPop());

        // If you want to see step by step
        /*
        std::cout << "Actual state of the towers:" << std::endl;
        showTowers();
        std::cin.get();
        */

       // To pause 1 second for each step
       showTowers();
       std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Just Solve the problem
    void solveHanoi()
    {
        if (this->num_disks > 0)
        {
            solveHanoiCall(&towers[0], &towers[1], &towers[2], this->num_disks);
        }
        // showTowers();
    }
    // Recusive Call to solve 
    void solveHanoiCall(Tower* start, Tower* middle, Tower* end, int height)
    {
        if (height == 1)
        {
            solveOneDisk(start, middle, end);
        }
        else
        {
            solveHanoiCall(start, end, middle, height - 1);
            moveDisks(start, end);
            solveHanoiCall(middle, start, end, height - 1);
        }
    }

private:
    // Just transfer the disk to the final tower
    void solveOneDisk(Tower* start, Tower* middle, Tower* end)
    {
        moveDisks(start, end);
    }
};

#endif