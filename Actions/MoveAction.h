#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"

class MoveAction: public Action
{
	Point P1;
	ApplicationManager *Set;
public:
	MoveAction( ApplicationManager *pApp);
	//Reads  parameters
	virtual void ReadActionParameters();

	//moves the figure to the new coordinates
		virtual void Execute() ;

	
};

#endif
