#include<stdio.h>
#include<math.h>
#define PI 3.1416   
int main(){
    float r;
    printf("Nhap ban kinh duong tron: ");
    scanf("%f", &r);
    float s,cv;
    s=PI * r * r;
    cv=2*PI*r;
    printf("Chu vi duong tron la: %f\n",cv);
    printf("Dien tich hinh tron la: %f", s);
    printf("Dong nay cho them, DO M NON");
    return 0;
}
