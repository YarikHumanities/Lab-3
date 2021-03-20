#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Pair {
	public:
		string Key;
		string Value;

};
//Linked list
class Node {
	public:
		string data;
		Node* next;
		Node(string x) {
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
		void addAtEnd(string word) {
			Node* n = new Node(word);
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
		void display() {
			Node* pointer = head;
			while (pointer != NULL) {
				cout << pointer->data << "->";
				pointer=pointer->next;
			}
		}


		LinkedList() {
			head = NULL;
		}
};



int main() {
	LinkedList list;
	list.addAtEnd("aa");
	list.addAtEnd("bb");
	list.addAtEnd("cc");
	list.display();
}