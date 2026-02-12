#include <stdio.h>
#include <math.h>

// Implement Archimedes algorithm to estimate pi for inscribed/circumscribed 
// polygons with n sides, up to 100, doubling n at each step, and time it.

// This is based on the math/python code given here https://www.craig-wood.com/nick/articles/pi-archimedes/
// This was the only place I found the math needed for this that didn't include pi in the calcs
int main(){
    float edge_squared = 2.0;
    float ret;
    for (int sides = 4; sides <= 128; sides*=2){
        ret = sides * sqrt(edge_squared) / 2;
        printf("%d-agon appoximates pi to: %f\n", sides, ret);
        edge_squared = 2 - 2 * sqrt(1 - edge_squared / 4);
    }
    return 0;
}