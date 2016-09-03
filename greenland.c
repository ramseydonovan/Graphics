// Program made by Donovan Ramsey for Patrick Juola 
// Uses OpenGL to make Greenland's flag
#include <stdio.h>
//LINUX OR WINDOWS #include <GL/glut.h>
#include <glut/glut.h>
#include <math.h>


void display(){
glClearColor( 255.0/255.0, 255.0/255.0,255.0/255.0 ,1.0); // White 
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON); // red bottom half of the flag 
glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(600,150);
glVertex2f(600,0);
glEnd();

glBegin(GL_POLYGON); // red half cirlce 
glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); 
 
double theta = 0.0; 
for(theta = 0; theta <=  3.141592654; theta = theta + 3.141592654 / 100) { 
glVertex2f(185 + 110 * cos(theta) , 150 + 110 * sin(theta) ); 
}

glEnd();

glBegin(GL_POLYGON); // white half circle  
glColor3f(1, 1, 1);
 
theta = 0.0; 
for(theta = 3.141592654; theta <=  2 * 3.141592654; theta = theta + 2 * 3.141592654 / 100) {
glVertex2f(185 + 110 * cos(theta) , 150 + 110 * sin(theta) ); 
}

glEnd();
 glFlush();
}

int main(int argc, char **argv){

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,300);
 glutCreateWindow("Gflag");
 glutDisplayFunc(display);
 glOrtho( 0, 500, 0, 300, -1, 1 );
 glutMainLoop();


}