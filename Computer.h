#include <iostream>
#include "Player.h"

class Computer : public Player {
    public:
        // Default constructor
        Computer() {}

        void setMove() {
            //generate a random number and mod it with 4 to get the value of the computer move (1 == paper, 2 == scissors, 3 == rock)
            int move = rand() % 4;
            
            while (move == 0){
                move = rand() % 4;
            }
            
            m_move = move;
        }

        // Destructor
        ~Computer() {};
    private:
};