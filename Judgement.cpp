#include"Judgement.h"


JUDGE::JUDGE()
{
}

JUDGE::~JUDGE()
{
}


int JUDGE::decide(BOARD* board) {
	//�жϵ�ǰ�����������û��ʤ�֣���ǰ����λ����BOARD�����д洢
	//ʤ��ֻ�ܳ����ڵ�ǰ����λ��ΪԲ�ĵİ뾶Ϊ4��Բ������
	//������ǰ���ܱߣ���ͬһ���ߵ��������ߵ�һ���͵�ǰ�����Ӳ�ͬ��λ�ã������ȵ���5����Ӯ
	//����ֵ0��������1:ֹͣ
	int vertical = 1;	//��ֱ����
	int level = 1;	//ˮƽ����
	int diagonal = 1;	//���Խ��߷���
	int sDiagonal = 1;//���Խ��߷���
	int m = board->nativeCoor.x;
	int n = board->nativeCoor.y;
	int side = board->nativeCoor.side;
	for (int i = 1; i <= 4; i++) //��
	{
		if (board->chessBoard[m - i][n] == side && m - i >=0)
			//��ǰm,n�϶�����Խ�磬����Ҫ�޶���������Խ��
			vertical++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //��
	{
		if (board->chessBoard[m + i][n] == side && m + i < MAX_ROW)
			vertical++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //��
	{
		if (board->chessBoard[m][n - i] == side && n - i >= 0)
			level++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //��
	{
		if (board->chessBoard[m][n + i] == side && n + i < MAX_COL)
			level++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //����
	{
		if (board->chessBoard[m + i][n - i] == side && n - i >= 0 && m + i < MAX_ROW)
			diagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //����
	{
		if (board->chessBoard[m - i][n + i] == side && m - i >= 0 && n + i < MAX_COL)
			diagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //����
	{
		if (board->chessBoard[m + i][n + i] == side && m + i < MAX_ROW && n + i < MAX_COL)
			sDiagonal++;
		else
			break;
	}
	for (int i = 1; i <= 4; i++) //����
	{
		if (board->chessBoard[m - i][n - i] == side && m - i >= 0 && n - i >= 0)
			sDiagonal++;
		else
			break;
	}
	if (vertical == 5 || level == 5 || diagonal == 5 || sDiagonal == 5)
	{
		if (side == 1)
		{
			cout << "��ҡ�ʤ������" << endl;
			return 1;
		}
		else
		{
			cout << "��ҡ�ʤ������" << endl;
			return 1;
		}
	}
	//��û����Ӯ������£����û�еط������ӣ���ƽ��
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			//���ӿ��䣬����0����ʾ����
			if (board->chessBoard[i][j] == 0)
			{
				return 0;
			}
		}		
	}
	//���ӿ��䣬ƽ�֣�����3
	cout << "���ӿ��䣬ƽ�֣�����" << endl;
	return 1;
}