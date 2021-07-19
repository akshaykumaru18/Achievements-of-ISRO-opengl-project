#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include "GetImagePath.h"
#include "elipse.h"
#include "AryabattaMission.h"
#include "SLVMission.h"
#include "MomMission.h"
#include "Quiz.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"


AryabhataMission arbMission;
SlvMission slvMission;
MomMission momMission;
Quiz quiz;



void loadABMissionImages();
void abSatellitePremetive();
void showQuizResult(bool result);

static int window, returnMenu,value=0;

static int activeWindow = 1;

unsigned int introBG;
unsigned int nightBG;
unsigned int earthT;
unsigned int marsT;

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


float textOpacity = 1.0;
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


    glColor4f( r * textOpacity, g * textOpacity, b * textOpacity,0.1 );
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
    if(quiz.showAnswer)
        showQuizResult(quiz.result);


    glPushMatrix();
    glLoadIdentity();
    glRotatef(30,1,1,1);
    //glRotatef(30,0,5,0);
    arbMission.drawSatellitePremitive();
    // glRotatef(30,0,0,1);
    glPopMatrix();








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

    // float color[2] = {1.0,1.0,1.0};
    /* Content Part*/
    displayText(2200,4800,1.0,1.0,1.0,1,"Milestone 1 : First Rocket Launch");
    displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : April 19, 1975");
    displayText(2800,4200,1.0,1.0,1.0,1,"Weight : 360 kg");
    displayText(2800,4000,1.0,1.0,1.0,1,"Mission Life : 6 months(nominal), Spacecraft mainframe");
    displayText(2800,3800,1.0,1.0,1.0,1,"                       active till March,1981");
    displayText(2800,3600,1.0,1.0,1.0,1,"Description : 6 months(nominal), Spacecraft mainframe");
    displayText(2800,3400,1.0,1.0,1.0,1,"                       active till March,1981");



    struct QuizFormat q = quiz.readQuiz(activeWindow);
    // printf("Active question is %s",q.question);
    //Quix section
    displayText(2800,1300,1.0,1.0,1.0,1, q.question);
    displayText(2800,1000,1.0,1.0,1.0,1,q.choices[0]);
    displayText(2800,800,1.0,1.0,1.0,1,q.choices[1]);
    displayText(2800,600,1.0,1.0,1.0,1,q.choices[2]);
    displayText(2800,400,1.0,1.0,1.0,1,q.choices[3]);




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







void abSatelliteAnimation(void)
{




    if(!arbMission.entry_anm_completed && arbMission.ab_entry_translate_x < 2500.0)
    {

        arbMission.ab_entry_translate_x += 20;
        //arbMission.ab_entry_translate_y += 40;
        glutPostRedisplay();

    }

    if(!arbMission.entry_anm_completed &&  arbMission.ab_entry_translate_y < 3900)
    {

        arbMission.ab_entry_translate_y += 40;
        glutPostRedisplay();

    }
    //Scaling
    if(!arbMission.entry_anm_completed && arbMission.ab_entry_scale_x < 0.5)
    {
        // printf("Hello scale %f \t %f\n",ab_entry_scale_x,ab_entry_scale_y);
        int i = 0;

        arbMission.ab_entry_scale_x += 0.005;
        arbMission.ab_entry_scale_y += 0.005;
        glutPostRedisplay();

    }


    if(arbMission.entry_anm_completed && arbMission.scale_out_timer == 0)
    {
        if(arbMission.ab_entry_scale_x > 0.4)
        {
            arbMission.ab_entry_scale_x -= 0.005;
            arbMission.ab_entry_scale_y -= 0.005;

            arbMission.ab_entry_translate_x += 20;
            arbMission.ab_entry_translate_y += 40;

            glutPostRedisplay();
        }
    }


    //ab_entry_rotation_theta += 0.5;

    //Translating



}



