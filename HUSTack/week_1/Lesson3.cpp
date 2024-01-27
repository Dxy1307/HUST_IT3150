#include<bits/stdc++.h>
using namespace std;
string s;
inline void upperCase() {
    for(int i = 0 ; i < s.length() ; i++) {
        if(s[i] <=  'z' && s[i] >= 'a') {
            s[i] -= 32;
        }
    }
}

int main() {
    while(cin.peek() != EOF) {
        getline(cin, s);
        upperCase();
        cout<< s << endl;   
    }
}