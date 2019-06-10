#pragma once
#include "Action.h"


class Rotate: public Action
{
	int angle;
public:
	Rotate(ApplicationManager *pApp);
	//read rotation angle
	virtual void ReadActionParameters();
	//rotate the selected figures
	virtual void Execute() ;
	~Rotate();
};

