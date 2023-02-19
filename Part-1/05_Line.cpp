#include <GL/glut.h>
#include <stdio.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	{
		glVertex2i(10, 10);
		glVertex2i(50, 50);
	}
	glEnd();
	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 200);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Green Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

