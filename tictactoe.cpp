#include <iostream>
using namespace std;
void grid(char* t) {
    cout << " "<< t[0] << " | " << t[1] << " | " << t[2] << "\n"
        "-----------\n " <<
        t[3] << " | " << t[4] << " | " << t[5] << "\n"
        "-----------\n " <<
        t[6] << " | " << t[7] << " | " << t[8] << "\n"
        ;
}
bool checkWin(char* t) {
    for (int i{ 0 };i < 9; i += 3) {
        if (t[i] == t[i + 1] && t[i] == t[i + 2] && t[i] != ' ') {
            return true;
        }
    }
    for (int i{ 0 };i < 3;i++) {
        if (t[i] == t[i + 3] && t[i] == t[i + 6] && t[i] != ' ') {
            return true;
        }
    }
    if (t[0] == t[4] && t[0] == t[8] && t[0] != ' ' || t[2] == t[4] && t[2] == t[6] && t[2] != ' ') {
        return true;
    }
    return false;
}
bool checkDraw(char* t) {
    for (int i{ 0 };i < 9;i++) {
        if (t[i] !='X' && t[i] !='O') {
            return false;
        }
    }
    return true;
}
void modifyElements(char* t) {
    static int x = 0;
    char c;
    (x % 2 == 0) ? c = 'O' : c = 'X';
    int nbElement;
    cout << "its " << c << "'s turn \n";
    cin >> nbElement;
    if (t[nbElement-1] == ' ') {
        t[nbElement-1] = c;
        x++;
    }
    grid(t);
    if (checkWin(t)){ cout <<c<<" won game over\n";}
    else if (checkDraw(t)) { cout << "draw"; }
    else{
    modifyElements(t);
    };
}
void how2Play() {
    cout << "how to play\n"
        "1- each player gets his turn\n"
        "2-input the number where you want to make you're play as shown below\n"
        " 1 | 2 | 3 \n"
        "-----------\n"
        " 4 | 5 | 6 \n"
        "-----------\n"
        " 7 | 8 | 9 \n"
        "\n\n\n"
        ;
}
int main()
{
    system("COLOR 0A");
    char tab[9] = { ' ', ' ', ' ',
                    ' ',' ',' ',
                    ' ',' ',' ' };

    how2Play();
    grid(tab);
    modifyElements(tab);
    
}

