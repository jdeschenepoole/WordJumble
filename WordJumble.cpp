// Title: Word Jumble
// By: Joseph Deschene-Poole
// Student Number: 100064439
// Date: September 26, 2007
// Description: The classic word jumble game where the player can ask for a hint
//              The program reads the words and hints from a text file
//              It automatically exits upon getting the right answer

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    string word1, word2, word3, word4, word5;
    string hint1, hint2, hint3, hint4, hint5;
    
    //opens file and reads from it
    ifstream myfile ("words.txt");
    if (myfile.is_open())
    {
       while (! myfile.eof() )
       {
            getline (myfile, word1);
	        getline (myfile, hint1);
	        getline (myfile, word2);
	        getline (myfile, hint2);
	        getline (myfile, word3);
	        getline (myfile, hint3);
	        getline (myfile, word4);
	        getline (myfile, hint4);
	        getline (myfile, word5);
	        getline (myfile, hint5);
       }
       myfile.close();
  }

  else cout << "Unable to open file"; 
    
    
    string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
       {word1, hint1},
       {word2, hint2},
       {word3, hint3},
       {word4, hint4},
       {word5, hint5}
    };
    


  	srand(time(0));
	int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  // word to guess
    string theHint = WORDS[choice][HINT];  // hint for word

    string jumble = theWord;  // jumbled version of word
    int length = jumble.size();
    for (int i=0; i<length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
            cout << theHint;
        else
            cout << "Sorry, that's not it.";

        cout <<"\n\nYour guess: ";
        cin >> guess;
    }

    if (guess == theWord)
        cout << "\nThat's it!  You guessed it!\n";

    cout << "\nThanks for playing.\n";

    return 0;
}
