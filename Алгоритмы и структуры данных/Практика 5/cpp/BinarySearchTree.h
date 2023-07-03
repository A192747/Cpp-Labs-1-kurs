#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <stack>
#include "Queue.h"


template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root_(nullptr) {}

	BinarySearchTree(const BinarySearchTree<T>& scr) = delete; //конструктор копирования

	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept: root_(scr->root_)
	{
		scr->root_ = nullptr;
	}

	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete; //конструктор копируваещего присваивания

	void swap(BinarySearchTree <T>& other) noexcept
	{
		std::swap(root_, other.root_);
	}

	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept
	{
		if (this != &src) 
		{
			swap(src);
		}
		return *this;
	}

	virtual ~BinarySearchTree()
	{
		while (this->root_ != nullptr)
		{
			this->deleteKey(this->root_->key_);
		}
	}

	//// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const
	{
		return (this->root_->iterativeSearchNode(key) != nullptr) ? 1 : 0;
	}

	// 2 Вставка нового элемента в дерево: true,если элемент добавлен;
	// false, если элемент уже был
	bool insert(const T& key)
	{
		if (iterativeSearch(key))
			return 0;
		Node <T>* NodeHead = this->root_;
		if (NodeHead == nullptr)
			this->root_ = new Node <T>(key);
		else
		{
			while (NodeHead != nullptr)
			{
				if (NodeHead->key_ > key)
				{
					if (NodeHead->left_ == nullptr)
					{
						NodeHead->left_ = new Node<T>(key);
						NodeHead = nullptr;
					}
					else
						NodeHead = NodeHead->left_;

				}
				else
				{
					if (NodeHead->right_ == nullptr)
					{
						NodeHead->right_ = new Node<T>(key);
						NodeHead = nullptr;
					}
					else
						NodeHead = NodeHead->right_;
				}
			}
			
		}
		return 1;
	}

	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key)
	{
		return root_->deleteNodeKey(this, key);
	}

	//// 4.1 Печать строкового изображения дерева в выходной поток out
	void print(std::ostream& out) const
	{
		return this->root_->printNode(out, this->root_);
	}

	//// 5.1 Определение количества узлов дерева
	int getCount() const
	{
		return this->root_->getCount(this->root_);
	}

	int getHeight() const
	{
		return this->root_->getHeight(this->root_);
	}

	//// 7 Инфиксный обход дерева (итеративный)
	void iterativeInorderWalk() const 
	{
		Node<T>* temp = this->root_;
		auto * stack = new std::stack<Node<T>*>;
		while (temp != nullptr or !stack->empty()) 
		{
			if (temp != nullptr) 
			{
				stack->push(temp);
				temp = temp->left_;
			}
			else
			{ 
				temp = stack->top();
				stack->pop();
				std::cout << temp->key_ << " ";
				temp = temp->right_;
			}
		}
	}

	//// 8.1 Инфиксный обход дерева (рекурсивный)
	void inorderWalk() const
	{
		this->root_->inorderWalk(this->root_);
	}


	//Итеративный метод обхода двоичного дерева по уровням (в ширину)
	void inorderWalk_Wide_Queue(const unsigned int & qsize) const
	{
		this->root_->inorderWalk_Wide_Queue(this->root_, qsize);
	}

	bool isTreeSimilar(const BinarySearchTree<T>& scr)
	{
		Node<T>* temp0 = this->root_;
		auto* stack0 = new std::stack<Node<T>*>;
		MyQueue <T> queue0(this->getCount());
		Node<T>* temp1 = scr.root_;
		auto* stack1 = new std::stack<Node<T>*>;
		MyQueue <T> queue1(scr.getCount());
		while ((temp0 != nullptr or !stack0->empty()) and (temp1 != nullptr or !stack1->empty()))
		{
			if ((temp0 != nullptr) and (temp1 != nullptr))
			{
				if (temp0->key_ != temp1->key_)
					return 0;
				stack0->push(temp0);
				stack1->push(temp1);
				temp0 = temp0->left_;
				temp1 = temp1->left_;
			}
			else
			{
				temp0 = stack0->top();
				temp1 = stack1->top();
				queue0.enQueue(temp0->key_);
				queue1.enQueue(temp1->key_);
				stack0->pop();
				stack1->pop();
				temp0 = temp0->right_;
				temp1 = temp1->right_;
			}
			if (((temp0 != nullptr) and (temp1 == nullptr)) or ((temp0 == nullptr) and (temp1 != nullptr)))
				return 0;
		}
		while (!queue1.isEmpty())
		{
			if (queue0.deQueue() != queue1.deQueue())
				return 0;
		}
		if (queue1.isEmpty() and queue0.isEmpty())
			return 1;
		else
			return 0;
	}

	bool isKeysSimilar(const BinarySearchTree<T>& scr)
	{
		Node<T>* temp0 = this->root_;
		auto* stack0 = new std::stack<Node<T>*>;
		MyQueue <T> queue0(this->getCount());
		while (temp0 != nullptr or !stack0->empty())
		{
			if (temp0 != nullptr)
			{
				stack0->push(temp0);
				temp0 = temp0->left_;
			}
			else
			{
				temp0 = stack0->top();
				stack0->pop();
				queue0.enQueue(temp0->key_);
				temp0 = temp0->right_;
			}
		}
		Node<T>* temp1 = scr.root_;
		auto* stack1 = new std::stack<Node<T>*>;
		MyQueue <T> queue1(scr.getCount());
		while (temp1 != nullptr or !stack1->empty())
		{
			if (temp1 != nullptr)
			{
				stack1->push(temp1);
				temp1 = temp1->left_;
			}
			else
			{
				temp1 = stack1->top();
				stack1->pop();
				queue1.enQueue(temp1->key_);
				temp1 = temp1->right_;
			}
		}
		while (!queue1.isEmpty())
		{
			if (queue0.deQueue() != queue1.deQueue())
				return 0;
		}
		if (!queue1.isEmpty() or !queue0.isEmpty())
			return 0;
		return 1;
	}


