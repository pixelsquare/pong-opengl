#include "header.h"
#define __HEADER_H__
#include <stdio.h>
#include <conio.h>
void main(int argc, char **argv)
{
           GLUTmain(argc, argv);
		   srand(time(NULL));
}

void Scene()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(LookX, LookY, LookZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/* Keyboard Rotate & Object Position */
	glTranslatef(MoveX, MoveY, 0.0f);
	glRotatef(AngleY, 0.0, 1.0, 0.0);
	glRotatef(AngleX, 1.0, 0.0, 0.0);
		/* Objects on Screen */
			Lighting();
			grid();
			bg();
			box();
			ball();
			paddle1();
			paddle2();

//******************************************* Color Changer*****//
	if(ball_x > boxR)
	{
		R = 1.0f;
		G = 0.0f;
		B = 0.0f;
		ball_x = 100.0f;
	}
	if(ball_x < boxL)
	{
		R = 0.0f;
		G = 0.0f;
		B = 1.0f;
		ball_x = -100.0f;
	}
//************************************************//
	glutSwapBuffers();
}

void bg()
{
	glPushMatrix();

	glTranslatef(0.0, 0.0, -0.4);
			glBegin(GL_QUADS);
					glNormal3f(1.0, 0.0, 0.0);
					glColor3f(0.2, 1.0, 0.5);
					glVertex3f(25.0, 25.0, 0.0);
					glVertex3f(25.0, -25.0, 0.0);
					glVertex3f(-25.0, -25.0, 0.0);
					glVertex3f(-25.0, 25.0, 00);
			glEnd();

}

void grid()
{
	for(int i = 0; i < 25; i++)
	{
		//x-axis (center)
		glPushMatrix();
		glTranslatef(0.0f, i, -0.5f);
	glBegin(GL_LINES);
		glVertex3f(-25.0f, 0.0f, 0.0f);
		glVertex3f(25.0f, 0.0f,0.0f);
	glEnd();
		glPopMatrix();
	
		//y-axis (center)
		glPushMatrix();
		glTranslatef(i, 0.0f, -0.5f);
	glBegin(GL_LINES);
		glVertex3f(0.0f, 25.0f, 0.0f);
		glVertex3f(0.0f, -25.0f,0.0f);
	glEnd();
		glPopMatrix();


	}

		for(int i = 0; i > -25; i--)
	{
		//x-axis (center)
		glPushMatrix();
		glTranslatef(0.0f, i, -0.5f);
	glBegin(GL_LINES);
		glVertex3f(-25.0f, 0.0f, 0.0f);
		glVertex3f(25.0f, 0.0f,0.0f);
	glEnd();
		glPopMatrix();
	
		//y-axis (center)
		glPushMatrix();
		glTranslatef(i, 0.0f, -0.5f);
	glBegin(GL_LINES);
		glVertex3f(0.0f, -25.0f, 0.0f);
		glVertex3f(0.0f, 25.0f,0.0f);
	glEnd();
		glPopMatrix();
	}
}

