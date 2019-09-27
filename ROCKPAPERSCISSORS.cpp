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
#include "Computer.h"
#include "Human.h"
#include "Round.h"
using namespace std;

enum move {Paper, Scissors, Rock};

// int getComputerMove(void);
// int getPlayerMove(void);
string convert(int move);
void scoreBoard(string winner, int* position);
void printScoreBoard(int* arr, int size);
void RockPaperScissor();

int main() {
	RockPaperScissor();
	return 0;
}

void RockPaperScissor() {

	Human *player = new Human();
	Computer *computer = new Computer();
	Round *newRound = new Round();

	// Scoreboard
	int track[3] = {0};

	for (int i = 0; i < 20; i++) {
		cout << "Round #" << i + 1 << endl;
		player->setMove();
		computer->setMove();
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

// int getPlayerMove(void){

// }

// int getComputerMove(void){
	
// }

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
