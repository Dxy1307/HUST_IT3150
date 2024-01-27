#include <bits/stdc++.h>
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
long n, m;

void Dijisktra(long s, long t) {
    vector<bool> check(n + 1, false);
    D[s] = 0;

    priority_queue<node, vector<node>, comp> h;
    h.push({s, D[s]});

    while(!h.empty()) {
        node x = h.top();
        h.pop();
        if(check[x.v]) continue;
        check[x.v] = true;
        long u = x.v;
        long w = x.best_weight;
        for(e temp : E[u]) {
            long y = temp.v;
            if(D[y] > w + temp.weight) {
                D[y] = w + temp.weight;
                h.push({y, D[y]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    D.resize(n + 1, INF);
    E.resize(n + 1);
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        E[u].push_back({v, w});
    }
    long s, t;
    cin >> s >> t;
    Dijisktra(s, t);
    if(D[t] == INF) D[t] = -1;
    cout << D[t] << endl;
}