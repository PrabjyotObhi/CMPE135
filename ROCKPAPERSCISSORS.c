//============================================================================
// Name        : ROCKPAPERSCISSORS.cpp
// Author      : Prabjyot Obhi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;
int genComputerMove(void);
string generateWinner(int Player, int Computer);

int main() {
	int PlayerMove;
	int ComputerMove;
	for (int i=0; i<20; i++){
		cout<<"Round #"<< i+1 << endl;
		cout<< "Please enter 1 for paper, 2 for scissors, or 3 for rock:"<<endl;
		cin>>PlayerMove;

		//Makes sure the move is valid for our set of values
		while (!(PlayerMove>=1 && PlayerMove<= 3)){
			cout<< "Invalid Move, Please try again"<<endl;
			cin>>PlayerMove;
		}
		ComputerMove = genComputerMove();
		cout<<"You played [" << PlayerMove <<"]"<< endl;
		cout<<"The computer played ["<< ComputerMove <<"]"<<endl;
		cout<<"The winner is ["<< (generateWinner(PlayerMove, ComputerMove)) <<"]"<< endl <<endl;
	}
return 0;
}

int genComputerMove(void){
	//generate a random number and mod it with 3 to get the value of the computer move (1== paper, 2== scissors, 3==rock)
	return rand()%3;
}


string generateWinner(int Player, int Computer){
	string Winner;
	if (Player == Computer){
		Winner = "Tie";
	}
	else if(Player == 1 && Computer == 2){
		Winner = "Computer";
	}
	else if (Player == 1 && Computer ==3){
		Winner = "Player";
	}
	else if (Player ==2 && Computer == 1){
		Winner = "Player";
	}
	else if (Player ==2 && Computer == 3){
		Winner = "Computer";
	}
	else if (Player == 3 && Computer == 1){
		Winner = "Computer";
	}
	else if (Player == 3 && Computer == 2){
		Winner = "Player";
	}
	return Winner;
}
