#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include "GetImagePath.h"
#include "elipse.h"
#include "AryabattaMission.h"
#include "Quiz.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
AryabhataMission arbMission;
void loadABMissionImages();
void abSatellitePremetive();

static int window, returnMenu,value=0;

static int activeWindow = 1;

unsigned int introBG;
unsigned int nightBG;
unsigned int earthT;

//Aryabhata Mission
unsigned int abimg1;
unsigned int abimg2;

void drawSatellitePremitive();
void drawLines(int x1,int y1,int x2,int y2);
void abSatelliteEntry();

int scale_out_timer = 10;
float ab_entry_translate_x = 0;
float ab_entry_translate_y = 0;

float ab_entry_scale_x = 0.0;
float ab_entry_scale_y = 0.0;

float ab_entry_rotation_theta = 0;

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;


bool rebuildIntro = false;
bool rebuildM1 = false;


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


/* GLUT callback Handlers */



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


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

void displayIntro()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, introBG);
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

    glutSwapBuffers();
    if(!rebuildIntro)
    {
        rebuildIntro = true;
        glutPostRedisplay();
    }


}

void displayMenuWindow()
{
    //printf("DisplayMenu function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glClearColor(0, 0, 0,0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    displayText(2500,2500,1.0,0.0,0.0,1,"Menu Screen");

    glFlush();
    glutSwapBuffers();
}

void msAryabattaSatellite()
{

    //printf("milestoneRocketLaunch function called \n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //AryabhataMission abMission;

    drawSatellitePremitive();

    /* Title Start */
    glColor3f(1, 1, 1);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex3f(2100, 4700, 10);
    glVertex3f(3400, 4700, 10);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(2100, 4650, 10);
    glVertex3f(3400, 4650, 10);
    glEnd();
    glFlush();
    /* Title End */

    /* Visual Part start */



    /* Display Image 2 */

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, abimg2);
    glBegin(GL_QUADS);
    //first vertex (bottom, left)
    glVertex3f(3000, 1600, 10);
    glTexCoord2f(0, 0);

    //second vertex (top,left)
    glVertex3f(3000, 3000, 10);
    glTexCoord2f(0, 1);

    //third vertex (top,right)
    glVertex3f(3700, 3000, 10);
    glTexCoord2f(1, 1);

    //four vertex (bottom,right)
    glVertex3f(3700, 1600, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

    /* Display Image 1 */

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, abimg1);
    glBegin(GL_QUADS);
    //first vertex (bottom, left)
    glVertex3f(3800, 1600, 10);
    glTexCoord2f(0, 0);

    //second vertex (top,left)
    glVertex3f(3800, 3000, 10);
    glTexCoord2f(0, 1);

    //third vertex (top,right)
    glVertex3f(4900, 3000, 10);
    glTexCoord2f(1, 1);

    //four vertex (bottom,right)
    glVertex3f(4900, 1600, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);




    /* Visual Part end */


    /* Content Part*/
    displayText(2200,4800,1.0,1.0,1.0,1,"Milestone 1 : First Rocket Launch");
    displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : April 19, 1975");
    displayText(2800,4200,1.0,1.0,1.0,1,"Weight : 360 kg");
    displayText(2800,4000,1.0,1.0,1.0,1,"Mission Life : 6 months(nominal), Spacecraft mainframe");
    displayText(2800,3800,1.0,1.0,1.0,1,"                       active till March,1981");
    displayText(2800,3600,1.0,1.0,1.0,1,"Description : 6 months(nominal), Spacecraft mainframe");
    displayText(2800,3400,1.0,1.0,1.0,1,"                       active till March,1981");



    //Quix section
    displayText(2800,1300,1.0,1.0,1.0,1,"Question : 1");
    displayText(2800,1000,1.0,1.0,1.0,1,"Option A");
    displayText(2800,800,1.0,1.0,1.0,1,"Option B");
    displayText(2800,600,1.0,1.0,1.0,1,"Option C");
    displayText(2800,400,1.0,1.0,1.0,1,"Option D");


    arbMission.drawEarth(earthT);
    arbMission.drawBGTexture(nightBG);


    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    glFlush();





    glutSwapBuffers();
    if(!rebuildM1)
    {
        rebuildM1 = true;
        glutPostRedisplay();
    }



}



