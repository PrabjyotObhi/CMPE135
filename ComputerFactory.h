#include "Computer.h"
#include "Move.h"

class RandomComputer : public Computer
{
    public:
        RandomComputer() {}

        void setMove() {
            // generate a random number and mod it with 4 to get the value of the computer move (1 == paper, 2 == scissors, 3 == rock)
            // int move = rand() % 4;
            
            // while (move == 0){
            //     move = rand() % 4;
            // }
            
            // m_move = move;

            RandomMove random;
            random.makeChoice();
            m_move = random.getChoice();
        }

        ~RandomComputer() {}
    private:
};

class MachineLearnComputer : public Computer
{
    public:
        MachineLearnComputer(int move) {
            machine_move = move;
        }

        void setMove() {
            MachineMove machine;
            machine.makePrediction(machine_move);
            machine.makeChoice();
            m_move = machine.getChoice();
        }

        ~MachineLearnComputer() {}
    private:
        int machine_move = 0;
};