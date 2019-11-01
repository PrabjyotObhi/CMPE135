#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
    public:
        Move() {}

        virtual void makeChoice() = 0;

        int getChoice() {
            return choice;
        }

        virtual ~Move() {}
    protected:
        int choice;
};

class RandomMove : public Move {
    public:
        RandomMove() {}

        void makeChoice() {
            int move = rand() % 4;
            
            while (move == 0){
                move = rand() % 4;
            }
            
            choice = move;
        }

        ~RandomMove() {}
    private:
};

class MachineMove : public Move {
    public:
        MachineMove() {}

        void makePrediction(int move) {
            machine_prediction = move;
        }

        void makeChoice() {
            choice = machine_prediction;
        }

        ~MachineMove() {}
    private:
        int machine_prediction;
};
#endif