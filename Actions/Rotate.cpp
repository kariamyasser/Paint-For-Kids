#include "Rotate.h"

#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Rotate::Rotate(ApplicationManager * pApp):Action(pApp)
{angle=1;
}

void Rotate::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*pIn =pManager->GetInput();

	pOut->PrintMessage("Choose Rotate Angle");
	RotateType ReAct=pIn->GetUserRotateAction();
	switch(ReAct)
	{
	case R_90 : angle=90; pOut->PrintMessage("Rotate by 90*");break;
	case R_180 : angle=180; pOut->PrintMessage("Rotate by 180*");break;
	case R_270 : angle=270; pOut->PrintMessage("Rotate by 270*"); break;
	case R_BACK : angle=0; pOut->PrintMessage("Back to Draw Toolbar");break;
	};
	

	
	pOut->ClearDrawArea();
}

//Execute the action
void Rotate::Execute() 
{
	
	Output* pOut = pManager->GetOutput();
	
while(angle!=0)
	{	
	ReadActionParameters();
			if (angle==0)
	{
		pOut->cleartoolbar();
		pOut->CreateDrawToolBar();
		break;
	}
			
			else{
		pManager->Rotatefig(angle);
	
	}
		pOut->PrintMessage("figures rotated successfully");
	
	Sleep(1100);
	
}
	
	pManager->saved=false;

}
	