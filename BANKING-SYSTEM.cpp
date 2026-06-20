#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    vector<string> transactions;

public:
    Account(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposited: Rs. " + to_string(amount));
        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amount;
        transactions.push_back("Withdrawn: Rs. " + to_string(amount));
        cout << "Withdrawal Successful!\n";
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        transactions.push_back("Transferred Rs. " + to_string(amount) +
                               " to Account " + to_string(receiver.accountNumber));

        receiver.transactions.push_back("Received Rs. " + to_string(amount) +
                                        " from Account " + to_string(accountNumber));

        cout << "Transfer Successful!\n";
    }

    void showDetails() {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        if (transactions.empty()) {
            cout << "No Transactions Found.\n";
            return;
        }

        for (string t : transactions) {
            cout << "- " << t << endl;
        }
    }
};

int main() {
    Account user1("Ayaan", 1001, 5000);
    Account user2("Ali", 1002, 3000);

    int choice;
    double amount;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer Funds\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Amount: ";
                cin >> amount;
                user1.deposit(amount);
                break;

            case 2:
                cout << "Enter Amount: ";
                cin >> amount;
                user1.withdraw(amount);
                break;

            case 3:
                cout << "Enter Amount: ";
                cin >> amount;
                user1.transfer(user2, amount);
                break;

            case 4:
                user1.showDetails();
                break;

            case 5:
                user1.showTransactions();
                break;

            case 6:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}