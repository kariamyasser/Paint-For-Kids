#include "MoveAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager * pApp):Action(pApp)
{
	Set=pApp;
}
void MoveAction::ReadActionParameters() 
{		

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
		pOut->PrintMessage("Moved");
		pManager->DrawMoved();
}


void MoveAction::Execute() 
{ 
	

	ReadActionParameters();
	
	pManager->saved=false;

	}