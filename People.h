#pragma once
#include"Player.h"
# include"Board.h"

class PEOPLE : public PLAYER
{
public:
	PEOPLE(int side);	//���캯��
	~PEOPLE();
	int luozi(BOARD* board);	//����
private:
};

