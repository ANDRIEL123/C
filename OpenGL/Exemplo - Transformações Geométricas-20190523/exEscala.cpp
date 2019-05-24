
#include <stdlib.h>
#include <GL/glut.h> //GLUT, que inclui automaticamente a glu.h e a gl.h

void Inicializa(void)
{
	glClearColor(1,1,1,0);  //define a cor de fundo como branco e opaco
}

/* Esse método callback é chamado na primeira vez 
que a janela aparece para o usuário, e também sempre 
que for necessário repintar a tela*/
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // limpa o buffer de cor com a cor setada no Inicializa
	
    glColor3f(1,0,0); //define a cor vermelha. Os elementos pintados a partir dessa linha serão vermelhos
	
	glScalef(2,1.5,1.0);
	glBegin(GL_TRIANGLES); //começa o desenho de um triangulo
		glVertex2f(-0.5,-0.5); //define um vértice do triangulo
		glVertex2f( 0.0, 0.5);
		glVertex2f( 0.5,-0.5);
	glEnd(); //finaliza o desenho do triangulo
	glFlush(); //manda renderizar o desenho
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //buffer simples
	glutInitWindowSize(400,400); //define o tamanho da janela
	glutInitWindowPosition(50, 50); // posiciona a janela, cuja origem é no canto superior esquerdo
	glutCreateWindow("Primeiro Programa"); //cria uma janela com o título especificado
	glutDisplayFunc(Desenha); //registra a função callback de redesenhenho
	Inicializa(); //inicialização própria desse programa
	glutMainLoop(); // entra no laço de processamento de eventos
	return 0;
}