void drawSatellitePremitive()
{


    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // glRotatef(ab_entry_rotation_theta,0,1,0);
    //glRotatef(ab_entry_rotation_theta,1,0,0);
    // glRotatef(ab_entry_rotation_theta,0,0,1);




    glScalef(arbMission.ab_entry_scale_x, arbMission.ab_entry_scale_y,1);
    glTranslated(arbMission.ab_entry_translate_x, arbMission.ab_entry_translate_y,0);
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

void abSatelliteEntry(void)
{


    if(arbMission.ab_entry_translate_x < 900.0 && arbMission.ab_entry_translate_y < 1600)
    {
        printf("Hello translate %f \t %f\n",arbMission.ab_entry_translate_x,arbMission.ab_entry_translate_y);
        int i = 0;

        arbMission.ab_entry_translate_x += 20;
        arbMission.ab_entry_translate_y += 40;
        glutPostRedisplay();

    }
    //Scaling
    if(arbMission.ab_entry_scale_x < 0.6)
    {
        printf("Hello scale %f \t %f\n",ab_entry_scale_x,ab_entry_scale_y);
        int i = 0;

        arbMission.ab_entry_scale_x += 0.005;
        arbMission.ab_entry_scale_y += 0.005;
        glutPostRedisplay();

    }


    //ab_entry_rotation_theta += 0.5;

    //Translating



}





void msFirstRocketLaunch()
{
    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 2 : First Rocket by ISRO");

    glFlush();
    glutSwapBuffers();
}

void msMangalyan()
{
    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();

    displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 3 : Mission Mangalyan");

    glFlush();
    glutSwapBuffers();
}

void ms104SatelliteLaunch()
{
    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();

    displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 4 : Mission 104 Satellite Launch");

    glFlush();
    glutSwapBuffers();
}

void ms5()
{
    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();

    displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 5 : Decide");

    glFlush();
    glutSwapBuffers();
}

void changeWindow(bool next)
{

    switch(activeWindow)
    {
    case 1:
        break;
    case 2:
        glutDisplayFunc(displayMenuWindow);

        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    }
    if(next)
    {
        activeWindow++;
    }
    else
    {
        activeWindow--;
    }

}

static void keyboardInput(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;
    case 'C':
    case 'c':
        printf("Key clicked is %c\n",key);
        //call menu window
        glutDisplayFunc(displayMenuWindow);
        //glutPostRedisplay();
        break;
    case 'S':
    case 's':
    case '1':
        ab_entry_translate_x = 0;
        ab_entry_translate_y = 0;
        ab_entry_scale_x = 0.0;
        ab_entry_scale_y = 0.0;
        loadABMissionImages();
        glutIdleFunc(abSatelliteEntry);
        glutDisplayFunc(msAryabattaSatellite);

        glutPostRedisplay();
        break;
    case '2':
        glutDisplayFunc(msFirstRocketLaunch);
        glutPostRedisplay();
        break;
    case '3':
        glutDisplayFunc(msMangalyan);
        glutPostRedisplay();
        break;
    case '4':
        glutDisplayFunc(ms104SatelliteLaunch);
        glutPostRedisplay();
        break;
    case '5':
        glutDisplayFunc(ms5);
        glutPostRedisplay();
        break;
    }

    //glutPostRedisplay();

}




void loadIntroScene(void)
{


    glGenTextures(1,&introBG);
    glBindTexture(GL_TEXTURE_2D,introBG);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width, height,channels;

    GetImagePath getImagePath;
    char *path = "\\final-intro.psd";
    path = getImagePath.getPath(&path,true);
    printf("\nPath is %s\n",path);
    unsigned char *data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);


    }
    else
    {
        std::cout << "Failed to load intro slide" << std::endl;
    }
    stbi_image_free(data);
    std::cout << "done" << std::endl;


}

