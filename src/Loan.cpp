#include "Loan.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

Loan::Loan(){};
Loan::Loan(double p, double air, int tm) {
    principal = p;
    annualInterestRate = air;
    tenureMonths = tm;
}

void Loan::setLoanDetails(double p, double air, int tm) {
    principal = p;
    annualInterestRate = air;
    tenureMonths = tm;
}

double Loan::getPrincipal() {
    return principal;
}

double Loan::getAnnualInterestRate() {
    return annualInterestRate;
}

int Loan::getTenureMonths() {
    return tenureMonths;
}

double Loan::calculateEMI() {
    double monthlyRate = annualInterestRate/12/100;
    double temp = pow(1 + monthlyRate, tenureMonths);
    double emi = principal*monthlyRate*temp / (temp-1);
    return emi;
}

double Loan::calculateTotalInterest() {
    double emi = calculateEMI();
    double totalPayment = emi*tenureMonths;
    double totalInterest = totalPayment-principal;
    return totalInterest;
}

double Loan::calculateTotalPayment() {
    double emi = calculateEMI();
    return emi * tenureMonths;
}

bool Loan::isValid() {
    if (principal>0 && annualInterestRate>0 && tenureMonths>0) {
        return true;
    }
    return false;
}

void Loan::displayLoanSummary() {
    if (!isValid()) {
        cout << "Please enter valid loan details first!"<<endl;
        return;
    }
    
    cout<<fixed<<setprecision(2);
    cout<<"\n=== LOAN SUMMARY ==="<<endl;
    cout<<"Principal Amount: Rs" << principal<<endl;
    cout<<"Annual Interest Rate: " << annualInterestRate<< "%"<<endl;
    cout<<"Loan Tenure: " << tenureMonths << " months"<<endl;
    cout<<"Monthly EMI: Rs" << calculateEMI()<<endl;
    cout<<"Total Interest: Rs" << calculateTotalInterest()<<endl;
    cout<<"Total Payment: Rs" << calculateTotalPayment()<<endl;
    cout<<"========================="<<endl;
}