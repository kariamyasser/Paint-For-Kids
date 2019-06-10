#ifndef CHNG_BW_ACTION_H
#define CHNG_BW_ACTION_H
#include "Action.h"


//Add Rectangle Action class
class ChangeBorderWidth: public Action
{
private:
	int x;//checks whether we got out of the border size tool bar
	
public:
	ChangeBorderWidth(ApplicationManager *pApp);
		void setwidth(int &width );// returns the width factor
	//Reads parameters
	virtual void ReadActionParameters();
	
	//cals set width using the parameters
	virtual void Execute() ;
	
};

#endif