#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Math.h>
float angle = 0;
void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
}
void display(void)
{
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 1.0, 1.0);
 glLoadIdentity (); /* clear the matrix */
gluLookAt(-1,3,5,0,0,0,0.2,1,0);
//gluLookAt(0,0,5,0,0,0,0,1,0);
//glTranslatef(step,0,0);
//veNgoiSao();
glPushMatrix();
	glScalef(1,2,1);
	glutWireCube(1.0);
glPopMatrix();
glPushMatrix();
	glTranslatef(0,2,0);
	glRotatef(90,1,0,0);
	glRotatef(angle,0,0,1);
	glutWireSphere(1,12,16);
glPopMatrix();
glFlush();
}
void reshape (int w, int h)
{ 
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//glOrtho(-50,50,-50,50,1.5,20.0);
 glMatrixMode (GL_MODELVIEW);
}
void spin(){
	if(angle < 360)
	angle = angle+0.005;
	else
		angle = 0;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(spin);
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
// glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}
