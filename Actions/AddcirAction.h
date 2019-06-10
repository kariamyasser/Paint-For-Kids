#ifndef ADD_cir_ACTION_H
#define ADD_cir_ACTION_H

#include "Action.h"

//Add Circle Action class
class AddcirAction: public Action
{
private:
	Point P1; //Circle Center
	Point P2;	//P2-P1 =radius
	 int r; //cicle radius
	GfxInfo cirGfxInfo;
public:
	AddcirAction(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();
	
	//Add Circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif