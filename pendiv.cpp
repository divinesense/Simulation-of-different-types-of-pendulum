#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;
#define pi 3.1415                                 
GLfloat theta=0.0;
GLfloat thetamax_seconds=20*(pi/180),l_seconds=10.0;
//GLfloat thetamax=45*(pi/180);
GLfloat g=98;
//l=20.0;  
GLint t=0; 
GLint val1=0;
static int w;
static int damp_pend1;
static int circ_pend1;
static int mainmenu;
GLint counter1=0;
GLint counter11=0;
GLint count1=0,counter4=0;
GLdouble theta1[3000]; 
GLdouble theta11[3000];   
GLdouble theta2[3000];
GLfloat total_theta[3000];
GLint flag=0;
GLint pflag=0;
GLfloat x2,y2;
GLint hr=0;
GLint min1=0;
GLint sec=0;   // for seconds pendulum time display
//GLdouble viewer[]={30.0,-5.0,0.0};
GLdouble viewer[]={0.0,-5.0,30.0};
GLdouble viewer1[]={0.0,10.0,5.0};
GLfloat viewer_angle=90*(pi/180);
GLfloat viewer_angle1=0*(pi/180);
GLint theta_circular2=0;
GLint theta_circular22=0;
//GLfloat l_circular=20.0,theta_max_circular=30*(pi/180);
double ti=0,tf=20;
double theta01=45*(pi/180);
double theta011=30*(pi/180);
double v0=2.5; // initial omega(w) value
int N=2500;
double alpha=12,m=50;
int val01;
int val011,val4;
GLdouble thetasp[10000],theta_phisp[10000];
GLfloat x_sp[10000],y_sp[10000],z_sp[10000];
GLfloat x_pen1[10000],y_pen1[10000];
GLfloat x_pen11[10000],y_pen11[10000];
GLint start=0,start2=0;
GLfloat x_pen2[10000],y_pen2[10000],z_pen2[10000];
GLfloat x_pen22[10000],y_pen22[10000],z_pen22[10000];

void rk1(GLfloat l){
    double h = (tf - ti)/N; 
    double t = ti;
    GLdouble theta, v, k11, k12, k21, k22, k31, k32, k41, k42;
    
    theta = theta01;
    v = v0;
    int i;
    theta1[0] = theta;

    for(i = 1; i<N; i++){
        k11 = h*v;
        k12 = -h*(alpha/m)*v -h*(g/l)*sin(theta);
        
        k21 = h*(v + k11/2);
        k22 = -h*(alpha/m)*(v + k12/2) - h*(g/l)*sin(theta + k12/2);
        
        k31 = h*(v + k21/2);
        k32 = -h*(alpha/m)*(v + k22/2)-h*(g/l)*sin(theta + k22/2);
        
        k41 = h*(v + k31);
        k42 = -h*(alpha/m)*(v + k32) - h*(g/l)*sin(theta + k32);
        
        theta = theta + (k11 + 2*k21 + 2*k31 + k41)/6;
        v = v + (k12 + 2*k22 + 2*k32 + k42)/6;
        t = t + h;

        theta1[i] = theta;
        
   }
     //cout<<theta1[i-1];
     i--;
        while(theta1[i]<=0.0)
       {   theta1[i+1]=theta1[i]+0.002;  i++; }
        val01=i;
       // cout<<"val "<<val01;
}
 
 void rk11(GLfloat l){
    double h = (tf - ti)/N; 
    double t = ti;
    GLdouble theta, v, k11, k12, k21, k22, k31, k32, k41, k42;
    
    theta = theta011;
    v = v0;
    int i;
    theta11[0] = theta;

    for(i = 1; i<N; i++){
        k11 = h*v;
        k12 = -h*(alpha/m)*v -h*(g/l)*sin(theta);
        
        k21 = h*(v + k11/2);
        k22 = -h*(alpha/m)*(v + k12/2) - h*(g/l)*sin(theta + k12/2);
        
        k31 = h*(v + k21/2);
        k32 = -h*(alpha/m)*(v + k22/2)-h*(g/l)*sin(theta + k22/2);
        
        k41 = h*(v + k31);
        k42 = -h*(alpha/m)*(v + k32) - h*(g/l)*sin(theta + k32);
        
        theta = theta + (k11 + 2*k21 + 2*k31 + k41)/6;
        v = v + (k12 + 2*k22 + 2*k32 + k42)/6;
        t = t + h;

        theta11[i] = theta;
   }
    // cout<<theta11[i-1];
     i--;
        while(theta11[i]<=0.0)
       {   theta11[i+1]=theta11[i]+0.002;  i++; }
        val011=i;
       // cout<<"val "<<val011;
}

