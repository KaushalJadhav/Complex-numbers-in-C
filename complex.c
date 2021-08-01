#pragma once
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#define pi=3.14159265358979323846;
struct c                                  // This is the structure complex
{
    double real;
    double imag;
};

struct rarg                              // This is the structure for modulus and argument
{
    double mod;
    double theta;
    char mode[10];
};

int checkstatus(struct rarg a)               //1  param_check ?radian || ?degree
{  int c=0;
    if (a.mode=="degree"||a.mode=="deg")
    c=1;
 return c;
}

void convt2rad(struct rarg *a)             //2    param_check if degree ->radian
{
    if(a->mode=="degree"||a->mode=="deg")
        a->theta=a->theta*pi/180;
    strcpy(a->mode,"degree");
}

void assigncomplex(struct c*comp,double r,double i)     //3   assignment to the struct c *ptr
{
    comp->real=r;
    comp->imag=i;
}

void cassign(struct c*comp,double r,double i)  // alternate
{
    comp->real=r;
    comp->imag=i;
}

struct c copycomplex(struct c c1)                        //4  create copy of struct complex
{
   struct c c2;
   c2.real=c1.real;
   c2.imag=c1.imag;
   return c2;
}

struct c ccopy(struct c c1)                     // alternate
{   
    struct c c2;
   c2.real=c1.real;
   c2.imag=c1.imag;
   return c2;
}

void printcomplex(struct c comp)                    //5   display in std_math_format
{
    printf("%.4lf+i%.4lf",comp.real,comp.imag);
}
 
void cprint (struct c comp)                  //alternate
{
  printf("%.4lf+i%.4lf",comp.real,comp.imag);
}

void printrarg(struct rarg a,int check)             //6 
{   if (check==0)                                   // param check=0 ? display->radian else display->degree
    printf("%.4lf<%.4lf",a.mod,a.theta);
    else printf("%.4lf<%.4lf",a.mod,a.theta*180/pi);
}

struct c addcomplex(struct c c1,struct c c2)     //7  
{
    struct c cadd;
    cadd.real=c1.real+c2.real;
    cadd.imag=c1.imag+c2.imag;
    return cadd;  
}

struct c cadd(struct c c1,struct c c2)     // alternate
{
    struct c c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return c2;  
}

struct c subcomplex(struct c c1,struct c c2)   //8  subtracts c2 from c1
{
    struct c csub;
    csub.real=c1.real-c2.real;
    csub.imag=c1.imag-c2.imag;
    return csub;
}

struct c csub(struct c c1,struct c c2)         // alternate
{
    struct c s;
    s.real=c1.real-c2.real;
    s.imag=c1.imag-c2.imag;
    return s;
}
struct c negatecomplex(struct c c1)         //9    additive inverse of complex number
{
    struct c c2,c3;
    assigncomplex(&c2,0,0);
    c3=subcomplex(c2,c1);
    return c3;
}

struct c cnegate(struct c c1)        // alternate
{
   struct c c2,c3;
    assigncomplex(&c2,0,0);
    c3=subcomplex(c2,c1);
    return c3;
}

struct c mulcomplex(struct c c1,struct c c2)   //10
{
    struct c cmul;
    cmul.real=c1.real*c2.real-c1.imag*c1.real;
    cmul.imag=c1.real*c2.imag+c1.imag*c2.real;
    return cmul;
}

struct c cmultiply(struct c c1,struct c c2)   //alternate
{
   struct c cmul;
    cmul.real=c1.real*c2.real-c1.imag*c1.real;
    cmul.imag=c1.real*c2.imag+c1.imag*c2.real;
    return cmul;
}

struct c scale_complex(struct c c1,double n)    //11    equivalent to cassign(&c2,n,0); mulcomplex(c1,c2)
{    struct c c2;
    c2.real=c1.real*n;
    c2.imag=c1.imag*n;
    return c2;
}

struct c cscale(struct c c1,double n)    //alternate
{
    struct c c2;
    c2.real=c1.real*n;
    c2.imag=c1.imag*n;
    return c2;
}

struct c congcomplex(struct c c1)            //12     congugate of complex number
{
    struct c congugate;
    congugate.real=c1.real;
    congugate.imag=-c1.imag;
    return congugate;
}

struct c ccong(struct c c1)            //alternate
{
    struct c congugate;
    congugate.real=c1.real;
    congugate.imag=-c1.imag;
    return congugate;
}

