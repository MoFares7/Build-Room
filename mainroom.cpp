#include "mainroom.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <cmath>
#include "texture.h"		// Header File For Texture Loader (only bmp files supported)
#include "3DTexture.h"		// Header File For Model Texture Binding (only bmp files are supported)
#include "Model_3DS.h"		// Header File For Model Loader (only 3ds fies are supported)


int ra, la, ua, da, fa, ba, tab, caseb, caseinterface, casess, tab1 , plant , windows , glass;
GLfloat light_position[] = { 2.0, 0.0, 5.0, 1.0 };
GLfloat light_ambient_color[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_diffuse_color[] = { 1.0, 1.0, 1.0, 1.0 };


mainroom::mainroom()
{

	ra = LoadTexture("Resources/Textures/case.bmp");
	la = LoadTexture("Resources/Textures/case.bmp");
	fa = LoadTexture("Resources/Textures/case.bmp");
	ba = LoadTexture("Resources/Textures/case.bmp");
	ua = LoadTexture("Resources/Textures/case.bmp");
	da = LoadTexture("Resources/Textures/case.bmp");

	tab = LoadTexture("Resources/Textures/case1.bmp");
	caseinterface = LoadTexture("Resources/Textures/a.bmp");

	casess = LoadTexture("Resources/Textures/casess.bmp");
	tab1 = LoadTexture("Resources/Textures/f.bmp");
	plant = LoadTexture("Resources/Textures/i.bmp");
	windows = LoadTexture("Resources/Textures/ice.bmp");
	glass = LoadTexture("Resources/Textures/r.bmp");
}


float room(float x, float y, float z, float width, float height, float length) {


	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, fa);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, ba);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, la);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, ra);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, ua);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, da);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	return 0;
}

float insideroom(float x, float y, float z, float width, float height, float length) {


	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y - height / 2;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, glass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	return 0;
}


void table1() {

	glBegin(GL_QUADS);
	glVertex3d(-9, -5.8, -5);
	glVertex3d(9, -5.8, -5);
	glVertex3d(9, -5.8, -12);
	glVertex3d(-9, -5.8, -12);
	glEnd();

}

void table2() {

	glPushMatrix();
	glBegin(GL_QUADS);
		//glColor3d(1, 0, 0);
	glVertex3d(-9, -1.5 , -5);
	glVertex3d(9, -1.5 , -5);
	glVertex3d(9, -1.8 , -5);
	glVertex3d(-9 , -1.8,-5);

	glEnd();
	glPopMatrix();
}

void table3() {

	glBindTexture(GL_TEXTURE_2D, tab1);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);

	glTexCoord2d(0, 0);
	glVertex3d(-8, -5.8, -5);
	glTexCoord2d(0, 1);
	glVertex3d(-8, -1.8, -5);
	glTexCoord2d(1, 1);
	glVertex3d(-7, -1.8, -5);
	glTexCoord2d(1, 0);
	glVertex3d(-7, -5.8, -5);

	glEnd();
}

void table4() {

	glBegin(GL_QUADS);
	//glColor3d(1, 0, 0);
	glVertex3d(-9, -1.5, -5);
	glVertex3d(-9, -1.5, -12);
	glVertex3d(-9, -1.8, -12);
	glVertex3d(-9, -1.8, -5);
	glEnd();

}

void table() {

	glTranslated(0, -3, -7);
	glPushMatrix();
	glEnable(GL_BLEND);
	glTranslated(0, 4, 0);
	glColor4d(0.5,0.5,0.5,0.1);
	table1();
	glPopMatrix();
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	
	
    glTranslated(0, 4.3, 0);
	glColor4f(0.5,0.5,0.5,0.3);

	table1();
	
	glPopMatrix();
    glDisable(GL_BLEND);
   glPushMatrix();
   table2();
   glTranslated(0,0,-7);
   table2();
   glPopMatrix();

   glPushMatrix();
   table4();
   glTranslated(18,0,0);
   table4();
   glPopMatrix();
 
}

void pole() {
	glPushMatrix();
	
	table3();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-3, 0, -13);
	glRotated(90, 0, 1, 0);
	table3();

	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, -1);

	table3();

	glPopMatrix();
	glPushMatrix();
	glTranslated(-2, 0, -13);
	glRotated(90, 0, 1, 0);
	table3();

	glPopMatrix();
	glPushMatrix();
	glTranslated(-2, 0, -13);
	glRotated(90, 0, 1, 0);
	table3();

	glPopMatrix();

}

void casesup() {
	glBindTexture(GL_TEXTURE_2D, casess);
	glBegin(GL_QUADS);

	glTexCoord2d(1, 0);
	glVertex3d(2, -1.2, -6);
	glTexCoord2d(1, 1);
	glVertex3d(5, -1.2, -6);
	glTexCoord2d(0, 1);
	glVertex3d(5, -1.2, -11);
	glTexCoord2d(0, 0);
	glVertex3d(2, -1.2, -11);

	glEnd();
}

void casesrl() {

	glBindTexture(GL_TEXTURE_2D, casess);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(2, 3.5, -6);
	glTexCoord2d(0, 1);
	glVertex3d(2, -1.8 , -6);
	glTexCoord2d(1, 1);
	glVertex3d(2, -1.8, -11);
	glTexCoord2d(1, 0);
	glVertex3d(2, 3.5, -11);

	glEnd();
}

