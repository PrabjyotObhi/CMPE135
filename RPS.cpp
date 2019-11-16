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
        
            scoreBoard(newRound->getWinner(), track);
            
            if(newRound->getWinner() == "Human") 
            {
                score.setScore(HUMAN);
            }
            else if(newRound->getWinner() == "Computer") 
            {
                score.setScore(COMPUTER);
            }
            else if(newRound->getWinner() == "Tie") 
            {
                score.setScore(TIE);
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
        	
       		player->setMove(move);
            
            if (choices.size() >= 5)
            {
                choices.pop();
            }

            choices.push(player->getMove()); //push player move

            computer->setParams(getString(choices), m);
            computer->setMove();
            computer_choice = computer->getMove();
            
            player_prediction = computer->getPlayerPrediction();
            
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

            newRound->setWinner(newRound->detWinner(player->getMove(), computer->getMove()));
            scoreBoard(newRound->getWinner(), track);

            if(newRound->getWinner() == "Human") 
            {
                score.setScore(HUMAN);
            }
            else if(newRound->getWinner() == "Computer") 
            {
                score.setScore(COMPUTER);
            }
            else if(newRound->getWinner() == "Tie") 
            {
                score.setScore(TIE);
            }

            winner = newRound->getWinner();

            delete newRound;
            delete computer;

            return winner;
        }
    
        int getRound() 
        {
            return m_round;
        }

        int getPlayerScore(int player) 
        {
            return score.getScore(player);
        }

        void printScoreBoard(int* arr, int size) 
        {
            cout << "Player           Computer            Tie" << endl;
            for (int i = 0; i < size; i++) {
                cout << "  " << arr[i] << "               ";
            }
            cout << endl << endl;
        }

        void scoreBoard(string winner, int* position)
        {
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
                temp.pop();
            }
            return s.str();
        }

        int getComputerChoice() {
            return computer_choice;
        }

        int getPlayerPrediction() {
            return player_prediction;
        }

        ~RPS() {}
    protected:
    private:
        int track[3] = {0};
        int m_round;
        int computer_choice;
        int player_prediction;
        Scoreboard score;
        queue<int> choices;
        map<string, int> m;

};