/*
============================================================================
Name : Question-29
Author : Pratyasa Ray
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 1st sept, 2023.
============================================================================
*/
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param param;


    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current scheduling policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }


    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to SCHED_FIFO\n");
    return 0;
}
