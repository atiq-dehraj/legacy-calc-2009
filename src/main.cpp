#include <iostream>
#include <fstream>
#include "Loan.h"
using namespace std;

void showMenu() {
    cout << "\n=== LOAN CALCULATOR MENU ===" << endl;
    cout << "1. Enter Loan Details" << endl;
    cout << "2. Calculate EMI" << endl;
    cout << "3. Show Total Interest" << endl;
    cout << "4. Show Total Payment" << endl;
    cout << "5. Display Full Summary" << endl;
    cout << "6. Load from config.txt" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option (1-7): ";
}

bool loadFromConfig(Loan& loan) {
    ifstream configFile("../config.txt");
    if (!configFile.is_open()) {
        configFile.open("config.txt");
        if (!configFile.is_open()) {
            return false;
        }
    }
    
    double principal, rate;
    int months;
    
    configFile >> principal >> rate >> months;
    configFile.close();
    
    loan.setLoanDetails(principal, rate, months);
    return loan.isValid();
}

int main() {
    Loan loan;
    int choice;
    double principal, rate;
    int months;
    

    
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter Principal Amount: $";
                cin >> principal;
                cout << "Enter Annual Interest Rate (%): ";
                cin >> rate;
                cout << "Enter Loan Tenure (months): ";
                cin >> months;
                
                loan.setLoanDetails(principal, rate, months);
                
                if (loan.isValid()) {
                    cout << "Loan details saved successfully!" << endl;
                } else {
                    cout << "Error: All values must be positive!" << endl;
                }
                break;
                
            case 2:
                if (loan.isValid()) {
                    cout << "Monthly EMI: $" << loan.calculateEMI() << endl;
                } else {
                    cout << "Please enter loan details first (Option 1 or 6)" << endl;
                }
                break;
                
            case 3:
                if (loan.isValid()) {
                    cout << "Total Interest: $" << loan.calculateTotalInterest() << endl;
                } else {
                    cout << "Please enter loan details first (Option 1 or 6)" << endl;
                }
                break;
                
            case 4:
                if (loan.isValid()) {
                    cout << "Total Payment: $" << loan.calculateTotalPayment() << endl;
                } else {
                    cout << "Please enter loan details first (Option 1 or 6)" << endl;
                }
                break;
                
            case 5:
                loan.displayLoanSummary();
                break;
                
            case 6:
                if (loadFromConfig(loan)) {
                    cout << "Loaded loan details from config.txt successfully!" << endl;
                    loan.displayLoanSummary();
                } else {
                    cout << "Error: Could not open config.txt or invalid data!" << endl;
                }
                break;
                
            case 7:
                cout << "Thank you for using Loan Calculator!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    
    return 0;
}