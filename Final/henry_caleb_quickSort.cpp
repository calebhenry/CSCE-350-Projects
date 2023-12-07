/**
 * @file Henry_Caleb_QuickSort.cpp
 * @author Caleb Henry
 * @brief Quicksorts the numbers in a file and puts the execution time and sorted list into output files
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

void quickSort(int arr[], int begin, int end);
int partition(int arr[], int begin, int end);
int medianIndex(int arr[], int begin, int end);

int main(int argc, char *argv[]) {
    //Open file and count number of numbers
    std::ifstream inputFile(argv[1]);
    int size = 0;
    int num;
    while (inputFile >> num) {
        size++;
    }
    inputFile.close();
    //Initialize array
    int arr[size];
    //Populate array with file
    inputFile.open(argv[1]);
    int index = 0;
    while (inputFile >> num) {
        arr[index++] = num;
    }
    inputFile.close();
    //Sort array and time it
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, size);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = stop - start;
    //Populate out file
    std::ofstream outputFile(argv[2]);
    outputFile.clear();
    for (int i : arr) {
        outputFile << i << " ";
    }
    outputFile.close();
    std::ofstream timeFile("henry_caleb_executionTime.txt");
    timeFile << size << "    " << duration.count();
    timeFile.close();
}

/**
 * @brief Sorts an array
 * 
 * @param arr The array to be sorted
 * @param begin The first index of the array
 * @param end The last index of the array
 */
void quickSort(int arr[], int begin, int end) {
    if(begin < end) {
        int s = partition(arr, begin, end);
        quickSort(arr, begin, s-1);
        quickSort(arr, s+1, end);
    } else {
        return;
    }
}

/**
 * @brief Picks a partition using the median of three method, then 
 * rearranges the array to be on the correct sides of the partition
 * 
 * @param arr The array to be partitioned
 * @param begin The beginning of the array
 * @param end The end of the array
 * @return int The partition
 */
int partition(int arr[], int begin, int end) {
    int medIndex = medianIndex(arr, begin, end);
    int temp = arr[medIndex];
    arr[medIndex] = arr[begin];
    arr[begin] = temp;
    int pivot = arr[begin];
    int i = begin;
    int j = end + 1;
    while (i < j) {
        do {
            i++;
        } while (arr[i] < pivot && i <= end);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[begin];
    arr[begin] = arr[j];
    arr[j] = temp;
    return j;
}

/**
 * @brief Find the index of the median of the beginning, middle, and end of an array
 * 
 * @param arr The array that is being parsed
 * @param l The start of the array
 * @param r The end of the array
 * @return int The median index of the array
 */
int medianIndex(int arr[], int l, int r) {
    int begin = arr[l], middle = arr[r-l/2], end = arr[r];

    if ((begin >= middle && begin <= end) || (begin >= end && begin <= middle)) {
        return l;
    } else if ((middle >= begin && middle <= end) || (middle >= end && middle <= begin)) {
        return r-l/2;
    } else {
        return r;
    }
}