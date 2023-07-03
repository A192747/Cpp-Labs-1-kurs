#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <stack>


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
	};
	Node<T>* root_; // Указатель на корневой узел
}; // конец шаблона класса TreeBinarySearchTree

#endif
