#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H
#include "Action.h"
class PasteAction:  public Action
{
	Point P;
	ApplicationManager *Set;
	Action *ActType;

friend class CopyAction;
public:
	PasteAction( ApplicationManager *pApp);
	//Reads  parameters
	virtual void ReadActionParameters();
	//returns the figs from clipboard to fig list
		virtual void Execute() ;

	
};

#endif