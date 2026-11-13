#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
int x0, y0, x1, y1;

void writePixel(int x, int y)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void midpointLine()
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx;
    int dE = 2 * dy;
    int dNE = 2 * (dy - dx);
    int x = x0, y = y0;
    writePixel(x, y);
    while (x < x1)
    {
        if (d <= 0)
        {
            d += dE;
            x++;
        }
        else
        {
            d += dNE;
            x++;
            y++;
        }
        writePixel(x, y);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    midpointLine();
}

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

int main(int argc, char** argv)
{
    printf("Enter the coordinates x0, y0, x1, y1: ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Line Algorithm");

    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
