#include <GL\glut.h>
#include<math.h>

float angle = 150.0 + 0.0;
float angle2 = 80.0;
float angle3 = 120.0;
float angle4 = 160.0;
float angle5 = 200.0;
float angle6 = 140.0;
float angle7 = 240.0;
float angle8 = 240.0;
float angle9 = 150.0;
float angle10 = 290.0;
void display(void);
void reshape(int x, int y);
int value;
void GoMenu(int value);
bool check;
bool check2;
bool check3;
bool check4;
bool check5;
bool check6;
bool check7;
bool check8;
bool check9;
bool check10;
bool check11;
bool checkk=false;
bool check15=true;
int j = 1.0;
int o = 1.0;
int p = 1.0;


///////////////////////////////
char text[] = "COMPUTER GRAPHICS PROJECT";
char text1[] = "PRESS D TO START ANIMATION";
char text2[] = "PRESS 0-9 TO ADD ELECTRONS";
//char text3[] = "PRESS C TO CLEAR";
char text4[] = "LEFT MOUSE CLICK FOR PLATFORM";
char text5[] = "RIGHT MOUSE CLICK TO REMOVE PLATFORM";
///////////////////////////////
void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        check = true;

    }

    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        check = false;
    }
    glutPostRedisplay();
}
/////////////////////////////////

///////////////////////////////
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        check2 = true;
        break;
    case '2':
        check3 = true;
        break;
    case '3':
        check4 = true;
        break;
    case '4':
        check5 = true;
        break;
    case '5':
        check6 = true;
        break;
    case '6':
        check7 = true;
        break;
    case '7':
        check8 = true;
        break;
    case '8':
        check9 = true;
        break;
    case '9':
        check10 = true;
        break;
    case '0':
        check11 = true;
        break;
    case 's':
        check15 = false;
        break;
    }
    glutPostRedisplay();
}
//////////////////////////////

void idle(void)
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    display();
}
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);                   
    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);    
    glShadeModel(GL_SMOOTH); 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(350, 350);

    glutCreateWindow("Solid Sphere");
    int sub1 = glutCreateMenu(GoMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Blue", 2);
    glutAddMenuEntry("Green", 3);
    glutCreateMenu(GoMenu);
    glutAddSubMenu("Colors", sub1);
    glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    initGL();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
void GoMenu(int value) {
    switch (value) {
    case 1:
        j = 1.0;
        o = 0.0;
        p = 0.0;
        
        break;
    case 2:
        j = 0.0;
        o = 0.0;
        p = 1.0;
  
        break;
    case 3:
        j = 0.0;
        o = 1.0;
        p = 0.0;
 
        break;
    case 4:
        exit(0);
        break;

    }
    glutPostRedisplay();
}
void display(void)
{

    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //////////////////////
    glColor3f(3.0,3.0,3.0);
    if (check15) {
        glRasterPos3f(-1.5, 3.0, -0.5);
        for (int i = 0; text[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }

    glRasterPos3f(3.8, 3.0, -0.5);
    for (int i = 0; text1[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);

    glRasterPos3f(3.8, 2.5, -0.5);
    for (int i = 0; text2[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);

    //glRasterPos3f(3.8, 2.0, -0.5);
    //for (int i = 0; text3[i] != '\0'; i++)
      //  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);

    glRasterPos3f(3.8, 1.5, -0.5);
    for (int i = 0; text4[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text4[i]);

    glRasterPos3f(3.8, 1.0, -0.5);
    for (int i = 0; text5[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text5[i]);
    /////////////////////
    glColor3f(j, o, p);
    if (check) {
        glBegin(GL_QUADS);
        glVertex3f(6.0, -3.0, 0.0);
        glVertex3f(10.0, -4.0, 0.0);
        glVertex3f(-10.0, -4.0, 0.0);
        glVertex3f(-6.0, -3.0, 0.0);
        glEnd();
    }
    //////////////////////

    /////////////////////
    glPushMatrix();
    glTranslatef(0.0, 0.0, -2.0);

    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    ////////////////////
    
        if (check2) {
            glPushMatrix();
            angle += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle, 0.0, 1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle >= 360)
                angle = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.08, 20, 20);
            glPopMatrix();
        }


        //////////////////////////////////////////////////
        if (check3) {
            glPushMatrix();
            angle2 += 0.1;
            glTranslatef(0.0, 0.0, -3.0);
            glRotatef(angle2, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 0.0, -3.0);

            if (angle2 >= 360)
                angle2 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        //////////////////////////////////////////////////
        if (check4) {
            glPushMatrix();
            angle3 += 0.1;
            glTranslatef(0.0, 0.0, -3.0);
            glRotatef(angle3, 1.0, 1.0, 0.0);
            glTranslatef(0.0, 0.0, -3.0);

            if (angle3 >= 360)
                angle3 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        ////////////////////////////////////////////////////
        if (check5) {
            glPushMatrix();
            angle4 += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle4, 1.0, -1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle4 >= 360)
                angle4 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        /////////////////////////////////////////////////////////
        if (check6) {
            glPushMatrix();
            angle10 += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle10, -1.0, 1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle10 >= 360)
                angle10 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        ///////////////////////////////////////////////////////
        if (check7) {
            glPushMatrix();
            angle5 += 0.1;
            glTranslatef(0.3, 0.0, -5.0);
            glRotatef(angle5, -1.0, -1.0, 0.0);
            glTranslatef(0.3, 0.0, -5.0);

            if (angle5 >= 360)
                angle5 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        //////////////////////////////////////////////////

        if (check8) {
            glPushMatrix();
            angle6 += 0.1;
            glTranslatef(0.0, 0.0, -3.0);
            glRotatef(angle6, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 0.0, -3.0);

            if (angle6 >= 360)
                angle6 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        ///////////////////////////////////////////////////////////////////////////
        if (check9) {
            glPushMatrix();
            angle7 += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle7, 0.0, 1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle7 >= 360)
                angle7 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        //////////////////////////////////////////////////////////////////////////////
        if (check10) {
            glPushMatrix();
            angle8 += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle8, -1.0, -1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle8 >= 360)
                angle8 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        ////////////////////////////////////////////////////////
        if (check11) {
            glPushMatrix();
            angle9 += 0.1;
            glTranslatef(0.0, 0.0, -5.0);
            glRotatef(angle9, -1.0, -1.0, 0.0);
            glTranslatef(0.0, 0.0, -5.0);

            if (angle9 >= 360)
                angle9 = 0;
            glColor3f(0.5, 0.5, 0.5);
            glutSolidSphere(0.1, 20, 20);
            glPopMatrix();
        }
        ////////////////////////////////////////////////////////
    
    glutSwapBuffers();
    
}

void reshape(int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    gluPerspective(55.0, (GLdouble)x / (GLdouble)y, 0.6, 21.0);
    gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

