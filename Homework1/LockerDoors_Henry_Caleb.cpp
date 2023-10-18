/**
 * @file LockerDoors_Henry_Caleb.cpp
 * @author Caleb Henry
 * @brief This program passes over a collection of n lockers r times. For each pass i every ith locker is opened if it 
 * is closed or closed if it is opened. All lockers start off closed. n and r are passed in through the terminal
 * @version 1.0
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

void openDoors(int n, int r);
int toggle(int num);

int main(int argc, char *argv[]) {
  std::cout << "Enter the total number of lockers: ";
  int n;
  std::cin >> n;
  std::cout << "Enter the total number of passes: ";
  int r;
  std::cin >> r;
  openDoors(n, r);
}

/**
 * @brief This program passes over a collection of n lockers r times. For each pass i every ith locker is opened if it 
 * is closed or closed if it is opened. All lockers start off closed.
 * 
 * @param n The number of lockers
 * @param r The number of passes
 */
void openDoors(int n, int r) {
  int arr[n] = {};
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < n; j++) {
      if ((j + 1) % (i + 1) == 0) {
        arr[j] = toggle(arr[j]);
      }
    }
  }
  int numOpen = 0;
  for (int i = 0; i < n; i++) {
    std::cout << "Locker number: " << i + 1 << "  Status: ";
    if (arr[i] == 0) {
      std::cout << "closed" << std::endl;
    } else {
      numOpen++;
      std::cout << "open" << std::endl;
    }
  }
  std::cout << "The total number of open lockers is " << numOpen << std::endl;
}

/**
 * @brief Toggles an integer between 0 and 1
 * 
 * @param num The number being toggled
 * @return int The number after being toggled
 */
int toggle(int num) {
  if (num == 0) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}
