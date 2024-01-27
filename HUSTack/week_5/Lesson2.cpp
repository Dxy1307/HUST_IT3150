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
    // DFS của đồ thị có hướng
    // bỏ 2 dòng cmt thì thành DFS của đồ thị vô hướng
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        A[u][szA[u]] = v;
        A[v][szA[v]] = u;
        szA[u]++;
        szA[v]++;
    }
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    int k = szA[u];
    // if(k > 0) {
        for(int i = 0; i < k; ++i) {
            if(visited[A[u][i]] == false) {
                dfs(A[u][i]);
            }
        }
    // }
}


int main() {
    input();
    for(int i = 1; i <= n; ++i) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
    return 0;
}