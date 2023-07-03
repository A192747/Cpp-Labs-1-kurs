#include <iostream>
#include "BinarySearchTree.h"
#include "Queue.h"

int main()
{

    MyQueue <int> queue(5.5);
    queue.enQueue(5);
    queue.enQueue(6);
    queue.enQueue(7);
    queue.enQueue(8);
    queue.enQueue(9);
    /*ueue.enQueue(10);*/
    /*queue.deQueue();*/
    for (int i = 0; i < 5; i++)
    {
        std::cout << queue.deQueue() << " ";
    }
    std::cout << std::endl;


    BinarySearchTree <double> tree0;
    tree0.insert(10);
    tree0.insert(5);
    tree0.insert(3);
    tree0.insert(2);
    tree0.insert(1);
    tree0.insert(4);
    tree0.insert(4.5);
    tree0.insert(3.9);
    tree0.insert(15);
    tree0.insert(12);
    tree0.insert(16);
    tree0.print(std::cout);

    BinarySearchTree <double> tree1;
    tree1.insert(10);
    tree1.insert(5);
    tree1.insert(4);
    
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(4.5);
    tree1.insert(3.9);
    tree1.insert(15);
    tree1.insert(12);
    tree1.insert(16);
    tree1.insert(5);
    

    std::cout << std::endl << std::endl << "Test inorderWalk():" << std::endl;
    tree0.inorderWalk();
    std::cout << std::endl << "Test iterativeInorderWalk():" << std::endl;
    tree0.iterativeInorderWalk();


    std::cout << std::endl << "Test inorderWalk_Wide_Queue():" << std::endl;
    tree0.inorderWalk_Wide_Queue(4);

    std::cout << std::endl << "Test isTreeSimilar():" << std::endl;
    std::cout << (tree0.isTreeSimilar(tree1) ? "Yes!" : "No!") << std::endl;

    std::cout << std::endl << "Test isKeysSimilar():" << std::endl;
    std::cout << (tree0.isKeysSimilar(tree1) ? "Yes!" : "No!") << std::endl;


}
