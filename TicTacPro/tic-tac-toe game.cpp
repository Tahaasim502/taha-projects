#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int row = 3;
const int column = 3;

//Function to display the board
void displayBoard(char array[row][column])
{
    cout << "   0   1    2" << endl; // column number
    for(int i = 0; i < 3; i++)
    {
        cout << i << " "; // row number
        for(int j = 0; j < 3; j++)
        {
            cout << array[i][j] << " "; 
            if(j < column - 1)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if(i < row - 1)
        {
            cout << "  ------------" << endl;
        }
    }
}


void playeGame()
{
    srand(time(0));
    int row_num = 0, column_num = 0, count = 0;
    char board[row][column] = {
        {'*', '*', '*'},
        {'*', '*', '*'},
        {'*', '*', '*'}
    };
    char choice;
    bool game_end = false;
    displayBoard(board);
    do
    {
        int rand_choice = rand() % 2;
        bool isplayer1 = rand_choice;
        if(isplayer1)
        {
            cout << "player 1 will go first: " << endl;
            cout << "Enter row (0-2) and column(0-2) to place X: ";
            cin >> row_num >> column_num;
            while(board[row_num][column_num] == 'X' || board[row_num][column_num] == 'O' || row_num >= row || row_num < 0|| column_num < 0 || column_num >= column) 
            {
                cout << "Invaild move! Cell already taken or out of bounds. Try again: " << endl;
                cin >> row_num >> column_num;
            }
            board[row_num][column_num] = 'X';
            count++;
            cout << "===== UPDATED BOARD =====" << endl;
            displayBoard(board);
        }
        else
        {
            cout << "Player 2 will go first: " << endl;
            cout << "Enter the row number(0-2) and column number(0-2) to place O: ";
            cin >> row_num >> column_num;
             while(board[row_num][column_num] == 'X' || board[row_num][column_num] == 'O' || row_num >= row || row_num < 0|| column_num < 0 || column_num >= column)
            {
                cout << "Invaild move! Cell already taken or out of bounds. Try again: " << endl;
                cin >> row_num >> column_num;
            }
            board[row_num][column_num] = 'O';
            count++;
            cout << "===== UPDATED BOARD =====" << endl;
            displayBoard(board);
        }

        //Rows & Columns
        for(int i = 0; i < row; i++)
        {
            if((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || ((board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')))
            {
                cout << "Player 1 has won the game" << endl;
                game_end = true;
                break;
            }
            if((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || ((board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')))
            {
                cout << "Player 2 has won the game" << endl;
                game_end = true;
                break;
            }
        }

        //Diagonals
        if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
        {
            cout << "Player 1 has won the game" << endl;
            game_end = true;
        }
        else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        {
            cout << "Player 2 has won the game" << endl;
            game_end = true;
        }
        isplayer1 = !isplayer1; 
    } while(!game_end && count < 9);
    
}

int main()
{
    playeGame();
    return 0;
}