#ifndef SELECT_FIG_ACTION_H
#define SELECT_FIG_ACTION_H

#include "Action.h"


class SelectFigureAction: public Action
{
private:
	Point P1; //Point to select
	
public:
	SelectFigureAction(ApplicationManager *pApp);

	//gets the coordinates and checks the fig
	virtual void ReadActionParameters();
	
	//selects the figure
	virtual void Execute() ;
	
};

#endif