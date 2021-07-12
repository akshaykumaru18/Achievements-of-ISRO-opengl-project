#ifndef QUIZ_H
#define QUIZ_H

#include<stdio.h>

struct QuizFormat
{
    char question[10000];
    int crctChoice;
    char choices[4][1000];
} q1,q2,q3,q4;
class Quiz
{
public:
    void loadQuiz()
    {
        struct QuizFormat qes1 = {"Quiz fuck you",1,{"Choice a","Choice b","Choice c","Choice d"}};
        q1 = qes1;

        printf("\nQestion1 is %s",qes1.question);
    }
};


#endif // QUIZ_H
