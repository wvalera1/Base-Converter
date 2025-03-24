//=============================================
// Walter Valera
// convert.cpp
// 28 Jan 2025
// Base number conversion program that operates
// from the commmand line
//=============================================

#include <iostream>
#include <map>
using namespace std;

//=============================================
// function declarations section
//=============================================

int to_base_10 ( string s , int base );

string from_base_10 ( int num, int base );

string convert ( string s , int b1, int b2 );

bool validString ( string s, int base);

//=============================================
//=============================================

int main ( int argc, char *argv[] )
{

	// process the command line arguments
	string s;			// string of input number
	int b1; 			// base of input number
	int b2;				// desired target base
	if ( argc < 3 )
	{
		cout << "Missing command line arguments.  Usage:\n";
		cout << "convert  x  b1  b2\n";
		exit(0);
	}
	s = string(argv[1]);
	b1 = atoi(argv[2]);
	if ( argc == 4 )
		b2 = atoi(argv[3]);
		
	// you can uncomment out this line to check that
	// you've read in the right command line params
	// printf("convert [%s] [%d] [%d]\n",s.c_str(),b1,b2);
	
	// rest of program here

    // Check b1 and b2 are valid bases
	if ( b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16) {
		cerr << "Error: Invalid base(s). Must be between 2 and 16" << endl;
		exit(1);

    // Check if s is expressed using valid digits for the base
	} else if (!validString(s, b1)) {
        cerr << "Error: Invalid input string" << endl;
        exit(1);

    // Print conversion result
    } else {
        cout << s << "_" << b1 << " = " << convert(s, b1, b2) << "_" << b2 << endl; 
    }


	return 0;
}

//=============================================
// function definitions section
//=============================================

// Letter-Number Conversions
    map<char, int> lmap = {
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'D', 13},
        {'E', 14},
        {'F', 15}
    };


// Convert to base 10
int to_base_10 ( string s , int base ) {
	int val = 0;
	for ( char i : s ) {
		val *= base;
        if (isdigit(i)) { // If i is a number
            val += i - '0'; // Subtact ASCII value from i
        } else if (lmap.find(i) != lmap.end()) { // If a letter is present in s
            val += lmap[i]; // Replace the letter with it's numerical equivalent
        }
	}

	return val;
} 

// Number-Letter Conversions
    map<int, char> nmap = {
        {10, 'A'},
        {11, 'B'},
        {12, 'C'},
        {13, 'D'},
        {14, 'E'},
        {15, 'F'}
    };

// Convert from base 10
string from_base_10 ( int num , int base ) {
    if (num == 0) {
        return "0";
    }
	string str = "";
	while ( num > 0 ) {
        int r = num%base;
        if (r >= 10) { // remainder >= 10 must be expressed with a letter 
            str = nmap[r] + str;
        } else {
            str = to_string(r) + str; // Else add remainder to str
        }
		num = num / base;
	}

	return str;
}

// Main conversion function
string convert ( string s , int b1, int b2 ) {

	// if b1 != 10, convert it to base 10, then b2
	if (b1 != 10) {
		int b1_to_base10 = to_base_10(s, b1);
		string result = from_base_10(b1_to_base10, b2);
		return result;

	} else {
	// else, convert from b1 to b2 
		int num = stoi(s); // Convert string to an int type
		string result = from_base_10(num, b2);
		return result;
	}

}

// Check if our string s ie expresesd using valid digits for the base
bool validString(string s, int base) {
    for (char i : s) {
        if (isdigit(i)) { // If i is a number
            if (i - '0' >= base) { // Subtract ASCII value from i, then check if >= base
                return false;
            }
        } else if (lmap.find(i) != lmap.end()) { // If i is a letter
            if (lmap[i] >= base) { // Check if it's number conversion is >= base
                return false;
            }
        } else { // If it's not a letter or a number
            return false;
        }
    }
    return true;
}
