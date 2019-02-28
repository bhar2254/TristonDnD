// Blaine Harper
// Intro to OOP - TristonDnD
// 2-28-19

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Options
{
public:
	void set_text(string str)
	{
		text = str;
	}
	void set_next(int a)
	{
		next = a;
	}
	string get_text()
	{
		return text;
	}
	int get_next()
	{
		return next;
	}
private:
	string text;
	int next;
};

int main()
{
	Options zone[64];
	int number_of_zones = 0;
  	string line;
  	ifstream options_file ("options.txt");
  	if (options_file.is_open())
  	{
  		int i = 0;
		int j = 0;

    	while ( getline (options_file,line) )
    	{
    		std::stringstream ss(line);
			std::vector<string> result;

    		while( ss.good() )
			{
			    std::string substr;
			    getline( ss, substr, ',' );
			    result.push_back(substr);
			}

			zone[i].set_text(result.at(0));
			zone[i].set_next(std::stoi(result.at(1)));
			number_of_zones++;
			i++;
    	}
    	options_file.close();
  	}

  	for(int i = 0; i < number_of_zones; i++)
  	{
  		cout << zone[i].get_text() << endl;
  	}
	return 0;
}