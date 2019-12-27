#include "function.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*funkcija crtanja neprijateljskog lasera*/
void draw_enemy_laser(int lane, double position){

	glPushMatrix();

	/*crtanje lasera u zavisnosti od staze i pozicije*/
	double tx = 0;
	double ty = 0;
	double tz = position;

	if(lane == -1)
		tx -= 3.25;
	else if(lane == 1)
		tx += 3.25;

	glTranslatef(tx, ty, tz);

	GLUquadric* gluqEnLaser = gluNewQuadric();
			glColor3f(32.0/255,178.0/255,170.0/255);
            gluQuadricTexture(gluqEnLaser, GLU_TRUE);
            gluQuadricDrawStyle(gluqEnLaser, GLU_FILL);
            gluCylinder(gluqEnLaser, 0.175, 0.175, 2, 20, 10);

    glTranslatef(-tx, -ty, -tz);

    glPopMatrix();
}

/*funkcija crtanja prijateljskog lasera*/
void draw_ally_laser(int lane, double position){

	glPushMatrix();

	/*crtanje lasera u zavisnosti od staze i pozicije*/
	double tx = 0;
	double ty = 0;
	double tz = position;

	if(lane == -1)
		tx -= 3.25;
	else if(lane == 1)
		tx += 3.25;

	glTranslatef(tx, ty, tz);

	/*laser gore levo*/
	glTranslatef(-2.5/2, 0.465/2, 0);

	GLUquadric* gluqAlLaser1 = gluNewQuadric();
			glColor3f(200.0/255,0/255,139.0/255);
            gluQuadricTexture(gluqAlLaser1, GLU_TRUE);
            gluQuadricDrawStyle(gluqAlLaser1, GLU_FILL);
            gluCylinder(gluqAlLaser1, 0.05, 0.05, 0.75, 20, 10);

    glTranslatef(2.5/2, -0.465/2, 0);      


    /*laser gore desno*/
	glTranslatef(2.5/2, 0.465/2, 0);

	GLUquadric* gluqAlLaser2 = gluNewQuadric();
			glColor3f(200.0/255,0/255,139.0/255);
            gluQuadricTexture(gluqAlLaser2, GLU_TRUE);
            gluQuadricDrawStyle(gluqAlLaser2, GLU_FILL);
            gluCylinder(gluqAlLaser2, 0.05, 0.05, 0.75, 20, 10);

    glTranslatef(-2.5/2, -0.465/2, 0);


    /*laser dole levo*/
	glTranslatef(-2.5/2, -0.465/2, 0);

	GLUquadric* gluqAlLaser3 = gluNewQuadric();
			glColor3f(200.0/255,0/255,139.0/255);
            gluQuadricTexture(gluqAlLaser3, GLU_TRUE);
            gluQuadricDrawStyle(gluqAlLaser3, GLU_FILL);
            gluCylinder(gluqAlLaser3, 0.05, 0.05, 0.75, 20, 10);

    glTranslatef(2.5/2, 0.465/2, 0);


    /*laser dole desno*/
	glTranslatef(2.5/2, -0.465/2, 0);

	GLUquadric* gluqAlLaser4 = gluNewQuadric();
			glColor3f(200.0/255,0/255,139.0/255);
            gluQuadricTexture(gluqAlLaser4, GLU_TRUE);
            gluQuadricDrawStyle(gluqAlLaser4, GLU_FILL);
            gluCylinder(gluqAlLaser4, 0.05, 0.05, 0.75, 20, 10);

    glTranslatef(-2.5/2, 0.465/2, 0);


    glTranslatef(-tx, -ty, -tz);

    glPopMatrix();
}

/*funkcija koja crta eksploziju*/
void draw_l_fireball(int lane, double size){

	glPushMatrix();

	double tx = 0;
	double ty = 0;
	double tz = 4.5;

	if(lane == -1)
		tx -= 3.25;
	else if(lane == 1)
		tx += 3.25;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	glPopMatrix();

}


/*funkcija koja crta eksplozije na star-destroyeru*/
void draw_w_fireball(double size){

	glPushMatrix();

	glTranslatef(0, 0, -15);

	double tx = 0;
	double ty = 0;
	double tz = 0;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	tx = -3;
	ty = 1;
	tz = 2;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	tx = 2;
	ty = 3;
	tz = -1;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	tx = -1;
	ty = 2;
	tz = -3;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	tx = 1;
	ty = 2;
	tz = 5;

	glTranslatef(tx, ty, tz);

	glColor3f(255.0/255,120.0/255,0);
	glutSolidSphere(size, 50, 50);

	glTranslatef(-tx, -ty, -tz);

	glPopMatrix();

}


/*izcrtavanje health-bara*/
void draw_health_bar(int hp){

	glTranslatef(-5, 5.2, -15);

	glPushMatrix();

		glRotatef(90, 0, 1, 0);

		/*unutrasnji cilindar*/
		GLUquadric* gluqHpCylInner = gluNewQuadric();
			glColor3f(0.6, 0.6, 0.6);
			gluQuadricTexture(gluqHpCylInner, GLU_TRUE);
			gluQuadricDrawStyle(gluqHpCylInner, GLU_FILL);
			gluCylinder(gluqHpCylInner, 0.2, 0.2, 10, 20, 10);


		/*kliping ravan za postepeno brisanje spoljasnjeg cilindra*/
		GLdouble plane0[] = {0, 0, -1, hp * 10 / 100.0};
		glClipPlane(GL_CLIP_PLANE0, plane0);
		glEnable(GL_CLIP_PLANE0);

		/*spoljasnji cilindar*/
		GLUquadric* gluqHpCylOuter = gluNewQuadric();
			glColor3f(1, 0.2, 0.2);
			gluQuadricTexture(gluqHpCylOuter, GLU_TRUE);
			gluQuadricDrawStyle(gluqHpCylOuter, GLU_FILL);
			gluCylinder(gluqHpCylOuter, 0.3, 0.3, 10, 20, 10);

		glDisable(GL_CLIP_PLANE0);

	glPopMatrix();

	glTranslatef(5, -5.2, 15);

}