#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1, x2, y1, y2;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	int dy, dx, step, xin, yin, x, y;
	dy = y2 - y1;
	dx = x2 - x1;

	if (abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else step = abs(dy);

	xin = dx / step;
	yin = dy / step;

	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	for (int i = 0; i < step; i++) {
		x = x + xin;
		y = y + yin;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}

	glFlush();
}

void init(void)
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glPointSize(3.0);
	glLoadIdentity();
	gluOrtho2D(0, 499, 0, 499);
}

void main(int argc, char **argv){
	printf("Enter the value of x1: ");
	scanf_s("%d", &x1);
	printf("Enter the value of y1: ");
	scanf_s("%d", &y1);
	printf("Enter the value of x2: ");
	scanf_s("%d", &x2);
	printf("Enter the value of y2: ");
	scanf_s("%d", &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DDA Line Drawing Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}