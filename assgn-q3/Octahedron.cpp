#include<GL\glut.h>


float xR,yR,zR;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1,1,1);
	glScalef(1.0,1.0,1.0);
	glRotatef(xR,1.0,0.0,0.0);
	glRotatef(yR,0.0,1.0,0.0);
	glRotatef(zR,0.0,0.0,1.0);
	glutWireOctahedron();
	glFlush();
}

void idle()
{
	yR += 0.01;
	display();
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	
	
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutInitDisplayMode(GLUT_RGBA);
	
	
	glutCreateWindow("My First Window");
	
	xR= yR =zR=13.0;
	
	
	glutDisplayFunc(display);
	
	glutIdleFunc(idle);
	
	glutMainLoop();
	return 0;
	
}
