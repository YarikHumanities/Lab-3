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
//Hash table
class HashTable {
private:
    Node** table;
public:
    int tableSize = 10;
    float threshold = 0.8;
    int size = 0;
    int maxSize = 0;
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
    float setThreshold(float threshold) {
        this->threshold = threshold;
        maxSize = (int)(tableSize * threshold);
    }
    void resize() {
        int OldTableSize = tableSize;
        tableSize *= 2;
        maxSize = (int)(tableSize * threshold);
        Node** OldTable = table;
        table = new Node * [tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
        size = 0;
        for (int hash = 0; hash < OldTableSize; hash++)
        {
            if (OldTable[hash] != NULL) {
                Node* oldEntry;
                Node* entry = OldTable[hash];
                while (entry != NULL) {
                    insert(entry->data.Key, entry->data.Value);
                    oldEntry = entry;
                    entry = entry->next;
                    delete oldEntry;
                }
            }
        }
        delete[] OldTable;
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
                size++;
            }
            else {
                prev->next = entry;
            }
        }
        else {
            entry->data.Value;
            size++;
        }
        if (size >= maxSize) {
            resize();
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
                cout << key << ": " << entry->data.Value << endl;
                flag = true;
            }
            entry = entry->next;
        }
        if (!flag)
        {
            cout << key << ":" << "There isn't such a word in the dictionary" << endl;
        }
    }
};
int main()
{
    /*int n = 2;
    HashTable dictionary;
    string key;
    string value;
    dictionary.insert("ac", "Hello");
    dictionary.insert("ac", "Bye");
    dictionary.insert("ca", "Wrong");
    /*for (int i = 0; i < n; i++)
    {
        cout << "Enter key: ";
        getline(cin, key);
        cout << "Enter word: ";
        getline(cin, value);
        dictionary.insert(key, value);
    }*/
    
   
    //dictionary.Search("ac");
    ifstream inFile;
    string path = "C:/Users/User/coding/Labs 1.2/Lab-3/Translator/dict_temp.txt";
    string str;
    HashTable dictionary;
    string key;
    string value;
    string defn = "Defn:";
    inFile.open(path);
    if (!inFile.is_open()) {
        std::cout << "Cannot open the dictionary" << std::endl;
    }
    else
    {
        std::cout << "Dictionary opened" << std::endl;
        while (!inFile.eof()) {
            str = "";
            key = "";
            value = "";
            getline(inFile, str);
            if (str.size() > 0) {
                string key_temp = string(str, 0, str.find(';'));
                key = key_temp;
                string value_temp = str.substr(str.find("Defn:") + 5);
                value = value_temp;
                dictionary.insert(key, value);
                key_temp = "";
                value_temp = "";
            }
        }
    }
    while (true) {
        string str1;
        cout << "Enter a word: ";
        getline(cin, str1);
        if (str1 == "I want to exit") {
            break;
        }
     
        int start = 0, end = 0;
        while (end < str1.size())
        {
            start = end;
            while (start < str1.size() && str1[start] == ' ')
            {
                ++start;
            }
            end = start;
            while (end < str1.size() && str1[end] != ' ')
            {
                ++end;
            }
            string word = string(str1, start, end - start);
            string right_word;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'A' and word[i] <= 'Z') {
                    right_word += word[i];
                }
                else {
                    right_word += (word[i] - 32);
                }
            }
            dictionary.Search(right_word);
        }
    }
    
}