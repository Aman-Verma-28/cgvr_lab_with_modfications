#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define degtorad 180.0 / 3.14159

GLfloat x_single, y_single, x_double, y_double;
static GLfloat spin_single = 0, spin_double = 0;
int single_buffer_window, double_buffer_window;

void draw_square(GLfloat x, GLfloat y)
{
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(x, y);
	glColor3f(0, 1, 0);
	glVertex2f(-y, x);
	glColor3f(0, 0, 1);
	glVertex2f(-x, -y);
	glColor3f(1, 1, 0);
	glVertex2f(y, -x);
	glEnd();
}

void display_single_buffer_idle()
{
	spin_single += 0.00025;
	if (spin_single > 360) spin_single -= 360;
	x_single = cos(degtorad * spin_single);
	y_single = sin(degtorad * spin_single);

	glutSetWindow(single_buffer_window);
	printf("Redisplaying \n");
	glutPostRedisplay();
}

void display_double_buffer_idle()
{
	spin_double += 0.00025;
	if (spin_double > 360) spin_double -= 360;
	x_double = cos(degtorad * spin_double);
	y_double = sin(degtorad * spin_double);

	glutSetWindow(double_buffer_window);
	glutPostRedisplay();
}

void display_single_buffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_square(x_single, y_single);
	glFlush();
}

void display_double_buffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_square(x_double, y_double);
	glutSwapBuffers();
}

void mouse_func(int state, int button, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(display_double_buffer_idle);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
}

void my_init()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-2, 2, -2, 2);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	// single buffer window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	single_buffer_window = glutCreateWindow("Single Buffer");

	glutSetWindow(single_buffer_window);
	my_init();
	glutDisplayFunc(display_single_buffer);
	glutIdleFunc(display_single_buffer_idle);


	// double buffer window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 0);
	double_buffer_window = glutCreateWindow("Double Buffer");

	// glutSetWindow(double_buffer_window);
	my_init();
	glutDisplayFunc(display_double_buffer);
	glutIdleFunc(display_double_buffer_idle);
	glutMouseFunc(mouse_func);

	glutMainLoop();
}