void rk4(int l,double m,double theta0,double theta_phi0,int N,double ti,double tf,double g)
{
    double h=0.01;
    double t=ti;
    double k11,k21,k31,k41,k12,k22,k32,k42,k13,k23,k33,k43;
    double p_phi=m*l*l*2.5*pow(sin(theta0),2);
    double theta=theta0;
    double theta_phi=theta_phi0;
    thetasp[0]=theta0;
    theta_phisp[0]=theta_phi0;
    double p_theta=450;
    int j;
    for(j=1;j<N;j++)
    {
       k11=((h*p_phi*p_phi*cos(theta))/(m*l*l*pow(sin(theta),3)))-h*m*g*l*sin(theta);
       k12=(h*p_theta)/(m*l*l);
       k13=(h*p_phi)/(m*l*l*(pow(sin(theta),2)));    
       
       k21=((h*p_phi*p_phi*cos(theta))/(m*l*l*pow(sin(theta),3)))-h*m*g*l*sin(theta);
       k22=(h*p_theta)/(m*l*l);
       k23=(h*p_phi)/(m*l*l*(pow(sin(theta),2))); 
       
       k31=((h*p_phi*p_phi*cos(theta))/(m*l*l*pow(sin(theta),3)))-h*m*g*l*sin(theta);
       k32=(h*p_theta)/(m*l*l);
       k33=(h*p_phi)/(m*l*l*(pow(sin(theta),2)));
       
       k41=((h*p_phi*p_phi*cos(theta))/(m*l*l*pow(sin(theta),3)))-h*m*g*l*sin(theta);
       k42=(h*p_theta)/(m*l*l);
       k43=(h*p_phi)/(m*l*l*(pow(sin(theta),2)));
       
       p_theta=p_theta+(k11+2*k21+2*k31+k41)/6;
       theta=theta+(k12+2*k22+2*k32+k42)/6;
       theta_phi=theta_phi+(k13+2*k23+2*k33+k43)/6;
       t=t+h;
       thetasp[j]=theta;
       theta_phisp[j]=theta_phi;
       
    } 
    val4=j;
 }


  void timer1(int id) 
  {
    if(pflag==0)
    {
        counter1++;
        if(counter1>=val01)
        {
        theta1[counter1]=0;
        }
         
    }
    glutPostRedisplay();
}
  void timer11(int id) 
  {
    if(pflag==0)
    {
        counter11++;
        if(counter11>=val011)
        {
        theta11[counter11]=0;
        }
         
    }
    glutPostRedisplay();
}

 void timer4(int id) 
  {
    if(pflag==0)
    {
        counter4++;
        if(counter4>=val4)
             counter4=0;
    }
    glutPostRedisplay();
}


void timer2(int id) 
  {
    if(pflag==0)
    {
        theta_circular2++;
        if(theta_circular2>=360)
         theta_circular2=0;
    }
    glutPostRedisplay();
}

void timer22(int id) 
  {
    if(pflag==0)
    {
        theta_circular22++;
        if(theta_circular22>=360)
         theta_circular22=0;
    }
    glutPostRedisplay();
}

  void timer3(int id) 
  {
      // cout<<"count 1 in timer3 is "<<count1<<"\n";
    if(pflag==0)
    {
        count1++;
        if(count1>=4*t)
         count1=0;
    }
    glutPostRedisplay();
}

