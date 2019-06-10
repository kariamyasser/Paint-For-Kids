#include "ExitAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ExitAction::ExitAction(ApplicationManager * pApp):Action(pApp)
{}

void ExitAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Sleep(600);
	

	pOut->ClearStatusBar();

}

string ExitAction:: ctos(color x)
		{
			string s;
			if (x .ucBlue== PURPLE.ucBlue && x.ucGreen== PURPLE.ucGreen && x.ucRed== PURPLE.ucRed) { s="PURPLE"; return s;}
			else if (x .ucBlue== RED.ucBlue && x.ucGreen== RED.ucGreen && x.ucRed== RED.ucRed ) { s="RED"; return s;}
			else if (x .ucBlue== YELLOW.ucBlue && x.ucGreen==YELLOW.ucGreen && x.ucRed== YELLOW.ucRed){ s="YELLOW"; return s;}
			else if (x .ucBlue== BLUE.ucBlue && x.ucGreen==BLUE.ucGreen && x.ucRed== BLUE.ucRed) {s="BLUE"; return s;}
			else if (x .ucBlue== GREEN.ucBlue && x.ucGreen==GREEN.ucGreen && x.ucRed== GREEN.ucRed) {s="GREEN"; return s;}
			else if (x .ucBlue== BLACK.ucBlue && x.ucGreen==BLACK.ucGreen && x.ucRed== BLACK.ucRed) {s="BLACK"; return s;}
			else { s= "NO_CLR"; return s;}

		}
//Execute the action
void ExitAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
		Input * pIn=pManager->GetInput();

	//This action needs to read some parameters first
	ReadActionParameters();
	if(pManager->saved==false)
	{
	pOut->PrintMessage("Do You Want to Save Your graph?? Yes or No");
	Sleep(1200);
	
	string s;
		pOut->PrintMessage("Please enter your choice >>> ");
		Sleep(1200);
	
	s = pIn->GetSrting(pOut);
	if (s=="Yes" || s=="YES"|| s=="yes"|| s=="y"|| s=="Y")
	{
		pOut->PrintMessage("Please enter file name >>> ");
	Sleep(1200);
	
		Input * pIn=pManager->GetInput();
	s = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Name >>> " +s);
	
	Sleep(1200);
	pOut->ClearStatusBar();

	pManager->outfile.open(s+".txt");

	color x =pOut->getCrntDrawColor();
	color y = pOut->getCrntFillColor();
	color z =pOut->getCrntBkColor();
	pManager->outfile<<ctos(x)<<"        "<<ctos(y)<<"        "<<ctos(z)<<"  \n"<<pManager->getfigcount()<<"  \n";
	
	pManager->save();
	pManager->outfile.close();
	pManager->saved=true;
	pOut->PrintMessage("File SAVED");
	Sleep(1200);
	pManager->saved=true;
	
	}
	else
	{
		pManager->saved=true;
	pManager->DeleteAll();

	pOut->ClearDrawArea();
	}
	
	}
	

	pOut->PrintMessage("BYE :)");
	
	
	pManager->DeleteAll();

	pOut->ClearDrawArea();
	
}
