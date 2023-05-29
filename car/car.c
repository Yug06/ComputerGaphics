/*
 * car.c
 *
 *  Created on: 12-Nov-2022
 *      Author: Yug
 */
#include<stdio.h>
#include <math.h>
#include<GL/glut.h>
#include "car.h"

void display(){
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//DDA(0,150,900,150);
	DDA(250,400,650,400); //left-right(up)
	DDA(250,400,250,320); //up-down(left)
	DDA(650,400,650,320); //up-down(right)

	DDA(250,320,320,320);//left from tire
	DDA(650,320,580,320);//right from tire
	DDA(380,320,520,320);//between tires

	DDA(340,400,370,450);//window left
	DDA(560,400,530,450);//window right
	DDA(370,450,530,450);//roof

	circle(30,350,320); //left tire
	circle(30,550,320);	//right tire

	DDA(0,290,900,290);//road

	floodfill8(350,320,intcolor,fillcolor);
	floodfill8(550,320,intcolor,fillcolor);
	floodfill8(400,360,intcolor,fillcolor1);
//	floodfill8(420,425,intcolor,fillcolor2);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 20);
	glutInitWindowSize(900, 700);

	glutCreateWindow("GHAR");
	gluOrtho2D(0.0, 900.0, 0.0, 700.0);
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION);


	glutMainLoop();

	return 0;

}


