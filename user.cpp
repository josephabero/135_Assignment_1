// #include "user.hpp"

// using namespace std;

// void User::setName(string name)
// {
// 	username = name;
// }

// string User::getName()
// {
// 	return username;
// }
#include "option.cpp"

class User : public Player
{
public:
    User(string username, Option option, int score = 0) : username(username), Player(option, score)
    {}

    void setName(string name)   { username = name }
    string getName()            { return username }

private:
    string username;
};