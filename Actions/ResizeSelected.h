#pragma once
#include "Action.h"
class ResizeSelected: public Action
{
private:
	
	float size;
public:
	ResizeSelected(ApplicationManager *pApp);

	//Reads resize factor
	virtual void ReadActionParameters();
	
	//resize selected shapes
	virtual void Execute() ;

};
