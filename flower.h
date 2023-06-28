#ifndef FLOWER_H
#define FLOWER_H

#include <iostream>
#include <string>

// Base Flower class
class Flower {
protected:
    std::string polyphenalOxidase;
    std::string color;
    float height;
    int growthStage;

public:
    Flower(std::string id, std::string clr, float h);
    virtual ~Flower();

    virtual void grow();
    virtual void display();
    std::string getPolyphenalOxidase() const; // Added member function to access polyphenalOxidase
};

// Derived TigerLily class
class TigerLily : public Flower {
    int petalCount;
public:
    TigerLily(std::string id, std::string clr, float h, int petals);
    void display() override;
};

// Derived Sunflower class
class Sunflower : public Flower {
    float seedSize;
public:
    Sunflower(std::string id, std::string clr, float h, float size);
    void display() override;
};

#endif // FLOWER_H
