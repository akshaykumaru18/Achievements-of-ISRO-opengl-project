#ifndef SLVMISSION_H
#define SLVMISSION_H
#include <GL/glut.h>
class SlvMission
{
public:
    float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;
    int p;
    int slp_top_x = 0;
    int slp_bottom_x = 0;
public:
    void pslv_rocket()
    {
        count++;
        count3++;

        for(i=0; i<=20; i++)
        {



            //RECTANGLE AT THE CENTRE OF ROCKET

            glColor3f(1,1,1);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5+slp_bottom_x,20.0+i); //left bottom point
            glVertex2f(264.5+slp_bottom_x,20.0+i); //right bottom point
            glVertex2f(264.5+slp_top_x,220.0+i);//top right point
            glVertex2f(235.5+slp_top_x,220.0+i);//top left point

            glEnd();
            //glColor3f(0.8,0.498039 ,0.196078);

            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//bulged-flag
            glVertex2f(232.5+slp_bottom_x,180.0+i);//bottom left
            glVertex2f(232.5+slp_top_x,220.0+i);//top left
            glVertex2f(267.5+slp_top_x,220.0+i);//top right
            glVertex2f(267.5+slp_bottom_x,180.0+i);//bottom right
            glEnd();

            glColor3f(1.0,1.0,1.0);//bonnet
            glBegin(GL_POLYGON);//front
            glVertex2f(232.5,180.0+i); //Traingle Bottom
            glVertex2f(267.5,180.0+i); //Tri Bottom n
            glVertex2f(250,160.0+i); //Tri Top
            glEnd();

            glColor3f(1.0,1.0,1.0);//downward tri
            glBegin(GL_POLYGON);//front
            glVertex2f(232.5,220.0+i); //Traingle Bottom
            glVertex2f(267.5,220.0+i); //Tri Bottom n
            glVertex2f(250,250.0+i); //Tri Top
            glEnd();
            glColor3f(1.0,0.5,0.0);
            glBegin(GL_LINES);
            glVertex2f(240.5,215.0+i); //flag saffrom
            glVertex2f(260.5,215.0+i);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex2f(240.5,210.0+i); //flag white
            glVertex2f(260.5,210.0+i);
            glEnd();
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_LINES);
            glVertex2f(240.5,205.0+i); //flag green
            glVertex2f(260.5,205.0+i);
            glEnd();
            glColor3f(0.0,0.0,1.0);
            glBegin(GL_POINTS);
            //glEnable(GL_PROGRAM_POINT_SIZE_EXT); //not working
            glPointSize(10000);//not working
            glVertex2f(250.5,210.0+i);
            glEnd();
            //Previous Outer Projection-

            glColor3f(1,1,1);//left body
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
            glEnd();
            if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
            else
                glColor3f(1.0,0.816,0.0);

            glBegin(GL_POLYGON);//outer fume
            glVertex2f(237.5,20+i);
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
            glFlush();
        }
    }

};

#endif // SLVMISSION_H
