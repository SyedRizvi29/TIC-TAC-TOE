#include <iostream>
using namespace std;
char board[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6','7','8'}};
int row, column;
char turn = 'X';
string p1;
string p2;
bool draw = false;

void start() {

    cout << "Enter Player 1 Name: \n";
    cin >> p1;
    cout << "Enter Player 2 Name: \n";
    cin >> p2;
    cout << p1 << " will go first \n";
    cout << p2 << " will go second \n \n";
}

void display_board(){

    cout << p1 << " [X] " << p2 << "[O] \n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
    cout << "\t     |     |     \n";
}

void player_turn(){
    int choice;
    if(turn =='X'){
        cout << p1 <<" Please select cell (0-8): \n";
    }
    else if(turn == 'O'){
        cout << p2 << " Please select cell (0-8): \n";
    }

    cin >> choice;

    switch(choice){
        case 0: row=0; column=0; break;
        case 1: row=0; column=1; break;
        case 2: row=0; column=2; break;
        case 3: row=1; column=0; break;
        case 4: row=1; column=1; break;
        case 5: row=1; column=2; break;
        case 6: row=2; column=0; break;
        case 7: row=2; column=1; break;
        case 8: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "Box already filled, please choose another \n";
        player_turn();
    }
    display_board();
}

bool game_con(){
    for(int i = 0; i<3 ; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board [i][2] || board[0][i] == board[1][i] && board [0][i] == board[2][i]){
            return false;
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    //Checking the if game already draw
    draw = true;
    return false;

}

int main() {
    start();
    display_board();

while(game_con()) {
    display_board();
    player_turn();
    game_con();
}

    if(turn == 'X' && draw == false){
        cout<<"\n Congratulations!" << p2 << " has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n Congratulations!"<< p1<< " has won the game";
    }
    else{
        cout<<"\n GAME DRAW!!! \n";
    }
}
