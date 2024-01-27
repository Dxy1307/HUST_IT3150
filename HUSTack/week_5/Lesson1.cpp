// Kruskal
#include<bits/stdc++.h>
using namespace std;

const int MaxN = 50000;

class Edge {
    public:
        int u, v, w;

        Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}

        bool operator < (const Edge &op) {
            return w < op.w;
        }
};

int n, m, parent[MaxN];
vector<Edge> edges;

void make_set(int u){
    parent[u] = u;// mặc định nhãn của u là u
}

// tìm nhãn của u
int find_set(int u){
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    for(int i = 1 ; i <= n ; ++i) make_set(i);
    sort(edges.begin(), edges.end());// sắp xếp các trọng số theo thứ tự tăng dần
    long long ans = 0;
    for(int i = 0 ; i < m ; ++i){
        Edge e = edges[i];
        int u = find_set(e.u);// tìm nhãn điềm đầu
        int v = find_set(e.v);// tìm nhãn điểm cuối
        // kiểm tra xem nếu khác nhãn tức là cạnh mới thêm
        // vào cây khung không tạo chu trình
        if(u != v){
            ans += e.w;
            parent[u] = v;// gán nhãn mới
        }
    }
    cout << ans << endl;

    return 0;
}