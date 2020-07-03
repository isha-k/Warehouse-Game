/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Include your information here - name, user name, ID number >> */

#include "project.h"

/*
The purpose of this function is to calculate the number of seconds a staff member has worked for their
shift at the Warehouse. This task was solved by converting the minutes of each clock in/clock out to 
seconds and then adding that to the number of seconds for each clock in/clock out respectively.
The absolute difference between these two values was then taken and returned. 
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB, timeWorked;

	timeA = minuteA * 60 + secondA;
	timeB = minuteB * 60 + secondB;

	if ((timeA - timeB) < 0) {
		timeWorked = (timeA - timeB) * -1;
	}
	else {
		timeWorked = timeA - timeB;
	}

	return timeWorked;
}

/*
The purpose of this function is to return the first occurence of the prime number which is lower 
than the number specified. We assume that the input number will be a positive integer greater than 2.
This task was solved by using a nested loop to determine whether each number below the specified
number had a remainder of 0. If it did, that meant it was not a prime and the loop continued to the
next number down until a prime was found. If no primes found above 2 then the function returns 2.
*/
int WarehouseAddress(int maximum)
{
	int i, j, toFind;
	int number = 2;


	for (i = maximum - 1; i > 2; i--) {
		for (j = 2; j < i; j++) {
			if (i % j != 0) {
				toFind = 1;
			}
			else if (i % j == 0) {
				toFind = -1;
				break;

			}
		}
		if (toFind == 1) {
			number = i;
			return number;
		} 
	}
	return number;

}

/*
The function of this task is to 'rotate' the characters. This was accomplished by storing the first
character in the string in a temporary variable and looping through string and replacing each character 
with the character following it. After this was done, the last character was replaced with the first 
character i.e. the one stored in the temporary variable. 
*/
void Advertise(char* words)
{
	int temp = words[0];
	int i = 0;

	while (words[i + 1] != '\0') {
		words[i] = words[i + 1];
		i++;
	}

	words[i] = temp;
	
}

/*
This function determines the lowest unique bid submitted by a person at an auction. This function
works by firstly finding the smallest and largest bid value that was submitted. This defines the 
parameters. It then finds how many times the numbers from smallest to biggest(inclusive) appear
in the bid array. If the value appears in the array 1 is added to count. If the value only appears once
it is returned. If there is no unique bid value, -1 is returned.
*/
int WinningBid(int *values, int length)
{
	int smallestVal, largestVal, i, j, num;
	int count = 0;

	smallestVal = values[0];
	largestVal = values[0];
	for (i = 1; i < length; i++) {
		if (values[i] < smallestVal) {
			smallestVal = values[i];
		}
		if (values[i] > largestVal) {
			largestVal = values[i];
		}
	}

	num = smallestVal;
	while (num < largestVal + 1) {
		for (j = 0; j < length; j++) {
			if (values[j] == num) {
				count++;
			}
		}
		if (count == 1) {
			return num;
		}
		else {
			count = 0;
			num++;
		}
	}
	return -1;
}

/*
The purpose of this function is to produce a string which displays a mock-up representation of the centre
of a given box (marked with an X). The exact centre of a given box is found by determining which 
conditions the length and width of the box fulfills. This code works by checking whether the width and 
length of each box is odd or even. Depending on this, the function prints the box and the X character, 
which denotes the box's centre point.
*/

void BoxDesign(char* design, int width, int height)
{
	int i, pos1, pos2, index, midIndex;
	int length = (width + 1) * height;

	for (index = 0; index < length; index += width + 1) {
		for (i = index; i < width + index + 1; i++) {
			if (i < width || (i == index + width - 1) || (i == index) || (index == width * (height - 1) + (height - 1) && i != (width + 1) * height - 1)) {
				design[i] = '*';
			}
			else if (i == index + width) {
				design[i] = '\n';
			}
			else {
				design[i] = ' ';
			}
		}
	}
	if (width > 2 && height > 2) {
		if (width % 2 == 1 && height % 2 == 1) {
			pos1 = length / 2 - 1;
			design[pos1] = 'X';
		}
		else if (width % 2 == 0 && height % 2 == 0) {
			pos1 = width * (height / 2);
			pos2 = length / 2 + width / 2;
			design[pos1 - 1] = 'X';
			design[pos1 - 2] = 'X';
			design[pos2] = 'X';
			design[pos2 - 1] = 'X';
		}
		else if (width % 2 == 0 && height % 2 == 1) {
			pos1 = (length - 1) / 2;
			design[pos1] = 'X';
			design[pos1 - 1] = 'X';
		}
		else if (width % 2 == 1 && height % 2 == 0) {
			pos1 = ((length - (width + 1))/2) - 1;
			pos2 = pos1 + (width + 1);
			design[pos1] = 'X';
			design[pos2] = 'X';
		}
	}
}
	

/*
The purpose of this function is to calculate a direct route from a worker to a box given the position of 
the worker and the position of the box. This function works by calling a helper function to find the position
of the worker and box in the 2D array. It then creates a direct route from the worker to the box by 'moving'
the worker first horizontally and then vertically. The movement of the worker is symbolised using the 
integer, 3. 
*/
void FindNum(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int number, int* rowPos, int* colPos);
void WorkerRoute(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE])
{
	int i, j;
	int workerRow, workerCol, boxRow, boxCol;

	FindNum(warehouse, 1, &workerRow, &workerCol);
	FindNum(warehouse, 2, &boxRow, &boxCol);

	if (workerCol == boxCol) {
		if (boxRow > workerRow) {
			for (i = workerRow + 1; i < boxRow; i++) {
				warehouse[i][workerCol] = 3;
			}
		}
		else {
			for (i = boxRow + 1; i < workerRow; i++) {
				warehouse[i][workerCol] = 3;
			}
		}
	}
	else if (workerRow == boxRow) {
		if (boxCol > workerCol) {
			for (i = workerCol + 1; i < boxCol; i++) {
				warehouse[workerRow][i] = 3;
			}
		}
		else {
			for (i = boxCol + 1; i < workerCol; i++) {
				warehouse[workerRow][i] = 3;
			}
		}
	}
	else {
		if (boxCol < workerCol) {
			for (i = boxCol; i < workerCol; i++) {
				warehouse[workerRow][i] = 3;
			}
		}
		else {
			for (i = boxCol; i > workerCol; i--) {
				warehouse[workerRow][i] = 3;
			}
		}
		if (boxRow < workerRow) {
			for (j = boxRow + 1; j < workerRow; j++) {
				warehouse[j][boxCol] = 3;
			}
		}
		else {
			for (j = boxRow - 1; j > workerRow; j--) {
				warehouse[j][boxCol] = 3;
			}
		}

	}
}
void FindNum(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int number, int* rowPos, int* colPos)
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == number) {
				*rowPos = i;
				*colPos = j;
			}
		}
	}
}

/*
The purpose of this function is to control the workers remotely given a move character. Each given character
corresponds to a movement either up, down, left, or right. The function first checks if the move is valid
by checking that the space the worker, represented by the integer 5, is moving to is empty, i.e. is 0 in the
array. If it is, then the move is carried out, else the user is prompted to enter another move. 
*/

void FindVal(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int value, int* valRow, int* valCol);

