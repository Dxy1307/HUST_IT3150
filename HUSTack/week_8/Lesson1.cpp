// Citizen data analysis
#include <bits/stdc++.h>
using namespace std;

long long numPeopleBetween[3005][1236];

int convertYear(string date) {
    return stoi(date.substr(0, 4));
}

int convertMonthDay(string date) {
    return stoi(date.substr(5, 2) + date.substr(8,2));
}

void data_process(long &totalPeople, unordered_map<string, long> &countPeopleDate, unordered_map<string, long> &generations, unordered_map<string, bool> &unrelatedPeople, int &maxUnrelatedPeople) {
    string code, date_of_birth, father_code, mother_code, is_alive, region_code;

    while(true) {
        cin >> code;
        if(code == "*") break;
        else {
            cin >> date_of_birth >> father_code >> mother_code >> is_alive >> region_code;

            totalPeople++;
            countPeopleDate[date_of_birth]++;
            numPeopleBetween[convertYear(date_of_birth)][convertMonthDay(date_of_birth)] += 1;

            if(father_code == "000000" && mother_code == "000000")
                generations[code] = 1;
            else {
                generations[code] = max(generations[father_code], generations[mother_code]) + 1;
            }

            if(unrelatedPeople[father_code] == true || unrelatedPeople[mother_code] == true) {
                unrelatedPeople[code] = false;                
            } else {
                unrelatedPeople[code] = true;
                maxUnrelatedPeople++;
            }
        }
    }        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long totalPeople = 0;
    unordered_map<string, long> countPeopleDate;
    unordered_map<string, long> generations;
    unordered_map<string, bool> unrelatedPeople;
    unrelatedPeople["000000"] = false;
    int maxUnrelatedPeople = 0;

    for(long i = 1; i <= 3000; ++i)
        for(int j = 1; j <= 1231; ++j) 
            numPeopleBetween[i][j] = 0;

    data_process(totalPeople, countPeopleDate, generations, unrelatedPeople, maxUnrelatedPeople);

    for(long i = 1; i <= 3000; ++i) {
        for(int j = 1; j <= 1231; ++j) {
            numPeopleBetween[i][j] += numPeopleBetween[i][j - 1];
        }
        numPeopleBetween[i + 1][0] += numPeopleBetween[i][1231];
    }

    string query;
    while(true) {
        cin >> query;
        if(query == "***") break;
        else if(query.length() == 13) 
            cout << totalPeople << '\n';
        else if(query.length() == 21) {
            string date;
            cin >> date;
            cout << countPeopleDate[date] << '\n';
        } else if(query.length() == 26) {
            string from_date, to_date;
            cin >> from_date >> to_date;
            int i1 = convertYear(from_date);
            int i2 = convertYear(to_date);
            int j1 = convertMonthDay(from_date);
            int j2 = convertMonthDay(to_date);
            cout << numPeopleBetween[i2][j2] - numPeopleBetween[i1][j1 - 1] << '\n';
        } else if(query.length() == 19) {
            string code;
            cin >> code;
            cout << generations[code] - 1 << '\n';
        } else if(query.length() == 20) {
            cout << maxUnrelatedPeople << '\n';
        }
    }
}