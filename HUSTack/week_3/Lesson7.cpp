#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* right;
    node* left;
};

node* newNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

node* insert(node* r, int x) {
    if(r == NULL) r = newNode(x);
    else {
        if(r->data > x) r->left = insert(r->left, x);
        else if(r->data < x) r->right = insert(r->right, x);
    }
    return r;
}

void preOrder(node* r) {
    if(r != NULL) {
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

int main() {
    int x;
    string str;
    node* r = NULL;
    while(true) {
        cin >> str;
        if(str == "#") break;
        else if(str == "insert") {
            cin >> x;
            r = insert(r, x);
        }
    }
    preOrder(r);
}