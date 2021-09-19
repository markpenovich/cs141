#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int choice;
  int numberOfSections = 0;

  cout << "Choose from among the following options:" << endl;
  cout << "1. Display original graphic" << endl;
  cout << "2. Display Gladiolus" << endl;
  cout << "3. Exit the program" << endl;
  cout << "Your choice -> ";
  cin >> choice;

  if (choice == 1) {
      cout << setw( 8) << " ";
      // Display a line across the top
      for( int i=0; i<42; i++) {
         cout << "-";
      }
      cout << endl;

      // Display ASCII graphics for "Flame + UIC".
      cout << setw( 8) << " " << "                           /\\            \n"
           << setw( 8) << " " << "                 /\\       /  \\           \n"
           << setw( 8) << " " << "        /\\      /  \\     /    \\          \n"
           << setw( 8) << " " << "       /  \\    /    \\   /      \\     \n"
           << setw( 8) << " " << "      /    \\  /      \\ /        \\   \n"
           << setw( 8) << " " << "      \\    \\/        \\/          \\   \n"
           << setw( 8) << " " << "       \\                           \\      \n"
           << setw( 8) << " " << "        \\                           \\    \n"
           << setw( 8) << " " << "         \\                           \\    \n"
           << setw( 8) << " " << "          \\                           \\   \n"
           << setw( 8) << " " << "          \\                            /     \n"
           << setw( 8) << " " << "  /\\     /                            /     \n"
           << setw( 8) << " " << " /  \\   /                            /        \n"
           << setw( 8) << " " << "/    \\ /                             \\       \n"
           << setw( 8) << " " << "\\                                     \\       \n"
           << setw( 8) << " " << " \\                                     \\      \n"
           << setw( 8) << " " << "  \\                                     |      \n"
           << endl;

     cout << setw( 8) << " " << "               _______       _____               \n"
          << setw( 8) << " " << "   |       |      |        /                   \n"
          << setw( 8) << " " << "   |       |      |        |                 \n"
          << setw( 8) << " " << "   |       |      |        |              \n"
          << setw( 8) << " " << "   |       |      |        |             \n"
          << setw( 8) << " " << "    \\_____/    ___|___     \\_____                \n"
          << endl;
      cout << setw( 8) << " ";
      // Display a line across the bottom
      for( int i=0; i<42; i++) {
          cout << "-";
      }
      cout << endl;
  } else if (choice == 2) {
    // Take in user input for # of sections
    cout << "Number of sections -> ";
    cin >> numberOfSections;

    // Create whitespace for section markers
    string whitespace;
    for (int i = 0; i < numberOfSections; i++) {
      whitespace += " ";
    }
    cout << whitespace << "---" << endl;

    // Center used to keep track of positioning, decreases by 1 every loop
    int center = numberOfSections;
    // Create each section of flower
    for (int i = 0; i < numberOfSections; i++) {

      for (int j = 0; j < i; j++) {
        cout << setw(numberOfSections - j) << "(" << setw(j + 2) << " " << setw(j + 2) << ")" << endl;
      }

      cout << setw(center) << "(" << setw(i + 2) << "@" << setw(i + 2) << ")" << endl;

      for (int j = i; j > 0; j--) {
        cout << setw(numberOfSections - j + 1) << "(" << setw(j + 1) << " " << setw(j + 1) << ")" << endl;
      }

      cout << whitespace << "---" << endl;
      center--;
    }

    // Create stem with alternating leaves
    for (int i = 0; i < numberOfSections; i++) {
      if (i % 2) {
        cout << whitespace << "\\|" << endl;
        cout << whitespace << " |" << endl;
      } else {
        cout << whitespace << " |/" << endl;
        cout << whitespace << " |" << endl;
      }
    }

  } else if (choice == 3) {
    exit(0);
  }

  cout << "Exiting" << endl;
  return 0;
}




/* ---------------------------------------------
    Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
        above each other.

    Course: CS 141, Fall 2021. Tues 5pm lab
    System: Mac using Xcode
    Author: Dale Reed

    Original ASCII graphics gives:
       ------------------------------------------
           ______     _____
          /          /     \      /   /    /    /
         /          |            /   /    /    /
        |            ---        /    -----    /
        |               \      /        /    /
         \_____   \_____/     /        /    /

        ------------------------------------------

   ---------------------------------------------
*/
