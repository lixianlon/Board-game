#include "game.h"
//函数的定义
//游戏的内容设计
void InitBoard(char board[ROW][COL], int row, int col)//初始化棋盘函数，将数组的初始值变为空字符
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

void DisplayBoard(char board[ROW][COL], int row, int col)//显示棋盘函数，打印棋盘
{
	//分组打印
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//打印第i组
	{
		for (j = 0; j < col; j++)//打印i-1
		{
			printf(" %c ", board[i][j]);//打印落棋处
			if (j < col - 1)//筛选，当j到达最后一列时(3-1=2,而[2]是数组中最后的一个元素)，跳过打印|
			{
				printf("|");//打印分格
			}
		}
		printf("\n");
		for (j = 0; j < row; j++)//打印i-2
		{
			//建立双重筛选，先判断i是否达到最后一行，再判断j是否到最后一列
			if (i < row - 1)//筛选，当i到达最后一行时，跳过打印---
			{
				printf("---");//打印分格
				if (j < col - 1)//筛选，当j到达最后一列时，跳过打印|
				{
					printf("|");//打印分格
				}
			}
		}

		printf("\n");
	}
}

void PlayeroneMove(char board[ROW][COL], int row, int col)//玩家落棋函数
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家1请输入落棋坐标:");
		scanf("%d%d", &x, &y);
		if (x>0 && x <= row  && y>0 && y <= col)//保证落棋范围在棋盘内
		{
			if (board[x - 1][y - 1] == ' ')//x和y是正常玩家认知中的位置坐标，而x-1和y-1是其对应的下标位置，保证落棋处没有棋子
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已有棋子，请重新输入\n");
			}
		}
		else
		{
			printf("你输入的坐标有误，请重新输入\n");
		}
	}
	printf("玩家1走\n");
}

void PlayertwoMove(char board[ROW][COL], int row, int col)//玩家落棋函数
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家2请输入落棋坐标:");
		scanf("%d%d", &x, &y);
		if (x>0 && x <= row  && y>0 && y <= col)//保证落棋范围在棋盘内
		{
			if (board[x - 1][y - 1] == ' ')//x和y是正常玩家认知中的位置坐标，而x-1和y-1是其对应的下标位置，保证落棋处没有棋子
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标已有棋子，请重新输入\n");
			}
		}
		else
		{
			printf("你输入的坐标有误，请重新输入\n");
		}
	}
	printf("玩家2走\n");
}

void AiMove(char board[ROW][COL], int row, int col)//电脑落棋函数，配合rand()实现电脑随机下棋
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while (1)//因为要排除落棋处有棋子的情况，所以这里建立一个循环，当落棋处已有棋子，将重新生成新的x，y坐标
	{
		x = rand() % row;//rand函数最大值为0-rand_max,这里要把数的范围定在0-2，所以模以row(3)
		y = rand() % col;//因此生成的随机坐标不会产生非法坐标，这样就不用判断电脑坐标会不会超出范围了
		//因为是电脑下棋，所以不用再考虑一般玩家不懂数组下标从0开始的情况
		//所以这里不用再运用x-1和y-1的下标，同时82和83行代码定好了x和y再0-2的下标范围，保证落棋不超出棋盘范围
		if (board[x][y] == ' ')//落棋处没有棋子
		{
			board[x][y] = '#';
			break;
		}
	}
}
//建立IsFull函数判断棋盘是否已经下满了，如果满了返回1，如果没满返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)//判断胜负函数，可用于落棋后判断局势
{
	//判断有四种游戏情况，1.玩家赢 2.电脑赢 3.平局 4.未分胜负继续对局
	//赢又有三种情况，一种是横三行同子，一种是竖三行同子，一种是对角线同子
	//对于这几种情况，我们让赢的一方返回它本身的值，平局返回'p'，未分胜负返回'c'
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];	//在有一方胜利的情况下返回它本身的值，优化判断流程，如果返回一个具体的值，又要再建立一个判断来返回另一方胜利情况下返回的值
		}
	}
	//竖三行
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//在有一方胜利的情况下返回它本身的值，优化判断流程
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	if (IsFull(board,row,col) == 1)//当IsFull函数=1的时候，表示棋盘已经下满了
	{
		return 'p';
	}
	return 'c';//上述情况都没有发生，返回'c'
}