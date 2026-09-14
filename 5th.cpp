#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class PaymentMethod{
    protected:
        string transactionId;
        double amount;

    public:
        PaymentMethod(string Id,double amt)
            :transactionId(Id),amount(amt){}

        virtual bool processPayment() const =0;
        virtual ~PaymentMethod() = default;

};

class CreditCardPayment: public PaymentMethod{
    private:
        string maskedCardNumber;

    public:
        CreditCardPayment(string tid,double amt,string card)
            : PaymentMethod(tid,amt),maskedCardNumber(card){}

        bool processPayment() const override{
            cout<<"Credit-card transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<maskedCardNumber<<" completed."<<endl;
            return true;
        }
};

class UPIPayment: public PaymentMethod{
    private:
        string upiId;

    public:
        UPIPayment(string tid,double amt,string upi)
            : PaymentMethod(tid,amt),upiId(upi){}

        bool processPayment() const override{
            cout<<"UPI transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<upiId<<" completed."<<endl;
            return true;
        }
};

class NetBankingPayment: public PaymentMethod{
    private:
        string bankName;

    public:
        NetBankingPayment(string tid,double amt,string bank)
            : PaymentMethod(tid,amt),bankName(bank){}

        bool processPayment() const override{
            cout<<"Net-banking transaction "<<transactionId<<" for Rs. "<<amount<<" using "<<bankName<<" completed."<<endl;
            return true;
        }
};

int main(){
    vector<unique_ptr<PaymentMethod>> Payments;
    Payments.push_back(make_unique<CreditCardPayment>("TXN001",2500,"XXXX-XXXX-1234"));
    Payments.push_back(make_unique<UPIPayment>("TX002",1200,"student@upi"));
    Payments.push_back(make_unique<NetBankingPayment>("TX003",5000,"Example Bank"));

    cout<<"===Payment Gateway==="<<endl;
    for(const auto& payment:Payments){
        payment->processPayment();

    }
}