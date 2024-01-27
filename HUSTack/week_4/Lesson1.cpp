#include <bits/stdc++.h>
using namespace std;

int m;

int hashC(const string &str) {
    unsigned long long count = 0;
    unsigned long long multi = 1;
    int k = str.length() - 1;
    for(int i = k; i>= 0; --i) {
        count = (count + (str[i] * multi) % m) % m;
        multi = (multi*256) % m;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        cout << hashC(str) << "\n";
    }
}