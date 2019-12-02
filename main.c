#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
//#include "function.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_special_key_press(int key, int x, int y);

void update(int value);

void left();
void right();

static int window_width, window_height;
static int h, v = 0;/*za razgledanje*/

int g_game_active = 1;

/*pracenje tekuce i zeljene pozicije xwing-a u odnosu na staze*/
int g_current_pos = 0;
int g_desired_pos = 0;

/*pracenje pozicije u kojoj crta xwing*/
double rotacija = 0;
double translacija = 0;


int main(int argc, char** argv){

	/*inicijalizacija biblioteke i prozora*/
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);

	glutCreateWindow(argv[0]);

	glutFullScreen();

	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
    glutSpecialFunc(on_special_key_press);
    glutSetCursor(GLUT_CURSOR_NONE);

	/*prostor za timer funkciju*/

	/*osvetljenje*/
	GLfloat light_ambient[] = {0.3, 0.3, 0.3, 0.7};
	GLfloat light_diffuse[] = {0.5, 0.5, 0.5, 0.7};
	GLfloat light_specular[] = {1, 1, 1, 1};

	//GLfloat model_ambient[] = {1, 1, 1, 0};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_position[] = {-3, 10, -4, 0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0);

    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    glutMainLoop();

    return 0;
}

void on_display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat light_position[] = {-5, 5, -1, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0, 6, 10, 0, 0, 0, 0, 1, 0);

	glRotatef(0+10*h, 0, 1, 0);
    glRotatef(0+10*v, 0, 0, 1);

    draw_track();

    glutTimerFunc(30, update, 0);

    draw_xwing(translacija, rotacija);

    draw_stardestroyer();

    glRotatef(-0+10*h, 0, 1, 0);
    glRotatef(-0+10*v, 0, 0, 1);

	glutSwapBuffers();
}

static void on_reshape(int width, int height){

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(60, (float) width / height, 0.01, 1500);

	window_width = width;
	window_height = height;
}

/*programiranje dugmica radi debagovanja i razgledanja*/
static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
    	/*na esc se prekida program*/
        exit(0);
        break;
    case 'h':
        h-=1;
        glutPostRedisplay();
        break;
    case 'j':
        h+=1;
        glutPostRedisplay();
        break;
    case 'u':
        v+=1;
        glutPostRedisplay();
        break;
    case 'n':
        v-=1;
        glutPostRedisplay();
        break;
    case 'a':

        if(translacija <= -3.25)
            break;

        translacija -= 3.25/30;
        rotacija += 12;
        glutPostRedisplay();
        break;
    case 'd':

        if(translacija >= 3.25)
            break;

        translacija += 3.25/30;
        rotacija -= 12;
        glutPostRedisplay();
        break;
    }


}

static void on_special_key_press(int key, int x, int y){

    switch(key){
        case GLUT_KEY_LEFT:
            if(g_game_active)
                left();
            break;
        case GLUT_KEY_RIGHT:
            if(g_game_active)
                right();
            break;
    }

}

/*skretanje u traku levo*/
void left(){

    if(g_current_pos != -1)
        g_desired_pos -= 1;

    glutPostRedisplay();

}


/*skretanje u traku desno*/
void right(){

    if(g_current_pos != +1)
        g_desired_pos += 1;

    glutPostRedisplay();

}

int update_count = 0;

/*fukncija za osvezavanje pozicije (tralacije i rotacije) x-winga*/
void update(int value){

    if(g_desired_pos != g_current_pos){

        if(update_count >= 60){
            update_count = 0;
            g_current_pos = g_desired_pos;
            return;
        }
        else{

            int coef_prom = 0;

            if(g_desired_pos < g_current_pos){
                coef_prom = -1;
            }
            else
                coef_prom = 1;

            translacija += coef_prom * 3.25/60;
            rotacija -= coef_prom * 6;
            update_count++;

            glutPostRedisplay();
                glutTimerFunc(80 + update_count * 5, update, 0);
        }
    }

}