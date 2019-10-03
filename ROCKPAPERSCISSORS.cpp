//============================================================================
// Name        : ROCKPAPERSCISSORS.cpp
// Author      : Prabjyot Obhi, Raymond Chen, Derrick Lien, Gaurav Kuppa
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

string convert(int move);
void scoreBoard(string winner, int* position);
void printScoreBoard(int* arr, int size);
void RockPaperScissor();
// void RockPaperScissor(char mode); TODO: add mode parameter

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "RockPaperScissors requires one command line argument (\"-r\" for random, \"-m\" for ML)." << endl;
	}
	else if (argc == 2) {
		string arg = argv[1];

		if (arg == "-r") {
			cout << "Computer utilizing random algorithm!" << endl;
			RockPaperScissor();
		}
		else if (arg == "-m") {
			cout << "Computer utilizing machine learning algorithm!" << endl;
		}
		else {
			cout << "Invalid argument. Valid arguments are \"r\" for random, \"m\" for ML." << endl;
		}
	}
	else {
		cout << "Invalid number of command line arguments. Please try again." << endl;
		cout << "Valid arguments are \"r\" for random, \"m\" for ML." << endl;
	}

	return 0;
}

void RockPaperScissor() {

	// TODO: Implement different computer player depending on game mode selected (random or ML)

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
