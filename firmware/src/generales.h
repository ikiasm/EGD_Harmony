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

#ifndef _GENERALES_FILE_NAME_H    /* Guard against multiple inclusion */
#define _GENERALES_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


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
#define GENERALES_CONSTANT 0


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
    typedef struct _generales_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } generales_struct_t;


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
    int GeneralesFunction(int param1, int param2);


    /* Provide C++ Compatibility */
    
    /*--------------------------DEFINES---------------------------*/
    
//SALIDAS
#define HIGH                 1
#define LOW                  0
#define HIGH_INV             0    
#define LOW_INV              1
#define INPUT                1
#define OUTPUT               0
#define TRUE                 1
#define FALSE                0
    
/*---------------------VARIABLES GLOBALES-----------------------*/


/*-------------------PROTOTIPO DE FUNCIONES---------------------*/
    
    
/*! Entero de 8 bits con signo */
typedef signed char Int8;
/*! Entero de 8 bits sin signo */
typedef unsigned char UInt8;
/*! Entero de 16 bits con signo */
typedef signed short Int16;
/*! Entero de 16 bits sin signo */
typedef unsigned short UInt16;
/*! Entero de 32 bits con signo */
typedef signed int Int32;
/*! Entero de 32 bits sin signo */
typedef unsigned int UInt32;
/*! Entero de 64 bits con signo */
typedef signed long int Int64;
/*! Entero de 64 bits sin signo */
typedef unsigned long int UInt64;
/*! Flotante */
typedef float Float;
/*! Flotante con mayor presicion */
typedef double Double;
/*! Boleano
   Solo puede tomar los valores TRUE o FALSE
 */
typedef Int8 Bool;
/*! Caracter */
typedef unsigned char Char;
/*! Para manejo de numeros reales */
typedef double Real;
#ifdef __cplusplus
}
#endif

#endif /* _GENERALES_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */