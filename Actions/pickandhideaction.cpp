#include "pickandhideaction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Pickandhideaction::Pickandhideaction(ApplicationManager * pApp):Action(pApp)
{}

void Pickandhideaction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the mode of playing");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

//Execute the action
void Pickandhideaction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	
Input* pIn = pManager->GetInput();
  while (true)
  {
	pOut->PrintMessage("Point to the shape you want,if you gonna play with area Pick the smallest or largest and be sure that there are no any copied figures ");
	
	
	pIn->GetPointClicked(P.x, P.y);
	CFigure*specificfigure;
		if (pManager->zoom_mode==true)
		{
			Point z;
			z.x = P.x /pManager->zoom_factor;
			z.y = P.y /pManager->zoom_factor;
			specificfigure=pManager->GetFigure(z);
		}
		else{specificfigure=pManager->GetFigure(P);}
		
	
	if (specificfigure==NULL)
	{
		pOut->PrintMessage("No figure selected ");
		Sleep(1100);
		pOut->ClearStatusBar();
		pOut->cleartoolbar();
		pOut->CreatePlayToolBar();
		break;
	}
		Beep (900,200);
			Sleep(125);
	specificfigure->DeleteFig(pOut,pManager->zoom_factor);
	
	specificfigure->setchoosen(true);
	pManager->UpdateInterface();
	Sleep(500);
	
	pOut->PrintMessage("Choose the mode of playing");
	
	
	pIn->GetPointClicked(P.x, P.y);
	
	
	
	if (P.y<50 && P.x<58)
	{
        pOut->PrintMessage("you Choosed playing with type. Now try to pick some figures has the same type of the choosen one");
		pManager->TypeMode(P,specificfigure);
		
			
	}
	else if(P.y<50 && P.x>58 && P.x<116)
	{
		if (specificfigure->returntype()==LINE)
		{
			pOut->PrintMessage("You cant play with line in Fill Colour ,please choose another type");
			pManager->ResetChoosen();
			Sleep(900);
			
		}
		else
		{
		pOut->PrintMessage("you Choosed playing with Fill Color.Now try to pick some figures has the same Fill clr of the choosen one");
		pManager->FillMode(P,specificfigure);
		}
	}
	else if (P.y<50 && P.x>116 && P.x<174)
	{
		if (specificfigure->returntype()==LINE)
		{
			pOut->PrintMessage("You cant play with line in Fill Colour ,please choose another type");
			pManager->ResetChoosen();
			Sleep(900);
			
		}
		else
		{
		pOut->PrintMessage("you Choosed playing with Type and Fill Color. Now try to pick some figures has the same type and fill clr of the choosen one");
		pManager->Type_FillMode(P,specificfigure);
		}
	}
	else if (P.y<50 && P.x>174 && P.x<232)
	{
		pOut->PrintMessage("you Choosed playing with Area. Now try to pick next figure related to the area of first figure ");
		pManager->AreaMode(P,specificfigure);
	}
	pManager->ResetChoosen();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	}
}