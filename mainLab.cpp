//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "Camera.h"
#include "figuras.h"
#include "FigPropias.h"

//	Prototipos de funciones
void fachada();
void silla();
void arbol(const GLuint &text);
void sillon_uno();
void mesa_comedor();
void sillon_dos();
void lampara();
void paloma();
void tele();
void mesa_sala();


/*int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;*/

static GLuint ciudad_display_list;	//Display List for the Monito


									//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotRodDer = 0.0, rotBrazoIzq = 0.0, rotBrazoDer = 0.0;
float movBrazoIzq = 0.0;
float giroMonito = 0;
float movBrazoDer = 0.0;
float movCuerpo = 0.0;

#define MAX_FRAMES 200		//cuantos cuadros clave se van a utilizar (keyframes)
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{

	float mov_pelotaX;
	float mov_pelotaY;
	float mov_pelotaZ;
	float rot_pelotaX;
	float rot_pelotaY;
	float rot_pelotaZ;

	float IncX;
	float IncZ;
	float IncY;
	float IncRotX;
	float IncRotY;
	float IncRotZ;

	/*
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ

	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ

	float rotRodIzq;
	float rotRodDer;

	float rotRodIzqInc;
	float rotRodDerInc;

	float giroMonito;
	float giroMonitoInc;
	
	float movBrazoDer;
	float movBrazoDerInc;
	
	float movBrazoIzq;
	float movBrazoIzqInc;
	
	float rotBrazoIzq;
	float rotBrazoDer;
	float rotBrazoDerInc;
	float rotBrazoIzqInc;
	
	float rotInc;

	float movCuerpo;
	float movCuerpoInc;
	*/

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time2, timebase = 0;
char s[30];


// Variables para keyframe
float mov_pelotaX = 0.0;
float mov_pelotaY = 0.0;
float mov_pelotaZ = 0.0;
float rot_pelotaX = 0.0;
float rot_pelotaY = 0.0;
float rot_pelotaZ = 0.0;

float IncX = 0.0;
float IncZ = 0.0;
float IncY = 0.0;
float IncRotX = 0.0;
float IncRotY = 0.0;
float IncRotZ = 0.0;


//	Objeto para dibujar figuras
Figures figures;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//Variables de apoyo para colocar figuras
float xx=0.0, yy = 0.0, zz = 0.0;
float tamx = 1.0, tamy = 1.0, tamz = 1.0;

//	Variables para animar a la paloma
GLfloat pos_paloma_x = -7.f;
GLfloat pos_paloma_y = 7.f;
GLfloat pos_paloma_z = -7.f;
GLfloat rot_paloma = 0.f;
GLfloat ant_pos_paloma_z = 0.f;

//	Variables para animar la pelota
GLfloat pos_ball_x = 0.f;
GLfloat pos_ball_y = 23.0f;
GLfloat pos_ball_z = -5.6f;
GLfloat rot_ball_x = 0.f;
GLfloat par_pos_ball_x_ini = 0.f;
GLfloat par_pos_ball_y_ini = 23.0f;
GLfloat par_pos_ball_z_ini = -5.6f;
GLfloat v_ini_ball = 10;
GLfloat angle_ball = 3.141592 / 10;
GLfloat ball_t = 0;
const GLfloat gravity = 9.81;
int estadoPelota = 1;

// Variable inicial de la paloma
int estadopaloma = 1;

//	Variables para animar la textura
GLdouble estadoTelevision = 1.0;

// Objeto de figuras.cpp
CFiguras fig7;

//	Texturas
CTexture window_texture;
CTexture cuarzo;
CTexture metal_cromo;
CTexture pared_interior;
CTexture puertaFrente;
CTexture garage;

CTexture pisoRojo;
CTexture pisoPatioT;

CTexture cielo_lateral;
CTexture cielo_frontal;
CTexture cielo_superior;
CTexture pasto;
CTexture lamp;
CTexture tocador;
CTexture t1;
CTexture t2;
CTexture t3;
CTexture t4;
CTexture t5;
CTexture t6;
CTexture t7;
CTexture t8;
CTexture t9;
CTexture t10;
CTexture t11;
CTexture t12;
CTexture t13;
CTexture t14;
CTexture sillon;
CTexture vitrina;
CTexture chimenea;
CTexture madera;
CTexture muebleBanio;
CTexture muebleBanio2;
CTexture negroMate;
CTexture almohada;
CTexture cabecera;
CTexture cobija;
CTexture tree_tex;
CTexture ball;
CTexture estante;
CTexture fondo_lad;
CTexture centro_mesa;
CTexture plata;
CTexture ball_basq;

//CTexture tree;

const double PI = 3.1415926535897;



void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].mov_pelotaX = mov_pelotaX;
	KeyFrame[FrameIndex].mov_pelotaY = mov_pelotaY;
	KeyFrame[FrameIndex].mov_pelotaZ = mov_pelotaZ;
	KeyFrame[FrameIndex].rot_pelotaX = rot_pelotaX;
	KeyFrame[FrameIndex].rot_pelotaY = rot_pelotaY;
	KeyFrame[FrameIndex].rot_pelotaZ = rot_pelotaZ;
			
	FrameIndex++;
}