double absolcomplex(struct c c1)          //13     modulus of complex number
{
    return sqrtl(pow(c1.real,2)+pow(c1.imag,2));
}

double cabsol(struct c c1)          //alternate
{
    double absolute;
    absolute=sqrtl(pow(c1.real,2)+pow(c1.imag,2));
    return absolute;
}

struct c divcomplex(struct c c1,struct c c2)   //14  returns c1/c2
{
    struct c cdiv;
    double a;
    a=absolcomplex(c2);
    if (a!=0)
    { 
     cdiv=mulcomplex(c1,congcomplex(c2));
     cdiv.real=cdiv.real/(a*a);
     cdiv.imag=cdiv.imag/(a*a);
    }
    else {cdiv.real=(double)(INFINITY);cdiv.imag=(double)(INFINITY);}
    return cdiv;
}

struct c cdiv(struct c c1,struct c c2)   //alternate
{
    struct c cdiv;
    double a;
    a=absolcomplex(c2);
    if (a!=0)
    { 
     cdiv=mulcomplex(c1,congcomplex(c2));
     cdiv.real=cdiv.real/(a*a);
     cdiv.imag=cdiv.imag/(a*a);
    }
    else {cdiv.real=(double)(INFINITY);cdiv.imag=(double)(INFINITY);}
    return cdiv;
}

struct rarg convtcomplex ( struct c c1)         //15    
{                                                      //convert the complex number
    struct rarg a;                                     // into modulus and argument
    a.mod=absolcomplex(c1);                            // with argument in radians
    a.theta=atan2(c1.imag,c1.real);
    strcpy(a.mode,"rad");    // WWWHHHYYY????
    return a;
}

struct rarg convt_2_complex ( struct c c1)      //16    
{                                                      //convert the complex number
    struct rarg a;                                     // into modulus and argument
    a.mod=absolcomplex(c1);                            //with argument in degrees
    a.theta=atan2(c1.imag,c1.real);
    a.theta=a.theta*180/pi;
    strcpy(a.mode,"degrees");
     return a;
}

struct c convtrarg( struct rarg a)           //17
{   if(a.mode=="degrees")
       a.theta=a.theta*pi/180;
    struct c c1;
    c1.real=a.mod*cos(a.theta);
    c1.imag=a.mod*sin(a.theta);
    return c1;
}

void assignrarg(struct rarg *a,double r,double t,int check)     //18
{ if(check==0)
   {a->mod=r;
    a->theta=t;} 
 else
   {a->mod=r;
    a->theta=t*pi/180;}
}

struct c geteuler(double theta,int check)           //19
{   struct c c1;
    if (check!=0)
    theta=theta*pi/180;
    c1.real=cos(theta);
    c1.imag=sin(theta);
    return c1;
}

struct c lncomplex(struct c c1)              //20
{
    struct c clog;
    if (absolcomplex(clog)!=0)
    {clog.real=log(absolcomplex(c1));
    clog.imag=atan2(c1.imag,c1.real);}
    else {clog.real=(double)('\0');clog.imag=(double)('\0');}
    return clog;
}

struct c lnc(struct c c1)              //alternate
{
    struct c clog;
    if (absolcomplex(clog)!=0)
    {clog.real=log(absolcomplex(c1));
    clog.imag=atan2(c1.imag,c1.real);}
    else {clog.real=(double)('\0');clog.imag=(double)('\0');}
    return clog;
}

struct c logcomplex(struct c c1,double n)    //21
{
    struct c clog;
    if (absolcomplex(clog)!=0)
    {clog.real=(log(absolcomplex(c1))/log(n));
    clog.imag=atan2(c1.imag,c1.real)/log(n);}
    else {clog.real=(double)('\0');clog.imag=(double)('\0');}
    return clog;
}

struct c logc(struct c c1,double n)    //alternate
{
    struct c clog;
    if (absolcomplex(clog)!=0)
    {clog.real=(log(absolcomplex(c1))/log(n));
    clog.imag=atan2(c1.imag,c1.real)/log(n);}
    else {clog.real=(double)('\0');clog.imag=(double)('\0');}
    return clog;
}

struct c powcomplex(struct c c1,double n)         //22
{
    struct rarg a;
    struct c cpow;
    a=convtcomplex(c1);
    a.mod=pow(a.mod,n);
    a.theta=n*a.theta;
    cpow=convtrarg(a);
    return cpow;
}

