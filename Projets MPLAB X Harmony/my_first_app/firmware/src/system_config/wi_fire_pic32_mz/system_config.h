/* 
 * File:   system_config.h
 * Author: Jeep
 *
 * Created on 30 septembre 2014, 22:30
 */

#ifndef SYSTEM_CONFIG_H
#define	SYSTEM_CONFIG_H

/* Previens les messages de PLIB superflus */
#define _PLIB_UNSUPPORTED

/* Options de configuration du pilote de timer */
#define DRV_TMR_INSTANCES_NUMBER            1
#define DRV_TMR_CLIENTS_NUMBER              1
#define DRV_TMR_INTERRUPT_MODE              false
#define DRV_TMR_COUNT_WIDTH                 16

/* Service Système pour le timer. Communique avec le pilote configuré plus haut. */
#define SYS_TMR_MAX_PERIODIC_EVENTS         1
#define SYS_TMR_MAX_DELAY_EVENTS            1
#define SYS_TMR_MAX_CLIENT_OBJECTS          1
#define SYS_TMR_UNIT_RESOLUTION             1000000
#define SYS_TMR_FREQUENCY_TOLERANCE         10
#define SYS_TMR_CLIENT_TOLERANCE            10

/* Configuration du service d'horloge */
#define SYS_CLK_PRIMARY_CLOCK               (200000000ul)   //200MHz
#define SYS_CLK_CONFIG_PRIMARY_XTAL         (24000000ul)    //24MHz
#define SYS_CLK_CONFIG_SECONDARY_XTAL       (0ul)           //Non utilisé
#define SYS_CLK_CONFIG_SYSPLL_INP_DIVISOR   3
#define SYS_CLK_CONFIGBIT_USBPLL_ENABLE     false
#define SYS_CLK_CONFIGBIT_USBPLL_DIVISOR    2
#define SYS_CLK_CONFIG_FREQ_ERROR_LIMIT     10

#define SYS_DEVCON_PIC32MX_MAX_PB_FREQ      SYS_CLK_PRIMARY_CLOCK

#endif	/* SYSTEM_CONFIG_H */

