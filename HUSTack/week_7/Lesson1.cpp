#include <bits/stdc++.h>
using namespace std;

struct Transaction {
    string from_account;
    string to_account;
    int money;
};

bool flag = false;

void data_process(map<string, long> &totalMoneyFromAccount, vector<Transaction> &transactions, set<string> &account_set, long &totalMoney) {
    string from_account, to_account, time_point, atm;
    int money;

    while(true) {
        cin >> from_account;
        if(from_account == "#") break;
        else {
            cin >> to_account >> money >> time_point >> atm;

            transactions.push_back({ from_account, to_account, money });
            account_set.insert(from_account);
            account_set.insert(to_account);
            totalMoney += money;
            totalMoneyFromAccount[from_account] += money;
        }
    }
}

void transaction_cycle(set<string> &visited, vector<Transaction> &transactions, string currAccount, string account, int k, int u) {
    for(const Transaction& transaction : transactions) {
        if(transaction.from_account == currAccount && visited.find(transaction.to_account) == visited.end()) {
            visited.insert(transaction.to_account);
            if(u == k && transaction.to_account == account) {
                flag = true;
                return;
            }
            else {
                transaction_cycle(visited, transactions, transaction.to_account, account, k, u + 1);
            }
            visited.erase(transaction.to_account);
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false);;
    cin.tie(0);cout.tie(0);

    vector<Transaction> transactions;
    transactions.reserve(1000);
    set<string> account_set;
    set<string> visited;
    map<string, long> totalMoneyFromAccount;
    long totalMoney = 0;
    data_process(totalMoneyFromAccount, transactions, account_set, totalMoney);
    
    string query;
    while(true) {
        cin >> query;
        if(query == "#") break;
        else if(query == "?number_transactions")
            cout << transactions.size() << endl;
        else if(query == "?total_money_transaction")
            cout << totalMoney << endl;
        else if(query == "?list_sorted_accounts") {
            for(const string& account : account_set) 
                cout << account << " ";
            cout << endl;
        } else if(query == "?total_money_transaction_from") {
            string account;
            cin >> account;
            cout << totalMoneyFromAccount[account] << endl;
        } else if(query == "?inspect_cycle") {
            string account;
            int k;
            cin >> account >> k;
            flag = false;
            visited.clear();
            transaction_cycle(visited, transactions, account, account, k, 1);
            if(flag) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}