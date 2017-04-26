#include<iostream>
#define Unassigned 0
#define N 9
using namespace std;

bool isUnAssigned(int grid[N][N],int & row,int & col)
{

	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(grid[row][col]==Unassigned)
			{
				return true;
			}
		}
	}
	return false;
}

bool isinRow(int grid[N][N],int col,int num)
{

	for(int row=0;row<N;row++)
	{
		if(grid[row][col]==num)
			return true;
	}

	return false;

}

bool isinCol(int grid[N][N],int row,int num)
{

	for(int col=0;col<N;col++)
	{
		if(grid[row][col]==num)
			return true;
	}
	return false;
}

bool isinBox(int grid[N][N],int rowStart,int colStart,int num)
{
	for(int row=0;row<3;row++)
	{
		for(int col=0;col<3;col++)
		{

			if(grid[row+rowStart][col+colStart]==num)
				return true;
		}
	}
	return false;
}
bool issafe(int grid[N][N],int row,int col,int num)
{


	return !isinRow(grid,col,num) &&
	!isinCol(grid,row,num) && !isinBox(grid,row-row%3,col-col%3,num);

}

bool sudokusolve(int grid[N][N])
{

	int row;
	int col;

	if(!isUnAssigned(grid,row,col))
	{
		return true;
	}

	for(int i=1;i<=9;i++)
	{

		if(issafe(grid,row,col,i))
		{
			grid[row][col]=i;

			if(sudokusolve(grid))
				return true;

			grid[row][col]=Unassigned;
		}
	}
	return false;
}

void printSudoku(int grid[N][N])
{

	for(int i=0;i<N;i++)
	{

		for(int j=0;j<N;j++)
		{

			cout<<grid[i][j]<<" ";
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{

	int grid[N][N];



	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin>>grid[i][j];
		}

	sudokusolve(grid);
	printSudoku(grid);
	cout<<"\n";

	}
}
