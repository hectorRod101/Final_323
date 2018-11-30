#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	string filename;
	string line;
	ifstream input;
	
	cout << "Enter filename: ";
	cin >> filename;
	input.open(filename);

	if(!input.is_open()){
		cout << "ERROR....Unable to open file.";
		exit(0);
	}

	while (getline(input, line) && !input.eof()) {
		cout << line << endl;
	}

	input.close();
	return 0;
}