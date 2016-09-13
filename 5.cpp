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
    double returnMedian = 0;
    int midPoint = 0, midPoint2 = 0;
    int *ptr = array;
    
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
    int totalSlices = people*3;
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
}

/******************************************************************
 resize: Takes an array, doubles its size and enters -1 for all
 new postions of the array
 int *arr = points at the array in main
 int size = passes the size of the orginal array from main
 returns: address of new array that is double the size of orginal
 ******************************************************************/

int *resize (int *arr, int size)
{  
    int index = 0;
    size = size * 2;
    int *reArray;
    
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
 shiftX: use dublicate array 3rd to last slide ch.9
 ******************************************************************/

int *shiftX (int *arr, int size)
{
    int *newArray;
    if (size <= 0) //size must be positive
        return NULL; //NULL is 0, an invalid address
    newArray = new int [size]; //allocate new array
    for (int index = 0; index < size; index++)
        newArray[index] = arr[index]; //copy to new array
    return newArray;
}

/******************************************************************
 subArray: use dublicate array 3rd to last slide ch.9
 ******************************************************************/

int *duplicateArray (int *arr, int size)
{
    int *newArray;
    if (size <= 0) //size must be positive
        return NULL; //NULL is 0, an invalid address
    newArray = new int [size]; //allocate new array
    for (int index = 0; index < size; index++)
        newArray[index] = arr[index]; //copy to new array
    return newArray;
}

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
    << "Actual median:   " << takeMedian << endl;
    
    takeMedian = median(arrayTwo, sizeTwo);
    
    cout  << "Test data: 1 2 3 4 5 6 7 8" << endl
    << "Expected median: 4.5" << endl
    << "Actual median:   " << takeMedian << endl << endl;
    
//***********************************************************************
    
    int peopleM = 25, pizzaM = 0, slicesM = 0;
    double tot = 0;
    
    tot =  pizza(peopleM, &pizzaM, &slicesM);
    
    cout << "Testing pizza for 25 people:" << endl
    << "Epected result: 112.80 p: 9 s: 3"  << endl
    << fixed << setprecision(2) << "Actual results: " << tot
    << fixed << setprecision(0) << " p: " << pizzaM
    << " s: " << slicesM << endl << endl;

//***********************************************************************
  
    int resizeArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, reaSize = 10, x = 0;
    int * ptr;
    ptr = resize(resizeArray, reaSize);    
    
    cout << "Testing resize:" << endl
    << "Test data: 1 2 3 4 5 6 7 8 9 0" << endl
    << "Expected results: 1 2 3 4 5 6 7 8 9 0 "
    << "-1 -1 -1 -1 -1 -1 -1 -1 -1 -1" << endl
    << "Actual result:    ";

    while (x < 20)
      {
       cout << ptr[x] << " ";
       x++;
       }
      cout << endl << endl;
  
//***********************************************************************
    
    return 0;
}
