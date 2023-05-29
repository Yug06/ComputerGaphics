/*
 * ghar.c
 *
 *  Created on: 04-Nov-2022
 *      Author: Yug
 */

#include<stdio.h>
#include<stdio.h>
#include <math.h>
#include<GL/glut.h>
#include "ghar.h"

void display(){
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	DDA(150,100,650,100); //base line
	DDA(100,400,700,400); //roof bottom
	DDA(150,100,150,400);	//side
	DDA(650,100,650,400);	//side
	DDA(150,550,650,550); //roof up

	DDA(150,550,100,400);	//roof side
	DDA(700,400,650,550);	//roof side

	DDA(350,100,350,270);	//door(left)
	DDA(450,100,450,270);	//door(right)
	DDA(350,270,450,270);	//door

	circle(30,250,300);	//window-1
	DDA(250,270,250,330);
	DDA(220,300,280,300);

	circle(30,550,300);	//window
	DDA(550,270,550,330);
	DDA(520,300,580,300);

	//DDA(100,100,400,400);
	//circle(50,100,100);
	glEnd();
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 20);
	glutInitWindowSize(800, 600);

	glutCreateWindow("GHAR");
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION);


	glutMainLoop();

	return 0;

}
