//
//  main.cpp
//  PRG-7-2-Average-Rainfall
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that lets the user enter the total rainfall for each of 12 months into an
//  array of doubles. The program should calculate and display the total rainfall for the
//  year, the average monthly rainfall, and the months with the highest and lowest amounts.
//
//  Input Validation: Do not accept negative numbers for monthly rainfall figures.

#include <iostream>

using namespace std;

void inputData(float[], int, string[]);
void calculateTotal(float[], int);
void calculateHighest(float[], int, string[]);
void calculateLowest(float[], int, string[]);

int main()
{
    const int INT_NUMBER_OF_MONTHS = 12;
    
    // Not using an array of doubles,
    // don't need numbers that large!!!
    float fltArrayMonths[INT_NUMBER_OF_MONTHS];
    
    string strArrayMonthNames[INT_NUMBER_OF_MONTHS] = {"January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October",
        "November", "December"};
    
    inputData(fltArrayMonths, INT_NUMBER_OF_MONTHS, strArrayMonthNames);
    
    calculateTotal(fltArrayMonths, INT_NUMBER_OF_MONTHS);
    
    calculateHighest(fltArrayMonths, INT_NUMBER_OF_MONTHS, strArrayMonthNames);
    
    calculateLowest(fltArrayMonths, INT_NUMBER_OF_MONTHS, strArrayMonthNames);
    
    return 0;
}

void inputData(float fltArrayMonths[], int INT_NUMBER_OF_MONTHS, string strArrayMonthNames[])
{
    float fltTempMonthRainfall;
    
    for(int i = 0 ; i < INT_NUMBER_OF_MONTHS ; i++)
    {
        cout << "Please enter the amount of rainfall for "
        << strArrayMonthNames[i] << ": ";
        cin >> fltTempMonthRainfall;
        while(!cin || fltTempMonthRainfall < 0.0f || fltTempMonthRainfall > 1000.0f)
        {
            cout << "Please enter a number between 0.0 and 1000.0:\n";
            cin.clear();
            cin.ignore();
            cin >> fltTempMonthRainfall;
        }
        fltArrayMonths[i] = fltTempMonthRainfall;
    }
}

void calculateTotal(float fltArrayMonths[], int INT_NUMBER_OF_MONTHS)
{
    float fltRainfallTotal;
    
    fltRainfallTotal = 0; // Initialize accumulator
    
    for(int i = 0 ; i < INT_NUMBER_OF_MONTHS ; i++)
    {
        fltRainfallTotal += fltArrayMonths[i];
    }
    
    cout << "The total rainfall for the year is: "
    << fltRainfallTotal << endl;
}

void calculateHighest(float fltArrayMonths[], int INT_NUMBER_OF_MONTHS, string strArrayMonthNames[])
{
    int intHighest;
    
    intHighest = 0;
    
    for(int i = 0 ; i < INT_NUMBER_OF_MONTHS ; i++)
    {
        if(fltArrayMonths[i] > fltArrayMonths[intHighest])
        {
            intHighest = i;
        }
    }
    
    cout << "The month of " << strArrayMonthNames[intHighest]
    << " had the most rainfall, totaling: " << fltArrayMonths[intHighest] << endl;
}

void calculateLowest(float fltArrayMonths[], int INT_NUMBER_OF_MONTHS, string strArrayMonthNames[])
{
    int intLowest;
    
    intLowest = 0;
    
    for(int i = 0 ; i < INT_NUMBER_OF_MONTHS ; i++)
    {
        if(fltArrayMonths[i] < fltArrayMonths[intLowest])
        {
            intLowest = i;
        }
    }
    
    cout << "The month of " << strArrayMonthNames[intLowest]
    << " had the least rainfall, totaling: " << fltArrayMonths[intLowest] << endl;
}


