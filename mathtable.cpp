#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void disp_tableMenu(string filename = "");
void table(const int a, const char type = '+', ostream& out = cout);

int int_input = 0;
string input, file_name;
ofstream to_file;
bool open_file = false;

int main( void )
{
	bool exit_main = false;
	cout << "\n\t\tComplex number class program" << endl; //program start statement
	while (!exit_main) {
		disp_tableMenu(file_name);
		cout << "\n\tChoice: ";
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (tolower(input[0])) {
		case '0': {
			cout << "\n(Type \"exit\" to return to menu and remove file name)";
			cout << "\nPlease enter the name of your data file: ";
			do {
				input.clear();
				getline(cin, input);
				if (input == "exit") {
					to_file.close();
					to_file.clear();
					file_name = "";
					open_file = false;
					break;
				}
				to_file.open(input);
				if (to_file) {
					file_name = input;
					open_file = true;
					cout << "\nFile \"" << file_name << "\" opened successfully!" << endl;
				} else {
					to_file.close();
					to_file.clear();
					file_name = "";
					open_file = false;
					cout << "\nInvalid file name.\n\nPlease enter another name: ";
				}
			} while (!to_file && file_name != "exit");
			break;
		} case '1': {
			cout << "\nWhat size should the addition table be? ";
			int_input = 0;
			cin >> int_input;
			if (int_input > 0 && int_input <= 20) {
				if (open_file) {
					cout << "\nCalculating..." << endl;
					table(int_input, '+', to_file);
					cout << "\nWritten to file." << endl;
				} else {
					cout << "\nCalculating..." << endl;
					table(int_input, '+');
				}
			} else if (int_input <= 0) {
				cout << "\nI'm sorry, the table size must be greater than zero." << endl;
			} else if (int_input > 20) {
				cout << "\nI'm sorry, " << int_input << " is too large of an addition table." << endl;
			}
			break;
		} case '2': {
			cout << "\nWhat size should the subtraction table be? ";
			int_input = 0;
			cin >> int_input;
			if (int_input > 0 && int_input <= 20) {
				if (open_file) {
					cout << "\nCalculating..." << endl;
					table(int_input, '-', to_file);
					cout << "\nWritten to file." << endl;
				}
				else {
					cout << "\nCalculating..." << endl;
					table(int_input, '-');
				}
			}
			else if (int_input <= 0) {
				cout << "\nI'm sorry, the table size must be greater than zero." << endl;
			}
			else if (int_input > 20) {
				cout << "\nI'm sorry, " << int_input << " is too large of a table." << endl;
			}
			break;
		} case '3': {
			cout << "\nWhat size should the multiplication table be? ";
			int_input = 0;
			cin >> int_input;
			if (int_input > 0 && int_input <= 20) {
				if (open_file) {
					cout << "\nCalculating..." << endl;
					table(int_input, '*', to_file);
					cout << "\nWritten to file." << endl;
				}
				else {
					cout << "\nCalculating..." << endl;
					table(int_input, '*');
				}
			}
			else if (int_input <= 0) {
				cout << "\nI'm sorry, the table size must be greater than zero." << endl;
			}
			else if (int_input > 20) {
				cout << "\nI'm sorry, " << int_input << " is too large of a table." << endl;
			}
			break;
		} case '4': {
			cout << "\nWhat size should the division table be? ";
			int_input = 0;
			cin >> int_input;
			if (int_input > 0 && int_input <= 20) {
				if (open_file) {
					cout << "\nCalculating..." << endl;
					table(int_input, '/', to_file);
					cout << "\nWritten to file." << endl;
				}
				else {
					cout << "\nCalculating..." << endl;
					table(int_input, '/');
				}
			}
			else if (int_input <= 0) {
				cout << "\nI'm sorry, the table size must be greater than zero." << endl;
			}
			else if (int_input > 20) {
				cout << "\nI'm sorry, " << int_input << " is too large of a table." << endl;
			}
			break;
		} case '5': {
			cout << "\nWhat size should the remainder table be? ";
			int_input = 0;
			cin >> int_input;
			if (int_input > 0 && int_input <= 20) {
				if (open_file) {
					cout << "\nCalculating..." << endl;
					table(int_input, '%', to_file);
					cout << "\nWritten to file." << endl;
				}
				else {
					cout << "\nCalculating..." << endl;
					table(int_input, '%');
				}
			}
			else if (int_input <= 0) {
				cout << "\nI'm sorry, the table size must be greater than zero." << endl;
			}
			else if (int_input > 20) {
				cout << "\nI'm sorry, " << int_input << " is too large of a table." << endl;
			}
			break;
		} case '6': case 'e': {
			exit_main = true;
			break;
		} default: {
			cout << "\nInvalid Choice." << endl;
			break;
		}
		}
	}
	cout << "\nExiting program." << endl; //program end statement
	to_file.close();
	to_file.clear();
	return 0;
}

void disp_tableMenu(string filename) {
	cout << "\n\t\tTable Menu" << endl; 
	cout << "\n\t0) Output to file: ";
	if (filename != "") {
		cout << "\"" << filename << "\"";
	} else {
		cout << "NONE";
	}
	cout << "\n\t1) Addition table";
	cout << "\n\t2) Subtraction table";
	cout << "\n\t3) Multiplication table";
	cout << "\n\t4) Division table";
	cout << "\n\t5) Remainder table";
	cout << "\n\t6) exit" << endl;
	return;
}

void table(const int a, const char type, ostream& out) {
	long long width;
	if (type != '+' && type != '-' && type != '*' && type != '/' && type != '%') {
		out << "Error making table" << endl;
		return;
	} else {
		width = ((type == '+') ? (static_cast<long long>(log10(2 * abs(a))) + 2)
			: (type == '-') ? (static_cast<long long>(log10(abs(a) - 1)) + 3)
			: (type == '*') ? (static_cast<long long>(log10(abs(a) * abs(a))) + 2)
			: (type == '/' || type == '%') ? (static_cast<long long>(log10(abs(a))) + 2)
			: (0));
		out << endl << setfill(' ') << setw(width) << type << " |" << ((type == '/') ? ("  ") : (""));
		for (int i = 1; i <= abs(a); i++) {
			out << setfill(' ') << setw(width) << i << ((type == '/') ? ("    ") : (""));
		}
		out << '\n' << setfill('-') << setw(width + 2) << "+"; //doesnt change
		out << setfill('-') << (((type != '/') ? (setw((static_cast<long long>(abs(a)) * width) + 1))
			: (setw((static_cast<long long>(abs(a)) * (width + 4)) + 1)))) << '-' << endl;
		for (int i = 1; i <= abs(a); i++) {
			out << setfill(' ') << setw(width) << i << " |";
			for (int n = 1; n <= abs(a); n++) {
				if (type == '/') {
					out << setfill(' ') << setw(width) << i / n << '.';
					out << setfill('0') << setw(3) << (static_cast<int>((1000 * i) / n) - 1000 * static_cast<int>(i / n));
				} else {
					out << setfill(' ') << setw(width) << ((type == '+') ? (i + n) : (type == '-') ? (i - n) : (type == '*') ? (i * n) : (i - n * static_cast<int>(i / n)));
				}
			}
			out << endl;
		}
	}
	return;
}