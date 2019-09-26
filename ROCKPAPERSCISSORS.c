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

enum move {Paper, Scissors, Rock};

int genComputerMove(void);
string generateWinner(int Player, int Computer);
int getPlayerMove(void);
string convert(int move);


int main() {
	int PlayerMove;
	int ComputerMove;
	for (int i=0; i<20; i++){
		cout<<"Round #"<< i+1 << endl;
		PlayerMove = getPlayerMove();
		ComputerMove = genComputerMove();
		cout<<"You played [" << convert(PlayerMove) <<"]"<< endl;
		cout<<"The computer played ["<< convert(ComputerMove) <<"]"<<endl;
		cout<<"The winner is ["<< (generateWinner(PlayerMove, ComputerMove)) <<"]"<< endl <<endl;
	}
return 0;
}


int getPlayerMove(void){
	int pmove;
	cout<< "Please enter 1 for paper, 2 for scissors, or 3 for rock:"<<endl;
	cin>>pmove;

	//Makes sure the move is valid for our set of values
	while (!(pmove>=1 && pmove<= 3)){
		cout<< "Invalid Move, Please try again"<<endl;
		cin>>pmove;
	}
	return pmove;
}

int genComputerMove(void){
	//generate a random number and mod it with 3 to get the value of the computer move (1== paper, 2== scissors, 3==rock)
	int move = rand() % 3;
	while (move == 0){
		move = rand() % 3;
	}
	return move;
}

string convert(int move){
	string item;
	switch(move){
		case 1:
			item ="Paper";
			break;
		case 2:
			item = "Scissor";
			break;
		case 3:
			item = "Rock";
			break;
		default:
			item = "Error";
	}
	return item;
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
