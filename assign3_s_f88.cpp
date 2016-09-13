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
    double returnMedian = 0;         //variable to hold found median
    int midPoint = 0, midPoint2 = 0; //holds median, both if needed
    int *ptr = array;                //pointer to array
    
    if (size % 2 != 0)
        returnMedian = *(ptr + (size / 2));
    else
    {
        midPoint = size/2;
        midPoint2 = midPoint - 1;
        returnMedian = (*(ptr+midPoint) + *(ptr+midPoint2)) / 2.0;
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
    int totalSlices = people*3;       //hold total amount of slices
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
}

/******************************************************************
 resize: Takes an array, creates a new one doubled its size and
 enters -1 for all new postions of the array at the end
 int *arr = points at the array in main
 int size = passes the size of the orginal array from main
 returns: address of new array that is double the size of orginal
 ******************************************************************/

int *resize (int *arr, int size)
{
    int index = 0;                   //counter
    size = size * 2;
    int *reArray;                    //pointer to array
    
    if (size <= 0)
        return NULL;
    
    reArray = new int [size*2];
    while (index < (size/2))
    {
        reArray[index] = arr[index];
        index++;
    }
    
    while (index < size)
    {
        reArray[index] = -1;
        index++;
    }
    
    return reArray;
}

/******************************************************************
 shiftX: Takes an array, creates a new one (orginal size plus x)
 enters -1 for all new postions of the array at the begining
 int *arr = points at the array in main
 int size = passes the size of the orginal array from main
 int x = desired size change of array
 returns: address of new array
 ******************************************************************/

int *shiftX (int *arr, int size, int x)
{
    int index = 0, count = 0;         //counters
    int *reArray;                     //pointer to array
    
    if (size <= 0)
        return NULL;
    
    reArray = new int [size+x];
    
    while (index < x)
    {
        reArray[index] = -1;
        index++;
    }
    
    while (index < (size+x))
    {
        reArray[index] = arr[count];
        index++;
        count++;
    }
    
    return reArray;
}

/******************************************************************
 duplicateArray: duplicates array given with size
 subArray: Takes an array, creates a new one with only desired
 part of the orginal array
 int *arr = points at the array in main
 int size = passes the size of the orginal array from main
 int *array = points at the array in main
 int start = starting postion in the array desired
 int length = the amount of desired to be displayed after start
 returns: address of new array
 ******************************************************************/

int *duplicateArray (int *arr, int size)
{
    int *newArray;                    //pointer to array
    if (size <= 0)
        return NULL;
    newArray = new int [size];
    for (int index = 0; index < size; index++)
        newArray[index] = arr[index];
    return newArray;
}

int *subArray (int *array, int start, int length)
{
    int *result = duplicateArray((array+start), length);
    return result;
}

/******************************************************************
 main: calls functions to be tested in main with hard coded
 agurments
 returns: 0
 ******************************************************************/

int main()
{
    
    int sizeOne = 9, arrayOne[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                                //size and array to be tested
    int sizeTwo = 8, arrayTwo[] = {1, 2, 3, 4, 5, 6, 7, 8};
                                //size and array to be tested
    double takeMedian = 0;
                                //median to be passed back
    
    takeMedian = median(arrayOne, sizeOne);
    
    cout << endl << "Testing median:" << endl
    << "Test data: 1 2 3 4 5 6 7 8 9" << endl
    << "Expected median: 5" << endl
    << "Actual median:   " << takeMedian << endl;
    
    takeMedian = median(arrayTwo, sizeTwo);
    
    cout << "Test data: 1 2 3 4 5 6 7 8" << endl
    << "Expected median: 4.5" << endl
    << "Actual median:   " << takeMedian << endl << endl;
    
//****************************************************************************
    
    int peopleM = 25, pizzaM = 0, slicesM = 0;
    //amount of people, variable for amount of pizza/slices
    double tot = 0;
    //total price
    
    tot =  pizza(peopleM, &pizzaM, &slicesM);
    
    cout << "Testing pizza for 25 people:" << endl
    << "Epected results: 112.80 p: 9 s: 3"  << endl
    << fixed << setprecision(2) << "Actual results:  " << tot
    << fixed << setprecision(0) << " p: " << pizzaM
    << " s: " << slicesM << endl << endl;
    
//****************************************************************************
    
    int resizeArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, reaSize = 10, x = 0;
    //size and array to be tested, and counter
    int * ptr;
    //pointer to array
    
    ptr = resize(resizeArray, reaSize);
    
    cout << "Testing resize:" << endl
    << "Test data: 1 2 3 4 5 6 7 8 9 0" << endl
    << "Expected results:  1 2 3 4 5 6 7 8 9 0 "
    << "-1 -1 -1 -1 -1 -1 -1 -1 -1 -1" << endl
    << "Actual results:    ";
    
    while (x < 20)
    {
        cout << ptr[x] << " ";
        x++;
    }
    cout << endl << endl;
    
//****************************************************************************
    
    int shiftArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; //array to be tested
    int shiftSize = 10, change = 4,  y = 0;            //size and to be tested
    int * shiftPtr;                                    //pointer to array
    
    shiftPtr = shiftX(shiftArray, shiftSize, change);
    
    cout << "Testing shiftX:" << endl
    << "Test data: 1 2 3 4 5 6 7 8 9 0" << endl
    << "Shift: 4" << endl
    << "Expected results: -1 -1 -1 -1 1 2 3 4 5 6 7 8 9 0" << endl
    << "Actual results:   ";
    
    while (y < (shiftSize + change))
    {
        cout << shiftPtr[y] << " ";
        y++;
    }
    
    cout << endl << endl;
    
//****************************************************************************
    
    int subArrayM[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //array to be tested
    int subSize = 10, start = 5,  length = 4, z = 0;
    //size to be tested, start point, number to output
    int * subPtr;
    //pointer to array
    
    subPtr = subArray(subArrayM, start, length);
    
    cout << "Testing subArray:" << endl
    << "Test data: 1 2 3 4 5 6 7 8 9 0" << endl
    << "Start: 5 Length: 4" << endl
    << "Expected result: 6 7 8 9" << endl
    << "Actual result:   ";
    
    while (z < (length))
    {
        cout << subPtr[z] << " ";
        z++;
    }
    
    cout << endl << endl;
    
//****************************************************************************
    
    return 0;
}
