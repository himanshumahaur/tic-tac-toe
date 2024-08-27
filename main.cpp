#include <iostream>
#include <conio.h>
using namespace std;

void show(int** board, int* pos) {
    switch(pos[0]) {
        case 0:
            cout << "      v\n";
            break;
        case 1:
            cout << "          v\n";
            break;
        case 2:
            cout << "              v\n";
            break;
    }
    for(int i=0; i<3; i++) {
        cout << "      ";
        for(int j=0; j<3; j++) {
            switch(board[i][j]) {
                case 1:
                    cout << "O";
                    break;
                case 0:
                    cout << " ";
                    break;
                case -1:
                    cout << "X";
            }
            if(j!=2) {
                cout << " | ";
            }
            else {
                if(pos[1]==i) {
                    cout << " <";
                }
            }
        }
        if(i!=2) {
            cout << "\n    -------------\n";
        }
    }
    cout << "\n";
}

void mark(int** board, int* pos, int turn) {
    if(turn==0) {
        //pos==o
        if(board[pos[1]][pos[0]]==0) {
            board[pos[1]][pos[0]]=1;
        }
    }
    else {
        //pos==x
        if(board[pos[1]][pos[0]]==0) {
            board[pos[1]][pos[0]]=-1;
        }
    }

}

int full(int** board) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j]==0) {
                return 0;
            }
        }
    }
    return 1;
}

int win(int** board) {
    for(int i=0; i<3; i++) {
        if(board[i][0]==1 && board[i][1]==1 && board[i][2]==1) {
            return 1;
        }
        else if(board[0][i]==1 && board[1][i]==1 && board[2][i]==1) {
            return 1;
        }
        else if(board[i][0]==-1 && board[i][1]==-1 && board[i][2]==-1) {
            return -1;
        }
        else if(board[0][i]==-1 && board[1][i]==-1 && board[2][i]==-1) {
            return -1;
        }
    }
    if(board[0][0]==1 && board[1][1]==1 && board[2][2]==1) {
            return 1;
        }
    else if(board[1][1]==1 && board[0][2]==1 && board[2][0]==1) {
            return 1;
    }
    else if(board[0][0]==-1 && board[1][1]==-1 && board[2][2]==-1) {
            return -1;
        }
    else if(board[1][1]==-1 && board[0][2]==-1 && board[2][0]==-1) {
            return -1;
    }
    return 0;
}

void reset(int** board, int* pos, string title, string oturn) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j]=0;
        }
    }
    pos[0]=1;
    pos[1]=1;

    system("cls");
    cout << title;
    cout << oturn;
    show(board, pos);
}

int main() {
    string title = "TIC-TAC-TOE(C) HM v0.1.3\n\n";

    string oturn = "        O-Turn\n\n";
    string xturn = "        X-Turn\n\n";
    string invalid = "\n       Invalid!\n";

    string owins = "  * * * O-Wins! * * *\n\n";
    string xwins = "  * * * X-Wins! * * *\n\n";
    string draw =  "         Tie! \n\n";

    string end;

    bool trig = true;
    char input;
    int pos[] = {1, 1};
    int turn = 0;

    int a[] = {0, 0, 0};
    int b[] = {0, 0, 0};
    int c[] = {0, 0, 0};

    int** board = new int*[3];
    board[0] = a;
    board[1] = b;
    board[2] = c;
    
    system("cls");
    cout << title;
    cout << oturn;
    show(board, pos);

    while(trig) {
        input = getch();

        system("cls");
        end = "";
        cout << title;

        switch(input) {
            case 'H':
                if(pos[1]>0)
                pos[1]--;
                break;
            case 'P':
                if(pos[1]<2)
                pos[1]++;
                break;
            case 'K':
                if(pos[0]>0)
                pos[0]--;
                break;
            case 'M':
                if(pos[0]<2)
                pos[0]++;
                break;
        }

        if(input==' ') {
            if(board[pos[1]][pos[0]]==0) {
                mark(board, pos, turn);
                turn = !turn;
            }
            else {
                end = invalid;
            }
        }
        
        if(win(board)||full(board)) {
            if(win(board)==1) {
                cout << owins;
            }
            else if(win(board)==-1) {
                cout << xwins;
            }
            else {
                cout << draw;
            }
            show(board, pos);
            getch();
            if(!turn) reset(board, pos, title, oturn);
            else reset(board, pos, title, xturn);
        }
        else {
            if(turn==0) {
                cout << oturn;
            }
            else {
                cout << xturn;
            }
            show(board, pos);
        }

        cout << end;
    }

    
    return 0;
}