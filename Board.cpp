# include"Board.h"

BOARD::BOARD()
//���캯������ʼ��ֵ
{
	//���ӺͰ��Ӹ���������
	blacks = 0;
	whites = 0;
	//����������м�
	nativeCur.oldX = MAX_ROW / 2;
	nativeCur.oldY = MAX_COL / 2;
	nativeCur.newX = MAX_ROW / 2;
	nativeCur.newY = MAX_COL / 2;
	//��ǰ���ӳ�ʼΪ�����м�
	nativeCoor.x = MAX_ROW / 2;
	nativeCoor.y = MAX_COL / 2;
	nativeCoor.side = 0;
	//��ʼ�����̺͹����
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			chessBoard[i][j] = 0;	//�ÿ�
			cursor[i][j] = 0;	//�ÿ�
		}
	}
	//��ʾ���
	cursor[nativeCur.newX][nativeCur.newY] = 1;
}

BOARD::~BOARD()
{
}

int BOARD::add(COORDINATE coor)
//��coor��ӵ�������
{
	//��������λ��
	nativeCoor = coor;
	//����ս����ӵ���Ӧ��vector�������³���(�����������ֹ���)
	if (coor.side == 1)
		//�洢����
	{
		BLACK.push_back(coor);
		blacks++;
	}
	else {
		//�洢����
		WHITE.push_back(coor);
		whites++;
	}
	//��ʾ������
	chessBoard[coor.x][coor.y] = coor.side;
	return 0;
}

int BOARD::updateCursor(CURSOR cur)
//���¹���λ��
{
	nativeCur = cur;
	//�����ȥ���
	cursor[cur.oldX][cur.oldY] = 0;
	//��ʾ���ڹ��
	cursor[cur.newX][cur.newY] = 1;
	return 0;
}

int BOARD::show() {
	//��ʾ������Ϣ
	SetConsoleTitle(L"�����޵������� ������ ���� ����ʾ�����ӣ���**����ʾ��������"); // ���ô��ڱ���
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	SMALL_RECT rc = { 0,0, 45, 100}; // ���ô���λ�úʹ�С
	SetConsoleWindowInfo(hOut, true, &rc);
	//SetConsoleScreenBufferSize(hOut, size);
	cout << endl;
	for (int i = 0; i < MAX_ROW; i++)
	{
		cout << endl;
		cout << "  ";
		for (int j = 0; j < MAX_COL; j++)
		{
			if (cursor[i][j] == 1)
				//�������
			{
				if (chessBoard[i][j] == 0)
					//��ǰλ�ÿ�������
				{
					cout << " ��  ";
				}
				else
					//��ǰλ�ò���������
				{
					cout << " ** ";
				}

			}
			else
				//���̴�֮
			{
				switch (chessBoard[i][j])
				{
				case 0:
					cout << " �� ";
					break;
				case 1:
					cout << " �� ";
					break;
				case 2:
					cout << " �� ";
					break;
				default:
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

