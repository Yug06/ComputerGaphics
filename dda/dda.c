/*
 * dda.c
 *
 *  Created on: 08-Sep-2022
 *      Author: Yug
 */


/*
 * dda.c
 *
 *  Created on: 15-Jul-2020
 *      Author: root
 */

#include <stdio.h>
#include<math.h>
#include <GL/glut.h>

void DDA(int x1,int y1,int x2,int y2)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	float dx, dy, steps, xinc, yinc, x, y;
	int k;

	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) >= abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xinc = dx / steps;
	yinc = dy / steps;

	x = x1;
	y = y1;
	glColor3f(1.0,0.0,0.0);
	glPointSize(10.0);

	glBegin(GL_POINTS);
	  glVertex2f(round(x),round(y));

	  k = 1;

	  while(k <= steps)
	  {
		  x = x + xinc;
		  y = y + yinc;

		  glVertex2f(round(x),round(y));
		 // printf("x = %f and y = %f\n",round(x),round(y));
		  k++;
	  }


}

void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DDA(100,100,100,400);
	DDA(100,400,400,400);
	DDA(400,400,400,100);
	DDA(400,100,100,100);


	glEnd();
	glFlush();

}


int main(int argc, char **argv)
{
//	printf("Enter starting point(x1 and y1):");
//	scanf("%d %d",&x1,&y1);
//
//	printf("Enter end point(x2 and y2):");
//	scanf("%d %d",&x2,&y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,20);

	glutCreateWindow("DDA LINE Algorithm");

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	glutDisplayFunc(display);

	glutMainLoop();

return 0;
}
