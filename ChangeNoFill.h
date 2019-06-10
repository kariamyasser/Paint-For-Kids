#ifndef CHNG_NFILL_ACTION_H
#define CHNG_NFILL_ACTION_H
#include "Actions\Action.h"


//Add Rectangle Action class
class ChangeNoFill: public Action
{
private:
	
	
public:
	ChangeNoFill(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif