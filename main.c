#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "function.h"
#include "image.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_special_key_press(int key, int x, int y);

void draw_background();

void update_xwing(int value);
void update_enemy_laser(int value);
void update_ally_laser(int value);
void update_fireball(int value);

void left();
void right();

/*imena fajla sa teksturama*/
#define FILENAME0 "./space.bmp"

/*identifikatori tekstura*/
static GLuint names[1];

static int window_width, window_height;
static int h, v = 0;/*za razgledanje*/

/*pracenje statusa igre*/
int g_game_active = 1;
int g_poraz = 0;
int g_pobeda = 0;

int g_star_destroyer_hp = 100;

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

/*pozicija prijateljskog lasera*/
double g_al_position = 5;
int g_al_in_flight = 0;
int g_al_lane = 0;
/*funkcija azuriranja prijateljskog lasera*/
int update_al_count = 0;
int g_al_shoot = 0;

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

	glutInitWindowSize(1800, 1000);
	glutInitWindowPosition(100, 100);

	glutCreateWindow(argv[0]);

	/*glutFullScreen();*/

	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
    glutSpecialFunc(on_special_key_press);
    glutSetCursor(GLUT_CURSOR_NONE);

	/*osvetljenje*/
	GLfloat light_ambient[] = {0.3, 0.3, 0.3, 0.7};
	GLfloat light_diffuse[] = {0.5, 0.5, 0.5, 0.7};
	GLfloat light_specular[] = {1, 1, 1, 1};

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

    /*teksture*/

    Image* image;

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    image = image_init(0, 0);

    /*Kreira se tekstura*/
    image_read(image, FILENAME0);

    glGenTextures(1, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    /*iskljucujemo aktivnu teksturu*/
    glBindTexture(GL_TEXTURE_2D, 0);

    /*brise objekat za citanje tekstura iz fajla*/
    image_done(image);

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

    draw_background();

    draw_track();

    if(g_game_active){
        glutTimerFunc(5, update_xwing, 0);
        glutTimerFunc(100, update_enemy_laser, 1);
    }

    draw_xwing(translacija, rotacija);

    draw_stardestroyer();
    draw_health_bar(g_star_destroyer_hp);

    if(g_al_shoot){


        if(!g_al_in_flight)
            g_al_lane = g_current_pos;

        draw_ally_laser(g_al_lane, g_al_position);
        glutTimerFunc(60, update_ally_laser, 3);

    }

    if(!g_el_in_flight){
        g_el_in_flight = 1;
        g_el_lane = g_current_pos;
    }

    draw_enemy_laser(g_el_lane, g_el_position);

    if(g_poraz){
        draw_l_fireball(g_current_hitbox, fireball_size);
        glutTimerFunc(5, update_fireball, 2);
    }

    if(g_pobeda){
    	draw_w_fireball(fireball_size);
    	glutTimerFunc(5, update_fireball, 2);
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

/*programiranje dugmica*/
static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
    	/*na esc se prekida program*/
    	/*oslobadjanje resursa za teksture*/
    	glDeleteTextures(2, names);
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
        g_pobeda = 0;
        g_star_destroyer_hp = 100;
        /*pracenje tekuce i zeljene pozicije xwing-a u odnosu na staze*/
        g_current_pos = 0;
        g_desired_pos = 0;
        g_current_hitbox = 0;

        /*pozicija neprijateljskog lasera*/
        g_el_position = -15;
        g_el_in_flight = 0;
        g_el_lane = 0;

        /*pozicija prijateljskog lasera*/
        g_al_position = 6;
        g_al_in_flight = 0;
        g_al_lane = 0;
        g_al_shoot = 0;

        /*pracenje pozicije u kojoj crta xwing*/
        rotacija = 0;
        translacija = 0;

        /*azuriranja*/
        update_xwing_count = 0;
        update_el_count = 0;
        update_al_count = 0;

        fireball_size = 0;
        update_fireball_count = 0;

        glutPostRedisplay();
        break;
    case ' ':
        if(g_game_active && g_al_shoot != 1 && !g_al_in_flight)
            g_al_shoot = 1;
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
        }
    }

}


/*funkcija za osvezavanje pozicije neprijateljskog lasera*/
void update_enemy_laser(int value){

	if(value != 1)
		return;

    if(!g_game_active)
        return;

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

    }
}


/*funkcija za osvezavanje pozicije neprijateljskog lasera*/
void update_ally_laser(int value){

	if(value != 3)
		return;

    if(!g_game_active)
        return;

    /*resetovanje pozicije lasera posle promasaja*/
    if(update_al_count >= 60){

        update_al_count = 0;
        g_al_position = 5;
        g_al_in_flight = 0;
        g_al_shoot = 0;


        return;
    }
    else{

        /*provera kolizije*/
        if(g_al_position <= -13.5){

            g_star_destroyer_hp-=5;

            if(g_star_destroyer_hp <= 0){
                g_game_active = 0;
                g_pobeda = 1;
                glutPostRedisplay();
                return;
            }
        }

        g_al_position -= 20.0/60;
        update_al_count++;     

        glutPostRedisplay();

    }
}


/*funkcija za osvezavanje eksplozije*/
void update_fireball(int value){

	if(value != 2)
		return;

    if(update_fireball_count >= 60){
        return;
    }

    fireball_size += 2.0/60;
    update_fireball_count++;

    glutPostRedisplay();

}


/*fukncija koja iscrtava pozadinu*/
void draw_background(){

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, names[0]);
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);

		glTexCoord2f(0, 0);
		glVertex3f(-60, 50, -20);

		glTexCoord2f(1, 0);
		glVertex3f(60, 50, -20);

		glTexCoord2f(1, 1);
		glVertex3f(60, -50, -20);

		glTexCoord2f(0, 1);
		glVertex3f(-60, -50, -20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

}