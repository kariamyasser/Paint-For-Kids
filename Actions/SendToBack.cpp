#include "SendToBack.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SendToBack::SendToBack(ApplicationManager * pApp):Action(pApp)
{
}

void SendToBack::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*pIn =pManager->GetInput();
	pOut->PrintMessage("Point to the shape you want ");
	pIn->GetPointClicked(P.x, P.y);
	

}

//Execute the action
void SendToBack::Execute() 
{
			Output* pOut = pManager->GetOutput();

			ReadActionParameters();
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
		pOut->ClearStatusBar();

		
	pOut->PrintMessage("You Didn't choose a correct figure ");
	}
			else{
		pManager->Bringtoback(specificfigure);
			pOut->ClearStatusBar();

		
	pOut->PrintMessage("Figure Sent To Back ");

			}
	}
	