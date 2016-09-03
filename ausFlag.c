// Program made by Donovan Ramsey for Patrick Juola 
// Uses OpenGL to make Australia's flag 
#include <stdio.h>
#include <glut/glut.h>
#include <math.h>

double pi = 3.141592654;
void display(){
glClearColor( 0.0/255.0, 39.0/255.0,118.0/255.0 ,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(20);
glBegin(GL_POLYGON); // white diagnal 1 
glColor3f(255.0/255.0,255.0/255.0, 255.0/255.0); // white

glVertex2f(0,285);
glVertex2f(0,300);
glVertex2f(25,300);
glVertex2f(300, 165);
glVertex2f(300, 150);
glVertex2f(275, 150);

glEnd();

glBegin(GL_POLYGON); // white diagnal 2
glColor3f(255.0/255.0,255.0/255.0, 255.0/255.0); // white

glVertex2f(275,300);
glVertex2f(300,300);
glVertex2f(300,285);
glVertex2f(25, 150);
glVertex2f(0, 150);
glVertex2f(0, 165);

glEnd();


glBegin(GL_POLYGON); // red diagnal 1 left 

glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(0,290);
glVertex2f(0,300);
glVertex2f(150, 225);
glVertex2f(150, 215);

glEnd();

glBegin(GL_POLYGON); // red diagnal 1 right 

glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(300,150);
glVertex2f(300,160);
glVertex2f(150, 235);
glVertex2f(150, 225);

glEnd();


glBegin(GL_POLYGON); // red diagnal 2 

glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(0,150);
glVertex2f(285, 300);
glVertex2f(300, 300);
glVertex2f(15,150);

glEnd(); 
// ____________________________________
glBegin(GL_POLYGON); // white horizontal 
glColor3f(255.0/255.0,255.0/255.0, 255.0/255.0); // white

glVertex2f(0,248);
glVertex2f(300,248);
glVertex2f(300,202);
glVertex2f(0,202);

glEnd();

glBegin(GL_POLYGON); // white vertical
glColor3f(255.0/255.0,255.0/255.0, 255.0/255.0); // white

glVertex2f(127,300);
glVertex2f(173,300);
glVertex2f(173,150);
glVertex2f(127,150);

glEnd();





// ____________________________________
glBegin(GL_POLYGON); //red horizontal
glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(0,240);
glVertex2f(300,240);
glVertex2f(300,210);
glVertex2f(0,210);

glEnd();

glBegin(GL_POLYGON); //red horizontal
glColor3f(208.0/255.0,12.0/255.0, 51.0/255.0); //red

glVertex2f(135,300);
glVertex2f(165,300);
glVertex2f(165,150);
glVertex2f(135,150);

glEnd();
//____________________________________________________________
int i;
double num_sides = 7.0; // number of triangles/sides of the polygon for the star
int xCoord[6] = {150, 450, 380, 450, 515,480}; // the positions of the stars on my flag
int yCoord[6] = {75, 50, 165, 248, 190, 142};
double theta = 0; 
double r = 14;  // the size of the star 
double star_point = 8; // how "pointy" the star's triangles are 
for (i = 0;  i < 6; i++){
	
	if (i == 5 ){
			num_sides = 5.0; 
			star_point = 2; 
			r = 6; 
		}
		
glBegin(GL_POLYGON); // **Modified Star code from Kinardi Isnata **
	glColor3f(1.0, 1.0, 1.0);
	
		for(theta =  pi * -90.0/180.0; theta <=  pi * 270.0/180.0; theta = theta + 2 * pi/num_sides)
	{
		glVertex2f(xCoord[i] + r * cos(theta), yCoord[i] + r * sin(theta));
	}
	glEnd();
	
	GLdouble points[3][2] = { 
								  {r * cos(54.0/180.0 * pi) , r * sin(54.0/180.0 * pi)}, //right
								  {0, (r+star_point) * cos(54.0/180.0 * pi) * sin(72.0/180.0 * pi)/cos(72.0/180.0 * pi)}, //top
								  {r * cos(126.0/180.0 * pi) ,r * sin(126.0/180.0 * pi)}
								};

	//Apply rotation formula on each coordinates to produce all triangles 
		for(double alpha = 0; alpha <= 2* pi ; alpha = alpha + 2 * pi /num_sides)
		{
			glBegin(GL_POLYGON);
			glColor3f(1.0,1.0,1.0);
			glVertex2f(xCoord[i] + points[0][0] * cos(alpha) - points[0][1] * sin(alpha), yCoord[i] + points[0][0] * sin(alpha) + points[0][1] * cos(alpha));
			glVertex2f(xCoord[i] + points[1][0] * cos(alpha) - points[1][1] * sin(alpha), yCoord[i] + points[1][0] * sin(alpha) + points[1][1] * cos(alpha));
			glVertex2f(xCoord[i] + points[2][0]  * cos(alpha) - points[2][1] * sin(alpha), yCoord[i] + points[2][0] * sin(alpha) + points[2][1] * cos(alpha));
			glEnd();
		}
		star_point = 5; 
		r = 8; 
}

 glFlush();
}

int main(int argc, char **argv){

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(600,300);
 glutCreateWindow("Gflag");
 glutDisplayFunc(display);
 glOrtho( 0, 600, 0, 300, -1, 1 );
 glutMainLoop();


}
