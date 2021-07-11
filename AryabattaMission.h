#ifndef ARYABATTAMISSION_H
#define ARYABATTAMISSION_H
#include "GetImagePath.h"
#include <GL/glut.h>
#include <stdio.h>
class AryabhataMission
{
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



};

#endif // ARYABATTAMISSION_H_INCLUDED
