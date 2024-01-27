#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* newNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

node* check(node* head, int x) {
    node* p = head;
    while(p != NULL) {
        if(p->data == x) return p;
        p = p->next;
    }
    return p;
}

node* addElement(node* p, int x) {
    node* temp = newNode(x);
    p->next = temp;
    return temp;
}

node* addHead(node* head, int x) {
    if(check(head, x) == NULL) {
        node* temp = new node;
        temp->data = x;
        temp->next = head;
        head = temp;
    }
    return head;
}

node* addTail(node* head, int x) {
    if(check(head, x) == NULL) {
        node* p = head;
        while(p -> next != NULL) {
            p = p->next;
        }
        node* temp = new node;
        temp->data = x;
        temp->next = NULL;
        p->next = temp;
    }
    return head;
}

node* addAfter(node* head, int u, int v) {
    node* tempU = check(head, u);
    node* tempV = check(head, v);
    if(tempV != NULL && tempU == NULL) {
        tempU = newNode(u);
        tempU->next = tempV->next;
        tempV->next = tempU;
    }
    return head;
}

node* addBefore(node* head, int u, int v) {
    node* p = head;
    node* tempU = check(head, u);
    node* tempV = check(head, v);
    if(tempV != NULL && tempU == NULL) {
        if(p->data == v) addHead(head, u);
        else {
            tempU = newNode(u);
            while(p->next != NULL) {
                if(p->next->data == v) {
                    tempU->next = tempV;
                    p->next = tempU;
                    break;
                }
                p = p->next;
            }
        }
    }
    return head;
}

node* deleteTail(node* head) {
    node* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    node* h = head;
    while(h->next != p) {
        h = h->next;
    }
    h->next = NULL;
    delete(p);
    return head;
}

node* remove(node* head, int k) {
    node* p = head;
    if(p->data == k) {
        p = p->next;
        delete(head);
        return p;
    } else {
        while(p ->next != NULL) {
            if(p->next->data == k && p->next->next == NULL) {
                head = deleteTail(head);
                break;
            }
            else if(p->next->data == k) {
                node* temp = p->next;
                p->next = p->next->next;
                delete(temp);
                break;
            }
            p = p->next;
        }
        return head;
    }
}

node* reverse(node* head) {
    if(head == NULL) return head;
    node *temp = head, *dsmoi = NULL, *newnode;

    while(temp != NULL) {
        newnode = newNode(temp->data);
        newnode->next = dsmoi;
        dsmoi = newnode;
        temp = temp->next;
    }

    return dsmoi;
}

void printList(node* head) {
    node* p = head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    node* head = newNode(x);
    node* p = head;
    for(int i = 1; i < n; i++) {
        cin >> x;
        p = addElement(p, x);
    }
    string str;
    int k, u, v;
    while(true) {
        cin >> str;
        if(str == "#") break;
        else if(str == "addlast") {
            cin >> k;
            head = addTail(head, k);
        } else if(str == "addfirst") {
            cin >> k;
            head = addHead(head, k);
        } else if(str == "addafter") {
            cin >> u >> v;
            head = addAfter(head, u, v);
        } else if(str == "addbefore") {
            cin >> u >> v;
            head = addBefore(head, u, v);
        } else if(str == "remove") {
            cin >> k;
            head = remove(head, k);
        } else if(str == "reverse") {
            head = reverse(head);
        }
    }

    printList(head);
    return 0;
}