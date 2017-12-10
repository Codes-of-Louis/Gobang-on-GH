#pragma once
# include<iostream>
# include<vector>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define MAX_ROW 20
#define MAX_COL 20

//����
typedef struct
{
	//��ʶ����
	int x;
	int y;
	//��ʶս��,1:BLACK/2:WHITE/0:DEFAULT
	int side;
} COORDINATE;

//���
typedef struct
{
	//������
	int oldX;
	int oldY;
	//������
	int newX;
	int newY;
} CURSOR;

class BOARD
	//������¼������������Ϣ
{
public:
	BOARD();
	~BOARD();
	int add(COORDINATE coor);	//�洢��������
	int updateCursor(CURSOR cur);	//���¹��λ��
	int show();	//��ӡ����
	CURSOR nativeCur;	//��ǰ���λ��
	COORDINATE nativeCoor;	//����λ��
	int chessBoard[MAX_ROW][MAX_COL];	//������Ϣ
	int cursor[MAX_ROW][MAX_COL];	//�������Ϣ
private:
	//���ݼ�¼
	int blacks;	//���Ӹ���
	int whites;	//���Ӹ���
	//�洢����
	vector<COORDINATE> BLACK;
	//�洢����
	vector<COORDINATE> WHITE;
};