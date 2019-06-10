#pragma once
#include "Action.h"
class ZoomOutAll: public Action
{
private:
	
	float size;
public:
	ZoomOutAll(ApplicationManager *pApp);

	//reads xoom out factor
	virtual void ReadActionParameters();
	
	//zoom out graph
	virtual void Execute() ;

};
