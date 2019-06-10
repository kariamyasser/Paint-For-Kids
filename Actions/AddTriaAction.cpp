#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddTriaAction::AddTriaAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriaAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriaGfxInfo.FillClr = pOut->getCrntFillColor();
	TriaGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriaAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if(   P1.y<50 || P2.y<50 || P3.y<50 || P1.y>650 || P2.y>650 || P3.y>650)
	{

		pOut->PrintMessage("Invalid Dimensions");
		Sleep(1000);
		pOut->ClearStatusBar();
	
	}
	else
	//Create a Triangle with the parameters read from the user
{	
	if(pManager->zoom_mode==true)
		{
			Point z,f,w;
			z.x=P1.x/pManager->zoom_factor ;
			
			z.y=P1.y/pManager->zoom_factor;
			f.x=P2.x/pManager->zoom_factor ;
			
			f.y=P2.y/pManager->zoom_factor ;

			w.x=P3.x/pManager->zoom_factor;
			
			w.y= P3.y/pManager->zoom_factor ;
	CTriangle *R=new CTriangle(z, f, w, TriaGfxInfo);

			pManager->AddFigure(R);

		}
		else
		{
	CTriangle *R=new CTriangle(P1, P2, P3, TriaGfxInfo);

	pManager->AddFigure(R);

		}

	
	
	CTriangle *R=new CTriangle(P1, P2, P3, TriaGfxInfo);

	//Add the Triangle to the list of figures
}
	pManager->saved=false;

}
