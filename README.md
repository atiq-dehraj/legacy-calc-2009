Loan Calculator Project

Project Overview:

A simple C++ loan calculation system that computes EMI (Equated Monthly Installment), total interest, and total payment for loans. The project follows object-oriented programming principles with proper separation of concerns.

Project structure: 
legacy-calc-2009/
├── README.md
├── Doxyfile
├── src/
│   ├── main.cpp
│   ├── Loan.h
│   └── Loan.cpp
├── test/
│   └── test_emi.cpp
└── docs/
    └── html/ (generated documentation)
    
Features: 
    Menu-driven interface for easy user interaction

    Loan calculations: EMI, total interest, total payment

    Input validation for positive values

    Boundary testing for negative, zero, and extreme values

    Documentation support via Doxygen


Source Code Files:

1. main.cpp

    Purpose: Main application with menu-driven interface

    Functions:

        showMenu(): Displays the main menu

        main(): Handles user input and menu navigation

2. Loan.h

    Purpose: Class declaration for Loan operations

    Key Components:

        Private members: principal, annualInterestRate, tenureMonths

        Public methods: Constructors, setters, calculation methods, validation
        
3. Loan.cpp

    Purpose: Implementation of Loan class methods

    Key Methods:

        calculateEMI(): Computes monthly installment

        calculateTotalInterest(): Computes total interest payable

        calculateTotalPayment(): Computes total repayment amount

        isValid(): Validates loan parameters

        displayLoanSummary(): Shows complete loan details
        
        
Test Files: 
test_emi.cpp

    Purpose: Google Tests for boundary conditions

    Test Cases:

        Negative values (principal, interest rate, tenure)

        Zero values validation

        Overflow scenarios (very large values)

        Underflow scenarios (very small positive values)
        
Compilation Instructions: 
        
    Main Application: 
    cd src/
    g++ -o m main.cpp Loan.cpp
    ./m

    Test: 
    cd test/
    g++ -o test_emi test_emi.cpp ../src/Loan.cpp -lgtest -lgtest_main -pthread
    ./test_emi

Document generation: 
    oxygen Doxyfile
    # Open docs/html/index.html in browser
    
Usage examples
    menu options: 
    Enter Loan Details: Input principal, interest rate, and tenure

    Calculate EMI: Show monthly installment only

    Show Total Interest: Display total interest amount

    Show Total Payment: Display total repayment amount

    Display Full Summary: Complete loan breakdown

    Exit: Close application
    

