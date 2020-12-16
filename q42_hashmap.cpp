#include <iostream>

struct h_node {
    std::string word;
    h_node* next;
};

class hashmap {
    public:
    h_node* words[117];

    int shash(std::string s) {
        int n = 7;
        for (int i = 0; i < s.size(); i++)
            n += 7+(s[i]*5);
        return n % 117;
    }

    bool sfind(std::string s) {
        int h = shash(s);
        if (words[h] == nullptr)
            return false;
        else {
            h_node* curr = words[h];
            do {
                if (curr->word == s)
                    return true;
                curr = curr->next;
            } while (curr != nullptr);
        }
        return false;
    }

    void sadd(std::string s) {
        if (sfind(s))
            return;

        int h = shash(s);
        h_node* newnode = new h_node;
        newnode->word = s;
        newnode->next = nullptr;

        if (words[h] == nullptr) {
            words[h] = newnode;
            return;
        }
        h_node* curr = words[h];
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newnode;
    }
};

int main() {
    hashmap* h = new hashmap;
    h->sadd("hello"); h->sadd("testword");
    std::cout << "testword=" << h->sfind("testword") << " bad=" << h->sfind("bad");
    return 0;
}
