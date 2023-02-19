#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int xc = 320, yc = 240;

void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}

void draw_circle(int r) {
	int x = 0, y = r;
	float pk = 3.0 - r*2.0;

	/* Plot the points */
	/* Plot the first point */
	plot_point(x, y);
	int k;
	/* Find all vertices till x=y */
	while (x < y)
	{
		x = x + 1;
		if (pk < 0)
			pk = pk + 4 * x + 6;
		else
		{
			y = y - 1;
			pk = pk + 4 * (x - y) + 10;
		}
		plot_point(x, y);
	}
	glFlush();
}

void display() {
	// Clears buffers to preset values
	glClear(GL_COLOR_BUFFER_BIT);

	int r = 100;
	draw_circle(r);
}

void init() {
	glClearColor(1, 1, 1, 1);
	// Set fill colour to black
	glColor3f(0, 0, 0);
	gluOrtho2D(0, 640, 0, 480);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Bresenham_Circle");
	// Initialize drawing colors
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}