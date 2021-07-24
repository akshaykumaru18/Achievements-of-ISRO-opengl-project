#ifndef MOMMISSION_H_INCLUDED
#define MOMMISSION_H_INCLUDED
#include "elipse.h"

class MomMission
{
public:
    float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;
    int p;
    bool namePlateCalled = false;

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




    void namePlate()
    {


        displayText(1130,2950,0,0,0,0,"P");
        displayText(1130,2840,0,0,0,0,"S");
        displayText(1130,2730,0,0,0,0,"L");
        displayText(1130,2620,0,0,0,0,"V");


        displayText(1140,2150,0,0,0,0,"I");
        displayText(1130,2000,0,0,0,0,"N");
        displayText(1130,1850,0,0,0,0,"D");
        displayText(1140,1700,0,0,0,0,"I");
        displayText(1130,1550,0,0,0,0,"A");
        glFlush();

    }
    void pslv_rocket()
    {
        count++;
        count3++;



        for(i=0; i<=10; i++)
        {


            if(true)
            {
                namePlate();
                namePlateCalled = true;
            }

            glColor3f(1.0,0.5,0.0);
            glBegin(GL_QUADS);
            glVertex2f(1050.5,3600.0+i); //flag green
            glVertex2f(1050.5,3700.0+i);
            glVertex2f(1250.5,3700.0+i);
            glVertex2f(1250.5,3600.0+i);
            glEnd();
            /*
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex2f(240.5,210.0+i); //flag white
            //glVertex2f(260.5,210.0+i);
            glEnd();
            */

            glColor3f(0.0,1.0,0.0);
            glBegin(GL_QUADS);
            glVertex2f(1050.5,3400.0+i); //flag green
            glVertex2f(1050.5,3500.0+i);
            glVertex2f(1250.5,3500.0+i);
            glVertex2f(1250.5,3400.0+i);
            glEnd();


            /* payload Start */
            glColor3f(1,1,1);
            glBegin(GL_QUADS);
            glVertex2f(1000,3300);
            glVertex2f(1000,4000);
            glVertex2f(1300,4000);
            glVertex2f(1300,3300);
            glEnd();


            glColor3f(1.0,1.0,1.0);//bonnet
            glBegin(GL_POLYGON);//front
            glVertex2f(1000.5,4000.0+i); //Traingle Bottom
            glVertex2f(1300.5,4000.0+i); //Tri Bottom n
            glVertex2f(1150,4300.0+i); //Tri Top
            glEnd();

            glColor3f(0.80,0.0,0.0);//bonnet
            glBegin(GL_POLYGON);//front
            glVertex2f(1000.5,3300.0+i); //Traingle Bottom
            glVertex2f(1300.5,3300.0+i); //Tri Bottom n
            glVertex2f(1150,3100.0+i); //Tri Top
            glEnd();



            /* payload end */
            /* Fourth Stage start */
            glColor3f(0.80,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,3100.0+i); //left bottom point
            glVertex2f(1250.5,3100.0+i); //right bottom point
            glVertex2f(1250.5,3300.0+i);//top right point
            glVertex2f(1050.5,3300.0+i);//top left point

            glEnd();
            /* Fourth Stage End */

            /* Third Stage start */
            glColor3f(1,1,1);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,2500.0+i); //left bottom point
            glVertex2f(1250.5,2500.0+i); //right bottom point
            glVertex2f(1250.5,3100.0+i);//top right point
            glVertex2f(1050.5,3100.0+i);//top left point

            glEnd();
            glColor3f(0.80,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,2300.0+i); //left bottom point
            glVertex2f(1250.5,2300.0+i); //right bottom point
            glVertex2f(1250.5,2500.0+i);//top right point
            glVertex2f(1050.5,2500.0+i);//top left point

            glEnd();
            /* Third Stage End */

            /* Second and First Stage Start */

            glColor3f(1,1,1);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,1500.0+i); //left bottom point
            glVertex2f(1250.5,1500.0+i); //right bottom point
            glVertex2f(1250.5,2300.0+i);//top right point
            glVertex2f(1050.5,2300.0+i);//top left point

            glEnd();

            glColor3f(0.80,0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,1300.0+i); //left bottom point
            glVertex2f(1250.5,1300.0+i); //right bottom point
            glVertex2f(1250.5,1500.0+i);//top right point
            glVertex2f(1050.5,1500.0+i);//top left point

            glEnd();
            // glColor3f(0.60,0.30,0);
            // glColor3f(0.40,0.26,0.12);
            glColor3f(0.60,0.0,0);
            glBegin(GL_QUADS);//core
            glVertex2f(1050.5,1150.0+i); //left bottom point
            glVertex2f(1250.5,1150.0+i); //right bottom point
            glVertex2f(1200.5,1300.0+i);//top right point
            glVertex2f(1100.5,1300.0+i);//top left point

