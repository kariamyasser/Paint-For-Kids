#include "AddlineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"






AddlineAction::AddlineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddlineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	lineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	lineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	lineGfxInfo.FillClr = pOut->getCrntFillColor();
	lineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();


	

}

//Execute the action
void AddlineAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if(   P1.y<50 || P2.y<50 || P1.y>650 || P2.y>650)
	{
		pOut->PrintMessage("Invalid Dimensions");
		Sleep(1000);
		pOut->ClearStatusBar();
	
	}
	else
	//Create a Line with the parameters read from the user
	{
		
		if(pManager->zoom_mode==true)
		{
			Point z,f;
			z.x=P1.x/pManager->zoom_factor ;
			
			z.y=P1.y/pManager->zoom_factor;
			f.x=P2.x/pManager->zoom_factor ;
			
			f.y=P2.y/pManager->zoom_factor ;

		CLine *R=new CLine(z, f,lineGfxInfo);
			pManager->AddFigure(R);

		}
		else
		{

		CLine *R=new CLine(P1, P2,lineGfxInfo);
	pManager->AddFigure(R);

		}
	//Add the Line to the list of figures
	}
	pManager->saved=false;

}