void resetElements( void )
{
	mov_pelotaX = KeyFrame[0].mov_pelotaX;
	mov_pelotaY = KeyFrame[0].mov_pelotaY;
	mov_pelotaZ = KeyFrame[0].mov_pelotaZ;
	rot_pelotaX = KeyFrame[0].rot_pelotaX;
	rot_pelotaY = KeyFrame[0].rot_pelotaY;
	rot_pelotaZ = KeyFrame[0].rot_pelotaZ;

}

void interpolation ( void )
{
	KeyFrame[playIndex].IncX = (KeyFrame[playIndex + 1].mov_pelotaX - KeyFrame[playIndex].mov_pelotaX) / i_max_steps;
	KeyFrame[playIndex].IncY = (KeyFrame[playIndex + 1].mov_pelotaY - KeyFrame[playIndex].mov_pelotaY) / i_max_steps;
	KeyFrame[playIndex].IncZ = (KeyFrame[playIndex + 1].mov_pelotaZ - KeyFrame[playIndex].mov_pelotaZ) / i_max_steps;	
	KeyFrame[playIndex].IncRotX = (KeyFrame[playIndex + 1].rot_pelotaX - KeyFrame[playIndex].rot_pelotaX) / i_max_steps;
	KeyFrame[playIndex].IncRotY = (KeyFrame[playIndex + 1].rot_pelotaY - KeyFrame[playIndex].rot_pelotaY) / i_max_steps;
	KeyFrame[playIndex].IncRotZ = (KeyFrame[playIndex + 1].rot_pelotaZ - KeyFrame[playIndex].rot_pelotaZ) / i_max_steps;	

}



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.3f);


	//	Texturas
	cuarzo.LoadTGA("textures/paredExt.tga");
	cuarzo.BuildGLTexture();
	cuarzo.ReleaseImage();

	metal_cromo.LoadTGA("textures/metal_cromo.tga");
	metal_cromo.BuildGLTexture();
	metal_cromo.ReleaseImage();

	tocador.LoadTGA("textures/tocador.tga");
	tocador.BuildGLTexture();
	tocador.ReleaseImage();

	pared_interior.LoadTGA("textures/pared.tga");
	pared_interior.BuildGLTexture();
	pared_interior.ReleaseImage();

	puertaFrente.LoadTGA("textures/puerta.tga");
	puertaFrente.BuildGLTexture();
	puertaFrente.ReleaseImage();

	garage.LoadTGA("textures/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

	estante.LoadTGA("textures/estante.tga");
	estante.BuildGLTexture();
	estante.ReleaseImage();

	fondo_lad.LoadTGA("textures/ladrillo_fachada.tga");
	fondo_lad.BuildGLTexture();
	fondo_lad.ReleaseImage();

	centro_mesa.LoadTGA("textures/centro_mesa.tga");
	centro_mesa.BuildGLTexture();
	centro_mesa.ReleaseImage();

	t1.LoadTGA("textures/t1.tga");
	t1.BuildGLTexture();
	t1.ReleaseImage();

	t2.LoadTGA("textures/t2.tga");
	t2.BuildGLTexture();
	t2.ReleaseImage();

	t3.LoadTGA("textures/t3.tga");
	t3.BuildGLTexture();
	t3.ReleaseImage();

	t4.LoadTGA("textures/t4.tga");
	t4.BuildGLTexture();
	t4.ReleaseImage();

	t5.LoadTGA("textures/t5.tga");
	t5.BuildGLTexture();
	t5.ReleaseImage();

	t6.LoadTGA("textures/t6.tga");
	t6.BuildGLTexture();
	t6.ReleaseImage();

	t7.LoadTGA("textures/t7.tga");
	t7.BuildGLTexture();
	t7.ReleaseImage();

	t8.LoadTGA("textures/t8.tga");
	t8.BuildGLTexture();
	t8.ReleaseImage();

	t9.LoadTGA("textures/t9.tga");
	t9.BuildGLTexture();
	t9.ReleaseImage();

	t10.LoadTGA("textures/t10.tga");
	t10.BuildGLTexture();
	t10.ReleaseImage();

	t11.LoadTGA("textures/t11.tga");
	t11.BuildGLTexture();
	t11.ReleaseImage();

	t12.LoadTGA("textures/t12.tga");
	t12.BuildGLTexture();
	t12.ReleaseImage();

	t13.LoadTGA("textures/t13.tga");
	t13.BuildGLTexture();
	t13.ReleaseImage();

	t14.LoadTGA("textures/t14.tga");
	t14.BuildGLTexture();
	t14.ReleaseImage();

	pisoRojo.LoadTGA("textures/piso_entrada.tga");
	pisoRojo.BuildGLTexture();
	pisoRojo.ReleaseImage();

	chimenea.LoadTGA("textures/chimenea.tga");
	chimenea.BuildGLTexture();
	chimenea.ReleaseImage();

	lamp.LoadTGA("textures/lampara.tga");
	lamp.BuildGLTexture();
	lamp.ReleaseImage();

	pisoPatioT.LoadTGA("textures/ladrillo.tga");
	pisoPatioT.BuildGLTexture();
	pisoPatioT.ReleaseImage();

	plata.LoadTGA("textures/plata.tga");
	plata.BuildGLTexture();
	plata.ReleaseImage();

	sillon.LoadTGA("textures/sillon.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	cielo_frontal.LoadTGA("textures/cielo_2.tga");
	cielo_frontal.BuildGLTexture();
	cielo_frontal.ReleaseImage();	

	cielo_lateral.LoadTGA("textures/cielo_3.tga");
	cielo_lateral.BuildGLTexture();
	cielo_lateral.ReleaseImage();

	cielo_superior.LoadTGA("textures/cielo.tga");
	cielo_superior.BuildGLTexture();
	cielo_superior.ReleaseImage();

	pasto.LoadTGA("textures/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	madera.LoadTGA("textures/madera_clara.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	negroMate.LoadTGA("textures/negroMate.tga");
	negroMate.BuildGLTexture();
	negroMate.ReleaseImage();

	almohada.LoadTGA("textures/almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	cabecera.LoadTGA("textures/cabecera.tga");
	cabecera.BuildGLTexture();
	cabecera.ReleaseImage();

	cobija.LoadTGA("textures/cobija.tga");
	cobija.BuildGLTexture();
	cobija.ReleaseImage();

	tree_tex.LoadTGA("textures/arbol.tga");
	tree_tex.BuildGLTexture();
	tree_tex.ReleaseImage();

	window_texture.LoadTGA("textures/window.tga");
	window_texture.BuildGLTexture();
	window_texture.ReleaseImage();

	ball.LoadTGA("textures/ball.tga");
	ball.BuildGLTexture();
	ball.ReleaseImage();

	ball_basq.LoadTGA("textures/balon_basq.tga");
	ball_basq.BuildGLTexture();
	ball_basq.ReleaseImage();

	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].mov_pelotaX = 0;
		KeyFrame[i].mov_pelotaY = 0;
		KeyFrame[i].mov_pelotaZ = 0;
		KeyFrame[i].rot_pelotaX = 0;
		KeyFrame[i].rot_pelotaY = 0;
		KeyFrame[i].rot_pelotaZ = 0;
		KeyFrame[i].IncX = 0;
		KeyFrame[i].IncY = 0;
		KeyFrame[i].IncZ = 0;
		KeyFrame[i].IncRotX = 0;
		KeyFrame[i].IncRotY = 0;
		KeyFrame[i].IncRotZ = 0;
	}

	//	posicion     (0, 2.5, 3)
	//	hacia donde  (0, 2.5, 0)
	//	inclinaci�n  (0, 1, 0)
	objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 37, 0, 1, 0);

	//	Reproducir m�sica si se est� en Windows
	#if _WIN32
	PlaySound(TEXT("halo_channel.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

}

void puertas(void){

	//Puerta Frontal
	glPushMatrix();
		glTranslatef(4.8, 5.0, 18.005);
		glPushMatrix();  //arco madera izq
			glTranslatef(-3, 2, 0);
			glScalef(2, 14, 1);
			glBindTexture(GL_TEXTURE_2D, madera.GLindex);
			
			glBegin(GL_QUADS);
				glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
			glEnd();
		glPopMatrix();
		glPushMatrix(); //arco madera der
			glTranslatef(6, 2, 0);
			glScalef(2, 14, 1);
			glBindTexture(GL_TEXTURE_2D, madera.GLindex);
			glBegin(GL_QUADS);
				glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
			glEnd();
		glPopMatrix();
		glPushMatrix(); //arco madera sup
			glTranslatef(1.5, 7.5, 0);
			glScalef(7, 3, 1);
			glBindTexture(GL_TEXTURE_2D, madera.GLindex);
			glBegin(GL_QUADS);
				glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
			glEnd();
		glPopMatrix();

		glPushMatrix(); //fondo ladrillo
			glTranslatef(1.5, 2, 0);
			glScalef(11, 14, 0);
			glBindTexture(GL_TEXTURE_2D, fondo_lad.GLindex);
			glBegin(GL_QUADS);
				glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, -4.5, 1);
			glScalef(3, 1 , 2);
			figures.l_prisma(pared_interior.GLindex);
		glPopMatrix();

		glScalef(3, 8, 1);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glBindTexture(GL_TEXTURE_2D, puertaFrente.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Puerta garage
	glPushMatrix();
		glTranslatef(-6, 4.5, 18.005);
		glScalef(12, 9, 1);
		glBindTexture(GL_TEXTURE_2D, garage.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();

}

void monito()
{
	glPushMatrix();

		//glTranslatef(xx,yy,zz);
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho

	glTranslatef(0.0, movCuerpo, 0.0);
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, plata.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	glRotatef(rotBrazoDer, 0.0, 1.0, 0.0);
	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-25, 0, 0, 1);
	glRotatef(-25, 1, 0, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	glRotatef(rotBrazoIzq, 0, 1, 0);
	glRotatef(movBrazoIzq, 0.0, 0.0, 1.0);

	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, plata.GLindex);

	//glTranslatef(0.0, movCuerpo+1.5, 0.0);


	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodDer, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glRotatef(15 - rotRodDer, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, plata.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glRotatef(15 - rotRodIzq, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, plata.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();

	glPopMatrix();
}



void cama(void){


	glPushMatrix();

	glTranslatef(10, 0, 15);
	glRotatef(-90, 0, 1, 0);

		glPushMatrix(); //pata 1 derecha
		glTranslatef(1.3+0.4,-0.75+0.1,0.40+0.8);
		
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 2 
		glTranslatef(1.3+0.4,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 3 izquierda
		glTranslatef(-1.3-0.6,-0.75+0.1,0.40+0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 4
		glTranslatef(-1.3-0.6,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //almohadas
			glTranslatef(1.2, 1, -0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); 
			
		glPushMatrix();
			glTranslatef(1.2, 1, 0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); //almohadas


		glPushMatrix();
		glTranslatef(0,0.5,0);

		glPushMatrix(); //cobija
			//glTranslatef(0,0.3,0);
			glTranslatef(-1, 0.21, 0);
			glScalef(1.4, 0.1, 3);
			glScalef(3-1.2,1+1.2,1+0.02);
			figures.u_prisma(cobija.GLindex);
		glPopMatrix(); //cobija

		glPushMatrix(); //Cabecera
			glTranslatef(2.4, 0, 0);
			glScalef(0.6, 3.2, 3.6);
			figures.u_prisma(cabecera.GLindex);
		glPopMatrix(); //Cabecera

		glScalef(1.4, 0.6, 3);
		glScalef(3,1,1);
		glColor3f(1,1,1);
		figures.u_prisma(0);
		glPopMatrix();
		//glColor3f(1,1,1);

	glPopMatrix();

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,29.98,0);
				glScalef(150, 60, 200);
				figures.skybox(0, 0, cielo_superior.GLindex, pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//	Ejes de referencia
			glPushMatrix();
				glBegin(GL_LINES);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(100.0, 0.0, 0.0);

				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 100.0, 0.0);

				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 100.0);
				glEnd();
			glPopMatrix();

			glPushMatrix(); //fachada
				fachada();
			glPopMatrix();
			
			glPushMatrix(); //puerta entrada y garage
				puertas();
			glPopMatrix();

			glPushMatrix(); //pelota
			glTranslatef(pos_ball_x, pos_ball_y, pos_ball_z);
			glRotatef(rot_ball_x, 1, 0, 0);
			figures.u_esfera(1, 20, 20, ball.GLindex);
			glPopMatrix();

			glPushMatrix(); //ventana 
				glTranslatef(7.9, 6, 18);
				glScalef(2.5, 8.4, 1);
				figures.ventana(window_texture.GLindex, true, false, false, 
				false, false, false);
			glPopMatrix();

			glPushMatrix(); //chimenea
				glDisable(GL_LIGHTING);
				glTranslatef(-11.3, 13, -16.8);
				
				glPushMatrix(); //estante
					glTranslatef(7, -9.5, -1);
					glPushMatrix(); //sillon 1
						glTranslatef(10.5,-2, 1);
						glPushMatrix(); //sillon 2
							glTranslatef(5.5, 0, 5.5);
							glRotatef(270, 0, 1, 0);
							glScalef(3,2,2);
							sillon_uno();
						glPopMatrix();
						glPushMatrix(); // mesa centro de la sala
							glTranslatef(0, .5, 8);
							glPushMatrix(); //sill�n individual
								glTranslatef(-6, -.5, -2);
								glRotatef(90, 0, 1, 0);
								glScalef(2,2,2);
								sillon_dos();
							glPopMatrix();
							glScalef(2,0.5,0.75);
							mesa_sala();
						glPopMatrix();
						glScalef(3,2,2);
						sillon_uno();
					glPopMatrix();
					glScalef(10, 8, 0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					figures.u_prisma(estante.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();

				glScalef(2, 26, 2);
				figures.u_prisma(pisoPatioT.GLindex);
				glColor3f(1,1,1);
				glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix(); //comedor 
				//glTranslatef(0,0,34);
				glPushMatrix(); //silla 1
					glTranslatef(-7.25, 1 ,-1.5);
					//glRotatef(-90,0,1,0);
					glScalef(2,2,2);
					silla();
				glPopMatrix();

				glPushMatrix(); //silla 2
					glTranslatef(-7.25, 1, 4.5);
					glRotatef(180,0,1,0);
					glScalef(2,2,2);
					silla();
				glPopMatrix();

				glPushMatrix(); //silla 3
					glTranslatef(-10, 1, 1.5);
					glRotatef(90,0,1,0);
					glScalef(2,2,2);
					silla();
				glPopMatrix();

				glPushMatrix(); //silla 4
					glTranslatef(-4.5, 1, 1.5);
					glRotatef(-90,0,1,0);
					glScalef(2,2,2);
					silla();
				glPopMatrix();

				glPushMatrix(); //mesa central del comedor
					glTranslatef(-7.2, -1, 1.5);
					glRotatef(45,0,1,0);
					glScalef(1.5,1,1.5);
					mesa_comedor();
				glPopMatrix();
				glColor3f(1,1,1);
			glPopMatrix();

			glPushMatrix(); //cama 
				cama();
			glPopMatrix();

			glPushMatrix(); //televisi�n
				glTranslatef(10, 4, 10);
				glRotatef(-90,1,0,0);
				glPushMatrix(); //mueble que sostiene la television
					glColor3f(0.3529,0.1764,0.0862);
					glRotatef(90,1,0,0);
					glTranslatef(0, -2.8, 0);
					glScalef(1.6, 3, 0.8);
					figures.u_prisma_mueble(madera.GLindex,tocador.GLindex);
					glColor3f(1,1,1);
				glPopMatrix();
				if (estadoTelevision >= 1 && estadoTelevision <= 10){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t1.GLindex);
				glutPostRedisplay();
				}
				else if (estadoTelevision >= 11 && estadoTelevision <= 20){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t2.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 21 && estadoTelevision <= 30){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t3.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 31 && estadoTelevision <= 40){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t4.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 41 && estadoTelevision <= 50){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t5.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 51 && estadoTelevision <= 60){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t6.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 61 && estadoTelevision <= 70){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t7.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 71 && estadoTelevision <= 80){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t8.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 81 && estadoTelevision <= 90){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t9.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 91 && estadoTelevision <= 100){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t10.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 101 && estadoTelevision <= 110){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t11.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 111 && estadoTelevision <= 120){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t12.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 121 && estadoTelevision <= 130){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t13.GLindex);
					glutPostRedisplay();
				}	
				else if (estadoTelevision >= 131 && estadoTelevision <= 140){
					figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t14.GLindex);
					glutPostRedisplay();
				}
			glPopMatrix();
			

			glPushMatrix();
				paloma();
			glPopMatrix();

			glPushMatrix();
				
				glTranslatef(30 + mov_pelotaX, 2 + mov_pelotaY, 10 + mov_pelotaZ);
				glRotatef(rot_pelotaX, 1, 0, 0);
				glRotatef(rot_pelotaY, 0, 1, 0);
				glRotatef(rot_pelotaZ, 0, 0, 1);
				//glEnable(GL_LIGHTING);
				figures.u_esfera(2, 20, 20, ball_basq.GLindex);
				//glDisable(GL_LIGHTING);
			glPopMatrix();		

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{

	// Animaci�n televisi�n
	++estadoTelevision;
	if(estadoTelevision == 140) estadoTelevision = 1;

	//Animaci�n paloma
	switch (estadopaloma)
	{
		case 1:
			pos_paloma_z += 0.1;
			if(pos_paloma_z >= 7)
			{
				estadopaloma = 2;
				ant_pos_paloma_z = pos_paloma_z;
			}
			break;
		case 2:
			pos_paloma_x += 0.1;
			rot_paloma = 90;
			if(pos_paloma_x >= 7)
			{
				estadopaloma = 3;
				ant_pos_paloma_z = pos_paloma_z;
			}
			break;
		case 3:
			pos_paloma_z -= 0.1;
			rot_paloma = 180;
			if(pos_paloma_z <= -7)
			{
				estadopaloma = 4;
			}
			break;
		case 4:
			pos_paloma_x -= 0.1;
			rot_paloma += 3;
			if(pos_paloma_x <= -7)
			{
				rot_paloma = 0;
				estadopaloma = 1;
			}
			break;
	}


	//Movimiento de la pelota
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				interpolation();
			}
		}
		else
		{	//Draw information


			mov_pelotaX += KeyFrame[playIndex].IncX;
			mov_pelotaY += KeyFrame[playIndex].IncY;
			mov_pelotaZ += KeyFrame[playIndex].IncZ;
			rot_pelotaX += KeyFrame[playIndex].IncRotX;
			rot_pelotaY += KeyFrame[playIndex].IncRotY;
			rot_pelotaZ += KeyFrame[playIndex].IncRotZ;

			/*
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;
			
			movCuerpo += KeyFrame[playIndex].movCuerpoInc;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			rotRodDer += KeyFrame[playIndex].rotRodDerInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			movBrazoIzq += KeyFrame[playIndex].movBrazoIzqInc;
			rotBrazoDer += KeyFrame[playIndex].rotBrazoDerInc;
			rotBrazoIzq += KeyFrame[playIndex].rotBrazoIzqInc;*/
			

			i_curr_steps++;
		}

	}

	/*frame++;
	time2 = glutGet(GLUT_ELAPSED_TIME);
	if (time2 - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time2 - timebase));
		timebase = time2;
		frame = 0;
	}*/

	//	Movimiento de la pelota
	switch(estadoPelota){
		case 1:
			pos_ball_z += 0.2;
			rot_ball_x -= 1;
			if (pos_ball_z >= 20.5) {
				estadoPelota = 2;
			}
			break;
		case 2:
			pos_ball_z = 21.0 + (v_ini_ball * ball_t);
			pos_ball_y = par_pos_ball_y_ini + (v_ini_ball * sin(angle_ball) * ball_t 
				- 0.5 * gravity * ball_t * ball_t);
			ball_t += 0.01;

			if (pos_ball_y <= 1)
			{
				estadoPelota = 3;
				xx = pos_ball_z;
				printf("%f\n", xx);
			}
			break;
		case 3:
			pos_ball_z += 0.2;
			if (pos_ball_z >= 48 )
			{
				estadoPelota = 4;
			}
			break;
	}
	


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case '<':
			pos_ball_x = par_pos_ball_x_ini;
			pos_ball_y = par_pos_ball_y_ini;
			pos_ball_z = par_pos_ball_z_ini;
			rot_ball_x = 0.f;
			ball_t = 0.f;
			estadoPelota = 1;
			break;

		//Movimientos de camara
		case 'w':   
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'q':
		case 'Q':
			objCamera.UpDown_Camera(CAMERASPEED+0.2);
			break;

		case 'z':
		case 'Z':
			objCamera.UpDown_Camera(-(CAMERASPEED+0.2));
			break;

		//Tecla para colocar la camara al frente de la casa
		case 'f':
		case 'F':
			objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 38, 0, 1, 0);
			break;

		//Tecla para colocar la camara en la cama
		case 'c':
		case 'C':
			objCamera.Position_Camera(10, 3, 16, 10, 3, 12, 0, 1, 0);
			break;

		//Tecla para colocar la camara en la esquina para ver el interior de la casa
		case 'p':
		case 'P':
			//objCamera.Position_Camera(22.13, 6.69f, -38.55, -48.94, 2.5f, -69.66, 0, 1, 0);
			objCamera.Position_Camera(-12.4, 3, 17.5, 12.4, 3, -10.5, 0, 1, 0);
			break;

		//Tecla para colocar la camara en una vista isometrica de la casa
		case 'i':
		case 'I':
			objCamera.Position_Camera(-23.94, 58.5f, 16.99, -5, 2.5f, -12.39, 0, 1, 0);
			break;

		case 'u':
			mov_pelotaX += 0.1;
			break;
		case 'U':
			mov_pelotaX -= 0.1;
			//zz -= 0.2;
			break;

		case 'j':
			mov_pelotaY += 0.1;
			break;
		case 'J':
			mov_pelotaY -= 0.1;
			//zz += 0.2;
			break;

		case 'h':
			mov_pelotaZ += 0.1;
			break;
		case 'H':
			mov_pelotaZ -= 0.1;
			//xx -= 0.2;
			break;

		case 'k':
			rot_pelotaX += 10;
			break;
		case 'K':
			rot_pelotaX -= 10;
			//xx += 0.2;
			break;

		case 'y':
			rot_pelotaY += 10;
			break;
		case 'Y':
			rot_pelotaY -= 10;
			//yy += 0.2;
			break;

		case 'n':
			rot_pelotaZ += 10;
			break;
		case 'N':
			rot_pelotaZ -= 10;
			//yy -= 0.2;
			break;

		case '1':
			tamx += 0.2;
			break;
		case '2':
			tamx -= 0.2;
			break;

		case '3':
			tamy += 0.2;
			break;

		case '4':
			tamy -= 0.2;
			break;

		case '5':
			tamz += 0.2;
			break;

		case '6':
			tamz -= 0.2;
			break;

		case 'l':
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'o':		//
		case 'O':
			if(FrameIndex<MAX_FRAMES)
				{
					saveFrame();
				}
			break;
/*
	case 'e':
	case 'E':
		if (play == false && (FrameIndex>1))
		{

			posX = KeyFrame[0].posX;
			posY = KeyFrame[0].posY;
			posZ = KeyFrame[0].posZ;
			rotRodIzq = KeyFrame[0].rotRodIzq;
			rotRodDer = KeyFrame[0].rotRodDer;
			giroMonito = KeyFrame[0].giroMonito;
			movBrazoDer = KeyFrame[0].movBrazoDer;
			movBrazoIzq = KeyFrame[0].movBrazoIzq;
			rotBrazoDer = KeyFrame[0].rotBrazoDer;
			rotBrazoIzq = KeyFrame[0].rotBrazoIzq;
			movCuerpo = KeyFrame[0].movCuerpo;

			//First Interpolation
			KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotRodDerInc = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movBrazoIzqInc = (KeyFrame[playIndex + 1].movBrazoIzq - KeyFrame[playIndex].movBrazoIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotBrazoDerInc = (KeyFrame[playIndex + 1].rotBrazoDer - KeyFrame[playIndex].rotBrazoDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotBrazoIzqInc = (KeyFrame[playIndex + 1].rotBrazoIzq - KeyFrame[playIndex].rotBrazoIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movCuerpoInc = (KeyFrame[playIndex + 1].movCuerpo - KeyFrame[playIndex].movCuerpo) / i_max_steps;

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;*/

		case 'x':
		rotRodIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'X':
		rotRodIzq--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'v':
		rotRodDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'V':
		rotRodDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'b':
		rotBrazoIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'B':
		rotBrazoIzq--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'g':
		rotBrazoDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'G':
		rotBrazoDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'm':
		movBrazoIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'M':
		movBrazoIzq--;
		//printf("%f \n", rotRodIzq);
		break;

	case '7':
		movBrazoDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case '8':
		movBrazoDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case '9':
		movCuerpo += 0.2;
		//printf("%f \n", rotRodIzq);
		break;

	case '0':
		movCuerpo -= 0.2;
		//printf("%f \n", rotRodIzq);
		break;

	case 't':
		giroMonito++;
		//printf("%f \n", giroMonito);
		break;

	case 'T':
		giroMonito--;
		//printf("%f \n", giroMonito);
		break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:   // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}




void silla()
{

	//RESPALDO
	glPushMatrix();
	glTranslatef(0,0.50,-0.22);
	glPushMatrix();
	glTranslatef(0,0.375,0.031);
	glRotatef(-90,1,0,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_medio_cilindro(0.25,0.0625,30,madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.75,0.0625);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glColor3f(1,1,0);
	//PATA 1
	glPushMatrix();
	glTranslatef(0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA  2
	glPushMatrix();
	glTranslatef(0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 3
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 4
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.25,0.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glColor3f(1,1,1);
}

void arbol(const GLuint &text)
{

	glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glBindTexture(GL_TEXTURE_2D, text);
		for(int i = 0; i < 12; i++)
		{
			glPushMatrix();
				glRotatef(30 / 2.0 * i, 0, 1, 0);
				glNormal3f(0, 0, 1);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0, 10.0, 0.0);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 10.0, 0.0);
				glEnd();
			glPopMatrix();

		}
		//glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}

void sillon_uno()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //DESCANSO BRAZO IZQ
	glTranslatef(-1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //RESPALDO
	glTranslatef(0,1.10,-0.375);

	glPushMatrix();
	glTranslatef(1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(-0.3,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(0.3,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(1.8,1.20,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(3,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void sillon_dos()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	

	glPushMatrix();
	glTranslatef(0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();


	glPushMatrix(); //RESPALDO
	glTranslatef(0,0.90,-0.375);

	glPushMatrix();
	glTranslatef(0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(-0.15,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(0.15,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(0.9,1.0,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void tele()
{
	glPushMatrix();
	glTranslatef(0,2.5,-0.35);
			glColor3f(1,1,1);
			glRotatef(-90,1,0,0);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t14.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t13.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t12.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t11.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t10.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t9.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t8.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t7.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t6.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t5.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t4.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t3.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t2.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t1.GLindex);
			glPopMatrix();
}
void lampara()
{
	glPushMatrix();
	glTranslatef(0,1,0.0);

	glPushMatrix();
	glTranslatef(0,0.0625,0);
	glPushMatrix();
	glTranslatef(0,2,0);
	//glColor3f(1,1,1);
	figures.u_cono(0.3,1,10,lamp.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	figures.u_cilindro(0.01,2,5,0);
	glPopMatrix();

	glColor3f(0,0,0);
	figures.u_cilindro(0.25,0.0625,30,0);
	glPopMatrix();
	glColor3f(1,1,1);
}

void mesa_comedor()
{
	glPushMatrix();
	glTranslatef(0,1.05,0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0,1.5,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(1.5,0.1,20,madera.GLindex);
	glPopMatrix();
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(0.125,1.5,15,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,0.05,1.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
}

void paloma()
{
	glPushMatrix();

	glTranslatef(pos_paloma_x, pos_paloma_y, pos_paloma_z);
	glRotatef(rot_paloma, 0, 1, 0);

	glPushMatrix();//Ala derecha
	glTranslatef(0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();	

	glPushMatrix();//Ala derecha
	glTranslatef(-0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();

	//PATAS
	glPushMatrix();//IZQUIERDA
	glTranslatef(-0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//DERECHA
	glTranslatef(0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	//CABEZA
	glPushMatrix();
	glTranslatef(0,0.65,0.25);
	glPushMatrix();//PUSH DE LA BOCA
	glTranslatef(0,0,0.07);

	glPushMatrix();//PUSH DE OJO IZQ
	glTranslatef(-0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//PUSH DE OJO DER
	glTranslatef(0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.25,0.25,0.05);
	glColor3f(0.9568,0.8156,0.2470);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.25,0.75,0.1);
	glColor3f(0.6666,0.7176,0.7215);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.5,1,0.5);
	glColor3f(0.4745,0.4901,0.4980);
	figures.u_prisma(0);
	glPopMatrix();
}




void fachada()
{
	glPushMatrix();

	glTranslatef(0, 11, 0);
	
	//	Figura A (central)
	
	glPushMatrix();
		glScalef(26, 22, 36);
		figures.u_prisma_no_derecha(cuarzo.GLindex);	
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
		glScalef(25.995, 21.995, 35.995);
		figures.l_prisma_no_derecha(cuarzo.GLindex, metal_cromo.GLindex);	
	glPopMatrix();
	glDisable(GL_LIGHTING);
	

	glColor3f(1, 1, 1);

	glPopMatrix();
}

void mesa_sala()
{
	glPushMatrix(); // stack de primer prisma medio - frente
			glPushMatrix(); // stack de segundo prisma medio - medio
			glTranslatef(0.0, 0.0, -2.5);
				glPushMatrix(); // stack de tercer prisma medio - atr�s
				glTranslatef(0.0, 0.0, -2.5);
					glPushMatrix(); //stack de cuarto prisma derecha - atr�s
					glTranslatef(1.25, -1.5, 0.0);
						glPushMatrix(); //stack de quinto prisma derecha - medio
						glTranslatef(0.0, 1.5, 2.5);
							glPushMatrix(); //stack de sexto prisma derecha - frente
							glTranslatef(0.0, -1.5, 2.5);
								//glColor3f(1.0, 1.0, 1.0);
								glScalef(0.5, 4.0, 1.0);
								figures.prisma(madera.GLindex, madera.GLindex);
							glPopMatrix();
							//glColor3f(1.0, 1.0, 1.0);
							glScalef(0.5, 1.0, 4.0);
							figures.prisma(madera.GLindex, madera.GLindex);
						glPopMatrix();
						//glColor3f(1.0, 1.0, 1.0);
						glScalef(0.5, 4.0, 1.0);
						figures.prisma(madera.GLindex, madera.GLindex);
					glPopMatrix();
					glPushMatrix(); //stack de s�ptimo prisma izquierda - atr�s
					glTranslatef(-1.25, -1.5, 0.0);
						glPushMatrix(); //stack de octavo prisma izquierda - medio
						glTranslatef(0.0, 1.5, 2.5);
							glPushMatrix(); //stack de noveno prisma izquierda - medio
							glTranslatef(0.0, -1.5, 2.5);
								//glColor3f(1.0, 1.0, 1.0);
								glScalef(0.5, 4.0, 1.0);
								figures.prisma(madera.GLindex, madera.GLindex);
							glPopMatrix();
							//glColor3f(1.0, 1.0, 1.0);
							glScalef(0.5, 1.0, 4.0);
							figures.prisma(madera.GLindex,madera.GLindex);
						glPopMatrix();
						//glColor3f(1.0, 1.0, 1.0);
						glScalef(0.5, 4.0,1.0);
						figures.prisma(madera.GLindex, madera.GLindex);
					glPopMatrix();
					//glColor3f(1.0, 1.0, 1.0);
					glScalef(2.0, 1.0, 1.0);
					figures.prisma(madera.GLindex, madera.GLindex);
				glPopMatrix();
				//glColor3f(1.0, 1.0, 1.0);
				glScalef(2.0, 1.0, 4.0);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				figures.prisma(centro_mesa.GLindex, centro_mesa.GLindex);
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			//glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0,1.0,1.0);  
			figures.prisma(madera.GLindex, madera.GLindex);	
		glPopMatrix();
}