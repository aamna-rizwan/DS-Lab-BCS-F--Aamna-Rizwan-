
#include <iostream>
using namespace std;

class BankAccount{
    private:
    int balance;
    public:
    BankAccount(){balance=0;}
    BankAccount(int b){
        balance=b;
    }
    BankAccount(const BankAccount &obj){
        balance = obj.balance;
    }
    void deduct(int d){
        balance=balance-d;
    }
    void display(){
        cout << "Balance : " << balance << endl;
    }
};

int main() {
    BankAccount account1;
    account1.display();
    BankAccount account2(1000);
    account2.display();
    BankAccount account3 = account2;
    account3.deduct(200);
    account3.display();
    account2.display();
}
