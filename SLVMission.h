#ifndef SLVMISSION_H
#define SLVMISSION_H
#include <GL/glut.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
const float DEG2RAD = 3.14159/180;
int p;
void static_rocket();
void rocket_to_cam_pos();
void rocket_in_motion();
void mars(float radius);
class SlvMission
{
public:
    float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;
     //float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0;
    int p;
   public: void displayText(int x,int y,float r,float g,float b,int font,char *string)
{
    //void *f = (int *)font;
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {

        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
    return;
}
   public: void semicircle(float radius,float u,float v)
{

	glColor3f(1.0 ,1.0 ,1.0);
   glBegin(GL_POLYGON);

   for (int i=135; i<=315; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

    displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : 18 July 1980, 08:01:00 IST");
    displayText(2800,4200,1.0,1.0,1.0,1,"Mass : 35 kg");
    displayText(2800,4000,1.0,1.0,1.0,1,"Mission Life : 1.2 years");


   glEnd();
}

public:
    void rocket_to_cam_pos()
{

   count++;
    count3++;

    glClearColor(1,1,1,1);
    for(i=0; i<=100; i++)
    {
        if(count<=3){
        glClearColor(0.0 ,0.0 ,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(245.5,120+i); //left bottom point
        glVertex2f(264.5,120+i); //right bottom point
        glVertex2f(264.5,180+i);//top right point
        glVertex2f(245.5,180+i);//top left point
        glEnd();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(242.5,100+i); //left bottom point
        glVertex2f(267.5,100+i); //right bottom point
        glVertex2f(267.5,60+i);//top right point
        glVertex2f(242.5,60+i);//top left point
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(242.5,60+i); //left bottom point
        glVertex2f(267.5,60+i); //right bottom point
        glVertex2f(267.5,40+i);//top right point
        glVertex2f(242.5,40+i);//top left point
        glEnd();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(242.5,40+i); //left bottom point
        glVertex2f(267.5,40+i); //right bottom point
        glVertex2f(267.5,20+i);//top right point
        glVertex2f(242.5,20+i);//top left point
        glEnd();

          glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//left exhaust
        glVertex2f(242.5,30+i);
        glVertex2f(242.5,20+i);
        glVertex2f(229.5,20+i);
        glEnd();

           glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);//left exhaust
        glVertex2f(267.5,30+i);
        glVertex2f(267.5,20+i);
        glVertex2f(280.5,20+i);
        glEnd();

	glBegin(GL_LINES);
        glVertex2f(245.5,214.0+i); //flag saffrom
        glVertex2f(264.5,214.0+i);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_LINES);
        glVertex2f(245.5,212.0+i); //flag white
        glVertex2f(264.5,212.0+i);
        glEnd();
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_LINES);
        glVertex2f(245.5,210.0+i); //flag green
        glVertex2f(264.5,210.0+i);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(245.5,20+i); //left bottom point
        glVertex2f(264.5,20+i); //right bottom point
        glVertex2f(264.5,220+i);//top right point
        glVertex2f(245.5,220+i);//top left point
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);//core
        glVertex2f(242.5,100+i); //left bottom point
        glVertex2f(267.5,100+i); //right bottom point
        glVertex2f(250.5,120+i);//top right point
        glEnd();
//BONNET
        glColor3f(1.0,1.0,1.0);//downward tri
        glBegin(GL_POLYGON);//front
        glVertex2f(245.5,220.0+i);
         glVertex2f(255,238.0+i); //Traingle Bottom
        glVertex2f(264.5,220.0+i); //Tri Bottom n

        glEnd();
        glColor3f(1.0,0.5,0.0);

        glColor3f(0.0,0.0,1.0);
        glBegin(GL_POINTS);
        //glEnable(GL_PROGRAM_POINT_SIZE_EXT); //not working
        glPointSize(10000);//not working
        glVertex2f(250.5,210.0+i);
        glEnd();
          ;

        //Previous Outer Projection-

      /*  glColor3f(1,1,1);//left body
        glBegin(GL_POLYGON);
        glVertex2f(235.5,20.0+i);
        glVertex2f(235.5,120.0+i);
        glVertex2f(220.5,120.0+i);
        glVertex2f(220.5,20.0+i);
        glEnd();
        glColor3f(0.2,0.2,0.2);
        glBegin(GL_LINES);
        glVertex2f(235.5,20.0+i);
        glVertex2f(235.5,120.0+i);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(235.5,120.0+i);
        glVertex2f(220.5,120.0+i);
        glVertex2f(228,140.0+i);
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);//right body
        glVertex2f(264.5,20.0+i);
        glVertex2f(264.5,120.0+i);
        glVertex2f(280.5,120.0+i);
        glVertex2f(280.5,20.0+i);
        glEnd();
        glColor3f(0.2,0.2,0.2);
        glBegin(GL_LINES);
        glVertex2f(264.5,20.0+i);
        glVertex2f(264.5,120.0+i);
        glEnd();
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(264.5,120.0+i);
        glVertex2f(280.5,120.0+i);
        glVertex2f(270,140.0+i);
        glEnd();*/
        if((p%2)==0)
            glColor3f(1.0,0.25,0.0);
        else
            glColor3f(1.0,0.816,0.0);

        glBegin(GL_POLYGON);//outer fume
        glVertex2f(245.5,20+i);
        glVertex2f(234.16,16.66+i);
        glVertex2f(230.82,13.32+i);
        glVertex2f(227.48,9.98+i);
        glVertex2f(224.14,6.64+i);
        glVertex2f(220.8,3.3+i);
        glVertex2f(217.5,0+i);
        glVertex2f(221.56,-5+i);
        glVertex2f(225.62,-10+i);
        glVertex2f(229.68,-15+i);
        glVertex2f(233.74,-20+i);
        glVertex2f(237.8,-25+i);
        glVertex2f(241.86,-30+i);
        glVertex2f(245.92,-35+i);
        glVertex2f(250,-40+i);
        glVertex2f(254.06,-35+i);
        glVertex2f(258.12,-30+i);
        glVertex2f(262.18,-25+i);
        glVertex2f(266.24,-20+i);
        glVertex2f(270.3,-15+i);
        glVertex2f(274.36,-10+i);
        glVertex2f(278.42,-5+i);
        glVertex2f(282.5,0+i);
        glVertex2f(278.5,4+i);
        glVertex2f(274.5,8+i);
        glVertex2f(270.5,12+i);
        glVertex2f(266.5,16+i);
        glVertex2f(262.5,20+i);//28 points
        glEnd();

        if((p%2)==0)
            glColor3f(1.0,0.816,0.0);
        else
            glColor3f(1.0,0.25,0.0);

        glBegin(GL_POLYGON);//inner fume
        glVertex2f(237.5,20+i);
        glVertex2f(236.5,17.5+i);
        glVertex2f(235.5,15+i);
        glVertex2f(234.5,12.5+i);
        glVertex2f(233.5,10+i);
        glVertex2f(232.5,7.5+i);
        glVertex2f(236,5+i);
        glVertex2f(239.5,2.5+i);
        glVertex2f(243,0+i);
        glVertex2f(246.5,-2.5+i);
        glVertex2f(250,-5+i);
        glVertex2f(253.5,-2.5+i);
        glVertex2f(257,0+i);
        glVertex2f(260.5,2.5+i);
        glVertex2f(264,5+i);
        glVertex2f(267.5,7.5+i);
        glVertex2f(266.5,10+i);
        glVertex2f(265.5,12.5+i);
        glVertex2f(264.5,15+i);
        glVertex2f(263.5,17.5+i);
        glVertex2f(262.5,20+i);//21 points

        glEnd();
        p=p+1;
        for(j=0; j<=1000000; j++);
           glutPostRedisplay();
           glutSwapBuffers();
        glFlush();
    }
    }
}


};

#endif // SLVMISSION_H
