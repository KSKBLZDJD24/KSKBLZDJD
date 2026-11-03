#pragma once
#include<iostream>

struct Node
{
	int data;
	Node* next;

	Node();
	Node(int data);
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList& operator = (const LinkedList& other);
	~LinkedList();

	bool ListC(int i, int x);
	bool ListS(int i);
	void print() const;

};

