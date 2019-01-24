#include "elevator.h"
#include <stdlib.h>
#include <stdbool.h>

struct Elevator {
    int F, u, d, pos, u_cnt, d_cnt;
    bool been[MAXF + 1];
};
Elevator* newElevator(int u, int d, int F) {
    Elevator *ret = (Elevator*)calloc(1, sizeof(Elevator));
    ret->u = u;
    ret->d = d;
    ret->F = F;
    ret->pos = 1;
    ret->been[1] = true;
    return ret;
}
int up(Elevator* elevator) {
    if ( elevator->pos + elevator->u > elevator->F ) {
        elevator->u_cnt++;
        elevator->d_cnt = 0;
        if ( elevator->u_cnt >= 4 )
            return -1;
        return 0;
    } else {
        elevator->pos += elevator->u;
        elevator->been[elevator->pos] = true;
        elevator->u_cnt = elevator->d_cnt = 0;
        return 1;
    }
}
int down(Elevator* elevator) {
    if ( elevator->pos - elevator->d < 1 ) {
        elevator->d_cnt++;
        elevator->u_cnt = 0;
        if ( elevator->d_cnt >= 4 )
            return -1;
        return 0;
    } else {
        elevator->pos -= elevator->d;
        elevator->been[elevator->pos] = true;
        elevator->u_cnt = elevator->d_cnt = 0;
        return 1;
    }
}
int visited(struct Elevator* elevator, int floor) {
    if ( elevator->been[floor] )
        return 1;
    return 0;
}
int getPosition(struct Elevator* elevator) {
    return elevator->pos;
}