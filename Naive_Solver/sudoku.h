#include<iostream>
#include<cstdlib>
#include <stdio.h>
//using namespace std;

//Constant Variables
#define UNASSIGNED 0
#define N 9

class Sudoku
{
	//imortant methods
private:
	/*---------------------------------------
   Basic methods associated with element
   type and geometry
  ---------------------------------------*/
	bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
	bool IsSafe(int grid[N][N], int row, int col, int num);
	bool SolveSudoku(int gird[N][N]);
	bool CheckRow(int gird[N][N], int row, int num);
	bool CheckCol(int grid[N][N], int col, int num);
	bool CheckBox(int grid[N][N], int boxStarRow, int boxStarCol, int num);
	void Printer(int grid[N][N]);

public:
	Sudoku();
	~Sudoku(){}



};

void Sudoku::Printer(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			printf("%d", grid[row][col]);
			printf(" ");

		}
		printf("\n");
	}


}


bool Sudoku::IsSafe(int grid[N][N], int row, int col, int num)
{
	/* Check to see if 'num' is already placed in the current row, current column, and current 3*3 square*/
	return	!CheckRow(grid, row, num) &&
		!CheckCol(grid, col, num) &&
		!CheckBox(grid, row - row % 3, col - col % 3, num);
}


bool Sudoku::CheckRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;

}


bool Sudoku::CheckCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;

}


bool Sudoku::CheckBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}


bool Sudoku::FindUnassignedLocation(int grid[N][N], int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

//note the following is a recursive function

bool Sudoku::SolveSudoku(int grid[N][N])
{
	int row, col;
	if (!FindUnassignedLocation(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (IsSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}


//Defining the constructor

Sudoku::Sudoku()
{
	int grid[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//
			std::cin >> grid[i][j];
		}
	}

	if (SolveSudoku(grid) == true)
	{
		std::cout << "\n\n";
		Printer(grid);
	}
	else {
		printf("No Solution Exists.");

	}
}
