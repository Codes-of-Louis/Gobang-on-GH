#include<string>
#include<windows.h>

#include"Player.h"
#include "People.h"
#include"Judgement.h"
#include"Machine.h"
int main()
{
	//������Ϣ
	SetConsoleTitle(L"��ӭ���������޵������壬��ѡ��ģʽ"); // ���ô��ڱ���
	cout << "��������ӭ���������޵������壬��ѡ��ģʽ������" << endl << endl;
	cout << "	1 : ����ģʽ" << endl;
	cout << "	2/anykey : �˻�ģʽ" << endl;
	cout << "��������ѡ��";
	int mode;
	cin >> mode;
	//����ָ��
	BOARD* board = new BOARD();
	JUDGE* jud = new JUDGE();
	//����ָ�룬���������ָ���������
	PLAYER* player1;
	PLAYER* player2;
	//ѡ��һΪ�ˣ���ʼ��ʱָ��side
	player1 = new PEOPLE(1);
	//����modeѡ��ѡ�ֶ�
	if (mode == 1)
	{
		player2 = new PEOPLE(2);
	}
	else {
		player2 = new MACHINE(2);;
	}
	//ֱ���ֳ���Ӯ
	while (true)
	{
		player1->luozi(board);
		if (jud->decide(board) == 1)
			//�����˽��
		{
			break;
		}
		player2->luozi(board);
		if (jud->decide(board) == 1)
			//�����˽��
		{
			break;
		}
	}
	cin >> mode;//��ͣһ��
	return 0;
}