#include"People.h"


PEOPLE::PEOPLE(int side)
//���캯��
{
	nativeSide = side;
}

PEOPLE::~PEOPLE()
{
}

int PEOPLE::luozi(BOARD* board)
{
	CURSOR cur;
	COORDINATE coor;

	int action = 0;	//�Ƿ����ӣ����ӲŽ�����Ȩ���ƶ�λ�ò�������
	while (action == 0) {
		//���¹��
		//��һ�ֵ��µı����һ�ֵľɵ�
		cur.oldX = board->nativeCur.newX;
		cur.oldY = board->nativeCur.newY;
		system("cls");
		board->show();
		char decide;
		if (nativeSide == 1)
		{
			cout << "��ҡ������ӣ�w/s/a/d���Ʒ���j����,���� ����ʾ�����ӣ���**����ʾ��������: ";
		}
		else
		{
			cout << "��ҡ������ӣ�w/s/a/d���Ʒ���j����,���� ����ʾ�����ӣ���**����ʾ��������: ";

		}

		decide = _getch();  //����̨�Ӽ��̻��һ���ַ�
		switch (decide)   //����
		{
		case 'w':  //��
			cur.newX = (cur.oldX - 1 + MAX_ROW) % MAX_ROW;  //ʹ���������-1�������ܳ����������ƣ�ѭ��
			cur.newY = cur.oldY;
			board->updateCursor(cur);	//���¹��
			break;
		case 's':  //��
			cur.newX = (cur.oldX + 1 + MAX_ROW) % MAX_ROW;
			cur.newY = cur.oldY;
			board->updateCursor(cur);
			break;
		case 'a':  //��
			cur.newX = cur.oldX;
			cur.newY = (cur.oldY - 1 + MAX_COL) % MAX_COL;
			board->updateCursor(cur);
			break;
		case 'd':  //��
			cur.newX = cur.oldX;
			cur.newY = (cur.oldY + 1 + MAX_COL) % MAX_COL;
			board->updateCursor(cur);
			break;
		case 'j':   //����
			coor.x = cur.oldX;
			coor.y = cur.oldY;
			coor.side = nativeSide;
			board->add(coor);	//����
			action = 1;	//��ʾ�Ѿ����ӣ����Խ�����Ȩ
			break;
		}

	}
	system("cls");
	board->show();
	return 0;
}
