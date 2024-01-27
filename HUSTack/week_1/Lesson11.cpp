#include <bits/stdc++.h>
#include <string>
using namespace std;

#define MAX 100000
int arr[MAX];

int find_max(int arr[], int l, int r) {
    int max = -1001;
    for(int i = l; i <= r; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(int arr[], int l, int r) {
    int min = 1001;
    for(int i = l; i <= r; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int sumArr(int arr[], int l, int r) {
    int sum = 0;
    for(int i = l; i <= r; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string str;
    cin >> str;
    int max = find_max(arr, 0, n-1);
    int min = find_min(arr, 0, n-1);
    int sum = sumArr(arr, 0, n-1);

    queue<int> ans;
    while(true) {
        getline(cin, str);
        if(str == "***") break;
        else if(str == "find-max") ans.push(max);
        else if(str == "find-min") ans.push(min);
        else if(str == "sum") ans.push(sum);
        else if(str.length() >= 20){
            int temp = str.rfind(" ");
            int tempHead = str.find(" ");
            int i = stoi(str.substr(tempHead+1, temp-1));
            int j = stoi(str.substr(temp+1));
            ans.push(find_max(arr, i-1, j-1));
        }
    }
    while(!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
}