#include <stdlib.h>
#include <GL/glut.h>

//USAR PUSHMATRIX
//TRANSLACAO

void Desenha(void)
{
	GLint width;

	// Limpa a janela de visualiza��o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica a cor preta - Voc� pode trocar de cor, use: RGB
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(2);
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_QUADS);
		glVertex2f(-55.0f,55.0f);
		glVertex2f(55.0f,  55.0f);
		glVertex2f( 55.0f,  15.0f);
		glVertex2f( -55.0f,15.0f);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
		glVertex2f(55.0f,-55.0f);
		glVertex2f(-55.0f,  -55.0f);
		glVertex2f( -55.0f,  15.0f);
		glVertex2f( 55.0f,15.0f);
	glEnd();

	glColor3f(0.8f, 0.9f, 1.0f);

		//MORRO DIREITO
    glBegin(GL_LINES);
		glVertex2f(10.0,15.1);
        glVertex2f(30.0,15.1);
        glVertex2f(11.0,15.4);
        glVertex2f(29.0,15.4);
        glVertex2f(12.0,15.7);
        glVertex2f(28.0,15.7);
        glVertex2f(17.0,16.0);
        glVertex2f(27.0,16.0);
        glVertex2f(19.0,16.3);
        glVertex2f(23.0,16.3);
	glEnd();

	//MORRO ESQUERDO
		glBegin(GL_LINES);
			 	glVertex2f(-40.0,15.1);
        glVertex2f(-15.0,15.1);
				glVertex2f(-39.0,15.4);
				glVertex2f(-16.0,15.4);
				glVertex2f(-38.0,15.7);
				glVertex2f(-17.0,15.7);
				glVertex2f(-22.0,16.0);
				glVertex2f(-18.0,16.0);
				glVertex2f(-37.0,16.0);
				glVertex2f(-25.0,16.0);
				glVertex2f(-36.0,16.3);
				glVertex2f(-26.0,16.3);
				glVertex2f(-35.0,16.6);
				glVertex2f(-27.0,16.6);
				glVertex2f(-34.0,16.9);
				glVertex2f(-28.0,16.9);
				glVertex2f(-33.0,17.2);
				glVertex2f(-29.0,17.2);
				glVertex2f(-32.0,17.2);
				glVertex2f(-30.0,17.2);
		glEnd();

		glLineWidth(3);
		//PISTA
		glBegin(GL_LINES);
			glVertex2f(30.0,-25.0);
			glVertex2f(0.0,15.0);
			glVertex2f(-30.0,-25.0);
			glVertex2f(0.0,15.0);
		glEnd();

		//Linha do meio da PISTA
		//glVertex2f(largura, altura);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex2f(0.0, 10.0);
			glVertex2f(0.0, 15.0);
			glVertex2f(0.0, 5.0);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, -5.0);
			glVertex2f(0.0, -10.0);
			glVertex2f(0.0, -15.0);
			glVertex2f(0.0, -20.0);
			glVertex2f(0.0, -25.0);
			glVertex2f(0.0, -27.0);

		glEnd();
		//DESENHO O QUADRADO DO CARRO
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex2f(-8.0, -28.0);
			glVertex2f(-8.0, -20.0);
			glVertex2f(-13.0, -20.0);
			glVertex2f(-13.0, -28.0);
		glEnd();

		//DESENHA PENEUS DO CARRO
		glColor3f(1.0f, 1.0f, 1.0f);
		glPointSize(6);

		glBegin(GL_POINTS);
			glVertex2f(-7.5, -21.5);
			glVertex2f(-13.5,-21.5);
			glVertex2f(-7.5, -26.0);
			glVertex2f(-13.5,-26.0);
		glEnd();




	// Executa os comandos OpenGL
	glFlush();
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior,
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (w <= h)
		gluOrtho2D (-40.0f, 40.0f, -40.0f*h/w, 40.0f*h/w);
	else
		gluOrtho2D (-40.0f*w/h, 40.0f*w/h, -40.0f, 40.0f);
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(600,450);

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Desenho de Linhas");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a fun��o respons�vel por fazer as inicializa��es
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}
