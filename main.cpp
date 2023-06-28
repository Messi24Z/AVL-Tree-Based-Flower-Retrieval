#include "flower.h"
#include "flowerTree.h"

int main() {
    FlowerTree flowerTree;

    // Create flowers
    Flower* flower1 = new TigerLily("T001", "Orange", 0.8, 6);
    Flower* flower2 = new TigerLily("T002", "Yellow", 1.0, 8);
    Flower* flower3 = new Sunflower("S001", "Yellow", 1.2, 0.8);
    Flower* flower4 = new Sunflower("S002", "Orange", 1.5, 1.0);

    // Insert flowers into FlowerTree
    flowerTree.insert(flower1);
    flowerTree.insert(flower2);
    flowerTree.insert(flower3);
    flowerTree.insert(flower4);

    // Display flowers in FlowerTree
    flowerTree.display();

    return 0;
}
