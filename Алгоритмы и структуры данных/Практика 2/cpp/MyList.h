#ifndef MY_LIST
#define MY_LIST
#include <string>

class SinglyOrderedList
{
public:
	SinglyOrderedList();
	virtual ~SinglyOrderedList();
	void insert(std::string str);
	bool searchItem(std::string str);
	bool deleteItem(std::string str);
	void mergewithList(SinglyOrderedList & Sol);
	SinglyOrderedList(const SinglyOrderedList& Sol);
	void outAll();
	int getCount();
	void subtractList(SinglyOrderedList& Sol);
	void crossLists(const SinglyOrderedList& left, const SinglyOrderedList& right);

private:
	
	struct NodeSolo
	{
		struct NodeScd
		{
			std::string item__;
			NodeScd* next__;
			NodeScd(std::string str = "", NodeScd* next = nullptr) : item__(str), next__(next) {}
		};
		~NodeSolo();
		NodeSolo() : head__(nullptr), next_(nullptr) , count__(0), FirstEl('\0') {}
		NodeSolo(std::string str = "", NodeSolo* next = nullptr)
		{
			if (str == "")
				head__ = nullptr;
			else
				head__ = new NodeScd(str); 
			next_ = next; 
			FirstEl = str[0];
			if (str == "")
				count__ = 0;
			else
				count__ = 1;
		}
		void outNodeAll();
		void insertNode(const NodeSolo& Nsolo);
		void insertIteminNode(std::string str);
		bool searchIteminNode(std::string str);
		bool deleteIteminNode(std::string str);
		NodeSolo* next_;
		NodeScd* head__;
		int count__;
		char FirstEl;
	};
	NodeSolo* head_;
	int count_;
};


#endif