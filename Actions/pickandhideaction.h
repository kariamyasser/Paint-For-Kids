#ifndef PICK_HIDE_ACTION
#define PICK_HIDE_ACTION
#include "Action.h"



class Pickandhideaction: public Action
{
private:
	Point P;
public:
	Pickandhideaction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
	
};

#endif