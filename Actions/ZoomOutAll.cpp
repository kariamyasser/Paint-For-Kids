#include "ZoomOutAll.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ZoomOutAll::ZoomOutAll(ApplicationManager * pApp):Action(pApp)
{size=1;
}

void ZoomOutAll::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*pIn =pManager->GetInput();

	pOut->PrintMessage("Choose zoom out factor");
	ZoomoutType ReAct=pIn->GetUserZoomoutAction();
	switch(ReAct)
	{
	case Z_25 : size=0.75; pManager->zoom_mode=true; break;
	case Z_50 : size=0.5; pManager->zoom_mode=true;break;
	case Z_75 : size=0.25;pManager->zoom_mode=true; break;
		
	case ZO_NO: size=1; pManager->zoom_mode=false;break;
	case ZO_BACK: size=0; break;
	};
	


}

//Execute the action
void ZoomOutAll::Execute() 
{
		Output* pOut = pManager->GetOutput();
while (size!=0)
	{
		ReadActionParameters();
	if (size ==0){
	
		pOut->ClearStatusBar();
		pOut->cleartoolbar();
		pOut->CreateZoomToolBar();
		break;
	}
	else{
		
			pManager->zoom_factor=size;
				pOut->ClearDrawArea();
				pManager->UpdateInterface();
				pOut->cleartoolbar();
				pOut->CreateZoomoutToolBar();
				pOut->ClearStatusBar();
	}
	
		pOut->PrintMessage("Figures	zoomed out");
	
	Sleep(1100);
}
	
	}
