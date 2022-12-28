#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500

int x1, yc1, x2, yc2, flag=0;

void drawPixel(int x, int y){
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void drawLine(){

	int inc1, inc2, incx=1, incy=1, dx, dy, e, i, x, y;

	dx = x2 - x1;
	dy = yc2- yc1;

	if(dy<0){
		dy = -dy;
		incy = -1;
	}

	if(dx<0){
		dx=-dx;
		incx=-1;
	}

	if(dx==0){
		for(i=0;i<=dy;i++){
			drawPixel(x1, yc1+i);
		}
		return;
	}

	if(dy==0){
		for(i=0;i<=dx;i++){
			drawPixel(x1+i, yc1);
		}
		return;
	}

	x = x1;
	y = yc1;

	if(dx>=dy){
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		e = 2*dy - dx;

		for(i=0;i<dx;i++){
			if(e>=0){
				y+=incy;
				e+=inc1;
			}
			else
				e+=inc2;
			x+=incx;
			drawPixel(x, y);
		}
	}

	else{
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		e=2*dx-dy;

		for(i=0;i<dy;i++){
			if(e>=0){
				x+=incx;
				e+=inc1;
			}
			else
				e+=inc2;
			y+=incy;
			drawPixel(x, y);
		}
	}
	glFlush();
}


void display(){}

void myInit(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	gluOrtho2D(-250, 250, -250, 250);
}

void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(flag==0){
			flag++;
			x1=x-250;
			yc1=250-y;

		}
		else{
			flag--;
			x2=x-250;
			yc2=250-y;
			drawLine();
		}

	}
}



int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	

	int option;

	cout<< "Enter 1: For Keyboard\nEnter 2: For Mouse\n";
	cin>> option;

	if(option==1){
		cout<<"x1: \n"; cin>>x1; cout<< "y1: \n"; cin>>yc1;
		cout<<"x2: \n"; cin>>x2; cout<<"y2: \n"; cin>>yc2;
		glutCreateWindow("Line Drawing");
		glutDisplayFunc(drawLine);
		myInit();
	}

	else{
		glutCreateWindow("Line Drawing");
		glutMouseFunc(mouse);
		glutDisplayFunc(display);
		myInit();
	}

	glutMainLoop();


	return 0;
}