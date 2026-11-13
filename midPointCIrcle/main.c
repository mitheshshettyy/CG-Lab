#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
int radius;

void circlePoints(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glVertex2f(y, x);
    glVertex2f(y, -x);
    glVertex2f(x, -y);
    glVertex2f(-x, -y);
    glVertex2f(-y, -x);
    glVertex2f(-y, x);
    glVertex2f(-x, y);
    glEnd();
    glFlush();
}

void midpointCircle()
{
    int x = 0;
    int y = radius;
    float d = 1.25f - radius;
    circlePoints(x, y);
    while (y > x)
    {
        if (d <= 0)
        {
            d += 2 * x + 3;
            x++;
        }
        else
        {
            d += 2 * (x - y) + 5;
            x++;
            y--;
        }
        circlePoints(x, y);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    midpointCircle();
    glFlush();
}

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

int main(int argc, char** argv)
{
    printf("Enter the radius: ");
    scanf("%d", &radius);

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Circle Algorithm");

    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
