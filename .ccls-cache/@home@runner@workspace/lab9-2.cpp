//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by Kevin Zadonia on 3/20/25


#include <iostream>
#include <iomanip>
#include <cmath>


//function prototype
double payment (int, double, int);



int main()
{
    using namespace std;
//declare variables
int carPrice = 0;
int rebate = 0;
double creditRate = 0.0;
double dealerRate = 0.0;
int term = 0;
double creditPayment = 0.0;
double dealerPayment = 0.0;
double totalCreditPayment = 0.0;
double totalDealerPayment = 0.0;

//get user input
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

//call function to calculate payments
creditPayment = payment(carPrice - rebate, creditRate / 12, term * 12);

    //if statement to check if the user entered a valid option
    if (creditPayment == -1) {
        cout << "Error, invalid payment option." << endl;
        return 1; 
    }
//caclulate dealer payment    
dealerPayment = payment(carPrice, dealerRate / 12, term * 12);

    //if statement to check if the user entered a valid option
    if (dealerPayment == -1) {
        cout << "Error: Invalid payment option." << endl;
        return 1; 
    }

    //total payments for credit union
    totalCreditPayment = creditPayment * term * 12;

    //total payments for dealer
    totalDealerPayment = dealerPayment * term * 12;

    
//display payments
cout << fixed << setprecision(2) << endl;

cout << "Credit union payment: $" << creditPayment << endl;
    
cout << "Total amount paid through credit union: $" << totalCreditPayment << endl;
    
cout << "Dealer payment: $" << dealerPayment << endl;

cout << "Total amount paid through dealer: $" << totalDealerPayment << endl;





    return 0;
} //end of main function    

double payment (int prin, double monthRate, int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    monthPay = prin * monthRate /
        (1 - pow(monthRate + 1, -months));
    return monthPay;
    
} //end of getPayment function

