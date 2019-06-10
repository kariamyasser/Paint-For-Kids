#include "PasteAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "CopyAction.h"

PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
	Set=pApp;
}


	

void PasteAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Point where do you want to Paste");
			pManager->DrawCut_Copy();

	}
void PasteAction::Execute() 
{ 
					
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
			
	 pManager->saved=false;

	}

