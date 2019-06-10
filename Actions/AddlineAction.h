#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"

//Add Line Action class
class AddlineAction: public Action
{
private:
	Point P1, P2; //line Corners
	GfxInfo lineGfxInfo;
public:
	AddlineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();
	
	//Add line to the ApplicationManager
	virtual void Execute() ;
	
};

#endif