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
 median: Fins the median with a given array and size of the array
 int *array = paints at the array of ints in main, in which to find
 the median of
 int size = specified in main (size of the array being passed)
 returns: median value of the array elements, as a double
 ******************************************************************/

double median(int *array, int size)
{
    double returnMedian = 0, cleanUp = 0, cleanUp2 = 0; 

    if (size % 2 != 0)
    returnMedian = *(array + (size / 2));
    else                             //needs work
{
     cleanUp = size/2;
     cleanUp2 = cleanUp + 1;
   //1  returnMedian = (*(array+cleanUp) + *(array+cleanUp2)) / 2;
                                     //does not work w/cleanup
   //2  returnMedian = (2 + 7) / 2;  //returns int division, not double
   //3  returnMedian = 4.5;          //returns 4.5, so can return double
} 
    return returnMedian;
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
 resize: 
 ******************************************************************/

void resize()
{
}

/******************************************************************
 shiftX:
 ******************************************************************/

void shiftX()
{
}

/******************************************************************
 subArray:
 ******************************************************************/

//int *subArray (int *array, int start, int length)
//{
//    int *result = duplicateArray(__________, ___________);
//    return result;
//}

/******************************************************************
 main:
 ******************************************************************/

int main()
{

    int sizeOne = 9, arrayOne[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sizeTwo = 8, arrayTwo[] = {1, 2, 3, 4, 5, 6, 7, 8};
    double takeMedian = 0;

    takeMedian = median(arrayOne, sizeOne);

    cout << endl << "Testing median:" << endl 
    << "Test data: 1 2 3 4 5 6 7 8 9" << endl
    << "Expected median: 5" << endl
    << "Actual median: " << takeMedian << endl;

    takeMedian = median(arrayTwo, sizeTwo);

    cout  << "Test data: 1 2 3 4 5 6 7 8" << endl
    << "Expected median: 4.5" << endl
    << "Actual median: " << takeMedian << endl << endl;
    
//***********************************************************************************
   
    int peopleM = 25, pizzaM = 0, slicesM = 0;
    double tot = 0;
    
    tot =  pizza(peopleM, &pizzaM, &slicesM);
    
    cout << "Testing pizza for 25 people:" << endl
    << "Epected result: 112.80 p: 9 s: 3"  << endl
    << fixed << setprecision(2) << "Actual results: " << tot
    << fixed << setprecision(0) << " p: " << pizzaM
    << " s: " << slicesM << endl << endl;

//***********************************************************************************

    return 0;
}
