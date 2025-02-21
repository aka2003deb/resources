#include <iostream>
#include <string>
using namespace std;

// Base class for all accounts
class account {
public:
    string holder;
    double balance;

    account(string holder) : holder(holder), balance(0) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) balance -= amount;
    }

    virtual void print_account() const = 0; // Pure virtual function
};

// Derived class for saving accounts
class saving_account : public account {
public:
    saving_account(string holder) : account(holder) {}

    void deposit(double amount) override {
        account::deposit(amount); // Use base class method
    }

    void withdraw(double amount) override {
        account::withdraw(amount); // Use base class method
    }

    double fixed_deposit_rate() const {
        return balance * 4.5 / 100;
    }

    void print_account() const override {
        cout << "holder: " << holder << endl;
        cout << "balance: " << balance << endl;
        cout << "interest rate: 4.5" << endl;
        cout << "FD rates: " << fixed_deposit_rate() << endl;
    }
};

// Derived class for current accounts
class current_account : public account {
public:
    current_account(string holder) : account(holder) {}

    void deposit(double amount) override {
        account::deposit(amount); // Use base class method
    }

    void withdraw(double amount) override {
        account::withdraw(amount); // Use base class method
    }

    void print_account() const override {
        cout << "holder: " << holder << endl;
        cout << "balance: " << balance << endl;
    }
};

int main() {
    saving_account *sa = new saving_account("John");
    sa->deposit(1000);
    sa->withdraw(100.3);
    sa->print_account();
    delete sa;

    current_account *ca = new current_account("Mathew");
    ca->deposit(10);
    ca->withdraw(100.3); // Testing overdraft scenario (shouldn't change balance)
    ca->print_account();
    delete ca;

    return 0;
}
