#include <bits/stdc++.h>
using namespace std;

inline int convertTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));

    return hour * 3600 + minute * 60 + second;
}

void data_process(long &totalRevenue, unordered_map<string, long> &revenueOfShop, unordered_map<string, long> &consumeOfCustomerShop, long &totalOrders, long long *rits) {
    string customerID, productID, shopID, timePoint;
    int price;

    while(true) {
        cin >> customerID;
        if(customerID == "#") break;
        else {
            cin >> productID >> price >> shopID >> timePoint;

            totalOrders++;
            totalRevenue += price;
            revenueOfShop[shopID] += price;
            consumeOfCustomerShop[customerID + shopID] += price;
            rits[convertTime(timePoint)] += price;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long totalOrders = 0;
    long totalRevenue = 0;
    unordered_map<string, long> revenueOfShop;
    unordered_map<string, long> consumeOfCustomerShop;
    long long rits[86405];

    for(int i = 1; i <= 86400; ++i)
        rits[i] = 0;

    data_process(totalRevenue, revenueOfShop, consumeOfCustomerShop, totalOrders, rits);

    for(int i = 1; i <= 86400; ++i) 
        rits[i] += rits[i - 1];

    string query;
    while(true) {
        cin >> query;
        if(query == "#") break;
        else if(query.length() == 20) 
            cout << totalOrders << '\n';
        else if(query.length() == 14)
            cout << totalRevenue << '\n';
        else if(query.length() == 16) {
            string shop;
            cin >> shop;
            cout << revenueOfShop[shop] << '\n';
        } else if(query.length() == 31) {
            string customer, shop;
            cin >> customer >> shop;
            cout << consumeOfCustomerShop[customer + shop] << '\n';
        } else if(query.length() == 24) {
            string from_time, to_time;
            cin >> from_time >> to_time;
            cout << rits[convertTime(to_time)] - rits[convertTime(from_time) - 1] << '\n';
        }
    }

    return 0;
}