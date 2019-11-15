//============================================================================
// Name        : ROCKPAPERSCISSORS.cpp
// Author      : Prabjyot Obhi, Raymond Chen, Derrick Lien, Gaurav Kuppa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <map>
#include "Computer.h"
#include "Human.h"
#include "Round.h"
#include "Chooser.h"
#include "Scoreboard.h"
#include <vector>
#include <sstream>
using namespace std;

// void writeFreq(const vector<string> &sequence, const vector<int> &frequency);
// void readFreq(vector<string> &sequence, vector<int> &frequency);

class RPS {
    public:

        RPS() {
            computer_choice = 0;
            m_round = 0;
        }

        void r_RockPaperScissor() {
            Human *player = new Human();
            Computer *computer = new Computer();
            Round *newRound = new Round();

            // Scoreboard
            

            for (int i = 0; i < 20; i++) {
                cout << "Round #" << i + 1 << endl;
                player->setMove_rand();
                computer->setMove_rand();
                cout << "You played [" << convert(player->getMove()) << "]" << endl;
                cout << "The computer played [" << convert(computer->getMove()) << "]" << endl;
                newRound->setWinner(newRound->detWinner(player->getMove(), computer->getMove()));
                cout << "The winner is [" << newRound->getWinner() << "]" << endl << endl;
                scoreBoard(newRound->getWinner(), track);
                printScoreBoard(track, 3);
            }
        }

        string playRound(int move) {
            Computer *computer = new Computer();
            Round *newRound = new Round();
            string winner = "";

            m_round++;
            computer->setMove_rand();
            newRound->setWinner(newRound->detWinner(move, computer->getMove()));
            computer_choice = computer->getMove();
            cout << "Human move was " << move << endl;
            cout << "Computer move was " << computer_choice << endl;

            scoreBoard(newRound->getWinner(), track);
            
            if(newRound->getWinner() == "Human") {
                score.setScore(HUMAN);
                cout << "Human won!\n";
            }
            else if(newRound->getWinner() == "Computer") {
                score.setScore(COMPUTER);
                cout << "Computer won!\n";
            }
            else if(newRound->getWinner() == "Tie") {
                score.setScore(TIE);
                cout << "Tie!\n";
            }

            winner = newRound->getWinner();

            delete newRound;
            delete computer;

            return winner;
        }

        string playMLRound(int move)
        {
            m_round++;

        	Human *player = new Human();
        	Computer *computer = new Computer();
        	Round *newRound = new Round();
        	int n = 5;
            string winner = "";
        	// Choices
        	// queue<char> choices;
        	// Map
        	// map<string, int> m;
        	// Scoreboard
        	// int track[3] = {0};

       		cout << "Round #" << m_round << endl;
            player->setMove(move);
            
            if (choices.size() >= 5)
            {
                choices.pop();
            }

            choices.push(player->getMove()); //push player move
            cout << "player move = " << player->getMove() << endl;
            cout << "choices[0] = " << choices.front() << endl;

            computer->setParams(getString(choices), m);
            computer->setMove();
            computer_choice = computer->getMove();

            cout << "computer move = " << computer_choice << endl;
            
            cout << "Predicted human move [" << computer->getPlayerPrediction() << "]" << endl;
            cout << "You played [" << convert(player->getMove()) << "]" << endl;
            cout << "The computer played [" << convert(computer->getMove()) << "]" << endl;
            
            // if (choices.size() >= 5)
            // {
            //     choices.pop();
            // }
            // choices.push(computer->getMove());
            if (choices.size() == 5)
            {
                string s = getString(choices);
                if (m.find(s) == m.end())
                {
                    // not found
                    m[s] = 1;
                }
                else
                {
                    // found
                    m[s] = m[s] + 1;
                }
                choices.pop();
            }
            choices.push(computer->getMove());

            queue<int> temp = choices;

            cout << "content of choices queue = ";

            for(int i = 0; i < choices.size(); i++) {
                cout << temp.front() << " ";
                temp.pop();
            }

            cout << endl;

            newRound->setWinner(newRound->detWinner(player->getMove(), computer->getMove()));
            cout << "The winner is [" << newRound->getWinner() << "]" << endl
                    << endl;
            scoreBoard(newRound->getWinner(), track);

            if(newRound->getWinner() == "Human") {
                score.setScore(HUMAN);
                cout << "Human won!\n";
            }
            else if(newRound->getWinner() == "Computer") {
                score.setScore(COMPUTER);
                cout << "Computer won!\n";
            }
            else if(newRound->getWinner() == "Tie") {
                score.setScore(TIE);
                cout << "Tie!\n";
            }

            winner = newRound->getWinner();

            delete newRound;
            delete computer;

            return winner;
            // printScoreBoard(track, 3);
        }
    
        int getRound() {
            cout << "round = " << m_round << endl;
            return m_round;
        }

