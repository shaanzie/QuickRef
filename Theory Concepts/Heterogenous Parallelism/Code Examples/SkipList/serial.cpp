#include<bits/stdc++.h>

using namespace std;

class Skiplist {
public:
    struct Node {
        vector<Node *> next;
        int val;
        Node(int x) : val(x) {}
    };
    double load;
    Node *head;
    Node *tail;
    int count;
    int height;
    Skiplist() : count(0), height(-1), load(0.3), head(new Node(-1)), tail(new Node(20001)) {
        srand(time(NULL));
        head->next.push_back(tail);
    }
    void reconstruct() {
        vector<int> nums;
        Node *node = head->next[0];
        while (node != tail) {
            nums.push_back(node->val);
            node = node->next[0];
        }
        height = -1;
        count = 0;
        head = new Node(-1);
        head->next.push_back(tail);
        for (auto n : nums) {
            add(n);
        }
    }
    bool search(int target) {
        Node *node = head;
        while (node != tail) {
            int i = node->next.size() - 1;
            while (i >= 0 && node->next[i]->val > target) {
                i--;
            }
            if (i >= 0) {
                node = node->next[i];
                if (node->val == target)
                    return true;
            } else {
                return false;
            }
        }
        return false;
    }

    void add(int num) {
        Node *node = head;
        stack<Node *> stk;
        count++;
        while (node != tail) {
            int i = node->next.size() - 1;
            while (i >= 0 && node->next[i]->val > num) {
                stk.push(node);
                i--;
            }
            if (i >= 0) {
                node = node->next[i];
            } else {
                Node *newNode = new Node(num);
                i = 0;
                while (!stk.empty()) {
                    node = stk.top();
                    newNode->next.push_back(node->next[i]);
                    node->next[i] = newNode;
                    stk.pop();
                    i++;
                    if (rand() % 2 == 0) {
                        break;
                    }
                }
                if (head->next.back() != tail) {
                    head->next.push_back(tail);
                    height = head->next.size() - 2;
                }
                return;
            }
        }
    }

    bool erase(int num) {
        Node *node = head;
        stack<Node *> stk;
        while (node != tail) {
            int i = node->next.size() - 1;
            while (i >= 0 && node->next[i]->val >= num) {
                if (node->next[i]->val == num) {
                    while (!stk.empty() && stk.top()->next[i + 1] != node->next[i]) {
                        stk.pop();
                    }
                    stk.push(node);
                }
                i--;
            }
            if (i >= 0) {
                node = node->next[i];
            } else {
                if (node->next[0]->val == num) {
                    Node *temp = node->next[0];
                    i = 0;
                    while (!stk.empty()) {
                        node = stk.top();
                        node->next[i] = temp->next[i];
                        stk.pop();
                        i++;
                    }
                    count--;
                    if (count < load * pow(2, height))
                        reconstruct();
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};