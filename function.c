#include "function.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*funkcija crtanja neprijateljskog lasera*/
void draw_enemy_laser(int lane, double position){

	/*crtanje lasera u zavisnosti od staze i pozicije*/
	double tx = -0.3;
	double ty = -0.2;
	double tz = position;

	if(lane == -1)
		tx -= 3.25;
	else if(lane == 1)
		tx += 3.25;

	glTranslatef(tx, ty, tz);

	GLUquadric* gluqEnLaser = gluNewQuadric();
			glColor3f(0.2, 0.8, 0.5);
            gluQuadricTexture(gluqEnLaser, GLU_TRUE);
            gluQuadricDrawStyle(gluqEnLaser, GLU_FILL);
            gluCylinder(gluqEnLaser, 0.125, 0.125, 1, 20, 10);

    glTranslatef(-tx, -ty, -tz);
}