#include <iostream>

class Node;

class List {
    Node *head; // Head of the list
    Node *tail; // Tail of the list

public:
    explicit List(Node *h = NULL) : head(h), tail(h) {}

    void display();
    void append(Node *p);
};

class Node {
    int val;
    Node *next;

public:
    explicit Node(int i) : val(i), next(NULL) {}

    friend class List; // List is a friend of Node. So, List can access Node's private members
};

void List::display() {
    Node *temp = head;
    while (temp) {
        std::cout << temp->val
                  << " "; // Node val is private within class Node. To access it
                         // inside a member function of class List, we need to make
                         // display() a friend function of class Node
        temp = temp->next;
    }
}

void List::append(Node *p) {
    if (!head)
        head = tail = p;
    else {
        tail->next = p; // Node next is private within class Node. To access it
                       // inside a member function of class List, we need to make
                       // append() a friend function of class Node
        tail = tail->next;
    }
}


int main() {
    List ll;

    Node n1(1);
    Node n2(2);
    Node n3(3);

    ll.append(&n1);
    ll.append(&n2);
    ll.append(&n3);

    return 0;
}