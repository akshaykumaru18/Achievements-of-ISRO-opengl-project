#ifndef QUIZ_H
#define QUIZ_H

#include<stdio.h>

struct QuizFormat
{
    char question[10000];
    int crctChoice;
    char choices[4][1000];
};
class Quiz
{
public:
    struct QuizFormat questions[5];
public:
    void loadQuiz()
    {
        struct QuizFormat q1 = {"Where did rocket launched?",1,{"a) INDIA","b) Australia","C) RUSSIA","D) SRI LANKA"}};
        questions[0] = q1;



    }
    struct QuizFormat readQuiz(int activeWindow)
    {
       // printf("\nQestion1 is %d %s",activeWindow,questions[activeWindow-1].question);
        return  questions[activeWindow-1];
    }
};


#endif // QUIZ_H
