#ifndef ARYABATTAMISSION_H
#define ARYABATTAMISSION_H
#include "GetImagePath.h"
#include <GL/glut.h>
#include <stdio.h>
class AryabhataMission
{

public:
    int scale_out_timer = 10;

    bool entry_anm_completed = false;

    bool sat_to_earth_com = false;
    float ab_entry_translate_x = 0;
    float ab_entry_translate_y = 0;

    float ab_entry_scale_x = 0.0;
    float ab_entry_scale_y = 0.0;


public:
    void drawBGTexture(unsigned int texture)
    {
        //printf("drawBGTexture called\n");
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glVertex3f(0, 0, 10);
        glTexCoord2f(0, 0);
        glVertex3f(0, 5000, 10);
        glTexCoord2f(0, 1);
        glVertex3f(5000, 5000, 10);
        glTexCoord2f(1, 1);
        glVertex3f(5000, 0, 10);
        glTexCoord2f(1, 0);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);


    }

    void drawEarth(unsigned int texture)
    {
        //printf("drawBGTexture called\n");
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glVertex3f(0, -500, 10);
        glTexCoord2f(0, 0);
        glVertex3f(0, 1500, 10);
        glTexCoord2f(0, 1);
        glVertex3f(1000, 1500, 10);
        glTexCoord2f(1, 1);
        glVertex3f(1000,-500, 10);
        glTexCoord2f(1, 0);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);


    }


    void drawSatellitePremitive()
    {




        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        glScalef(ab_entry_scale_x, ab_entry_scale_y,1);
        glTranslated(ab_entry_translate_x, ab_entry_translate_y,0);


        //drawLines(1700,2400,1200,2000);
        //drawLines(1700,2400,1500,2000);



        // drawLines(1200,1300,1400,1650);
        // drawLines(900,1700,1100,1900);
        Elipse elipse;
        elipse.setColor(1,1,1);
        // elipse.draw(1350,3200,90,110,10,false,0,360);
        // elipse.draw(1350,1100,90,110,10,false,0,360);
        // glRotated(ab_entry_rotation_theta,0,1,0);
        // glRotated(ab_entry_rotation_theta,0,0,1);
        //glRotated(ab_entry_rotation_theta,1,0,0);


        //Satellite drawing start

        //Antenna 1
        glColor4f(1.0, 1, 0.0,1);
        glBegin(GL_QUADS);
        glVertex3f(1800,1900,10);  //bottom left
        glVertex3f(2500,4400,10); //top left
        glVertex3f(1850,1900,10); //top right
        glVertex3f(2500,4400,10); //bottom right
        glEnd();

        //Antenna 2
        glColor4f(1.0, 1, 0.0,1);
        glBegin(GL_QUADS);
        glVertex3f(850,1900,10);  //bottom left
        glVertex3f(100,4400,10); //top left
        glVertex3f(900,1850,10); //top right
        glVertex3f(100,4400,10); //bottom right
        glEnd();
        glFlush();
        drawLines(800,3800,1900,3800);



        //satellite top
        /* left Part Start*/
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(200,2700,10);  //bottom left
        glVertex3f(800,3800,10); //top left
        glVertex3f(1000,3800,10); //top right
        glVertex3f(800,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //vertical lines
        drawLines(200,2700,800,3800);
        drawLines(300,2700,840,3800);
        drawLines(400,2700,880,3800);
        drawLines(500,2700,920,3800);
        drawLines(600,2700,960,3800);
        drawLines(700,2700,1000,3800);
        drawLines(800,2700,1000,3800);

        //horizontal lines
        drawLines(200,2700,800,2700);
        drawLines(250,2800,820,2800);
        drawLines(350,3000,850,3000);
        drawLines(460,3200,900,3200);
        drawLines(570,3400,930,3400);
        drawLines(700,3600,960,3600);
        drawLines(800,3800,1000,3800);

        /* left Part End*/
        /* Middle Part Start*/
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(900,2700,10);  //bottom left
        glVertex3f(1100,3800,10); //top left
        glVertex3f(1600,3800,10); //top right
        glVertex3f(1800,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(900,2700,1100,3800);
        drawLines(1020,2700,1200,3800);
        drawLines(1100,2700,1250,3800);
        drawLines(1650,2700,1500,3800);
        drawLines(1550,2700,1450,3800);
        drawLines(1800,2700,1600,3800);

        //horizontal lines
        drawLines(1100,3800,1600,3800);
        drawLines(900,2800,1800,2800);
        drawLines(950,3000,1750,3000);

        drawLines(1020,3400,1680,3400);
        drawLines(1060,3600,1640,3600);
        drawLines(900,2700,1800,2700);

        /* Middle Part End*/



        /* Right Part Start*/
        //right
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(1900,2700,10);  //bottom left
        glVertex3f(1700,3800,10); //top left
        glVertex3f(1900,3800,10); //top right
        glVertex3f(2600,2700,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(1900,2700,1700,3800);
        drawLines(1980,2700,1700,3800);
        drawLines(2180,2700,1750,3800);
        drawLines(2380,2700,1800,3800);
        drawLines(2480,2700,1850,3800);
        drawLines(2600,2700,1900,3800);

        //horizontal lines
        drawLines(1900,2700,2600,2700);
        drawLines(1880,2800,2550,2800);
        drawLines(1860,3000,2400,3000);
        drawLines(1810,3200,2290,3200);
        drawLines(1780,3400,2170,3400);
        drawLines(1740,3600,2050,3600);
        drawLines(1700,3800,1900,3800);

        /* Right Part End*/


        //satellite body

        //left
        /*Left Part Start */
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(200,1600,10);  //bottom left
        glVertex3f(200,2700,10); //top left
        glVertex3f(800,2700,10); //top right
        glVertex3f(800,1600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(200,1600,200,2700);
        drawLines(300,1600,300,2700);
        drawLines(400,1600,400,2700);
        drawLines(500,1600,500,2700);
        drawLines(600,1600,600,2700);
        drawLines(700,1600,700,2700);
        drawLines(800,1600,800,2700);

        //horizontal lines
        drawLines(200,1750,800,1750);
        drawLines(200,2000,800,2000);
        drawLines(200,2250,800,2250);
        drawLines(200,2500,800,2500);

        /*Left Part End */
        //middle
        /*Middle Side Start*/
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(900,1600,10);  //bottom left
        glVertex3f(900,2700,10); //top left
        glVertex3f(1800,2700,10); //top right
        glVertex3f(1800,1600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(900,1600,900,2700);
        drawLines(1000,1600,1000,2700);
        drawLines(1100,1600,1100,2700);
        drawLines(1200,1600,1200,2700);
        drawLines(1300,1600,1300,2700);
        drawLines(1400,1600,1400,2700);
        drawLines(1500,1600,1500,2700);
        drawLines(1600,1600,1600,2700);
        drawLines(1700,1600,1700,2700);
        drawLines(1800,1600,1800,2700);

        //horizontal lines
        drawLines(900,1750,1800,1750);
        drawLines(900,2000,1800,2000);
        drawLines(900,2250,1800,2250);
        drawLines(900,2500,1800,2500);

        /*Middle Side End*/

        //right
        /*Right Side Start*/
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(1900,1600,10);  //bottom left
        glVertex3f(1900,2700,10); //top left
        glVertex3f(2600,2700,10); //top right
        glVertex3f(2600,1600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(1900,1600,1900,2700);
        drawLines(2000,1600,2000,2700);
        drawLines(2100,1600,2100,2700);
        drawLines(2200,1600,2200,2700);
        drawLines(2300,1600,2300,2700);
        drawLines(2400,1600,2400,2700);
        drawLines(2500,1600,2500,2700);
        drawLines(2600,1600,2600,2700);

        drawLines(900,1600,900,2700);
        drawLines(1000,1600,1000,2700);
        drawLines(1100,1600,1100,2700);
        drawLines(1200,1600,1200,2700);
        drawLines(1300,1600,1300,2700);
        drawLines(1400,1600,1400,2700);
        drawLines(1500,1600,1500,2700);
        drawLines(1600,1600,1600,2700);
        drawLines(1700,1600,1700,2700);
        drawLines(1800,1600,1800,2700);
        //horizontal lines
        drawLines(1900,1750,2600,1750);
        drawLines(1900,2000,2600,2000);
        drawLines(1900,2250,2600,2250);
        drawLines(1900,2500,2600,2500);

        /*Right Side End*/

        //satellite bottom

        //left
        /*Left part start*/
        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(800,600,10);  //bottom left
        glVertex3f(200,1600,10); //top left
        glVertex3f(800,1600,10); //top right
        glVertex3f(1000,600,10); //bottom right
        glEnd();

        //Solar panel lines
        //vertical lines
        drawLines(200,1600,800,600);
        drawLines(300,1600,840,600);
        drawLines(400,1600,880,600);
        drawLines(500,1600,920,600);
        drawLines(600,1600,960,600);
        drawLines(700,1600,980,600);
        drawLines(800,1600,1000,600);


        drawLines(200,1600,820,1600);
        drawLines(310,1400,840,1400);
        drawLines(440,1200,880,1200);
        drawLines(550,1000,930,1000);
        drawLines(660,800,960,800);
        drawLines(790,600,1000,600);


        /*Left part end*/

        //middle
        /*Middle Part Start*/


        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(1100,600,10);  //bottom left
        glVertex3f(900,1600,10); //top left
        glVertex3f(1800,1600,10); //top right
        glVertex3f(1600,600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(1100,600,900,1600);
        drawLines(1200,600,1000,1600);
        drawLines(1250,600,1100,1600);
        drawLines(1450,600,1550,1600);
        drawLines(1500,600,1650,1600);
        drawLines(1600,600,1800,1600);

        //horizontal lines
        drawLines(900,1600,1800,1600);
        drawLines(930,1500,1780,1500);
        drawLines(960,1250,1750,1250);
        drawLines(1030,900,1680,900);
        drawLines(1070,750,1630,750);
        drawLines(1090,600,1600,600);

        /*Middle Part End*/
        //right
        /*Right Part Start*/


        glColor4f(0.0, 0, 0.6,1);
        glBegin(GL_QUADS);
        glVertex3f(1700,600,10);  //bottom left
        glVertex3f(1900,1600,10); //top left
        glVertex3f(2600,1600,10); //top right
        glVertex3f(1900,600,10); //bottom right
        glEnd();

        //Solar panel lines
        //Vertical lines
        drawLines(1900,1600,1700,600);
        drawLines(1980,1600,1700,600);
        drawLines(2180,1600,1750,600);
        drawLines(2380,1600,1800,600);
        drawLines(2480,1600,1850,600);
        drawLines(2600,1600,1900,600);

        //horizontal lines
        drawLines(1900,1600,2600,1600);
        drawLines(1850,1400,2450,1400);
        drawLines(1830,1200,2330,1200);
        drawLines(1790,1000,2200,1000);
        drawLines(1730,800,2030,800);
        drawLines(1700,600,1900,600);


        /*Right Part End*/
        //Satellite drawing end
        drawLines(800,600,1900,600);


        //Antenna
        glColor4f(1.0, 1, 0.0,1);
        glBegin(GL_QUADS);
        glVertex3f(1800,1900,10);  //bottom left
        glVertex3f(2500,4400,10); //top left
        glVertex3f(1850,1900,10); //top right
        glVertex3f(2500,4400,10); //bottom right
        glEnd();

        glPopMatrix();
        glutPostRedisplay();


    }

    void drawLines(int x1,int y1,int x2,int y2)
{
    glColor4f(1, 1, 0,1);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFlush();
}



};

#endif // ARYABATTAMISSION_H_INCLUDED
