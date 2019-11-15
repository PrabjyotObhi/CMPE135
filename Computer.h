
#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Computer : public Player {
    public:
        // Default constructor
        Computer() {}

        void setMove_rand() {
            //generate a random number and mod it with 4 to get the value of the computer move (1 == paper, 2 == scissors, 3 == rock)
            int move = rand() % 4;
            
            while (move == 0){
                move = rand() % 4;
            }
            
            m_move = move;
        }

        map<string, int> m;
    string currentWindow;

    vector<string> keyToList(map<string, int> m)
    {
        vector<string> v;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            v.push_back(it->first);
            cout << it->first << "\n";
        }
        return v;
    }

    void setParams(string currentWindow, map<string, int> m)
    {
        this->m = m;
        this->currentWindow = currentWindow;
    }
    void setMove()
    {
        //generate a random number and mod it with 4 to get the value of the computer move (1 == paper, 2 == scissors, 3 == rock)
        string choice = currentWindow.substr(0, 4);

        vector<string> v = keyToList(m);
        int maxVal = 0;
        int index = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].substr(0, 4) == choice)
            {
                if (m[v[i]] > maxVal)
                {
                    maxVal = m[v[i]];
                    index = i;
                }
            }
        };
        if (index > -1)
        {
            string playerChoice = v[index].substr(4, 1);
            if (playerChoice == "\001")
            {
                m_move = 2;
            }
            else if (playerChoice == "\002")
            {
                m_move = 3;
            }
            else if (playerChoice == "\003")
            {
                m_move = 1;
            }
        }
        else
        {
            // random
            int move = rand() % 4;

            while (move == 0)
            {
                move = rand() % 4;
            }

            m_move = move;
        }
    }

    int getMove()
    {
        return m_move;
    }
        
        // Destructor
        ~Computer() {
            cout << "deleting computer object...\n";
        };
    private:
};

#endif /* COMPUTER_H */

