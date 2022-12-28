#include<iostream>
#include<GL/glut.h>
#include<math.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int xc, yc, r;
int point1_done = 0;
int p1_x, p1_y, p2_x, p2_y;


void drawCricle(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(xc+x, yc+y);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc-x, yc-y);
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc-y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-y, yc-x);
	glEnd();
}

void circle(){
	int x = 0;
	int y = r;

	draw_circle()
}