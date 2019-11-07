#include "draw.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void draw_xwing(){

	glTranslatef(0, 0, 0); 
        glRotatef(30, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCyl = gluNewQuadric();
        gluQuadricTexture(gluqCyl, GLU_TRUE);
        gluQuadricDrawStyle(gluqCyl, GLU_LINE);
        gluCylinder(gluqCyl, 0.5, 0.5, 1.5, 6, 10);

        GLUquadric* gluqCylDisk1 = gluNewQuadric();
        gluQuadricTexture(gluqCylDisk1, GLU_TRUE);
        gluQuadricDrawStyle(gluqCylDisk1, GLU_LINE);
        gluDisk(gluqCylDisk1, 0, 0.5, 6, 10);

        glTranslatef(0, 0, 1.5);
            GLUquadric* gluqCylDisk2 = gluNewQuadric();
            gluQuadricTexture(gluqCylDisk2, GLU_TRUE);
            gluQuadricDrawStyle(gluqCylDisk2, GLU_LINE);
            gluDisk(gluqCylDisk2, 0, 0.5, 6, 10);
        glTranslatef(0, 0, -1.5);

    glRotatef(-30, 0, 0, 1);
    glTranslatef(0, 0, 0);

    /*cockpit*/
    glTranslatef(0, -0.05, -1.9);  
        glRotatef(30, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCylf = gluNewQuadric();
        gluQuadricTexture(gluqCylf, GLU_TRUE);
        gluQuadricDrawStyle(gluqCylf, GLU_LINE);
        gluCylinder(gluqCylf, 0.20, 0.38, 1.9, 6, 10);

        GLUquadric* gluqCylfDisk1 = gluNewQuadric();
        gluQuadricTexture(gluqCylfDisk1, GLU_TRUE);
        gluQuadricDrawStyle(gluqCylfDisk1, GLU_LINE);
        gluDisk(gluqCylfDisk1, 0, 0.20, 6, 10);

        /*vrh*/
        glTranslatef(0, 0, -0.25); 
        glRotatef(0, 0, 0, 1);
            glColor3f(0.5, 0.5, 0.5);
            GLUquadric* gluqCylf1 = gluNewQuadric();
            gluQuadricTexture(gluqCylf1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCylf1, GLU_LINE);
            gluCylinder(gluqCylf1, 0.2, 0.26, 0.4, 6, 10);

            GLUquadric* gluqCylf1Disk = gluNewQuadric();
            gluQuadricTexture(gluqCylf1Disk, GLU_TRUE);
            gluQuadricDrawStyle(gluqCylf1Disk, GLU_LINE);
            gluDisk(gluqCylf1Disk, 0, 0.2, 6, 10);

            glTranslatef(0, 0, 0.4);
            GLUquadric* gluqCylf1Disk1 = gluNewQuadric();
            gluQuadricTexture(gluqCylf1Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCylf1Disk1, GLU_LINE);
            gluDisk(gluqCylf1Disk1, 0, 0.26, 6, 10);
            glTranslatef(0, 0, -0.4);

        glRotatef(0, 0, 0, 1);
        glTranslatef(0, 0, 0.25);

    /*vetrobran*/
    glRotatef(-30, 0, 0, 1);   
    glTranslatef(0, 0.05, 1.9);

    glTranslatef(0, 0.14, -0.65); 
    glRotatef(30, 0, 0, 1);
        glColor3f(0.3, 0.4, 1);
        GLUquadric* gluqCylf2 = gluNewQuadric();
        gluQuadricTexture(gluqCylf2, GLU_TRUE);
        gluQuadricDrawStyle(gluqCylf2, GLU_FILL);
        gluCylinder(gluqCylf2, 0.21, 0.27, 0.6, 6, 10);

            GLUquadric* gluqCylf2Disk = gluNewQuadric();
            gluQuadricTexture(gluqCylf2Disk, GLU_TRUE);
            gluQuadricDrawStyle(gluqCylf2Disk, GLU_LINE);
            gluDisk(gluqCylf2Disk, 0, 0.21, 6, 10);

            glTranslatef(0, 0, 0.6);
                GLUquadric* gluqCylf2Disk1 = gluNewQuadric();
                gluQuadricTexture(gluqCylf2Disk1, GLU_TRUE);
                gluQuadricDrawStyle(gluqCylf2Disk1, GLU_LINE);
                gluDisk(gluqCylf2Disk1, 0, 0.27, 6, 10);
            glTranslatef(0, 0, -0.6);

    glRotatef(-30, 0, 0, 1);
    glTranslatef(0, -0.14, 0.65); 

    /*krilo gore levo*/
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);/*wired polygon*/
    glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(0, -0.1, 0.2);
            glVertex3f(0, -0.1, 1.1);
            glVertex3f(0, 0.2, 1.1);
            glVertex3f(0, 0.2, 0.2);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(0, -0.1, 0.2);
            glVertex3f(0, -0.1, 1.1);
            glVertex3f(-2.5, 0.45, 1.1);
            glVertex3f(-2.5, 0.45, 0.2);
        glEnd();
      
        glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(0, -0.1, 1.1);
            glVertex3f(0, 0.2, 1.1);
            glVertex3f(-2.5, 0.5, 1.1);
            glVertex3f(-2.5, 0.45, 1.1);
        glEnd();
   
        glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(0, 0.2, 1.1);
            glVertex3f(0, 0.2, 0.2);
            glVertex3f(-2.5, 0.5, 0.2);
            glVertex3f(-2.5, 0.5, 1.1);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(0, -0.1, 0.2);
            glVertex3f(0, 0.2, 0.2);
            glVertex3f(-2.5, 0.5, 0.2);
            glVertex3f(-2.5, 0.45, 1.1);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(-2.5, 0.45, 1.1);
            glVertex3f(-2.5, 0.45, 0.2);
            glVertex3f(-2.5, 0.5, 0.2);
            glVertex3f(-2.5, 0.5, 1.1);
        glEnd();

        /*krilo gore desno*/
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);/*wired polygon*/
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.1, 0.2);
                glVertex3f(0, -0.1, 1.1);
                glVertex3f(0, 0.2, 1.1);
                glVertex3f(0, 0.2, 0.2);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.1, 0.2);
                glVertex3f(0, -0.1, 1.1);
                glVertex3f(2.5, 0.45, 1.1);
                glVertex3f(2.5, 0.45, 0.2);
            glEnd();
          
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.1, 1.1);
                glVertex3f(0, 0.2, 1.1);
                glVertex3f(2.5, 0.5, 1.1);
                glVertex3f(2.5, 0.45, 1.1);
            glEnd();
       
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.2, 1.1);
                glVertex3f(0, 0.2, 0.2);
                glVertex3f(2.5, 0.5, 0.2);
                glVertex3f(2.5, 0.5, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.1, 0.2);
                glVertex3f(0, 0.2, 0.2);
                glVertex3f(2.5, 0.5, 0.2);
                glVertex3f(2.5, 0.45, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(2.5, 0.45, 1.1);
                glVertex3f(2.5, 0.45, 0.2);
                glVertex3f(2.5, 0.5, 0.2);
                glVertex3f(2.5, 0.5, 1.1);
            glEnd();

        /*krilo dole levo*/
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);/*wired polygon*/
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(0, -0.2, 0.2);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(-2.5, -0.45, 1.1);
                glVertex3f(-2.5, -0.45, 0.2);
            glEnd();
          
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(-2.5, -0.5, 1.1);
                glVertex3f(-2.5, -0.45, 1.1);
            glEnd();
       
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(0, -0.2, 0.2);
                glVertex3f(-2.5, -0.5, 0.2);
                glVertex3f(-2.5, -0.5, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, -0.2, 0.2);
                glVertex3f(-2.5, -0.5, 0.2);
                glVertex3f(-2.5, -0.45, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(-2.5, -0.45, 1.1);
                glVertex3f(-2.5, -0.45, 0.2);
                glVertex3f(-2.5, -0.5, 0.2);
                glVertex3f(-2.5, -0.5, 1.1);
            glEnd();

        /*krilo dole desno*/
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);/*wired polygon*/
        glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(0, -0.2, 0.2);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(2.5, -0.45, 1.1);
                glVertex3f(2.5, -0.45, 0.2);
            glEnd();
          
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 1.1);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(2.5, -0.5, 1.1);
                glVertex3f(2.5, -0.45, 1.1);
            glEnd();
       
            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, -0.2, 1.1);
                glVertex3f(0, -0.2, 0.2);
                glVertex3f(2.5, -0.5, 0.2);
                glVertex3f(2.5, -0.5, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(0, 0.1, 0.2);
                glVertex3f(0, -0.2, 0.2);
                glVertex3f(2.5, -0.5, 0.2);
                glVertex3f(2.5, -0.45, 1.1);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(0.8, 0.8, 0.8);
                glVertex3f(2.5, -0.45, 1.1);
                glVertex3f(2.5, -0.45, 0.2);
                glVertex3f(2.5, -0.5, 0.2);
                glVertex3f(2.5, -0.5, 1.1);
            glEnd();

    /*blaster gore levo*/
    glTranslatef(-2.5, 0.465, 0.15);

    glColor3f(0.8, 0.8, 0.8);
    GLUquadric* gluCylBl1 = gluNewQuadric();
    gluQuadricTexture(gluCylBl1, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl1, GLU_LINE);
    gluCylinder(gluCylBl1, 0.07, 0.07, 1, 20, 10);

    GLUquadric* gluCylBl1Disk1 = gluNewQuadric();
    gluQuadricTexture(gluCylBl1Disk1, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl1Disk1, GLU_LINE);
    gluDisk(gluCylBl1Disk1, 0, 0.07, 20, 10);

    glTranslatef(0, 0, 1);
    GLUquadric* gluCylBl1Disk2 = gluNewQuadric();
    gluQuadricTexture(gluCylBl1Disk2, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl1Disk2, GLU_LINE);
    gluDisk(gluCylBl1Disk2, 0, 0.07, 20, 10);
    glTranslatef(0, 0, -1);

        glTranslatef(0, 0, -1);

        GLUquadric* gluCylBl12 = gluNewQuadric();
        gluQuadricTexture(gluCylBl12, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl12, GLU_LINE);
        gluCylinder(gluCylBl12, 0.04, 0.04, 1.3, 20, 10);

        GLUquadric* gluCylBl12Disk1 = gluNewQuadric();
        gluQuadricTexture(gluCylBl12Disk1, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl12Disk1, GLU_LINE);
        gluDisk(gluCylBl12Disk1, 0, 0.04, 20, 10);

        glTranslatef(0, 0, 1.3);
        GLUquadric* gluCylBl12Disk2 = gluNewQuadric();
        gluQuadricTexture(gluCylBl12Disk2, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl12Disk2, GLU_LINE);
        gluDisk(gluCylBl12Disk2, 0, 0.04, 20, 10);
        glTranslatef(0, 0, -1.3);

            glTranslatef(0, 0, -0.07);

            glColor3f(0.5, 0.5, 0.5);

            GLUquadric* gluCylBl13 = gluNewQuadric();
            gluQuadricTexture(gluCylBl13, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl13, GLU_LINE);
            gluCylinder(gluCylBl13, 0.065, 0.065, 0.07, 20, 10);

            GLUquadric* gluCylBl13Disk1 = gluNewQuadric();
            gluQuadricTexture(gluCylBl13Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl13Disk1, GLU_LINE);
            gluDisk(gluCylBl13Disk1, 0, 0.065, 20, 10);

            glTranslatef(0, 0, 0.07);
            GLUquadric* gluCylBl13Disk2 = gluNewQuadric();
            gluQuadricTexture(gluCylBl13Disk2, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl13Disk2, GLU_LINE);
            gluDisk(gluCylBl13Disk2, 0, 0.065, 20, 10);
            glTranslatef(0, 0, -0.07);

            glTranslatef(0, 0, 0.07);

        glTranslatef(0, 0, 1);

    glTranslatef(2.5, -0.465, -0.15);

    /*blaster gore desno*/
    glTranslatef(2.5, 0.465, 0.15);

    glColor3f(0.8, 0.8, 0.8);
    GLUquadric* gluCylBl2 = gluNewQuadric();
    gluQuadricTexture(gluCylBl2, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl2, GLU_LINE);
    gluCylinder(gluCylBl2, 0.07, 0.07, 1, 20, 10);

    GLUquadric* gluCylBl2Disk1 = gluNewQuadric();
    gluQuadricTexture(gluCylBl2Disk1, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl2Disk1, GLU_LINE);
    gluDisk(gluCylBl2Disk1, 0, 0.07, 20, 10);

    glTranslatef(0, 0, 1);
    GLUquadric* gluCylBl2Disk2 = gluNewQuadric();
    gluQuadricTexture(gluCylBl2Disk2, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl2Disk2, GLU_LINE);
    gluDisk(gluCylBl2Disk2, 0, 0.07, 20, 10);
    glTranslatef(0, 0, -1);

        glTranslatef(0, 0, -1);

        GLUquadric* gluCylBl22 = gluNewQuadric();
        gluQuadricTexture(gluCylBl22, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl22, GLU_LINE);
        gluCylinder(gluCylBl22, 0.04, 0.04, 1.3, 20, 10);

        GLUquadric* gluCylBl22Disk1 = gluNewQuadric();
        gluQuadricTexture(gluCylBl22Disk1, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl22Disk1, GLU_LINE);
        gluDisk(gluCylBl22Disk1, 0, 0.04, 20, 10);

        glTranslatef(0, 0, 1.3);
        GLUquadric* gluCylBl22Disk2 = gluNewQuadric();
        gluQuadricTexture(gluCylBl22Disk2, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl22Disk2, GLU_LINE);
        gluDisk(gluCylBl22Disk2, 0, 0.04, 20, 10);
        glTranslatef(0, 0, -1.3);

            glTranslatef(0, 0, -0.07);

            glColor3f(0.5, 0.5, 0.5);

            GLUquadric* gluCylBl23 = gluNewQuadric();
            gluQuadricTexture(gluCylBl23, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl23, GLU_LINE);
            gluCylinder(gluCylBl23, 0.065, 0.065, 0.07, 20, 10);

            GLUquadric* gluCylBl23Disk1 = gluNewQuadric();
            gluQuadricTexture(gluCylBl23Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl23Disk1, GLU_LINE);
            gluDisk(gluCylBl23Disk1, 0, 0.065, 20, 10);

            glTranslatef(0, 0, 0.07);
            GLUquadric* gluCylBl23Disk2 = gluNewQuadric();
            gluQuadricTexture(gluCylBl23Disk2, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl23Disk2, GLU_LINE);
            gluDisk(gluCylBl23Disk2, 0, 0.065, 20, 10);
            glTranslatef(0, 0, -0.07);

            glTranslatef(0, 0, 0.07);

        glTranslatef(0, 0, 1);

    glTranslatef(-2.5, -0.465, -0.15);

    /*blaster dole levo*/
    glTranslatef(-2.5, -0.465, 0.15);

    glColor3f(0.8, 0.8, 0.8);
    GLUquadric* gluCylBl3 = gluNewQuadric();
    gluQuadricTexture(gluCylBl3, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl3, GLU_LINE);
    gluCylinder(gluCylBl3, 0.07, 0.07, 1, 20, 10);

    GLUquadric* gluCylBl3Disk1 = gluNewQuadric();
    gluQuadricTexture(gluCylBl3Disk1, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl3Disk1, GLU_LINE);
    gluDisk(gluCylBl3Disk1, 0, 0.07, 20, 10);

    glTranslatef(0, 0, 1);
    GLUquadric* gluCylBl3Disk2 = gluNewQuadric();
    gluQuadricTexture(gluCylBl3Disk2, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl3Disk2, GLU_LINE);
    gluDisk(gluCylBl3Disk2, 0, 0.07, 20, 10);
    glTranslatef(0, 0, -1);

        glTranslatef(0, 0, -1);

        GLUquadric* gluCylBl32 = gluNewQuadric();
        gluQuadricTexture(gluCylBl32, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl32, GLU_LINE);
        gluCylinder(gluCylBl32, 0.04, 0.04, 1.3, 20, 10);

        GLUquadric* gluCylBl32Disk1 = gluNewQuadric();
        gluQuadricTexture(gluCylBl32Disk1, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl32Disk1, GLU_LINE);
        gluDisk(gluCylBl32Disk1, 0, 0.04, 20, 10);

        glTranslatef(0, 0, 1.3);
        GLUquadric* gluCylBl32Disk2 = gluNewQuadric();
        gluQuadricTexture(gluCylBl32Disk2, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl32Disk2, GLU_LINE);
        gluDisk(gluCylBl32Disk2, 0, 0.04, 20, 10);
        glTranslatef(0, 0, -1.3);

            glTranslatef(0, 0, -0.07);

            glColor3f(0.5, 0.5, 0.5);

            GLUquadric* gluCylBl33 = gluNewQuadric();
            gluQuadricTexture(gluCylBl33, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl33, GLU_LINE);
            gluCylinder(gluCylBl33, 0.065, 0.065, 0.07, 20, 10);

            GLUquadric* gluCylBl33Disk1 = gluNewQuadric();
            gluQuadricTexture(gluCylBl33Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl33Disk1, GLU_LINE);
            gluDisk(gluCylBl33Disk1, 0, 0.065, 20, 10);

            glTranslatef(0, 0, 0.07);
            GLUquadric* gluCylBl33Disk2 = gluNewQuadric();
            gluQuadricTexture(gluCylBl33Disk2, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl33Disk2, GLU_LINE);
            gluDisk(gluCylBl33Disk2, 0, 0.065, 20, 10);
            glTranslatef(0, 0, -0.07);

            glTranslatef(0, 0, 0.07);

        glTranslatef(0, 0, 1);

    glTranslatef(2.5, 0.465, -0.15);

    /*blaster dole desno*/
    glTranslatef(2.5, -0.465, 0.15);

    glColor3f(0.8, 0.8, 0.8);
    GLUquadric* gluCylBl4 = gluNewQuadric();
    gluQuadricTexture(gluCylBl4, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl4, GLU_LINE);
    gluCylinder(gluCylBl4, 0.07, 0.07, 1, 20, 10);

    GLUquadric* gluCylBl4Disk1 = gluNewQuadric();
    gluQuadricTexture(gluCylBl4Disk1, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl4Disk1, GLU_LINE);
    gluDisk(gluCylBl4Disk1, 0, 0.07, 20, 10);

    glTranslatef(0, 0, 1);
    GLUquadric* gluCylBl4Disk2 = gluNewQuadric();
    gluQuadricTexture(gluCylBl4Disk2, GLU_TRUE);
    gluQuadricDrawStyle(gluCylBl4Disk2, GLU_LINE);
    gluDisk(gluCylBl4Disk2, 0, 0.07, 20, 10);
    glTranslatef(0, 0, -1);

        glTranslatef(0, 0, -1);

        GLUquadric* gluCylBl42 = gluNewQuadric();
        gluQuadricTexture(gluCylBl42, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl42, GLU_LINE);
        gluCylinder(gluCylBl42, 0.04, 0.04, 1.3, 20, 10);

        GLUquadric* gluCylBl42Disk1 = gluNewQuadric();
        gluQuadricTexture(gluCylBl42Disk1, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl42Disk1, GLU_LINE);
        gluDisk(gluCylBl42Disk1, 0, 0.04, 20, 10);

        glTranslatef(0, 0, 1.3);
        GLUquadric* gluCylBl42Disk2 = gluNewQuadric();
        gluQuadricTexture(gluCylBl42Disk2, GLU_TRUE);
        gluQuadricDrawStyle(gluCylBl42Disk2, GLU_LINE);
        gluDisk(gluCylBl42Disk2, 0, 0.04, 20, 10);
        glTranslatef(0, 0, -1.3);

            glTranslatef(0, 0, -0.07);

            glColor3f(0.5, 0.5, 0.5);

            GLUquadric* gluCylBl43 = gluNewQuadric();
            gluQuadricTexture(gluCylBl43, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl43, GLU_LINE);
            gluCylinder(gluCylBl43, 0.065, 0.065, 0.07, 20, 10);

            GLUquadric* gluCylBl43Disk1 = gluNewQuadric();
            gluQuadricTexture(gluCylBl43Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl43Disk1, GLU_LINE);
            gluDisk(gluCylBl43Disk1, 0, 0.065, 20, 10);

            glTranslatef(0, 0, 0.07);
            GLUquadric* gluCylBl43Disk2 = gluNewQuadric();
            gluQuadricTexture(gluCylBl43Disk2, GLU_TRUE);
            gluQuadricDrawStyle(gluCylBl43Disk2, GLU_LINE);
            gluDisk(gluCylBl43Disk2, 0, 0.065, 20, 10);
            glTranslatef(0, 0, -0.07);

            glTranslatef(0, 0, 0.07);

        glTranslatef(0, 0, 1);

    glTranslatef(-2.5, 0.465, -0.2);


    /*gore levi motor*/
    glTranslatef(-0.7, 0.4, 0.2);
    glRotatef(0, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCyl2 = gluNewQuadric();
        gluQuadricTexture(gluqCyl2, GLU_TRUE);
        gluQuadricDrawStyle(gluqCyl2, GLU_LINE);
        gluCylinder(gluqCyl2, 0.25, 0.25, 0.9, 20, 10);

        GLUquadric* gluqCyl2Disk1 = gluNewQuadric();
            gluQuadricTexture(gluqCyl2Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl2Disk1, GLU_LINE);
            gluDisk(gluqCyl2Disk1, 0, 0.25, 20, 10);

            glTranslatef(0, 0, 0.9);
                GLUquadric* gluqCyl2Disk2 = gluNewQuadric();
                gluQuadricTexture(gluqCyl2Disk2, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl2Disk2, GLU_LINE);
                gluDisk(gluqCyl2Disk2, 0, 0.25, 20, 10);
            glTranslatef(0, 0, -0.9);


        glTranslatef(0.125, 0, 0.9);
            glColor3f(0.8, 0.8, 0.8);
            GLUquadric* gluqCyl21 = gluNewQuadric();
            gluQuadricTexture(gluqCyl21, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl21, GLU_LINE);
            gluCylinder(gluqCyl21, 0.125, 0.125, 0.45, 20, 10);

            glTranslatef(0, 0, 0.45);
                glColor3f(0.6, 0.6, 0.6);
                GLUquadric* gluqCyl22 = gluNewQuadric();
                gluQuadricTexture(gluqCyl22, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl22, GLU_LINE);
                gluCylinder(gluqCyl22, 0.160, 0.160, 0.18, 20, 5);

                GLUquadric* gluqCyl22Disk1 = gluNewQuadric();
                gluQuadricTexture(gluqCyl22Disk1, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl22Disk1, GLU_LINE);
                gluDisk(gluqCyl22Disk1, 0, 0.160, 20, 5);

                glTranslatef(0, 0, 0.160);
                    glColor3f(0.5, 0.5, 0.5);
                    GLUquadric* gluqCyl23 = gluNewQuadric();
                    gluQuadricTexture(gluqCyl23, GLU_TRUE);
                    gluQuadricDrawStyle(gluqCyl23, GLU_LINE);
                    gluCylinder(gluqCyl23, 0.160, 0.125, 0.14, 20, 5);

                    glTranslatef(0, 0, 0.14);
                        glColor3f(0.6, 0, 0.6);
                        GLUquadric* gluqCyl231Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl231Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl231Disk2, GLU_LINE);
                        gluDisk(gluqCyl231Disk2, 0, 0.0825, 20, 10);

                        glColor3f(0.7, 0, 0.7);
                        GLUquadric* gluqCyl232Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl232Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl232Disk2, GLU_LINE);
                        gluDisk(gluqCyl232Disk2, 0.0825, 0.125, 20, 10);
                    glTranslatef(0, 0, -0.14);

                glTranslatef(0, 0, -0.160);  


            glTranslatef(0, 0, -0.45);  


        glTranslatef(-0.125, 0, -0.9); 

    glTranslatef(0.7, -0.4, -0.2);       


    /*gore desni motor*/
    glRotatef(180, 0, 0, 1);
    glTranslatef(-0.7, -0.4, 0.2);      
    glRotatef(0, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCyl1 = gluNewQuadric();
        gluQuadricTexture(gluqCyl1, GLU_TRUE);
        gluQuadricDrawStyle(gluqCyl1, GLU_LINE);
        gluCylinder(gluqCyl1, 0.25, 0.25, 0.9, 20, 10);

        GLUquadric* gluqCyl1Disk1 = gluNewQuadric();
            gluQuadricTexture(gluqCyl1Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl1Disk1, GLU_LINE);
            gluDisk(gluqCyl1Disk1, 0, 0.25, 20, 10);

            glTranslatef(0, 0, 0.9);
                GLUquadric* gluqCyl1Disk2 = gluNewQuadric();
                gluQuadricTexture(gluqCyl1Disk2, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl1Disk2, GLU_LINE);
                gluDisk(gluqCyl1Disk2, 0, 0.25, 20, 10);
            glTranslatef(0, 0, -0.9);


        glTranslatef(0.125, 0, 0.9);
            glColor3f(0.8, 0.8, 0.8);
            GLUquadric* gluqCyl11 = gluNewQuadric();
            gluQuadricTexture(gluqCyl11, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl11, GLU_LINE);
            gluCylinder(gluqCyl11, 0.125, 0.125, 0.45, 20, 10);

            glTranslatef(0, 0, 0.45);
                glColor3f(0.6, 0.6, 0.6);
                GLUquadric* gluqCyl12 = gluNewQuadric();
                gluQuadricTexture(gluqCyl12, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl12, GLU_LINE);
                gluCylinder(gluqCyl12, 0.160, 0.160, 0.18, 20, 5);

                GLUquadric* gluqCyl12Disk1 = gluNewQuadric();
                gluQuadricTexture(gluqCyl12Disk1, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl12Disk1, GLU_LINE);
                gluDisk(gluqCyl12Disk1, 0, 0.160, 20, 5);

                glTranslatef(0, 0, 0.160);
                    glColor3f(0.5, 0.5, 0.5);
                    GLUquadric* gluqCyl13 = gluNewQuadric();
                    gluQuadricTexture(gluqCyl13, GLU_TRUE);
                    gluQuadricDrawStyle(gluqCyl13, GLU_LINE);
                    gluCylinder(gluqCyl13, 0.160, 0.125, 0.14, 20, 5);

                    glTranslatef(0, 0, 0.14);
                        glColor3f(0.6, 0, 0.6);
                        GLUquadric* gluqCyl131Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl131Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl131Disk2, GLU_LINE);
                        gluDisk(gluqCyl131Disk2, 0, 0.0825, 20, 10);

                        glColor3f(0.7, 0, 0.7);
                        GLUquadric* gluqCyl132Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl132Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl132Disk2, GLU_LINE);
                        gluDisk(gluqCyl132Disk2, 0.0825, 0.125, 20, 10);
                    glTranslatef(0, 0, -0.14);

                glTranslatef(0, 0, -0.160);  


            glTranslatef(0, 0, -0.45);  


        glTranslatef(-0.125, 0, -0.9);        


    glRotatef(-0, 0, 0, 1);    
    glTranslatef(0.7, 0.4, -0.2);
    glRotatef(-180, 0, 0, 1);

    /*dole desni motor*/
    glTranslatef(-0.7, -0.4, 0.2);
    glRotatef(0, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCyl3 = gluNewQuadric();
        gluQuadricTexture(gluqCyl3, GLU_TRUE);
        gluQuadricDrawStyle(gluqCyl3, GLU_LINE);
        gluCylinder(gluqCyl3, 0.25, 0.25, 0.9, 20, 10);

        GLUquadric* gluqCyl3Disk1 = gluNewQuadric();
            gluQuadricTexture(gluqCyl3Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl3Disk1, GLU_LINE);
            gluDisk(gluqCyl3Disk1, 0, 0.25, 20, 10);

            glTranslatef(0, 0, 0.9);
                GLUquadric* gluqCyl3Disk2 = gluNewQuadric();
                gluQuadricTexture(gluqCyl3Disk2, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl3Disk2, GLU_LINE);
                gluDisk(gluqCyl3Disk2, 0, 0.25, 20, 10);
            glTranslatef(0, 0, -0.9);


        glTranslatef(0.125, 0, 0.9);
            glColor3f(0.8, 0.8, 0.8);
            GLUquadric* gluqCyl31 = gluNewQuadric();
            gluQuadricTexture(gluqCyl31, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl31, GLU_LINE);
            gluCylinder(gluqCyl31, 0.125, 0.125, 0.45, 20, 10);

            glTranslatef(0, 0, 0.45);
                glColor3f(0.6, 0.6, 0.6);
                GLUquadric* gluqCyl32 = gluNewQuadric();
                gluQuadricTexture(gluqCyl32, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl32, GLU_LINE);
                gluCylinder(gluqCyl32, 0.160, 0.160, 0.18, 20, 5);

                GLUquadric* gluqCyl32Disk1 = gluNewQuadric();
                gluQuadricTexture(gluqCyl32Disk1, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl32Disk1, GLU_LINE);
                gluDisk(gluqCyl32Disk1, 0, 0.160, 20, 5);

                glTranslatef(0, 0, 0.160);
                    glColor3f(0.5, 0.5, 0.5);
                    GLUquadric* gluqCyl33 = gluNewQuadric();
                    gluQuadricTexture(gluqCyl33, GLU_TRUE);
                    gluQuadricDrawStyle(gluqCyl33, GLU_LINE);
                    gluCylinder(gluqCyl33, 0.160, 0.125, 0.14, 20, 5);

                    glTranslatef(0, 0, 0.14);
                        glColor3f(0.6, 0, 0.6);
                        GLUquadric* gluqCyl331Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl331Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl331Disk2, GLU_LINE);
                        gluDisk(gluqCyl331Disk2, 0, 0.0825, 20, 10);

                        glColor3f(0.7, 0, 0.7);
                        GLUquadric* gluqCyl332Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl332Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl332Disk2, GLU_LINE);
                        gluDisk(gluqCyl332Disk2, 0.0825, 0.125, 20, 10);
                    glTranslatef(0, 0, -0.14);

                glTranslatef(0, 0, -0.160);  


            glTranslatef(0, 0, -0.45);  


        glTranslatef(-0.125, 0, -0.9); 

    glTranslatef(0.7, 0.4, -0.2);   


    /*dole levi motor*/
    glRotatef(180, 0, 0, 1);
    glTranslatef(-0.7, 0.4, 0.2);      
    glRotatef(0, 0, 0, 1);
        glColor3f(0.8, 0.8, 0.8);
        GLUquadric* gluqCyl4 = gluNewQuadric();
        gluQuadricTexture(gluqCyl4, GLU_TRUE);
        gluQuadricDrawStyle(gluqCyl4, GLU_LINE);
        gluCylinder(gluqCyl4, 0.25, 0.25, 0.9, 20, 10);

        GLUquadric* gluqCyl4Disk1 = gluNewQuadric();
            gluQuadricTexture(gluqCyl4Disk1, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl4Disk1, GLU_LINE);
            gluDisk(gluqCyl4Disk1, 0, 0.25, 20, 10);

            glTranslatef(0, 0, 0.9);
                GLUquadric* gluqCyl4Disk2 = gluNewQuadric();
                gluQuadricTexture(gluqCyl4Disk2, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl4Disk2, GLU_LINE);
                gluDisk(gluqCyl4Disk2, 0, 0.25, 20, 10);
            glTranslatef(0, 0, -0.9);


        glTranslatef(0.125, 0, 0.9);
            glColor3f(0.8, 0.8, 0.8);
            GLUquadric* gluqCyl41 = gluNewQuadric();
            gluQuadricTexture(gluqCyl41, GLU_TRUE);
            gluQuadricDrawStyle(gluqCyl41, GLU_LINE);
            gluCylinder(gluqCyl41, 0.125, 0.125, 0.45, 20, 10);

            glTranslatef(0, 0, 0.45);
                glColor3f(0.6, 0.6, 0.6);
                GLUquadric* gluqCyl42 = gluNewQuadric();
                gluQuadricTexture(gluqCyl42, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl42, GLU_LINE);
                gluCylinder(gluqCyl42, 0.160, 0.160, 0.18, 20, 5);

                GLUquadric* gluqCyl42Disk1 = gluNewQuadric();
                gluQuadricTexture(gluqCyl42Disk1, GLU_TRUE);
                gluQuadricDrawStyle(gluqCyl42Disk1, GLU_LINE);
                gluDisk(gluqCyl42Disk1, 0, 0.160, 20, 5);

                glTranslatef(0, 0, 0.160);
                    glColor3f(0.5, 0.5, 0.5);
                    GLUquadric* gluqCyl43 = gluNewQuadric();
                    gluQuadricTexture(gluqCyl43, GLU_TRUE);
                    gluQuadricDrawStyle(gluqCyl43, GLU_LINE);
                    gluCylinder(gluqCyl43, 0.160, 0.125, 0.14, 20, 5);

                    glTranslatef(0, 0, 0.14);
                        glColor3f(0.6, 0, 0.6);
                        GLUquadric* gluqCyl431Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl431Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl431Disk2, GLU_LINE);
                        gluDisk(gluqCyl431Disk2, 0, 0.0825, 20, 10);

                        glColor3f(0.7, 0, 0.7);
                        GLUquadric* gluqCyl432Disk2 = gluNewQuadric();
                        gluQuadricTexture(gluqCyl432Disk2, GLU_TRUE);
                        gluQuadricDrawStyle(gluqCyl432Disk2, GLU_LINE);
                        gluDisk(gluqCyl432Disk2, 0.0825, 0.125, 20, 10);
                    glTranslatef(0, 0, -0.14);

                glTranslatef(0, 0, -0.160);  

            glTranslatef(0, 0, -0.45);  

        glTranslatef(-0.125, 0, -0.9);
        glRotatef(180, 0, 0, 1);
}