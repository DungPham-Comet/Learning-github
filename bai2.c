#include<stdio.h>
#include<math.h>
#define PI 3.1416
int main(){
    float n;
    printf("Nhap gia tri: ");
    scanf("%f",&n);
    printf("Dien tich hinh tron co chu vi %f la: %f\n",n, PI * PI * n/(2*PI));
    printf("Dien tich hinh vuong co chu vi %f la: %f\n",n,(n/4) * (n/4));
    printf("Dien tich tam giac deu co chu vi %f la: %f",n, (n/3) * pow(3,0.5)/4);
    return 0;
}