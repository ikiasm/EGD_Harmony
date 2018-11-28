/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _INYECCION_FILE_NAME_H    /* Guard against multiple inclusion */
#define _INYECCION_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "app.h"
#include <proc/p32mx795f512l.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */

#define INY1_TRIS       TRISDbits.TRISD12   //RD12
#define INY1_OUTPUT     LATDbits.LATD12
#define INY2_TRIS       TRISDbits.TRISD13   //RD11
#define INY2_OUTPUT     LATDbits.LATD13
#define INY3_TRIS       TRISDbits.TRISD6    //RD6
#define INY3_OUTPUT     LATDbits.LATD6
#define INY4_TRIS       TRISDbits.TRISD7    //RD7
#define INY4_OUTPUT     LATDbits.LATD7
#define BANKA_TRIS      TRISDbits.TRISD1    //RD1
#define BANKA_OUTPUT    LATDbits.LATD1
#define BANKB_TRIS      TRISDbits.TRISD3    //RD3
#define BANKB_OUTPUT    LATDbits.LATD3    
#define INY1_OD     ODCDbits.ODCD12
#define INY2_OD     ODCDbits.ODCD11
#define INY3_OD     ODCDbits.ODCD6
#define INY4_OD     ODCDbits.ODCD7
#define BANKA_OD    ODCDbits.ODCD1
#define BANKB_OD    ODCDbits.ODCD3
//#define OPEN_DRAIN

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
    typedef struct _inyeccion_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } inyeccion_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

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
    int InyeccionFunction(int param1, int param2);


    /* Provide C++ Compatibility */
    //Inicializacion de las salidas de inyeccion y banks
extern void inyeccionInit(void);
//Funciones generadoras de pulsos para la activacion de las monobombas de cada cilindro
//Parametro tiempo expreso en microsegundos
extern void pulsoIny1(int tiempo);
extern void pulsoIny2(int tiempo);
extern void pulsoIny3(int tiempo);
extern void pulsoIny4(int tiempo);
//Funciones generadoras de pulsos modulados PWM para el control de monobombas
//BancoA corresponde a los pulsos de cilindros 1 -2
//BancoB corresponde a los pulsos de cilindros 3 - 4
//Parametro tiempo expresado en microsegundos
extern bool pulsoBancoA(int tiempo);
extern bool pulsoBancoB(int tiempo);
extern void tick10usIny(void);
#ifdef __cplusplus
}
#endif

#endif /* _INYECCION_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
