// All pair shortest paths
#include<bits/stdc++.h>
using namespace std;

const long MAX = 1e9 + 1;
const long INF = LONG_MAX;
typedef struct Edge {
    long v;
    long weight;
} e;

typedef struct Node {
    long v;
    long best_weight;
} node;

struct comp {
    bool operator() (node a, node b) {
        return a.best_weight > b.best_weight;
    }
};
vector<long> D;
vector<vector<e>> E;
long n , m;


void Dijisktra(long s) {
    vector<bool> check(n+1, false);
    D[s] = 0;

    priority_queue<node, vector<node>, comp > h ;
    h.push({s,D[s]});

    while(!h.empty()) {
        node x = h.top();
        h.pop();
        if(check[x.v]) {
            continue;
        }
        check[x.v] = true ;
        long u = x.v;
        long w = x.best_weight;
        for(e tmp: E[u]) {
            int y =tmp.v;
            if(D[y]  > w + tmp.weight) {
                D[y] = w + tmp.weight;
                h.push({y, D[y]});
                
            }
        }
    
    }
}

int main(){
    ios_base::sync_with_stdio(0);;
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    D.resize(n + 1, INF);
    E.resize(n+1);
    int fir, sec, wei;
    for(int i = 0 ; i < m ; i ++) {
        cin >> fir >> sec >> wei;
        E[fir].push_back(e{sec, wei});
    }
    for(int i  = 1; i <= n ; i++) {
        Dijisktra(i);
        for(int j = 1; j <= n ; j++) {
            cout << D[j] << " ";
            D[j] = INF;
        }
        cout << "\n";
    }
}
