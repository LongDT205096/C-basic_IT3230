/*in circle?*/

#include<stdio.h>

typedef struct point{
    double x,y;
} point_t;

typedef struct circle{
    point_t center;
    double radius;
} circle_t;

int check(point_t *p, circle_t *c){
    double x_c, y_c;
    x_c = p->x - c->center.x;
    y_c = p->y - c->center.y;
    return (x_c * x_c + y_c * y_c <= c->radius * c->radius);
}

int main(){
    point_t p;
    circle_t c;
    double x,y;
    printf("Tao hinh tron:\n");
    printf("Tam: ");
        scanf("%lf %lf",&c.center.x,&c.center.y);
    printf("Ban kinh: ");
        scanf("%lf",&c.radius);
    printf("Nhap diem: ");
        scanf("%lf %lf",&p.x,&p.y);
    if(check(&p,&c))
        printf("Diem nam trong hinh tron");
    else
        printf("Diem nam ngoai hinh tron");
    return 0;
}
