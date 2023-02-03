//������Ϸ�ĳ���
#include "game.h"
#include <windows.h>
void menu()//�˵�����������˵�
{
	printf("\n");
	printf("***** 1. 1player *****\n");
	printf("***** 2. 2player *****\n");
	printf("***** 0.  exit   *****\n");

}

void oneplayer()//��Ϸ������������Ϸ�����������
{
	//�������������̵���Ϣ
	char board[ROW][COL] = {0};
	char win = 0;//����һ�������ж���Ϸ����
	InitBoard(board,ROW,COL);//��ʼ������,��Ϊc�����޷���������飬���������ɵ�ʱ��ض���ӡ���ַ���������Ҫ�����ַ���ʼ��Ϊ�ո�
	//��ʾ����
	DisplayBoard(board,ROW,COL);//����Ҫ��ӡ�������Լ��У���������
								//��ʱ������Ҫ��ӡ���̣������̵������Ϊ�����飬�����ӡ��һ�����ֳַ�������ͷָ����飨���һ�м����зָ��ߣ�
								//	 % | % | %   1-1
								//  ---|---|---  1-2
								//   % | % | %   2-1
								//  ---|---|---  2-2
								//	 % | % | %   3-1
								//               3-2			
	while (1)
	{
		//�����
		PlayeroneMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//����һ�����ӣ���ӡһ������
		//����һ������һ������Ҫ�ж�һ���Ƿ���һ��ʤ��
		win = IsWin(board, ROW, COL);//��win������IsWin���ص�ֵ
		if (win != 'c')//��win��'c'ʱ����ʾ��Ϸû�н������������壬��win������ֵʱ������ѭ��
		{
			break;
		}
		//������
		Sleep(1000);//�ӳٵ���������ٶȣ���λms
		AiMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//����һ�����ӣ���ӡһ������
		win =IsWin(board, ROW, COL);//��win������IsWin���ص�ֵ
		if (win != 'c')//��win��'c'ʱ����ʾ��Ϸû�н������������壬��win������ֵʱ������ѭ��
		{
			break;
		}
	}
	
	if (win == '*')
	{
		printf("��һ��ʤ��\n");
	}
	else if (win == '#')
	{
		printf("���Ի��ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}

void twoplayer()//��Ϸ������������Ϸ�����������
{
	//�������������̵���Ϣ
	char board[ROW][COL] = { 0 };
	char win = 0;//����һ�������ж���Ϸ����
	InitBoard(board, ROW, COL);//��ʼ������
	//��ʾ����
	DisplayBoard(board, ROW, COL);//����Ҫ��ӡ�������Լ��У���������
			
	while (1)
	{
		//�����
		PlayeroneMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//����һ�����ӣ���ӡһ������
		//����һ������һ������Ҫ�ж�һ���Ƿ���һ��ʤ��
		win = IsWin(board, ROW, COL);//��win������IsWin���ص�ֵ
		if (win != 'c')//��win��'c'ʱ����ʾ��Ϸû�н������������壬��win������ֵʱ������ѭ��
		{
			break;
		}
		//������
		PlayertwoMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//����һ�����ӣ���ӡһ������
		win = IsWin(board, ROW, COL);//��win������IsWin���ص�ֵ
		if (win != 'c')//��win��'c'ʱ����ʾ��Ϸû�н������������壬��win������ֵʱ������ѭ��
		{
			break;
		}
	}

	if (win == '*')
	{
		printf("���1���ʤ��\n");
	}
	else if (win == '#')
	{
		printf("���2���ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�ṩһ�������������
	do{
		menu();//�ṩ�˵�ѡ��
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				oneplayer();//��������Խ�����Ϸ
				break;
			case 2:
				twoplayer();//���֮�������Ϸ
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default :
				printf("�����������������1��0\n");
				break;
		}
	} while (input != 0);
}

int main()
{
	test();
	return 0;
}