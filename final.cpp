#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<glut.h>
#include <math.h>
int flag=0,h=0;


unsigned char key1;
void mykey(unsigned char key,int x,int y)
{
   key1=key;

   if(key=='M' || key=='m')
	   flag=1;
 
}

void init2()
{
	glClearColor(0.0,0.0,0.0,0.0);
	
	gluLookAt(0,0,300,0,0,0,0,1,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,499,0,499,150,900);
glMatrixMode(GL_MODELVIEW);
}

void Graphics (void)
{
glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_LIGHTING);
	GLfloat	Pos1[]= {20,-20,-20,0};
	GLfloat	Pos2[]= {0,1,0,0};
	
	glPushMatrix();
    glTranslatef (400, 500, 0);
	glLightfv(GL_LIGHT0,GL_POSITION,Pos1);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1,GL_POSITION,Pos2);
	glEnable(GL_LIGHTING); 
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,Pos2);	
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,40.0);
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,5.0);
	glEnable(GL_LIGHT1);
	glColor3f (1,0,1);
	glutSolidSphere(100,30,40);
    glPopMatrix();

	glPushMatrix();
    glTranslatef (50, 20, 0.0);
    glLightfv(GL_LIGHT0,GL_POSITION,Pos1);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1,GL_POSITION,Pos2);
	glEnable(GL_LIGHTING); 
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,Pos2);	
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,40.0);
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,5.0);
	glEnable(GL_LIGHT1);
	glColor3f (1,0,1);
	glutSolidSphere(100,30,50);
    glPopMatrix();

	glFlush();
}

void Environment()
{

	GLfloat  AmbientLight[] = { 0.9, 0.9, 0.1, 0.0 };
	GLfloat  diffuseLight[] = { 0.1, 0.9, 0.9, 1.0 };
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};

	glEnable(GL_LIGHTING);  
	glLightfv(GL_LIGHT0,GL_AMBIENT,AmbientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHTING); 
	glLightfv(GL_LIGHT1,GL_AMBIENT,AmbientLight);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT1,GL_SPECULAR,specular);
	glEnable(GL_LIGHT1);


}



/***************************************/

void *currentfont;
char str[10];
int size,a[10],pass[10];
void selection(int a[10],int);
 


void setFont(void *font)
{
	currentfont=font;
}

