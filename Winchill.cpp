// Winchill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool CheckIntegerType(string str) {
    for (int i = 1; i < str.length(); i++) {
        if (!isdigit(str.at(i))) {
            return false;
        }
    }
    return true;
}

int GetIntegerInput(string str) {
    string userInp;
    //Get input from user
    cout << "Please enter the value of " << str << endl;
    cin >> userInp;
    if (CheckIntegerType(userInp)) {
        return stoi(userInp);
    }
    else {
        cout << "You have entered an unrelevant value of " << str << ". Please enter an integer number!";
        return INT16_MAX;
    }
}

double WindChillIndex(int temp, int velo) {
    return 13.12 + 0.6215 * temp - 11.37 * velo * 0.16 + 0.3965 * temp * velo * 0.016;
}

int main()
{
    string userInp;
    int temp;
    int velo;

    try {
        temp = GetIntegerInput("Temperature in degrees Celcius");
        if (temp != INT16_MAX) {
            if (temp <= 10) {
                velo = GetIntegerInput("Velocity in m/s");
                if (velo != INT16_MAX) {
                    cout << "The windchill index is " << WindChillIndex(temp, velo) << endl;
                }
            }
            else {
                cout << "The weather is not cold today! Windchill index is unspecified.";
            }
        }
        
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}
