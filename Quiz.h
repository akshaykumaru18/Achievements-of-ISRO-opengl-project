#ifndef QUIZ_H
#define QUIZ_H

#include<stdio.h>

struct QuizFormat
{
    char question[10000];
    char crctChoice;
    char choices[4][1000];
};
class Quiz
{
public:
    struct QuizFormat questions[5];
    bool showAnswer = false;
    bool result = false;
    char crctChoice;
public:
    void loadQuiz()
    {
        struct QuizFormat q1 = {"Where did rocket launched?",'a',{"a) INDIA","b) Australia","C) RUSSIA","D) SRI LANKA"}};
        questions[0] = q1;



    }
    struct QuizFormat readQuiz(int activeWindow)
    {
        // printf("\nQestion1 is %d %s",activeWindow,questions[activeWindow-1].question);
        return  questions[activeWindow-1];
    }

    bool validateQuiz(int activeWindow,char choice)
    {
        // printf("\nQestion1 is %d %s",activeWindow,questions[activeWindow-1].question);
        if(questions[activeWindow-1].crctChoice == choice)
        {
             showAnswer = true;
             result = true;
             crctChoice = questions[activeWindow-1].crctChoice;
            return true;
        }
        else
        {

             showAnswer = true;
             result = false;
             crctChoice = questions[activeWindow-1].crctChoice;
            return false;
        }

    }

};


#endif // QUIZ_H
