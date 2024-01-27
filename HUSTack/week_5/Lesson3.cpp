#include <bits/stdc++.h>
using namespace std;
#define M 1000

int n, m;

int A[M][M];// lưu các điểm con của điểm i
int szA[M];// lưu số điểm con của điểm i
bool visited[M]; // kiểm tra điểm i đã thăm hay chưa

void input() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; ++i) {
        szA[i] = 0;
        visited[i] = false;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        A[u][szA[u]] = v;
        A[v][szA[v]] = u;
        szA[u]++;
        szA[v]++;
    }
    for(int i = 1; i <= n; ++i) {
        sort(A[i], A[i] + szA[i]);
    }
}

void BFS(int u) {
    visited[u] = true;
    cout << u << " ";
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for(int i = 0; i < szA[curr]; ++i) {
            if(!visited[A[curr][i]]) {
                visited[A[curr][i]] = true;
                cout << A[curr][i] << " ";
                Q.push(A[curr][i]);
            }
        }
    }
}

int main() {
    input();
    for(int i = 1; i <= n; ++i) visited[i] = false;
    for(int i = 1; i <= n; ++i) 
        if(!visited[i]) BFS(i);
}