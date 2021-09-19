/* ----------------------------------------------------------------------
    Program 2: Great 13
        Peg puzzle. Jump pegs to try and leave only a single peg.

    Course: CS 141, Fall 2021. Tues 10am lab
    System: Mac using Atom
    Author: Mark Penovich

   ----------------------------------------------------------------------
*/

#include <iostream>
#include <cctype>   // for toupper()
using namespace std;

char pA, pB, pC, pD, pE, pF, pG, pH, pI, pJ, pK, pL, pM;
char moveFrom, moveOver, moveTo;
int moveNumber;
int numberOfPieces;

// Display the game instructions.
void displayInstructions()
{
    cout << "Class: CS 141             \n"
         << "Program: #2 Great 13      \n"
         << "  \n"
         << "Make a series of jumps until there is a single piece left in the   \n"
         << "middle. On each move you must jump an adjacent piece into an empty \n"
         << "square, jumping horizontally, vertically, or diagonally.           \n"
         << "Input of 'R' resets the board back to the beginning, and input of  \n"
         << "'X' exits the game.'   \n"
         << endl;
} //end displayInstructions()

// Display the board, using the global variables pA..pM
void displayBoard()
{
    cout <<"\n "
         <<                 "    Board   " <<            " Position \n"
         <<"       "             << pA <<             "          A    \n"
         <<"     " <<      pB<<" "<<pC<<" "<<pD<<       "      B C D  \n"
         <<"   "<<pE<<" "<<pF<<" "<<pG<<" "<<pH<<" "<<pI<<"  E F G H I\n"
         <<"     " <<      pJ<<" "<<pK<<" "<<pL<<       "      J K L  \n"
         <<"       "             << pM <<             "          M    \n"
         << endl;
} //end displayBoard()

/*
displayErrorMessage() prints out errors.
Error codes:
  1. *** Pieces must be adjacent. Please retry
  2. *** Source must have a piece. Please retry
  3. *** Must jump a piece. Please retry
  4. *** Destination must be blank. Retry
*/
void displayErrorMessage(int errorCode)
{
  switch (errorCode) {
    case 1:
      cout << "\n" << "   *** Pieces must be adjacent. Please retry" << "\n" << endl;
      break;
    case 2:
      cout << "\n" << "   *** Source must have a piece. Please retry" << "\n" << endl;
      break;
    case 3:
      cout << "\n" << "   *** Must jump a piece. Please retry" << "\n" << endl;
      break;
    case 4:
      cout << "\n" << "   *** Destination must be blank. Retry" << "\n" << endl;
      break;
    default:
      break;
  }
} // end displayErrorMessage()


/*
 Each boardPiece() function represents all possible moves that its respective
 letter can make. We also checks for errors and then print out the neseccary
 error message that we get from the displayErrorMessage() function.
*/

