#include <conio.h>
#include <iostream>
#include <cstdlib>   
#include <chrono>
#include <stdlib.h>  
int color(int x);
int player = 0;
using namespace std;
char board[3][3]{ {'_','_','_'},
                     {'_','_','_'}
                   ,{'_','_','_'} };
void game_board();
bool isWinner(char ch4) {
    return ((board[0][0] == ch4 && board[0][1] == ch4 && board[0][2] == ch4) ||
        (board[1][0] == ch4 && board[1][1] == ch4 && board[1][2] == ch4) ||
        (board[2][0] == ch4 && board[2][1] == ch4 && board[2][2] == ch4) ||
        (board[0][0] == ch4 && board[1][0] == ch4 && board[2][0] == ch4) ||
        (board[0][1] == ch4 && board[1][1] == ch4 && board[2][1] == ch4) ||
        (board[0][2] == ch4 && board[1][2] == ch4 && board[2][2] == ch4) ||
        (board[0][0] == ch4 && board[1][1] == ch4 && board[2][2] == ch4) ||
        (board[0][2] == ch4 && board[1][1] == ch4 && board[2][0] == ch4));
}
bool Boardfull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != ' ')
                return false;
                
    
}
int color(int x){

    if (x == 1)
        system("color 04");
    if (x == 2)
        system("color 01");

    return 1;
}

int main()
{
    auto start = chrono::steady_clock::now();
    system("color F0");

    while (true)
    {
        
        game_board();
        int row, column;
        cout << "Player 1: ";
        while (true)
        {
            
            color(1);
            cout << "\nEnter the row(0-2) :";
            cin >> row;
            cout << "\nEnter the column(0-2) :";
            cin >> column;
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {
               
                if (board[row][column] == '_')
                {
                    
                    board[row][column] = 'x' ;
                    break;
                    color(2);
                }
                
                else
                    cout << "is not empty";
            }
            else
                cout << "out of range";
            
        }
        if (isWinner('x'))
        {
            cout << "player 1 bord\n";
            game_board();
                break;
        }
        else if (Boardfull() && !(isWinner('X') || isWinner('O')))
        {
            cout << "mosavi\n";
            game_board();
            break;
        }
  
        
        while (true)
        {
            color(2);
            game_board();
            cout << "Player 2: ";
            cout << "\nEnter the row :";
            cin >> row;
            cout << "\nEnter the column :";
            cin >> column;
            if (0 <= row && row <= 2 && 0 <= column && column <= 2)
            {
               
                if (board[row][column] == '_')
                {
                    board[row][column] = 'o';
                    break;
                    color(1);
                }
                else
                    cout << "is not empty\n";
            }
            else
                cout << "out of range\n";
            
        }
        if (isWinner('o'))
        {
            cout << "player 2 bord\n";
            game_board();
            break;
        }
        else if (Boardfull() && !(isWinner('X') || isWinner('O')))
        {
            cout << "mosavi\n";
            game_board();
            break;
        }
      
    }
    
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in seconds: "<< chrono::duration_cast<chrono::seconds>(end - start).count()<< " sec";
    
}
void game_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << "\t";
        cout << "\n";
    }
}


