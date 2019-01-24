#include "reservation.h"
#include <stdlib.h>

/* Be careful of the following situations:
 *    1. insert on the head of linked list
 *    2. insert on the emtpy list 
 */  
Reservation *new_reserve(int np, int start, int end) {
    Reservation *ret = (Reservation *)malloc(sizeof(Reservation));
    ret->nP = np;
    ret->StartTime = start;
    ret->EndTime = end;
    ret->next = NULL;
    return ret;
}
int ReserveRoom(RoomStatus list[], int n, int nP, int StartTime, int EndTime) {
    for ( int i = 0; i < n; i++) {
        if ( list[i].capacity < nP )
            continue;
        Reservation *tail = list[i].reservation;
        if ( tail == NULL ) {
            list[i].reservation = new_reserve(nP, StartTime, EndTime);
            return 1;
        } else {
            Reservation *prev = NULL;
            while ( tail != NULL && tail->StartTime < StartTime ) {
                prev = tail;
                tail = tail->next;
            }
            if ( prev == NULL ) {
                if ( EndTime <= tail->StartTime ) {
                    list[i].reservation = new_reserve(nP, StartTime, EndTime);
                    list[i].reservation->next = tail;
                    return 1;
                } else
                    continue;
            }
            if ( StartTime >= prev->EndTime && EndTime <= (tail == NULL ? __INT_MAX__ : tail->StartTime) ) {
                prev->next = new_reserve(nP, StartTime, EndTime);
                prev->next->next = tail;
                return 1;
            } else
                continue;
        }
    }
    return 0;
}