void loadABMissionImages(void)
{
    GetImagePath getImagePath;



    /* Image 1 */
    glGenTextures(1,&abimg1);
    glBindTexture(GL_TEXTURE_2D,abimg1);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width, height,channels;
    unsigned char *data;
    char *path = "\\images\\psds\\aryabatta-img1.psd";
    path = getImagePath.getPath(&path,true);
    //printf("\nAB image 1 Path is %s\n",path);
    data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        std::cout << "done loading aryabhata image 1" << std::endl;
    }
    else
    {
        std::cout << "Failed to load aryabhata image 1" << std::endl;
    }
    stbi_image_free(data);


    /* Image 2 */
    glGenTextures(1,&abimg2);
    glBindTexture(GL_TEXTURE_2D,abimg2);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    path = "\\images\\psds\\aryabatta-img2.psd";
    path = getImagePath.getPath(&path,true);
    //printf("\nAB image 1 Path is %s\n",path);
    data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        std::cout << "done loading aryabhata image 2" << std::endl;
    }
    else
    {
        std::cout << "Failed to load aryabhata image 2" << std::endl;
    }
    stbi_image_free(data);


    /* Night background loading */
    glGenTextures(1,&nightBG);
    glBindTexture(GL_TEXTURE_2D,nightBG);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    path = "\\images\\psds\\nightBG.psd";
    path = getImagePath.getPath(&path,true);
    //printf("\nAB image 1 Path is %s\n",path);
    data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        std::cout << "done loading NIGHT BG" << std::endl;
    }
    else
    {
        std::cout << "Failed to load NIGHT BG" << std::endl;
    }
    stbi_image_free(data);

    /* Earth loading */
    glGenTextures(1,&earthT);
    glBindTexture(GL_TEXTURE_2D,earthT);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    path = "\\images\\psds\\earth.psd";
    path = getImagePath.getPath(&path,true);
    //printf("\nAB image 1 Path is %s\n",path);
    data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        std::cout << "done loading Earth" << std::endl;
    }
    else
    {
        std::cout << "Failed to load Earth" << std::endl;
    }
    stbi_image_free(data);

    //glutIdleFunc(idle);

}


void  mouse(int btn, int state, int x, int y)
{
    /* mouse callback, selects an axis about which to rotate */
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;
}


void init(int w, int h)
{

    printf("Width and Hight : \t %d \t %d\n",w,h);
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    printf("top %f",(h/w));

    glLoadIdentity();
    /* if(w<=h)
     {

         glOrtho(0, 5000, 0, 5000.0 * (GLfloat) h / (GLfloat) w, -500.0, 500.0);
     }
     else{
         glOrtho(0, 5000.0 * (GLfloat) w / (GLfloat) h, 0, 5000.0, -500.0, 500.0);
     }
     */

    glOrtho(0, 5000, 0, 5000, 500, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0);

    Quiz quiz;
    quiz.loadQuiz();

}


void menu(int n)
{
    if(n==0)
    {
        glutDestroyMenu(window);
        exit(0);
    }
    else
    {
        value = n;
        if(value == 1)
        {

        }
        else if(value == 2)
        {

        }
        else if(value == 3)
        {

        }
    }


    glutPostRedisplay();
}
void createMenu()
{
    returnMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Exit",0);
    glutAddMenuEntry("Previous",1);
    glutAddMenuEntry("Next",2);
    glutAddMenuEntry("Menu",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(1500,800);
    glutInitWindowPosition(0,0);

    window  = glutCreateWindow("Achievements of ISRO");

    createMenu();
    glutDisplayFunc(displayIntro);

    //glutDisplayFunc(displayMenuWindow);

    loadIntroScene();

    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouse);

    glutReshapeFunc(init);


    glEnable(GL_DEPTH_TEST);
    //init();
    glutMainLoop();
    return EXIT_SUCCESS;
}


