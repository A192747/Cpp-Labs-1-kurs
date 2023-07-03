#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <stack>
#include "DoubleLinkedList.h"
#include "ReadAndOut.h"
#include <algorithm>

class BinarySearchTree
{
public:
	BinarySearchTree() : root_(nullptr) {}

	BinarySearchTree(const BinarySearchTree& scr) = delete; //конструктор копирования

	BinarySearchTree(BinarySearchTree&& scr) noexcept: root_(scr.root_)
	{
		scr.root_ = nullptr;
	}

	BinarySearchTree & operator= (const BinarySearchTree & src) = delete; //конструктор копируваещего присваивания

	void swap(BinarySearchTree & other) noexcept
	{
		std::swap(root_, other.root_);
	}

	BinarySearchTree & operator= (BinarySearchTree && src) noexcept
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
	bool iterativeSearch(const std::string& key) const
	{
		return (this->root_->iterativeSearchNode(key) != nullptr) ? 1 : 0;
	}

	// 2 Вставка нового элемента в дерево: true,если элемент добавлен;
	// false, если элемент уже был
	bool insert(const std::string& key, int& strNumber)
	{
		if (iterativeSearch(key))
		{
			this->root_->iterativeSearchNode(key)->List.insertTail(strNumber);
		}
		else
		{
			Node * NodeHead = this->root_;
			if (NodeHead == nullptr)
			{
				this->root_ = new Node(key);
				this->root_->List.insertTail(strNumber);
			}
			else
			{
				while (NodeHead != nullptr)
				{
					if (NodeHead->key_ > key)
					{
						if (NodeHead->left_ == nullptr)
						{
							NodeHead->left_ = new Node(key);
							NodeHead->left_->List.insertTail(strNumber);
							NodeHead = nullptr;
						}
						else
							NodeHead = NodeHead->left_;

					}
					else
					{
						if (NodeHead->right_ == nullptr)
						{
							NodeHead->right_ = new Node(key);
							NodeHead->right_->List.insertTail(strNumber);
							NodeHead = nullptr;
						}
						else
							NodeHead = NodeHead->right_;
					}
				}

			}
			return 1;
		}
	}

	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const std::string key)
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
		Node* temp = this->root_;
		auto * stack = new std::stack<Node*>;
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

	void putInATable(std::ostream & out)
	{
		int maxWordSize = this->root_->findMaxWordSize(this->root_, 0);
		for (int i = 0; i < maxWordSize + 19; i++)
			out << "-";
		out << "\n";
		out  << std::setw(maxWordSize + 1) << std::left << "| Words" << "  |" << "On which line |" <<"\n";
		for (int i = 0; i < maxWordSize + 19; i++)
			out << "-";
		out << "\n";
		this->root_->putInATable(this->root_, maxWordSize + 1, out);
		for (int i = 0; i < maxWordSize + 19; i++)
			out << "-";
		out << "\n";

	}

private:

	


	struct Node {
		std::string key_; // значение ключа, содержащееся в узле
		Node* left_; // указатель на левое поддерево
		Node* right_; // указатель на правое поддерево
		DoubleLinkedList List;
		Node(std::string key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right)
		{ }
		// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
		Node* iterativeSearchNode(const std::string& key)
		{
			Node * NodeHead = this;
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
		void printNode(std::ostream& out, Node* root) const 
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
		int getCount(const Node * node) const 
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
		int getHeight(const Node * node) const
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
		void inorderWalk(Node* node) const
		{
			if (node != nullptr)
			{
				inorderWalk(node->left_);
				std::cout << node->key_ << " ";
				inorderWalk(node->right_);
			}
		}

		std::size_t& findMaxWordSize(Node* node, std::size_t maxword)
		{
			if (node != nullptr)
			{
				findMaxWordSize(node->left_, maxword);
				maxword = std::max(maxword, node->key_.size());
				findMaxWordSize(node->right_, maxword);
			}
			return maxword;
		}

		void putInATable(Node* node, const int& maxWordSize, std::ostream & out) const
		{
			if (node != nullptr)
			{
				putInATable(node->left_, maxWordSize, out);
				out  << "| " << std::setw(maxWordSize) << std::left << node->key_ << "|";
				out << " "; node->List.outAll(out);
				putInATable(node->right_, maxWordSize, out);
			}
		}

		bool deleteNodeKey(BinarySearchTree* tr, std::string num)
		{
			Node * NodeHead = tr->root_;
			Node * NodeTemp = iterativeSearchNode(num);
			Node * NodeTempScd = nullptr;
			Node * NodeTempThr = nullptr;
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
	};
	Node* root_; // Указатель на корневой узел
}; // конец шаблона класса TreeBinarySearchTree

#endif
