#include <bits/stdc++.h>
using namespace std;

int descendants(string name, map<string, string> &family, map<string, int> &descendantsResult) {
    if(descendantsResult.find(name) != descendantsResult.end())
        return descendantsResult[name];

    int count = 0;
    for(auto& temp : family) {
        if(temp.second == name) {
            count += 1 + descendants(temp.first, family, descendantsResult);
        }
    }

    descendantsResult[name] = count;
    return count;
}

int generations(string name, map<string, string> &family, map<string, int> &descendantsResult) {
    if(descendants(name, family, descendantsResult) == 0) {
        return 0;
    } else {
        int count = 1;
        bool flag = false;
        for(auto& temp : family) {
            if(temp.second == name && descendants(temp.first, family, descendantsResult) > 0) {
                flag = true;
                count = max(count, generations(temp.first, family, descendantsResult));
            }
        }
        if(flag) count++;
        return count;
    }
}

int main() {
    map<string, string> family;
    string child, parent;

    while(true) {
        cin >> child;
        if(child == "***") break;
        else {
            cin >> parent;
            family[child] = parent;
        }
    }

    string cmd, param;
    map<string, int> descendantsResult;

    queue<int> ans;
    while(true) {
        cin >> cmd;
        if(cmd == "***") break;
        else if(cmd == "descendants") {
            cin >> param;
            ans.push(descendants(param, family, descendantsResult));
        } else if(cmd == "generation") {
            cin >> param;
            ans.push(generations(param, family, descendantsResult));
        }
    }

    while(!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
}