void displaypen(GLfloat theta,GLfloat l)
{
    GLint i;
    GLfloat x1=0.0,y1=0.0;
    if(0<=theta<pi/2)
    {
     x2=l*sin(theta);
     y2=-l*cos(theta);
    
    }
    else if(pi/2<=theta<pi)
    {
        x2=-l*cos(pi-theta);
        y2=l*sin(pi-theta); 
        
     }
     else if(-pi/2<=theta<0)
     {
          x2=l*sin(theta);
          y2=-l*cos(theta);
      }
      else if(-pi<=theta<-pi/2)
      {
          x2=l*cos(pi-abs(theta));
          y2=-l*sin(pi-abs(theta)); 
       }
     if(l==20.0)
     {
      x_pen11[counter11]=x2;
      y_pen11[counter11]=y2;
      glColor3f(0.5,0.5,0.5);
       glPointSize(3.0);
       start=counter11-70;                 
      for(i=start;i<=counter11;i++)
      {
      glBegin(GL_POINTS);
      glVertex2f(x_pen11[i],y_pen11[i]);
      glEnd();
      }
    }
    else if(l==30.0)
    {
      x_pen1[counter1]=x2;
      y_pen1[counter1]=y2;
      glColor3f(0.5,0.5,0.5);
       glPointSize(3.0);
       start=counter1-70;                 
      for(i=start;i<=counter1;i++)
      {
      glBegin(GL_POINTS);
      glVertex2f(x_pen1[i],y_pen1[i]);
      glEnd();
      }  
     }
     glColor3f(0.0,1.0,0.0);
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex3f(0,0,0.0);
     glVertex3f(x2,y2,0.0);
     glEnd(); 
     
     glPushMatrix();
     GLfloat mat_ambient[]={1.0,1.0,1.0,1.0};
     GLfloat mat_diffuse[]={1.0,1.0,1.0,1.0};
     GLfloat mat_shininess[]={1.0,1.0,1.0,1.0};

     GLfloat lightintensity[]={1.0,1.0,1.0,1.0};
     GLfloat lightposition[]={3.0,-3.0,0.0,1.0};

     glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

     glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
     glLightfv(GL_LIGHT0,GL_SPECULAR,lightintensity);
      
     glColor3f(1.0,0.0,0.0);
     glTranslatef(x2,y2,0);
     glutSolidSphere(3,50,50);
     glPopMatrix();
 }
 
 void sphericalpen(GLfloat theta,GLfloat theta_phi,GLfloat l)
{
    // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     GLint i;
    GLfloat x1=0.0,y1=0.0;
     GLfloat x2=l*sin(theta)*cos(theta_phi);
     x_sp[counter4]=x2;
     GLfloat z2=l*sin(theta)*sin(theta_phi);
     z_sp[counter4]=z2;
     GLfloat y2=-l*cos(theta);
     y_sp[counter4]=y2; 
     // cout<<x2<<" "<<y2<<" "<<z2<<"\n";
     glColor3f(0.0,1.0,0.0);
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex3f(0,0,0.0);
     glVertex3f(x2,y2,z2);
     glEnd(); 
     glPointSize(3.0);
    glColor3f(0.5,0.5,0.5);
     for(i=0;i<=counter4;i++)
     {
     glBegin(GL_POINTS);
     glVertex3f(x_sp[i],y_sp[i],z_sp[i]);
     glEnd();
     }
     glPushMatrix();
     GLfloat mat_shininess[]={1.0,1.0,1.0,1.0};

     GLfloat lightintensity[]={1.0,1.0,1.0,1.0};
     GLfloat lightposition[]={3.0,-3.0,0.0,1.0};

     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

     glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
     glLightfv(GL_LIGHT0,GL_SPECULAR,lightintensity);
      
     glColor3f(1.0,0.0,0.0);
     glTranslatef(x2,y2,z2);
     glutSolidSphere(3,50,50);
     glPopMatrix();
 }
 
 void display_circular_pen(GLfloat theta,GLfloat l_circular,GLfloat theta_max_circular)
 {
      GLint i;
      GLfloat x1=0.0,y1=0.0;
      GLfloat h=l_circular*cos(theta_max_circular);
      GLfloat r_circular=l_circular*sin(theta_max_circular);
      GLfloat x3,z3;
      theta=theta*(pi/180);
      //cout<<"theta is "<<theta<<"\n";
         x3=r_circular*cos(theta);
         z3=r_circular*sin(theta);
         //cout<<"x3 "<<x3<<" z3 is "<<z3<<"\n";
     if(l_circular==2.0)
     {
      x_pen2[theta_circular2]=10*x3;
      z_pen2[theta_circular2]=10*z3;
      glColor3f(0.0,0.5,0.5);
       glPointSize(3.0);
       start2=theta_circular2-70;                 
      for(i=start2;i<=theta_circular2;i++)
      {
      glBegin(GL_POINTS);
      glVertex3f(x_pen2[i],-10*h,z_pen2[i]);
      glEnd();
      }   
     }
     else if(l_circular==3.0)
     {
      x_pen22[theta_circular22]=10*x3;
      z_pen22[theta_circular22]=10*z3;
      glColor3f(0.0,0.5,0.5);
       glPointSize(3.0);
       start2=theta_circular22-70;                 
      for(i=start2;i<=theta_circular22;i++)
      {
      glBegin(GL_POINTS);
      glVertex3f(x_pen22[i],-10*h,z_pen22[i]);
      glEnd();
      }  
      }   
     glColor3f(0.0,1.0,0.0);
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex3f(0,0,0.0);
     glVertex3f(10*x3,-10*h,10*z3);
     glEnd(); 
     
     
     glPushMatrix();
     GLfloat mat_ambient[]={1.0,0.0,0.0,1.0};
     GLfloat mat_diffuse[]={1.0,0.0,0.0,1.0};
     GLfloat mat_shininess[]={1.0,0.0,0.0,1.0};

     GLfloat lightintensity[]={0.7,0.7,0.7,1.0};
     GLfloat lightposition[]={0.0,5.0,0.0,0.0};

     glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

     glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
     glLightfv(GL_LIGHT0,GL_SPECULAR,lightintensity);
     
     glColor3f(1.0,0.0,0.0);
     glTranslatef(10*x3,-10*h,10*z3);
    // glScalef(1.3,1.3,1.3);
     glutSolidSphere(3,50,50);
     glPopMatrix();
         
}

