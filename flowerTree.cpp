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
    Node* x= z->right;
    Node* y= x->left;
    //rotate
    x->left=z;
    z->right=y;
    //height update
    updateHeight(z);
    updateHeight(x);

    return x;

}

Node* FlowerTree::rotateRight(Node* z) {
    // implement
    Node* x= z->left;
    Node* y= x->right;
    //rotate
    x->right=z;
    z->left=y;
    //height update
    updateHeight(z);
    updateHeight(x);

    return x;

}

Node* FlowerTree::balance(Node* node) {
    // implement

    updateHeight(node);
    int bf =getBalanceFactor(node);
    int rbf= getBalanceFactor(node->right);
    int lbf= getBalanceFactor(node->left);
    if(bf<-1 && rbf<=0)
        return rotateLeft(node);
    else if(bf>1 && lbf>=0)
        return rotateRight(node);
    else if(bf<-1 and rbf>=0){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }else if(bf>1 and lbf<=0){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }else
        return node;
}

Node* FlowerTree::insertNode(Node* node, Flower* flower) {
    // implement


   if (node== nullptr){
       node = new Node(flower);
       return node;
   }
   if(flower->getPolyphenalOxidase()<node->flower->getPolyphenalOxidase()){
       node->left = insertNode(node->left,flower);
       return balance(node);
   }else if(flower->getPolyphenalOxidase()>node->flower->getPolyphenalOxidase()){
       node->right = insertNode(node->right,flower);
       return balance(node);
   }

   else
       return node;



}

void FlowerTree::insert(Flower* flower) {
    root = insertNode(root, flower);
}

void FlowerTree::displayInOrder(Node* node) {
    // implement
    if( node == nullptr)
        return;

    displayInOrder(node->left);
    node->flower->display();
    displayInOrder(node->right);
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
    if(node== nullptr){
        return;
    }else{
        cleanup(node->left);
        cleanup(node->right);
        delete node->flower;
        delete node;

    }

}
void FlowerTree::updateHeight(Node* node){
    int lHeight= -1;
    if(node->left!= nullptr){
        lHeight = node->left->height;
    }
    int rHeight = -1;
    if(node->right != nullptr){
        rHeight= node->right->height;
    }
    node->height= max(lHeight,rHeight) + 1;


}



//a function that helps test the other functions in this class
void FlowerTree::displayRoot() {
    // implement
    root->flower->display();



}
