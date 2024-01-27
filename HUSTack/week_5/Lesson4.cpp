#include <bits/stdc++.h>
using namespace std;
#define M 1000

int n, m;
bool flag = false;

int A[M][M];// lưu các điểm con của điểm i
int szA[M];// lưu số điểm con của điểm i
bool visited[M]; // kiểm tra điểm i đã thăm hay chưa
int ans[M];

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
}

void printList() {
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << 1 << endl;
}

void dfs(int v, int u, int count) {
    visited[u] = true;
    // count++;
    ans[v] = u;
    int k = szA[u];
    if(count == n) {
        for(int i = 0; i < k; i++) {
            if(A[u][i] == 1) {
                // flag = true;
                // break;
                printList();
            }
        }
        // return;
    } else {
        for(int i = 0; i < k; ++i) {
            if(visited[A[u][i]] == false) {
                dfs(v+1, A[u][i], count + 1);
            }
        }
    }
    // count--;
    visited[u] = false;
}

int main() {
    int a;
    cin >> a;
    // queue<int> ans;
    for(int i = 1; i <= a; ++i) {
        input();
        int count = 0;
        dfs(1, 1, 1);
        // if(flag) ans.push(1);
        // else ans.push(0);
    }
    // while(!ans.empty()) {
    //     cout << ans.front() << endl;
    //     ans.pop();
    // }
    return 0;
}