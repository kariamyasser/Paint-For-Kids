#ifndef ADD_TRIA_ACTION_H
#define ADD_TRIA_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriaAction: public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriaGfxInfo;
public:
	AddTriaAction(ApplicationManager *pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();
	
	//Add Triangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif
