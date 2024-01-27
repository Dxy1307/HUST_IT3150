#include <bits/stdc++.h>
using namespace std;

string thay_the_xau(string T, string P1, string P2) {
    size_t pos = T.find(P1);
    while(pos != string::npos) {
        T.replace(pos, P1.length(), P2);
        pos = T.find(P1, pos + P2.length());
    }
    return T;
}

int main() {
    string T, P1, P2;
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    string ans = thay_the_xau(T, P1, P2);
    cout << ans;

    return 0;
}