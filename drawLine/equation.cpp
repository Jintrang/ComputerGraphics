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

//Thuat toan ve duong thang bang phuong trinh duong thang	
void LineBres(int x1,int y1,int x2,int y2)	
{
	b = (x1*y2-y1)/(x1-1);
	a = (y1-y2)/(x2-x1);
	
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

//Thuat toan DDA

void DDA(int x1, int y1, int x2, int y2) {
	a = x1 - x2;
	b = y1 - y2; 
	
  	int x = x1;	
	int y = y1;
	
	int m = max(abs(a), abs(b));
	float e =  1/m;
	
	int diffX = e * a;
	int diffY = e * b;
	
	  	glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			x+=diffX;
			y+=diffY;
	        glVertex2i(x,y);
	        glVertex2i(x+1,y);
	        glVertex2i(x,y+1);
	        glVertex2i(x,y-1);
	        glVertex2i(x-1,y);
		}
		glEnd();
	
	}
	
// Thuat toan Bresenham

void Bresenham(int x1, int y1, int x2, int y2) {
	int d = 2 * b + a;
	
  	int x = x1;	
	int y = y1;
	
	  	glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			x++;
			if(d > 0) {
				glVertex2i(x,y);
				if(d > 2*a) {
					d = d - 2*a;
					}
				d = d + 2*b;
				}
	        glVertex2i(x,y);
	        glVertex2i(x+1,y);
	        glVertex2i(x,y+1);
	        glVertex2i(x,y-1);
	        glVertex2i(x-1,y);
		}
		glEnd();
	}
	
	
//Midpoint Line-Drawing Algorithm (Thuat toan diem giua)
void MLD(int x1,int y1,int x2,int y2)	
{
	int dx = x2 - x1, dy = y2 - y1;
	int d = 2*dy - dx;
	
	int pos = 2*dy;
	int neg = 2*(dy-dx);
	
	int x = x1, y = y1;
	glVertex2i(x,y);
	
	  	glBegin(GL_POINTS);
		glVertex2i(x,y);
		while (x < x2)  
		{
			if(d <= 0) {
				d = d + pos;
			} else {
				d = d + neg;
				y = y + 1;
			}
			x = x + 1;
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
	MLD(10, 10, 200, 200);
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