int MakeMove(int warehouse[10][10], char move)
{
	int i, j, workerRow, workerCol, boxRow, boxCol, temp;
	FindVal(warehouse, WORKER, &workerRow, &workerCol);

	if (warehouse[workerRow][workerCol] == WORKER_ON_TARGET) {
		if (move == 'w') {
			if ((warehouse[workerRow - 1][workerCol]) == SPACE) {
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			if (warehouse[workerRow - 1][workerCol] == BOX && warehouse[workerRow - 2][workerCol] == SPACE) {
				warehouse[workerRow - 2][workerCol] = BOX;
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow - 1][workerCol] == TARGET) {
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow - 1][workerCol] == BOX && warehouse[workerRow - 2][workerCol] == TARGET) {
				warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;

			}
			else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow - 2][workerCol] == SPACE) {
				warehouse[workerRow - 2][workerCol] = BOX;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow - 2][workerCol] == TARGET) {
				warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
		}
		if (move == 's') {
			if ((warehouse[workerRow + 1][workerCol]) == SPACE) {
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			if (warehouse[workerRow + 1][workerCol] == BOX && warehouse[workerRow + 2][workerCol] == SPACE) {
				warehouse[workerRow + 2][workerCol] = BOX;
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow + 1][workerCol] == TARGET) {
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow + 1][workerCol] == BOX && warehouse[workerRow + 2][workerCol] == TARGET) {
				warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;

			}
			else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow + 2][workerCol] == SPACE) {
				warehouse[workerRow + 2][workerCol] = BOX;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow + 2][workerCol] == TARGET) {
				warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
		}
		if (move == 'a') {
			if ((warehouse[workerRow][workerCol - 1]) == SPACE) {
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			if (warehouse[workerRow][workerCol - 1] == BOX && warehouse[workerRow][workerCol - 2] == SPACE) {
				warehouse[workerRow][workerCol - 2] = BOX;
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol - 1] == TARGET) {
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol - 1] == BOX && warehouse[workerRow][workerCol - 2] == TARGET) {
				warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;

			}
			else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol - 2] == SPACE) {
				warehouse[workerRow][workerCol - 2] = BOX;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol - 2] == TARGET) {
				warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
		}
		if (move == 'd') {
			if ((warehouse[workerRow][workerCol + 1]) == SPACE) {
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			if (warehouse[workerRow][workerCol + 1] == BOX && warehouse[workerRow][workerCol + 2] == SPACE) {
				warehouse[workerRow][workerCol + 2] = BOX;
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol + 1] == TARGET) {
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol + 1] == BOX && warehouse[workerRow][workerCol + 2] == TARGET) {
				warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = TARGET;

			}
			else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol + 2] == SPACE) {
				warehouse[workerRow][workerCol + 2] = BOX;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
			else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol + 2] == TARGET) {
				warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = TARGET;
			}
		}
	}
	else if (warehouse[workerRow][workerCol] == WORKER) {
		if (move == 'w') {
			if ((warehouse[workerRow - 1][workerCol]) == SPACE) {
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			if (warehouse[workerRow - 1][workerCol] == BOX && warehouse[workerRow - 2][workerCol] == SPACE) {
				warehouse[workerRow - 2][workerCol] = BOX;
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow - 1][workerCol] == TARGET) {
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow - 1][workerCol] == BOX && warehouse[workerRow - 2][workerCol] == TARGET) {
				warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;

			}
			else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow - 2][workerCol] == SPACE) {
				warehouse[workerRow - 2][workerCol] = BOX;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow - 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow - 2][workerCol] == TARGET) {
				warehouse[workerRow - 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow - 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
		}
		if (move == 's') {
			if ((warehouse[workerRow + 1][workerCol]) == SPACE) {
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			if (warehouse[workerRow + 1][workerCol] == BOX && warehouse[workerRow + 2][workerCol] == SPACE) {
				warehouse[workerRow + 2][workerCol] = BOX;
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow + 1][workerCol] == TARGET) {
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow + 1][workerCol] == BOX && warehouse[workerRow + 2][workerCol] == TARGET) {
				warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;

			}
			else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow + 2][workerCol] == SPACE) {
				warehouse[workerRow + 2][workerCol] = BOX;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow + 1][workerCol] == BOX_ON_TARGET && warehouse[workerRow + 2][workerCol] == TARGET) {
				warehouse[workerRow + 2][workerCol] = BOX_ON_TARGET;
				warehouse[workerRow + 1][workerCol] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
		}
		if (move == 'a') {
			if ((warehouse[workerRow][workerCol - 1]) == SPACE) {
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			if (warehouse[workerRow][workerCol - 1] == BOX && warehouse[workerRow][workerCol - 2] == SPACE) {
				warehouse[workerRow][workerCol - 2] = BOX;
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol - 1] == TARGET) {
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol - 1] == BOX && warehouse[workerRow][workerCol - 2] == TARGET) {
				warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;

			}
			else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol - 2] == SPACE) {
				warehouse[workerRow][workerCol - 2] = BOX;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol - 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol - 2] == TARGET) {
				warehouse[workerRow][workerCol - 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol - 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
		}
		if (move == 'd') {
			if ((warehouse[workerRow][workerCol + 1]) == SPACE) {
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			if (warehouse[workerRow][workerCol + 1] == BOX && warehouse[workerRow][workerCol + 2] == SPACE) {
				warehouse[workerRow][workerCol + 2] = BOX;
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol + 1] == TARGET) {
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol + 1] == BOX && warehouse[workerRow][workerCol + 2] == TARGET) {
				warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER;
				warehouse[workerRow][workerCol] = SPACE;

			}
			else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol + 2] == SPACE) {
				warehouse[workerRow][workerCol + 2] = BOX;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
			else if (warehouse[workerRow][workerCol + 1] == BOX_ON_TARGET && warehouse[workerRow][workerCol + 2] == TARGET) {
				warehouse[workerRow][workerCol + 2] = BOX_ON_TARGET;
				warehouse[workerRow][workerCol + 1] = WORKER_ON_TARGET;
				warehouse[workerRow][workerCol] = SPACE;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 5 || warehouse[i][j] == 3) {
				return 0;
			}
		}
	}
	return 1;
}
void FindVal(int warehouse[WAREHOUSE_SIZE][WAREHOUSE_SIZE], int value, int* valRow, int* valCol)
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == value) {
				*valRow = i;
				*valCol = j;
			}
			else if (warehouse[i][j] == value + 1) {
				*valRow = i;
				*valCol = j;
			}
		}
	}
}