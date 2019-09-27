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

        void setChoice(int move) {
            m_move = move;
        }

        // Getters
        int getScore() {
            return m_score;
        }

        int getMove() {
            return m_move;
        }

        // Destructor (note: make virtual if making subclasses)
        ~Player();
    private:
        int m_score;
        int m_move;
};