void display_seconds_pen(GLfloat theta)
{
     // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     
    GLfloat x1=0.0,y1=0.0;
    if(0<=theta<pi/2)
    {
     x2=l_seconds*sin(theta);
     y2=-l_seconds*cos(theta);
    
    }
    else if(pi/2<=theta<pi)
    {
        x2=-l_seconds*cos(pi-theta);
        y2=l_seconds*sin(pi-theta); 
        
     }
     else if(-pi/2<=theta<0)
     {
          x2=l_seconds*sin(theta);
          y2=-l_seconds*cos(theta);
      }
      else if(-pi<=theta<-pi/2)
      {
          x2=l_seconds*cos(pi-abs(theta));
          y2=-l_seconds*sin(pi-abs(theta)); 
       }
     
     glColor3f(1.0,1.0,0.0);
     glLineWidth(4.0);
     glBegin(GL_LINES);
     glVertex3f(0,0,-5.0);
     glVertex3f(x2,y2,-5.0);
     glEnd(); 
     
     glPushMatrix();
     GLfloat mat_ambient[]={0.0,1.0,0.0,1.0};
     GLfloat mat_diffuse[]={0.0,1.0,0.0,1.0};
     GLfloat mat_shininess[]={0.0,1.0,0.0,1.0};

     GLfloat lightintensity[]={0.7,0.7,0.7,1.0};
     GLfloat lightposition[]={3.0,0.0,8.0,0.0};

     glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

     glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
     glLightfv(GL_LIGHT0,GL_SPECULAR,lightintensity);
     glColor3f(1.0,0.0,0.0);
     glTranslatef(x2,y2,-5);
     glutSolidSphere(3,50,50);
     glPopMatrix();
     
 }  
  
 void display_text(char *str,GLint x,GLint y,GLint z,GLfloat size,int color,int flag)
{
     GLint i;
     glPushMatrix();
     GLint len=strlen(str);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
       glEnable(GL_BLEND);
       if(flag==1)
       glEnable(GL_LINE_SMOOTH);
       else
       glDisable(GL_LINE_SMOOTH);
       glLineWidth(4.0);  
     if(color==1)
     glColor3f(1.0,0.0,0.0);
     else if(color==2)
     glColor3f(0.0,1.0,0.0);
     else if(color==3)
     glColor3f(1.0,1.0,0.0);
     else if(color==4)
     glColor3f(0.0,1.0,1.0);
     else if(color==5)
     glColor3f(1.0,0.0,1.0);
     glTranslatef(x,y,z);
     glScalef(size,size,size);
     for(i=0;i<len;i++)
     glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
      
      glPopMatrix();
 }
 
 void display1(GLfloat l,GLfloat thetamax)
{
    char str[200];
     rk1(l);
    glutTimerFunc(10,timer1,1);  
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
    displaypen(theta1[counter1],l);
    glPopMatrix();
    sprintf(str,"Length of pendulum is %.1f m, amplitude is %.1f degrees\n",l/10,thetamax*(180/pi));
    display_text(str,-53,20,0,0.02,1,0);
    sprintf(str,"Damping Pendulum\n");
    display_text(str,-53,15,0,0.02,1,0);
    glutSwapBuffers();
 }
 
  void display11(GLfloat l,GLfloat thetamax)
{
    char str[200];
     rk11(l);
    glutTimerFunc(10,timer11,1);  
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
    displaypen(theta11[counter11],l);
    glPopMatrix();
    sprintf(str,"Length of pendulum is %.1f m, amplitude is %.1f degrees\n",l/10,thetamax*(180/pi));
    display_text(str,-53,20,0,0.02,1,0);
    sprintf(str,"Damping Pendulum\n");
    display_text(str,-53,15,0,0.02,1,0);
    glutSwapBuffers();
 }
 
 void display4()
 {
     char str[200];
    glutTimerFunc(5,timer4,1);  
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,0.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    sphericalpen(thetasp[counter4],theta_phisp[counter4],20);
    glPopMatrix();
    glutSwapBuffers();
  }

 void display2(GLfloat l_circular,GLfloat theta_max_circular)
{
      glutTimerFunc(10,timer2,1); 
      
      glClearColor(0.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
     glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewer1[0],viewer1[1],viewer1[2],0.0,0.0,0.0,0.0,1.0,0.0);
    display_circular_pen(theta_circular2,l_circular,theta_max_circular);
    glPopMatrix();
    glutSwapBuffers();
 }
 
  void display22(GLfloat l_circular,GLfloat theta_max_circular)
{
      glutTimerFunc(10,timer22,1);
      glClearColor(0.0,1.0,1.0,0.0);
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
      glPushMatrix();
      glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(viewer1[0],viewer1[1],viewer1[2],0.0,0.0,0.0,0.0,1.0,0.0);
     display_circular_pen(theta_circular22,l_circular,theta_max_circular);
     glPopMatrix();
     glutSwapBuffers();
 }

