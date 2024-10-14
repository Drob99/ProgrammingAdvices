# include <iostream>
# include <cstdlib>

using namespace std;

enum enQuestionLevel { Easy = 1, Med  = 2, Hard = 3, Mix = 4};
enum enOpType        { Add  = 1, Sub  = 2, Mul  = 3, Div = 4, MIX = 5};
enum enResult        { Pass = 1, Fail = 2};

struct stQuestionInfo
{
    short QuestionNumber = 0;
    enQuestionLevel GeneralQuestionLevel;
    enQuestionLevel SpecificQuestionLevel;
    int FirstNumber;
    int SecondNumber;
    enOpType GeneralOpType;
    enOpType SpecificOpType;
    int UserAnswer;
    int CorrectAnswer;
    bool correct = false;
};

struct stGameResults
{
    short NumberOfQuestions = 0;
    short CorrectTimes      = 0;
    short WrongTimes        = 0;
    enQuestionLevel QuestionLevel;
    enOpType OpType;
    enResult Result;
};

int RandomNumber(int From, int To) 
{ 
 //Function to generate a random number
 int randNum = rand() % (To - From + 1) + From; 
 return randNum; 
} 

string QuestionLevel(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevel[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestionLevel[QuestionLevel - 1];
}

string Result (enResult Result)
{
    string arrResult[2] = {"Pass", "Fail"};
    string word = arrResult[Result - 1];
    if (Result - 1 == 0)
        word += " :-)";
    else
        word += " :-(";
    return word;
}

string Operation(enOpType OpType)
{
    string arrOpType[5] = {"+", "-", "*", "/", "Mix"};
    return arrOpType[OpType - 1];
}

enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    do
    {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel) QuestionLevel;
}

enOpType ReadOpType()
{
    short OpType = 0;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);

    return (enOpType) OpType;
}

enQuestionLevel GetQuestionLevel(enQuestionLevel GeneralQuestionLevel)
{
    enQuestionLevel specificQuestionLevel;
    int RandomChoice = RandomNumber(1,3);
    if (GeneralQuestionLevel == enQuestionLevel::Mix)
        return (enQuestionLevel) RandomChoice;
    else
        return GeneralQuestionLevel; 
}


int GetRandomNumber(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
        case (Easy):
            return RandomNumber(1, 10);
        case (Med):
            return RandomNumber(10, 50);
        case (Hard):
            return RandomNumber(50, 100);
        case (Mix):
            return RandomNumber(1, 100);
    }
}

enOpType GetOperation(enOpType GeneralOpType)
{
    enOpType specificOpType;
    int RandomChoice = RandomNumber(1,4);
    if (GeneralOpType == enOpType::MIX)
        return (enOpType) RandomChoice;
    else
        return GeneralOpType;  
}

bool IsQuestionCorrect(stQuestionInfo QuestionInfo)
{


    return QuestionInfo.UserAnswer == QuestionInfo.CorrectAnswer;
}

int GetCorrectAnswer(stQuestionInfo QuestionInfo)
{
    int CorrectAnswer  = 0;

    switch (QuestionInfo.SpecificOpType)
    {
        case (Add):
            CorrectAnswer = QuestionInfo.FirstNumber + QuestionInfo.SecondNumber;
            break;
        case (Sub):
            CorrectAnswer = QuestionInfo.FirstNumber - QuestionInfo.SecondNumber;
            break;
        case (Mul):
            CorrectAnswer = QuestionInfo.FirstNumber * QuestionInfo.SecondNumber;
            break;
        default:
            CorrectAnswer = QuestionInfo.FirstNumber / QuestionInfo.SecondNumber;
            break;
    }

    return CorrectAnswer;
}

int ReadUserAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

enResult IsGameWon(int CorrectTimes, int WrongTimes)
{
    if (CorrectTimes >= WrongTimes)
        return Pass;
    else
        return Fail;
}

