
#pragma once
#include "Action.h"
#include <fstream>
class LoadAll: public Action
{
private:
	
	string s;
	ifstream infile;
public:
	LoadAll(ApplicationManager *pApp);
	color stoc(string s);//change string to color
	//Reads parameters and filee name
	virtual void ReadActionParameters();
	void prepareloading();//checks whether to save the existing or not
	//loads it
	virtual void Execute() ;
	string  ctos(color x);//changes color to string
		

};