void casesfront() {
	glBindTexture(GL_TEXTURE_2D, caseinterface);
	glBegin(GL_QUADS);
	//	glColor3d(1, 0, 0);

	glTexCoord2d(0, 0);
	glVertex3d(2, 3.5, -6);
	glTexCoord2d(0, 1);
	glVertex3d(2, -1.8, -6);
	glTexCoord2d(1, 1);
	glVertex3d(5, -1.8, -6);
	glTexCoord2d(1, 0);
	glVertex3d(5, 3.5, -6);
	glEnd();
}

void casesback() {
	glBindTexture(GL_TEXTURE_2D, casess);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3d(2, 3.5, -6);
	glTexCoord2d(0, 1);
	glVertex3d(2, -1.8, -6);
	glTexCoord2d(1, 1);
	glVertex3d(5, -1.8, -6);
	glTexCoord2d(1, 0);
	glVertex3d(5, 3.5, -6);
	glEnd();
}

void cases() {
	//glTranslated(0,3,0);
	casesup();
	glPushMatrix();
	glTranslated(0, 4.7, 0);
	casesup();
	glPopMatrix();
	glPushMatrix();

	casesrl();
	glTranslated(3, 0, 0);
	casesrl();
	glPopMatrix();
	glPushMatrix();
	casesfront();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-5);
	//glDisable(GL_TEXTURE_2D);
	casesback();
	glPopMatrix();
}

void paint() {
	glBindTexture(GL_TEXTURE_2D, plant);
	glBegin(GL_QUADS);

	//glColor3d(1, 0,0);
	//glColor4f(1.0, 0, 0, 0.5);
	glTexCoord2d(1, 0);
	glVertex3d(-12, 2, -17.5);
	glTexCoord2d(1, 1);
	glVertex3d(-12, 7, -17.5);
	glTexCoord2d(0, 1);
	glVertex3d(-3, 7, -17.5);
	glTexCoord2d(0, 0);
	glVertex3d(-3, 2, -17.5);

	glEnd();

}

void window1() {
	glBindTexture(GL_TEXTURE_2D, windows);
	glBegin(GL_QUADS);

	//glColor3d(1, 0,0);
	//glColor4f(1.0, 0, 0, 0.5);
	glTexCoord2d(1, 0);
	glVertex3d(-12.2, 2, -17);
	glTexCoord2d(1, 1);
	glVertex3d(-12.2, 7, -17);
	glTexCoord2d(0, 1);
	glVertex3d(-11.4, 7, -17);
	glTexCoord2d(0, 0);
	glVertex3d(-11.4, 2, -17);

	glEnd();

}
void window2() {
	glBindTexture(GL_TEXTURE_2D, windows);
	glBegin(GL_QUADS);

	//glColor3d(1, 0,0);
	//glColor4f(1.0, 0, 0, 0.5);
	glTexCoord2d(1, 0);
	glVertex3d(-12, 6.6, -17);
	glTexCoord2d(1, 1);
	glVertex3d(-12, 7, -17);
	glTexCoord2d(0, 1);
	glVertex3d(-3, 7, -17);
	glTexCoord2d(0, 0);
	glVertex3d(-3, 6.6, -17);

	glEnd();

}
void window3() {
	

	//glColor3d(1, 0,0);
	//glColor4f(1.0, 0, 0, 0.5);
	
	glBegin(GL_QUADS);
	
	glVertex3d(-12, 2, -17.5);
	
	glVertex3d(-12, 7, -17.5);
	
	glVertex3d(-3, 7, -17.5);
	
	glVertex3d(-3, 2, -17.5);

	glEnd();
	glDisable(GL_BLEND);
}
void window4() {
	glBindTexture(GL_TEXTURE_2D, windows);
	glBegin(GL_QUADS);

	//glColor3d(1, 0,0);
	//glColor4f(1.0, 0, 0, 0.5);
	glTexCoord2d(1, 0);
	glVertex3d(-12, 2, -17);
	glTexCoord2d(1, 1);
	glVertex3d(-12, 7, -17);
	glTexCoord2d(0, 1);
	glVertex3d(-11.3, 7, -17);
	glTexCoord2d(0, 0);
	glVertex3d(-11.3, 2, -17);

	glEnd();


}

void window() {

	glPushMatrix();
	window1();
	glTranslated(9,0,0);
	window1();
	glPopMatrix();
	glPushMatrix();
	window2();
	
	glTranslated(0,-4.6,0);
	window2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.3, 0, 0);
	window4();
	glPopMatrix();
	glPushMatrix();
	
	glRotated(90, 0, 1, 0);
	glTranslated(9, 0, -29);
	window4();
	glTranslated(0, 0, 1);
	window4();

	glPopMatrix();


	glPushMatrix();
	glEnable(GL_BLEND);
	glColor4d(0.5, 0.5, 0.5, 0.6);
	window3();
	  


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_BLEND);
  glPopMatrix();
}

void lighting() {
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_color);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void drawallroom() {
	room(0, 0, 0, 35, 18, 50);
	
	table();
	pole();
	glTranslated(0, 0, -6);
	pole();
	glTranslated(15, 0, 0);
	pole();
	glTranslated(0, 0, 6);
	pole();
	glTranslated(-12, 0.3, 0);
	cases();
	glTranslated(3,2,0);
	paint();
	window();
	
}

void mainroom::drawModel()
{
	//lighting();
	drawallroom();
}