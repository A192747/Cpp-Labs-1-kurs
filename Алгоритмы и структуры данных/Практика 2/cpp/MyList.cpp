#include "MyList.h"
#include <iostream>
#include <string>

SinglyOrderedList::SinglyOrderedList() : count_(0), head_(nullptr) {}

SinglyOrderedList::~SinglyOrderedList()
{
	NodeSolo* temp = head_;
	NodeSolo* prev = nullptr;
	while (temp != nullptr)
	{
		prev = temp;
		temp = temp->next_;
		delete prev;
	}

}

void SinglyOrderedList::insert(std::string str)
{
	if (!searchItem(str))
	{
		if (this->head_ == nullptr)
		{
			this->head_ = new NodeSolo(str);
			this->head_->FirstEl = str[0];
			this->head_->count__ = 1;
			count_++;
		}
		else
		{

			NodeSolo* temp = this->head_;
			bool ist = 0;
			bool find = 0;
			while ((temp != nullptr) and (find != 1))
			{
				if (temp->FirstEl == str[0])
					find = 1;
				temp = temp->next_;
			}
			if (!find)
			{
				NodeSolo* prev = nullptr;
				temp = this->head_;
				while ((temp != nullptr) and (temp->FirstEl < str[0]) )
				{
					prev = temp;
					temp = temp->next_;
				}
				if (prev == nullptr)
				{
					NodeSolo* New_elem = new NodeSolo(str, temp);
					New_elem->FirstEl = str[0];
					this->head_ = New_elem;
				}
				else
				{
					prev->next_ = new NodeSolo(str, temp);
					prev->next_->FirstEl = str[0];
				}
				count_++;
			}
			else
			{
				temp = this->head_;
				while ((temp != nullptr) and (ist != 1))
				{
					if (temp->FirstEl == str[0])
					{
						temp->insertIteminNode(str);
						ist = 1;
					}
					else
					{
						temp = temp->next_;
					}
				}
			}
		}
	}

}

bool SinglyOrderedList::searchItem(std::string str)
{
	NodeSolo* temp = this->head_;
	while (temp != nullptr)
	{
		if (temp->searchIteminNode(str))
			return 1;
		temp = temp->next_;
	}
	return 0;
}

bool SinglyOrderedList::deleteItem(std::string str)
{
	if (searchItem(str))
	{
		NodeSolo* temp = this->head_;
		NodeSolo* prev = nullptr;
		while (temp->FirstEl != str[0])
		{
			prev = temp;
			temp = temp->next_;
		}
		if (temp->count__ == 1)
		{
			if (prev != nullptr)
				prev->next_ = temp->next_;
			else
				this->head_ = temp->next_;
			delete temp;
			this->count_--;
		}
		else
			temp->deleteIteminNode(str);
		return 1;
	}
	return 0;
}

void SinglyOrderedList::mergewithList(SinglyOrderedList & Sol) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	NodeSolo* temp = Sol.head_;
	SinglyOrderedList::NodeSolo::NodeScd* tempscdl = nullptr;
	if (temp != nullptr)
	{
		while (temp != nullptr)
		{
			tempscdl = temp->head__;
			while (tempscdl != nullptr)
			{
				this->insert(tempscdl->item__);
				tempscdl = tempscdl->next__;
			}
			temp = temp->next_;
		}
	}
	Sol.~SinglyOrderedList();
	Sol = * new SinglyOrderedList();
}

SinglyOrderedList::SinglyOrderedList(const SinglyOrderedList& Sol)
{
	this->count_ = 0;
	this->head_ = nullptr;
	NodeSolo* temp = Sol.head_;
	NodeSolo* tempo = this->head_;
	NodeSolo* prev = nullptr;
	while (temp != nullptr)
	{
		if (tempo == nullptr)
		{
			tempo = new NodeSolo("");
			this->head_ = tempo;
		}
		else
		{
			tempo = new NodeSolo("");
		}
		
		if (prev != nullptr)
			prev->next_ = tempo;
		tempo->FirstEl = temp->FirstEl;
		tempo->insertNode(*temp);
		prev = tempo;
		this->count_++;
		if (temp->next_ == nullptr)
		{
			tempo->next_ = nullptr;
		}
		temp = temp->next_;
	}
}

void SinglyOrderedList::outAll()
{
	if (this->count_ != 0)
	{
		NodeSolo* current = this->head_;
		while (current != nullptr)
		{
			current->outNodeAll();
			std::cout << std::endl;
			current = current->next_;
		}
	}
	else
		std::cout << "List is empty!" << std::endl;
	

}

