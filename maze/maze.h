
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "base.h"
#define N 10
typedef struct{
	int m;
	int n;
	char arr[N][N];
}MazeType;//迷宫各位置取'@','#',' ','*'
void InitMaze(MazeType&maze, int a[][4], int row, int col){
	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++){
			if (i>0 && i<row + 1 && j>0 && j<col + 1){
				if (a[i][j] == 1)maze.arr[i][j] = ' ';
				else maze.arr[i][j] = '*';
			}
			else maze.arr[i][j] = '#';
		}
	}
	maze.m = 0;
	maze.n = 0;
	
}
bool Pass(MazeType maze, PosType curpos){
	if (maze.arr[curpos.r][curpos.c] == '#')return false;
	else return true;
}
PosType Nextpos(PosType seat, directiveType di){
	
}
bool MazePath(MazeType&maze, PosType start, PosType end){
	
}
void PrintMaze(MazeType maze);
