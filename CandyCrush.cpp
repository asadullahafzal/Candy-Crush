
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<conio.h>
#include<string>
#include<ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

double getSecondsDuration(chrono::system_clock::time_point time2,
    chrono::system_clock::time_point time1) {
    return chrono::duration_cast<chrono::seconds>(time2 - time1).count();
}


char crushrand(char cand) {
    int c = rand() % 5 + 1;
    switch (c) {
    case 1: cand = '@'; break;
    case 2: cand = '#'; break;
    case 3: cand = '$'; break;
    case 4: cand = '%'; break;
    case 5: cand = '&'; break;
    }
    return cand;
}

char crushrandhard(char cand) {
    int c = rand() % 7 + 1;
    switch (c) {
    case 1: cand = '@'; break;
    case 2: cand = '#'; break;
    case 3: cand = '$'; break;
    case 4: cand = '%'; break;
    case 5: cand = '&'; break;
    case 6: cand = '!'; break;
    case 7: cand = '*'; break;
    }
    return cand;
}


void fill(char arr[8][8]) {
    char cand = ' ';
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (arr[x][y] == ' ') {
                arr[x][y] = crushrand(cand);
                if ((y > 1 && arr[x][y] == arr[x][y - 1] && arr[x][y] == arr[x][y - 2]) ||
                    (x > 1 && arr[x][y] == arr[x - 1][y] && arr[x][y] == arr[x - 2][y]) ||
                    (x > 1 && y > 1 && arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x - 2][y - 2]) ||
                    (x < 6 && y > 1 && arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x + 2][y - 2])) {
                    arr[x][y] = crushrand(cand);
                }
            }
        }
    }
}

void fillhard(char arr[10][10]) {
    char cand = ' ';
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (arr[x][y] == ' ') {
                arr[x][y] = crushrandhard(cand);
                if ((y > 1 && arr[x][y] == arr[x][y - 1] && arr[x][y] == arr[x][y - 2]) ||
                    (x > 1 && arr[x][y] == arr[x - 1][y] && arr[x][y] == arr[x - 2][y]) ||
                    (x > 1 && y > 1 && arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x - 2][y - 2]) ||
                    (x < 8 && y > 1 && arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x + 2][y - 2])) {
                    arr[x][y] = crushrandhard(cand);
                }
            }
        }
    }
}

void FILLcandies(char arr[8][8]) {
    char c = ' ';
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = crushrand(c);
            if ((j > 1 && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2]) ||
                (i > 1 && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j]) ||
                (i > 1 && j > 1 && arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 2]) ||
                (i < 6 && j > 1 && arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2])) {
                arr[i][j] = crushrand(c);
            }
        }
    }
}

void FILLcandieshard(char arr[10][10]) {
    char c = ' ';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = crushrandhard(c);
            if ((j > 1 && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2]) ||
                (i > 1 && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j]) ||
                (i > 1 && j > 1 && arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i - 2][j - 2]) ||
                (i < 8 && j > 1 && arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2])) {
                arr[i][j] = crushrandhard(c);
            }
        }
    }
}

void print(char arr[8][8]) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int color = 7; // Default color
            switch (arr[x][y]) {
            case '@': color = 1; break;
            case '#': color = 2; break;
            case '$': color = 3; break;
            case '%': color = 4; break;
            case '&': color = 5; break;
            case '!': color = 6; break;
            case '*': color = 7; break;
            }
            SetConsoleTextAttribute(h, color);
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 7);
}

void printhard(char arr[10][10]) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE

    );
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int color = 7; // Default color
            switch (arr[x][y]) {
            case '@': color = 1; break;
            case '#': color = 2; break;
            case '$': color = 3; break;
            case '%': color = 4; break;
            case '&': color = 5; break;
            case '!': color = 6; break;
            case '*': color = 7; break;
            }
            SetConsoleTextAttribute(h, color);
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 7);
}

