#include <stdio.h>
#include <math.h>
struct par{
	int a;
	int b;
	int c;
	int d;
}para;
 double fun(struct par para,double x)
 {
	 double fx;
	 fx = para.a*x*x*x + para.b*x*x + para.c*x + para.d;
	 return fx;
}
 double integral(double(*fp)(struct par,double), double x, double y,double delta)
 {
	 double s_0,s_1,s_2 ,c;
	 c = (x + y) / 2;
	 s_0 = 0.5*((fp(para, x) + fp(para, y))*fabs(x - y));
	 s_1 = 0.5*((fp(para, x) + fp(para, c))*fabs(x - c));
	 s_2= 0.5*((fp(para, c) + fp(para, y))*fabs(c - y));
	 if ((s_0 - s_1 - s_2) < delta)
		 return s_1 + s_2;
	 else
		 return integral(fp,x,c,delta)+integral(fp,c,y,delta);
 }
int main()
{
	double x, y,result,delta=1e-8;
	double(*fp)(struct par,double);
	fp = fun;
	printf("�к���f(x)=a*x^3+b*x^2+c*x+d,");
	printf("������a,b,c,d��ֵ:\n");
	scanf("%d%d%d%d", &para.a, &para.b, &para.c, &para.d);
	printf("����������ֵ�����:");
	scanf("%lf%lf", &x, &y);
	result=integral(fp, x, y, delta);
	printf("�ú�����(%lf,%lf)�Ķ�������%lf.\n", x, y, result);
	return 0;

}
