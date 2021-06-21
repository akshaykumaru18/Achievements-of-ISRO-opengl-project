#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"


bool rebuildIntro = true;
static int window, returnMenu,value=0;

static int activeWindow = 1;

unsigned int introBG;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

char  introWindowPsd[];
bool isAK = false;
if(true){
    introWindowPsd = "C:\\Users\\Akshay Kumar U\\cgv project\\Achievements-of-ISRO-opengl-project\\final-intro.psd";
}else{
   introWindowPsd = "C:\\Users\\Hp\\CGV\\Achievements-of-ISRO-opengl-project\\final-intro.psd";
}

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
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
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

void msFirstRocketLaunch()
{
    //  printf("milestoneRocketLaunch function called\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 5000, 10);
    glVertex3f(5000, 5000, 10);
    glVertex3f(5000, 0, 10);
    glEnd();
    displayText(2500,2500,1.0,0.0,0.0,1,"Milestone 1 : First Rocket Launch");
    glFlush();
    glutSwapBuffers();
}

void msAryabattaSatellite()
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
    displayText(2500,2500,1.0,1.0,0.0,1,"Milestone 2 : Aryabatta Rocket Launch");

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
        glutPostRedisplay();
        break;
    case 'S':
    case 's':
        printf("Key clicked is %c\n",key);
        //call milestone 1 First Rocket Launch by ISRO
        glutDisplayFunc(msFirstRocketLaunch);
        glutPostRedisplay();
        break;
    case '1':
        glutDisplayFunc(msFirstRocketLaunch);
        glutPostRedisplay();
        break;
    case '2':
        glutDisplayFunc(msAryabattaSatellite);
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

    glutPostRedisplay();

}

static void idle(void)
{

    if(rebuildIntro == true)
    {
        printf("Called glutPostRedisplay %d",rebuildIntro);
        glutPostRedisplay();
        rebuildIntro = false;
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
    //unsigned char *data = stbi_load("C:\\Users\\Hp\\CGV\\Achievements-of-ISRO-opengl-project\\final-intro.psd", &width, &height, &channels, STBI_rgb_alpha);
    unsigned char *data = stbi_load(introWindowPsd, &width, &height, &channels, STBI_rgb_alpha);
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




void init(void)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);

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
    glutIdleFunc(idle);


    glEnable(GL_DEPTH_TEST);
    init();
    glutMainLoop();
    return EXIT_SUCCESS;
}


