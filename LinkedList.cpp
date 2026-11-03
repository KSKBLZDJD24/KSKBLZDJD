#include "LinkedList.h"

using namespace std;

Node::Node() : data(0), next(nullptr){}

Node::Node(int data) {
	this->data = data;
	this->next = nullptr;
}

LinkedList::LinkedList() : head(new Node(0)){}

LinkedList::LinkedList(const LinkedList& other) {
	head = new Node(0);
	Node* p = other.head->next;
	Node* tail = head;
	while (p!=nullptr){
		Node* s = new Node(p->data);
		tail->next = s;
		tail = s;
		p = p->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
	if (this == &other) {
		return *this;
	}

	Node* tur = head;
	while (tur!=nullptr)
	{
		Node* temp = tur->next;
		delete tur;
		tur = temp;
	}

	head = new Node(0);
	Node* p = other.head->next;
	Node* tail = head;
	while (p!=nullptr)
	{
		Node* s = new Node(p->data);
		tail->next = s;
		tail = s;
		p = p->next;
	}
	return *this;
}

LinkedList::~LinkedList() {
	Node* p = head;
	while (p!=nullptr)
	{
		Node* tail = p->next;
		delete p;
		p = tail;
	}
}

bool LinkedList::ListC(int i,int x) {
	if (i < 1)return false;

	Node* p = head;
	int j = 0;
	while (p != nullptr && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr)return false;

	Node* s = new Node(x);
	s->next = p->next;
	p->next = s;

	return true;
}

bool LinkedList::ListS(int i) {
	Node* p = head;
	int j = 0;
	if (i < 1)return false;

	while (p != nullptr && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (p == nullptr || p->next == nullptr)return false;

	Node* del = p->next;
	p->next = del->next;
	delete del;

	return true;
}

void LinkedList::print() const {
	Node* p = head->next;
	while (p!=nullptr)
	{
		cout << "Êä³ö£º" << p->data << endl;
		p = p->next;
	}
}