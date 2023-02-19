#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;


int a = 0;
int b = 0;

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320,320,-240,240,-1,1);	
}

void equationLine(int x1,int y1,int x2,int y2) {
	b = (x1*y2-y1)/(x1-1);
	a = (y1-y2)/(x2-x1);
}
	
void LineBres(int x1,int y1,int x2,int y2)	
{
	equationLine(x1, y1, x2, y2);
  	int x = x1;	
	int y = y1;
	
	if(a> 1) {
	  	glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			x+=1;
			y = round(a*x +b);
	        glVertex2i(x,y);
	        glVertex2i(x+1,y);
	        glVertex2i(x,y+1);
	        glVertex2i(x,y-1);
	        glVertex2i(x-1,y);
		}
		glEnd();
	} else{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			x++;
			y = round(a*x +b);
	        glVertex2i(x,y);
	        glVertex2i(x+1,y);
	        glVertex2i(x,y+1);
	        glVertex2i(x,y-1);
	        glVertex2i(x-1,y);
		}
		glEnd();
	}
	
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	LineBres(10, 10, 200, 200);
	glViewport(0,0,640,480);
	glFlush();

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Thuat toan ve duong thang bang phuong trinh duong thang");
	 
	init();  
	glutDisplayFunc(display);    
	glutMainLoop();
	return 0;
}
