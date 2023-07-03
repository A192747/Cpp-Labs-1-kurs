//
// Примеры использования класса DoubleLinkedList
//
#include "DoubleLinkedList.h"
#include <iostream>

int main() {
	DoubleLinkedList list;   // Создание пустого списка
	list.insertTail(5);
	list.insertHead(2);      // Добавление элементов
	list.insertHead(3);
	list.insertHead(1);
	std::cout <<"//List  " << std::endl;
	list.outAll();

	list.deleteItem(2);
	std::cout << std::endl << "//deleteItem 2 " << std::endl;
	list.outAll();
	std::cout << std::endl;
	std::cout << ((list.searchItem(1)) ? "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;
	std::cout << std::endl;

	DoubleLinkedList  list1(list);
	std::cout << std::endl << "//Copying a list " << std::endl;
	list1.outAll();  // Копирование списка
	list1.insertHead(4);         // Добавление элемента
	std::cout << std::endl << "//insert head 4 " << std::endl;
	list1.outAll();
	list1.insertHead(5);         // Добавление элемента
	std::cout << std::endl << "//insert head 5 " << std::endl;
	list1.outAll();
	list1.deleteHead();          // Удаление головного
	std::cout << std::endl << "//Delete head " << std::endl;
	list1.outAll();
	list1.insertHead(6);
	std::cout << std::endl << "//insert head 6" << std::endl;
	list1.outAll();
	list1.deleteHead();
	std::cout << std::endl << "//Delete head " << std::endl;
	list1.outAll();        // Печать результата
	std::cout << std::endl << "//replaceItem(4, 15) " << std::endl;
	list1.replaceItem(4, 15);
	list1.outAll();

	return 0;
}