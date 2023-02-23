#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;


int deltaX = 0;
int deltaY = 0;

void init1()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}

void calculateDelta(int x1,int y1,int x2,int y2) {
	deltaX = x1 - x2;
	deltaY = y1 - y2;
}
	
void LineBres1(int x1,int y1,int x2,int y2)	
{
	calculateDelta(x1, y1, x2, y2);
  	int x = x1;	
	int y = y1;
	
	int m = max(abs(x), abs(y));
	int e = 1/m;
	int diffX = e*deltaX;
	int diffY = e*deltaY;
	
	  	glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			x+= diffX;
			y+= diffY;
	        glVertex2i(x,y);
	        glVertex2i(x+1,y);
	        glVertex2i(x,y+1);
	        glVertex2i(x,y-1);
	        glVertex2i(x-1,y);
		}
		glEnd();
	
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	LineBres1(10, 10, 200, 200);
	glViewport(0,0,640,480);
	glFlush();

}

int min(int argc, char** argv){
	glutInit(&argc, argv);
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Thuat toan ve duong thang bang phuong trinh duong thang");
	 
	init1();  
	glutDisplayFunc(display);    
	glutMainLoop();
	return 0;
}
