#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char symbol;
    int freq;
    int index;            
    Node *left, *right;
    Node(char s, int f, int idx)
        : symbol(s), freq(f), index(idx), left(nullptr), right(nullptr) {}
    Node(int f, int idx, Node *l, Node *r)
        : symbol('\0'), freq(f), index(idx), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq != b->freq)
            return a->freq > b->freq;
        return a->index > b->index;
    }
};

void printCodes(Node* root, string code = "") {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->symbol << " -> " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd'};
    vector<int> freq = {45, 90, 35, 20};
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < chars.size(); ++i)
        pq.push(new Node(chars[i], freq[i], i));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int minIndex = min(left->index, right->index);
        pq.push(new Node(left->freq + right->freq, minIndex, left, right));
    }
    printCodes(pq.top());
    return 0;
}
