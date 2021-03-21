
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
private:
	Node** table;
public:
	int tableSize = 127;
	HashTable() {
		table = new Node * [tableSize];
		for (int i = 0; i < tableSize; i++)
		{
			table[i] = NULL;
		}
	}
	int HashFunc(string key) {
		int sum = 0;
		for (int i = 0; i < key.size(); i++)
		{
			sum += key[i];
		}
		return sum % key.size();
	}
	void insert(string key, string value) {
		Pair aa;
		aa.set_Key_Value(key, value);
		int hash_val = HashFunc(key);
		Node* prev = NULL;
		Node* entry = table[hash_val];
		while (entry != NULL) {
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL) {
			entry = new Node(aa);
			if (prev == NULL) {
				table[hash_val] = entry;
			}
			else {
				prev->next = entry;
			}

		}
		else {
			entry->data.Value;
		}
	}
	void Search(string key)
	{
		bool flag = false;
		int hash_val = HashFunc(key);
		Node* entry = table[hash_val];
		while (entry != NULL)
		{
			if (entry->data.Key == key)
			{
				cout << entry->data.Value << " ";
				flag = true;
			}
			entry = entry->next;
		}
		if (!flag)
		{
			cout << "Not"<<endl;
		}
	}
};


int main() 
{

}