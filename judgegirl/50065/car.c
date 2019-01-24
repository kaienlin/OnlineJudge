#include "car.h"

CarStatusList carSimulation(CarStatus car, Command commands[]) {
    CarStatusList ret;
    ret.num = 0;
    int cmd_i = 0, cmd;
    while (1) {
        cmd = commands[cmd_i].t;
        int v = commands[cmd_i].v;
        if ( cmd == 0 )
            return ret;
        else if ( cmd == 1 ) {
            car.g += v;
        } else if ( cmd == 2 ) {
            if ( car.g < v )
                return ret;
            car.x += v;
            car.g -= v;
            ret.status[ret.num++] = car;
        } else if ( cmd == 3 ) {
            if ( car.g < v )
                return ret;
            car.x -= v;
            car.g -= v;
            ret.status[ret.num++] = car;
        } else if ( cmd == 4 ) {
            if ( car.g < v )
                return ret;
            car.y += v;
            car.g -= v;
            ret.status[ret.num++] = car;
        } else if ( cmd == 5 ) {
            if ( car.g < v )
                return ret;
            car.y -= v;
            car.g -= v;
            ret.status[ret.num++] = car;
        }
        cmd_i++;
    }
}