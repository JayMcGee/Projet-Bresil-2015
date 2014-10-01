/* 
 * File:   main.c
 * Author: Jeep
 *
 * Created on 30 septembre 2014, 22:19
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "system/common/sys_module.h"

/*
 * 
 */
int main(void ) {

    /* Initialize all MPLAB^^®^^ Harmony modules, including application(s). */
    SYS_Initialize( NULL );

    while ( true )
    {
        /* Maintain the state machines of all MPLAB^^®^^ Harmony modules. */
        SYS_Tasks( );
    }

    /* Execution should not come here during normal operation */
    return ( EXIT_FAILURE );
}

