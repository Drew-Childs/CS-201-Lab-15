//Drew Childs, Lab 15
#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

list<char> fillList(string input_string) {		//populates list with each element in the string
	list<char> temp_list;
	
	for (int i = 0; i < input_string.length(); i++) {
		temp_list.push_back(input_string[i]);
	}

	return temp_list;
}

void printList(ofstream &output, list<char> input_list) {		//outputs list
	for (list<char>::iterator iter = input_list.begin(); iter != input_list.end(); iter++) {
		output << "[" << *iter << "] -> ";
	}

	output << "0" << endl << endl;
}

list<char> removeCharacter(char remove, list<char> input_list) {		//removes character
	input_list.remove(remove);
	input_list.remove(toupper(remove));

	return input_list;
}

int main() {
	list<char> curr_word;		//opening files/declaring variables/lists
	string read_word;
	ifstream words("input.txt");
	ofstream output("output.txt");

	while (true) {
		getline(words, read_word);		//reading in word

		if (read_word == "END") {		//exits loop
			break;
		}

		curr_word = fillList(read_word);		//puts each character into list

		curr_word = removeCharacter('a', curr_word);		//removing vowels
		curr_word = removeCharacter('e', curr_word);
		curr_word = removeCharacter('i', curr_word);
		curr_word = removeCharacter('o', curr_word);
		curr_word = removeCharacter('u', curr_word);

		printList(output, curr_word);		//printing word list
	}

	words.close();		//closing files
	output.close();
}