stGameResults FillGameResults(int NumberOfQuestions, short CorrectTimes, short WrongTimes, enOpType Optype, enQuestionLevel QuestionLevel)
{
    stGameResults GameResults;
    GameResults.NumberOfQuestions = NumberOfQuestions;
    GameResults.CorrectTimes = CorrectTimes;
    GameResults.WrongTimes = WrongTimes;
    GameResults.OpType = Optype;
    GameResults.QuestionLevel = QuestionLevel;
    GameResults.Result = IsGameWon(CorrectTimes, WrongTimes);
    return GameResults;
}

stGameResults PlayGame(short HowManyQuestions)
{
    stQuestionInfo QuestionInfo;
    short CorrectTimes = 0, WrongTimes = 0;
    QuestionInfo.GeneralQuestionLevel = ReadQuestionLevel();
    QuestionInfo.GeneralOpType = ReadOpType();
    for (short QuestionNumber = 1; QuestionNumber <= HowManyQuestions; QuestionNumber++)
    {
        cout << "\nQuestion [" << QuestionNumber << "/" << HowManyQuestions << "]\n\n";
        QuestionInfo.QuestionNumber = QuestionNumber;
        QuestionInfo.SpecificQuestionLevel = GetQuestionLevel(QuestionInfo.GeneralQuestionLevel);
        QuestionInfo.FirstNumber = GetRandomNumber(QuestionInfo.SpecificQuestionLevel);
        cout << QuestionInfo.FirstNumber << "\n";
        QuestionInfo.SecondNumber = GetRandomNumber(QuestionInfo.SpecificQuestionLevel);
        cout << QuestionInfo.SecondNumber << " ";
        QuestionInfo.SpecificOpType = GetOperation(QuestionInfo.GeneralOpType);
        cout << Operation(QuestionInfo.SpecificOpType) << "\n";
        cout << "_____________________________\n";
        QuestionInfo.UserAnswer = ReadUserAnswer();
        QuestionInfo.CorrectAnswer = GetCorrectAnswer(QuestionInfo);
        cout << "\n";
        QuestionInfo.correct = IsQuestionCorrect(QuestionInfo);

        if (QuestionInfo.correct)
        {
            system("color 2F");
            cout << "Correct Answer :-)\n";
            CorrectTimes ++;
        }
        else
        {
            system ("color 4F");
            cout << "Wrong Answer :-(\n";
            cout << "The right answer is: " << QuestionInfo.CorrectAnswer << "\n"; 
            WrongTimes ++;
        }
    }

    return FillGameResults(HowManyQuestions, CorrectTimes, WrongTimes, QuestionInfo.GeneralOpType, QuestionInfo.GeneralQuestionLevel);
}

void SetScreenColor(enResult Result)
{
    if (Result == Pass)
        system ("color 2F");
    else
        system ("color 4F");
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << "____________________________________________\n\n";
    cout << "      Final Result is " << Result(GameResults.Result) << "\n";
    cout << "____________________________________________\n\n";
    cout << " Number Of Questions    : " << GameResults.NumberOfQuestions << "\n";
    cout << " Questions Level        : " << QuestionLevel(GameResults.QuestionLevel)  << "\n";
    cout << " OpType                 : " << Operation(GameResults.OpType) << "\n";
    cout << " Number of Right Answers: " << GameResults.CorrectTimes << "\n";
    cout << " Number of Wrong Answers: " << GameResults.WrongTimes << "\n";
    cout << "____________________________________________\n\n";
    SetScreenColor(GameResults.Result);
}

short ReadHowManyQuestions()
{
    short NumberOfQuestions = 0;
    do
    {
        cout << "How Many Questions do you want to answer? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1);

    return NumberOfQuestions;
}

void ResetScreen() 
{ 
 system("cls"); 
 system("color 0F"); 
} 

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyQuestions());
        ShowFinalGameResults(GameResults);
        cout << endl << "Do you want to play again? Y/N? ";

        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
}

int main() 
{ 
 //Seeds the random number generator in C++, called only once
 srand((unsigned)time(NULL)); 
 
 StartGame(); 
 return 0; 
}