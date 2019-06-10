#ifndef CHNG_FCLR_ACTION_H
#define CHNG_FCLR_ACTION_H
#include "Action.h"


//Add Rectangle Action class
class ChangeFillColorAction: public Action
{
private:
	int x;//checks whether we got out of the color tool bar
	
public:
	ChangeFillColorAction(ApplicationManager *pApp);
	
     void 	setFillcolor(color &newColor,ActionType newcolor);// set new fill color
	//Reads parameters
	virtual void ReadActionParameters();
	
	//calls setfillcolor AND executes
	virtual void Execute() ;
	
};

#endif