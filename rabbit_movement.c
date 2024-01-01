#include <GL/glut.h>

// Window dimensions
const int windowWidth = 800;
const int windowHeight = 600;

// Rabbit position and movement variables
GLfloat rabbitPosX = 0.0f, rabbitPosY = 0.0f;
GLfloat moveX = 0.01f, moveY = 0.01f;

// Function prototypes
void display();
void reshape(GLsizei width, GLsizei height);
void keyboard(unsigned char key, int x, int y);
void initGL();

int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DOUBLE); 
    glutInitWindowSize(windowWidth, windowHeight); 
    glutInitWindowPosition(50, 50);  
    glutCreateWindow("OpenGL Rabbit Movement");  

    glutDisplayFunc(display);  
    glutReshapeFunc(reshape);  
    glutKeyboardFunc(keyboard);  

    initGL();  
    glutMainLoop();  
    return 0;
}

void initGL() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);  
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);  
    float aspectRatio = (float)w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w >= h) {

        gluOrtho2D(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0);
    } else {

        gluOrtho2D(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio);
    }
}


void drawRabbit() {
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    glPushMatrix(); 
    glTranslatef(rabbitPosX, rabbitPosY, 0.0f);  


    glColor3f(0.50f, 0.50f, 0.0f);


    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.0f, 0.1f);
    glEnd();
    //Ear
    glBegin(GL_TRIANGLES);
    glVertex2f( 0.1f, 0.1f);
    glVertex2f(0.200f, 0.1f);
    glVertex2f(0.200f, 0.200f);
    glEnd();
    // Front body
    glBegin(GL_TRIANGLES);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.1f, -0.15f);
    glVertex2f(0.3f, -0.15f);    
    glEnd();
    // Front leg
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.05f, -0.15f);
    glVertex2f(0.20, -0.15f);
    glVertex2f(0.15f, -0.25f);
    glEnd();
    // Back body
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.4f, -0.25f);
    glEnd();
    // Back leg
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, -0.15f);
    glVertex2f(0.4f, -0.35f);
    glVertex2f(0.5f, -0.25f);
    glEnd();
    //Tail
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.5f, -0.05f);
    glVertex2f(0.5f, 0.05f);
    glEnd();

    glPopMatrix();  

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':  // Move left
            rabbitPosX -= moveX;
            break;
        case 'd':  // Move right
            rabbitPosX += moveX;
            break;
        case 'w':  // Move up
            rabbitPosY += moveY;
            break;
        case 's':  // Move down
            rabbitPosY -= moveY;
            break;
    }
    glutPostRedisplay();  
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
    glMatrixMode(GL_MODELVIEW);    

    drawRabbit();

    glutSwapBuffers();  
}