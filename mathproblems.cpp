/*

 Tess Waerneman
 11/11/17

 This program work as a math self assessment for the user. The program will ask the user 
 to input the number of questions wanted for each set of +, - and *, and the upper number 
 limit for each set. Arithmetic problems will be printed on the screen for the user to 
 answer. After that an output with the result will tell the user how many correct answers 
 and the percent for each set and in total. The program works mainly with functions 
 passing parameters using pass-by-value and pass-by-reference for the function who 
 need to respond with information.

 */


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


void getProbsPerSet(double &probsPerSet);
void doOneSet(char operand,double probsPerSet, double &numCorrect);
void printReport(double inputAdCorrect, double inputSubCorrect,
                 double inputMulCorrect, double probsPerSet);

void generateOperands(char oprtr, int maxNum, int &firstNum, int &secNum, int &inputAns);
double doOneProblem(char oprtr, int maxNum);
void checkAnswer(int inputAns, int correctAns, bool &result);
void calculateCorrectAnswer(int firstNum, int SecNum, char oprtr,  int &correctAns);

void getMaxNum(int &maxNum);
void printHeader(char oprtr);






int main()
{

    double probsPerSet;
    double inputAdCorrect;
    double inputSubCorrect;
    double inputMulCorrect;

    srand(static_cast<unsigned> (time(0)));
    getProbsPerSet(probsPerSet);
    doOneSet('+', probsPerSet, inputAdCorrect);
    doOneSet('-', probsPerSet, inputSubCorrect);
    doOneSet('*', probsPerSet, inputMulCorrect);
    printReport(inputAdCorrect, inputAdCorrect, inputMulCorrect, probsPerSet);

}






// This function gets the number of problems per set that the user wants.
void getProbsPerSet(double &probsPerSet)
{

    cout << "Enter problems per set: ";
    cin >> probsPerSet;
    cout << endl;

}






/// This function creates a set of problems and prints the header for the set.
void doOneSet(char oprtr, double probsPerSet, double &numCorrect)
{

    int maxNum;

    printHeader(oprtr);
    getMaxNum(maxNum);

    numCorrect = 0;
    for (int count = 0; count < probsPerSet; count++) {

        numCorrect = numCorrect + doOneProblem(oprtr, maxNum);

    }
}






// Prints the results in the form of the number of correct answers and percent for
// each set and in total on the screen.
void printReport(double inputAdCorrect, double inputSubCorrect,
                 double inputMulCorrect, double probsPerSet)
{

    double adResultSet;
    double subResultSet;
    double mulResultSet;

    double totalProbs;
    double totalCorrect;
    double resultOverall;

    adResultSet = (inputAdCorrect / probsPerSet * 100);
    subResultSet = (inputSubCorrect / probsPerSet * 100);
    mulResultSet = (inputMulCorrect / probsPerSet * 100);

    totalCorrect = (inputAdCorrect + inputSubCorrect + inputMulCorrect);
    totalProbs = (probsPerSet * 3);
    resultOverall = (totalCorrect / totalProbs * 100);

    cout << endl << setprecision(1) << fixed << "Set #1:  You got " << inputAdCorrect <<
    " correct out of " << probsPerSet << " for " << adResultSet << "%" << endl;

    cout << setprecision(1) << fixed << "Set #2:  You got " << inputSubCorrect <<
    " correct out of " << probsPerSet << " for " << subResultSet << "%" << endl;
    cout << setprecision(1) << fixed << "Set #3:  You got " << inputMulCorrect <<
    " correct out of " << probsPerSet << " for " << mulResultSet << "%" << endl;
    cout << setprecision(1) << fixed << "Overall you got " << totalCorrect <<
    " correct out of " << totalProbs << " for " << resultOverall << "%" << endl;

}






// Outputs the set number based on the operator as a header for organizational purpose.
void printHeader(char oprtr)
{

    if (oprtr == '+') {
        cout << "Set #1 " << endl;
    }
    if (oprtr == '-') {
        cout << endl << "Set #2 " << endl;
    }
    if (oprtr == '*') {
        cout << endl << "Set #3 " << endl;
    }

    cout << "----------" << endl;
    cout << endl;

}






// Gets the maximum number to be used in each set from the user.
void getMaxNum(int &maxNum)
{
    cout << "What is the maximum number for this set? ";
    cin	>> maxNum;
    cout << endl;
}






// This function summarizes each problem and corresponding answer by calling
// generateOperands, calculateCorrectAnswer and checkAnswer which will be
// passed to doOneSet.
double doOneProblem(char oprtr, int maxNum)
{

    int firstNum;
    int secNum;
    int inputAns;
    int correctAns;
    bool result;

    generateOperands(oprtr, maxNum, firstNum, secNum, inputAns);
    calculateCorrectAnswer(firstNum, secNum, oprtr, correctAns);
    checkAnswer(inputAns, correctAns, result);

    if (result) {
        return 1;
    }
    else {
        return 0;
    }

}






// This function will randomly generate each operand and concatenate it with the operator
// and allow the user to input an answer which will be sent to doOneProblem.
void generateOperands(char oprtr, int maxNum, int &firstNum, int &secNum, int &inputAns)
{

    firstNum = rand() % (maxNum + 1);
    secNum = rand() % (maxNum + 1);

    cout << firstNum << " " << oprtr << " " << secNum << " = ";
    cin	>> inputAns;

}






// This function will calculate the correct answer based on if-statements
// for each operator.
void calculateCorrectAnswer(int firstNum, int secNum, char oprtr, int &correctAns)
{

    if (oprtr == '+') {
        correctAns = (firstNum + secNum);
    }
    if (oprtr == '-') {
        correctAns = (firstNum - secNum);
    }
    if (oprtr == '*') {
        correctAns = (firstNum * secNum);
    }

}






// This function will output Correct or Incorrect depending on the users answer.
void checkAnswer(int inputAns, int correctAns, bool &result)
{

    if (inputAns == correctAns) {
        cout << "Correct" << endl;
        result = true;
    }
    else {
        cout << "Incorrect" << endl;
        result = false;
    }

}






/*

 Enter problems per set: 3

 Set #1
 ----------

 What is the maximum number for this set? 100

 23 + 66 = 89
 Correct
 68 + 75 = 143
 Correct
 83 + 76 = 150
 Incorrect

 Set #2
 ----------

 What is the maximum number for this set? 90

 6 - 12 = -6
 Correct
 27 - 63 = 35
 Incorrect
 9 - 64 = -55
 Correct

 Set #3
 ----------

 What is the maximum number for this set? 20

 1 * 20 = 20
 Correct
 19 * 19 = 360
 Incorrect
 4 * 13 = 56
 Incorrect

 Set #1:  You got 2.0 correct out of 3.0 for 66.7%
 Set #2:  You got 2.0 correct out of 3.0 for 66.7%
 Set #3:  You got 1.0 correct out of 3.0 for 33.3%
 Overall you got 5.0 correct out of 9.0 for 55.6%
 Program ended with exit code: 0

 */
