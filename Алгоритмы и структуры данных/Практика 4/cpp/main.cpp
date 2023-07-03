#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree <int> tree;
    std::cout << (tree.insert(15) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(10) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(12) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(13) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(13) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(20) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.insert(14) ? "I insert" : "BAD") << std::endl;
    std::cout << (tree.iterativeSearch(12) ? "I find it" : "BAD") << std::endl;

    std::cout << "Tree hight:" << tree.getHeight() << std::endl;
    std::cout << "Tree count:" << tree.getCount() << std::endl;





    std::cout << std::endl << "Print tree:" << std::endl;
    tree.print(std::cout);


    std::cout << std::endl << std::endl << "After move constructor:";
    BinarySearchTree <int> tree1;
    tree1 = std::move(tree);  // конструктор перемещения

    std::cout << std::endl << "Print tree1:" << std::endl;
    tree1.print(std::cout);

    std::cout << std::endl << std::endl << "Print tree:" << std::endl;
    tree.print(std::cout);




    std::cout << std::endl << "Delete test - 1:" << std::endl;
    tree1.deleteKey(12);
    tree1.print(std::cout);

    BinarySearchTree <double> tree0;
    std::cout << std::endl << std::endl << "Delete test - 2:" << std::endl;
    std::cout << "Before Delete:" << std::endl;
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

    std::cout << std::endl << std::endl << "After Delete:" << std::endl;
    tree0.deleteKey(3);
    tree0.print(std::cout);

    std::cout << std::endl << std::endl << "After Delete root:" << std::endl;
    tree0.deleteKey(10);
    tree0.print(std::cout);

    std::cout << std::endl << std::endl << "After Delete root:" << std::endl;
    tree0.deleteKey(12);
    tree0.print(std::cout);

    std::cout << std::endl << std::endl << "After Delete root:" << std::endl;
    tree0.deleteKey(15);
    tree0.print(std::cout);

    std::cout << std::endl << std::endl << std::endl << "Test inorderWalk():" << std::endl;
    tree0.inorderWalk();
    std::cout << std::endl << std::endl << "Test iterativeInorderWalk():" << std::endl;
    tree0.iterativeInorderWalk();


}
