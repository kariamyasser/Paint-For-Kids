#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "Action.h"

class CutAction: public Action
{
	Point P1;
	ApplicationManager *Set;
public:
	CutAction( ApplicationManager *pApp);
	//Reads parameters
	virtual void ReadActionParameters();
	//remove from fig list and add to clipboard
		virtual void Execute() ;

	
};

#endif
