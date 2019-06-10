#ifndef CHNG_CLR_ACTION_H
#define CHNG_CLR_ACTION_H
#include "Action.h"


//Add Rectangle Action class
class ChangeColorAction: public Action
{
private:
	int x; //checks whether we got out of the color tool bar
public:
	ChangeColorAction(ApplicationManager *pApp);
	void setDrawcolor(color &newColor,ActionType newcolor);// changes the drawing color
	//Reads parameters
	virtual void ReadActionParameters();
	
	//calls set drawcolor and executes
	virtual void Execute() ;
	
};

#endif