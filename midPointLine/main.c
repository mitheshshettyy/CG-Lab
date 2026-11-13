#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int x0,y0,x1,y1;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
}

void writePixel(int x,int y)
{
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void display()
{
    float dx=x1-x0, dy=y1-y0;
    float d=2*dy-dx;
    float dE=2*dy;
    float dNE=2*(dy-dx);
    int x=x0, y=y0;
    writePixel(x,y);

    while(x<x1)
    {
        if(d<0)
        {
            d+=dE;
            x++;
        }
        else
        {
            d+=dNE;
            x++;
            y++;
        }
        writePixel(x,y);
    }
}

int main(int argc, char** argv)
{
    printf("Enter the values: x0,y0,x1,y1 :");
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("MidPoint Line Algorithm");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
