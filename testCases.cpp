//
// Created by Meseret Mengistie on 7/11/23.
//
#include "flowerTree.h"
#include "flower.h"

int main(){
    cout<<"testing some of the avl functions implemented "<<endl;
    FlowerTree flowerTree;

    // Create flowers
    Flower* flower1 = new TigerLily("T001", "Orange", 0.8, 6);
    Flower* flower2 = new TigerLily("T002", "Yellow", 1.0, 8);
    Flower* flower3 = new Sunflower("S001", "Yellow", 1.2, 0.8);
    Flower* flower4 = new Sunflower("S002", "Orange", 1.5, 1.0);
    Flower* flower5 = new TigerLily("A001", "Orange", 0.4, 6);
    Flower* flower6 = new TigerLily("C002", "Yellow", 1.6, 8);
    Flower* flower7 = new Sunflower("K001", "Yellow", 2.0, 0.8);
    Flower* flower8 = new Sunflower("J002", "Orange", 1.5, 1.0);
    cout<<"\n1st test trying to display an empty tree "<<endl;
    flowerTree.display();

    // Insert flowers into FlowerTree
    cout<<"\n2nd testing a tree with one element which we can assume to be the root with an id of \'T001\'"<<endl;
    flowerTree.insert(flower1);
    flowerTree.display();
    cout<<"\ncurrent root"<<endl;
    flowerTree.displayRoot();

    cout<<"\n3rd test adding two more flowers with ids and display"<<endl;

    flowerTree.insert(flower3);
    flowerTree.insert(flower4);
    flowerTree.display();
    cout<<"\ncurrent root"<<endl;
    flowerTree.displayRoot();

    cout<<"\nour current root is different from the first one proving that our tree balanced itself"<<endl;

    cout<<"\n4th test adding one more flower with the id bigger that what we have inserted to see it's placement in our tree and to show our inorder function is correctly implemented "<<endl;
    flowerTree.insert(flower2);
    flowerTree.display();


    cout<<"\n5th test adding more nodes and checking the current root"<<endl;

    flowerTree.insert(flower5);
    flowerTree.insert(flower6);
    flowerTree.insert(flower7);
    flowerTree.insert(flower8);

    flowerTree.display();
    cout<<"\n=======current root======="<<endl;
    flowerTree.displayRoot();

    cout<<"there is no memory leak for this program which indicates that the function cleanup does remove node properly"<<endl;







    return 0;
}