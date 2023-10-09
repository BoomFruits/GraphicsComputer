#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Math.h>
float angle = 0;
float angle1 =0;
void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
}
void display(void)
{
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 1.0, 1.0);
 glLoadIdentity (); /* clear the matrix */;
 gluLookAt(5,3,5,0,0,0,0,1,0);
glPushMatrix();
	glScalef(1,2,1);
	glRotatef(angle,0,1,0);
	glutWireCube(1);
glPopMatrix();
glPushMatrix();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex3f(0,1.5,0);
		glVertex3f(0,1.5,5);
	glEnd();
	glTranslatef(0,1.5,0);
	glRotatef(angle1,0,0,1);
	glTranslatef(0,-1.5,0);
		glTranslatef(0,3,0);
	glScalef(1,2,1);
	glutWireCube(1);
glPopMatrix();
glFlush();
}
void reshape (int w, int h)
{ 
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//glOrtho(-10,10,-10,10,1.5,20.0);
 glMatrixMode (GL_MODELVIEW);
}
void spin(){
	if(angle < 360)
	angle = angle+0.005;
	else
		angle = 0;
	glutPostRedisplay();
}
void spin1(){
		if(angle < 360)
	angle1 = angle1+0.005;
	else
		angle1 = 0;
	glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y){
	if(key == 'q'){
		glutIdleFunc(spin);
	}else if(key == 'r'){
		glutIdleFunc(spin1);
	}
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (argv[0]);
 init ();
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}