float slvTranslate_y = -50;
float slvTranslate_x = 100;
float slvrotate_y = 0;
int rotate_sleep_cnt = 0;

void slvAnimation(void)
{


    if(slvTranslate_y < 200)
    {

        slvTranslate_y +=1;
        //arbMission.ab_entry_translate_y += 40;
        glutPostRedisplay();

    }
    if(rotate_sleep_cnt <20)
    {
        rotate_sleep_cnt++;
    }
    if(rotate_sleep_cnt == 20)
    {

        if(slvrotate_y <= 140)
        {
            slvrotate_y +=10;
            slvTranslate_x +=1;
        }
        rotate_sleep_cnt=0;
    }


}

void msFirstRocketLaunch()
{
    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    /* Title Start */
    glColor3f(1, 1, 1);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex3f(2000, 4750, 10);
    glVertex3f(3500, 4750, 10);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(2000, 4700, 10);
    glVertex3f(3500, 4700, 10);
    glEnd();
    glFlush();
    /* Title End */
    glPushMatrix();

    glScalef(5.0,8.0,0.0);
    glTranslated(slvTranslate_x,slvTranslate_y,0);

   // glRotated(slvrotate_y,1,1,0);
    //slvMission.rocket_in_motion();
    slvMission.rocket_to_cam_pos();
     glPopMatrix();
   // glScalef(5.0,8.0,0.0);
  // glTranslatef(2000,4800,0);
  glPushMatrix();
    slvMission.rohinisatellite();
    //glutIdleFunc(abSatelliteAnimation);
    //drawSatellitePremitive();
    glPopMatrix();
    // displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 2 : First Rocket by ISRO");
    displayText(2000,4800,1.0,1.0,1.0,1,"MILESTONE 2 : ROHINI SATELLITE RS-1");
    displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : 18 July 1980, 08:01:00 IST");
    displayText(2800,4200,1.0,1.0,1.0,1,"Mass : 35 kg");
    displayText(2800,4000,1.0,1.0,1.0,1,"Mission Life : 1.2 years");
    //displayText(2600,3600,1.0,1.0,1.0,1,"Description : Used for measuring in-flight performance of ");
    // displayText(2800,3400,1.0,1.0,1.0,1,"
    //displayText(2800,3400,1.0,1.0,1.0,1,"second experimental launch of SLV-3. This was India's first ");
    displayText(2800,3800,1.0,1.0,1.0,1,"Description : This was India's first indigenous satellite launch,");
    displayText(2800,3600,1.0,1.0,1.0,1,"Making it the Seventh Nation to possess the capability to launch its own satellites on its own rockets.");
    displayText(2800,3400,1.0,1.0,1.0,1,"its own Satellites on its own Rockets.");
    displayText(2800,3200,1.0,1.0,1.0,1,"Launch Vehicle : \t SLV-3-E2");
    displayText(2800,3000,1.0,1.0,1.0,1,"Launch site : \t Satish Dhawan Space centre, Sriharikota");
    glFlush();
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
}


float pslvRotate_y = 0;
float momTranslate_y = 0;
float momTranslate_x = 0;

int mom_rotate_sleep_cnt = 0;
bool stopRotation = false;
bool animationStarts = false;
bool showInfo = false;
bool showMOM = false;

void momAnimation(void)
{


    if(animationStarts)
    {
        if(momTranslate_y <= 4000)
        {

            momTranslate_y +=10;
            //arbMission.ab_entry_translate_y += 40;
            glutPostRedisplay();

        }
        if(momTranslate_x == 2400)
        {
            animationStarts = false;
            showMOM = true;
        }
        if(momTranslate_x <= 2400)
        {

            momTranslate_x +=10;
            //arbMission.ab_entry_translate_y += 40;
            glutPostRedisplay();

        }
        if(rotate_sleep_cnt <2)
        {
            rotate_sleep_cnt++;
        }
        if(!stopRotation && rotate_sleep_cnt == 2)
        {
            if(pslvRotate_y < 60)
            {
                pslvRotate_y +=1;
            }


            // pslvRotate_y +=10;
            if(pslvRotate_y >= 60 ||(pslvRotate_y >= 60 && pslvRotate_y < 140))
            {

                pslvRotate_y = 120;
                stopRotation = true;
                printf("rocket animation will stop \n");
            }
            rotate_sleep_cnt = 0;
        }
    }



}
struct RevolutionPath r;