void display3()
{
    
    char str[50];
   glutTimerFunc(1,timer3,1); //3.99
     glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   
    if((count1==2*t) || (count1==4*t-1))
    { 
        sec++;
        if(sec>=60)
        { 
           min1++;
           sec=0;
              if(min1>=60)
              {
                 hr++;
                 min1=0; sec=0;
                   if(hr>=24)
                   { 
                       hr=0; min1=0; sec=0;     
                   }         
              }       
        }
    }
   
    sprintf(str,"Time %d : %d : %d\n",hr,min1,sec);
    glColor3f(1,1,1);
    display_text(str,-53,20,0,0.02,1,0);
    sprintf(str,"Seconds Pendulum..L=1m\n");
    display_text(str,-53,15,0,0.02,1,0);
    display_seconds_pen(total_theta[count1]);
    glutSwapBuffers();
 }  

   
 void disp()
 {
      char str[50];
      glClearColor(0.0,0.0,0.0,0.0);
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      //glClearColor(1.0,1.0,0.0,0.0);
      
     
      sprintf(str,"COMPUTER GRAPHICS AND VISUALIZATION\n");
      display_text(str,-60,30,0,0.032,1,1);
      sprintf(str,"PROJECT\n");
      display_text(str,-5,25,0,0.032,1,1);
      sprintf(str,"SIMULATION OF DIFFERENT TYPES OF PENDULUM\n");
      display_text(str,-40,20,0,0.02,2,1);
      sprintf(str,"1. DAMPED PENDULUM\n");
      display_text(str,-30,14,0,0.015,4,0);
      sprintf(str,"2. CIRCULAR PENDULUM\n");
      display_text(str,-30,10,0,0.015,4,0);
      sprintf(str,"3. SECONDS PENDULUM\n");
      display_text(str,-30,6,0,0.015,4,0);
      sprintf(str,"4. SPHERICAL PENDULUM\n");
      display_text(str,-30,2,0,0.015,4,0);
      
      sprintf(str,">>>Press space to pause/resume motion\n");
      display_text(str,-45,-5,0,0.015,5,1);
      sprintf(str,">>>Press 'q' to quit\n");
      display_text(str,-45,-9,0,0.015,5,1);
      sprintf(str,">>>Press 'a''d''w''s' for camera rotation\n");
      display_text(str,-45,-13,0,0.015,5,1);
      sprintf(str,">>>Uses Runge-Kutta method for numerical integration\n");
      display_text(str,-45,-18,0,0.015,5,1);
      
      sprintf(str,"A3 BATCH\n");
      display_text(str,30,-27,0,0.02,3,1);
      sprintf(str,"DIVYENDU DUTTA\n");
      display_text(str,30,-32,0,0.02,3,1);
      sprintf(str,"1BI13CS050\n");
      display_text(str,30,-37,0,0.02,3,1);
      if(val1==1) display1(30.0,45*(pi/180)); 
      else if(val1==2)  display11(20.0,30*(pi/180)); 
      else if(val1==3) display2(2.0,30*(pi/180));
      else if(val1==4) display22(3.0,45*(pi/180));
      else if(val1==5)  display3();
      else if(val1==6) display4();
     glutSwapBuffers();
      
  }
 
  void keybd(unsigned char key, int x, int y){
     if(key==113) //q to quit
        exit(0);
      else if(key==32)   // space to pause/resume
      {     if(pflag==0)
                pflag=1;
            else
            pflag=0;
      }
      if(key=='a') { 
        viewer_angle=viewer_angle*(180/pi); 
        //cout<<"DFDF"<<viewer_angle<<"\n";  
        viewer_angle+=90.0;  
        viewer_angle=viewer_angle*(pi/180); 
        viewer[0]=30.0*cos(viewer_angle); 
        viewer[2]=30.0*sin(viewer_angle); 
        }
      if(key=='d') { 
         viewer_angle=viewer_angle*(180/pi); 
        // cout<<"DFDF"<<viewer_angle<<"\n";  
         viewer_angle-=90.0;  
         viewer_angle=viewer_angle*(pi/180); 
         viewer[0]=30.0*cos(viewer_angle); 
         viewer[2]=30.0*sin(viewer_angle); 
         }
         
         if(key=='w') { 
        viewer_angle1=viewer_angle1*(180/pi); 
       // cout<<"DFDF"<<viewer_angle1<<"\n";  
        viewer_angle1+=90.0;  
        viewer_angle1=viewer_angle1*(pi/180); 
        viewer1[2]=10.0*cos(viewer_angle1); 
        viewer1[1]=10.0*sin(viewer_angle1); 
        }
      if(key=='s') { 
         viewer_angle1=viewer_angle1*(180/pi); 
        // cout<<"DFDF"<<viewer_angle1<<"\n";  
         viewer_angle1-=90.0;  
         viewer_angle1=viewer_angle1*(pi/180); 
         viewer1[2]=10.0*cos(viewer_angle1); 
         viewer1[1]=10.0*sin(viewer_angle1); 
         }  
        if((key=='a')||(key=='d'))
         glutPostRedisplay();
      
 } 
