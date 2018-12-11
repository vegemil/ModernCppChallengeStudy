//49. Text histogram
//Write a program that, given a text, determines and prints a histogram with the frequency of each letter of the alphabet.The frequency is the percentage of the number of appearances of each letter from the total count of letters.
//The program should count only the appearances of letters and ignore digits, signs, and other possible characters.The frequency must be determined based on the count of letters and not the text size.


#include "gsl/gsl"
// create `main` function for catch
#define CATCH_CONFIG_MAIN   
#include "catch2/catch.hpp"

// Redirect CMake's #define to C++ constexpr string
constexpr auto TestName = PROJECT_NAME_STRING;


#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>

//I am extending the std::map so that 
class WordHistogram : public std::map<std::string, int> {
	std::string &toLowerString(std::string &word) {
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); });
		return word;
	}
public:

	//we want to overload the operator[] so that we only look at lowercase versions.
	// note the logic for this came from the sgi STL implementaion
	// source available here: www.sgi.com/tech/stl/stl_map.h
	int &operator[](std::string word) {
		word = toLowerString(word); // conver the word to lower case
		iterator it = lower_bound(word); //it->first will be the first key >= word or it==end()
		if (it == this->end() || word != it->first) { //is the word in the map already?
			it = this->insert(it, value_type(word, 0)); //if not, add it to the map.
		}
		return it->second;
	}
};

void displayResults(WordHistogram words) {
	WordHistogram::iterator it;
	for (WordHistogram::iterator it = words.begin(); it != words.end(); it++) {
		std::cout << it->first << " - " << it->second << std::endl;
	}
}


#include <sstream> //used for testing
using namespace std;

string removePunct(string& str) {
	string result = "";
	for (size_t i = 0; i < str.length(); i++) {
		if (isalpha(str[i])) {
			result += str[i];
		}
	}
	return result;
}

TEST_CASE("Text histogram") {
	// A string to test with...
	string testStr = "It was the best of times, it was the worst of times;\n"
		"it was the age of wisdom, it was the age of foolishness;\n"
		"it was the epoch of belief, it was the epoch of incredulity;\n"
		"it was the season of Light, it was the season of Darkness;\n"
		"it was the spring of hope, it was the winter of despair;\n"
		"we had everything before us, we had nothing before us;\n"
		"we were all going directly to Heaven, we were all going the other way\n";
	istringstream input(testStr);
	WordHistogram histogram;
	string word;
	while (input >> word) {
		word = removePunct(word);
		histogram[word]++;
		//To watch results add up.
		//cout << word << " -- " << histogram[word] << endl;
	}
	cout << "\nResults:\n----------------------------" << endl;
	displayResults(histogram);
}