int SinglyOrderedList::getCount()
{
	return this->count_;
}

void SinglyOrderedList::subtractList(SinglyOrderedList& Sol)
{
	NodeSolo* lefttemp = this->head_;
	NodeSolo* nextSolo = nullptr;
	SinglyOrderedList::NodeSolo::NodeScd* tempscdl = nullptr;
	SinglyOrderedList::NodeSolo::NodeScd* next = nullptr;
	if (lefttemp != nullptr)
	{
		
		while (lefttemp != nullptr)
		{
			nextSolo = lefttemp->next_;
			tempscdl = lefttemp->head__;
			while (tempscdl != nullptr)
			{
				next = tempscdl->next__;
				if ((this->searchItem(tempscdl->item__)) and (Sol.searchItem(tempscdl->item__)))
					this->deleteItem(tempscdl->item__);
				tempscdl = next;
			}
			lefttemp = nextSolo;
		}
	}

}

void SinglyOrderedList::crossLists(const SinglyOrderedList& left, const SinglyOrderedList& right)
{
	NodeSolo* temp = left.head_;
	SinglyOrderedList::NodeSolo::NodeScd* tempscdl = nullptr;
	SinglyOrderedList::NodeSolo::NodeScd* tempscdr = nullptr;
	NodeSolo* scdtemp = right.head_;
	if ((scdtemp != nullptr) and (temp != nullptr))
	{
		while (scdtemp != nullptr)
		{
			if (temp != nullptr)
			{
				if ((temp->FirstEl != scdtemp->FirstEl))
					temp = temp->next_;
				else
				{
					tempscdr = scdtemp->head__;
					tempscdl = temp->head__;
					while (tempscdr != nullptr)
					{
						if (tempscdl->item__ == tempscdr->item__)
						{
							this->insert(tempscdl->item__);
						}
						tempscdl = tempscdl->next__;
						if (tempscdl == nullptr)
						{
							tempscdr = tempscdr->next__;
							tempscdl = scdtemp->head__;
						}

					}
					scdtemp = scdtemp->next_;

				}

			}
			else
			{
				temp = left.head_;
				scdtemp = scdtemp->next_;
			}


		}
	}
}

SinglyOrderedList::NodeSolo::~NodeSolo()
{
	NodeScd* temp = head__;
	NodeScd* tempScd = nullptr;
	while (temp != nullptr)
	{
		tempScd = temp->next__;
		delete temp;
		temp = tempScd;
	}
}

void SinglyOrderedList::NodeSolo::outNodeAll()
{
	NodeScd* current = head__;
	while (current != nullptr)
	{
		std::cout << current->item__ << " ";
		current = current->next__;
	}
}

void SinglyOrderedList::NodeSolo::insertNode(const NodeSolo& Nsolo)
{
	NodeScd* temp = Nsolo.head__;
	while (temp != nullptr)
	{
		this->insertIteminNode(temp->item__);
		temp = temp->next__;
	}
}

void SinglyOrderedList::NodeSolo::insertIteminNode(std::string str)
{
	NodeScd* temp = this->head__;
	if (!searchIteminNode(str))
	{
		if (temp == nullptr)
		{
			this->head__ = new NodeScd(str);
		}
		else
		{
			NodeScd* prev = nullptr;
			while ((temp != nullptr) and (temp->item__ < str))
			{
				prev = temp;
				temp = temp->next__;
			}
			if (prev != nullptr)
				prev->next__ = new NodeScd(str, temp);
			else
			{
				NodeScd* New_elem = new NodeScd(str, temp);
				this->head__ = New_elem;
			}
		}
		count__++;
	}
}

bool SinglyOrderedList::NodeSolo::searchIteminNode(std::string str)
{
	NodeScd* temp = this->head__;
	while (temp != nullptr)
	{
		if (temp->item__ == str)
			return 1;
		temp = temp->next__;
	}
	return 0;
}

bool SinglyOrderedList::NodeSolo::deleteIteminNode(std::string str)
{
	NodeScd* temp = head__;
	NodeScd* prev = nullptr;
	while (temp->item__ != str)
	{
		prev = temp;
		temp = temp->next__;
	}
	if ((prev != nullptr) and (temp != nullptr))
	{
		prev->next__ = temp->next__;
	}
	else
	{
		if (prev == nullptr)
		{
			head__ = temp->next__;
		}
	}
	delete temp;
	count__--;
	return 1;
}
