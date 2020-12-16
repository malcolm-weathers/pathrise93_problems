#include <iostream>

struct node {
    int num;
    node* next;
};

class linkedlist {
    public:
    node* first;
    node* last;

    void add(int num) {
        node* n = new node;
        n->num = num;

        if (first == nullptr) {
            first = n;
            last = n;
        } else {
            last->next = n;
            last = n;
        }
    }

    void print() {
        if (first == nullptr) {
            std::cout << "Empty\n";
            return;
        }
        node* current = first;
        do {
            std::cout << current->num << "->";
            current = current->next;
        } while (current != nullptr);
        std::cout << "\n";
    }

    void rvrse(node* curr=nullptr, node* prev=nullptr) {
        if (curr == nullptr) {
            curr = first;
            last = curr;
        }
        node* tmp = curr->next;
        curr->next = prev;
        if (tmp != nullptr) {
            rvrse(tmp, curr);
        } else {
            first = curr;
        }
    }
};

int main() {
    linkedlist* mylist = new linkedlist;
    mylist->add(5);
    mylist->add(55);
    mylist->add(4);
    mylist->add(7);
    mylist->print();
    mylist->rvrse();
    mylist->print();
    return 0;
}