void calc_theta(GLfloat l)
{
     int thetamax_second=thetamax_seconds*100000;
     float thetamax_second1=(float)thetamax_second/100000;
     while(theta<=thetamax_second1)
     {
          theta=thetamax_seconds*sin(sqrt(g/l)*t);
          if(theta<0.0)
          theta=-theta;
          theta2[t]=theta;
          t++;             
     }
    
     GLint i=0,j;
     for(j=t-1;j>=0;j--)
    { total_theta[i]=theta2[j]; i++; }
     for(j=0;j<t;j++)
     { total_theta[i]=-theta2[j]; i++; }
     for(j=t-1;j>=0;j--)
     { total_theta[i]=-theta2[j];  i++; }
     for(j=0;j<t;j++)
    {  total_theta[i]=theta2[j]; i++; }
     
 } 
 

 
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     if(w<=h)
    glOrtho(-50.0,50.0,-50.0*((GLfloat)h/(GLfloat)w),50.0*((GLfloat)h/(GLfloat)w),-100.0,100.0); 
      else
      glOrtho(-50.0*((GLfloat)w/(GLfloat)h),50.0*((GLfloat)w/(GLfloat)h),-50.0,50.0,-100.0,100.0);
      
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void menu(int);
void createMenu()
{
     damp_pend1=glutCreateMenu(menu);
     glutAddMenuEntry("Q=45 & L=3m",1);
     glutAddMenuEntry("Q=30 & L=2m",2);
     
     circ_pend1=glutCreateMenu(menu);
     glutAddMenuEntry("Q=30 & L=2m",3);
     glutAddMenuEntry("Q=45 & L=3m",4);
     
     mainmenu=glutCreateMenu(menu);
     glutAddSubMenu("Damped pendulum",damp_pend1);
     glutAddSubMenu("Circular pendulum",circ_pend1);
     glutAddMenuEntry("Spherical Pendulum",6);
     glutAddMenuEntry("Seconds pendulum",5);
     
     glutAddMenuEntry("EXIT",0);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
 }
 void menu(int value)
{
     if(value==0)
     {
       glutDestroyWindow(w);
       exit(0);
     }
     val1=value;
     //cout<<"val1 "<<val1<<"\n";
     glutPostRedisplay();
 }

 int main(int argc,char *argv[])
 {
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
     
     glutInitWindowPosition(0,0);
     glutInitWindowSize(1000,870);
     w=glutCreateWindow("pendulum");
     //glClearColor(0.0,1.0,0.0,0.0);
     calc_theta(10.0);
      rk4(20,50,30*(pi/180),60*(pi/180),5000,0,20,9.8);
    // cout<<"t is "<<t<<"\n";
     glutReshapeFunc(reshape);
     createMenu();
     glutDisplayFunc(disp);
     glutKeyboardFunc(keybd);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_NORMALIZE);
     glShadeModel(GL_SMOOTH);
     glEnable(GL_COLOR_MATERIAL);
     glutMainLoop();
     return 0;
 }
         
