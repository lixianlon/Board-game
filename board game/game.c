#include "game.h"
//�����Ķ���
//��Ϸ���������
void InitBoard(char board[ROW][COL], int row, int col)//��ʼ�����̺�����������ĳ�ʼֵ��Ϊ���ַ�
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

void DisplayBoard(char board[ROW][COL], int row, int col)//��ʾ���̺�������ӡ����
{
	//�����ӡ
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//��ӡ��i��
	{
		for (j = 0; j < col; j++)//��ӡi-1
		{
			printf(" %c ", board[i][j]);//��ӡ���崦
			if (j < col - 1)//ɸѡ����j�������һ��ʱ(3-1=2,��[2]������������һ��Ԫ��)��������ӡ|
			{
				printf("|");//��ӡ�ָ�
			}
		}
		printf("\n");
		for (j = 0; j < row; j++)//��ӡi-2
		{
			//����˫��ɸѡ�����ж�i�Ƿ�ﵽ���һ�У����ж�j�Ƿ����һ��
			if (i < row - 1)//ɸѡ����i�������һ��ʱ��������ӡ---
			{
				printf("---");//��ӡ�ָ�
				if (j < col - 1)//ɸѡ����j�������һ��ʱ��������ӡ|
				{
					printf("|");//��ӡ�ָ�
				}
			}
		}

		printf("\n");
	}
}

void PlayeroneMove(char board[ROW][COL], int row, int col)//������庯��
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("���1��������������:");
		scanf("%d%d", &x, &y);
		if (x>0 && x <= row  && y>0 && y <= col)//��֤���巶Χ��������
		{
			if (board[x - 1][y - 1] == ' ')//x��y�����������֪�е�λ�����꣬��x-1��y-1�����Ӧ���±�λ�ã���֤���崦û������
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������������ӣ�����������\n");
			}
		}
		else
		{
			printf("�������������������������\n");
		}
	}
	printf("���1��\n");
}

void PlayertwoMove(char board[ROW][COL], int row, int col)//������庯��
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("���2��������������:");
		scanf("%d%d", &x, &y);
		if (x>0 && x <= row  && y>0 && y <= col)//��֤���巶Χ��������
		{
			if (board[x - 1][y - 1] == ' ')//x��y�����������֪�е�λ�����꣬��x-1��y-1�����Ӧ���±�λ�ã���֤���崦û������
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("�������������ӣ�����������\n");
			}
		}
		else
		{
			printf("�������������������������\n");
		}
	}
	printf("���2��\n");
}

void AiMove(char board[ROW][COL], int row, int col)//�������庯�������rand()ʵ�ֵ����������
{
	int x = 0;
	int y = 0;
	printf("������\n");
	while (1)//��ΪҪ�ų����崦�����ӵ�������������ｨ��һ��ѭ���������崦�������ӣ������������µ�x��y����
	{
		x = rand() % row;//rand�������ֵΪ0-rand_max,����Ҫ�����ķ�Χ����0-2������ģ��row(3)
		y = rand() % col;//������ɵ�������겻������Ƿ����꣬�����Ͳ����жϵ�������᲻�ᳬ����Χ��
		//��Ϊ�ǵ������壬���Բ����ٿ���һ����Ҳ��������±��0��ʼ�����
		//�������ﲻ��������x-1��y-1���±꣬ͬʱ82��83�д��붨����x��y��0-2���±귶Χ����֤���岻�������̷�Χ
		if (board[x][y] == ' ')//���崦û������
		{
			board[x][y] = '#';
			break;
		}
	}
}
//����IsFull�����ж������Ƿ��Ѿ������ˣ�������˷���1�����û������0
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

char IsWin(char board[ROW][COL], int row, int col)//�ж�ʤ��������������������жϾ���
{
	//�ж���������Ϸ�����1.���Ӯ 2.����Ӯ 3.ƽ�� 4.δ��ʤ�������Ծ�
	//Ӯ�������������һ���Ǻ�����ͬ�ӣ�һ����������ͬ�ӣ�һ���ǶԽ���ͬ��
	//�����⼸�������������Ӯ��һ�������������ֵ��ƽ�ַ���'p'��δ��ʤ������'c'
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];	//����һ��ʤ��������·����������ֵ���Ż��ж����̣��������һ�������ֵ����Ҫ�ٽ���һ���ж���������һ��ʤ������·��ص�ֵ
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//����һ��ʤ��������·����������ֵ���Ż��ж�����
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];

	if (IsFull(board,row,col) == 1)//��IsFull����=1��ʱ�򣬱�ʾ�����Ѿ�������
	{
		return 'p';
	}
	return 'c';//���������û�з���������'c'
}