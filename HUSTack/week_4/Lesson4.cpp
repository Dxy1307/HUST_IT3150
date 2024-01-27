#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int M) {
    int count = 0;
    map<int, int> map;
    for(int i = 0; i < n; i++) {
        count += map[M-arr[i]];
        map[arr[i]]++;
    }
    return count;
}

int main() {
    int n, M;
    cin >> n >> M;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << getPairsCount(arr, n, M) << endl;
    return 0;
}