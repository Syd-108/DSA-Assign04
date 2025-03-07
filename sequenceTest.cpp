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
        if (objectNum == 1)
        {
            s1.start();
            cout << "s1 started." << endl;
        }
        else
        {
            s2.start();
            cout << "s2 started." << endl;
        }
        break;

    case '&':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            s1.end();
            cout << "s1 ended." << endl;
        }
        else
        {
            s2.end();
            cout << "s2 ended." << endl;
        }
        break;

    case '+':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            if (s1.is_item())
            {
                s1.advance();
                cout << "s1 advanced one item." << endl;
            }
            else
                cout << "Can't advance s1." << endl;
        }
        else
        {
            if (s2.is_item())
            {
                s2.advance();
                cout << "s2 advanced one item." << endl;
            }
            else
                cout << "Can't advance s2." << endl;
        }
        break;

    case '-':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            if (s1.is_item())
            {
                s1.move_back();
                cout << "s1 moved back one item." << endl;
            }
            else
                cout << "Can't move back s1." << endl;
        }
        else
        {
            if (s2.is_item())
            {
                s2.move_back();
                cout << "s2 moved back one item." << endl;
            }
            else
                cout << "Can't move back s2." << endl;
        }
        break;

    case '?':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            if (s1.is_item())
                cout << "s1 has a current item." << endl;
            else
                cout << "s1 has no current item." << endl;
        }
        else
        {
            if (s2.is_item())
                cout << "s2 has a current item." << endl;
            else
                cout << "s2 has no current item." << endl;
        }
        break;

    case 'C':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            if (s1.is_item())
                cout << "Current item in s1 is: " << s1.current() << endl;
            else
                cout << "s1 has no current item." << endl;
        }
        else
        {
            if (s2.is_item())
                cout << "Current item in s2 is: " << s2.current() << endl;
            else
                cout << "s2 has no current item." << endl;
        }
        break;

    case 'P':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            cout << "s1 contains: ";
            show_list(s1);
        }
        else
        {
            cout << "s2 contains: ";
            show_list(s2);
        }
        break;

    case 'A':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            numHold = get_number();
            s1.add(numHold);
            cout << numHold << " added to s1." << endl;
        }
        else
        {
            charHold = get_character();
            s2.add(charHold);
            cout << charHold << " added to s2." << endl;
        }
        break;

    case 'R':
        objectNum = get_object_num();
        if (objectNum == 1)
        {
            if (s1.is_item())
            {
                numHold = s1.current();
                s1.remove_current();
                cout << numHold << " removed from s1." << endl;
            }
            else
                cout << "s1 has no current item." << endl;
        }
        else
        {
            if (s2.is_item())
            {
                charHold = s2.current();
                s2.remove_current();
                cout << charHold << " removed from s2." << endl;
            }
            else
                cout << "s2 has no current item." << endl;
        }
        break;

    case 'Q':
        cout << "Quit option selected...bye" << endl;
        break;

    default:
        cout << choice << " is invalid...try again" << endl;

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
