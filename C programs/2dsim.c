#include <stdio.h>
#include <math.h>

const double g=9.8; //defined gravity
const double pi=3.14159265; // defined pi

struct projectile {
    double x;   //  position of projectile in x and y axis
    double y;

    double v; //initial velocity
    double vx;  //velocity in 2d components
    double vy;

    double ax;  // acceleration in two components in x and y axis
    double ay;


    double anglei;

    double mass;  // fixed mass property

    double drag_coefficient;  // drag coefficiant
};

double accel_mag(struct projectile rocket) { 
     double a_mag =sqrt( rocket.ax * rocket.ax +rocket.ay * rocket.ay) ;
     return a_mag ;
};
double force(struct projectile rocket,double a_mag){
    double F_mag = rocket.mass * a_mag;
    return F_mag ;
};

double speed(struct projectile rocket){
    double v_mag= sqrt(rocket.vx * rocket.vx + rocket.vy *rocket.vy );
    return v_mag;
};

int main() {
    double dt= 0.01 ;
    double t=0;
    struct projectile rocket ;
    printf("enter your initial position in x \n");
    scanf("%lf",   &rocket.x  );
    printf("enter your initial position in y \n");
    scanf("%lf",   &rocket.y  );
    printf("enter your initial velocity\n");
    scanf("%lf",   &rocket.v );
    printf("Enter launch angle in degrees:\n");
    scanf("%lf", &rocket.anglei);
    double theta_rad = rocket.anglei * (pi / 180.0);
    rocket.vx = rocket.v * cos(theta_rad);
    rocket.vy = rocket.v * sin(theta_rad);
    rocket.ax = 0;
    rocket.ay = -g;
    printf("vx = %lf\n", rocket.vx);
    printf("vy = %lf\n", rocket.vy);


    while (rocket.y >= 0) {
        rocket.vx = rocket.vx + rocket.ax * dt ;
        rocket.vy = rocket.vy + rocket.ay * dt ;
        rocket.x = rocket.x + rocket.vx * dt ;
        rocket.y = rocket.y + rocket.vy * dt ;
        t = t + dt ;
        printf("TIME     | X POS     | Y POS     | VX        | VY\n      |");
        printf("t=%.2lf  | x=%.2lf   | y=%.2lf   |vx=%.2lf   | vy=%.2lf  |\n",  t, rocket.x, rocket.y, rocket.vx, rocket.vy);

    }
    
    
}