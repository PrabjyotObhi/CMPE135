#ifndef PLAYER_H
#define PLAYER_H

// Abstract class Player
class Player{
    public:
        // Default constructor
        Player() {
            m_score = 0;
        }

        // Mutators
        void setScore(int score) {
            m_score = score; 
        }

        virtual void setMove() = 0;

        // Getters
        int getScore() {
            return m_score;
        }

        int getMove() {
            return m_move;
        }

        // Destructor (note: make virtual if making subclasses)
        virtual ~Player() {};
    private:
        int m_score;
    protected:
        int m_move;
};

#endif