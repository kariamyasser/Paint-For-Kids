#include "SaveAll.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SaveAll::SaveAll(ApplicationManager * pApp):Action(pApp)
{
}
string SaveAll:: ctos(color x)
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
void SaveAll::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Please enter file name >>> ");
	Input * pIn=pManager->GetInput();
	s = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Name >>> " +s);
	
	Sleep(1100);
	

	pOut->ClearStatusBar();

}

//Execute the action
void SaveAll::Execute() 
{
   

	//This action needs to read some parameters first
	ReadActionParameters();
	
	 Output* pOut = pManager->GetOutput();
	
	pManager->outfile.open(s+".txt");

	color x =pOut->getCrntDrawColor();
	color y = pOut->getCrntFillColor();
	color z =pOut->getCrntBkColor();
	int pen= pOut->getCrntPenWidth();
	pManager->outfile<<ctos(x)<<"        "<<ctos(y)<<"        "<<ctos(z)<<"  \n"<<pen<<"        "<<pManager->getfigcount()<<"  \n";
	
	pManager->save();
	pManager->outfile.close();
	pManager->saved=true;
	pOut->PrintMessage("File SAVED");
}


