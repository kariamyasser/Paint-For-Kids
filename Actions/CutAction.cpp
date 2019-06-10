#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{
	Set=pApp;
}
void CutAction::ReadActionParameters() 
{		

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
		pOut->PrintMessage("Is cut");
				pManager->DeleteCut_copyList();

		pManager->RemoveCut();
}
	

	



void CutAction::Execute() 
{ 
	

	
	ReadActionParameters();
	pManager->saved=false;

	}