//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

    // Function prototype
    void getPayment(int, double, int);

    int main()
    {
        // Declare variables
        int carPrice = 0;
        int rebate = 0;
        double creditRate = 0.0;
        double dealerRate = 0.0;
        int term = 0;

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

        // Call function to calculate payments (now void)
        cout << fixed << setprecision(2) << endl; 
        cout << "Credit union payment: $";
        getPayment(carPrice - rebate, creditRate / 12, term * 12);

        cout << "Dealer payment: $";
        getPayment(carPrice, dealerRate / 12, term * 12);

        return 0;
    } // end of main function    

    // ***** Function definitions *****
    void getPayment(int prin, double monthRate, int months)
    {
        // Calculates and prints a monthly payment
        double monthPay = 0.0;
        monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
        cout << monthPay << endl; // Output the result instead of returning
    } // end of getPayment function