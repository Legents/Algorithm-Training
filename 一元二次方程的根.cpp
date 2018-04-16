#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	float a1,a2;
	scanf("%f%f%f",&a,&b,&c);
	if(a==0&&b==0&&c==0){
		printf("Zero Equation");
		return 0; 
	}
	else if(a==0&&b==0&&c!=0){
		printf("Not An Equation");
		return 0; 
	}
	else if(a==0){
		printf("%.2f",-c/b);
		return 0;
	}
	float d=b*b-4.0*a*c;
	 if(d>0){
		printf("%.2f\n%.2f",(-b+sqrt(d))/(2.0*a),(-b-sqrt(d))/(2.0*a));
		return 0;
	}
	else if(d==0){
		printf("%.2f",-b/(2.0*a));
		return 0;
	}
	else if(d<0){
		printf("%.2f+%.2fi\n",b!=0?(-b/(2.0*a)):0,sqrt(-d)/(2.0*a));
		//printf("\n");
		printf("%.2f-%.2fi",b!=0?(-b/(2.0*a)):0,sqrt(-d)/(2.0*a));
		//printf("\n");
		return 0;
	}
	
	return 0;
}
