#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = new Node;
		head->next = nullptr;
	}

	//Éî¿½±´
	LinkedList(const LinkedList& other) {
		head = new Node;
		head->next = nullptr;

		Node* p = other.head->next;
		Node* tail = head;

		while (p != nullptr) {
			Node* s = new Node;
			s->data = p->data;
			s->next = nullptr;

			tail->next = s;
			tail = s;

			p = p->next;
		}
	}


	LinkedList& operator = (const LinkedList& other) {
		if (this == &other) {
			return *this;
		}

	
		Node* tur = head;
		while (tur != 0) {
			Node* temp = tur->next;
			delete tur;
			tur = temp;
		}

		head = new Node;
		head->next = nullptr;

		Node* p = other.head->next;
		Node* tail = head;
		while (p != nullptr) {
			Node* s = new Node;
			s->data = p->data;
			s->next = nullptr;

			tail->next = s;
			tail = s;
			p = p->next;
		}

		return *this;
	}
	
	~LinkedList() {
		Node* cur = head;
		while (cur != 0) {
			Node* temp = cur->next;
			delete cur;
			cur = temp;
		}
	}

	bool ListC(int i, int x) {
		Node* p = head;
		int j = 0;
		
		if (i < 1) {
			return false;
		}

		while (p != 0 && j < i - 1) {
			p = p->next;
			j++;
		}

		if (p == nullptr) {
			return false;
		}

		Node* s = new Node;
		s->next = p->next;
		p->next = s;
		s->data = x;

		return true;
	}
	
	bool ListS(int i) {
		int j = 0;
		Node* p = head;
		if (i < 1) {
			return false;
		}

		while (p != 0 && j < i - 1) {
			p = p->next;
			j++;
		}

		if (p == nullptr) {
			return false;
		}

		Node* del = p->next;
		p->next = del->next;
		delete del;

		return true;
	}

	void print() {
		Node* shuchu = head->next;
		while (shuchu != nullptr) {
			cout << "Êä³ö:  " << shuchu->data << endl;
			shuchu = shuchu->next;
		}
	}
};

int main() {
	LinkedList list;

	for (int i = 1; i <= 4; i++) {
		list.ListC(i, i * 5);
	}

	list.print();

	list.ListS(2);

	list.print();

	LinkedList list2 = list;
	list2.print();

	LinkedList list3;
	list3 = list;
	list3.print();

	return 0;
}