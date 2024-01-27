#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    map<int, int> seen;
    stack<int> ans;

    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        if(seen.find(A[i]) != seen.end()) {
            seen[A[i]]++;
        } else {
            seen[A[i]] = 0;
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(seen[A[i]] > 0) {
            ans.push(1);
            seen[A[i]]--;
        } else {
            ans.push(0);
        }
    }   

    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    
    return 0;
}