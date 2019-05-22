#include <stdlib.h>
#include <GL/glut.h>

void Inicializa(void)
{
	glClearColor(1,1,1,0);
}

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5,-0.5);
		glVertex2f( 0.0, 0.5);
		glVertex2f( 0.5,-0.5);
	glEnd();
	glutSwapBuffers();
}

void funcao_ociosa(void){
   glRotatef(1,0,0,1);
   glutPostRedisplay(); /* Manda o redesenhar a tela em cada frame, sempre que o sistema ficar ocioso */
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	glutIdleFunc(funcao_ociosa);//registramos a fun��o idle/ociosa
	Inicializa();
	glutMainLoop();
	return 0;
}
