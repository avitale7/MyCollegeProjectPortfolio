#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <array>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void)
{
	srand(int(time(nullptr)));
	int amountOfDice, sidesOfDice, modifier, min, max, exampleDiceRoll;
	double avg;
	string endStrings[] = { "y","yes","yea","yepperooni","yes, I do, I most certainly do!","Y","YES","Yes","yEs","yES","yeS" };
	bool end;
	string endTester;
	cout << "\n                 Welcome to the Dice Statistics Program!!!\n";
	cout << "\ndice rolls are formated as such: ";
	cout << "\n 1d6+0 - one six sided dice with a modifier of 0.";
	cout << "\n 1d6+1 - one six sided dice with a modifier of +1.";
	cout << "\n 1d6-1 - one six sided dice with a modifier of -1.";
	cout << "\n 2d6+0 - two six sided dice with a modifier of 0.";
	cout << "\n1d20+0 - one twenty sided dice with a modifier of  0.\n";
	do {
		max = 2;
		cout << "\nWhat is your dice roll? ";
		cin >> amountOfDice;
		cin.ignore(1) >> sidesOfDice;
		if (cin.peek() == '+' || cin.peek() == '-') {
			cin >> modifier;
		} else {
			modifier = 0;
		}
		while (amountOfDice <= 0 || sidesOfDice < 2) {
			cout << "Please input a valid amount of dice and a valid amount of dice sides." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n') >> amountOfDice;
			cin.ignore(1) >> sidesOfDice; 
			if (cin.peek() == '+' || cin.peek() == '-') {
				cin >> modifier;
			} else {
				modifier = 0;
			}
		}
		cout << "\nThank you! Calculating...  ";
		if (sidesOfDice == 10 || sidesOfDice == 100) {
			min = 0; //ten sided dice has a minimum value of 0 
			max = sidesOfDice - 1; //ten sided dice has a maximum value of 9 
		}
		else {
			min = 1;
			max = sidesOfDice;
		}
		avg = 0;
		for (int i = 1; i < sidesOfDice + min; i++) {
			avg += i;
		}
		avg = avg / double(sidesOfDice);
		exampleDiceRoll = 0;
		for (int i = 0; i < amountOfDice; i++) {
			exampleDiceRoll += rand() % (max - min + 1) + min;
		}
		cout << "Done.\n";
		if (sidesOfDice == 10) {
			cout << "\nDid you know? ten sided dice have a minimum of 0 and a maximum of 9.\n";
		}
		if (sidesOfDice == 100) {
			cout << "\nDid you know? percentile dice have a minimum of 0 and a maximum of 99.\n";
		}
		cout << "\nWhen rolling " << amountOfDice << "d" << sidesOfDice;
        if (modifier != 0) {
		    cout << setw(int(floor(log10(modifier)))+2) << setfill('+') << modifier;
        }
		cout << " (" << amountOfDice << " " << sidesOfDice << " sided dice";
        if (modifier != 0) {
            cout << " with a modifier of " << modifier;
        }
        cout << "), your statistics will be: \n";
		cout << "\n  Minimum: " << min * amountOfDice + modifier;
		cout << "\n  Average: " << avg * amountOfDice + modifier;
		cout << "\n  Maximum: " << max * amountOfDice + modifier << endl;
		cout << "\nA typical dice roll might result in " << exampleDiceRoll + modifier << ".\n";
		cout << "\nThank you for using the DSP!!\n";
		cout << "\nEndeavor to have an extemporaneous day!\n";
		end = true;
		cout << "\nWould you like to roll another dice? ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n') >> endTester;
		for (int exit = 0; exit < 11; exit++) {
			if (endTester == endStrings[exit]){
				end = false;
			}
		}
	} while (end == false);
	return 0;
}
