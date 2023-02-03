#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3//声明棋盘中的行
#define COL 3//声明棋盘中的列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数的声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayeroneMove(char board[ROW][COL], int row,int col);
void PlayertwoMove(char board[ROW][COL], int row, int col);

void AiMove(char board[ROW][COL], int row, int col);
//建立一个IsWin函数，通过返回的字符判断游戏的结局
char IsWin(char board[ROW][COL],int row,int col);