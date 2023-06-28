#include "flowerTree.h"

// AVL tree node
Node::Node(Flower* f)
    : flower(f), left(nullptr), right(nullptr), height(1) {}

// FlowerTree class
FlowerTree::FlowerTree()
    : root(nullptr) {}

FlowerTree::~FlowerTree() {
    cleanup(root);
}

int FlowerTree::getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int FlowerTree::getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* FlowerTree::rotateLeft(Node* z) {
    // implement
}

Node* FlowerTree::rotateRight(Node* z) {
    // implement
}

Node* FlowerTree::balance(Node* node) {
   // implement
}

Node* FlowerTree::insertNode(Node* node, Flower* flower) {
    // implement
}

void FlowerTree::insert(Flower* flower) {
    root = insertNode(root, flower);
}

void FlowerTree::displayInOrder(Node* node) {
    // implement
}

void FlowerTree::display() {
    if (root == nullptr) {
        std::cout << "No flowers in the FlowerTree." << std::endl;
        return;
    }

    std::cout << "Flowers in the FlowerTree:" << std::endl;
    displayInOrder(root);
}

bool FlowerTree::comparePolyphenalOxidase(const std::string& id1, const std::string& id2) {
    return id1 < id2;
}

void FlowerTree::cleanup(Node* node) {
    // implement
}
