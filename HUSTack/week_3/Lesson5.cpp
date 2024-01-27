#include <bits/stdc++.h>
using namespace std;
string ans = "";

struct node {
    int data;
    node* leftMostChild;
    node* rightSibling;
};

node* newNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->leftMostChild = NULL;
    temp->rightSibling = NULL;
    return temp;
}

node* find(node* r, int v) {
    if(r == NULL) return NULL;
    if(r->data == v) return r;
    node* p = r->leftMostChild;
    while(p != NULL) {
        node* hv = find(p, v);
        if(hv != NULL) return hv;
        p = p->rightSibling;
    }
    return NULL;
}

node* insert(node* r, int u, int v) {
    node* tempU = find(r, u);
    node* tempV = find(r, v);
    if(tempV != NULL && tempU == NULL) {
        tempU = newNode(u);
        if(tempV->leftMostChild == NULL) tempV->leftMostChild = tempU;
        else {
            node* p = tempV->leftMostChild;
            while(p != NULL) {
                if(p->rightSibling == NULL) {
                    p->rightSibling = tempU;
                    break;
                }
                p = p->rightSibling;
            }
        }
    }
    return r;
}

void preOrder(node* r) {
    if(r == NULL) return;
    // cout << r->data << " ";
    ans = ans + to_string(r->data) + " ";
    node* p = r->leftMostChild;
    while(p != NULL) {
        preOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(node* r) {
    if(r == NULL) return;
    node* p = r->leftMostChild;
    while(p != NULL) {
        postOrder(p);
        p = p->rightSibling;
    }
    // cout << r->data << " ";
    ans = ans + to_string(r->data) + " ";
}

void inOrder(node* r) {
    if(r == NULL) return;
    node* p = r->leftMostChild;
    inOrder(p);
    // cout << r->data << " ";
    ans = ans + to_string(r->data) + " ";
    if(p != NULL) p = p->rightSibling;
    while(p != NULL) {
        inOrder(p);
        p = p->rightSibling;
    }
}

int main() {
    queue<string> temp;
    int u, v;
    string str;
    node* r = NULL;
    while(true) {
        cin >> str;
        if(str == "*") break;
        else if(str == "MakeRoot") {
            cin >> u;
            r = newNode(u);
        } else if(str == "Insert") {
            cin >> u >> v;
            r = insert(r, u, v);
        } else if(str == "InOrder") {
            ans = "";
            inOrder(r);
            temp.push(ans);
        } else if(str == "PostOrder") {
            ans = "";
            postOrder(r);
            temp.push(ans);
        } else if(str == "PreOrder") {
            ans = "";
            preOrder(r);
            temp.push(ans);
        }
    }
    
    while(!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
}