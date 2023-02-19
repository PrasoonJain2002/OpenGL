#include <GL/glut.h>
#include <stdio.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4, 0.6, 0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.1, 0.3);
	glVertex2f(-0.1, 0.1);
	glVertex2f(-0.4, 0.1);
	glEnd();

	glFlush();
}

void init() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Rectangle on Black BG");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}