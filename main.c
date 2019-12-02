#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "function.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_special_key_press(int key, int x, int y);

void update_xwing(int value);
void update_enemy_laser(int value);
void update_fireball(int value);

void left();
void right();

static int window_width, window_height;
static int h, v = 0;/*za razgledanje*/

int g_game_active = 1;
int g_poraz = 0;

/*pracenje tekuce i zeljene pozicije xwing-a u odnosu na staze*/
int g_current_pos = 0;
int g_desired_pos = 0;
int g_current_hitbox = 0;
/*brojac azuriranja xwinga*/
int update_xwing_count = 0;

/*pozicija neprijateljskog lasera*/
double g_el_position = -15;
int g_el_in_flight = 0;
int g_el_lane = 0;
/*funkcija azuriranja neprijateljskog lasera*/
int update_el_count = 0;

/*pracenje pozicije u kojoj crta xwing*/
double rotacija = 0;
double translacija = 0;

/*pracenje eksplozije*/
double fireball_size = 0;
int update_fireball_count = 0;


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

    if(g_game_active){
        glutTimerFunc(30, update_xwing, 0);
        glutTimerFunc(100, update_enemy_laser, 1);
    }

    draw_xwing(translacija, rotacija);

    draw_stardestroyer();

    if(!g_el_in_flight){
        g_el_in_flight = 1;
        g_el_lane = g_current_pos;
    }

    draw_enemy_laser(g_el_lane, g_el_position);

    if(g_poraz){
        draw_l_fireball(g_current_hitbox, fireball_size);
        glutTimerFunc(30 + update_fireball_count * 10, update_fireball, 2);
    }
    

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
    case 'p':
        if(g_game_active){
            g_game_active = 0;
            glutPostRedisplay();
        }
        else{
            g_game_active = 1;
            glutPostRedisplay();
        }
        break;
    case 'r':
        /*reset*/

        g_game_active = 1;
        g_poraz = 0;
        /*pracenje tekuce i zeljene pozicije xwing-a u odnosu na staze*/
        g_current_pos = 0;
        g_desired_pos = 0;
        g_current_hitbox = 0;

        /*pozicija neprijateljskog lasera*/
        g_el_position = -15;
        g_el_in_flight = 0;
        g_el_lane = 0;

        /*pracenje pozicije u kojoj crta xwing*/
        rotacija = 0;
        translacija = 0;

        /*azuriranja*/
        update_xwing_count = 0;
        update_el_count = 0;

        fireball_size = 0;
        update_fireball_count = 0;

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

/*funkcija za osvezavanje pozicije (translacije i rotacije) x-winga*/
void update_xwing(int value){

    if(g_desired_pos != g_current_pos){

        /*azuriranje hitboxa*/
        if(update_xwing_count > 30){
            g_current_hitbox = g_desired_pos;
        }

        /*provera stizanja u novu stazu*/
        if(update_xwing_count >= 60){
            update_xwing_count = 0;
            g_current_pos = g_desired_pos;
            return;
        }
        else{

            /*postepeno menjanje staze*/
            
            int coef_prom = 0;

            if(g_desired_pos < g_current_pos){
                coef_prom = -1;
            }
            else
                coef_prom = 1;

            translacija += coef_prom * 3.25/60;
            rotacija -= coef_prom * 6;
            update_xwing_count++;

            glutPostRedisplay();

            if(g_game_active)
                glutTimerFunc(80 + update_xwing_count * 5, update_xwing, 0);
        }
    }

}

/*funkcija za osvezavanje pozicije neprijateljskog lasera*/
void update_enemy_laser(int value){

    /*resetovanje pozicije lasera posle promasaja*/
    if(update_el_count >= 60){
        update_el_count = 0;
        g_el_position = -15;
        g_el_in_flight = 0;
        return;
    }
    else{

        /*provera kolizije*/
        if(g_el_position >= 3 && g_el_lane == g_current_hitbox){
            g_game_active = 0;
            g_poraz = 1;
            glutPostRedisplay();
            return;
        }

        g_el_position += 20.0/60;
        update_el_count++;     

        glutPostRedisplay();
        
        if(g_game_active)
            glutTimerFunc(2000 + update_el_count * 2000 * 2, update_enemy_laser, 1);

    }
}

void update_fireball(int value){

    if(update_fireball_count >= 60){
        return;
    }

    fireball_size += 2.0/60;
    update_fireball_count++;

    glutPostRedisplay();
    glutTimerFunc(60 + update_fireball_count * 10, update_fireball, 2);

}