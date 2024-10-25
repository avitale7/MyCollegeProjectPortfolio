#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <math.h>
#include <cmath>
#include <time.h>
#include <string>
#include <cstring>
#include <xstring>
#include <array>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <functional> 
#include "genarr.h"

//#include "String\strextra.h"
//#include "String\strcls.h"
//#include "String\handy.h"
//#include "String\input.h"
//#include "String\menu.h"

using namespace std;

const size_t MAX = 16;

template < typename DataType > inline void output(const DataType& data, ostream& os = std::cout) {
    os << data << endl;
};
template < class ArrT > inline void output(const ArrT& arr, long size, ostream& os = std::cout) {
    os << "{ ";
    for (long i = 0; i < size; i++) {
        os << arr[i] << ((i != size - 1) ? (", ") : (" }"));
    };
    os << endl;
};

//make into functions print, add, uppercase
// for applying
template < typename DataType > void print(DataType& data) { cout << data << " | "; return; };
template < typename DataType > void addfour(DataType& x) { x += 4; return; };
template < typename DataType > void uppercase(DataType& data) { data = toupper(data); return; };

// for accumulating
template < typename DataType > DataType add(DataType& x, DataType& y) { return x + y; };
template < typename DataType > DataType subtract(DataType& x, DataType& y) { return x - y; };
string append(const string& x, const string& y) { return x + ' ' + y; }

//make into objects print, add, sum
template < typename DataType > class example_print
{
    
public:
    example_print(void) { return; }
    template < typename DataType > ostream& operator() (DataType output, ostream& os = std::cout) { return os << output << " "; }
};
template < typename DataType > class example_add
{
    DataType addend;
public:
    example_add(DataType add = 0) { addend = add; }
    example_add(const example_add& add) { addend = add.addend; }
    void operator() (DataType& add_to) { add_to += addend; return; }
};
template < typename DataType > class example_sum
{
    DataType sum;
public:
    example_sum(DataType s = 0) : sum{ s } { }
    DataType operator ( ) (void) const { return sum; }
    DataType operator ( ) (DataType data) { sum += data; return sum; }
    DataType operator ( ) (DataType* arr) { for (auto& i : arr) { sum += i; } return sum; }
    void reset(DataType s = 0) { sum = s; return; }
    friend ostream& operator<<(ostream& out, const example_sum& s) { out << s.sum; return out; }
};

int main()
{
    short output_MAX = 3; //outputs always output the first three of an array, to show changes
    cout << "\n\tIntegers" << endl;
    short int_total;
    short int_arr[MAX];
    for (unsigned short i = 0; i < MAX; i++) {
        int_arr[i] = i;
    }
    //  Integers
    //Print
    cout << "print() ";
    apply_fauto(int_arr, print<short>);
    cout << endl;
    output(int_arr, output_MAX);
    //Add 4
    cout << "add() ";
    apply_fauto(int_arr, addfour<short>);
    cout << endl;
    output(int_arr, output_MAX);
    //Obj Print
    cout << "example_print() ";
    apply_cauto(int_arr, example_print<short>());
    cout << endl;
    output(int_arr, output_MAX);
    //Obj Add 4
    cout << "example_add() ";
    apply_cauto(int_arr, example_add<short>(4));
    cout << endl;
    output(int_arr, output_MAX);
    //Obj Sum
    cout << "example_sum() ";
    apply_cauto(int_arr, example_sum<short>());
    cout << endl;
    output(int_arr, output_MAX);
    int_total = accumulate_cauto(int_arr, add<short>, static_cast<short>(0)); //Extra
    cout << "total: ";
    output(int_total);

    cout << "\n\tDoubles" << endl;
    double double_total;
    double double_arr[MAX];
    for (unsigned short i = 0; i < MAX; i++) {
        double_arr[i] = i + 0.1*i + 0.01;
    }
    //  Doubles
    //Print
    cout << "print() ";
    apply_fauto(double_arr, print<double>);
    cout << endl;
    output(double_arr, output_MAX);
    //Add 4
    cout << "add() ";
    apply_fauto(double_arr, addfour<double>);
    cout << endl;
    output(double_arr, output_MAX);
    //Obj Print
    cout << "example_print() ";
    apply_cauto(double_arr, example_print<double>());
    cout << endl;
    output(double_arr, output_MAX);
    //Obj Add 4
    cout << "example_add() ";
    apply_cauto(double_arr, example_add<double>(4.0));
    cout << endl;
    output(double_arr, output_MAX);
    //Obj Sum
    cout << "example_sum() ";
    apply_cauto(double_arr, example_sum<double>());
    cout << endl;
    output(double_arr, output_MAX);
    double_total = accumulate_cauto(double_arr, add<double>, 0.0); //Extra
    cout << "total: ";
    output(double_total);

    cout << "\n\tCharacters" << endl;
    double char_total;
    char char_arr[MAX];
    for (unsigned short i = 0; i < MAX; i++) {
        char_arr[i] = static_cast<char>(97 + i);
    }
    //  Characters
    //Print
    cout << "print() ";
    apply_fauto(char_arr, print<char>);
    cout << endl;
    output(char_arr, output_MAX);
    //Add 4
    cout << "add() ";
    apply_fauto(char_arr, addfour<char>);
    cout << endl;
    output(char_arr, output_MAX);
    //Uppercase
    cout << "uppercase() ";
    apply_fauto(char_arr, uppercase<char>);
    cout << endl;
    output(char_arr, output_MAX);
    //Obj Print
    cout << "example_print() ";
    apply_cauto(char_arr, example_print<char>());
    cout << endl;
    output(char_arr, output_MAX);
    //Obj Add 4
    cout << "example_add() ";
    apply_cauto(char_arr, example_add<char>(4));
    cout << endl;
    output(char_arr, output_MAX);
    //Obj Sum
    cout << "example_sum() ";
    apply_cauto(char_arr, example_sum<char>());
    cout << endl;
    output(char_arr, output_MAX);
    char_total = accumulate_cauto(char_arr, add<char>, ' '); //Extra
    cout << "total: ";
    output(char_total);

    cout << "\n\tStrings" << endl;
    string str_arr[MAX] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen"}, sentence = "";
    //  Strings
    //Print
    cout << "print() ";
    apply_fauto(str_arr, print<string>);
    cout << endl;
    output(str_arr, output_MAX);
    //Add 4
    cout << "add() ";
    apply_fauto(str_arr, addfour<string>);
    cout << endl;
    output(str_arr, output_MAX);
    //Obj Print
    cout << "example_print() ";
    apply_cauto(str_arr, example_print<string>());
    cout << endl;
    output(str_arr, output_MAX);
    //Obj Add 4
    cout << "example_add() ";
    apply_cauto(str_arr, example_add<string>("4"));
    cout << endl;
    output(str_arr, output_MAX);
    //Obj Sum
    cout << "example_sum() ";
    sentence = accumulate_cauto(str_arr, append, string()) + '.';
    cout << endl;
    cout << "Sentence: ";
    output(sentence);

	cout << "\nEnd of program" << endl;
	return 0;
}
/*
    Show your template functions' power by passing arrays of

short integers, doubles, chararacters, String class objects, all in one test application.

    Also test (as appropriate) passing functions that

print an element, add 4 to an element, uppercase an element
    
    Next test (as appropriate) by passing function objects which

print an element on a pre-specified stream (requires a reference data member in the function object class -- fun!),
add n to an element (show that this works for different values of n using the same function object!!),
summing all the elements, uppercase an element

    Note: Some tests may not be appropriate for apply and others may not be appropriate for accumulate. You must decide which.
*/