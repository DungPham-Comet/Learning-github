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
<<<<<<< HEAD
    printf("Dong nay cho them, ??????");
=======
    printf("Dong nay cho them, DO M NON");
>>>>>>> 9a5776d03fd033959bc84b31efd514ccd1d7cad7
    return 0;
}
