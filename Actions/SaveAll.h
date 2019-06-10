
#pragma once
#include "Action.h"
#include <fstream>
class SaveAll: public Action
{
private:
	Point P1; 
	string s;

public:
	SaveAll(ApplicationManager *pApp);
	string ctos(color x);
	//Reads the file name
	virtual void ReadActionParameters();
	
	//saves the graph
	virtual void Execute() ;

};
