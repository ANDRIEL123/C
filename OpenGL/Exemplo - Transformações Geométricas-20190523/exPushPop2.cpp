
#include <stdlib.h>
#include <GL/glut.h> //GLUT, que inclui automaticamente a glu.h e a gl.h

void Inicializa(void)
{
	glClearColor(1,1,1,0);  //define a cor de fundo como branco e opaco
}

/* Esse m�todo callback � chamado na primeira vez
que a janela aparece para o usu�rio, e tamb�m sempre
que for necess�rio repintar a tela*/
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // limpa o buffer de cor com a cor setada no Inicializa



	glPushMatrix();
	glColor3f(1,0,0); //define a cor vermelha. Os elementos pintados a partir dessa linha ser�o vermelhos
	glTranslatef(-0.5,0,0);
    glutWireSphere(0.5,10,8);
    glPopMatrix();

    glPushMatrix();
	glColor3f(0,1,0); //define a cor verde. Os elementos pintados a partir dessa linha ser�o verdes
    glTranslatef(0.5,0,0);
    glutSolidSphere(0.5,20,8);
	glPopMatrix();

	glFlush(); //manda renderizar o desenho
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //buffer simples
	glutInitWindowSize(400,400); //define o tamanho da janela
	glutInitWindowPosition(50, 50); // posiciona a janela, cuja origem � no canto superior esquerdo
	glutCreateWindow("Primeiro Programa"); //cria uma janela com o t�tulo especificado
	glutDisplayFunc(Desenha); //registra a fun��o callback de redesenhenho
	Inicializa(); //inicializa��o pr�pria desse programa
	glutMainLoop(); // entra no la�o de processamento de eventos
	return 0;
}
