/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************
#include <proc/p32mx795f512l.h>
#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
static int contaTicks;
//probablemente estos static int sean extern int en el archivo comunicacion
static int avance = 20;
static int tiempoIny = 2000;
//sincroFlag variable global creada en el archivo de sincronismo
//una vez creada ahi, sacar de aca. (extern bool sincroFlag)
static bool sincroFlag = false;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    inyeccionInit();
    DRV_TMR0_Start();
    DRV_TMR1_Start();
    DRV_TMR2_Start();
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
       
        
            if (appInitialized)
            {
            
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }
        
        case APP_STATE_SERVICE_TASKS:
        {
        
            secuenciaIny(avance , tiempoIny);
            
            break;
        }

        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void secuenciaIny(avance , tiempoIny)
{
    //sacar de aca la variable rpm una vez integrado el source deteccion de dientes
    //esta variable va a ser global y la actualiza deteccion de dientes
    int rpm = 700;
    float avanceAux;
    float ticksPorVuelta;
    float ticksPorGrados;
    static int ticksAPMS1;
    static int ticksAPMS2;
    static int ticksAPMS3;
    static int ticksAPMS4;
    static int ticksAvancePMS1;
    static int ticksAvancePMS2;
    static int ticksAvancePMS3;
    static int ticksAvancePMS4;
    static bool activo = false;
    static int stage = 0;
    
    switch(stage)
    {
        case 0://init calculo de valores para los disparos
            ticksPorVuelta = ((60000000) / (rpm * 10));
            ticksPorGrados = ((ticksPorVuelta) / (360));
            if(sincroFlag)
            {
                contaTicks = 0;
                avanceAux = avance * ticksPorGrados;
                ticksAPMS1 = REF_PMS1 * ticksPorGrados;
                ticksAPMS2 = REF_PMS2 * ticksPorGrados;
                ticksAPMS3 = REF_PMS3 * ticksPorGrados;
                ticksAPMS4 = REF_PMS4 * ticksPorGrados;
                ticksAvancePMS1 = (ticksAPMS1 - avanceAux);
                ticksAvancePMS2 = (ticksAPMS2 - avanceAux);
                ticksAvancePMS3 = (ticksAPMS3 - avanceAux);
                ticksAvancePMS4 = (ticksAPMS4 - avanceAux);  
                //sincroFlag = false;
                stage++;
            }
            break;
        case 1://inyeccion cilindro 1
            if(contaTicks >= ticksAvancePMS1)
            {
                activo = pulsoIny1(tiempoIny);
                if(activo)
                {
                    stage++;
                }
            }
            break;
        case 2://inyeccion cilindro 3
            if(contaTicks >= ticksAvancePMS3)
            {
                activo = pulsoIny3(tiempoIny);
                if(activo)
                {
                    stage++;
                }
            }
            break;
        case 3://inyeccion cilindro 4
            if(contaTicks >= ticksAvancePMS4)
            {
                activo = pulsoIny4(tiempoIny);
                if(activo)
                {
                    stage++;
                }
            }
            break;
        case 4://inyeccion cilindro 2
            if(contaTicks >= ticksAvancePMS2)
            {
                activo = pulsoIny2(tiempoIny);
                if(activo)
                {
                    //sincroFlag = false;
                    stage = 0;
                }
            }            
            break;
        default:
            break;
    }
}

void ticks10usSincro()
{
    contaTicks++;
}
/*******************************************************************************
 End of File
 */
