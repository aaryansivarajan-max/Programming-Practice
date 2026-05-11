#include <stdio.h>
#include <math.h>

const double g=9.8; //defined gravity
const double pi=3.14159265; // defined pi
struct initial {
    double Vi; //initial velocity
    double anglei; //initial angle
    double t; //t=time
    double Xi;
    double Yi;
};
double calc_x(struct  initial init,double t){
    double theta_rad = init.anglei * (pi/180.0);
    double x = init.Xi+(init.Vi *cos(theta_rad) *  t);
    return x;

}
double calc_y(struct initial init, double t){
    double theta_rad=init.anglei *(pi / 180.0); // converted angle into  radians since c math libs uses radians
    double Vy =init.Vi * sin(theta_rad); // since dy=vy*t-0.5*g*t*t
    double y =init.Yi + (Vy*t)-0.5 * g * t * t;
    return y;
}

double max_height(struct initial rocket){
    double theta_rad = rocket.anglei * (pi / 180);
    double Vy_i = rocket.Vi * sin(theta_rad);
    return rocket.Yi + (pow(Vy_i,2) / (2 * g));

}
double max_range(struct initial rocket){
    double theta_rad=rocket.anglei * (pi / 180);
    double Vx = rocket.Vi * cos(theta_rad);
    double Vy = rocket.Vi * sin(theta_rad);
    double discriminant = sqrt(pow(Vy,2) + (2 * g * rocket.Yi));
    return rocket.Xi + (Vx / g) * (Vy + discriminant);

}

int main() {
    struct initial rocket ={50.0,45.0,0.0,2.0};
    printf("PROJECTILE MOTION SIMULATION\n");
    printf("TIME(SECONDS) | X POS(METRE) | Y POS(METRE)\n");
    printf("---------------------------------------------\n");
    for (double t=0; t <= 10.0;t += 0.5){
        double x =calc_x(rocket,t);
        double y=calc_y(rocket,t);
        if (y < 0)break;
        printf("%7.1f  |  %8.2f  | %8.2f\n",t,x,y);
    }

    printf("\n---Ballistics Report---\n");
    printf("Max Altitude : %.2f\n",max_height(rocket));
    printf("Impact Range : %.2f\n",max_range(rocket));
        return 0;
}
