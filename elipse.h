#ifndef ELIPSE_H
#define ELIPSE_H
#include <GL/glut.h>
#include <math.h>
struct RevolutionPath
{
    float x;
    float y;
};
class Elipse
{
private:
    float color[3];
    int depthIndex;
public:
    struct RevolutionPath revolution[360];
public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }


    void draw1(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, int startAngle, int stopAngle)
    {
        float x,y;
        bool hollow = false;
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
        if (hollow)
        {
            glPointSize(3);
            glBegin(GL_POINTS);
        }
        else if (!hollow)
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {

             x = Rx * cos((i * 3.142) / 180);
             y = Ry * sin((i * 3.142) / 180);
        //printf("Revolution Path in loop : %f \t %f\n",x,y);
             struct RevolutionPath r = {x,y};
             revolution[(int)i] = r;
             glVertex3f(x, y, depthIndex);
             // printf("Revolution Path : %f \t %f\n",revolution[0].x,revolution[0].y);
        }

        glEnd();
        glPopMatrix();


    }

    void draw(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, int startAngle, int stopAngle)
    {
        float x,y;
        bool hollow = true;
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
        if (hollow)
        {
            glPointSize(3);
            glBegin(GL_POINTS);
        }
        else if (!hollow)

            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {

             x = Rx * cos((i * 3.142) / 180);
             y = Ry * sin((i * 3.142) / 180);
        //printf("Revolution Path in loop : %f \t %f\n",x,y);
             struct RevolutionPath r = {x,y};
             revolution[(int)i] = r;
             glVertex3f(x, y, depthIndex);
             // printf("Revolution Path : %f \t %f\n",revolution[0].x,revolution[0].y);
        }

        glEnd();
        glPopMatrix();


    }

    struct RevolutionPath nextPoints(int i){
        return revolution[i];
    };

};

#endif // ELIPSE_H