private:

	

	template <class T>
	struct Node {
		T key_; // значение ключа, содержащееся в узле
		Node<T>* left_; // указатель на левое поддерево
		Node<T>* right_; // указатель на правое поддерево
		Node<T>* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }
		// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
		Node<T>* iterativeSearchNode(const T& key)
		{
			Node <T>* NodeHead = this;
			if (NodeHead == nullptr)
				return nullptr;
			else
			{
				while (NodeHead != nullptr)
				{
					if (NodeHead->key_ > key)
						NodeHead = NodeHead->left_;
					else
					{
						if (NodeHead->key_ < key)
							NodeHead = NodeHead->right_;
						else
							return NodeHead;
					}
				}
			}
			return nullptr;
		}

		//// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
		void printNode(std::ostream& out, Node<T>* root) const 
		{

			if (root == nullptr)
				return;
			out << root->key_;
			if (!root->left_ and !root->right_)
				return;
			if (root->left_ != nullptr)
			{
				out << " (";
				printNode(out, root->left_);
				out << ") ";
			}
			if (root->right_ != nullptr) 
			{
				out << " (";
				printNode(out, root->right_);
				out << ") ";
			}
		}

		//// 5.2 Рекурсивная функция определения количества узлов дерева
		int getCount(const Node <T>* node) const 
		{
			if (node->left_ == nullptr && node->right_ == nullptr)
				return 1;
			int left, right;
			if (node->left_ != nullptr)
				left = getCount(node->left_);
			else
				left = 0;
			if (node->right_ != nullptr)
				right = getCount(node->right_);
			else
				right = 0;

			return left + right + 1;

		}

		//// 6.2 Рекурсивная функция определения высоты дерева
		int getHeight(const Node <T>* node) const
		{
			if (node == nullptr)
				return 0;
			int left, right;
			if (node->left_ != nullptr) {
				left = getHeight(node->left_);
			}
			else
				left = -1;
			if (node->right_ != nullptr) {
				right = getHeight(node->right_);
			}
			else
				right = -1;
			int max = left > right ? left : right;
			return max + 1;
		}

		//// 8.2 Рекурсивная функция для организации обхода узлов дерева.
		void inorderWalk(Node<T>* node) const
		{
			if (node != nullptr)
			{
				inorderWalk(node->left_);
				std::cout << node->key_ << " ";
				inorderWalk(node->right_);
			}
		}

		bool deleteNodeKey(BinarySearchTree* tr, T num)
		{
			Node <T>* NodeHead = tr->root_;
			Node <T>* NodeTemp = iterativeSearchNode(num);
			Node <T>* NodeTempScd = nullptr;
			Node <T>* NodeTempThr = nullptr;
			if (NodeTemp == nullptr)
				return 0;
			if ((NodeTemp == tr->root_) and ((NodeTemp->left_ == nullptr) and (NodeTemp->right_ == nullptr)))
			{
				delete NodeTemp;
				tr->root_ = nullptr;
				return 1;
			}
			if ((NodeTemp->left_ != nullptr) and (NodeTemp->right_ != nullptr))
			{
				NodeTempThr = NodeTemp;
				NodeTempScd = NodeTemp->right_;
				while (NodeTempScd->left_ != nullptr)
				{
					NodeTempThr = NodeTempScd;
					NodeTempScd = NodeTempScd->left_;
				}
				if (NodeTempScd == NodeTemp->right_)
				{
					NodeTemp->key_ = NodeTempScd->key_;
					NodeTemp->right_ = NodeTemp->right_->right_;
					delete NodeTempScd;
					return 1;
				}
				else
				{
					NodeTemp->key_ = NodeTempScd->key_;
					NodeTempThr->left_ = nullptr;
					delete NodeTempScd;
					return 1;
				}
			}
			if ((NodeTemp->left_ == nullptr) and (NodeTemp->right_ == nullptr))
			{
				while ((NodeHead->right_ != NodeTemp) and ((NodeHead->left_ != NodeTemp)))
				{
					if (NodeHead->key_ > num)
						NodeHead = NodeHead->left_;
					else
					{
						NodeHead = NodeHead->right_;
					}
				}
				if (NodeHead->right_ == NodeTemp)
				{
					NodeHead->right_ = nullptr;
					delete NodeTemp;
					return 1;
				}
				if (NodeHead->left_ == NodeTemp)
				{
					NodeHead->left_ = nullptr;
					delete NodeTemp;
					return 1;
				}
				return 0;
			}
			if (((NodeTemp->left_ != nullptr) and (NodeTemp->right_ == nullptr)) or ((NodeTemp->left_ == nullptr) and (NodeTemp->right_ != nullptr)))
			{
				
				if (NodeTemp->left_ != nullptr)
					NodeTempScd = NodeTemp->left_;
				else
					NodeTempScd = NodeTemp->right_;
				if (NodeTemp == tr->root_)
				{
					delete NodeTemp;
					tr->root_ = NodeTempScd;
					return 1;
				}

				while (1)   
				{
					if (NodeHead->key_ > num)
					{
						if ((NodeHead->left_ == nullptr) or (NodeHead->left_ == NodeTemp))
							break;
						NodeHead = NodeHead->left_;
					}
					else
					{
						if ((NodeHead->right_ == nullptr) or (NodeHead->right_ == NodeTemp))
							break;
						NodeHead = NodeHead->right_;
					}
				}
				if (NodeHead->right_ == NodeTemp)
				{
					NodeHead->right_ = NodeTempScd;
					delete NodeTemp;
					return 1;
				}
				if (NodeHead->left_ == NodeTemp)
				{
					NodeHead->left_ = NodeTempScd;
					delete NodeTemp;
					return 1;
				}
				return 0;
			}
		}

		void inorderWalk_Wide_Queue(Node<T> * root, const unsigned int & qsize) 
		{
			MyQueue <Node<T>*>  queue(qsize);
			queue.enQueue(root);
			while (!queue.isEmpty()) 
			{
				Node <T>* tmp = queue.deQueue();
				std::cout << tmp->key_ << " ";
				//Если есть левый наследник, то в очередь
				if (tmp->left_) 
				{
					queue.enQueue(tmp->left_);
				}
				//Если есть правый наследник, то в очередь
				if (tmp->right_) 
				{
					queue.enQueue(tmp->right_);
				}
			}
		}
	};
	Node<T>* root_; // Указатель на корневой узел
}; // конец шаблона класса TreeBinarySearchTree

#endif
