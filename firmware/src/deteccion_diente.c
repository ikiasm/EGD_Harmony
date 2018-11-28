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

#include "deteccion_diente.h"

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

void deteccion_diente();


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

void deteccion_diente()
{
    static UInt32 tiempoAnt,RPM_ant, RPM_2;
    static UInt8 i,j;
    static UInt8 flag_RPM=0;
    float seg_RPM;
     static UInt32 deltaAnt;
     UInt32 delta = tickActualRpm - tiempoAnt;
     UInt32 doble_diente=deltaAnt*0.7;
  //   static UInt16 promedioDientes;
 //    static UInt16 vectorDelta[58];
 //    UInt16 spanDelta;
     
    if((delta < doble_diente) || (cont_dientes==12))
    {
     //       seg_RPM=((tiempoActual*0.000050*60)/cont_dientes);
//        if(RPM_ant>1000)                                         //para estas rpm usaba esta formula
//        {
//            RPM = ((60000000)/(tickActualRpm * 50));
//        }
//        else if(RPM_ant<=1000)                                      //para estas rpm esta formula tenia mas precision
        {
        seg_RPM=(deltaAnt*12*50);
        RPM=((60000000/seg_RPM)*2);
        }
        //
         if(flag_RPM==0)   //&& tick_1ms>10)   
        {
                RPM_ant=RPM;
                flag_RPM=1;
        }

        if((RPM>RPM_ant+50 || RPM<RPM_ant-50) && (flag_RPM==1))     
        {
            flag_RPM=0;
            RPM_ant=RPM;
        }
        if((RPM>RPM_ant+20 || RPM<RPM_ant-20) && (flag_RPM==1))            //  || 900>
        {
            RPM=RPM_ant;
        }
        if(RPM<100 && RPM>4000)
        {
            RPM=RPM_ant;
        }
        
        
        cont_dientes=0;
        tickActualRpm=0;
//        promedioDientes=0;
//        i=0;
    }

    tiempoAnt = tickActualRpm;
    deltaAnt = delta;
    cont_dientes++;
     
}

/* *****************************************************************************
 End of File
 */
