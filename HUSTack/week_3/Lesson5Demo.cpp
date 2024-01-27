#include<bits/stdc++.h>
using namespace std ;

map<int, vector<int > > mp ;
bool check[10000];

int root ;
inline void makeRoot(int u) {
    mp[u];
    root = u ;
    check[root] = true ;
}

inline void insertNode(int u, int v ) {
    if(!check[v]) return ;
    if(check[u]) return ;
    if(!check[u]) {
        mp[v].push_back(u);
        check[u] = true ;
    }
}

inline void PreOrder(int root) {
    cout << root<< " ";
    for(unsigned i = 0 ; i < mp[root].size(); i ++ ) {
        PreOrder(mp[root].at(i));
    }
}

inline void InOder(int root) {
    if(mp[root].size() != 0) {
        InOder(mp[root].at(0));
    }
    cout<< root << " ";
        for(unsigned int i = 1; i < mp[root].size(); i ++) {
            InOder(mp[root].at(i));
        }
}

inline void PostOder(int root) {
    for(unsigned int i = 0 ; i < mp[root].size(); i ++) {
        PostOder(mp[root].at(i));
    }
    cout << root << " ";
}

int main() {
    string request ;
    int val1, val2;
    cin >> request ;
      while(request != "*") {
        if(request == "MakeRoot") {
            cin >> root;
            makeRoot(root);
            cin >> request; 
            continue;
        }
        if(request == "Insert") {
            cin >> val1 >> val2 ;
            insertNode(val1, val2);
            cin >> request ;
            continue;
        }
        if(request == "InOrder") {
            InOder(root);
            cout<<endl;
            cin >> request ;
            continue;
        }
        if(request == "PreOrder") {
            PreOrder(root);
            cin >> request ;
            cout<<endl;
            continue;
        }
        if(request == "PostOrder") {
            PostOder(root);
            cin >> request;
            cout<<endl;
            continue;
        }
    }
}
