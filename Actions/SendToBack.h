#pragma once
#include "Action.h"
class SendToBack: public Action
{
private:
	Point P; //Rectangle Corners
	
public:
	SendToBack(ApplicationManager *pApp);

	//Reads the fig to be sent to back
	virtual void ReadActionParameters();
	
	//fig is sent to back
	virtual void Execute() ;

};
