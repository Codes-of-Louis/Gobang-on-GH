#pragma once
#include"Board.h"

class PLAYER
{
public:
	PLAYER();
	~PLAYER();
	virtual int luozi(BOARD* board);	//��д��
	int nativeSide;
private:
};