            glEnd();

            /*Fire Start*/
            if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
            else
                glColor3f(1.0,0.816,0.0);

            glBegin(GL_POLYGON);//outer fume
            glVertex2f(1080.5,1150+i);
            glVertex2f(1250.5,1150+i);

            glVertex2f(1085.5,1150+i);
            glVertex2f(1095.5,950+i);
            glVertex2f(1105.5,1150+i);
            glVertex2f(1115.5,900+i);
            glVertex2f(1125.5,1150+i);
            glVertex2f(1135.5,950+i);
            glVertex2f(1145.5,1150+i);
            glVertex2f(1155.5,900+i);
            glVertex2f(1165.5,1150+i);
            glVertex2f(1175.5,950+i);
            glVertex2f(1185.5,1150+i);
            glVertex2f(1195.5,900+i);
            glVertex2f(1105.5,1150+i);
            glVertex2f(1115.5,950+i);
            glVertex2f(1125.5,1150+i);
            glVertex2f(1135.5,900+i);
            glVertex2f(1145.5,1150+i);
            glVertex2f(1155.5,950+i);
            glVertex2f(1165.5,1150+i);
            glVertex2f(1175.5,900+i);
            glVertex2f(1185.5,1150+i);
            glVertex2f(1195.5,950+i);
            glVertex2f(1205.5,1150+i);
            glVertex2f(1215.5,900+i);
            glVertex2f(1225.5,1150+i);
            glVertex2f(1235.5,950+i);


            glEnd();

            if((p%2)==0)
                glColor3f(1.0,0.816,0.0);
            else
                glColor3f(1.0,0.25,0.0);

            glBegin(GL_POLYGON);//inner fume
            glVertex2f(1080.5,1150+i);
            glVertex2f(1250.5,1150+i);


            glVertex2f(1090.5,1150+i);

            glVertex2f(1110.5,1150+i);
            glVertex2f(1120.5,750+i);
            glVertex2f(1130.5,700+i);
            glVertex2f(1140.5,1150+i);
            glVertex2f(1150.5,750+i);
            glVertex2f(1160.5,700+i);
            glVertex2f(1170.5,1150+i);
            glVertex2f(1180.5,750+i);
            glVertex2f(1190.5,700+i);
            glVertex2f(1200.5,1150+i);
            glVertex2f(1210.5,750+i);
            glVertex2f(1220.5,700+i);




            glEnd();

            /*Fire End*/