int rv = 0;
float rx = 1000;
float ry = 0;
void revolveAroundMars(int)
{
    if(rv == 355)
    {
        rv = 0;
    }
    Elipse elipse;
    struct RevolutionPath  path = elipse.nextPoints(rv);

    //printf("Next %d \n",rv);
 printf("Current X Y is %f \t %f \n",path.x,path.y);
    if(path.x != 0.0 && path.y != 0.0)
    {
        rx = path.x;
        ry = path.y;
    }
//    if(rx == 0 && ry == 0)
//        {
//
//           printf("Next X Y is zero %f \t %f \n",rx,ry);
//
//        }
    if(path.x == 0 && path.y == 0)
        {
           printf("Next X Y is zero %f \t %f \n",rx,ry);

        }
    rv++;

    glutPostRedisplay();
   // glutTimerFunc(1000,revolveAroundMars,18);

}
void msMangalyan()
{

    // printf("msAryabattaSatellite function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(showMOM)
    {
        Elipse elipse;
        elipse.setColor(0.5,0.5,0.5);
        elipse.draw(3100,3100,1000,1500,1,0,360);

        glutTimerFunc(100,revolveAroundMars,18);
    //    glutIdleFunc();
        glPushMatrix();
        // glScalef(0.4,0.6,0.0);q
        // glTranslated(momTranslate_x,momTranslate_y,0);
        //glRotated(pslvRotate_y,80,80,0);

        glTranslated(3050,3100,0);
        glTranslated(rx,ry,0);
        glColor3f(1.0,1.0,1.0);
        momMission.mom_orbitor();

        glPopMatrix();



    }
    else
    {
        glPushMatrix();
        glScalef(0.4,0.6,0.0);
        glTranslated(momTranslate_x,momTranslate_y,0);
        glRotated(pslvRotate_y,80,80,0);
        momMission.pslv_rocket();
        glPopMatrix();
    }


    if(showInfo)
    {

        /* Title Start */
        glColor3f(1, 1, 1);
        glLineWidth(3.0);
        glBegin(GL_LINES);
        glVertex3f(1400, 4750, 10);
        glVertex3f(3900, 4750, 10);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(1400, 4700, 10);
        glVertex3f(3900, 4700, 10);
        glEnd();
        glFlush();
        /* Title End */
        displayText(1400,4800,1.0,1.0,1.0,1,"MILESTONE 3 :MARS ORBITER MISSION(MOM)-MANGALYAAN-1");
        displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : 5 November 2013, 14:38:00 IST");
        displayText(2800,4200,1.0,1.0,1.0,1,"Mass : 340 kg and 488 kg");
        displayText(2800,4000,1.0,1.0,1.0,1,"Power:840W");
        displayText(2800,3800,1.0,1.0,1.0,1,"Mission Life : 6 months(But currently its still running)");
        displayText(2800,3600,1.0,1.0,1.0,1,"Description : The Mars Orbiter Mission (MOM), informally ");
        // displayText(2800,3400,1.0,1.0,1.0,1,"
        displayText(2800,3400,1.0,1.0,1.0,1,"called Mangalyaan is India's first Mars orbiter  ");
        //displayText(2800,3200,1.0,1.0,1.0,1,"indigenous satellite launch, making it the seventh nation to possess the capability to launch its own satellites on its own rockets.  ");
        displayText(2800,3000,1.0,1.0,1.0,1,"Launch Vehicle:PSLV-C25");
        displayText(2800,2800,1.0,1.0,1.0,1,"Launch site: Satish Dhawan Space centre, Sriharikota");

    }


    glPushMatrix();

    glScalef(0.9,0.9,0.0);
    glTranslated(3000,3000,0);

    momMission.drawPlanet(marsT,0.5);
    glPopMatrix();
    arbMission.drawBGTexture(nightBG);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    glFlush();
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

    displayText(2500,4600,1.0,1.0,0.0,1,"MILESTONE 4 : PSLV-C37 (104 satellites Launch)");

    displayText(2800,4400,1.0,1.0,1.0,1,"Launch Date : 15 February 2017, 9:28:00 IST[");
    displayText(2800,4200,1.0,1.0,1.0,1,"Mass : 714 kg,8.4 kg and 9.7 kg");
    //displayText(2800,4000,1.0,1.0,1.0,1,"Power:840W");
    displayText(2800,3800,1.0,1.0,1.0,1,"Mission Life : Over 5 years");
    displayText(2800,3600,1.0,1.0,1.0,1,"Description : Its mission is identical to its predecessors (Resourcesat-1 and Resourcesat-2) ");
    // displayText(2800,3400,1.0,1.0,1.0,1,"
    displayText(2800,3400,1.0,1.0,1.0,1,"ISRO holds the world record for launching the highest number of satellites ");
    displayText(2800,3200,1.0,1.0,1.0,1,"by a single launch vehicle (104 satellites, including the CartoSat-2D and 2 indigenously designed nano-satellites, INS-1A and INS-1B)");
    displayText(2800,3000,1.0,1.0,1.0,1,"Launch Vehicle:PSLV-C25");
    displayText(2800,2800,1.0,1.0,1.0,1,"Launch site: Satish Dhawan Space centre, Sriharikota");

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

void showQuizResult(bool qr)
{
    if(qr)
    {

        glColor3f(0, 1, 0);
        glBegin(GL_QUADS);
        glVertex3f(4300, 500, 10);
        glVertex3f(4000, 800, 10);
        glVertex3f(4050, 800, 10);
        glVertex3f(4370, 500, 10);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(4300, 500, 10);
        glVertex3f(4700, 1300, 10);
        glVertex3f(4750, 1300, 10);
        glVertex3f(4370, 500, 10);
        glEnd();

        char res[10000];
        strcpy(res,"correct");
        strcat(res," : ");
        char *ch = &quiz.crctChoice;
        strcat(res,ch);
        displayText(4200,300,0,1,0,1,res);
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        glVertex3f(3900, 100, 10);
        glVertex3f(3900, 1500, 10);
        glVertex3f(4900, 1500, 10);
        glVertex3f(4900, 100, 10);
        glEnd();

        glFlush();
    }
    else
    {
        glColor3f(1,0, 0);
        glBegin(GL_QUADS);
        glVertex3f(4600, 500, 10);
        glVertex3f(4150, 1300, 10);
        glVertex3f(4200, 1300, 10);
        glVertex3f(4650, 500, 10);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(4150, 500, 10);
        glVertex3f(4600, 1300, 10);
        glVertex3f(4650, 1300, 10);
        glVertex3f(4200, 500, 10);
        glEnd();

        char res[10000];
        strcpy(res,"Correct");
        strcat(res," : ");
        char *ch = &quiz.crctChoice;
        strcat(res,ch);
        displayText(4200,300,1,0,0,1,res);

        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        glVertex3f(3900, 100, 10);
        glVertex3f(3900, 1500, 10);
        glVertex3f(4900, 1500, 10);
        glVertex3f(4900, 100, 10);
        glEnd();

        glFlush();
    }




}

static void keyboardInput(unsigned char key, int x, int y)
{
    bool result;
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;
        //case 'C':
        //case 'c':
        //  printf("Key clicked is %c\n",key);
        //call menu window
        // glutDisplayFunc(displayMenuWindow);
        //glutPostRedisplay();
        break;
    case 'S':
    case 's':
    case '1':
        arbMission.ab_entry_translate_x = 0;
        arbMission.ab_entry_translate_y = 0;
        arbMission.ab_entry_scale_x = 0.0;
        arbMission.ab_entry_scale_y = 0.0;
        arbMission.entry_anm_completed = false;
        activeWindow = 1;
        loadABMissionImages();
        glutIdleFunc(abSatelliteAnimation);

        glutDisplayFunc(msAryabattaSatellite);

        glutPostRedisplay();
        break;
    case '2':
        glutIdleFunc(slvAnimation);
        glutDisplayFunc(msFirstRocketLaunch);
        glutPostRedisplay();
        break;
    case '3':
        glutIdleFunc(momAnimation);
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

    case 'a':
    case 'A':

        result = quiz.validateQuiz(activeWindow,'a');
        printf("Result is %d\n", result);
        showQuizResult(result);
        break;

    case 'b':
    case 'B':

        result = quiz.validateQuiz(activeWindow,'b');
        printf("Result is %d\n", result);
        showQuizResult(result);
        break;
    case 'c':
    case 'C':

        result = quiz.validateQuiz(activeWindow,'c');
        printf("Result is %d\n", result);
        showQuizResult(result);
        break;

    case 'd':
    case 'D':

        result = quiz.validateQuiz(activeWindow,'d');
        printf("Result is %d\n", result);
        showQuizResult(result);
        break;

    case ' ':
        if(!showMOM)
            animationStarts = true;
        showInfo = false;
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
    path = getImagePath.getPath(&path,false);
    printf("\nPath is %s\n",path);
    unsigned char *data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);

    // unsigned char *data = stbi_load("C:\\Users\\Hp\\CGV\\Achievements-of-ISRO-opengl-project\\final-intro.psd", &width, &height, &channels, STBI_rgb_alpha);

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


    /* Night background loading */
    glGenTextures(1,&nightBG);
    glBindTexture(GL_TEXTURE_2D,nightBG);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    path = "\\images\\psds\\nightBG.psd";
    path = getImagePath.getPath(&path,false);
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
    path = getImagePath.getPath(&path,false);
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
    path = getImagePath.getPath(&path,false);
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






    //glutIdleFunc(idle);

}

