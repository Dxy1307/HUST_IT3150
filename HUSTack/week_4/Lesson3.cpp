#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node* left;
    node* right;
};

node* newNode(string str) {
    node* temp = new node;
    temp->data = str;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node* insert(node* r, string str) {
    if(r == NULL) r = newNode(str);
    else {
        if(str < r->data) r->left = insert(r->left, str);
        else if(str > r->data) r->right = insert(r->right, str);
    }
    return r;
}

bool search(node*r, string str) {
    if(r == NULL) return false;
    if(r->data == str) return true;
    if(str < r->data) return search(r->left, str);
    else return search(r->right, str);
}

int main() {
    queue<int> ans;
    string str;
    node* r = NULL;
    while(true) {
        cin >> str;
        if(str == "*") break;
        else r = insert(r, str);
    }

    string cmd, k;
    while(true) {
        cin >> cmd;
        if(cmd == "***") break;
        else {
            cin >> k;
            if(cmd == "find") {
                if(search(r, k)) ans.push(1);
                else ans.push(0);
            } else if(cmd == "insert") {
                if(search(r, k)) ans.push(0);
                else {
                    r = insert(r, k);
                    ans.push(1);
                }
            }
        }
    }

    while(!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
}