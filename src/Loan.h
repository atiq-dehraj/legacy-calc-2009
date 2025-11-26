#ifndef LOAN_H
#define LOAN_H

class Loan {
private:
    double principal;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan();
    Loan(double p, double air, int tm);
    
    void setLoanDetails(double p, double air, int tm);
    
    double getPrincipal();
    double getAnnualInterestRate();
    int getTenureMonths();
    
    double calculateEMI();
    double calculateTotalInterest();
    double calculateTotalPayment();
    
    void displayLoanSummary();
    
    bool isValid();
};

#endif