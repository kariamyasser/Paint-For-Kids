
#ifndef SCRAMBLE_ACTION_H
#define SCRAMBLE_ACTION_H
#include "Action.h"
class ScrambleAction :public Action
{

public:
	ScrambleAction( ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
		virtual void Execute() ;



};


#endif