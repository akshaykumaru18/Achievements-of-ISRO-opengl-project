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
public:
    void displayText(int x,int y,float r,float g,float b,int font,char *string)
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
public:
    void semicircle(float radius,float u,float v)
    {

        glColor3f(1.0,1.0,1.0);
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
        for(i=0; i<=20; i++)
        {
            if(count<=300)
            {
                //glClearColor(0.0,0.0,0.0,1.0);
                //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
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

                //glutSwapBuffers();
                glFlush();
            }
        }

    }

public:
    void rohinisatellite()
    {


        //left antannae
        drawLines(300,2700,200,2900);
        drawLines(200,2900,260,4200);
        //left centre antenna
        drawLines(1000,2600,900,2800);
        drawLines(900,2800,800,4400);
        //right centre antanna
        drawLines(1700,2700,1800,2800);
        drawLines(1800,2800,1900,4400);
        //right antanna
        drawLines(2400,2700,2500,2900);
        drawLines(2500,2900,2600,4200);

        drawLines(1000,3800,1700,3800);
        //grey matter
        glColor3f(0.3,0.3,0.3);
        glBegin(GL_POLYGON);
        glVertex3f(1237.5,1925,10);  //bottom left
        glVertex3f(1237.5,2375,10); //top left
        glVertex3f(1462.5,2375,10); //top right
        glVertex3f(1462.5,1925,10); //bottom right
        glEnd();

        //centre square
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex3f(1100,1700,10);  //bottom left
        glVertex3f(1100,2600,10); //top left
        glVertex3f(1600,2600,10); //top right
        glVertex3f(1600,1700,10); //bottom right
        glEnd();

        //satellite top
        /* left Part Start*/
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_POLYGON);
        glVertex3f(300,2700,10);  //bottom left
        // glVertex3f(800,3800,10); //top left
        glVertex3f(1000,3800,10); //top right
        glVertex3f(800,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //vertical lines
        // drawLines(200,2700,800,3800);
        drawLines(300,2700,1000,3800);
        drawLines(400,2700,1000,3800);
        drawLines(500,2700,1000,3800);
        drawLines(600,2700,1000,3800);
        drawLines(700,2700,1000,3800);
        drawLines(800,2700,1000,3800);

        //horizontal lines
        drawLines(300,2700,800,2700);
        drawLines(380,2800,820,2800);
        drawLines(470,3000,850,3000);
        drawLines(600,3200,900,3200);
        drawLines(730,3400,930,3400);
        //drawLines(750,3600,960,3600);
        //  drawLines(1000,3800,1000,3800);

        /* left Part End*/
        /* Middle Part Start*/
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_QUADS);
        glVertex3f(1000,2700,10);  //bottom left
        glVertex3f(1200,3800,10); //top left
        glVertex3f(1500,3800,10); //top right
        glVertex3f(1700,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        //drawLines(900,2700,1100,3800);
        drawLines(1020,2700,1200,3800);
        drawLines(1100,2700,1250,3800);
        drawLines(1650,2700,1500,3800);
        drawLines(1550,2700,1450,3800);
        // drawLines(1800,2700,1600,3800);

        //horizontal lines
        //   drawLines(1100,3800,1540,3800);
        drawLines(1020,2800,1680,2800);
        drawLines(1040,3000,1640,3000);

        drawLines(1120,3400,1620,3400);
        drawLines(1140,3600,1500,3600);
        drawLines(1000,2700,1700,2700);

        /* Middle Part End*/



        /* Right Part Start*/
        //right
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_POLYGON);
        glVertex3f(1900,2700,10);  //bottom left
        glVertex3f(1700,3800,10); //top left
        //  glVertex3f(1900,3800,10); //top right
        glVertex3f(2380,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(1900,2700,1700,3800);
        drawLines(1980,2700,1700,3800);
        drawLines(2180,2700,1700,3800);
        drawLines(2380,2700,1700,3800);
        drawLines(2380,2700,1700,3800);
        // drawLines(2480,2700,1850,3800);
        // drawLines(2600,2700,1900,3800);

        //horizontal lines
        drawLines(1900,2700,2380,2700);
        drawLines(1880,2800,2340,2800);
        drawLines(1860,3000,2220,3000);
        drawLines(1810,3200,2100,3200);
        drawLines(1780,3400,1940,3400);
        drawLines(1740,3600,1820,3600);
        //    drawLines(1700,3800,1900,3800);

        /* Right Part End*/


        //satellite body

        //left
        /*Left Part Start */
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_QUADS);
        glVertex3f(300,1600,10);  //bottom left
        glVertex3f(300,2700,10); //top left
        glVertex3f(800,2700,10); //top right
        glVertex3f(800,1600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        // drawLines(200,1600,200,2700);
        drawLines(300,1600,300,2700);
        drawLines(400,1600,400,2700);
        drawLines(500,1600,500,2700);
        drawLines(600,1600,600,2700);
        drawLines(700,1600,700,2700);
        drawLines(800,1600,800,2700);

        //horizontal lines
        drawLines(300,1750,800,1750);
        drawLines(300,2000,800,2000);
        drawLines(300,2250,800,2250);
        drawLines(300,2500,800,2500);

        /*Left Part End */
        //middle
        /*Middle Side Start*/
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_QUADS);
        glVertex3f(1000,1600,10);  //bottom left
        glVertex3f(1000,2700,10); //top left
        glVertex3f(1700,2700,10); //top right
        glVertex3f(1700,1600,10); //bottom right
        glEnd();

        // drawLines(900,1600,900,2700);
        drawLines(1000,1600,1000,2700);
        drawLines(1100,1600,1100,2700);
        drawLines(1200,1600,1200,2700);
        drawLines(1300,1600,1300,2700);
        drawLines(1400,1600,1400,2700);
        drawLines(1500,1600,1500,2700);
        drawLines(1600,1600,1600,2700);
        drawLines(1700,1600,1700,2700);
        // drawLines(1800,1600,1800,2700);

        //horizontal lines
        drawLines(1000,1750,1700,1750);
        drawLines(1000,2000,1700,2000);
        drawLines(1000,2250,1700,2250);
        drawLines(1000,2500,1700,2500);

        /*Middle Side End*/

        //right
        /*Right Side Start*/
        glColor3f(0.309,0.1843,0.309);
        glBegin(GL_QUADS);
        glVertex3f(1900,1600,10);  //bottom left
        glVertex3f(1900,2700,10); //top left
        glVertex3f(2400,2700,10); //top right
        glVertex3f(2400,1600,10); //bottom right
        glEnd();

        //right centre vertical lines
        drawLines(1900,1600,1900,2700);
        drawLines(2000,1600,2000,2700);
        drawLines(2100,1600,2100,2700);
        drawLines(2200,1600,2200,2700);
        drawLines(2300,1600,2300,2700);
        drawLines(2400,1600,2400,2700);
        //drawLines(2500,1600,2500,2700);
        // drawLines(2600,1600,2600,2700);


        //horizontal lines
        drawLines(1900,1750,2400,1750);
        drawLines(1900,2000,2400,2000);
        drawLines(1900,2250,2400,2250);
        drawLines(1900,2500,2400,2500);

        //ANTENNA
        //drawLines(900,1600,900,2400);
        //Satellite drawing end
        drawLines(300,1600,2400,1600);
        //black strip right up
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(1750,2700,10);  //bottom left
        glVertex3f(1550,3800,10); //top left
        glVertex3f(1650,3800,10); //top right
        glVertex3f(1850,2700,10); //bottom right
        glEnd();

        //black below left strip
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(850,2700,10);  //bottom left
        glVertex3f(850,1600,10); //top left
        glVertex3f(950,1600,10); //top right
        glVertex3f(950,2700,10); //bottom right
        glEnd();

        //black top left strip
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(850,2700,10);  //bottom left
        glVertex3f(1050,3800,10); //top left
        glVertex3f(1150,3800,10); //top right
        glVertex3f(950,2700,10); //bottom right
        glEnd();

        //below black right strip
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(1750,2700,10);  //bottom left
        glVertex3f(1750,1600,10); //top left
        glVertex3f(1850,1600,10); //top right
        glVertex3f(1850,2700,10); //bottom right
        glEnd();


        //below right strip
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex3f(1725,2700,10);  //bottom left
        glVertex3f(1725,1600,10); //top left
        glVertex3f(1875,1600,10); //top right
        glVertex3f(1875,2700,10); //bottom right
        glEnd();

        //below left strip
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex3f(825,2700,10);  //bottom left
        glVertex3f(825,1600,10); //top left
        glVertex3f(975,1600,10); //top right
        glVertex3f(975,2700,10); //bottom right
        glEnd();

        //top left strip
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex3f(825,2700,10);  //bottom left
        glVertex3f(1025,3800,10); //top left
        glVertex3f(1175,3800,10); //top right
        glVertex3f(975,2700,10); //bottom right
        glEnd();

        //top right strip
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex3f(1725,2700,10);  //bottom left
        glVertex3f(1525,3800,10); //top left
        glVertex3f(1675,3800,10); //top right
        glVertex3f(1875,2700,10); //bottom right
        glEnd();

        glPopMatrix();
        glutPostRedisplay();


    }

    void drawLines(int x1,int y1,int x2,int y2)
    {
        glColor4f(1, 1, 1,1);
        glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
        glFlush();
    }


};

#endif // SLVMISSION_H