void loadPlanets(void)
{
    GetImagePath getImagePath;
    /* Earth loading */
    glGenTextures(1,&earthT);
    glBindTexture(GL_TEXTURE_2D,earthT);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width, height,channels;
    unsigned char *data;
    char *path = "\\images\\psds\\earth.psd";
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

    /* Mars loading */
    glGenTextures(1,&marsT);
    glBindTexture(GL_TEXTURE_2D,marsT);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    path = "\\images\\psds\\mars-wbg.psd";
    path = getImagePath.getPath(&path,true);
    //printf("\nAB image 1 Path is %s\n",path);
    data = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        std::cout << "done loading Mars" << std::endl;
    }
    else
    {
        std::cout << "Failed to load Mars" << std::endl;
    }
    stbi_image_free(data);
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

    glOrtho(0, 5000, 0, 5000, 400, -500);

    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0);



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
            glutDisplayFunc(msAryabattaSatellite);
        }
        else if(value == 2)
        {
            glutDisplayFunc(msFirstRocketLaunch);
        }
        else if(value == 3)
        {
            glutDisplayFunc(msMangalyan);
        }
        else if(value == 4)
        {
            glutDisplayFunc(msMangalyan);
        }
        else if(value == 5)
        {
            glutDisplayFunc(ms104SatelliteLaunch);
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
    loadPlanets();

    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouse);

    glutReshapeFunc(init);


    glEnable(GL_DEPTH_TEST);

    //init();
    glutMainLoop();
    return EXIT_SUCCESS;
}


