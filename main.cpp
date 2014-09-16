#include <iostream>
#include <map>
#include "headers/node.h"

using namespace std;

// Build Acyclic List
Node * buildAcyclicList();

// Build Cyclic List
Node * buildCyclicList();

// Checks if list of Cyclic or Acyclic
bool checkCyclic(Node *);

int main() {

	Node * acyclic_head = buildAcyclicList();
	Node * cyclic_head = buildCyclicList();
	
	if(checkCyclic(acyclic_head))
		cout << "List is acyclic" << endl;
	else
		cout << "List is cyclic" << endl;
}

bool checkCyclic(Node * head) {

	map<Node *, int> listCheck;

	while(head) {

		listCheck[head]++;

		if(listCheck[head] > 1)
			return false;

		head = head->next;

	}

	return true;
}

Node * buildAcyclicList() {

	Node * n0 = new Node;
	Node * n1 = new Node;
	Node * n2 = new Node;
	Node * n3 = new Node;
	Node * n4 = new Node;

	n0->data = 3;
	n1->data = 2;
	n2->data = 4;
	n3->data = 6;
	n4->data = 2;

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	return n0;

}

Node * buildCyclicList() {

	Node * n0 = new Node;
	Node * n1 = new Node;
	Node * n2 = new Node;
	Node * n3 = new Node;
	Node * n4 = new Node;

	n0->data = 3;
	n1->data = 2;
	n2->data = 4;
	n3->data = 6;
	n4->data = 2;

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	return n0;

}