            //Left roket booster
            glColor3f(0.80,0,0);
            glBegin(GL_TRIANGLES);
            glVertex2f(940.5,2300.0+i);
            glVertex2f(1045.5,2300.0+i);
            glVertex2f(995.5,2400.0+i);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);
            glVertex2f(940.5,1400.0+i);
            glVertex2f(940.5,2300.0+i);
            glVertex2f(1045.5,2300.0+i);
            glVertex2f(1045.5,1400.0+i);
            glEnd();



            glColor3f(0.60,0.0,0.0);
            glBegin(GL_QUADS);
            glVertex2f(1040.5,1200.0+i);
            glVertex2f(1030.5,1400.0+i);
            glVertex2f(950.5,1400.0+i);
            glVertex2f(920,1200.0+i);
            glEnd();


            /* FIRE START*/
            if((p%2)==0)
                glColor3f(1.0,0.816,0.0);
            else
                glColor3f(1.0,0.25,0.0);

            //glColor3f(0.0,0.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(930.0,1200);
            glVertex2f(1020.0,1200);

            glVertex2f(1000.0, 900);
            glVertex2f(1010.0, 1000);
            glVertex2f(990.0, 900);
            glVertex2f(980.0, 1100);
            glVertex2f(970.0, 1050);
            glVertex2f(960.0, 1050);
            glVertex2f(950.0, 1000);
            glVertex2f(940.0, 1100);
            glVertex2f(930.0, 1100);
            glVertex2f(920.0, 900);
            glVertex2f(910.0, 950);

            glEnd();

            if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
            else
                glColor3f(1.0,0.816,0.0);

            glBegin(GL_POLYGON);
            glVertex2f(930.0,1200);
            glVertex2f(1020.0,1200);



            glVertex2f(1015.0,950);
            glVertex2f(1035.0,850);
            glVertex2f(1010.0,900);
            glVertex2f(1020.0,850);
            glVertex2f(1000.0,950);
            glVertex2f(900.0,850);
            glVertex2f(935.0,960);
            glVertex2f(925.0,880);
            glVertex2f(940.0,800);
            glVertex2f(960.0,980);
            glVertex2f(910.0,800);
            glEnd();
            /* FIRE End*/


            //right roket booster
            glColor3f(0.80,0,0);
            glBegin(GL_TRIANGLES);
            glVertex2f(1252.5,2300.0+i);
            glVertex2f(1360.5,2300.0+i);
            glVertex2f(1306.5,2400.0+i);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_POLYGON);
            glVertex2f(1252.5,1400.0+i);
            glVertex2f(1252.5,2300.0+i);
            glVertex2f(1360.5,2300.0+i);
            glVertex2f(1360.5,1400.0+i);
            glEnd();



            glColor3f(0.60,0.0,0.0);
            glBegin(GL_QUADS);
            glVertex2f(1252.5,1200.0+i);
            glVertex2f(1262.5,1400.0+i);
            glVertex2f(1340.5,1400.0+i);
            glVertex2f(1380,1200.0+i);
            glEnd();

            /* FIRE START*/
            if((p%2)==0)
                glColor3f(1.0,0.816,0.0);
            else
                glColor3f(1.0,0.25,0.0);

            //glColor3f(0.0,0.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(1252.0,1200);
            glVertex2f(1360.0,1200);

            glVertex2f(1350.0, 1000);
            glVertex2f(1340.0, 1050);
            glVertex2f(1330.0, 1000);
            glVertex2f(1320.0, 1100);
            glVertex2f(1310.0, 1050);
            glVertex2f(1300.0, 1150);
            glVertex2f(1290.0, 1000);
            glVertex2f(1280.0, 1100);
            glVertex2f(1270.0, 1100);
            glVertex2f(1260.0, 1000);
            glVertex2f(1250.0, 1050);

            glEnd();

            if((p%2)==0)
                glColor3f(1.0,0.25,0.0);
            else
                glColor3f(1.0,0.816,0.0);

            glBegin(GL_POLYGON);
            glVertex2f(1252.0,1200);
            glVertex2f(1360.0,1200);



            glVertex2f(1355.0,950);
            glVertex2f(1345.0,850);
            glVertex2f(1335.0,900);
            glVertex2f(1325.0,850);
            glVertex2f(1305.0,950);
            glVertex2f(1295.0,850);
            glVertex2f(1285.0,960);
            glVertex2f(1275.0,880);
            glVertex2f(1265.0,800);
            glVertex2f(1255.0,980);
            glVertex2f(1255.0,800);
            glEnd();
            /* FIRE End*/
            /* Second and First Stage end */



            p=p+1;
            for(j=0; j<=1000000; j++);
            glutPostRedisplay();
            glFlush();
        }
    }


    void mom_orbitor(unsigned int texture,unsigned int bulb)
    {
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2d(130,150);
        glVertex2d(120,150);
        glVertex2d(130,120);
        glVertex2d(120,120);
        glEnd();
        glColor3f(1,1,0.0);
        glBegin(GL_POLYGON);
        glVertex2d(340,450);
        glVertex2d(350,630);
        glVertex2d(370,630);

        glVertex2d(380,450);
        glEnd();



        /* glColor3f(0.5,0.5,0.5);
         glBegin(GL_POLYGON);
         glVertex2d(250,520);
         glVertex2d(170,450);
         glVertex2d(320,450);
         glEnd(); */

        /* glColor3f(1,1,0);
         glBegin(GL_QUADS);
         glVertex2d(100,450);
         glVertex2d(-15,520);
         glVertex2d(250,520);
         glVertex2d(400,450);
         glEnd(); */
        /*Texture */
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glVertex2d(100,450);
        glTexCoord2f(0, 0);
        glVertex2d(-15,520);
        glTexCoord2f(0, 1);
        glVertex2d(250,520);
        glTexCoord2f(1, 1);
        glVertex2d(400,450);
        glTexCoord2f(1, 0);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);
        /*Texture */


        /* glColor3f(1,1,0);
         glBegin(GL_QUADS);
         glVertex2d(-15,230);
         glVertex2d(-15,520);
         glVertex2d(100,450);
         glVertex2d(100,100);
         glEnd(); */

        /*Texture */
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glVertex2d(-15,230);
        glTexCoord2f(0, 0);
        glVertex2d(-15,520);
        glTexCoord2f(0, 1);
        glVertex2d(100,450);
        glTexCoord2f(1, 1);
        glVertex2d(100,100);
        glTexCoord2f(1, 0);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);
        /*Texture */


        /*
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        glVertex2d(200,200);
        glVertex2d(200,350);
        glVertex2d(300,350);
        glVertex2d(300,200);
        glEnd();


        glColor3f(0.6,0.6,0.6);
        glBegin(GL_QUADS);
        glVertex2d(150,150);
        glVertex2d(150,400);
        glVertex2d(350,400);
        glVertex2d(350,150);
        glEnd();
        */
        /*  glColor3f(1,1,0);
         glBegin(GL_QUADS);
         glVertex2d(100,100);
         glVertex2d(100,450);
         glVertex2d(400,450);
         glVertex2d(400,100);
         glEnd();
         */

        /*Texture */
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glVertex2d(100,100);
        glTexCoord2f(0, 0);
        glVertex2d(100,450);
        glTexCoord2f(0, 1);
        glVertex2d(400,450);
        glTexCoord2f(1, 1);
        glVertex2d(400,100);
        glTexCoord2f(1, 0);
        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);
        /*Texture */


        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2d(400,275);
        glVertex2d(420,275);
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2d(100,275);
        glVertex2d(60,275);
        glEnd();


        //solar panel
        //1st panel
        drawLines(-190,450,-30,450);
        drawLines(-190,450,-160,650);

        drawLines(-160,450,-140,650);
        drawLines(-130,450,-110,650);
        drawLines(-100,450,-80,650);
        drawLines(-70,450,-50,650);



        drawLines(-160,630,-10,630);
        drawLines(-160,600,-10,600);
        drawLines(-175,570,-15,570);
        drawLines(-175,540,-15,540);
        drawLines(-175,510,-15,510);
        drawLines(-190,490,-15,490);
        drawLines(-190,460,-15,460);



        drawLines(-30,450,-10,650);
        drawLines(-160,650,-10,650);

        glColor3f(0,0.3,1);
        glBegin(GL_QUADS);
        glVertex2d(-160,650);
        glVertex2d(-190,450);
        glVertex2d(-30,450);
        glVertex2d(-10,650);
        glEnd();


        //2nd panel

        drawLines(-200,250,-50,250);
        drawLines(-200,250,-180,430);


        drawLines(-200,250,-180,430);
        drawLines(-160,250,-130,430);
        drawLines(-140,250,-100,430);
        drawLines(-120,250,-70,430);
        drawLines(-90,250,-40,430);



        drawLines(-180,430,-30,430);
        drawLines(-180,400,-30,400);
        drawLines(-190,370,-40,370);
        drawLines(-190,340,-40,340);
        drawLines(-190,310,-40,310);
        drawLines(-190,280,-40,280);
        drawLines(-190,250,-40,250);



        drawLines(-50,250,-30,430);
        drawLines(-180,430,-30,430);


        glColor3f(0,0.3,1);
        glBegin(GL_QUADS);
        glVertex2d(-180,430);
        glVertex2d(-200,250);
        glVertex2d(-50,250);
        glVertex2d(-30,430);
        glEnd();




        //3rd panel

        drawLines(-200,40,-60,40);
        drawLines(-200,40,-190,230);


        drawLines(-180,40,-170,230);
        drawLines(-160,40,-150,230);
        drawLines(-140,40,-130,230);
        drawLines(-120,40,-110,230);
        drawLines(-100,40,-90,230);
        drawLines(-80,40,-70,230);


        drawLines(-190,200,-50,200);
        drawLines(-190,170,-50,170);
        drawLines(-190,130,-50,130);
        drawLines(-190,90,-50,90);



        drawLines(-60,40,-50,230);
        drawLines(-190,230,-50,230);


        glColor3f(0,0.3,1);
        glBegin(GL_QUADS);
        glVertex2d(-190,230);
        glVertex2d(-200,40);
        glVertex2d(-60,40);
        glVertex2d(-50,230);
        glEnd();




        /* solar panel end */



//         glColor3f(1,1,1);
//        glBegin(GL_POINTS);
//        for(int i=0;i<1000;++i)
//        {
//            glVertex3f(cos(2*3.141*i/1000),sin(2*3.141*i/1000),0);
//        }
//        glEnd();
        glColor3f(1,1,1);
        Elipse elipse;
        elipse.setColor(0.6,0.6,0.6);
        elipse.draw1(530,275,100,255,1,0,360);


    }

    void drawLines(int x1,int y1,int x2,int y2)
    {
        glLineWidth(1);
        glColor4f(1, 1, 0,1);
        glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    void drawPlanet(unsigned int texture,float opacity)
    {
        //printf("drawBGTexture called\n");
        glEnable(GL_TEXTURE_2D);
        glColor4f(1, 1, 1,opacity);
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



    void pslv_rocket_deprecated()
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
            glColor3f(1.0,1.0,0.0);//bonnet
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
