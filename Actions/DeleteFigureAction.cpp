#include "DeleteFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager * pApp):Action(pApp)
{}

void DeleteFigureAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	

	pOut->PrintMessage("Deleting all selected shapes,Please wait");
	
	Sleep(300);
	

	pOut->ClearStatusBar();

}

//Execute the action
void DeleteFigureAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	

	//This action needs to read some parameters first
   
	ReadActionParameters();
	

	pManager->DeleteSelectedFigure();
			pOut->PrintMessage("Selected figures deleted");
	
	Sleep(1100);
	pOut->ClearDrawArea();
	pManager->saved=false;

}
