#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    double first{};
    double last{};
    double stride{};
    double percent{};
    int mult{0};
    double price{};
    double tax{};
    double withTax{};

    cout << "INPUT PART\n" << "==========\n" << "Enter first price: ";
    cin >> first;
    while (first < 0) // if incorret input as "first price" (negative numbers)
    {
        cout << "ERROR: First price must be at least 0 (zero) SEK\n";
        cout << "Enter first price: ";
        cin >> first;
    }
    cout << setw(17) << left << "Enter last price" << ": ";
    cin >> last;
    while (last < first) // if incorret input as "last price" (last price smaller than first price)
    {
        cout << "ERROR: Last price can not be smaller than first price\n";
        cout << setw(17) << left << "Enter last price" << ": ";
        cin >> last;
    }
    cout << setw(17) << left << "Enter stride" << ": ";
    cin >> stride;
    while (stride < 0.01) // if incorret input as "first price" (too small stride)
    {
        cout << "ERROR: Stride must be at least 0.01\n";
        cout << setw(17) << left << "Enter stride" << ": ";
        cin >> stride;
    }
    cout << setw(17) << left << "Enter tax percent" << ": ";
    cin >> percent;
    while (percent < 0 || percent > 100) // if incorret input as "percent" (should not be negative or over 100%)
    {
        cout << "ERROR: Tax percent must be between 0-100%";
        cout << setw(17) << left << "Enter tax percent" << ": ";
        cin >> percent;
    }

    cout << "\nTAX TABLE\n" << "=========" << endl;
    cout << setw(12) << right << "Price" << setw(17) << right << "Tax" << setw(21) << right << "Price with tax\n" << "-------------------------------------------------" << endl;

    do
    {
        price = first + stride * mult;
        tax = price * percent * 0.01;
        withTax = price + tax; 
        cout << setw(12) << fixed << setprecision(2) << price << setw(17) << tax << setw(20) << withTax << endl; // "right" is default for setw
        mult += 1; //increases the multiplier by 1               
    } 
    while (price <= last - stride);


}
