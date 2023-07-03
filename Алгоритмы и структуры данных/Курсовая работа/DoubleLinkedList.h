#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

#include <iostream>

class DoubleLinkedList
{
private:
    

    struct Node         
    {
        int item_;        
        Node* next_;      
        Node* prev_;      

        
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;         
    Node* head_;        
    Node* tail_;        
 
    void swap(DoubleLinkedList& other) noexcept;
    
    
    Node* head() const { return head_; }

    
    Node* tail() const { return tail_; }

    // Добавление сформированного узла в хвост списка
    void insertTail(Node* x);

    // Добавление сформированного узла в начало списка
    void insertHead(Node* x); // (int item);

  // Удаление заданного узла 
    void deleteNode(Node* x);

    // Поиск узла (адрес) с заданным значением  
    Node* searchNode(int& item);

    // Замена информации узла на новое 
    Node* replaceNode(Node* x, int& item);

public:

    // Конструктор "по умолчанию" - создание пустого списка
    DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }

    // Конструктор "копирования" – создание копии имеющегося списка
    DoubleLinkedList(const DoubleLinkedList& src);

    // Оператор присваивания (копирующее присваивание)
    DoubleLinkedList& operator=(const DoubleLinkedList& right);

    // Конструктор перемещения 
    DoubleLinkedList(DoubleLinkedList&& other) noexcept;

    // Оператор перемещающего присваивания 
    DoubleLinkedList& operator=(DoubleLinkedList&& right) noexcept;
   
    // количество элементов списка
    int count()const { return count_; }

    // Доступ к информации головного узла списка
    int headItem() const;
    int& headItem();

    // Доступ к информации хвостового узла списка
    int tailItem() const;
    int& tailItem();

    // Добавление элемента в голову списка
    void insertHead(int& item);

    // Добавление элемента в хвост списка
    void insertTail(int& item);

    // Удаление элемента с головы списка
    bool deleteHead();

    // Удаление элемента из хвоста списка
    bool deleteTail();

    // Удаление узла с заданным значением  
    bool deleteItem(int& item);

    // Поиск записи с заданным значением  
    bool searchItem(int& item);

    // Замена информации узла на новое 
    bool replaceItem(int& itemOld, int& itemNew);

    // Вывод элементов списка в текстовом виде в стандартный выходной поток 
    void outAll(std::ostream & out);

    int& getCount();

    // Деструктор списка	
    virtual ~DoubleLinkedList();
};
#endif

