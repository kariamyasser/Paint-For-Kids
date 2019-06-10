#ifndef CHNG_BCLR_ACTION_H
#define CHNG_BCLR_ACTION_H
#include "Action.h"


//Add Rectangle Action class
class ChangeBckgndColorAction: public Action
{
private:
	
	int x;	//checks whether we got out of the color tool bar
public:
	ChangeBckgndColorAction(ApplicationManager *pApp);
		void setBkGndcolor(color &newColor,ActionType newcolor);// sets the new background color
	//Reads parameters and gets color
	virtual void ReadActionParameters();
	
	//changes the color
	virtual void Execute() ;
	
};

#endif