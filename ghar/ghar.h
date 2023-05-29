/*
 * ghar.h
 *
 *  Created on: 04-Nov-2022
 *      Author: Yug
 */

#ifndef GHAR_H_
#define GHAR_H_
void putpixel(int x, int y, int xc, int yc){
	glVertex2i(x+xc, y+yc);
	glVertex2i(y+xc, x+yc);
	glVertex2i(x+xc, -y+yc);
	glVertex2i(-y+xc, x+yc);
	glVertex2i(-x+xc, -y+yc);
	glVertex2i(-y+xc, -x+yc);
	glVertex2i(-x+xc, y+yc);
	glVertex2i(y+xc, -x+yc);
}

void circle(int r, int a, int b){
	int d1,x,y;
	x=0;
	y=r;
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	d1=3-(2*r);
	while(x<=y){
		if(d1<0){
			x++;
			d1=d1+4*x+6;
			putpixel(x,y,a,b);
		}
		else{
			x++;
			y--;
			d1=d1+4*(x-y)+10;
			putpixel(x,y,a,b);
		}
	}
}

void DDA(int x1, int y1, int x2, int y2){
	float dx,dy,steps,xinc,yinc,x,y;
	int k;

	dx=x2-x1;
	dy=y2-y1;

	if(abs(dx)>=abs(dy)){
		steps = abs(dx);
	}
	else{
		steps= abs(dy);
	}

	xinc = dx/steps;
	yinc= dy/steps;

	x=x1;
	y=y1;

	glPointSize(5.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2d(round(x), round(y));

	k=1;
	while(k<=steps){
		x=x+xinc;
		y=y+yinc;
		glVertex2d(round(x), round(y));
		k++;
	}
}



#endif /* GHAR_H_ */
