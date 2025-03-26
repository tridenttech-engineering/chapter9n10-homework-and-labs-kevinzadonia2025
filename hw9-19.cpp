//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by Kevin Zadonia on 3/25/25

#include <iostream>
#include <iomanip>
#include <cmath>

// Function prototypes
double payment(int, double, int);
double getTotal(double monthPay, int months);

int main()
{
    using namespace std;

    // Declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCreditPayment = 0.0;
    double totalDealerPayment = 0.0;

    // Get user input
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    creditPayment = payment(carPrice - rebate, creditRate / 12, term * 12);

    // Check if the user entered a valid option
    if (creditPayment == -1) {
        cout << "Error: Invalid payment option for credit union." << endl;
        return 1; 
    }

    // Calculate dealer payment    
    dealerPayment = payment(carPrice, dealerRate / 12, term * 12);

    // Check if the user entered a valid option
    if (dealerPayment == -1) {
        cout << "Error: Invalid payment option for dealer." << endl;
        return 1; 
    }

    // Total payments for credit union using getTotal function
    totalCreditPayment = getTotal(creditPayment, term * 12);

    // Total payments for dealer using getTotal function
    totalDealerPayment = getTotal(dealerPayment, term * 12);

    // Display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Total amount paid through credit union: $" << totalCreditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "Total amount paid through dealer: $" << totalDealerPayment << endl;

    return 0;
} // end of main function    

double payment(int prin, double monthRate, int months)
{
    // Check for zero denominator
    if (monthRate == 0) {
        return -1; // Return -1 if the denominator would be zero
    }

    // Calculates and returns a monthly payment
    double monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
    return monthPay;
} // end of payment function

double getTotal(double monthPay, int months)
{
    double total = 0.0;
    double roundPay = 0.0;

    roundPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    total = roundPay * months;
    return total;
}