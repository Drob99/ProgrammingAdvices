// Stone - Paper - Scissors
#include<iostream>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3};
enum enGameResult { Win = 1, Draw = 2, Lose = 3};

bool ReadPlayAgain(string message)
{
    char reply;
    cout << message;
    cin >> reply;

    if (reply == 'y' || reply == 'Y')
        return true;
    else
        return false;
}

enGameResult IsWon(enGameChoice Computer, enGameChoice Player)
{
    if (Computer == Player)
    {
        system("color 6F");
        return Draw;
    }

    switch (Computer)
    {
        case Stone:
        {
            if (Player == Paper){
                system("color 2F");
                return Win;
            }
            else{
                system("color 4F");
                return Lose;
            }
        }
        
        case Paper:
        {
            if (Player == Scissor)
            {
                system("color 2F");
                return Win;
            }
            else
            {
                system("color 4F");
                return Lose;
            }
        }

        case Scissor:
        {
            if (Player == Stone)
            {
                system("color 2F");
                return Win;
            }
            else
            {
                system("color 4F");
                return Lose;
            }
        }
    }
}


int RandomNumber(int From, int To){
    // Function to generate random number
    // cout << rand() << "\n";
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadNumberInRange(string message, int From, int To)
{
    int num;
    do
    {
        cout <<  message;
        cin >> num;
    }while(num < From || num > To);

    return num;
}

enGameChoice ReadPlayerChoice(){
    return (enGameChoice) ReadNumberInRange("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ", 1, 3);
}

enGameChoice ReadComputerChoice()
{
    return enGameChoice(RandomNumber(1, 3));
}


int ReadNumberOfRounds(string message)
{
    int num;
    do
    {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);
    
    return num;
}

string Choice (enGameChoice Choice)
{
    switch (Choice)
    {
        case (Stone):
            return "Stone";
        case (Paper):
            return "Paper";
        case (Scissor):
            return "Scissor";
    }
}

string Result(enGameResult result)
{
    switch (result)
    {
        case (Win):
            return "Player1";
        case (Lose):
            return "Computer";
        case (Draw):
            return "No winner";
    }
}

void PrintRoundResults (int Number, enGameResult RoundResult, enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
    cout << "\n_______________Round [" << Number << "] _________________\n\n";
    cout << "Player1  Choice: " << Choice(PlayerChoice) << "\n";
    cout << "Computer Choice: " << Choice(ComputerChoice) << "\n";
    cout << "Round Winner   : [" << Result(RoundResult) << "]\n"; 
    cout << "_________________________________________________________\n";
}

void AddRoundToGamearray(enGameResult array[], int &arrLength, enGameResult Result)
{
    array[arrLength] = Result;
    arrLength++;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";

    }

    cout << "\n";
}

int PlayerWinCount(enGameResult arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Win)
            count ++;
    }
    return count;
}

int ComputerWinCount(enGameResult arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Lose)
            count ++;
    }
    return count;
}

int DrawCount(enGameResult arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Draw)
            count ++;
    }
    return count;
}

string FinalWinner(enGameResult Game[], int GameRounds)
{
    int PlayerWins = PlayerWinCount(Game, GameRounds);
    int ComputerWins = ComputerWinCount(Game, GameRounds);

    if (PlayerWins > ComputerWins)
        return "Player1";
    else if (ComputerWins > PlayerWins)
        return "Computer";
    else
        return "No Winner";
}

void PlayRound(int Number, enGameResult Game[], int &GameRounds)
{
    cout << "\nRound [" << Number << "] begins:\n";

    enGameChoice PlayerChoice = ReadPlayerChoice();
    enGameChoice ComputerChoice = ReadComputerChoice();

    enGameResult GameResult = IsWon(ComputerChoice, PlayerChoice);
    PrintRoundResults(Number, GameResult, PlayerChoice, ComputerChoice);
    AddRoundToGamearray(Game, GameRounds, GameResult);
}

void PrintGameOverMenu( enGameResult Game[], int GameRounds)
{
    cout << "\t\t_______________________________________________________________\n\n";
    cout << "\t\t                     *** G a m e O v e r ***                   \n";
    cout << "\t\t_______________________________________________________________\n\n";
    cout << "\t\t_______________________[Game Results ]_________________________\n\n";
    cout << "\t\tGame Rounds           : " << GameRounds << "\n";
    cout << "\t\tPlayer1 won times     : " << PlayerWinCount(Game, GameRounds) << "\n";
    cout << "\t\tComputer won times    : " << ComputerWinCount(Game, GameRounds) << "\n";
    cout << "\t\tDraw times            : " << DrawCount(Game, GameRounds) << "\n";
    cout << "\t\tFinal Winner          : " << FinalWinner(Game, GameRounds) << "\n";
    cout << "\t\t_______________________________________________________________\n\n";
}

void PlayGame()
{
    bool PlayAgain = true;
    do
    {
        system("color 0F");
        enGameResult Game[10];
        int GameRounds = 0;
        int rounds = ReadNumberOfRounds ("\n\nHow Many Rounds 1 to 10  ?");
        for (int i = 0; i < rounds; i++)
            PlayRound(i+1, Game, GameRounds);
        
        PrintGameOverMenu(Game, GameRounds);
        PlayAgain = ReadPlayAgain("\t\tDo you want to play again? Y/N?");
    } while (PlayAgain);
}


int main()
{
    srand ((unsigned)time(NULL));

    PlayGame();
    return 0;
}
