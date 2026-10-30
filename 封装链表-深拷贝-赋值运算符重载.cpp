#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList() {
		//构造函数 先head初始化
		head = new Node;
		head->next = nullptr;
	}

	LinkedList(const LinkedList& other) {
		//深拷贝
		//初始化head
		head = new Node;
		head->next = nullptr;

		Node* p = other.head->next;
		Node* tail = head;
		while (p != nullptr)
		{
			Node* s = new Node;
			s->data = p->data;
			s->next = nullptr;

			tail->next = s;
			tail = s;

			p = p->next;
		}
	}

	LinkedList& operator = (const LinkedList& other) {
		//检查this
		if (this == &other) {
			return *this;
		}

		//删数据
		Node* tur = head;
		while (tur != nullptr) {
			Node* temp = tur->next;
			delete tur;
			tur = temp;
		}

		//深拷贝
		//初始化四条
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

		//返回
		return *this;
	}

	~LinkedList() {
		//删数据
		Node* p = head;

		while (p != nullptr)
		{
			Node* tail = p->next;
			delete p;
			p = tail;
		}
	}

	bool ListC(int i, int x) {
		if (i < 1) {
			return false;
		}

		Node* p = head;
		int j = 0;
		while (p != nullptr && j < i - 1) {
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
		Node* p = head;
		int j = 0;

		if (i < 1) {
			return false;
		}

		while (p != nullptr && j < i - 1) {
			p = p->next;
			j++;
		}

		if (p == nullptr || p->next == nullptr) {
			return false;
		}

		Node* del = p->next;
		p->next = del->next;
		del->next = nullptr;
		delete del;

		return true;
	}

	void print() {
		Node* p = head->next;
		while (p != nullptr) {
			cout << "输出：" << p->data << endl;
			p = p->next;
		}
	}
};

int main() {
	LinkedList list1;

	for (int i = 1; i <= 4; i++) {
		list1.ListC(i, i * 7);
	}
	list1.print();

	list1.ListS(2);

	list1.print();

	LinkedList list2 = list1;

	LinkedList list3;
	list3 = list1;

	list2.print();

	return 0;
}