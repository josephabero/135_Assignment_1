#ifndef SCORE_HPP
#define SCORE_HPP

class Score
{
    public:
    Score();
    void setScore(int score);
    void incrementScore();
    int const getScore();

    private:
    int score; 
};

#endif