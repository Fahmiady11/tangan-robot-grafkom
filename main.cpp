/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int shoulder = 0, elbow = 0, siku=0;
void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
}
void display(void)
{
 glClear (GL_COLOR_BUFFER_BIT);
 glPushMatrix();
    glTranslatef (0.0, -1.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) siku, 0.0, 1.0, 0.0);
    glTranslatef (0.0, 1.0, 0.0);

    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();

 glPopMatrix();
 glutSwapBuffers();
}
void reshape (int w, int h)
{
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glTranslatef (0.0, 0.0, -5.0);
}
void keyboard (unsigned char key, int x, int y)
{
 switch (key)
 {
 case 's':
 shoulder = (shoulder + 5) % 360;
 glutPostRedisplay();
 break;
 case 'S':
 shoulder = (shoulder - 5) % 360;
 glutPostRedisplay();
 break;
 case 'e':
 elbow = (elbow + 5) % 360;
 glutPostRedisplay();
 break;
 case 'E':
 elbow = (elbow - 5) % 360;
 glutPostRedisplay();
 break;

 case 'd':
 siku = (siku + 5) % 360;
 glutPostRedisplay();
 break;
 case 'D':
 siku = (siku - 5) % 360;
 glutPostRedisplay();
 break;
 case 27:
 exit(0);
 break;
 default:
 break;
 }
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize (700, 600);
 glutInitWindowPosition (100, 100);
 glutCreateWindow (argv[0]);
 init ();
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}
