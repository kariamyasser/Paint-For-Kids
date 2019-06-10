#ifndef EXIT_ACTION
#define EXIT_ACTION
#include "Action.h"

//Add Rectangle Action class
class ExitAction: public Action
{

public:
	ExitAction(ApplicationManager *pApp);

	//Reads whether the user wants to save the graph if it is not saved
	virtual void ReadActionParameters();
	
	//exits and saves
	virtual void Execute() ;
	
	string ctos(color x);//change color to string
};

#endif