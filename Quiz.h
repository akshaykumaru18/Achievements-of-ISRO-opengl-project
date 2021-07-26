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
        struct QuizFormat q1 = {"Where did rocket launched?",'c',{"a) INDIA","b) Australia","C) RUSSIA","D) SRI LANKA"}};
        struct QuizFormat q2 = {"India's first indigenous sounding rocket?",'b',{"a) SLV-3","b) RH-75","C) PSLV","D) GSLV Mk III"}};
        struct QuizFormat q3 = {"Who was the Project Director MOM Mission?",'b',{"a) INDIA","b) V Kesava Raju","C) V Koteswara Rao","D) K Sivan"}};
        questions[0] = q1;
        questions[1] = q2;
        questions[2] = q3;



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
