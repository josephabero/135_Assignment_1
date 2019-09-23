using namespace std;

class Computer: public Player
{
public:
	void generateOption()
	{
		// generate random option
		setOption(dynamic_cast<Option>(rand() % 3));
	}
}