#include<iostream>
#include<math.h>
#include<GL/glut.h>
const int screenWidth = 320;
const int screenHeight = 240;
GLdouble A, B, C, D;
const double PI = 3.1415926535897932384;
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	/*A = screenWidth / ;
	B = 0.0;
	C = D = screenHeight / ;*/
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (GLdouble x = 0; x < 300;x += 3) {
		GLdouble func = 300-100*cos((2*PI*x)/100) + 30*cos((4*PI*x)/100) + 6*cos((6*PI*x)/100);
		glVertex2d(x,func-200);
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);

	glutCreateWindow("Line Graph");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}