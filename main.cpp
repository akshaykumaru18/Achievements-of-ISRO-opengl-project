#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

void loadABMissionImages();
void abSatellitePremetive();
bool rebuildIntro = true;
bool rebuildM1 = true;
static int window, returnMenu,value=0;

static int activeWindow = 1;

unsigned int introBG;

//Aryabhata Mission
unsigned int abimg1;
unsigned int abimg2;

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 0;





const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


/* GLUT callback Handlers */

char* getPath(char **path,bool isAk)
{
    printf("Given path is %s",*path);
    char akPath[] = "C:\\Users\\Akshay Kumar U\\cgv project\\Achievements-of-ISRO-opengl-project";
    char pkPath[] = "C:\\Users\\Hp\\CGV\\Achievements-of-ISRO-opengl-project";
    char finalPath[10000];
    if(isAk == true)
    {
        strcpy(finalPath,akPath);
        strcat(finalPath,*path);
        *path = finalPath;
        //printf("final path is %s",*path);
        return *path;
    }

    else
    {

        strcpy(finalPath,pkPath);
        strcat(finalPath,*path);
        *path = finalPath;
        //printf("final path is %s",*path);
        return *path;
    }
    //  return;

}
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
void spinSatellite()
{
   // printf("\nspinning in %d",theta[axis]);
    theta[axis] += 0.75;
    if(theta[axis] > 360.0)
            theta[axis] -= 360.0;

    glutPostRedisplay();

}
void msAryabattaSatellite()
{

    //  printf("milestoneRocketLaunch function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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



    abSatellitePremetive();

    /* Display Image 2 */

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, abimg2);
    glBegin(GL_QUADS);
    //first vertex (bottom, left)
    glVertex3f(2800, 1200, 10);
    glTexCoord2f(0, 0);

    //second vertex (top,left)
    glVertex3f(2800, 2800, 10);
    glTexCoord2f(0, 1);

    //third vertex (top,right)
    glVertex3f(3400, 2800, 10);
    glTexCoord2f(1, 1);

    //four vertex (bottom,right)
    glVertex3f(3400, 1200, 10);
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
    glVertex3f(3500, 1200, 10);
    glTexCoord2f(0, 0);

    //second vertex (top,left)
    glVertex3f(3500, 2800, 10);
    glTexCoord2f(0, 1);

    //third vertex (top,right)
    glVertex3f(4900, 2800, 10);
    glTexCoord2f(1, 1);

    //four vertex (bottom,right)
    glVertex3f(4900, 1200, 10);
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


    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    glFlush();
    glutSwapBuffers();
    if(rebuildM1)
    {
        glutPostRedisplay();
        rebuildM1 = false;
    }

}

void abSatellitePremetive()
{


    // printf("Theta value is %f of x \n",theta[0]);
    // printf("Theta value is %f of y \n",theta[1]);
    // printf("Theta value is %f of z \n",theta[2]);
    glPushMatrix();
    glLoadIdentity();


    glRotatef(theta[0], 0.0, 1.0, 0.0);






    /*FRONT FACE START */
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    //first vertex (bottom, left)
    glVertex3f(500, 1200, 500);


    //second vertex (top,left)
    glVertex3f(500, 3500, 500);


    //third vertex (top,right)
    glVertex3f(2000, 3500, 500);


    //four vertex (bottom,right)
    glVertex3f(2000, 1200, 500);
    glEnd();
    /*FRONT FACE END*/

    /*BACK FACE START */
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    //first vertex (bottom, left)
    glVertex3f(500, 1200, -500);


    //second vertex (top,left)
    glVertex3f(500, 3500, -500);


    //third vertex (top,right)
    glVertex3f(2000, 3500, -500);


    //four vertex (bottom,right)
    glVertex3f(2000, 1200, -500);
    glEnd();
    /*BACK FACE END*/

    /*RIGHT FACE START */
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    //first vertex (bottom, left)
    glVertex3f(2000, 1200, 500);


    //second vertex (top,left)
    glVertex3f(2000, 3500, 500);


    //third vertex (top,right)
    glVertex3f(2000, 3500, -500);


    //four vertex (bottom,right)
    glVertex3f(2000, 1200, -500);
    glEnd();
    /*RIGHT FACE END*/

    /*LEFT FACE START */
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    //four vertex (bottom,right)
    glVertex3f(500, 1200, 500);


    //third vertex (top,right)
    glVertex3f(500, 3500, 500);



    //second vertex (top,left)
    glVertex3f(500, 3500, -500);

//first vertex (bottom, left)
    glVertex3f(500, 1200, -500);



    glEnd();
    /*LEFT FACE END*/

    /*TOP FACE START */
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    //first vertex (bottom, left)
    glVertex3f(500, 3500, 500);


    //second vertex (top,left)
    glVertex3f(500, 3500, -500);


    //third vertex (top,right)
    glVertex3f(2000, 3500, -500);


    //four vertex (bottom,right)
    glVertex3f(2000, 3500, 500);
    glEnd();
    /*TOP FACE END*/


    /*BOTTOM FACE START */
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    //first vertex (bottom, left)
    glVertex3f(500, 1200, 500);


    //second vertex (top,left)
    glVertex3f(500, 1200, -500);


    //third vertex (top,right)
    glVertex3f(2000, 1200, -500);


    //four vertex (bottom,right)
    glVertex3f(2000, 1200, 500);
    glEnd();
    /*BOTTOM FACE END*/

    glFlush();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();


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
        printf("Key clicked is %c\n",key);
        //call milestone 1 First Rocket Launch by ISRO

        glutDisplayFunc(msAryabattaSatellite);
        //glutPostRedisplay();
        break;
    case '1':
        loadABMissionImages();
         glutIdleFunc(spinSatellite);
        glutDisplayFunc(msAryabattaSatellite);
       // glutPostRedisplay();
        break;
    case '2':
        glutDisplayFunc(msFirstRocketLaunch);
       // glutPostRedisplay();
        break;
    case '3':
        glutDisplayFunc(msMangalyan);
       // glutPostRedisplay();
        break;
    case '4':
        glutDisplayFunc(ms104SatelliteLaunch);
        //glutPostRedisplay();
        break;
    case '5':
        glutDisplayFunc(ms5);
       // glutPostRedisplay();
        break;
    }

    //glutPostRedisplay();

}

static void idle(void)
{

    if(rebuildIntro == true)
    {
        //printf("Called glutPostRedisplay %d",rebuildIntro);
        glutPostRedisplay();
        rebuildIntro = false;
    }

    if(rebuildM1 == true)
    {
        //printf("Called glutPostRedisplay %d",rebuildM1);
        glutPostRedisplay();
        rebuildM1 = false;
    }

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


    char *path = "\\final-intro.psd";
    path = getPath(&path,true);
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
    glutIdleFunc(idle);

}

void loadABMissionImages(void)
{
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
    path = getPath(&path,true);
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
    path = getPath(&path,true);
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


void  mouse(int btn, int state, int x, int y)
{
/* mouse callback, selects an axis about which to rotate */
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}


void init(int w, int h)
{

    printf("Width and Hight : \t %d \t %d\n",w,h);
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    printf("top %f",(h/w));
    /*
    glLoadIdentity();
    if(w<=h)
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
    glutReshapeFunc(init);
    //createMenu();
    //glutDisplayFunc(displayIntro);
    glutDisplayFunc(msAryabattaSatellite);
    //glutDisplayFunc(displayMenuWindow);

    loadIntroScene();

    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutIdleFunc(spinSatellite);


    glEnable(GL_DEPTH_TEST);
    //init();
    glutMainLoop();
    return EXIT_SUCCESS;
}


