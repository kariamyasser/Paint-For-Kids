#pragma once
#include "Action.h"
class ZoomInAll: public Action
{
private:
	
	float size;
public:
	ZoomInAll(ApplicationManager *pApp);

	//Reads zoom in factor
	virtual void ReadActionParameters();
	
	//zoom in graph
	virtual void Execute() ;

};
