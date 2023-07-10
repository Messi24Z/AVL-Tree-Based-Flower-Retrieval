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
    Node* rLNode= z->right->left;
    if(z!=root){
        switchNodes(parentNode(z),z,z->right);
    }else{
        root = z->right;

    }
    z->left = z->right;
    z->right = rLNode;

}

Node* FlowerTree::rotateRight(Node* z) {
    // implement
    Node* lRNode= z->left->right;
    if(z!=root){
        switchNodes(parentNode(z),z,z->left);
    }else{
        root = z->left;

    }
    z->right = z->left;
    z->left = lRNode;
}

Node* FlowerTree::balance(Node* node) {
    // implement
    //cout<<"balance problem";
    updateHeight(node);
    int bFactor = getBalanceFactor(node);
    if(bFactor == -2){
        if(getBalanceFactor(node->right)==1){
            rotateRight(node->right);
        }
        return rotateLeft(node);
    }else if(bFactor==2){
        if(getBalanceFactor(node->left)==-1){
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
    return node;

}

Node* FlowerTree::insertNode(Node* node, Flower* flower) {
    // implement

    node= new Node(flower);
    if(root== nullptr){
        root = node;
        return node;
    }
      else {
        Node *curr = root;

        while (curr != nullptr) {
            if (node->flower->getPolyphenalOxidase() < curr->flower->getPolyphenalOxidase()) {
                if (curr->left == nullptr) {
                    curr->left = node;

                    curr = nullptr;
                } else
                    curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = node;

                    curr = nullptr;
                } else
                    curr = curr->right;
            }

        }
    }
   node = parentNode(node);
   while(node!= root){
        balance(node);
        node= parentNode(node);
    }
    return  node;
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
    // implement
    while(root!= nullptr){
        removeNode(node);
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
void FlowerTree::switchNodes(Node* parent,Node* curr, Node* node){
    cout<<"hello"<<endl;
    if(parent->left == curr)
        parent->left = node;
    else if(parent->right == curr)
        parent->right = node;


}
Node* FlowerTree::parentNode(Node* node){
    if(node== root)
        return nullptr;
    else{
        Node* curr = root;
        while(curr->right!=node and curr->left!=node){
            if( node->flower->getPolyphenalOxidase()<curr->flower->getPolyphenalOxidase()){
                curr = curr->left;
            }else
                curr=curr->right;
        }
        return curr;
    }

}
void FlowerTree::removeNode(Node* node){
    if (node== nullptr){
        cout<<"nothing to remove here"<<endl;
    }
    if (node->left!=nullptr and node->right!= nullptr ){
        Node* succNode = node->right;
        while(succNode->left!= nullptr){
            succNode = succNode->left;
        }
        node->flower = succNode->flower;
        removeNode(succNode);

    }
    else if( node == root){
        if(node->left != nullptr)
            root = node->left;
        else
            root = node->right;
        //return;
    }
    else if(node->left!=nullptr)
        switchNodes(parentNode(node),node,node->left);
    else
        switchNodes(parentNode(node),node,node->right);

    node = parentNode(node);
    while(node!= nullptr){
        balance(node);
        node = parentNode(node);
    }

}