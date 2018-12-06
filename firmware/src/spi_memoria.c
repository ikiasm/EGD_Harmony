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
#include "spi_memoria.h"
#include "app.h"
//#include "plib.h"
//#include <peripheral/spi_5xx_6xx_7xx.h>


#define SS_ENABLE_TRIS                   TRISDbits.TRISD14       //PIN 47 (SS3)
#define SS_ENABLE_LAT                    LATDbits.LATD14      
#define SCK_ENABLE_TRIS                   TRISDbits.TRISD15       //PIN 48 (SCK3)
#define SCK_ENABLE_LAT                    LATDbits.LATD15
#define SDI_ENABLE_TRIS                   TRISFbits.TRISF2       //PIN 52 (SDI3)
#define SDI_ENABLE_LAT                    LATFbits.LATF2
#define SDO_ENABLE_TRIS                   TRISFbits.TRISF8       //PIN 53 (SDO3)
#define SDO_ENABLE_LAT                    LATFbits.LATF8   
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
void memoria_get_adress()
{
    UInt8 dir_carga, dir_rpm;
    UInt32 direccion;
    UInt32 carga;
//    if(conversion_terminada==1)
//    {
//    carga= result[AN03];    // saco el porcentaje
//    dir_carga = carga / (0x49);
//    dir_rpm = RPM / 500;
//    direccion = dir_carga*0x10 + dir_rpm;
    memoria_read(0x000000BF);
   // memoria_write(0xAA, 0x000000BF); 
//    if(dir_rpm < 0)
//    {
//     dir_rpm++;   
//    }
//    }
}
UInt8 memoria_read(UInt32 dir)
{
    UInt32 dato_mapa;
    UInt32 direccion_completa;
    static UInt8 mapa=0;
 //   waitBusy();
    SS_ENABLE_LAT = 0;
    switch(mapa)
    {
        case 0: //direccion_completa = 0x03000100 + dir;  //READ + dir INYECC
               // direccion_completa = 0x0301AA55;
             //   SpiChnPutC(0x3, 0x0301FFF6);
//                SpiChnPutC(0x3, 0x030000A0);
                SPI_transfer(0x030000A0);
                dato_mapa=SPI_transfer( 0);
//                SpiChnPutC(0x3, 0);                 //dummy byte
                mapa = 0;mapa = 0;mapa = 0;mapa = 0;
                dato_mapa=SPI3BUF;
                mapa = 0;
                SS_ENABLE_LAT = 1;
                break;
    //    case 1: SDO_ENABLE_TRIS = 0x03000200 + dir;  //READ + dir ENCENDIDO
        case 1: //SDO_ENABLE_TRIS = 0x0301FFFF;
                mapa = 0;
                break;
        default: mapa = 0; break;
    }
//    if(SPI3STATbits.SPIBUSY == 0)
//    {
//    dato_mapa = SPI3BUF;
//    SS_ENABLE_LAT = LOW_INV;
//    }

       
}
UInt8 memoria_write(UInt32 valor, UInt32 direccion)
{
    UInt32 dato_escrito;
//    waitBusy();
//    direccion = direccion + 0x02000000;
//    SPI3CONbits.MODE16 = 0;     // 8 bit mode
//    SPI3CONbits.MODE32 = 0;
    
    SS_ENABLE_LAT = 0;
    SpiChnPutC(0x3, 0x06000000);    //WREN
    SS_ENABLE_LAT = 1;
   
    SS_ENABLE_LAT = 0;
    
//    SPI3CONbits.MODE16 = 0;     // 8 bit mode
//    SPI3CONbits.MODE32 = 1;
    
    SpiChnPutC(0x3, 0x020000A0);    //WRITE+ADRESS
    SpiChnPutC(0x3, 0xBFAA000A);        //data  32bit
    SpiChnPutC(0x3, 0);
//   // SPI3BUF=0x020000BF;
//    dato_escrito=SPI3BUF;
//    Delay10KTCYx(1);
    //delay_ms(1);
  //  waitBusy();
    SS_ENABLE_LAT = 1;
}
void waitBusy()
{
    int status = 0;
 
    do{
        SS_ENABLE_LAT = 0;                         // Select EEPROM
        SpiChnPutC(0x3, 0x05000000);           // Read EEPROM status register
       // status = SPI_transfer( 0);     // send dummy byte to receive incoming data
        SpiChnPutC(0x3, 0);
        status=SPI3BUF;
        status=status;
        SS_ENABLE_LAT = 1;                         // Release EEPROM
    }while( status & 0x01);             // write-in-progress while status<0> set to '1'
 
  //  return 0;
} // END waitBusy()
UInt32 SPI_transfer( UInt32 b)
{
    SPI3BUF = b;                        // write to buffer for TX
    while( !SPI3STATbits.SPITBE);       // wait transfer complete
    return SPI3BUF;                     // read the received value
} // END SPI1_transfer()




/* *****************************************************************************
 End of File
 */
