#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "Action.h"

class CopyAction: public Action
{
	Point P1;
	ApplicationManager *Set;
public:
	CopyAction( ApplicationManager *pApp);
	//Reads  parameters
	virtual void ReadActionParameters();
	//add the selected figures to clipboard
		virtual void Execute() ;

	
};

#endif
