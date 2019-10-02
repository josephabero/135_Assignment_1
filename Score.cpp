#include "Score.hpp"

Score::Score()
{
    score = 0;
}
void Score::setScore(int score)
{
    this->score = score;
}
void Score::incrementScore()
{
    score++;
}
int const Score::getScore()
{
    return score;
}