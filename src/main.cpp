#include <Arduino.h>
#include "SEDHOM_Display_OS/SEDHOM_Display_OS.h"

SEDHOM_OS_Icons_t Icon_TFT;

string_t rec =0;
int index =30,cof=40;
int end=0;
void handle_wifi();
void name_wifi(char * str);
void handle_commandes(string_t);
int handle_rssi(char * rssi);
WIFI_STATUS_t get_v(char * rssi) 
{
    int val = atoi(rssi);
    if (val <= -90) return WIFI_Status_not_connected;             // ضعيف جدًا
    else if (val <= -80) return WIFI_Status_no_internet;           // ضعيف
    else if (val <= -70) return WIFI_Status_conected_level_1;        // متوسط منخفض
    else if (val <= -60) return WIFI_Status_conected_level_2_half;    // متوسط
    else if (val <= -50) return WIFI_Status_conected_level_3;      // جيد
    else return WIFI_Status_conected_level_4_full;                 // ممتاز
}
void setup()
{
    SEDHOM_OS_Device_Start_Comunication();
    /////////////////
    pinMode(1,OUTPUT);
    //////////////////
    init_Rotation_and_mode(1,BLACK); 
    ////////////////////////////////////////////////////////////////////    
    ///////////////////////////////////////////////////////////////////////////////////
    //  Icon.WIFI_Icon(200,200,WIFI_Status_conected_level_4_full,BLUE,LIGHTGREY,Icon.Mode());
    WIFI_NAME_1 ="Sedhom";
    Range_wifi_1 = 99;
    Range_wifi_draw_1 = WIFI_Status_conected_level_4_full;
    
    Is_window_1_or_window_2_wifi_window= 0;
    // WIFI_Settings_window();
}
void loop()
{
     handle_wifi();
}
void handle_wifi()
{
    if(SEDHOM_Ready_or_Avaliable())
    {
       char * rec = SEDHOM_OS_Device_Recieve();
       handle_commandes(rec);
        if (strcmp(rec, "wifi_name") == 0)
        {
            char * dd = SEDHOM_OS_Device_Recieve();
            name_wifi(dd);
            Icon.Text(cof+30,index,SmallFont,GREEN,dd);
        }
        if (strcmp(rec,"wifi_Range")==0)
        {
            char * dd = SEDHOM_OS_Device_Recieve();
            Icon.WIFI_Icon(cof,index,get_v(dd),BLUE,DARKGREY,Icon.Mode());
            Icon.Text(cof+160,index,SmallFont,MAGENTA,dd);
            index += 40;
        }
        if(index >= Icon.Screen_lenght())
        {
            index=30;
            cof = 275;
            end ++ ;
            Icon.Divider_Horezontal(230,10,Icon.Screen_lenght()-30,3,RED);
        } 
        if(end ==2)
        {
            index=30;
            cof=40;
            end =0;
            Icon.clear_All_Display();
        }



    }  
}
void name_wifi(char * str)
{

}
void handle_commandes(string_t command)
{
    if (!strcmp(command,"wifi_name"))
    {
    }
    if (!strcmp(command,"wifi_Range"))
    {
        
    }
}