// Function to store the player's score in the scoreboard file
void score(string name, int playerScore) {
    ofstream file("SCOREBOARD.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error Opening File." << endl;
    }
    else {
        file << name << " Your score is : " << playerScore;
        file.close();
    }
}

void printInstructions() {
    cout << "INSTRUCTIONS:" << endl;
    cout << "1. Select 1 for EASY mode and 2 for HARD mode." << endl;
    cout << "2. Enter the current and new row and column coordinates to swap candies." << endl;
    cout << "3. Match candies in rows or columns of 3 or more to score points." << endl;
    cout << "4. You have a limited number of moves. Use them wisely!" << endl;
    cout << "5. The game ends when you run out of moves." << endl;
}

void getUserMove(int& row, int& col, int& newRow, int& newCol) {
    char key;
    key = _getch(); // Capture the first key press

    switch (key) {
    case KEY_UP:
        newRow = row - 1;
        newCol = col;
        break;
    case KEY_DOWN:
        newRow = row + 1;
        newCol = col;
        break;
    case KEY_LEFT:
        newRow = row;
        newCol = col - 1;
        break;
    case KEY_RIGHT:
        newRow = row;
        newCol = col + 1;
        break;
    default:
        cout << "Invalid key. Try again." << endl;
        getUserMove(row, col, newRow, newCol);
        break;
    }
}

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    std::string name;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t|---------------  WELCOME TO THE GAME  ----------------|"<<endl;
    cout << "\t\t\t\t|             BY: 23F-0693 ASADULLAH                   |" << endl;
    cout << "\t\t\t\t|               23F-0610 ALI HASSAN                    |" << endl;
    cout << "\t\t\t\t|______________________________________________________|" << endl;
    cout << "\t\t\t\t|______________________________________________________|" << endl;
    cout << "\t\t\t\t  ENTER YOUR NAME TO PLAY THE GAME : ";
    cin >> name;

    int playerScore = 0;
    int score = 0, counter = 0;
    int game;
    char replay = 'Y';

    char c;
    auto startTime = chrono::system_clock::now();  // Renamed 'time' to 'startTime'
    int gameDuration = 15;
    bool timeRanOut = true;

    while (gameDuration >= getSecondsDuration(chrono::system_clock::now(), startTime)) {
        if (_kbhit() == 0) {
            system("cls");
            cout << "You have " << gameDuration - getSecondsDuration(chrono::system_clock::now(), startTime)
                << " seconds left. Hurry" << endl;
            Sleep(40);
        }
        else {
            auto newTime = chrono::system_clock::now();
            c = _getch();
            cout << "You entered " << c << endl;
            cout << "You took " << getSecondsDuration(newTime, startTime) << " seconds!" << endl;
            timeRanOut = false;
            break;
        }
    }

    if (timeRanOut) {
        cout << "Your time has run out!";
    }


    while (replay == 'Y' || replay == 'y') {
        system("CLS");
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t|-------------------CANDY CRUSH------------------------|" << endl;
        cout << "\t\t\t\t|                                                      |" << endl;
        cout << "\t\t\t\t|                  1. EASY                             |" << endl;
        cout << "\t\t\t\t|                  2. HARD                             |" << endl;
        cout << "\t\t\t\t|                  3. HOW TO PLAY                      |" << endl;
        cout << "\t\t\t\t|                  4. SCOREBOARD                       |" << endl;
        cout << "\t\t\t\t|                  5. QUIT GAME                        |" << endl;
        cout << "\t\t\t\t|                                                      |" << endl;
        cout << "\t\t\t\t|______________________________________________________|" << endl;
        cout << "\t\t\t\tEnter Your Choice (1-5): ";
        cin >> game;

 
        if (game == 1 || game == 2) {
            int row, col, newRow, newCol;
            char temp;
            int moves = 10;  // You can adjust the number of moves as needed

            if (game == 1) {
                char candies[8][8];
                FILLcandies(candies);
                print(candies);
                while (moves > 0) {
                    cout << "Enter the current row and column: ";
                    cin >> row >> col;
                    cout << "Enter the new row and column: ";
                    cin >> newRow >> newCol;

                    if (row < 0 || row >= 8 || col < 0 || col >= 8 ||
                        newRow < 0 || newRow >= 8 ||
                        newCol < 0 || newCol >= 8) {
                        cout << "Invalid coordinates. Try again." << endl;
                        continue;
                    }

                    temp = candies[row][col];
                    candies[row][col] = candies[newRow][newCol];
                    candies[newRow][newCol] = temp;

                    counter = 0;
                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            if ((y > 1 && candies[x][y] == candies[x][y - 1] && candies[x][y] == candies[x][y - 2]) ||
                                (x > 1 && candies[x][y] == candies[x - 1][y] && candies[x][y] == candies[x - 2][y])) {
                                counter++;
                                candies[x][y] = ' ';
                                candies[x][y - 1] = ' ';
                                candies[x][y - 2] = ' ';
                            }
                        }
                    }

                    if (counter > 0) {
                        cout << "Match found! Score + " << counter * 10 << endl;
                        score += counter * 10;
                        fill(candies);
                        print(candies);

                        // Store the score in the scoreboard file with the current date and time
                        void score(string name, int playerScore);
                    }
                    else {
                        cout << "No match found. Moves left: " << --moves << endl;
                        temp = candies[row][col];
                        candies[row][col] = candies[newRow][newCol];
                        candies[newRow][newCol] = temp;
                    }
                }
            }
            else if (game == 2) {
                char candies1[10][10];
                FILLcandieshard(candies1);
                printhard(candies1);
                while (moves > 0) {
                    cout << "Enter the current row and column: ";
                    cin >> row >> col;
                    cout << "Enter the new row and column: ";
                    cin >> newRow >> newCol;

                    if (row < 0 || row >= 10 || col < 0 || col >= 10 ||
                        newRow < 0 || newRow >= 10 ||
                        newCol < 0 || newCol >= 10) {
                        cout << "Invalid coordinates. Try again." << endl;
                        continue;
                    }

                    temp = candies1[row][col];
                    candies1[row][col] = candies1[newRow][newCol];
                    candies1[newRow][newCol] = temp;

                    counter = 0;
                    for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 10; y++) {
                            if ((y > 1 && candies1[x][y] == candies1[x][y - 1] && candies1[x][y] == candies1[x][y - 2]) ||
                                (x > 1 && candies1[x][y] == candies1[x - 1][y] && candies1[x][y] == candies1[x - 2][y])) {
                                counter++;
                                candies1[x][y] = ' ';
                                candies1[x][y - 1] = ' ';
                                candies1[x][y - 2] = ' ';
                            }
                        }
                    }

                    if (counter > 0) {
                        cout << "Match found! Score + " << counter * 10 << endl;
                        score += counter * 10;
                        fillhard(candies1);
                        printhard(candies1);
                    }
                    else {
                        cout << "No match found. Moves left: " << --moves << endl;
                        temp = candies1[row][col];
                        candies1[row][col] = candies1[newRow][newCol];
                        candies1[newRow][newCol] = temp;
                    }
                }
            }

        }
            else if (game == 3) {
                system("CLS");
                printInstructions();
            }
            else if (game == 4) {
                system("CLS");
                ifstream scoreboardFile("SCOREBOARD.txt");
                if (!scoreboardFile.is_open()) {
                    cout << "No scores available." << endl;
                }
                else {
                    cout << "SCOREBOARD:" << endl;
                    cout << scoreboardFile.rdbuf() << endl;
                    scoreboardFile.close();
                }
            }
            else if (game == 5) {
                cout << "Thank you for playing! Goodbye!" << endl;
                replay = 'N'; // Exit the loop and end the game
            }
            else {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }

            if (replay == 'Y' || replay == 'y') {
                cout << "Do you want to play again? (Y/N): ";
                cin >> replay;
            }
    }
    return 0;

}
       
    



                





