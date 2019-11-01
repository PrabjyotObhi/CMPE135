#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include "Player.h"

class Human : public Player {
    public:
        // Default constructor
        Human() {}

        void setMove_rand() {
            
            int move = 0;
            
            // Implement counter in future version, if user fails to set valid move, forfeit round
            int counter = 0;

            std::cout << "Please enter 1 for paper, 2 for scissors, or 3 for rock:" << std::endl;
            std::cin >> move;

            //Makes sure the move is valid for our set of moves
            while (!(move >= 1 && move <= 3)) {
                std::cout << "Invalid Move, Please try again" << std::endl;
                std::cin >> move;
            }
            m_move = move;
        }

        // Destructor
        ~Human() {};
    private:
};

#endif /* HUMAN_H */

