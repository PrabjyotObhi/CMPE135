#include <iostream>

enum {
    HUMAN, COMPUTER, TIE
};

class Scoreboard {
    public:
        Scoreboard() {
            std::cout << "Creating scoreboard...\n";
        }

        void setScore(int winner) {
            if(winner == HUMAN) score[HUMAN]++;
            else if (winner == COMPUTER) score[COMPUTER]++;
            else if (winner == TIE) score[TIE]++;
            else std::cout << "Error: invalid winner\n";

            // std::cout << "winner = " << winner << std::endl;
            // std::cout << "Total score of winner = " << score[winner] << std::endl;
            // std::cout << score[0] << " " << score[1] << " " << score[2] << std::endl;
        }

        int getScore(int player) {
            if(player == HUMAN) return score[HUMAN];
            else if(player == COMPUTER) return score[COMPUTER];
            else if(player == TIE) return score[TIE];
            else return -1; // Simple error flag
        }
        
        ~Scoreboard() {
            std::cout << "Deleting scoreboard...\n";
        }
    private:
        int score[3] = {0};
};