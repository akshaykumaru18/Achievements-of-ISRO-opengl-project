#ifndef MOMMISSION_H_INCLUDED
#define MOMMISSION_H_INCLUDED

class MomMission
{
public:
    float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;
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

            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        }
        return;
    }
    void pslv_rocket()
    {
        count++;
        count3++;

        for(i=0; i<=20; i++)
        {

            displayText(245,138,0,0,0,0,"P");
            displayText(245,128,0,0,0,0,"S");
            displayText(245,118,0,0,0,0,"L");
            displayText(245,108,0,0,0,0,"V");
            glColor3f(1.0,0.5,0.0);
            glBegin(GL_QUADS);
            glVertex2f(240.5,215.0+i); //flag saffrom
            glVertex2f(260.5,215.0+i);
            glVertex2f(260.5,220.0+i);
            glVertex2f(240.5,220.0+i);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex2f(240.5,210.0+i); //flag white
            //glVertex2f(260.5,210.0+i);
            glEnd();
            glColor3f(0.0,1.0,0.0);
            glBegin(GL_QUADS);
            glVertex2f(240.5,208.0+i); //flag green
            glVertex2f(260.5,208.0+i);
            glVertex2f(260.5,203.0+i);
            glVertex2f(240.5,203.0+i);
            glEnd();


            /* payload Start */

            glColor3f(1,1,1);
            glBegin(GL_POLYGON);//bulged-flag
            glVertex2f(232.5,180.0+i);//bottom left
            glVertex2f(232.5,220.0+i);//top left
            glVertex2f(267.5,220.0+i);//top right
            glVertex2f(267.5,180.0+i);//bottom right
            glEnd();
            glColor3f(1.0,0.0,0.0);//bonnet
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
            /* payload end */
            /* Fourth Stage start */
            glColor3f(1,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5,150.0+i); //left bottom point
            glVertex2f(264.5,150.0+i); //right bottom point
            glVertex2f(264.5,220.0+i);//top right point
            glVertex2f(235.5,220.0+i);//top left point

            glEnd();
            /* Fourth Stage End */

            /* Third Stage start */
            glColor3f(1,1,1);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5,100.0+i); //left bottom point
            glVertex2f(264.5,100.0+i); //right bottom point
            glVertex2f(264.5,150.0+i);//top right point
            glVertex2f(235.5,150.0+i);//top left point

            glEnd();
            glColor3f(1,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5,70.0+i); //left bottom point
            glVertex2f(264.5,70.0+i); //right bottom point
            glVertex2f(264.5,100.0+i);//top right point
            glVertex2f(235.5,200.0+i);//top left point

            glEnd();
            /* Third Stage End */

            /* Second and First Stage Start */
            glColor3f(1,1,1);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5,-5.0+i); //left bottom point
            glVertex2f(264.5,-5.0+i); //right bottom point
            glVertex2f(264.5,70.0+i);//top right point
            glVertex2f(235.5,70.0+i);//top left point
            glEnd();
            glColor3f(1,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(235.5,-15.0+i); //left bottom point
            glVertex2f(264.5,-15.0+i); //right bottom point
            glVertex2f(264.5,-5.0+i);//top right point
            glVertex2f(235.5,-5.0+i);//top left point
            glEnd();


            glColor3f(1,1,1);//left body
            glBegin(GL_POLYGON);
            glVertex2f(235.5,-20.0+i);
            glVertex2f(235.5,60.0+i);
            glVertex2f(220.5,60.0+i);
            glVertex2f(220.5,-20.0+i);
            glEnd();

            glColor3f(0.2,0.2,0.2);
            glBegin(GL_LINES);
            glVertex2f(235.5,-20.0+i);
            glVertex2f(235.5,60.0+i);
            glEnd();
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(235.5,70.0+i);
            glVertex2f(220.5,70.0+i);
            glVertex2f(228,80.0+i);
            glEnd();



            glColor3f(1,1,1);

            glBegin(GL_POLYGON);//right body
            glBegin(GL_POLYGON);
            glVertex2f(264.5,-20.0+i);
            glVertex2f(264.5,60.0+i);
            glVertex2f(280.5,60.0+i);
            glVertex2f(280.5,-20.0+i);
            glEnd();


            glColor3f(0.2,0.2,0.2);
            glBegin(GL_LINES);
            glVertex2f(264.5,-20.0+i);
            glVertex2f(264.5,60.0+i);
            glEnd();
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2f(264.5,70.0+i);
            glVertex2f(280.5,70.0+i);
            glVertex2f(270,80.0+i);
            glEnd();
            /* Second and First Stage end */






            if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
            else
                glColor3f(1.0,0.816,0.0);

            glBegin(GL_POLYGON);//outer fume
            glVertex2f(237.5,-20+i);
            glVertex2f(234.16,-26.66+i);
            glVertex2f(230.82,-20.32+i);
            glVertex2f(227.48,-59.98+i);
            glVertex2f(224.14,-30.64+i);
            glVertex2f(220.8,-63.3+i);

            glVertex2f(217.5,-30+i);
            glVertex2f(221.16,-76.66+i);
            glVertex2f(225.82,-30.32+i);
            glVertex2f(229.48,-79.98+i);
            glVertex2f(233.14,-30.64+i);
            glVertex2f(237.8,-73.3+i);


            glVertex2f(241.86,-30+i);
            glVertex2f(245.92,-76.6+i);
            glVertex2f(250,-30+i);
            glVertex2f(254.06,-76.9+i);
            glVertex2f(258.12,-30+i);
            glVertex2f(262.18,-76.6+i);
            glVertex2f(266.24,-30+i);
            glVertex2f(270.3,-70+i);
            glVertex2f(274.36,-30+i);
            glVertex2f(278.42,-70+i);
            glVertex2f(282.5,-30+i);
            glVertex2f(278.5,-78+i);
            glVertex2f(274.5,-30+i);
            glVertex2f(270.5,-20+i);
            glVertex2f(266.5,-20+i);
            glVertex2f(262.5,-20+i);//28 points

            glEnd();

            if((p%2)==0)
                glColor3f(1.0,0.816,0.0);
            else
                glColor3f(1.0,0.25,0.0);

            glBegin(GL_POLYGON);//inner fume
            glVertex2f(237.5,-70+i);
            glVertex2f(236.5,-67.5+i);
            glVertex2f(235.5,-75+i);
            glVertex2f(234.5,-62.5+i);
            glVertex2f(233.5,-70+i);
            glVertex2f(232.5,-67.5+i);
            glVertex2f(236,-85+i);
            glVertex2f(239.5,-62.5+i);
            glVertex2f(243,-80+i);
            glVertex2f(246.5,-62.5+i);
            glVertex2f(250,-85+i);
            glVertex2f(253.5,-62.5+i);
            glVertex2f(257,-80+i);
            glVertex2f(260.5,-82.5+i);
            glVertex2f(264,85+i);
            glVertex2f(267.5,-87.5+i);
            glVertex2f(266.5,-80+i);
            glVertex2f(265.5,-82.5+i);
            glVertex2f(264.5,-85+i);
            glVertex2f(263.5,-87.5+i);
            glVertex2f(262.5,-80+i);//21 points

            glEnd();

            p=p+1;
            for(j=0; j<=1000000; j++);
            glutPostRedisplay();
            glFlush();
        }
    }

};


#endif // MOMMISSION_H_INCLUDED
