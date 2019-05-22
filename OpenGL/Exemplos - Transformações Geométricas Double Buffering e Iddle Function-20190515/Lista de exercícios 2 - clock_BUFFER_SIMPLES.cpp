
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
int seg = 0;
int min = 0;
int h = 0;

//função de desenho do círculo obtida em http://slabode.exofire.net/circle_draw.shtml
/*void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 
}*/
void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	float theta = 2 * 3.1415926 / float(num_segments); 
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	} 
	glEnd(); 
}

void Inicializa(void)
{
	glClearColor(1,1,1,0);
}

void DesenhaPonteiroSegundos(){
   glPushMatrix();
       glRotatef(-360*seg/60,0,0,1);
       glColor3f(1.0f, 0.0f, 0.0f);
       glBegin(GL_LINES);
          glVertex2f(0,0);
          glVertex2f(0,0.4f);
       glEnd();
   glPopMatrix();     
}

void desenhaPonteiroMinutos(){
   glPushMatrix();
       glRotatef(-360*min/60,0,0,1);
       glColor3f(0.0f, 0.0f, 1.0f);
       glLineWidth(3);
       glBegin(GL_LINES);
          glVertex2f(0,0);
          glVertex2f(0,0.3f);
       glEnd();
   glPopMatrix();  
}

void desenhaPonteiroHoras(){
   glPushMatrix();
       glRotatef(-360*h/12,0,0,1);
       glColor3f(0.0f, 1.0f, 0.0f);
       glLineWidth(3);
       glBegin(GL_LINES);
          glVertex2f(0,0);
          glVertex2f(0,0.2f);
       glEnd();
   glPopMatrix();
}

void desenhaHoras(){
   int i;
   for(i=0; i<60; i++){
      glPushMatrix();
          if(i%5==0){
              glLineWidth(5);
          }
          else{
              glLineWidth(2);
          }
          glRotatef(-360*i/60,0,0,1);
          glBegin(GL_LINES);
              glVertex2f(0,0.45);
              glVertex2f(0,0.48);
          glEnd();
      glPopMatrix();         
   }
}

void desenhaCirculosRelogio(){
   glLineWidth(3);
   glColor3f(0.0f, 0.0f, 0.0f);
   glutSolidSphere(0.03,20,10);
   DrawCircle(0,0,0.5,30);
}
void Desenha(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   desenhaCirculosRelogio();
   desenhaHoras();
   //ponteiro do segundos
   DesenhaPonteiroSegundos();
   //ponteiro do minutos
   desenhaPonteiroMinutos();
   //ponteiro das horas
   desenhaPonteiroHoras();
   glFlush();
}

void Timer(int value) {
   seg++;
   if(seg==60){
        seg=0;
        min++;
   }
   if(min==60){
        min=0;
        h++;
   }
   if(h == 12){
        h=0;
   }
   glutPostRedisplay(); //manda o método Desenha ser executado novamente*/
   glutTimerFunc(1, Timer, 0); // define que a função Timer deverá ser executada novamente após 1 segundo
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //buffer simples
	glutInitWindowSize(400,400); //define o tamanho da janela
	glutInitWindowPosition(50, 50); // posiciona a janela, cuja origem é no canto superior esquerdo
	glutCreateWindow("Primeiro Programa"); //cria uma janela com o título especificado
	glutDisplayFunc(Desenha); //registra a função callback de redesenhenho
	glutTimerFunc(1000, Timer, 0); //define a função de tempo, que começa a executar 1000 milisegundos depois da inicialização
	Inicializa(); //inicialização própria desse programa
	glutMainLoop(); // entra no laço de processamento de eventos
	return 0;
}
