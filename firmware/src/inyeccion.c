/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "inyeccion.h"
#include "generales.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
int global_data;
static int tickActualIny = 0;
static int tickActualRpm = 0;


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */
static int ExampleLocalFunction(int param1, int param2) {
    return 0;
}


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}

void inyeccionInit()
{
    INY1_TRIS = OUTPUT;
    INY2_TRIS = OUTPUT;
    INY3_TRIS = OUTPUT;
    INY4_TRIS = OUTPUT;
    BANKA_TRIS = OUTPUT;
    BANKB_TRIS = OUTPUT;
#ifdef OPEN_DRAIN
    INY1_OD = TRUE;
    INY2_OD = TRUE;
    INY3_OD = TRUE;
    INY4_OD = TRUE;
    BANKA_OD = TRUE;
    BANKB_OD = TRUE;
#endif
    
}

bool pulsoIny1(int tiempo)
{
    static bool estado = false;
    static bool burstRunning = false;
    static int stage = 0;
    switch(stage)
    {
        case 0:
            estado = false;
            burstRunning = pulsoBancoA(tiempo);
            if(burstRunning)
            {
                INY1_OUTPUT = HIGH;
                
            }
            
            if(!burstRunning)
            {
                INY1_OUTPUT = LOW;
                stage++;
            }
            break;
        case 1:
            estado = true;
            stage = 0;
            break;
        case 2:
            estado = false;
            stage = 0;
        default:
            break;
    }
    return estado;
}
bool pulsoIny2(int tiempo)
{
    static bool estado = false;
    static bool burstRunning = false;
    static int stage = 0;
    switch(stage)
    {
        case 0:
            estado = false;
            burstRunning = pulsoBancoA(tiempo);
            if(burstRunning)
            {
                INY2_OUTPUT = HIGH;
                
            }
            
            if(!burstRunning)
            {
                INY2_OUTPUT = LOW;
                stage++;
            }
            break;
        case 1:
            estado = true;
            stage = 0;
            break;
        case 2:
            estado = false;
            stage = 0;
        default:
            break;
    }
    return estado;
}
bool pulsoIny3(int tiempo)
{
    static bool estado = false;
    static bool burstRunning = false;
    static int stage = 0;
    switch(stage)
    {
        case 0:
            estado = false;
            burstRunning = pulsoBancoB(tiempo);
            if(burstRunning)
            {
                INY3_OUTPUT = HIGH;
                
            }
            
            if(!burstRunning)
            {
                INY3_OUTPUT = LOW;
                stage++;
            }
            break;
        case 1:
            estado = true;
            stage = 0;
            break;
        case 2:
            estado = false;
            stage = 0;
        default:
            break;
    }
    return estado;
}
bool pulsoIny4(int tiempo)
{
    static bool estado = false;
    static bool burstRunning = false;
    static int stage = 0;
    switch(stage)
    {
        case 0:
            estado = false;
            burstRunning = pulsoBancoB(tiempo);
            if(burstRunning)
            {
                INY4_OUTPUT = HIGH;
                
            }
            
            if(!burstRunning)
            {
                INY4_OUTPUT = LOW;
                stage++;
            }
            break;
        case 1:
            estado = true;
            stage = 0;
            break;
        case 2:
            estado = false;
            stage = 0;
        default:
            break;
    }
    return estado;
}

