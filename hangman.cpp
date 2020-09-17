#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

void printBlankSpaces(string word)
{
    int wordLength = word.size();
    cout << "Spaces of empty word: ";
    for (int i = 0; i < wordLength; i++)
        word[i] != ' ' ? cout << "_ " : cout << " ";
    cout << endl;
}

bool letterInWord(char letter, string word)
{
    int wordLength = word.length();
    for (int i = 0; i < wordLength; i++)
    {
        int position = word[i];
        if (word[i] != letter)
        {
            position++;
        }
        if (word[i] == letter)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string word = "ensalada";

    //Fix wierd bug when using words between 7-9 characters

    int wordLength = word.length();

    char emptyCharArray[wordLength + 1];
    emptyCharArray[wordLength] = '\0';

    // Print empty spaces for the word
    printBlankSpaces(word);

    // Ask user for letter
    char letter;

    for (int i = 0; i < wordLength; i++)
    {

        if (word[i] == ' ')
            emptyCharArray[i] = ' ';
        else
            emptyCharArray[i] = '_';
    }

    // Draw body test
    string bodyParts[7] = {"   O", " _-^-_", "|  |  |", "   |", "  | |", " _| |_"};
    int numberOfMistakes = sizeof(bodyParts) / sizeof(bodyParts[0]);

    int wrongAnswers = 0;

    while (emptyCharArray != word)
    {
        cout << "Please enter a letter: " << endl;
        cin >> letter;
        cout << endl;
        if (letterInWord(letter, word) == true)
        {
            cout << "___" << endl
                 << "   |" << endl;
            for (int i = 0; i <= wrongAnswers; i++)
            {
                cout << bodyParts[i] + " " << endl;
            }

            cout << endl
                 << "Wrong guess. You guessed: " << letter << endl;
            cout << endl;
            wrongAnswers++;
            cout << "Wrong number guesses: " << wrongAnswers << endl
                 << endl;
        }
        if (wrongAnswers == numberOfMistakes - 1)
        {
            cout << "Ran out of guesses, play again soon!" << endl
                 << endl;
            return 0;
        }

        // Find better method to see if char is in string
        if (letterInWord(letter, word) == false)
        {

            for (int i = 0; i < wordLength; i++)
            {

                // int comparePosition = compareArray[i];
                int position = word[i];

                if (letter != position)
                {
                    position++;
                }
                else if (letter == position)
                {
                    emptyCharArray[i] = letter;
                }
            }
        }
        cout << emptyCharArray << endl;
    }
    cout << endl
         << "Congrats, you won! The word was: " << emptyCharArray << endl
         << "Play again soon!" << endl;
    ;

    return 0;
}