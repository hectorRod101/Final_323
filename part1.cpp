#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	string filename;
	string line ;

	char current;
	char meme[2];
	int tracker = 0;
	ifstream input;
	ofstream output;


	//cout << "Enter filename: ";
	//cin >> filename;
	input.open("/Users/albertorocha/Documents/GitHub/Final_323/finalp1.txt");
	output.open("/Users/albertorocha/Documents/GitHub/Final_323/output.txt");

	if(!input.is_open()){
		cout << "ERROR....Unable to open input file.";
		exit(0);
	}
	if(!output.is_open()){
		cout << "ERROR....Unable to open output file.";
		exit(0);
	}

	while (!input.eof() ) {

		input.get(current);


			if(current == '/' || current == '*'){

				if (tracker >= 2){
					tracker = 0;
				}
				meme[tracker] = current;

				tracker ++;

			}
			else if( meme[0] == '/' && meme[1]== '/'){

				if(current == '\n') {
					meme[0]= ' ';
					meme[1] = ' ';

				}
			}
			else if( meme[0] == '/' && meme[1]== '*'){



			}
			else if (meme[0] == '*' && meme[1]== '/'){
				meme[0]=' ';
				meme[1] = ' ';
			}

			else if(current !=' ') {

				line += current;
			}


			if(current == '\n' || current == '\0') {

				output << line;
				line = "";
			}

	}

output << '\n' << line;


	input.close();
	output.close();
	return 0;
}