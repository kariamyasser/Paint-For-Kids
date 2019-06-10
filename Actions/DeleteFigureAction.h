#ifndef DELETE_FIG_ACTION_H
#define DELETE_FIG_ACTION_H
#include "Action.h"


class DeleteFigureAction: public Action
{

public:
	DeleteFigureAction(ApplicationManager *pApp);

	//gets the seleted items
	virtual void ReadActionParameters();
	
	//deletes and removes them from fig list
	virtual void Execute() ;
	
};

#endif