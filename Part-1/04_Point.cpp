#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glFlush();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // Background Color
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Blank Window");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

	return 0;
}