#include <gtest/gtest.h>
#include <fstream>
#include "../src/Loan.h"

// Test loading from config file
TEST(LoanConfigTest, LoadFromConfigFile) {
    std::ifstream configFile("../config.txt");
    if (!configFile.is_open()) {
        configFile.open("config.txt");
    }
    
    if (configFile.is_open()) {
        double principal, rate;
        int months;
        
        configFile >> principal >> rate >> months;
        configFile.close();
        
        Loan loan(principal, rate, months);
        EXPECT_TRUE(loan.isValid());
        EXPECT_GT(loan.calculateEMI(), 0);
        EXPECT_GT(loan.calculateTotalPayment(), principal);
    }
}

// Test negative numbers
TEST(LoanBoundaryTest, NegativeNumbers) {
    Loan negativeLoan(-10000, -12, -12);
    EXPECT_FALSE(negativeLoan.isValid());
}

// Test zero values
TEST(LoanBoundaryTest, ZeroValues) {
    Loan zeroLoan(0, 0, 0);
    EXPECT_FALSE(zeroLoan.isValid());
}