/*File Name: assign3_s_f88.cpp
 
 Author: Shane Fleming
 Date: 02/17/16
 Assignment Number: 3
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Pointers and Dynamic Memory Allocation*/

#include <iostream>
#include <iomanip>

using namespace std;

/******************************************************************
 median:
 ******************************************************************/

double median(int array, int size)
{
    int medianV = 0;
    
    
    return medianV;
}

/******************************************************************
 pizza: Calcualtes the number of whole pizzas and slices needed to
 feed int people
 int people = specified in main (total number of pizza eaters)
 int *pizzas = points at main value instead of passing by reference
 int *slices = points at main value instead of passing by reference
 returns: double price of total pizzas and slices
 ******************************************************************/

double pizza (int people, int *pizzas, int *slices)
{
    int totalSlices = people*3;
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
}

/******************************************************************
 
 ******************************************************************/

void resize()
{
}

/******************************************************************
 
 ******************************************************************/

void shiftX()
{
}

/******************************************************************
 
 ******************************************************************/

//int *subArray (int *array, int start, int length)
//{
//    int *result = duplicateArray(__________, ___________);
//    return result;
//}

/******************************************************************
 
 ******************************************************************/

int main()
{
    
    int peopleM = 25, pizzaM = 0, slicesM = 0;
    double tot = 0;
    
    tot =  pizza(peopleM, &pizzaM, &slicesM);
    
    cout << "Testing pizza for 25 people:" << endl
    << "Epected result: 112.80 p: 9 s: 3"  << endl
    << fixed << setprecision(2) << "Actual results: " << tot
    << fixed << setprecision(0) << " p: " << pizzaM
    << " s: " << slicesM << endl;
    
    return 0;
}
