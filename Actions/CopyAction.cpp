#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
	Set=pApp;
}
void CopyAction::ReadActionParameters() 
{		

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

		pOut->PrintMessage("Is copied");
		
		 	pManager->DeleteCut_copyList();
	pManager->AddCopy();
		
}


void CopyAction::Execute() 
{ 
	
	
	ReadActionParameters();
	pManager->saved=false;

	}