//void pulsoIny2(int tiempo)
//{
//    static bool burstRunning = false;
//    if(burstRunning)
//    {
//        INY2_OUTPUT = HIGH;
//    }
//    burstRunning = pulsoBancoA(tiempo);
//    if(!burstRunning)
//    {
//        INY2_OUTPUT = LOW;
//    }  
//}
//void pulsoIny3(int tiempo)
//{
//    static bool burstRunning = false;
//    if(burstRunning)
//    {
//        INY3_OUTPUT = HIGH;
//    }
//    burstRunning = pulsoBancoB(tiempo);
//    if(!burstRunning)
//    {
//        INY3_OUTPUT = LOW;
//    }  
//}
//void pulsoIny4(int tiempo)
//{
//    static bool burstRunning = false;
//    if(burstRunning)
//    {
//        INY4_OUTPUT = HIGH;
//    }
//    burstRunning = pulsoBancoB(tiempo);
//    if(!burstRunning)
//    {
//        INY4_OUTPUT = LOW;
//    }  
//}
bool pulsoBancoA(int tiempo)
{
    static int stage = 0;
    static int tiempoAcumulado = 0;
    static int duracionVariable;
    static bool status = false;
    int duty, dutyNeg, dutyPos;
    int aux, periodo, duracion, tiempoAux;
    switch(stage)
    {
        case 0:
            tickActualIny = 0;
            tiempoAcumulado = 0;
            //tiempoAux = (tiempo / 10);//pasado a ticks de 10 us.
            status = true;
            //LATCbits.LATC15 = 1;
            stage++;
            break;
        case 1:
            aux = 0;
            duracion = 57;  //valor multiplicado por 10us
            periodo = 800; //periodo para 50kHz con clock de 40MHz
            dutyPos = 32;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            aux = (duty*periodo)/100;
            DRV_TMR1_PeriodValueSet(periodo);
            DRV_OC0_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            DRV_OC0_Start();
            if(tickActualIny > duracion)
            {
                stage++;
                tickActualIny = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
            }            
            break;
        case 2:
            aux = 0;
            duracion = 55;
            periodo = 800;
            dutyPos = 83;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            aux = (duty*periodo)/100;
            DRV_OC0_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            if(tickActualIny > duracion)
            {
                stage++;
                tickActualIny = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
            }
            break;
        case 3:
            aux = 0;
            duracion = 54;
            tiempoAux = (tiempo / 10);//pasado a ticks de 10 us.
            duracionVariable = tiempoAux - tiempoAcumulado;
            periodo = 2000;//periodo para 20kHz con clock de 40MHz
            dutyPos = 90;//90;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            DRV_TMR1_PeriodValueSet(periodo);
            aux = (duty*periodo)/100;
            DRV_OC0_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            if(tickActualIny > duracionVariable)
            {
                stage++;
                tickActualIny = 0;
                DRV_TMR1_PeriodValueSet(800);//importante para que tenga tiempo 
                tiempoAcumulado = tiempoAcumulado + duracionVariable;//de setear el periodo y no se cuelgue
            }                                
            break;
        case 4:
            //Posiblemente haya que sacar este case
            //Corresponderia al apagado del Transitor de referencia
            DRV_OC0_Stop();
            duracion = 20;
            //TRISDbits.TRISD1 = 0;
            BANKA_OUTPUT = 0;//LATDbits.LATD1 = 0;//LATDbits.LATD1 = 1;            
            if(tickActualIny > duracion)
            {
                stage = 0; //si anda sacar case 5:
                tickActualIny = 0;
                BANKA_OUTPUT = 0;//LATDbits.LATD1 = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
                status = false;
                //LATCbits.LATC15 = 0;
            }
            break;
        case 5://case para realizar pruebas, no iria en el definitivo.
            //status = false;
            if(tickActualIny > (3160 - tiempoAcumulado))
            {
                stage = 0;
                tickActualIny = 0;
                tiempoAcumulado = 0;
                
            }
            break;
        default:
            break;
    }
    return status;
}
bool pulsoBancoB(int tiempo)
{
    static int stage = 0;
    static int tiempoAcumulado = 0;
    static int duracionVariable;
    static bool status = false;
    int duty, dutyNeg, dutyPos;
    int aux, periodo, duracion, tiempoAux;
    switch(stage)
    {
        case 0:
            tickActualIny = 0;
            tiempoAcumulado = 0;
            //tiempoAux = (tiempo / 10);//pasado a ticks de 10 us.
            status = true;
            //LATCbits.LATC15 = 1;
            stage++;
            break;
        case 1:
            aux = 0;
            duracion = 57;  //valor multiplicado por 10us
            periodo = 800; //periodo para 50kHz con clock de 40MHz
            dutyPos = 32;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            aux = (duty*periodo)/100;
            DRV_TMR1_PeriodValueSet(periodo);
            DRV_OC1_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            DRV_OC1_Start();
            if(tickActualIny > duracion)
            {
                stage++;
                tickActualIny = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
            }            
            break;
        case 2:
            aux = 0;
            duracion = 55;
            periodo = 800;
            dutyPos = 83;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            aux = (duty*periodo)/100;
            DRV_OC1_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            if(tickActualIny > duracion)
            {
                stage++;
                tickActualIny = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
            }
            break;
        case 3:
            aux = 0;
            duracion = 54;
            tiempoAux = (tiempo / 10);//pasado a ticks de 10 us.
            duracionVariable = tiempoAux - tiempoAcumulado;
            periodo = 2000;//periodo para 20kHz con clock de 40MHz
            dutyPos = 90;//90;
            dutyNeg = (100 - dutyPos);
            duty = dutyPos; //dutyNeg;
            DRV_TMR1_PeriodValueSet(periodo);
            aux = (duty*periodo)/100;
            DRV_OC1_PulseWidthSet(aux);
            //DRV_OC0_Duty(aux);
            if(tickActualIny > duracionVariable)
            {
                stage++;
                tickActualIny = 0;
                DRV_TMR1_PeriodValueSet(800);//importante para que tenga tiempo 
                tiempoAcumulado = tiempoAcumulado + duracionVariable;//de setear el periodo y no se cuelgue
            }                                
            break;
        case 4:
            //Posiblemente haya que sacar este case
            //Corresponderia al apagado del Transitor de referencia
            DRV_OC1_Stop();
            duracion = 20;
            //TRISDbits.TRISD1 = 0;
            BANKA_OUTPUT = 0;//LATDbits.LATD1 = 0;//LATDbits.LATD1 = 1;            
            if(tickActualIny > duracion)
            {
                stage = 0; //si anda sacar case 5:
                tickActualIny = 0;
                BANKA_OUTPUT = 0;//LATDbits.LATD1 = 0;
                tiempoAcumulado = tiempoAcumulado + duracion;
                status = false;
                //LATCbits.LATC15 = 0;
            }
            break;
        case 5://case para realizar pruebas, no iria en el definitivo.
            //status = false;
            if(tickActualIny > (3160 - tiempoAcumulado))
            {
                stage = 0;
                tickActualIny = 0;
                tiempoAcumulado = 0;
                
            }
            break;
        default:
            break;
    }
    return status;   
}

void tick10usIny()
{
    tickActualIny++;
}
/* *****************************************************************************
 End of File
 */
