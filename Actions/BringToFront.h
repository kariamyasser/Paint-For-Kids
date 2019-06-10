#pragma once
#include "Action.h"
class BringToFront: public Action
{
private:
	Point P; 
	
public:
	BringToFront(ApplicationManager *pApp);

	//Reads shape to be brought to front parameters
	virtual void ReadActionParameters();
	
	//brings shape to front
	virtual void Execute() ;

};
