#include <bits/stdc++.h>
using namespace std;

inline int convertTime(string date) {
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);
    int result = stoi(year + month + day);
    return result;
}

int main() {
    string str = "MAX_UNRELATED_PEOPLE";
    // cout << convertTime(str);
    cout << str.length();
}