void init(void)
{
	glClearColor(1,1,1,1);
	glColor3f(0,1,0);
	gluOrtho2D(0.0,700.0,0.0,240.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
}


void drawstring(GLfloat x,GLfloat y,char *string)
{
    char *c;
	glRasterPos2f(x,y);
 
	for(c=string;*c!='\0';*c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}



void title()												// to draw the starting screen
{
		
	setFont(GLUT_BITMAP_HELVETICA_18);
		glBegin(GL_POLYGON);
			glColor3f(0.0,0.1,0.2);
		glVertex2i(-750,500);
			glColor3f(0.0,0.0,0.0);	
		glVertex2i(-750,0);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(500,0);
			glColor3f(0.0,0.1,0.2);
		glVertex2i(500,500);
	glEnd();

	glColor3f(1.0,0.0,1.0);
	drawstring(-500.0,350.0,"*  * G R A P H I C A L   I L L U S T R A T I O N   OF   S O R T I N G  T E C H N I C S *  *");
	
	glColor3f(1.0,1.0,1.0);
	drawstring(-200.0,200,"SUBMITTED   BY");				
	
	glColor3f(0.0,1.0,1.0);
	drawstring(-300.0,100.0," ADARSH S.                           4JN15CS001");
	
	glColor3f(0.0,1.0,1.0);
	drawstring(-300.0,50.0,"  HAREESH J NAIK.	                  4JN15CS028");
	
	glColor3f(1.0,1.0,1.0);
	drawstring(-240.0,-50.0,"UNDER THE GUIDANCE OF");
	
	glColor3f(0.0,1.0,1.0);
	drawstring(-480.0,-100.0," Ms.SUSHMA R.B. ");

		setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(90.0,-120.0,"        B.E.,");		
	
	glColor3f(0.0,1.0,1.0);
	drawstring(100.0,-120.0,"            M tech Lecturer, Dept of CS&E");

	glColor3f(0.0,1.0,1.0);
	drawstring(100.0,-140.0,"     JNNCE, SHIVAMOGGA");

	
	setFont(GLUT_BITMAP_HELVETICA_18);

	glColor3f(0.0,1.0,1.0);
	drawstring(-280.0,-100.0,"                                                                                     Mr.RAVINDRA S");
	setFont(GLUT_BITMAP_HELVETICA_12);

	glColor3f(0.0,1.0,1.0);
	drawstring(-530.0,-120.0,"               B.E.,Lecturer, Dept of CS&E");		
	
	glColor3f(0.0,1.0,1.0);
	drawstring(-530.0,-140.0,"               JNNCE,SHIVAMOGGA");

    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(200.0,-300.0," Press M or m to -> continue");
    
	glFlush();
}	

void delay()
{
	int i,j;
	for(i=0;i<10000;i++)
		for(j=0;j<10000;j++);
}

void draw_tab1()
{
	
	int i,h,k;
	char s[20],*s1;
	glColor3f(1,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
	drawstring(90.0,210.0,"*******This is the implementation of selection sort using openGL*******");
	for(i=0;i<size;i++)
	{
		h=100+i*50;
		k=150+i*50;
		//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
			glColor3f(0,0,0);
			glVertex2i(h,100);
			glColor3f(0.8,0,0);
			glVertex2i(k,100);
			glVertex2i(k,150);
			glVertex2i(h,150);
		glEnd();
		s1=itoa(a[i],s,10);
		glColor3f(1,0.8,0.5);
		drawstring(h+10,125,s1);
		
		delay();
	}
	glFlush();
}
 
void selection(int a[10],int n)
{
int i,j,min,t;
//glClear(GL_COLOR_BUFFER_BIT);
 for(i=0;i<=n-2;i++)
{
	min=i;
	for(j=i+1;j<=n-1;j++)
		if(a[j]<a[min]) min=j;
		t=a[i];
		a[i]=a[min];
		a[min]=t;
}
}
void myDisplay1(void)
{
	//int k,h,i,j,v,m,l=0;
 
	glColor3f(1,1,0);
	
	//int cols[]={1391376,463792,198768,86961,33936,13776,4592,1968,861,336,112,48,21,7,3,1};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	draw_tab1();
	delay();
	selection(a,size);
	delay();
		glClear(GL_COLOR_BUFFER_BIT);
	//delay();
		draw_tab1();
		
			//delay();
	
	
	glFlush();
}
 
	 





/************************************/


void mergesort(int a[10],int,int,int);

void draw_tab2()
{
	int i,h,k;
	char s[20],*s1;
	glColor3f(1,0,1);
	drawstring(90.0,210.0,"*******This is the implementation of merge sort using openGL*******");
	for(i=0;i<size;i++)
	{
		h=100+i*50;
		k=150+i*50;
		//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
			glColor3f(0,0,0);
			glVertex2i(h,100);
			glColor3f(1,0,0);
			glVertex2i(k,100);
			glVertex2i(k,150);
			glVertex2i(h,150);
		glEnd();
		s1=itoa(a[i],s,10);
		glColor3f(0,0,0);
		drawstring(h+10,125,s1);
		
		delay();
	}
	glFlush();
}
void merge(int a[10],int l,int h)
{
	int m;
	if(l<h)
	 {
		 m=(l+h)/2;
		 merge(a,l,m);
		 merge(a,m+1,h);
		 mergesort(a,l,m,h);
	 }
	
}

void myDisplay2(void)
{
	//int k,h,i,j,v,m,l=0;
	//int cols[]={1391376,463792,198768,86961,33936,13776,4592,1968,861,336,112,48,21,7,3,1};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	draw_tab2(); 
	merge(a,0,size-1);
	//delay();
		glClear(GL_COLOR_BUFFER_BIT);
	//delay();
		draw_tab2();
		
			//delay();
	
	
	glFlush();
}
 
	 

 void  mergesort(int a[10],int l,int m,int h)
{
	int i=l,j=m+1,k=l;
	char c[20];
	while(i<=m && j<=h)

	{
		
		if(a[i]<=a[j])
		{
			c[k++]=a[i++];
		}

		else
		{
			c[k++]=a[j++];

		}

	}
	while(i<=m)
	{
		c[k++]=a[i++];
	}

	while(j<=h)
	{
		c[k++]=a[j++];
	}
	for(i=l;i<k;i++)
	{
	//	delay();
		a[i]=c[i];
		glClear(GL_COLOR_BUFFER_BIT);

			draw_tab2();
//glFlush();
	}

 }


/********************/

void quick(int a[10],int,int,int);
int partition(int a[10],int,int);

void draw_tab3()
{
	int i,h,k;
	char s[20],*s1;
	glColor3f(1,0,1);
	drawstring(90.0,210.0,"*******This is the implementation of Quick sort using openGL*******");
	for(i=0;i<size;i++)
	{
		h=100+i*50;
		k=150+i*50;
		//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
		    glColor3f(0,0,0);
			glVertex2i(h,100);
			glColor3f(0,1,0);
			glVertex2i(k,100);
			glVertex2i(k,150);
			glVertex2i(h,150);
		glEnd();
		s1=itoa(a[i],s,10);
		glColor3f(1,0,0);
		drawstring(h+10,125,s1);
		
		delay();
	}
	glFlush();
}
void quick(int a[10],int low,int high)
{
	int j;
	if(low<high)
	 {
		 j=partition(a,low,high);
		 quick(a,low,j-1);
		 quick(a,j+1,high);
	 }
	
}

void myDisplay3(void)
{
	//int k,h,i,j,v,m,l=0;
	//int cols[]={1391376,463792,198768,86961,33936,13776,4592,1968,861,336,112,48,21,7,3,1};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	draw_tab3(); 
	quick(a,0,size-1);
	//delay();
		glClear(GL_COLOR_BUFFER_BIT);
	//delay();
		draw_tab3();
		
			//delay();
	
	
	glFlush();
}
 
	 

int partition(int a[],int low,int high)
{
	int p,i,j,temp;
	p=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(i<high && a[i]<p)
		{
			i++;
			//count++;
		}
		while(j>low && a[j]>=p)
		{
			j--;
		//	count++;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		//	count++;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}

			
		glClear(GL_COLOR_BUFFER_BIT);

			draw_tab3();
//glFlush();
}




void sort_menu(int id)
{
	int i;
	switch(id)
	{
	case 1:
	
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	printf("Enter the elements\n");
	for(i=0;i<size;i++)
	scanf("%d",&a[i]);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800.0,600.0);
	glutInitWindowPosition(00.0,0.0);
    glutCreateWindow("SELECTION_SORT");

	init();
		glutDisplayFunc(myDisplay1);
	
    break;
	
	case 2:
	
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	printf("Enter the elements\n");
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800.0,600.0);
	glutInitWindowPosition(00.0,0.0);

	glutCreateWindow("MERGE_SORT");
	init();

        glutDisplayFunc(myDisplay2);
		
     break;
	case 3:
	
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	printf("Enter the elements\n");
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800.0,600.0);
	glutInitWindowPosition(0.0,0.0);

	glutCreateWindow("QUICK_SORT");
	init();

        glutDisplayFunc(myDisplay3);
		
     break;



	
	default:
		printf("\n Wrong Choice \n");
		exit(0);
	}
	glutPostRedisplay();
}

void displayt()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
		title();
if(flag==1 && h==0)
	{
	h=1;
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (450,100);
	glutInitWindowSize (800,500);
	glutCreateWindow("Sort Selection Menu");

		init2();
	glutDisplayFunc (Graphics);
	Environment();

	glutCreateMenu(sort_menu);
	glutAddMenuEntry("SELECTION_SORT",1);
	glutAddMenuEntry("MERGE_SORT",2);
	glutAddMenuEntry("QUICK_SORT",3);

	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

}
void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-750.0,450.0,-500.0,400.0);
}
/**************************************************/   

void main(int argc, char**argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);



	glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,950);
    glutCreateWindow("SORTING");
	myinit();
	glutDisplayFunc(displayt);
	glutKeyboardFunc(mykey);
    
		glutMainLoop();
   }
