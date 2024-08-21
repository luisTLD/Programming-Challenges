#ifndef DISK_H
#define DISK_H

class Disk
{
private:
    int size;
    Disk* next;

public:
    Disk(int size) : size(size), next(nullptr) {}
    Disk() : size(0), next(nullptr) {}

    // Getters
    int getSize() const {return this->size;}
    Disk* getNext() const {return this->next;}
    // Setters
    void setNext(Disk* next) {this->next = next;}
};

#endif