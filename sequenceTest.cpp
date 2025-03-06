// FILE: sequenceTest.cpp
// An interactive test program for the sequence class

#include <cctype>      // provides toupper
#include <iostream>    // provides cout and cin
#include <cstdlib>     // provides EXIT_SUCCESS
#include "sequence.h"
using namespace std;

// PROTOTYPES for functions used by this test program:

#include <iostream>
#include <cctype>
#include "sequence.h"
using namespace std;

// Function Prototypes
void print_menu();
char get_user_command();
int get_object_num();
double get_number();
char get_character();

template <typename T>
void show_list(sequence<T> src);

int main()
{
    sequence<double> s1;  // sequence of doubles
    sequence<char> s2;    // sequence of characters
    char choice;
    int objectNum;
    double numHold;
    char charHold;

    cout << "Sequences s1 (double) and s2 (char) created empty." << endl;

    do
    {
        print_menu();
        choice = toupper(get_user_command());

        switch(choice)
        {
            case '!':
                objectNum = get_object_num();
                (objectNum == 1) ? s1.start() : s2.start();
                cout << "Sequence " << objectNum << " started." << endl;
                break;
            case '&':
                objectNum = get_object_num();
                (objectNum == 1) ? s1.end() : s2.end();
                cout << "Sequence " << objectNum << " ended." << endl;
                break;
            case '+':
                objectNum = get_object_num();
                if (objectNum == 1 && s1.is_item()) s1.advance();
                else if (objectNum == 2 && s2.is_item()) s2.advance();
                else cout << "Cannot advance." << endl;
                break;
            case '-':
                objectNum = get_object_num();
                if (objectNum == 1 && s1.is_item()) s1.move_back();
                else if (objectNum == 2 && s2.is_item()) s2.move_back();
                else cout << "Cannot move back." << endl;
                break;
            case '?':
                objectNum = get_object_num();
                cout << ((objectNum == 1 ? s1.is_item() : s2.is_item())
                        ? "Has item." : "No current item.") << endl;
                break;
            case 'C':
                objectNum = get_object_num();
                if (objectNum == 1 && s1.is_item()) cout << "Current item: " << s1.current() << endl;
                else if (objectNum == 2 && s2.is_item()) cout << "Current item: " << s2.current() << endl;
                else cout << "No current item." << endl;
                break;
            case 'P':
                objectNum = get_object_num();
                (objectNum == 1) ? show_list(s1) : show_list(s2);
                break;
            case 'A':
                objectNum = get_object_num();
                if(objectNum == 1) s1.add(get_number());
                else s2.add(get_character());
                break;
            case 'R':
                objectNum = get_object_num();
                if (objectNum == 1 && s1.is_item()) s1.remove_current();
                else if (objectNum == 2 && s2.is_item()) s2.remove_current();
                else cout << "No current item to remove." << endl;
                break;
            case 'Q':
                cout << "Exiting..." << endl; break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while(choice != 'Q');
}

void print_menu()
{
    cout << "! Start\n& End\n+ Advance\n- Move Back\n? Check Current\n"
         << "C Current item\nP Print sequence\nA Add\nR Remove\nQ Quit\n";
}

char get_user_command()
{
    char command;
    cout << "Choice: "; cin >> command;
    return command;
}

template <typename T>
void show_list(sequence<T> src)
{
    for(src.start(); src.is_item(); src.advance())
        cout << src.current() << " ";
    cout << endl;
}

int get_object_num()
{
    int num;
    cout << "Enter sequence (1 for double, 2 for char): ";
    cin >> num;
    return num;
}

double get_number()
{
    double num;
    cout << "Enter number: "; cin >> num;
    return num;
}

char get_character()
{
    char ch;
    cout << "Enter character: ";
    cin >> ch;
    return ch;
}
