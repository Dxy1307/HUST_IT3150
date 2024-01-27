// Max Flow
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;

vector<bool> visited;
vector<int> trace;
int c[MAX][MAX] = {};

int n, m;
int s, t;
bool checkPath = false;
int maxFlow = 0;

void input() {
    cin >> n >> m;
    cin >> s >> t;
    visited.resize(n + 1, false);
    trace.resize(n + 1, 0);
    int fir, sec, wei;
    for(int i = 1; i <= m; ++i) {
        cin >> fir >> sec >> wei;
        c[fir][sec] = wei;
    }
}

void bfs(int u, int t, vector<bool> &visited, vector<int> &trace) {
    for(int i = 1; i <= n; ++i) visited[i] = false;
    visited[u] = true;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        if(curr == t) {
            checkPath = true;
            return;
        }
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                if(c[curr][i]) {
                    visited[i] = true;
                    trace[i] = curr;
                    Q.push(i);
                }
            }
        }
    }
}

void increase_flow(int head, int tail, vector<bool> &visited, vector<int> &trace) {
    while(true) {
        checkPath = false;
        bfs(head, tail, visited, trace);
        if(!checkPath) break;

        int minCapacity = INT_MAX;
        int v = tail;
        int u;
        while(v != head) {
            u = trace[v];
            minCapacity = min(minCapacity, c[u][v]);
            v = u;
        }

        v = tail;
        while(v != head) {
            u = trace[v];
            c[u][v] -= minCapacity;
            c[v][u] += minCapacity;
            v = u;
        }

        maxFlow += minCapacity;
    }
}

int main() {
    ios_base::sync_with_stdio(0);;
    cin.tie(NULL);cout.tie(NULL);
    input();
    increase_flow(s, t, visited, trace);
    cout << maxFlow << endl;
}