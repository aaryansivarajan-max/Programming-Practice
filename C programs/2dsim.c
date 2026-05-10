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
double calc_dx(struct  initial init,double t){
    double theta_rad = init.anglei * (pi/180.0);
    double dx = init.Xi+(init.Vi *cos(theta_rad) *  t);
    return dx;

}
double calc_dy(struct initial init, double t){
    double theta_rad=init.anglei *(pi / 180.0); // converted angle into  radians since c math libs uses radians
    double Vy =init.Vi * sin(theta_rad); // since dy=vy*t-0.5*g*t*t
    double dy =init.Yi + (Vy*t)-0.5 * g * t * t;
    return dy;
}

int main() {
    struct initial rocket ={50.0,45.0,0.0,2.0};
    printf("PROJECTILE MOTION SIMULATION\n");
    printf("TIME(SECONDS) | X POS(METRE) | Y POS(METRE)\n");
    printf("---------------------------------------------\n");
    for (double t=0; t <= 5.0;t += 0.5){
        double x =calc_dx(rocket,t);
        double y=calc_dy(rocket,t);
        printf("%7.1f  |  %8.2f  | %8.2f\n",t,x,y);
    }
    return 0;
}