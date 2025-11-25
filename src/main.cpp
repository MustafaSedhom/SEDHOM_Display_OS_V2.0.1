#include <Arduino.h>
#include "SEDHOM_Display_OS/SEDHOM_Display_OS.h"

SEDHOM_OS_Icons_t Icon_TFT;
void ID_on_tap();
void setup()
{
    SEDHOM_OS_Device_Start_Comunication();
    /////////////////
    pinMode(1,OUTPUT);
    //////////////////
    init_Rotation_and_mode(1,BLACK); 
    ////////////////////////////////////////////////////////////////////    
    ///////////////////////////////////////////////////////////////////////////////////

    // Icon_TFT.set_mode(Light_Mode);
    Icon_TFT.ID_Card_Icon(100,50,Icon_TFT.Mode(),GREEN,CYAN,Icon_TFT.Mode(),
    true,false,true,
    "MUSTAFA SEDHOM","SCIENCE UNVERSITY","COMPUTER SCINCE",
    "AND MATHEMATICS","22/02/2006","011 449 829 08",
    ID_on_tap);

}
void loop()
{
}
void ID_on_tap()
{

}