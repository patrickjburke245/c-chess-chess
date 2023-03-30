#include <iostream>
#include <string>
//#include <gtk/gtk.h>

using namespace std;

const int board_dimension = 8;

class Game {
    public:
        string board[board_dimension][board_dimension] = {
            {"R1", "N1", "B1", "Q1", "K1", "B1", "N1", "R1"},
            {"P1", "P1", "P1", "P1", "P1", "P1", "P1", "P1"},
            {"__", "__", "__", "__", "__", "__", "__", "__"},
            {"__", "__", "__", "__", "__", "__", "__", "__"},
            {"__", "__", "__", "__", "__", "__", "__", "__"},
            {"__", "__", "__", "__", "__", "__", "__", "__"},
            {"P2", "P2", "P2", "P2", "P2", "P2", "P2", "P2"},
            {"R2", "N2", "B2", "Q2", "K2", "B2", "N2", "R2"}
        };

        char sourceLetter;
        int sourceNumber;

        char destinationLetter;
        int destinationNumber;

        int sourceIndex[2] = {0, 0};
        int destinationIndex[2] = {0, 0};

        //typedef struct {char letter, int number} position;

        void acceptUserInputSource() {
            cout << "Choose the square of the piece that you'd like to move ({Letter}{#}): ";
            cin >> sourceLetter >> sourceNumber;
            cout << "You specified " << sourceLetter << sourceNumber << ".\n";
        }

        void unitConverterSource() {
            sourceIndex[1] = sourceLetter - 65;
            sourceIndex[0] = 8-sourceNumber;
            cout << "This translates to index = " << sourceIndex[0] << ", " << sourceIndex[1] << "\n";
        }

        void unitConverterDestination() {
            destinationIndex[1] = destinationLetter - 65;
            destinationIndex[0] = 8-destinationNumber;
            cout << "This translates to index = " << destinationIndex[0] << ", " << destinationIndex[1] << "\n";
        }
        
        void acceptUserInputDestination() {
            cout << "Where do you want to move it? ";
            cin >> destinationLetter >> destinationNumber;
            if (destinationLetter != sourceLetter) {
                cout << "You cannot move diagonally.";
            }
        }

        void moveKing() {
            /* Only allow king to move 1 spot
            pseudo code
            if offset
            
            */
            
            if (board[destinationIndex[0]][destinationIndex[1]].find('_') != string::npos) {
                string temp = board[sourceIndex[0]][sourceIndex[1]];
                board[sourceIndex[0]][sourceIndex[1]] = board[destinationIndex[0]][destinationIndex[1]];
                board[destinationIndex[0]][destinationIndex[1]] = temp;
            } else {
                cout << "Illegal move - there is another piece in your way.\n";
            }
            
        }

        void movePawn() {
            //take user input for location of their pawn
            //scrub user input.. if not in range (0-7/8, or not valid pawn location, ask them to re-enter.
            //tell them to stop trolling)
            //if pawn never been moved before.. well then allow user to move it 2 turns
            string temp = board[sourceIndex[0]][sourceIndex[1]];
            board[sourceIndex[0]][sourceIndex[1]] = board[destinationIndex[0]][destinationIndex[1]];
            board[destinationIndex[0]][destinationIndex[1]] = temp;
        }

        void moveRook() {
            //dummy
        }
};

int main() {

    Game game1;
    // Print starting board.
    cout << "   A  B  C  D  E  F  G  H\n\n";
    for (int i = 0; i < board_dimension; i++) {
        cout << 8-i << "  ";
        for (int j = 0; j < board_dimension; j++) {
            cout << game1.board[i][j] << " ";
        }
        cout << "\n";
    }
    int turn_tracker = 1;
    while(1) {
        game1.acceptUserInputSource();
        game1.unitConverterSource();

        game1.acceptUserInputDestination();
        game1.unitConverterDestination();

        //game1.movePawn();
        game1.moveKing();

        cout << "   A  B  C  D  E  F  G  H\n\n";
        for (int i = 0; i < board_dimension; i++) {
            cout << 8-i << "  ";
            for (int j = 0; j < board_dimension; j++) {
                cout << game1.board[i][j] << " ";
            }
            cout << "\n";
        }
        if (turn_tracker == 1) {
            turn_tracker = 2;
            cout << "\nPlayer 2! Your turn.\n";
        } else {
            turn_tracker = 1;
            cout << "\nPlayer 1! Your turn.\n";
        }
    }

    /*
    add method to retire pieces
    */

    /*
    1. if index value contains P, and it's player 2's turn, allow them to decrement 1-2 the first index.
    2. if ", and it's player 1's turn, allow them to increment first index once or twice.
    3. if index value contains R, allow them to change first index, or second index, but not both...
    ... if in for loop the rook would overtake or jump another piece, disallow the move, and prompt...
    ... user for new move
    4. knight - allow user to jump over pieces! and move like so: https://sakkpalota.hu/index.php/en/chess/rules#knight
    5. queen - allow anything rook, bishop can do without overtaking or
    6. king - can move 1 spot left/right, 1 spot up/down, or superset of these
    7. bishop - diagonal moves left/right offset must be equivalent to up/down offset.
    */

    //Defining Game rules
    //Player 1 Pawns can move 1 down
    if (game1.board[1][1].find('P') != string::npos && game1.board[1][1].find('1') != string::npos) {
        cout << "this is a Player 1 Pawn\n";
        game1.movePawn();
    }

    return 0;

    /*std::string starting_board[8][8] = {
        {"R1", "KN1", "B1", "Q1", "K1", "B1", "KN1", "R1"},
        {"P1", "P1", "P1", "P1", "P1", "P1", "P1", "P1"},
        {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
        {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
        {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
        {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
        {"P2", "P2", "P2", "P2", "P2", "P2", "P2", "P2"},
        {"R2", "KN2", "B2", "Q2", "K2", "B2", "KN2", "R2"}
    };*/

}