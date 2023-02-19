#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myinit() {
	glClearColor(0, 0, 0, 1.0); // Background Color
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Blank Window");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}