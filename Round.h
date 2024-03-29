#include <string>

class Round {
    public:
        // Default constructor
        Round() {
            m_winner = "";
        };

        // Determine winner of round
        std::string detWinner(int playerMove, int computerMove) {
            std::string winner;
            
            if (playerMove == computerMove){
                winner = "Tie";
            }
            else if(playerMove == 1 && computerMove == 2){
                winner = "Computer";
            }
            else if (playerMove == 1 && computerMove ==3){
                winner = "Human";
            }
            else if (playerMove ==2 && computerMove == 1){
                winner = "Human";
            }
            else if (playerMove ==2 && computerMove == 3){
                winner = "Computer";
            }
            else if (playerMove == 3 && computerMove == 1){
                winner = "Computer";
            }
            else if (playerMove == 3 && computerMove == 2){
                winner = "Human";
            }
            return winner;
        }

        // Getter
        std::string getWinner() {
            return m_winner;
        }
        
        // Mutator
        void setWinner(std::string winner) {
            m_winner = winner;
        }

        ~Round() {
            cout << "deleting round object...\n";
        }

    private:
        std::string m_winner;

};