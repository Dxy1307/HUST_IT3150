#include <bits/stdc++.h> 
using namespace std;

int main() {
    char c;
    int count = 0;
    bool isWord = false;

    while(cin.peek() != EOF) {
        c = cin.get();

        if(isspace(c)) {
            if(isWord) {
                count++;
                isWord = false;
            }
        } else {
            isWord = true;  
        }
    }

    if(isWord) {
        count++;
    }

    cout << count;
}