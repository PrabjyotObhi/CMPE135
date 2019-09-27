//============================================================================
// Name        : ROCKPAPERSCISSORS.cpp
// Author      : Prabjyot Obhi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.h"
#include "Round.h"
using namespace std;

enum move {Paper, Scissors, Rock};

int getComputerMove(void);
int getPlayerMove(void);
string convert(int move);
void scoreBoard(string winner, int* position);
void printScoreBoard(int* arr, int size);
void RockPaperScissor();

int main() {
	RockPaperScissor();
	return 0;
}

void RockPaperScissor(){

	Player *player = new Player();
	Player *computer = new Player();
	Round *newRound = new Round();

	// Scoreboard
	int track[3] = {0};

	for (int i = 0; i < 20; i++) {
		cout << "Round #" << i + 1 << endl;
		player->setMove(getPlayerMove());
		computer->setMove(getComputerMove());
		cout << "You played [" << convert(player->getMove()) << "]" << endl;
		cout << "The computer played [" << convert(computer->getMove()) << "]" << endl;
		newRound->setWinner(newRound->detWinner(player->getMove(), computer->getMove()));
		cout << "The winner is [" << newRound->getWinner() << "]" << endl << endl;
		scoreBoard(newRound->getWinner(), track);
		printScoreBoard(track, 3);
	}
}

void printScoreBoard(int* arr, int size) {
	cout << "Player           Computer            Tie" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  " << arr[i] << "               ";
	}
	cout << endl << endl;
}

void scoreBoard(string winner, int* position){
	if (winner == "Player") {
		position[0]++;
	}
	else if (winner == "Computer") {
		position[1]++;
	}
	else {
		position[2]++;
	}

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

int getComputerMove(void){
	//generate a random number and mod it with 3 to get the value of the computer move (1== paper, 2== scissors, 3==rock)
	int move = rand() % 4;
	while (move == 0){
		move = rand() % 4;
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
