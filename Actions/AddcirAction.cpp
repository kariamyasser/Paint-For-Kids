#include "AddcirAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"




AddcirAction::AddcirAction(ApplicationManager * pApp):Action(pApp)
{}

void AddcirAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New circle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	
	r=sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
	
	cirGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	cirGfxInfo.DrawClr = pOut->getCrntDrawColor();
	cirGfxInfo.FillClr = pOut->getCrntFillColor();
	cirGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddcirAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if(  P1.y>50 && P1.y-r>50 && P1.y<650 && P1.y+r<650 && P1.y-r<650)
	//Create a Circle with the parameters read from the user
	{
		if(pManager->zoom_mode==true)
		{
			Point z;
			z.x=P1.x / pManager->zoom_factor;
			
			z.y=P1.y / pManager->zoom_factor;
			int f=r/pManager->zoom_factor ;
		CCircle *R=new CCircle(z, f, cirGfxInfo);
		pManager->AddFigure(R);
		}
		else
		{
		CCircle *R=new CCircle(P1, r, cirGfxInfo);
		pManager->AddFigure(R);
		}
	//Add the Circle to the list of figures
	
	}
	else
	{
		pOut->PrintMessage("Invalid Dimensions");
		Sleep(1000);
		pOut->ClearStatusBar();
	
	}
pManager->saved=false;
	
}
