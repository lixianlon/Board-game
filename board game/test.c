//测试游戏的程序
#include "game.h"
#include <windows.h>
void menu()//菜单函数，定义菜单
{
	printf("\n");
	printf("***** 1. 1player *****\n");
	printf("***** 2. 2player *****\n");
	printf("***** 0.  exit   *****\n");

}

void oneplayer()//游戏函数，定义游戏程序如何运行
{
	//建立数组存放棋盘的信息
	char board[ROW][COL] = {0};
	char win = 0;//定义一个数来判断游戏进程
	InitBoard(board,ROW,COL);//初始化棋盘,因为c语言无法定义空数组，当棋盘生成的时候必定打印有字符，所以需要将该字符初始化为空格
	//显示棋盘
	DisplayBoard(board,ROW,COL);//将需要打印的数组以及行，列数传参
								//此时我们需要打印棋盘，将棋盘的整体分为三个组，分组打印，一个组又分成内容组和分割线组（最后一行假设有分割线）
								//	 % | % | %   1-1
								//  ---|---|---  1-2
								//   % | % | %   2-1
								//  ---|---|---  2-2
								//	 % | % | %   3-1
								//               3-2			
	while (1)
	{
		//玩家走
		PlayeroneMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//当有一方落子，打印一次棋盘
		//当有一方走完一步，需要判断一下是否有一方胜出
		win = IsWin(board, ROW, COL);//用win来接收IsWin返回的值
		if (win != 'c')//当win是'c'时，表示游戏没有结束，继续下棋，当win是其他值时，跳出循环
		{
			break;
		}
		//电脑走
		Sleep(1000);//延迟电脑下棋的速度，单位ms
		AiMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//当有一方落子，打印一次棋盘
		win =IsWin(board, ROW, COL);//用win来接收IsWin返回的值
		if (win != 'c')//当win是'c'时，表示游戏没有结束，继续下棋，当win是其他值时，跳出循环
		{
			break;
		}
	}
	
	if (win == '*')
	{
		printf("玩家获得胜利\n");
	}
	else if (win == '#')
	{
		printf("电脑获得胜利\n");
	}
	else
	{
		printf("平局\n");
	}

}

void twoplayer()//游戏函数，定义游戏程序如何运行
{
	//建立数组存放棋盘的信息
	char board[ROW][COL] = { 0 };
	char win = 0;//定义一个数来判断游戏进程
	InitBoard(board, ROW, COL);//初始化棋盘
	//显示棋盘
	DisplayBoard(board, ROW, COL);//将需要打印的数组以及行，列数传参
			
	while (1)
	{
		//玩家走
		PlayeroneMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//当有一方落子，打印一次棋盘
		//当有一方走完一步，需要判断一下是否有一方胜出
		win = IsWin(board, ROW, COL);//用win来接收IsWin返回的值
		if (win != 'c')//当win是'c'时，表示游戏没有结束，继续下棋，当win是其他值时，跳出循环
		{
			break;
		}
		//电脑走
		PlayertwoMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//当有一方落子，打印一次棋盘
		win = IsWin(board, ROW, COL);//用win来接收IsWin返回的值
		if (win != 'c')//当win是'c'时，表示游戏没有结束，继续下棋，当win是其他值时，跳出循环
		{
			break;
		}
	}

	if (win == '*')
	{
		printf("玩家1获得胜利\n");
	}
	else if (win == '#')
	{
		printf("玩家2获得胜利\n");
	}
	else
	{
		printf("平局\n");
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//提供一个真正的随机数
	do{
		menu();//提供菜单选择
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				oneplayer();//单人与电脑进行游戏
				break;
			case 2:
				twoplayer();//玩家之间进行游戏
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default :
				printf("你的输入有误，请输入1或0\n");
				break;
		}
	} while (input != 0);
}

int main()
{
	test();
	return 0;
}