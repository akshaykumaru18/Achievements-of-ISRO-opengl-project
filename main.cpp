#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

static int slices = 16;
static int stacks = 16;

unsigned int introBG;

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



static void displayIntroWindow(void){
   /* glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(10,40,0);
    glVertex3f(60,40,0);
    glVertex3f(40,60,0);
    glEnd();
    glFlush();
    glutSwapBuffers(); */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, introBG);
    /*
     glBegin(GL_POLYGON);
    glVertex3f(10,40,0);
    glTexCoord2f(0, 0);
    glVertex3f(100,100,0);
    glTexCoord2f(0, 1);
    glVertex3f(100,100,0);
    glTexCoord2f(1, 1);
    glEnd(); */
      glBegin(GL_QUADS);
    glVertex3f(20,20,0);
    glTexCoord2f(0, 0);
    glVertex3f(80,20,0);
    glTexCoord2f(0, 1);
    glVertex3f(80,300,0);
    glTexCoord2f(1, 1);
    glVertex3f(20,300,0);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


void loadIntroScene(void){
    glGenTextures(1,&introBG);
    glBindTexture(GL_TEXTURE_2D,introBG);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width, height,channels;
    unsigned char *data = stbi_load("C:\\Users\\Akshay Kumar U\\cgv project\\Achievements-of-ISRO-opengl-project\\template.psd", &width, &height, &channels, 0);
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    if(data){
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //glGenerateMipmap(GL_TEXTURE_2D);

    }else{
        std::cout << "Failed to load intro slide" << std::endl;
    }
    stbi_image_free(data);
    std::cout << "done" << std::endl;

}

void displayIntro2()
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
/* Program entry point */
void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // glOrtho(0, 10, 0, 10, 0, -500);
    glOrtho(100.0f, 00.0f, 0.0f, 300.0f, -1.0, 1.0);
  //glOrtho(1, 1, 1, 1, -1.0, 1.0);
 // The understanding of this is centered on 0, 0 points, the left side is 300 width, the right side is 0 width, the lower side has 0 height, and the upper side has 300 height

    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void init2(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(50,20);

    glutCreateWindow("Achievements of ISRO");
    glutDisplayFunc(displayIntro2);
   // glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    loadIntroScene();

    //glClearColor(0,0,0,1);
    //glEnable(GL_CULL_FACE);
   // glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);



    init2();

    glutMainLoop();

    return EXIT_SUCCESS;
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}

