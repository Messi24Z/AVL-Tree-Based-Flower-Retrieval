#ifndef FLOWERTREE_H
#define FLOWERTREE_H

#include "flower.h"
using namespace std;

// AVL tree node
class Node {
public:
    Flower* flower;
    Node* left;
    Node* right;
    int height;

    Node(Flower* f);
};

// FlowerTree class
class FlowerTree {
private:
    Node* root;

    // Helper functions
    void cleanup(Node* node);
    int getHeight(Node* node);

    Node* rotateLeft(Node* z);
    Node* rotateRight(Node* z);
    Node* balance(Node* node);
    Node* insertNode(Node* node, Flower* flower);
    void displayInOrder(Node* node);
    void updateHeight(Node* node);

public:
    FlowerTree();
    ~FlowerTree();

    int getBalanceFactor(Node* node);
    void insert(Flower* flower);
    void display();
    void displayRoot();


private:
    bool comparePolyphenalOxidase(const std::string& id1, const std::string& id2); // Added helper function to compare flower IDs
};

#endif // FLOWERTREE_H