void box()
{
	glPushMatrix();
	glColor3f(R, G, B);

		/* Ball Edges */
		glPushMatrix(); // BOTTOM - LEFT BOX
		glScalef(0.8, 1.0, 1.0);
		glTranslatef(-6.0, -6.0, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix(); // BOTTOM - RIGHT BOX
		glScalef(0.8, 1.0, 1.0);
		glTranslatef(6.0, -6.0, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix(); // TOP - LEFT BOX
		glScalef(0.8, 1.0, 1.0);
		glTranslatef(-6.0, 6.0, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix(); // TOP - RIGHT BOX
		glScalef(0.8, 1.0, 1.0);
		glTranslatef(6.0, 6.0, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();

		for(int a = 0; a < 12; a++)
		{
			a += 1.0;
			glPushMatrix(); // RIGHT Side
			glScalef(0.8, 1.0, 0.5);
			glTranslatef(0.0, -5.0, -0.3);
			glTranslatef(6.0, a, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // RIGHT Side
			glScalef(0.8, 1.0, 0.8);
			glTranslatef(0.0, -6.0, 0.0);
			glTranslatef(6.0, a, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // LEFT Side
			glScalef(0.8, 1.0, 0.5);
			glTranslatef(0.0, -5.0, -0.3);
			glTranslatef(-6.0, a, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // LEFT Side
			glScalef(0.8, 1.0, 0.8);
			glTranslatef(0.0, -6.0, 0.0);
			glTranslatef(-6.0, a, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // TOP Side
			glScalef(0.8, 1.0, 0.5);
			glTranslatef(-5.0, 0.0, -0.3);
			glTranslatef(a, 6.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // TOP Side
			glScalef(0.8, 1.0, 0.8);
			glTranslatef(-6.0, 0.0, 0.0);
			glTranslatef(a, 6.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // BOTTOM Side
			glScalef(0.8, 1.0, 0.5);
			glTranslatef(-5.0, 0.0, -0.3);
			glTranslatef(a, -6.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix(); // BOTTOM Side
			glScalef(0.8, 1.0, 0.8);
			glTranslatef(-6.0, 0.0, 0.0);
			glTranslatef(a, -6.0, 0.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
	glPopMatrix();
}

void ball()
{
	
//************************************************//

	if((blrx >= p1ulx && bulx <= p1lrx) && (blry <= p1uly && buly >= p1lry))
	{
		Tx = true;
		Srate = ((rand() % 50) / 1000.0) + 0.05;
	}
	if((blrx >= p2ulx && bulx <= p2lrx) && (blry <= p2uly && buly >= p2lry))
	{
		Tx = false;
		Srate = ((rand() % 50) / 1000.0) + 0.07;
	}

//******************************************* TEST (X-axis) *****//
	if (Tx)
    {
      ball_x -= Srate;
      blrx -= Srate;
      bulx -= Srate;
    }
    else
    {
      ball_x += Srate;
      blrx += Srate;
      bulx += Srate;
    }
//************************************************//
	if(buly >= boxT && bulx <= boxT)
	{
		Ty = true;
		Srate = ((rand() % 50) / 1000.0) + 0.08;
	}
	if(blrx >= boxB && blry <= boxB)
	{
		Ty = false;
		Srate = ((rand() % 50) / 1000.0) + 0.04;
	}
//******************************************* TEST (Y-axis)*****//
	if (Ty)
    {
      ball_y -= Srate;
      blry -= Srate;
      buly -= Srate;
    }
    else
    {
      ball_y += Srate;
      blry += Srate;
      buly += Srate;
    }
//************************************************//
	angle += 1.0;
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(ball_x, ball_y, z);
	glRotatef(angle, 1.0f, 1.0f, 1.0f);
	glutWireSphere(0.3, slices, stacks);
	glPopMatrix();
}

void paddle1()
{
	if(Tai1)
	{
	if(blrx >= p1 && bulx >= p1)
	{
		Tai = false;
	//Srate = ((rand() % 100) / 1000.0) + 0.02;
	}
	if(blry <= p1 && buly <= p1)
	{
		Tai = true;
	//Srate = ((rand() % 100) / 1000.0) + 0.02;
	}

	if (Tai)
    {
		if(p1lry >= -5.2)
		{
		  p1 -= Srate;
		  p1uly -= Srate;
		  p1lry -= Srate;
		}
    }
	else
	{
		if(p1lry <= 5.2)
		{
		  p1 += Srate;
		  p1uly += Srate;
		  p1lry += Srate;
		}
	 }
	}



	glPushMatrix();
	glTranslatef(4.0, p1, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);

		glPushMatrix();
		glRotatef(90.0, -45.0, 0.0, 0.0);
		glScalef(pwidth, pheight, 0.5);
		glutSolidCone(0.4, 2.5, slices, stacks);
		glPopMatrix();

		glPushMatrix();
		glRotatef(90.0, 45.0, 0.0, 0.0);
		glScalef(0.3, 0.3, 0.5);
		glutSolidCone(0.4, 2.5, slices, stacks);
		glPopMatrix();

		glPushMatrix();
		glutSolidSphere(0.15, slices, stacks);
		glPopMatrix();

	glPopMatrix();
}

void paddle2()
{
	if(Tai2)
	{
	if(blrx >= p2 && bulx >= p2)
	{
		Tai = false;
		//Srate = ((rand() % 100) / 1000.0) + 0.02;
	}
	if(blry <= p2 && buly <= p2)
	{
		Tai = true;
		//Srate = ((rand() % 100) / 1000.0) + 0.02;
	}

	if (Tai)
    {
		if(p2lry >= -5.2)
		{
		  p2 -= Srate;
		  p2uly -= Srate;
		  p2lry -= Srate;
		}
    }
	else
	{
		if(p2lry <= 5.2)
		{
		  p2 += Srate;
		  p2uly += Srate;
		  p2lry += Srate;
		}
	 }
	}
	glPushMatrix();
	glTranslatef(-4.0, p2, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);

		glPushMatrix();
		glRotatef(90.0, -45.0, 0.0, 0.0);
		glScalef(pwidth, pheight, 0.5);
		glutSolidCone(0.4, 2.5, slices, stacks);
		glPopMatrix();

		glPushMatrix();
		glRotatef(90.0, 45.0, 0.0, 0.0);
		glScalef(0.3, 0.3, 0.5);
		glutSolidCone(0.4, 2.5, slices, stacks);
		glPopMatrix();

		glPushMatrix();
		glutSolidSphere(0.15, slices, stacks);
		glPopMatrix();

	glPopMatrix();
}