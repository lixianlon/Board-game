#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3//���������е���
#define COL 3//���������е���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayeroneMove(char board[ROW][COL], int row,int col);
void PlayertwoMove(char board[ROW][COL], int row, int col);

void AiMove(char board[ROW][COL], int row, int col);
//����һ��IsWin������ͨ�����ص��ַ��ж���Ϸ�Ľ��
char IsWin(char board[ROW][COL],int row,int col);