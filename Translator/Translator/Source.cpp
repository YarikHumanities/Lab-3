
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Pair {
public:
	string Key;
	string Value;
	void set_Key_Value(string a, string b) {
		Key = a;
		Value = b;
	}
};
//Linked list
class Node {
public:
	Pair data;
	Node* next;
	Node(Pair x) {
		data = x;
		next = NULL;
	}
};
class LinkedList {

public:
	Node* head;
	bool isEmpty() {
		if (head == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void addAtEnd(Pair pair) {
		Node* n = new Node(pair);
		if (head == NULL) {
			head = n;
			n->next = NULL;
		}
		else {
			Node* n2 = getLastNode();
			n2->next = n;
		}
	}
	Node* getLastNode() {
		Node* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		return ptr;
	}


	LinkedList() {
		head = NULL;
	}
};
class HashTable {

};


int main() {
	LinkedList list;
	Pair a;
	a.set_Key_Value("one", "word1");
	Pair b;
	a.set_Key_Value("two", "word2");
	Pair c;
	a.set_Key_Value("three", "word3");
	list.addAtEnd(a);
	list.addAtEnd(b);
	list.addAtEnd(c);
	
	
}