/*
Board Piece: A
Legal moves: ABE, ACG, ADI
*/
void boardPieceA()
{
  if (moveOver == 'B' && moveTo == 'E') { // Check one of the possible moves (ABE).
    if (pB == '#') { // Check if the moveOver piece exists.
      if (pE == '.') { // Check if the moveTo piece is empty.
        pB = '.'; // If all conditions are met, assign the moveOver piece '.' to its respective variable to signify empty board piece
        pA = '.'; // Assign the moveFrom piece to its respective variable
        pE = '#'; // Assign the moveTo piece a '#' to its respective variable
        moveNumber++; // Add one to the moveNumber variable
        numberOfPieces--; // Remove one from our numberOfPieces variable
        displayBoard(); // Display updated board
      } else {
        displayErrorMessage(4); // Display "*** Destination must be blank. Retry" if moveTo is not blank
      }
    } else {
      displayErrorMessage(3); // Display "*** Must jump a piece. Please retry" if moveOver does not contain a piece #
    }
  } else if (moveOver == 'C' && moveTo == 'G') { // Check one of the possible moves (ACG). etc etc.
    if (pC == '#') {
      if (pG == '.') {
        pC = '.';
        pA = '.';
        pG = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'D' && moveTo == 'I') {
    if (pD == '#') {
      if (pI == '.') {
        pD = '.';
        pA = '.';
        pI = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceA()

/*
Board Piece: B
Legal moves: BCD, BGL, BFJ
*/
void boardPieceB()
{
  if (moveOver == 'C' && moveTo == 'D') {
    if (pC == '#') {
      if (pD == '.') {
        pC = '.';
        pB = '.';
        pD = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'G' && moveTo == 'L') {
    if (pG == '#') {
      if (pL == '.') {
        pG = '.';
        pB = '.';
        pL = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'F' && moveTo == 'J') {
    if (pF == '#') {
      if (pL == '.') {
        pF = '.';
        pB = '.';
        pL = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceB()

/*
Board Piece: C
Legal moves: CGK
*/
void boardPieceC()
{
  if (moveOver == 'G' && moveTo == 'K') {
    if (pG == '#') {
      if (pK == '.') {
        pG = '.';
        pC = '.';
        pK = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceC()

/*
Board Piece: D
Legal moves: DCB, DGJ, DHL
*/
void boardPieceD()
{
  if (moveOver == 'C' && moveTo == 'B') {
    if (pC == '#') {
      if (pB == '.') {
        pC = '.';
        pD = '.';
        pB = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'G' && moveTo == 'J') {
    if (pG == '#') {
      if (pJ == '.') {
        pG = '.';
        pD = '.';
        pJ = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'H' && moveTo == 'L') {
    if (pH == '#') {
      if (pL == '.') {
        pH = '.';
        pD = '.';
        pL = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceD()

/*
Board Piece: E
Legal moves: EBA, EFG, EJM
*/
void boardPieceE()
{
  if (moveOver == 'B' && moveTo == 'A') {
    if (pB == '#') {
      if (pA == '.') {
        pB = '.';
        pE = '.';
        pA = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'F' && moveTo == 'G') {
    if (pF == '#') {
      if (pG == '.') {
        pF = '.';
        pE = '.';
        pG = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'J' && moveTo == 'M') {
    if (pJ == '#') {
      if (pM == '.') {
        pJ = '.';
        pE = '.';
        pM = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceE()

/*
Board Piece: F
Legal moves: FGH
*/
void boardPieceF()
{
  if (moveOver == 'G' && moveTo == 'H') {
    if (pG == '#') {
      if (pH == '.') {
        pG = '.';
        pE = '.';
        pH = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceF()

/*
Board Piece: G
Legal moves: GHI, GKM, GFE, GCA
*/
void boardPieceG()
{
  if (moveOver == 'H' && moveTo == 'I') {
    if (pH == '#') {
      if (pI == '.') {
        pH = '.';
        pG = '.';
        pI = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'K' && moveTo == 'M') {
    if (pK == '#') {
      if (pM == '.') {
        pK = '.';
        pG = '.';
        pM = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'F' && moveTo == 'E') {
    if (pF == '#') {
      if (pE == '.') {
        pF = '.';
        pG = '.';
        pE = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'C' && moveTo == 'A') {
    if (pC == '#') {
      if (pA == '.') {
        pC = '.';
        pG = '.';
        pA = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceG()

/*
Board Piece: H
Legal moves: HGF
*/
void boardPieceH()
{
  if (moveOver == 'G' && moveTo == 'F') {
    if (pG == '#') {
      if (pF == '.') {
        pG = '.';
        pH = '.';
        pF = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceH()

/*
Board Piece: I
Legal moves: IDA, IHG, ILM
*/
void boardPieceI()
{
  if (moveOver == 'D' && moveTo == 'A') {
    if (pD == '#') {
      if (pA == '.') {
        pD = '.';
        pI = '.';
        pA = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'H' && moveTo == 'G') {
    if (pH == '#') {
      if (pG == '.') {
        pH = '.';
        pI = '.';
        pG = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'L' && moveTo == 'M') {
    if (pL == '#') {
      if (pM == '.') {
        pL = '.';
        pI = '.';
        pM = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceI()

/*
Board Piece: J
Legal moves: JFB, JGD, JKL
*/
void boardPieceJ()
{
  if (moveOver == 'F' && moveTo == 'B') {
    if (pF == '#') {
      if (pB == '.') {
        pF = '.';
        pJ = '.';
        pB = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'G' && moveTo == 'D') {
    if (pG == '#') {
      if (pD == '.') {
        pG = '.';
        pJ = '.';
        pD = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'K' && moveTo == 'L') {
    if (pK == '#') {
      if (pM == '.') {
        pK = '.';
        pJ = '.';
        pM = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceJ()

/*
Board Piece: K
Legal moves: KGC
*/
void boardPieceK()
{
  if (moveOver == 'G' && moveTo == 'C') {
    if (pG == '#') {
      if (pC == '.') {
        pG = '.';
        pK = '.';
        pC = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceK()

/*
Board Piece: L
Legal moves: LKJ, LGB, LHD
*/
void boardPieceL()
{
  if (moveOver == 'K' && moveTo == 'J') {
    if (pK == '#') {
       if (pJ == '.') {
         pK = '.';
         pL = '.';
         pJ = '#';
         moveNumber++;
         numberOfPieces--;
       } else {
         displayErrorMessage(4);
       }
      displayBoard();
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'G' && moveTo == 'B') {
    if (pG == '#') {
      if (pB == '.') {
        pG = '.';
        pL = '.';
        pB = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'H' && moveTo == 'D') {
    if (pH == '#') {
      if (pD == '.') {
        pH = '.';
        pL = '.';
        pD = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceL()

/*
Board Piece: M
Legal moves: MJE, MKG, MLI
*/
void boardPieceM(){
  if (moveOver == 'J' && moveTo == 'E') {
    if (pJ == '#') {
      if (pE == '.') {
        pJ = '.';
        pM = '.';
        pE = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'K' && moveTo == 'G') {
    if (pK == '#') {
      if (pG == '.') {
        pK = '.';
        pM = '.';
        pG = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else if (moveOver == 'L' && moveTo == 'I') {
    if (pL == '#') {
      if (pI == '.') {
        pL = '.';
        pM = '.';
        pI = '#';
        moveNumber++;
        numberOfPieces--;
        displayBoard();
      } else {
        displayErrorMessage(4);
      }
    } else {
      displayErrorMessage(3);
    }
  } else {
     displayErrorMessage(1);
  }
} // end boardPieceM()


// Check the user input 'moveFrom' to see if it is a valid move, if it is call its respective boardPiece() function
// If the source does not have a piece on it display error message 2
void checkMove()
{
  switch (moveFrom) {
    case 'A':
      (pA == '#') ? boardPieceA() : displayErrorMessage(2);
      break;
    case 'B':
      (pB == '#') ? boardPieceB() : displayErrorMessage(2);
      break;
    case 'C':
      (pC == '#') ? boardPieceC() : displayErrorMessage(2);
      break;
    case 'D':
      (pD == '#') ? boardPieceD() : displayErrorMessage(2);
      break;
    case 'E':
      (pE == '#') ? boardPieceE() : displayErrorMessage(2);
      break;
    case 'F':
      (pF == '#') ? boardPieceF() : displayErrorMessage(2);
      break;
    case 'G':
      (pG == '#') ? boardPieceG() : displayErrorMessage(2);
      break;
    case 'H':
      (pH == '#') ? boardPieceH() : displayErrorMessage(2);
      break;
    case 'I':
      (pI == '#') ? boardPieceI() : displayErrorMessage(2);
      break;
    case 'J':
      (pJ == '#') ? boardPieceJ() : displayErrorMessage(2);
      break;
    case 'K':
      (pK == '#') ? boardPieceK() : displayErrorMessage(2);
      break;
    case 'L':
      (pL == '#') ? boardPieceL() : displayErrorMessage(2);
      break;
    case 'M':
      (pM == '#') ? boardPieceM() : displayErrorMessage(2);
      break;
  }
}

// ----------------------------------------------------------------------
// Main section of the program, containing the game play loop
int main() {
    displayInstructions();

    // Set board values to the default starting position
    pA=pB=pC=pD=pE=pF=pH=pI=pJ=pK=pL=pM='#';
    pG='.';
    numberOfPieces = 12;
    moveNumber = 1;

    // Game play loop
    displayBoard();
    while(numberOfPieces > 1) {
        cout << moveNumber << ". " << "Enter positions from, jump, and to (e.g. EFG): "; // Read just the first user input, handling inputs 'X' or 'R'
        cin >> moveFrom;
        moveFrom = toupper(moveFrom);

        // Check for user input x which ends the game.
        if (moveFrom == 'X') {
            cout << "Exiting" << endl << endl;
            cout << "Better luck next time." << endl;
            break;
        }

        // Check for user input r which resets the game.
        if (moveFrom == 'R') {
            cout << "\n" << "   *** Restarting" << endl;
            pA=pB=pC=pD=pE=pF=pH=pI=pJ=pK=pL=pM='#';
            pG='.';
            numberOfPieces = 12;
            moveNumber = 1;
            displayBoard();
            continue;
        }

        // Assign user input to its respective variable.
        cin >> moveOver >> moveTo;

        // Uppercase characters so its easier to handle in logic.
        moveOver = toupper(moveOver);
        moveTo = toupper(moveTo);

        checkMove();
     } //end while( numberOfPieces > 1)

     // Display winning message if user successfully navigates the game
     if(numberOfPieces <= 1) {
       cout << "\n" << "Congratulations, you did it!" << endl;
     }

    cout << "Done." << endl;
    return 0;
} //end main()



// if (moveFrom == 'A') {
//
//   // if (pA == '#') {
//   //
//   //   boardPieceA();
//   // } else {
//   //   displayErrorMessage(2);
//   // }
// } else if (moveFrom == 'B') {
//   if (pB == '#') {
//     boardPieceB();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'C') {
//   if (pC == '#') {
//     boardPieceC();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'D') {
//   if (pD == '#') {
//     boardPieceD();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'E') {
//   if (pE == '#') {
//     boardPieceE();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'F') {
//   if (pF == '#') {
//     boardPieceF();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'G') {
//   if (pG == '#') {
//     boardPieceG();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'H') {
//   if (pH == '#') {
//     boardPieceH();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'I') {
//   if (pI == '#') {
//     boardPieceI();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'J') {
//   if (pJ == '#') {
//     boardPieceJ();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'K') {
//   if (pK == '#') {
//     boardPieceK();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'L') {
//   if (pL == '#') {
//     boardPieceL();
//   } else {
//     displayErrorMessage(2);
//   }
// } else if (moveFrom == 'M') {
//   if (pM == '#') {
//     boardPieceM();
//   } else {
//     displayErrorMessage(2);
//   }
// }
