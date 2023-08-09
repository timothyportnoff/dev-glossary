#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "flashcard.cc"
using std::string;

void strip_leading_space(std::string& str){ str.erase(0, str.find_first_not_of(' ')); }

void strip_trailing_space(std::string& str){ str.erase(str.find_last_not_of(' ') + 1); }

void strip_space(std::string& str){ 
	std::string return_str;
	for (size_t i = 0; i < str.size(); i++) { 
		if (str[i] != ' ') return_str += str[i]; 
	} 
	str = return_str;
}

void die(string msg = "Program exiting.") {
	std::cout << "\nERROR! " << msg << std::endl;
	exit(1);
}
					
void study_glossary(std::vector<Flashcard>& glossary) {
	
}

std::vector<Flashcard> make_flashcards() {
	std::vector<Flashcard> glossary;
	return glossary;
}

std::vector<Flashcard> load_glossary(string file_name) {
	std::vector<Flashcard> glossary;
	std::fstream file(file_name);
	if (!file) die("Couldn't grab file to load glossary.");
	string front, back;
	while (file) {
		getline(file, front, ':');
		std::cout << front << std::endl;
		getline(file, back, '\n');
		std::cout << back << std::endl;
		Flashcard card(front, back);
		glossary.push_back(card);
	}
	std::cout << "Glossary loaded!" << std::endl;
	return glossary;
}

int main(int argc, char* argv[]) {
	int choice = -1;
	std::string file_name;
	std::vector<Flashcard> glossary;
	if (argc >= 3) die("Insufficient command-line arguments provided.");
	if (argc == 2) {
		glossary = load_glossary(argv[1]);
	}
	if (argc == 1) {
		std::cout << "Welcome to Dev-Glossary." << std::endl;
		while(choice != 0) {
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1) Study Glossary" << std::endl;
			std::cout << "2) Load Glossary" << std::endl;
			std::cout << "3) Create Glossary" << std::endl;
			std::cout << "4) Do something else???" << std::endl;
			std::cout << "0) Exit Program." << std::endl;
			std::cin >> choice;
			switch (choice) {
				case 0: 
					return 0;
					break;
				case 1: 
					study_glossary(glossary);
					break;
				case 2: 
					std::cout << "Enter the name of the file you would like to open." << std::endl;
					std::cin >> file_name;
					glossary = load_glossary(file_name);
					break;
				case 3: 
					std::cout << "Enter the name of the file you would like to create." << std::endl;
					std::cin >> file_name;
					break;
				case 4: 
					std::cout << "There is nothing else to do. Go study." << std::endl;
					break;
				default: 
					std::cout << "Not a valid option. Please choose again." << std::endl;
					break;
			}
		}
	}
	return 0;
}