struct c powc(struct c c1,double n)         //alternate
{
    struct rarg a;
    struct c cpow;
    a=convtcomplex(c1);
    a.mod=pow(a.mod,n);
    a.theta=n*a.theta;
    cpow=convtrarg(a);
    return cpow;
}

struct c expcomplex( struct c c1)            //23
{
    struct c c2,c3,cexp;
    c2.real=exp(c1.real);c2.imag=0;
    c3=geteuler(c1.imag,0);
    cexp=mulcomplex(c2,c3);
    return cexp;
}

struct c expc( struct c c1)            //alternate
{
    struct c c2,c3,cexp;
    c2.real=exp(c1.real);c2.imag=0;
    c3=geteuler(c1.imag,0);
    cexp=mulcomplex(c2,c3);
    return cexp;
}

struct c pow2complex(struct c c1,struct c c2)     //24
{
   struct c c3;
   c3=expcomplex(mulcomplex(c2,lncomplex(c1)));
}

struct c cpowc(struct c c1,struct c c2)     //alternate
{
   struct c c3;
   c3=expcomplex(mulcomplex(c2,lncomplex(c1)));
}

struct c sqrcomplex(struct c c1)            //25
{
    return powcomplex(c1,2);
}

struct c sqrc(struct c c1)            //alternate
{
    return powcomplex(c1,2);
}

struct c sqrtcomplex(struct c c1)          //26
{
    return powcomplex(c1,0.5);
}

struct c sqrtc(struct c c1)          //alternate
{
    return powcomplex(c1,0.5);
}

void getroots(struct c *c1,struct c *c2,double a,double b,double c)      //27
{
   if(b*b-4*a*c<0)
   {
       c1->real=-b/(2*a);
       c1->imag=sqrt(4*a*c-b*b)/(2*a);
   }
   if(b*b-4*a*c>0)
   {
       c1->real=-b/(2*a)+sqrt(-4*a*c+b*b)/(2*a);
       c1->imag=0;
   }
   *c2=congcomplex(*c1);
}

struct c discriminant(struct c c1,struct c c2,struct c c3)         //28
{
    struct c d;
    d=subcomplex(sqrcomplex(c2),mulcomplex(c2,c3));
    return d;
}

struct c getdelta(struct c c1,struct c c2,struct c c3)         //alternate
{
    struct c d;
    d=subcomplex(sqrcomplex(c2),mulcomplex(c2,c3));
    return d;
}

void getrootsc(struct c *c1,struct c *c2,struct c a,struct c b,struct c d)    //29
{
    *c1=addcomplex(negatecomplex(b),discriminant(a,b,d));
    *c1=divcomplex(*c1,scale_complex(a,2));
    *c2=negatecomplex(addcomplex(b,discriminant(a,b,d)));
    *c2=divcomplex(*c2,scale_complex(a,2));
}
struct c rotatecomplex(struct c c1,double t,int check)       //30
{   
    struct rarg a;
    struct c c2;
    if (check!=0)
    t=t*pi/180;
    a=convtcomplex(c1);
    a.theta=a.theta+t;
    c2=convtrarg(a);
    return c2;
}

struct c crotate(struct c c1,double t,int check)       //30
{   
    struct rarg a;
    struct c c2;
    if (check!=0)
    t=t*pi/180;
    a=convtcomplex(c1);
    a.theta=a.theta+t;
    c2=convtrarg(a);
    return c2;
}

double distcomplex (struct c c1,struct c c2)     //31
{
    double d,d1,d2;
    d1=pow(c1.real-c2.real,2);
    d2=pow(c1.imag-c2.imag,2);
    d=sqrt(d1+d2);
}

double cdist (struct c c1,struct c c2)           //alternate
{
    double d,d1,d2;
    d1=pow(c1.real-c2.real,2);
    d2=pow(c1.imag-c2.imag,2);
    d=sqrt(d1+d2);
}

struct c getmid(struct c c1,struct c c2)
{
    struct c cmid;
    cmid=addcomplex(c1,c2);
    cmid=scale_complex(cmid,0.5);
    return cmid;
}

struct c divide_line(struct c c1,struct c c2,double x,double y)
{   struct c cr,c3; 
    if(y==0.0)
    {
        if(x==0.0) y=x=0.0;
        else y=1-x;
    } 
    cr=cadd(cscale(c1,x),cscale(c2,y));
    cassign(&c3,x+y,0);
    cr=cdiv(cr,c3);
    return c3;
}
