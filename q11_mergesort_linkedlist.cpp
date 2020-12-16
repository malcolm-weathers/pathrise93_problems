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

int depth(node* curr) {
    if (curr->next == nullptr) {
        return 1;
    } else {
        return 1 + depth(curr->next);
    }
}

node* middle(node* first) {
    int d = depth(first)/2;
    node* mid = first;
    for (int i = 0; i < d; i++) {
        mid = mid->next;
    }
    return mid;
}

void printn(node* n) {
    std::cout << n->num << "->";
    if (n->next != nullptr) {
        printn(n->next);
    } else {
        std::cout << "\n";
    }
}

node* mergesortll(node* n) {
    if (depth(n) == 1) {
        return n;
    } else if (depth(n) == 2) {
        if (n->num < n->next->num) {
            return n;
        }
        node* tmp = n->next;
        tmp->next = n;
        n->next = nullptr;
        return tmp;
    }

    node* m = middle(n);
    node* p = m->next;
    m->next = nullptr;

    node* o1 = mergesortll(n);
    node* o2 = mergesortll(p);

    node* newc = new node;
    node* curr = newc;
    while (o1 != nullptr || o2 != nullptr) {
        if (o1 == nullptr) {
            curr->next = o2;
            curr = curr->next;
            o2 = o2->next;
        } else if (o2 == nullptr) {
            curr->next = o1;
            curr = curr->next;
            o1 = o1->next;
        } else {
            if (o1->num < o2->num) {
                curr->next = o1;
                curr = curr->next;
                o1 = o1->next;
            } else {
                curr->next = o2;
                curr = curr->next;
                o2 = o2->next;
            }
        }
    }
    node* t = newc->next;
    delete newc;
    return t;
}

int main() {
    linkedlist* mylist = new linkedlist;
    mylist->add(55);
    mylist->add(6);
    mylist->add(4);
    mylist->add(73);
    mylist->add(30);
    mylist->add(474);
    mylist->add(73);
    mylist->add(30);

    printn(mylist->first);
    mylist->first = mergesortll(mylist->first);
    printn(mylist->first);
    return 0;
}
