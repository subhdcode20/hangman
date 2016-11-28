#include <bits/stdc++.h>
using namespace std;

void hanging(int state);
void game(string word);

int main() {
	cout<<"            ********************************               "<<endl;
	cout<<"                  HANGMAN BY SUBHdCODE                      "<<endl;
	cout<<"            ********************************               "<<endl;
	string input;
	char c;
	int count = 0;
	ifstream file("ask");
	getline(file, input);
	file.close();

	game(input);
	return 0;
}


void game(string word) {
	int hangs=7;
	char guess;
	string display = word;
	for(size_t i=0; i<display.length(); i++) {
		display[i] = '*';
	}
	cout<<endl<<" || guess the charecters of the word hidden by \"*\" 1 by 1! || "<<endl;
	cout<<" -- "<<display<<" -- "<<endl;
	cout<<" || you have 15 guesses and 7 hangs to comlete the word.  || "<<endl;
	cout<<" || for each wrong guess you increase your hangs. || "<<endl;
	cout<<" || exceeding the number of hangs ... you shal be hanged!!  || "<<endl;
	cout<<"PLAY-->"<<endl;
	int n=15;
	bool win_lose;
	while(1) {
		bool input = false;
		cout<<"enter your guess :";
		cin>>guess;
		n--;
		if(n==0){
			cout<<"         no more guesses left!!      "<<endl;
			cout<<"******** you lose ********"<<endl;
			win_lose = true;
			break;
		}

		for(int i=0; i<word.length(); i++) {
			if(guess == word[i]) {
				display[i] = word[i];
				input = true;
			}

		}
		if(input == true) {
			cout<<"******* good guess *******"<<endl;
			cout<<display<<endl;

			if(display.find("*") == string::npos) {
				cout<<"********* YOU WIN!!!! **********"<<endl;
				cout<<"      CONGRATULATIONS!!      "<<endl;
				win_lose = true;
				break;
			}
			cout<<"hangs left : "<<hangs<<endl;
		}



		//	}
			else {
				hangs--;
				if(hangs == 0) {
					cout<<"******** you lose ********"<<endl;
					cout<<"******** you are hanged ********"<<endl;
					win_lose = true;
					cout<<endl;
					hanging(hangs);
					cout<<endl;
					break;
				}
				else {
					cout<<"******* bad guess *******"<<endl;
					cout<<"hangs left : "<<hangs<<endl;
					cout<<endl;
					hanging(hangs);
					cout<<endl;
				}
			}

		}

		if(win_lose == true) {
			cout<<"Thanks for playing..!"<<endl;
			//getch();
			//break;
		}


	return;
}



void hanging(int state) {
	switch(state) {
		case 6 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"  ============="<<endl<<endl;
			break;
		case 5 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |    O  "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"  ============="<<endl<<endl;
			break;
		case 4 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |    O  "<<endl
			<<"   |    |  "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"  ============="<<endl<<endl;
			break;
		case 3 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |    O  "<<endl
			<<"   |   /|  "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"  ============="<<endl<<endl;
			break;
		case 2 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |    O  "<<endl
			<<"   |   /|\\ "<<endl
			<<"   |       "<<endl
			<<"   |       "<<endl
			<<"  ============="<<endl<<endl;
			break;
		case 1 :
			cout<<endl<<endl
			<<"   +----+  "<<endl
			<<"   |    |  "<<endl
			<<"   |    O  "<<endl
			<<"   |   /|\\ "<<endl
			<<"   |     \\ "<<endl
			<<"   |       "<<endl
			<<"  ============"<<endl<<endl;
			break;
		case 0 :
			cout<<endl<<endl
		  <<"   +----+     "<<endl
		  <<"   |    |     "<<endl
		  <<"   |    O     "<<endl
		  <<"   |   /|\\   "<<endl
		  <<"   |   / \\   "<<endl
		  <<"   |You are Dead "<<endl
		  <<"  ============"<<endl<<endl;
			break;
	}
	return;
}
