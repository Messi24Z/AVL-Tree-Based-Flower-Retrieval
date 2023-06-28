#include "flower.h"

// Base Flower class
Flower::Flower(std::string id, std::string clr, float h)
    : polyphenalOxidase(id), color(clr), height(h), growthStage(0) {}

Flower::~Flower() {}

void Flower::grow() {
    height += 0.1;
    growthStage++;
}

void Flower::display() {
    std::cout << "Flower ID: " << polyphenalOxidase << "\nColor: " << color << "\nHeight: " << height << "\nGrowth Stage: " << growthStage << std::endl;
}

std::string Flower::getPolyphenalOxidase() const {
    return polyphenalOxidase;
}


// Derived TigerLily class
TigerLily::TigerLily(std::string id, std::string clr, float h, int petals)
    : Flower(id, clr, h), petalCount(petals) {}

void TigerLily::display() {
    std::cout << "Tiger Lily - ";
    Flower::display();
    std::cout << "Petal Count: " << petalCount << std::endl;
}


// Derived Sunflower class
Sunflower::Sunflower(std::string id, std::string clr, float h, float size)
    : Flower(id, clr, h), seedSize(size) {}

void Sunflower::display() {
    std::cout << "Sunflower - ";
    Flower::display();
    std::cout << "Seed Size: " << seedSize << std::endl;
}