        int getPlayerScore(int player) {
            return score.getScore(player);
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
                    item ="Rock";
                    break;
                case 2:
                    item = "Paper";
                    break;
                case 3:
                    item = "Scissor";
                    break;
                default:
                    item = "Error";
            }
            return item;
        }

        string getString(queue<int> q)
        {
            stringstream s;
            queue<int> temp = q;
            while (!temp.empty())
            {
                s << temp.front();
                cout << "s = " << s.str() << endl;
                cout << "temp.front() = " << temp.front() << endl;
                temp.pop();
            }
            return s.str();
        }

        int getComputerChoice() {
            return computer_choice;
        }

        ~RPS() {}
    protected:
    private:
        int track[3] = {0};
        int m_round;
        int computer_choice;
        Scoreboard score;
        queue<int> choices;
        map<string, int> m;

};
  
    // RandomChooser Random;
    // MachineLearningChooser ML;
        
	// vector<string> moveSequence; // vector of strings to hold past move sequences
	// vector<int> freq; // vector of ints to hold frequencies of each sequence

	//Read in sequences and their frequencies from the text file
	//readFreq(moveSequence, freq);

// void r_RockPaperScissor() {

	// TODO: Implement different computer player depending on game mode selected (random or ML)

	// Human *player = new Human();
	// Computer *computer = new Computer();
	// Round *newRound = new Round();

	// // Scoreboard
	// int track[3] = {0};

	// for (int i = 0; i < 20; i++) {
	// 	cout << "Round #" << i + 1 << endl;
	// 	player->setMove_rand();
	// 	computer->setMove_rand();
	// 	cout << "You played [" << convert(player->getMove()) << "]" << endl;
	// 	cout << "The computer played [" << convert(computer->getMove()) << "]" << endl;
	// 	newRound->setWinner(newRound->detWinner(player->getMove(), computer->getMove()));
	// 	cout << "The winner is [" << newRound->getWinner() << "]" << endl << endl;
	// 	scoreBoard(newRound->getWinner(), track);
	// 	printScoreBoard(track, 3);
	// }
// }


// void printScoreBoard(int* arr, int size) {
// 	cout << "Player           Computer            Tie" << endl;
// 	for (int i = 0; i < size; i++) {
// 		cout << "  " << arr[i] << "               ";
// 	}
// 	cout << endl << endl;
// }

// void scoreBoard(string winner, int* position){
// 	if (winner == "Player") {
// 		position[0]++;
// 	}
// 	else if (winner == "Computer") {
// 		position[1]++;
// 	}
// 	else {
// 		position[2]++;
// 	}
// }

// string convert(int move){
// 	string item;
// 	switch(move){
// 		case 1:
// 			item ="Paper";
// 			break;
// 		case 2:
// 			item = "Scissor";
// 			break;
// 		case 3:
// 			item = "Rock";
// 			break;
// 		default:
// 			item = "Error";
// 	}
// 	return item;
// }

// string getString(queue<char> q)
// {
// 	string s;
// 	queue<char> temp = q;
// 	while (!temp.empty())
// 	{
// 		s += temp.front();
// 		temp.pop();
// 	}
// 	return s;
// }
// void writeFreq(const vector<string> &sequence, const vector<int> &frequency) {
// 	ofstream freqfile;

// 	size_t size = sequence.size();
// 	// cout << "sequence size = " << size << endl;

// 	freqfile.open("freqfile.txt");

// 	if(freqfile.is_open()) {
// 		for(int i = 0; i < size; i++) {
// 			freqfile << sequence[i] << " " << frequency[i] << endl; 
// 		}
// 		freqfile << "End of writeFreq" << endl;
// 	}
// 	else
// 	{
// 		cout << "Error! File not open.\n" << endl;
// 	}
	
// 	freqfile.close();
// }

// void readFreq(vector<string> &sequence, vector<int> &frequency) {
// 	ifstream freqfile;
// 	string line = "";
// 	string move_sequence = "";
// 	string freq = "";

// 	freqfile.open("freqfile.txt");
	
// 	if(freqfile.is_open()) 
// 	{
// 		while(getline(freqfile, line)) 
// 		{
// 			for(string::iterator it = line.begin(); it != line.end(); ++it) 
// 			{
// 				if(*it >= 'A' && *it <= 'Z') {
// 					move_sequence += *it;
// 				}
// 				else if (*it >= '0' && *it <= '9') {
// 					freq += *it;
// 				}
// 			}
// 			sequence.push_back(move_sequence); // Store history of past N moves (N=5 in this case)
// 			frequency.push_back(stoi(freq)); // Store frequency of sequence history[i] at frequency[i]
// 			move_sequence = "";
// 			freq = "";
// 		}
// 		cout << "Finished reading frequency file!\n" << endl; // DEBUG
// 	}
// 	else {
// 		cout << "Error! File not open.\n" << endl;
// 	}

// 	freqfile.close();
// }
