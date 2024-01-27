// Analyze Code Submission of a Programming Contest
#include <bits/stdc++.h>
using namespace std;

inline int convertTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));

    return hour * 3600 + minute * 60 + second;
}

void data_process(long &totalSubmissions, long &totalErrSubmissions, unordered_map<string, long> &submissionErrByUsers, unordered_map<string, long> &totalPointOfUsers, long long *nsp) {
    string userID, problemID, timePoint, status;
    int point;
    
    while(true) {
        cin >> userID;
        if(userID == "#") break;
        else {
            cin >> problemID >> timePoint >> status >> point;

            totalSubmissions++;
            if(status == "ERR") {
                totalErrSubmissions++;
                submissionErrByUsers[userID]++;
            } else {
                totalPointOfUsers[userID] += point;
            }

            nsp[convertTime(timePoint)]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long totalSubmissions = 0;
    long totalErrSubmissions = 0;
    unordered_map<string, long> submissionErrByUsers;
    unordered_map<string, long> totalPointOfUsers;
    long long nsp[86405];

    for(int i = 1; i <= 86400; ++i) 
        nsp[i] = 0;

    data_process(totalSubmissions, totalErrSubmissions, submissionErrByUsers, totalPointOfUsers, nsp);

    for(int i = 1; i <= 86400; ++i) 
        nsp[i] += nsp[i - 1];

    string query;
    string userID;
    while(true) {
        cin >> query;
        if(query == "#") break;
        else if(query.length() == 25 && query[1] == 't')
            cout << totalSubmissions << '\n';
        else if(query.length() == 23)
            cout << totalErrSubmissions << '\n';
        else if(query.length() == 31) {
            cin >> userID;
            cout << submissionErrByUsers[userID] << '\n';
        } else if(query.length() == 20) {
            cin >> userID;
            cout << totalPointOfUsers[userID] << '\n';
        } else if(query.length() == 25 && query[1] == 'n') {
            string from_time, to_time;
            cin >> from_time >> to_time;
            int t1 = convertTime(from_time);
            int t2 = convertTime(to_time);
            cout << nsp[t2] - nsp[t1 - 1] << '\n';
        }
    }
}