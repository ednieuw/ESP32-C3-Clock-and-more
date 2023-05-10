/* 

--------------------------------------  
 Author .    : Ed Nieuwenhuys
 Changes V001: Derived from PocuterWordClockV052
 Changes V002: Stable version without ILI 9341 display / SD card
 Changes V003: Added ILI9341
 Changes V004: Screen layout. Displayprintln()
 Changes V005: BT connection on led blue, repait digitalprint. Turn off LEDs after 1 minute 
 Changes V006: LDR and Backlight regulation
 Changes V007: Debugging
 Changes V008: Added Light intensity S Slope T Min U Max
 Changes V009: Clean up code. Can be used with the ILI9341 Display. 
 Changes V010: Added a SK6812 LED-strip for a 4-language word clock 
 Changes V011: Compiles also for ESP32-S3. Added menu option & for requery NTP 

// ESP32-C3-12F layout seen from top
// ADC   ----- I0 19
// IO 01 ----- I0 18
// NC    ----- I0 10
// IO 02 ----- I0 09
// IO 03 ----- I0 08
// IO 04 ----- 3V3  
// IO 05 ----- GND  
// NC    ----- NC   
// NC    ----- I0 06
// GND   ----- I0 07
// 3V3   ----- NC   
// EN    ----- RX   
// IO 00 ----- TX   
// GND   ----- GND  
// 5V    ----- 3V3  

ILI9341 connections
MISO  to GPIO 10
LED   to 3V3
SCK   to GPIO 09
MOSI  to GPIO 08  
DC/RS to GPIO 06
RESET to GPIO 07
CS    to GND
GND   to GND
3V3   to 3V3


  
Usage of:
1 Screen, colours and fonts
2 BLE nRF UART connection with phone
3 Buttons
4 RGB LED
5 RTC module for time
6 ??SD-card or SPIFFS storage of a struct with settings
7 Get timezone corrected time with daylight savings from a NTP server via WIFI
8 Menu driven with serial monitor, BLE and WIFI
9 Change connection settings of WIFI via BLE
10 Get time with NTP server via WIFI


How to compile: Install ESP32 boards
Set to:
Board: ESP32-C3 DEV module
Patition Scheme: Huge (4Mb, No OTA, 1MB SPIFFS)


Starting the monitor will result in the board to be unresponsive. This is due to the CTS and RTS levels of the serial interface. Disabling the control lines prevents the board to become unresponsive. Edit the file “boards.txt” from the definition of the board. The file is located in the following directory, where xxxxx is the user name: “C:\Users\xxxxx\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.2”
To get to this location, click on the “Preferences” to open the file explorer, then click trough to the above location.
Change the following lines (lines 35 and 36):
esp32c3.serial.disableDTR=false
esp32c3.serial.disableRTS=false
to
esp32c3.serial.disableDTR=true
esp32c3.serial.disableRTS=true                   
*/
// =============================================================================================================================
//--------------------------------------------
// ESP32-C3 Includes defines and initialisations
//--------------------------------------------

#include <NimBLEDevice.h>      // For BLE communication  https://github.com/h2zero/NimBLE-Arduino
#include <ESPNtpClient.h>      // https://github.com/gmag11/ESPNtpClient
#include <WiFi.h>              // Used for NTP time and web page
#include <AsyncTCP.h>          // Used for webpage   https://github.com/me-no-dev/ESPAsyncWebServer
#include <ESPAsyncWebServer.h> // Used for webpage   https://github.com/me-no-dev/ESPAsyncWebServer
#include <Preferences.h>
#include "Colors.h"
#include <Adafruit_ILI9341.h>


#define HET     ColorLeds("Het",     0,   2, MINColor);   
#define IS      ColorLeds("is",      4,   5, SECColor);    Is = true; 
#define WAS     ColorLeds("was",     7,   9, SECColor);    Is = false;
#define MVIJF   ColorLeds("vijf",    11, 14, LetterColor); 
#define PRECIES ColorLeds("precies", 16, 22, LetterColor);
#define MTIEN   ColorLeds("tien",    25, 28, LetterColor); 
#define KWART   ColorLeds("kwart",   32, 36, LetterColor);
#define VOOR    ColorLeds("voor",    38, 41, LetterColor);
#define OVER    ColorLeds("over",    43, 46, LetterColor);
#define HALF    ColorLeds("half",    48, 51, LetterColor);
#define MIDDER  ColorLeds("midder",  53, 58, LetterColor);
#define VIJF    ColorLeds("vijf",    60, 63, LetterColor);
#define TWEE    ColorLeds("twee",    65, 68, LetterColor);
#define EEN     ColorLeds("een",     71, 73, LetterColor);
#define VIER    ColorLeds("vier",    76, 79, LetterColor);
#define ELF     ColorLeds("elf",     80, 82, LetterColor);
#define TIEN    ColorLeds("tien",    84, 87, LetterColor);
#define TWAALF  ColorLeds("twaalf",  89, 94, LetterColor);
#define DRIE    ColorLeds("drie",    97,100, LetterColor);
#define NEGEN   ColorLeds("negen",  102,106, LetterColor);
#define ACHT    ColorLeds("acht",   107,110, LetterColor);
#define NACHT   ColorLeds("nacht",  114,118, LetterColor);
#define ZES     ColorLeds("zes",    112,114, LetterColor);
#define ZEVEN   ColorLeds("zeven",  116,120, LetterColor);
#define NOEN    ColorLeds("noen",   120,123, LetterColor);
#define UUR     ColorLeds("uur",    125,127, LetterColor);
//#define EDSOFT  ColorLeds("EdSoft", 132,132, LetterColor);
#define X_OFF   ColorLeds("",         0,  2, 0);
#define X_ON    ColorLeds("",         0,  2, LetterColor);

#define IT      ColorLeds("It",     1,   2, MINColor);   
#define ISUK    ColorLeds("is",       4,   5, SECColor);    Is = true;
#define WASUK   ColorLeds("was",      7,   9, SECColor);    Is = false;
#define EXACTUK ColorLeds("exact",   11,  15, LetterColor);
#define HALFUK  ColorLeds("half",    16,  19, LetterColor); 
#define TWENTY  ColorLeds("twenty",  21,  26, LetterColor); 
#define MFIVE   ColorLeds("five",    28,  31, LetterColor);
#define QUARTER ColorLeds("quarter", 32,  38, LetterColor);
#define MTEN    ColorLeds("ten",     39,  41, LetterColor);
#define PAST    ColorLeds("past",    43,  46, LetterColor);
#define TO      ColorLeds("to",      48,  49, LetterColor);
#define MID     ColorLeds("mid",     53,  55, LetterColor);
#define SIXUK   ColorLeds("six",     57,  59, LetterColor);
#define TWO     ColorLeds("two",     61,  63, LetterColor);
#define FIVE    ColorLeds("five",    64,  67, LetterColor);
#define TWELVE  ColorLeds("twelve",  69,  74, LetterColor);
#define TEN     ColorLeds("ten",     76,  78, LetterColor);
#define ELEVEN  ColorLeds("eleven",  80,  85, LetterColor);
#define FOUR    ColorLeds("four",    88,  91, LetterColor);
#define ONE     ColorLeds("one",     93,  95, LetterColor);
#define EIGHT   ColorLeds("eight",   97, 101, LetterColor);
#define THREE   ColorLeds("three",  101, 105, LetterColor);
#define NIGHT   ColorLeds("night",  106, 110, LetterColor);
#define NINE    ColorLeds("nine",   112, 115, LetterColor);
#define SEVEN   ColorLeds("seven",  116, 120, LetterColor);
#define OCLOCK  ColorLeds("Oclock", 122, 127, LetterColor);

#define ES      ColorLeds("Es",       0,   1, MINColor);   
#define IST     ColorLeds("ist",      3,   5, SECColor);    Is = true;
#define WAR     ColorLeds("war",      6,   8, SECColor);    Is = false;
#define GENAU   ColorLeds("genau",   10,  14, LetterColor);
#define MZEHN   ColorLeds("zehn",    16,  19, LetterColor);
#define MFUNF   ColorLeds("funf",    20,  23, LetterColor);
#define VIERTEL ColorLeds("viertel", 24,  30, LetterColor);
#define ZWANZIG ColorLeds("zwanzig", 32,  38, LetterColor);
#define KURZ    ColorLeds("kurz",    40,  43, LetterColor);
#define VOR     ColorLeds("vor",     45,  47, LetterColor);
#define NACH    ColorLeds("nach",    48,  51, LetterColor);
#define HALB    ColorLeds("halb",    53,  56, LetterColor);
#define FUNF    ColorLeds("funf",    58,  61, LetterColor);
#define EINS    ColorLeds("eins",    64,  67, LetterColor);
#define VIERDE  ColorLeds("vier",    69,  72, LetterColor);
#define ZWOLF   ColorLeds("zwolf",   73,  77, LetterColor);
#define MITTER  ColorLeds("mitter",  80,  85, LetterColor);
#define ACHTDE  ColorLeds("acht",    87,  90, LetterColor);
#define NACHTDE ColorLeds("nacht",   86,  90, LetterColor);
#define DREI    ColorLeds("drei",    92,  95, LetterColor);
#define SECHS   ColorLeds("sechs",   96, 100, LetterColor);
#define SIEBEN  ColorLeds("sieben", 102, 107, LetterColor);
#define NEUN    ColorLeds("neun",    107, 110, LetterColor);
#define ZWEI    ColorLeds("zwei",   112, 115, LetterColor);
#define ZEHN    ColorLeds("zehn",   116, 119, LetterColor);
#define ELFDE   ColorLeds("elf",    120, 122, LetterColor);
#define UHR     ColorLeds("uhr",    125, 127, LetterColor);

#define IL      ColorLeds("Il",     0,   1, MINColor);   
#define EST     ColorLeds("est",      3,   5, SECColor);    Is = true;
#define ETAIT   ColorLeds("etait",    6,  10, SECColor);    Is = false;
#define EXACT   ColorLeds("exact",   11,  15, LetterColor);
#define SIX     ColorLeds("six",     16,  18, LetterColor); 
#define DEUX    ColorLeds("deux",    19,  22, LetterColor); 
#define TROIS   ColorLeds("trois",   23,  27, LetterColor);
#define ONZE    ColorLeds("onze",    28,  31, LetterColor);
#define QUATRE  ColorLeds("quatre",  32,  37, LetterColor);
#define MINUIT  ColorLeds("minuit",  39,  44, LetterColor);
#define DIX     ColorLeds("dix",     45,  47, LetterColor);
#define CINQ    ColorLeds("cinq",    48,  51, LetterColor);
#define NEUF    ColorLeds("neuf",    52,  55, LetterColor);
#define MIDI    ColorLeds("midi",    57,  60, LetterColor);
#define HUIT    ColorLeds("huit",    64,  67, LetterColor);
#define SEPT    ColorLeds("sept",    69,  72, LetterColor);
#define UNE     ColorLeds("une",     73,  75, LetterColor);
#define HEURE   ColorLeds("heure",   80,  84, LetterColor);
#define HEURES  ColorLeds("heures",  80,  85, LetterColor);
#define ET      ColorLeds("et",      87,  88, LetterColor);
#define MOINS   ColorLeds("moins",   90,  94, LetterColor);
#define LE      ColorLeds("le",      96,  97, LetterColor);
#define DEMI    ColorLeds("demie",   99, 103, LetterColor);
#define QUART   ColorLeds("quart",  106, 110, LetterColor);
#define MDIX    ColorLeds("dix",    112, 114, LetterColor);
#define VINGT   ColorLeds("vingt",  116, 120, LetterColor);
#define MCINQ   ColorLeds("cinq",   122, 125, LetterColor);
#define DITLEHEURE DitLeHeure();

//--------------------------------------------
// SPIFFS storage
//--------------------------------------------
Preferences FLASHSTOR;

 //--------------------------------------------
// COLOURS
//--------------------------------------------   

const byte DEFAULTCOLOUR = 0;
const byte HOURLYCOLOUR  = 1;          
const byte WHITECOLOR    = 2;
const byte OWNCOLOUR     = 3;
const byte OWNHETISCLR   = 4;
const byte WHEELCOLOR    = 5;
const byte DIGITAL       = 6;


// Pin Assignments
#define  PhotoCellPin 2
#define  EMPTY01      1
#define  EMPTY00      0


#define  REDPIN       3
#define  GREENPIN     4
#define  BLUEPIN      5
#define  COLD_WHITE  18
#define  WARM_WHITE  19

//--------------------------------------------
// ESP32-C3 initialysations
//--------------------------------------------
bool     PrintDigital = false;                                                           // Show digital display 
bool     IP_Printed   = false;                                                           // The IP address will be printed on the display
bool     Date_Printed = false;                                                           // The date will be printed on the display  
char     Template[140];                                                                  // Contains the string with characters to be printed in the display
uint32_t LastButtonTime = 0;                                                             // Used to avoid debouncing the button

//------------------------------------------------------------------------------
// LDR PHOTOCELL
//------------------------------------------------------------------------------
//                                                                                            //
const byte SLOPEBRIGHTNESS  = 80;                                 // Steepness of with luminosity of the LED increases
const int  MAXBRIGHTNESS    = 255;                                // Maximun value in bits  for luminosity of the LEDs (1 - 255)
const byte LOWBRIGHTNESS    = 5;                                  // Lower limit in bits of Brightness ( 0 - 255)   
byte     TestLDR            = 0;                                  // If true LDR inf0 is printed every second in serial monitor
int      OutPhotocell;                                            // stores reading of photocell;
int      MinPhotocell       = 999;                                // stores minimum reading of photocell;
int      MaxPhotocell       = 1;                                  // stores maximum reading of photocell;
uint32_t SumLDRreadshour    = 0;
uint32_t NoofLDRreadshour   = 0;

//--------------------------------------------
// CLOCK initialysations
//--------------------------------------------                                 

static  uint32_t msTick;                        // Number of millisecond ticks since we last incremented the second counter
byte    lastminute = 0, lasthour = 0, lastday = 0, sayhour = 0;
bool    Zelftest             = false;
bool    Is                   = true;            // toggle of displaying Is or Was
bool    ZegUur               = true;            // Say or not say Uur in NL clock
struct tm timeinfo;                             // storage of time 



//--------------------------------------------
// SCREEN Pixel initialysations
//--------------------------------------------
const byte MATRIX_WIDTH     = 16;
const byte MATRIX_HEIGHT    = 8;
const byte NUM_LEDS         = MATRIX_WIDTH * MATRIX_HEIGHT ;        
struct   LEDPrintbuffer
         { 
          char Character;  
          uint32_t RGBColor;
         } Strippos[NUM_LEDS+1];
bool     LEDsAreOff            = false;         // If true LEDs are off except time display
bool     NoTextInColorLeds     = false;         // Flag to control printing of the text in function ColorLeds()
int      Previous_LDR_read     = 512;           // The actual reading from the LDR + 4x this value /5  
uint32_t MINColor              = C_YELLOW;      //C_RED;
uint32_t SECColor              = C_YELLOW;     //C_GREEN;
uint32_t LetterColor           = C_YELLOW;      
uint32_t HourColor[24] ={C_WHITE, C_RED, C_ORANGE, C_YELLOW,  C_YELLOW_GREEN, C_GREEN,
                         C_CYAN,  C_DODGER_BLUE, C_PURPLE, C_MAGENTA, C_GOLD, C_SPRING_GREEN,
                         C_WHITE, C_CHOCOLATE, C_ORANGE, C_KHAKI, C_YELLOW_GREEN, C_BEIGE,
                         C_AQUA_MARINE,  C_SKY_BLUE, C_HOT_PINK, C_DEEP_PINK, C_CORAL, C_LAWN_GREEN};  
//--------------------------------------------
// SCREEN ILI9341
//--------------------------------------------
#define TFT_MISO   -1 //10  not used 
#define TFT_SCK    9
#define TFT_MOSI   8
#define TFT_DC     6
#define TFT_RESET  7
#define TFT_CS     -1 //0  not used
#define TFT_LED    1 // the LED backlight display
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RESET, TFT_MISO);

//--------------------------------------------
// BLE   //#include <NimBLEDevice.h>
//--------------------------------------------
BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected    = false;
bool oldDeviceConnected = false;
std::string ReceivedMessageBLE;

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"        // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

//----------------------------------------
// WEBSERVER
//----------------------------------------
int WIFIConnected = 0;              // Is wIFI connected?

AsyncWebServer server(80);       
#include "Webpage.h"
          
//----------------------------------------
// Common
//----------------------------------------
#define MAXTEXT 140
char sptext[MAXTEXT];                    // For common print use 
bool SerialConnected = true;   
struct EEPROMstorage {                   // Data storage in EEPROM to maintain them after power loss
  byte DisplayChoice    = 0;
  byte TurnOffLEDsAtHH  = 0;
  byte TurnOnLEDsAtHH   = 0;
  byte LanguageChoice   = 0;
  byte LightReducer     = 0;
  int  LowerBrightness  = 0;
  int  UpperBrightness  = 0;
  int  NVRAMmem[24];                                            // LDR readings
  byte BLEOnOff         = 1;
  byte NTPOnOff         = 1;
  byte WIFIOnOff        = 1;  
  int  TimeCorrection   = 0;              // Time correction in seconds
  byte UseSDcard        = 0;
  byte UseBLELongString = 0;              // Send strings longer than 20 bytes per message. Possible in IOS app BLEserial Pro 
  uint32_t OwnColour    = 0;              // Self defined colour for clock display
  uint32_t DimmedLetter = 0;
  uint32_t BackGround   = 0;
  char Ssid[30];
  char Password[40];
  char BLEbroadcastName[30];             // Name of the BLE beacon
  char Timezone[50];
  int  Checksum        = 0;
}  Mem; 
//--------------------------------------------
// Menu
//0        1         2         3         4
//1234567890123456789012345678901234567890----  
 char menu[][40] = {
 "A SSID B Password C BLE beacon name",
 "D Date (D15012021) T Time (T132145)",
 "E Timezone  (E<-02>2 or E<+01>-1)",
 "  Make own colour of:  (Hex RRGGBB)",
 "F Font  G Dimmed font H Bkgnd",
 "I To print this Info menu",
 "K LDR reads/sec toggle On/Off", 
 "L L0 = NL, L1 = UK, L2 = DE",
 "  L3 = FR, L4 = Wheel",
 "N Display off between Nhhhh (N2208)",
 "O Display toggle On/Off", 
 "Q Display colour choice      (Q0-6)",
 "  Q0 Yellow  Q1 hourly",
 "  Q2 White   Q3 All Own",
 "  Q4 Own     Q5 Wheel",
 "  Q6 Digital display",
 "R Reset settings @ = Reset MCU",
 "--Light intensity settings (1-250)--",
 "S=Slope V=Min  U=Max  (S80 L5 M200)",
 "W=WIFI  X=NTP&  Y=BLE  Z=Fast BLE", 
 "Ed Nieuwenhuys Feb 2023" };
 
//  -------------------------------------   End Definitions  ---------------------------------------
//                                                                                            //

//--------------------------------------------
// ARDUINO Setup
//--------------------------------------------
void setup() 
{
 Serial.begin(115200);                 Tekstprintln("Serial started");                        // Setup the serial port to 115200 baud //
 pinMode(REDPIN,     OUTPUT);
 pinMode(GREENPIN,   OUTPUT);
 pinMode(BLUEPIN,    OUTPUT);
 pinMode(COLD_WHITE, OUTPUT);
 pinMode(WARM_WHITE, OUTPUT);
 pinMode(TFT_LED,    OUTPUT);                                                                     // ILI9341 backlight                          

//  adcAttachPin(PhotoCellPin);
//  adcStart(PhotoCellPin);
//  analogReadResolution(10); // Default of 12 is not very linear. Recommended to use 10 or 11 depending on needed resolution.
//  analogSetAttenuation(ADC_6db); // Default is 11db which is very noisy. Recommended to use 2.5 or 6.

 // pinMode(PhotoCellPin, INPUT);
// pinMode(PhotoCellPin, INPUT);
 
 Previous_LDR_read = ReadLDR();
 InitScreen();                            Tekstprintln("Screen started");
 InitStorage();                           Tekstprintln("Setting loaded");                     // Load settings from storage and check validity 
 if (Mem.BLEOnOff) StartBLEService();     Tekstprintln("BLE started");                        // Start BLE service
 if(Mem.WIFIOnOff){ Tekstprintln("Starting WIFI"); StartWIFI_NTP();   }                       // Start WIFI and optional NTP if Mem.WIFIOnOff = 1

 Mem.DisplayChoice == DIGITAL?PrintDigital=true:PrintDigital=false; 
 SWversion();                                                                                 // Print the menu + version 
 GetTijd(0);                                                                                  // 
// Displaytime();                                                                               // Print the tekst time in the display
 Print_tijd();
 msTick = LastButtonTime = millis(); 
 ClearScreen(); 
}
//                                                                                            //
//--------------------------------------------
// ARDUINO Loop
//--------------------------------------------
void loop() 
{
 EverySecondCheck();  
 CheckDevices();
}
//--------------------------------------------
// Common Check connected input devices
//--------------------------------------------
void CheckDevices(void)
{
 CheckBLE();                                                                                  // Something with BLE to do?
 SerialCheck();                                                                               // Check serial port every second 
// ButtonsCheck();                                                                              // Check if buttons pressed
}
//                                                                                            //
//--------------------------------------------
// CLOCK Update routine done every second
//--------------------------------------------
void EverySecondCheck(void)
{
 static int lumi=0;
 uint32_t msLeap;
 
 msLeap = millis() - msTick;                                                                  // uint32_t msLeapButton = millis()- LastButtonTime;
 (msLeap>500?lumi=(1000-msLeap)/40:lumi=msLeap/40);                                           // Turn ON/betwOFF the second on LED. 
 if (msLeap%100==0){ SetStatusLED(-1,-1,12-lumi,lumi*WIFIConnected,-1); }                    // Do not update the LED unnecessary often
 if (msLeap >999)                                                                             // Every second enter the loop
  { 
   GetTijd(0);                                                                                // Update timeinfo.tm_sec, timeinfo.tm_min, timeinfo.tm_hour, timeinfo.tm_mday, timeinfo.tm_mon, timeinfo.tm_year
   if (timeinfo.tm_min != lastminute) EveryMinuteUpdate();                                    // Enter the every minute routine after one minute
   if (Mem.DisplayChoice == DIGITAL) PrintTimeInScreen();                                     // Show the digital time in the screen
   DimLeds(TestLDR);                                                                          // Every second an intensitiy check and update from LDR reading 
   msTick = millis();
  }  
 }
//--------------------------------------------
// CLOCK Update routine done every minute
//-------------------------------------------- 
void EveryMinuteUpdate(void)
{
 lastminute = timeinfo.tm_min;  
 if(!LEDsAreOff)  Displaytime();                                                              // Turn the display on                 
// Print_tijd();                                                                              //  sprintf(sptext,"NTP:%s", NTP.getTimeDateString());   Tekstprintln(sptext);  
 if(timeinfo.tm_hour != lasthour) EveryHourUpdate();
}
//--------------------------------------------
// CLOCK Update routine done every hour
//--------------------------------------------
void EveryHourUpdate(void)
{
 lasthour = timeinfo.tm_hour;
 if(timeinfo.tm_hour == Mem.TurnOffLEDsAtHH){ LEDsAreOff = true;  ClearScreen(); }            // Is it time to turn off the LEDs?
 if(timeinfo.tm_hour == Mem.TurnOnLEDsAtHH)   LEDsAreOff = false;                             // 
 Mem.NVRAMmem[lasthour] =(byte)((SumLDRreadshour / NoofLDRreadshour?NoofLDRreadshour:1));    // Update the average LDR readings per hour
 SumLDRreadshour  = 0;
 NoofLDRreadshour = 0;
 if (timeinfo.tm_mday != lastday) EveryDayUpdate();  
}
//                                                                                            //
//------------------------------------------------------------------------------
// CLOCK Update routine done every day
//------------------------------------------------------------------------------
void EveryDayUpdate(void)
{
 if(timeinfo.tm_mday != lastday) 
   {
    lastday = timeinfo.tm_mday; 
    Previous_LDR_read = ReadLDR();                                                           // to have a start value
    MinPhotocell      = Previous_LDR_read;                                                  // Stores minimum reading of photocell;
    MaxPhotocell      = Previous_LDR_read;                                                  // Stores maximum reading of photocell;
//    StoreStructInFlashMemory();                                                             // 
    }
}
//--------------------------------------------
// Common check for serial input
//--------------------------------------------
void SerialCheck(void)
{
 String SerialString; 
 while (Serial.available())
    { 
     char c = Serial.read();                                                               // Serial.write(c);
     if (c>31 && c<128) SerialString += c;                                                    // Allow input from Space - Del
     else c = 0;                                                                              // Delete a CR
    }
 if (SerialString.length()>0) 
    {
     ReworkInputString(SerialString+"\n");                                                    // Rework ReworkInputString();
     SerialString = "";
    }
}

//                                                                                            //
//------------------------------------------------------------------------------
// Common Reset to default settings
//------------------------------------------------------------------------------
void Reset(void)
{
 Mem.Checksum        = 25065;                                                                 //
 Mem.DisplayChoice   = DEFAULTCOLOUR;                                                         // 
 Mem.OwnColour       = C_GREEN;                                                               // Own designed colour.
 Mem.DimmedLetter    = 0X191919;
 Mem.BackGround      = C_BLACK; 
 Mem.LanguageChoice  = 4;                                                                     // 0 = NL, 1 = UK, 2 = DE, 3 = FR, 4 = Wheel
 Mem.LightReducer     = SLOPEBRIGHTNESS;                                                      // Factor to dim ledintensity with. Between 0.1 and 1 in steps of 0.05
 Mem.UpperBrightness  = MAXBRIGHTNESS;                                                        // Upper limit of Brightness in bits ( 1 - 1023)
 Mem.LowerBrightness  = LOWBRIGHTNESS;                                                        // Lower limit of Brightness in bits ( 0 - 255)
 Mem.TurnOffLEDsAtHH = 0;                                                                     // Display Off at nn hour
 Mem.TurnOnLEDsAtHH  = 0;                                                                     // Display On at nn hour Not Used
 Mem.BLEOnOff        = 1;                                                                     // BLE On
 Mem.UseBLELongString= 0;
 Mem.NTPOnOff        = 0;                                                                     // NTP On
 Mem.WIFIOnOff       = 0;                                                                     // WIFI On  
 Mem.TimeCorrection  = 0;                                                                     // Correct time if necesaary in seconds
 Mem.UseSDcard       = 0;
 Previous_LDR_read    = ReadLDR();                                            // to have a start value. max = 4096/8 = 255
 MinPhotocell         = Previous_LDR_read;                                                    // Stores minimum reading of photocell;
 MaxPhotocell         = Previous_LDR_read;                                                    // Stores maximum reading of photocell;                                            
 TestLDR              = 0;                                                                    // If true LDR display is printed every second
 
 strcpy(Mem.Ssid,"");                                                                         // Default SSID
 strcpy(Mem.Password,"");                                                                     // Default password
 strcpy(Mem.BLEbroadcastName,"ESPWordClock");
 strcpy(Mem.Timezone,"CET-1CEST,M3.5.0,M10.5.0/3");                                           // Central Europe, Amsterdam, Berlin etc.
 // For debugging
// strcpy(Mem.Ssid,"Guest");
// strcpy(Mem.Password,"guest_001");
// Mem.NTPOnOff        = 1;                                                                     // NTP On
// Mem.WIFIOnOff       = 1;                                                                     // WIFI On  

 Tekstprintln("**** Reset of preferences ****"); 
 StoreStructInFlashMemory();                                                                  // Update Mem struct       
 GetTijd(0);                                                                                  // Get the time and store it in the proper variables
 SWversion();                                                                                 // Display the version number of the software
 //Displaytime();
}
//--------------------------------------------
// Common common print routines
//--------------------------------------------
void Tekstprint(char const *tekst)    { if(Serial) Serial.print(tekst);  SendMessageBLE(tekst);sptext[0]=0;   } 
void Tekstprintln(char const *tekst)  { sprintf(sptext,"%s\n",tekst); Tekstprint(sptext);  }
void TekstSprint(char const *tekst)   { printf(tekst); sptext[0]=0;}                          // printing for Debugging purposes in serial monitor 
void TekstSprintln(char const *tekst) { sprintf(sptext,"%s\n",tekst); TekstSprint(sptext); }
void Displayprint(const char *tekst)  { tft.print(tekst);   }                                 // Print to an attached display
void Displayprintln(const char *tekst){ tft.println(tekst); }
//------------------------------------------------------------------------------
//  Common Constrain a string with integers
// The value between the first and last character in a string is returned between the low and up bounderies
//------------------------------------------------------------------------------
int SConstrainInt(String s,byte first,byte last,int low,int up){return constrain(s.substring(first, last).toInt(), low, up);}
int SConstrainInt(String s,byte first,          int low,int up){return constrain(s.substring(first).toInt(), low, up);}
//                                                                                            //
//--------------------------------------------
// Common Init and check contents of EEPROM
//--------------------------------------------
void InitStorage(void)
{
 // if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){ Tekstprintln("Card Mount Failed");   return;}
 // else Tekstprintln("SPIFFS mounted"); 

 GetStructFromFlashMemory();
 if( Mem.Checksum != 25065)
   {
    sprintf(sptext,"Checksum (25065) invalid: %d\n Resetting to default values",Mem.Checksum); 
    Tekstprintln(sptext); 
    Reset();                                                                                  // If the checksum is NOK the Settings were not set
   }
 Mem.LanguageChoice  = _min(Mem.LanguageChoice, 4);                                           // Constrain the value to valid ranges 
 Mem.DisplayChoice   = _min(Mem.DisplayChoice, DIGITAL);                                      // Constrain the value to valid ranges 
 if(Mem.OwnColour == 0) Mem.OwnColour = C_GREEN;                                           // If memory is empty cq black colour then store default value, blue  
 Mem.LightReducer    = constrain(Mem.LightReducer,1,250);                                   // 
 Mem.LowerBrightness = constrain(Mem.LowerBrightness, 1, 250);                              // 
 Mem.UpperBrightness = _min(Mem.UpperBrightness, 255); 
 if(strlen(Mem.Password)<5 || strlen(Mem.Ssid)<3)     Mem.WIFIOnOff = Mem.NTPOnOff = 0;       // If ssid or password invalid turn WIFI/NTP off
 
 StoreStructInFlashMemory();
}
//--------------------------------------------
// COMMON Store mem.struct in FlashStorage or SD
// Preferences.h  
//--------------------------------------------
void StoreStructInFlashMemory(void)
{

// if (pocuter->SDCard->cardIsMounted())      
//  {
//   FILE * fp;
//   char fileName[64];
//   snprintf(fileName, 64, "%s%s", pocuter->SDCard->getMountPoint(), "/MemStore.txt");
//   fp = fopen (fileName, "wb");
//   if (! fp) { sprintf(sptext,"Could not open %s to write!\n", fileName); Tekstprintln(sptext); } 
//   else {
//         fwrite(& Mem , sizeof(Mem),1,fp);
//         fclose(fp); 
////       sprintf(sptext,"File written!: %s\n",fileName); Tekstprintln(sptext); 
//        }    
//   } 
// 
//                    
//  else  
  {  
//  sprintf(sptext,"SDCard not Mounted!\n"); Tekstprintln(sptext);  
  FLASHSTOR.begin("Mem",false);       //  delay(100);
  FLASHSTOR.putBytes("Mem", &Mem , sizeof(Mem) );
  FLASHSTOR.end();          
  }
  
// Can be used as alternative
//  SPIFFS
//  File myFile = SPIFFS.open("/MemStore.txt", FILE_WRITE);
//  myFile.write((byte *)&Mem, sizeof(Mem));
//  myFile.close();



 }
//--------------------------------------------
// COMMON Get data from FlashStorage
// Preferences.h
//--------------------------------------------
void GetStructFromFlashMemory(void)
{
//                
// if (pocuter->SDCard->cardIsMounted()) 
//   {
//     FILE * fp;
//     char fileName[64];
//     snprintf(fileName, 64, "%s%s", pocuter->SDCard->getMountPoint(), "/MemStore.txt");
//     fp = fopen (fileName, "rb");
//     if (! fp) { sprintf(sptext,"Could not open %s to read!\n", fileName); Tekstprintln(sptext); } 
//     else {
//           fread(& Mem, sizeof(Mem),1,fp);
//           fclose(fp); 
//           sprintf(sptext,"Settings from SD-card read!: %s\n",fileName); Tekstprintln(sptext); 
//          }    
//   } 
//  else 
//           
   {  
//    sprintf(sptext,"SDCard not Mounted!\n Using Flashstorage"); Tekstprintln(sptext);  
    FLASHSTOR.begin("Mem", false);
    FLASHSTOR.getBytes("Mem", &Mem, sizeof(Mem) );
    FLASHSTOR.end();         
    }

  sprintf(sptext,"Mem.Checksum = %d",Mem.Checksum);Tekstprintln(sptext); 

// Can be used as alternative
//  File myFile = SPIFFS.open("/MemStore.txt");  FILE_WRITE); myFile.read((byte *)&Mem, sizeof(Mem));  myFile.close();
}

//--------------------------------------------
//  CLOCK Input from Bluetooth or Serial
//--------------------------------------------
void ReworkInputString(String InputString)
{
 char ff[50];  InputString.toCharArray(ff,InputString.length());                              // Convert a String to char array
 sprintf(sptext,"Inputstring: %s  Lengte : %d\n", ff,InputString.length()-1); 
 // Tekstprint(sptext);
 if(InputString.length()> 40){Serial.printf("Input string too long (max40)\n"); return;}                                                         // If garbage return
 sptext[0] = 0;                                                                               // Empty the sptext string
 if(InputString[0] > 31 && InputString[0] <127)                                               // Does the string start with a letter?
  { 
  switch (InputString[0])
   {
    case 'A':
    case 'a': 
            if (InputString.length() >5 )
            {
             InputString.substring(1).toCharArray(Mem.Ssid,InputString.length()-1);
             sprintf(sptext,"SSID set: %s", Mem.Ssid);  
            }
            else sprintf(sptext,"**** Length fault. Use between 4 and 30 characters ****");
            break;
    case 'B':
    case 'b': 
           if (InputString.length() >5 )
            {  
             InputString.substring(1).toCharArray(Mem.Password,InputString.length()-1);
             sprintf(sptext,"Password set: %s\n Enter @ to reset ESP32 and connect to WIFI and NTP", Mem.Password); 
             Mem.NTPOnOff        = 1;                                                         // NTP On
             Mem.WIFIOnOff       = 1;                                                         // WIFI On  
            }
            else sprintf(sptext,"%s,**** Length fault. Use between 4 and 40 characters ****",Mem.Password);
            break;   
    case 'C':
    case 'c': 
           if (InputString.length() >5 )
            {  
             InputString.substring(1).toCharArray(Mem.BLEbroadcastName,InputString.length()-1);
             sprintf(sptext,"BLE broadcast name set: %s", Mem.BLEbroadcastName); 
             Mem.BLEOnOff        = 1;                                                         // BLE On
            }
            else sprintf(sptext,"**** Length fault. Use between 4 and 30 characters ****");
            break;      
    case 'D':
    case 'd':  
            if (InputString.length() == 10 )
              {
               timeinfo.tm_mday = (int) SConstrainInt(InputString,1,3,0,31);
               timeinfo.tm_mon  = (int) SConstrainInt(InputString,3,5,0,12) - 1; 
               timeinfo.tm_year = (int) SConstrainInt(InputString,5,9,2000,9999) - 1900;
               Date_Printed = false;                                                            // Date will be printed in Digital display mode
               SetRTCTime();
               Print_tijd();  //Tekstprintln(sptext);                                           // Print_Tijd() fills sptext with time string
              }
            else sprintf(sptext,"****\nLength fault. Enter Dddmmyyyy\n****");
            break;
    case 'F':
    case 'f':  
             if (InputString.length() == 8 )
               {
                LetterColor = Mem.OwnColour = HexToDec(InputString.substring(1,7));               // Display letter color 
                sprintf(sptext,"Font colour stored0X%X", Mem.OwnColour);
                Tekstprintln("**** Own colour changed ****");    
                Displaytime();
               }
             else sprintf(sptext,"****\nLength fault. Enter Frrggbb hexadecimal (0 - F)\n****");            
             break;
    case 'G':
    case 'g':  
             if (InputString.length() == 8 )
               {
                Mem.DimmedLetter = HexToDec(InputString.substring(1,7));               // Display letter color 
                sprintf(sptext,"Dimmed colour stored0X%X", Mem.DimmedLetter);
                Tekstprintln("**** Dimmed font colour changed ****");    
                Displaytime();
               }
             else sprintf(sptext,"****\nLength fault. Enter Grrggbb hexadecimal (0 - F)\n****");            
             break;
    case 'H':
    case 'h':  
             if (InputString.length() == 8 )
               {
                Mem.BackGround = HexToDec(InputString.substring(1,7));               // Display letter color 
                sprintf(sptext,"Own colour stored0X%X", Mem.BackGround);
                Tekstprintln("**** BackGround colour changed ****");    
                Displaytime();
               }
             else sprintf(sptext,"****\nLength fault. Enter Hrrggbb hexadecimal (0 - F)\n****");            
             break;            
    case 'I':
    case 'i': 
            SWversion();
            break;
    case 'K':
    case 'k':
             TestLDR = 1 - TestLDR;                                                           // If TestLDR = 1 LDR reading is printed every second instead every 30s
             sprintf(sptext,"TestLDR: %s",TestLDR? "On" : "Off");
             break;      
    case 'L':                                                                                   // Language to choose
    case 'l':
             if (InputString.length() == 3 )
               {
                byte res = (byte) InputString.substring(1,2).toInt();   
                Mem.LanguageChoice = res%5;                       // Result between 0 and 4
                byte ch = Mem.LanguageChoice;                
                sprintf(sptext,"Language choice:%s",ch==0?"NL":ch==1?"UK":ch==2?"DE":ch==3?"FR":ch==4?"Rotate language":"NOP"); 
//                Tekstprintln(sptext);
                lastminute = 99;                                  // Force a minute update
               }
             else sprintf(sptext,"****\nDisplay choice length fault. Enter L0 - L4\n****"); 
            break;     

    case 'N':
    case 'n':
             if (InputString.length() == 2 )         Mem.TurnOffLEDsAtHH = Mem.TurnOnLEDsAtHH = 0;
             if (InputString.length() == 6 )
              {
               Mem.TurnOffLEDsAtHH =(byte) InputString.substring(1,3).toInt(); 
               Mem.TurnOnLEDsAtHH = (byte) InputString.substring(3,5).toInt(); 
              }
             Mem.TurnOffLEDsAtHH = _min(Mem.TurnOffLEDsAtHH, 23);
             Mem.TurnOnLEDsAtHH  = _min(Mem.TurnOnLEDsAtHH, 23); 
             sprintf(sptext,"Display is OFF between %2d:00 and %2d:00", Mem.TurnOffLEDsAtHH,Mem.TurnOnLEDsAtHH );
 //            Tekstprintln(sptext); 
             break;
    case 'O':
    case 'o':
             if(InputString.length() == 2)
               {
                LEDsAreOff = !LEDsAreOff;
                sprintf(sptext,"Display is %s", LEDsAreOff?"OFF":"ON" );
                if(LEDsAreOff) { ClearScreen();}                                                  // Turn the display off
                else Displaytime();                                                               // Turn the display on                
               }
             break;                                                                   

    case 'q':
    case 'Q':  
             if (InputString.length() == 3 )
               {
   //             byte OldDC = Mem.DisplayChoice;
                Mem.DisplayChoice = (byte) InputString.substring(1,2).toInt(); 
                sprintf(sptext,"Display choice: Q%d", Mem.DisplayChoice);
                lastminute = 99;                                        // Force a minute update
 //               Mem.DisplayChoice == DIGITAL?PrintDigital=true:PrintDigital=false;               // if DIGITAL display PrintDigital is true
                ClearScreen();
   //             OldDC = Mem.DisplayChoice; ClearScreen();  ------------- nog uitzoeken
               }
             else sprintf(sptext,"**** Display choice length fault. Enter Q0 - Q6"); 
         //    Displaytime();                                             // Turn on the display with proper time 
            break;
    case 'R':
    case 'r':
             if (InputString.length() == 2)
               {   
                Reset();
                sprintf(sptext,"\nReset to default values: Done");
                Displaytime();                                          // Turn on the display with proper time
               }                                
             else sprintf(sptext,"**** Length fault. Enter R ****");
             break;      
    case 'S':                                                                                 // factor ( 0 - 1) to multiply brighness (0 - 255) with 
    case 's':
            if (InputString.length() < 6)
               {    
                Mem.LightReducer = (byte) SConstrainInt(InputString,1,1,255);
                sprintf(sptext,"Slope brightness changed to: %d%%",Mem.LightReducer);
               }
              break;                    
    case 'T':
    case 't':
//                                                                                            //
             if(InputString.length() == 8)  // T125500
               {
                timeinfo.tm_hour = (int) SConstrainInt(InputString,1,3,0,23);
                timeinfo.tm_min  = (int) SConstrainInt(InputString,3,5,0,59); 
                timeinfo.tm_sec  = (int) SConstrainInt(InputString,5,7,0,59);
                SetRTCTime();
                Print_tijd(); 
               }
             else sprintf(sptext,"**** Length fault. Enter Thhmmss ****");
             break;            
    case 'U':                                                                                 // factor to multiply brighness (0 - 255) with 
    case 'u':
            if (InputString.length() < 6)
               {    
                Mem.UpperBrightness = SConstrainInt(InputString,1,1,255);
                sprintf(sptext,"Upper brightness changed to: %d bits",Mem.UpperBrightness);
               }
              break;  
    case 'V':
    case 'v':  
             if (InputString.length() < 6)
               {      
                Mem.LowerBrightness = (byte) SConstrainInt(InputString,1,0,255);
                sprintf(sptext,"Lower brightness: %d bits",Mem.LowerBrightness);
               }
             break;      
    case 'W':
    case 'w':
             if (InputString.length() == 2)
               {   
                Mem.WIFIOnOff = 1 - Mem.WIFIOnOff; 
                sprintf(sptext,"WIFI is %s after restart", Mem.WIFIOnOff?"ON":"OFF" );
               }                                
             else sprintf(sptext,"**** Length fault. Enter W ****");
             break; 
    case 'X':
    case 'x':
             if (InputString.length() == 2)
               {   
                Mem.NTPOnOff = 1 - Mem.NTPOnOff; 
                sprintf(sptext,"NTP is %s after restart", Mem.NTPOnOff?"ON":"OFF" );
               }                                
             else sprintf(sptext,"**** Length fault. Enter X ****");
             break; 
    case 'Y':
    case 'y':
             if (InputString.length() == 2)
               {   
                Mem.BLEOnOff = 1 - Mem.BLEOnOff; 
                sprintf(sptext,"BLE is %s after restart", Mem.BLEOnOff?"ON":"OFF" );
               }                                
             else sprintf(sptext,"**** Length fault. Enter Y ****");
             break; 
    case 'Z':
    case 'z':
             if (InputString.length() == 2)
               {   
                Mem.UseBLELongString = 1 - Mem.UseBLELongString; 
                sprintf(sptext,"Fast BLE is %s", Mem.UseBLELongString?"ON":"OFF" );
               }                                
             else sprintf(sptext,"**** Length fault. Enter U ****");
             break; 
        
    case '@':
             if (InputString.length() == 2)
               {   
               Tekstprintln("\n*********\n ESP restarting\n*********\n");
                ESP.restart();   
               }                                
             else sprintf(sptext,"**** Length fault. Enter @ ****");
             break;     
    case '#':
             if (InputString.length() == 2)
               {   
                Zelftest = 1 - Zelftest; 
                sprintf(sptext,"Zelftest: %d",Zelftest);
                Displaytime();                                          // Turn on the display with proper time
               }                                
             else sprintf(sptext,"**** Length fault. Enter S ****");
             break; 
    case '$':
             if (InputString.length() == 2)
               {   
                Mem.UseSDcard = 1 - Mem.UseSDcard; 
                sprintf(sptext,"SD is %s after restart", Mem.UseSDcard?"used":"NOT used" );
                sprintf(sptext,"This function is not working, .... yet" );
               }                                
             else sprintf(sptext,"**** Length fault. Enter Z ****");
             break; 
    case '&':                                                            // Get NTP time
             if (InputString.length() == 2)
              {
               Tekstprint("NTP query started. \nClock time: ");
               GetTijd(1);
               Tekstprint("\n  NTP time: ");
               PrintNTP_tijd();
               Tekstprintln("");
               } 
             break;
    case '0':
    case '1':
    case '2':        
             if (InputString.length() == 7 )                                                  // For compatibility input with only the time digits
              {
               timeinfo.tm_hour = (int) SConstrainInt(InputString,0,2,0,23);
               timeinfo.tm_min  = (int) SConstrainInt(InputString,2,4,0,59); 
               timeinfo.tm_sec  = (int) SConstrainInt(InputString,4,6,0,59);
               sprintf(sptext,"Time set");  
               SetRTCTime();
               Print_tijd(); 
               } 
    default: break;
    }
  }  
 Tekstprintln(sptext); 
 StoreStructInFlashMemory();                                                                          // Update EEPROM                                     
 InputString = "";
}
//--------------------------------------------
// LDR reading are between 0 and 255. 
// ESP32 analogue read is between 0 - 4096 --   is: 4096 / 8
//--------------------------------------------
int ReadLDR(void)
{
  return analogRead(PhotoCellPin)/16;
}
//--------------------------------------------
// CLOCK Control the LEDs on the ESP32
// -1 leaves intensity untouched
//--------------------------------------------
void SetStatusLED(int WW, int CW, int Re, int Gr, int Bl)
{
 if(Re >=0 ) analogWrite(REDPIN, Re);
 if(Gr >=0 ) analogWrite(GREENPIN, Gr);
 if(Bl >=0 ) analogWrite(BLUEPIN, Bl);
 if(CW >=0 ) analogWrite(COLD_WHITE, CW);
 if(WW >=0 ) analogWrite(WARM_WHITE, WW);
}

//--------------------------------------------
//  LED Dim the leds measured by the LDR and print values
// LDR reading are between 0 and 255. The Brightness send to the LEDs is between 0 and 255
//--------------------------------------------
void DimLeds(bool print) 
{ 
  int LDRread = ReadLDR();                                                                  // ESP32 analoge read is between 0 - 4096, reduce it to 0-1024                                                                                                   
  int LDRavgread = (4 * Previous_LDR_read + LDRread ) / 5;                                  // Read lightsensor and avoid rapid light intensity changes
  Previous_LDR_read = LDRavgread;                                                           // by using the previous reads
  OutPhotocell = (uint32_t)((Mem.LightReducer * sqrt(255*LDRavgread))/100);                 // Linear --> hyperbolic with sqrt. Result is between 0-255
  MinPhotocell = min(MinPhotocell, LDRavgread);                                             // Lowest LDR measurement
  MaxPhotocell = max(MaxPhotocell, LDRavgread);                                             // Highest LDR measurement
  OutPhotocell = constrain(OutPhotocell, Mem.LowerBrightness, Mem.UpperBrightness);         // Keep result between lower and upper boundery en calc percentage
  SumLDRreadshour += LDRavgread;    NoofLDRreadshour++;                                     // For statistics LDR readings per hour
  if(print)
  {
   sprintf(sptext,"LDR:%3d Avg:%3d",LDRread,LDRavgread);    Tekstprint(sptext);
   sprintf(sptext," (%3d-%3d)",MinPhotocell,MaxPhotocell);  Tekstprint(sptext);
   sprintf(sptext," Out:%3d", OutPhotocell);                Tekstprint(sptext);
   sprintf(sptext,"=%2d%% ",(int)(OutPhotocell/2.55) );     Tekstprint(sptext); 
   Print_tijd();  
  }
 if(LEDsAreOff) OutPhotocell = 0;
 SetBrightnessLeds(OutPhotocell);     // values between 0 and 255
}

//--------------------------------------------
//  LED Set color for LED. 
// Fill the struct Strippos with the proper character and its colour
//--------------------------------------------
void ColorLeds(char const *Texkst, int FirstLed, int LastLed, uint32_t RGBColor)
{ 
 int n, i=0;
 char Tekst[135];
  if (!NoTextInColorLeds && (strlen(Texkst) > 0 && strlen(Texkst) <10) )
     {sprintf(sptext,"%s ",Texkst); Tekstprint(sptext); }                                     // Print the text  
                                                                                              // sprintf(sptext," %s, F:%d, L:%d F-L:%d ",Texkst, FirstLed,LastLed,1+LastLed-FirstLed );  Tekstprint(sptext);
 strcpy(Tekst,Texkst);
 to_upper(Tekst);   
 for (n=FirstLed; n<=FirstLed + (LastLed-FirstLed); n++)
 {
  Strippos[n].Character = Tekst[i++];
  Strippos[n].RGBColor = RGBColor;                                                            // Every character has its color stored here
//  sprintf(sptext,"-Strippos[%d].Character=:%c",n, Strippos[n].Character); Tekstprint(sptext);   
 }
}
//                                                                                            //
//--------------------------------------------
//  COMMON String upper
//--------------------------------------------
void to_upper(char* string)
{
 const char OFFSET = 'a' - 'A';
 while (*string)
  {
   (*string >= 'a' && *string <= 'z') ? *string -= OFFSET : *string;
   string++;
  }
}

//------------------------------------------------------------------------------
//  LED Set brightness of backlight
//------------------------------------------------------------------------------  
void SetBrightnessLeds(byte Bright)
{
 SetBackLight(Bright);                                               // Set brightness of LEDs   
}
//--------------------------------------------
//  LED Clear the character string
//--------------------------------------------
void LedsOff(void) 
{ 
 for (int n=0; n<NUM_LEDS; n++) 
     Strippos[n].Character = Strippos[n].RGBColor = 0;                                        // Erase the struct Strippos
}

//--------------------------------------------
//  LED Set second color
//  Set the colour per second of 'IS' and 'WAS'
//--------------------------------------------
void SetSecondColour(void)
{
 switch (Mem.DisplayChoice)
  {
   case DEFAULTCOLOUR: LetterColor = C_YELLOW;
                       MINColor =    C_YELLOW;   // C_GREEN + ((timeinfo.tm_min/2)<<19);
                       SECColor=     C_YELLOW;   //C_GREEN + ((timeinfo.tm_hour/2)<<19);         // (30 << 19 = 0XF00000         
                                                                                    break;
   case HOURLYCOLOUR : LetterColor = MINColor = SECColor = HourColor[timeinfo.tm_hour];       break;    // A colour every hour
   case WHITECOLOR   : LetterColor = MINColor = SECColor = C_WHITE;                 break;    // All white
   case OWNCOLOUR    : LetterColor = MINColor = SECColor = Mem.OwnColour;           break;    // Own colour
   case OWNHETISCLR  : LetterColor = Mem.OwnColour; 
                       MINColor = C_YELLOW;
                       SECColor = C_YELLOW;                                         break;    // Own colour except HET IS WAS  
   case WHEELCOLOR   : LetterColor = MINColor = SECColor = (17*(timeinfo.tm_min*60));      break;    // Colour of all letters changes per minute
   case DIGITAL      : LetterColor = C_WHITE; MINColor = SECColor = C_BLACK;        break;    // Digital display of time. No IS WAS turn color off in display
  }
}
//                                                                                            //
//--------------------------------------------
// CLOCK Version info
//--------------------------------------------
void SWversion(void) 
{ 
 #define FILENAAM (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
 PrintLine(35);
 for (uint8_t i = 0; i < sizeof(menu) / sizeof(menu[0]); Tekstprintln(menu[i++]));
 PrintLine(35);
 byte ch = Mem.LanguageChoice;
 byte dp = Mem.DisplayChoice;
 sprintf(sptext,"     Display off: %02dh - %02dh",Mem.TurnOffLEDsAtHH, Mem.TurnOnLEDsAtHH);  Tekstprintln(sptext);
 sprintf(sptext,"  Display choice: %s",dp==0?"Yellow":dp==1?"Hourly":dp==2?"White":
                      dp==3?"All Own":dp==4?"Own":dp==5?"Wheel":dp==6?"Digital":"NOP");      Tekstprintln(sptext);
 sprintf(sptext,"            SSID: %s", Mem.Ssid);                                           Tekstprintln(sptext);
 
// sprintf(sptext,"        Password: %s", Mem.Password);                                       Tekstprintln(sptext);
 sprintf(sptext,"        BLE name: %s", Mem.BLEbroadcastName);                               Tekstprintln(sptext);
 sprintf(sptext,"      IP-address: %d.%d.%d.%d", 
              WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3] );  Tekstprintln(sptext);
 sprintf(sptext,"Timezone:%s", Mem.Timezone);                                                Tekstprintln(sptext); 
 sprintf(sptext," %s %s %s %s", Mem.WIFIOnOff?"WIFI=On":"WIFI=Off", 
                             Mem.NTPOnOff? "NTP=On":"NTP=Off",
                             Mem.BLEOnOff? "BLE=On":"BLE=Off",
                             Mem.UseBLELongString? "FastBLE=On":"FastBLE=Off" );           Tekstprintln(sptext);
 sprintf(sptext," Language choice: %s",
         ch==0?"NL":ch==1?"UK":ch==2?"DE":ch==3?"FR":ch==4?"Rotate language":"NOP");         Tekstprintln(sptext);
 sprintf(sptext,"Software: %s",FILENAAM);                                                    Tekstprintln(sptext);  //VERSION); 
 Print_tijd(); 
 PrintLine(35);
}
void PrintLine(byte Lengte)
{
 for(int n=0; n<Lengte; n++) sptext[n]='_';
 sptext[Lengte] = 0;
 Tekstprintln(sptext);
}
//                                                                                            //
//--------------------------------------------
// CLOCK Say the time and load the LEDs 
// with the proper colour and intensity
//--------------------------------------------
void Displaytime(void)
{ 
 if (Mem.DisplayChoice == DIGITAL)  //PrintDigital) 
  {
//   ClearScreen();
   PrintTimeInScreen();
  }
 else
  {
   byte Language;                                                                     // Start by clearing the display to a known state 
   SetSecondColour();
   if(Mem.LanguageChoice == 4)  Language = random(4);
   else                         Language = Mem.LanguageChoice;
   switch(Language)                                                                  //
     {
      case 0: 
      strncpy(Template,"HETVISOWASOVIJFQPRECIESZSTIENKPFKWARTSVOORSOVERAHALFSMIDDERTVIJFATWEESOEENOXVIERELFQTIENKTWAALFBHDRIECNEGENACHTFZESVZEVENOENVUUR",129);  
              ColorLeds(Template,0,127, Mem.DimmedLetter);
              Dutch(); Print_tijd();   break;
      case 1: 
      strncpy(Template,"HITVISOWASOEXACTHALFITWENTYEFIVEQUARTERTENZPASTATOLFSMIDKSIXVTWOFIVEETWELVEXTENRELEVENENFOURAONETEIGHTHREENIGHTFNINESEVENROCLOCK",129);  
              ColorLeds(Template,0,127, Mem.DimmedLetter);
              English(); Print_tijd(); break;
      case 2: 
      strncpy(Template,"ESTISTWARSGENAUTZEHNFUNFVIERTELQZWANZIGTKURZAVORNACHYHALBKFUNFBOEINSEVIERZWOLFARMITTERNACHTNDREISECHHNSIEBENEUNBZWEIZEHNELFMKUHR",129);
              ColorLeds(Template,0,127, Mem.DimmedLetter); 
              German(); Print_tijd();  break;
      case 3:
      strncpy(Template,"ILWESTETAITEXACTSIXDEUXTROISONZEQUATRERMINUITDIXCINQNEUFKMIDISWOHUITESEPTUNEDOSRHEURESYETOMOINSELETDEMIENEQUARTNDIXEVINGTOCINQKR",129); 
              ColorLeds(Template,0,127, Mem.DimmedLetter);
              French(); Print_tijd();  break;
     }
//      ClearScreen();
      ShowChars(); 
   }
}
//--------------------------- Time functions --------------------------
//                                                                                            //
//--------------------------------------------
// RTC Get time from NTP cq RTC 
// and store it in timeinfo struct
//--------------------------------------------
void GetTijd(byte printit)
{
 if(Mem.NTPOnOff) getLocalTime(&timeinfo);                                                  // if NTP is running get the loacal time
else { 
      time_t now = time(NULL);
      localtime_r(&now, &timeinfo);
    } 
 if (printit)  Print_RTC_tijd();                                                            // otherwise time in OK struct timeonfo
}
//--------------------------------------------
// RTC prints time to serial
//--------------------------------------------
void Print_RTC_tijd(void)
{
 sprintf(sptext,"%02d:%02d:%02d %02d-%02d-%04d  ", 
     timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec,
     timeinfo.tm_mday,timeinfo.tm_mon,timeinfo.tm_year+1900);
 Tekstprint(sptext);
}
//--------------------------------------------
// NTP print the NTP time for the timezone set 
//--------------------------------------------
void PrintNTP_tijd(void)
{
 sprintf(sptext,"%s  ", NTP.getTimeDateString());  
 Tekstprint(sptext);              // 17/10/2022 16:08:15

// int dd,mo,yy,hh,mm,ss=0;      // nice method to extract the values from a string into vaiabeles
// if (sscanf(sptext, "%2d/%2d/%4d %2d:%2d:%2d", &dd, &mo, &yy, &hh, &mm, &ss) == 6) 
//     {      sprintf(sptext,"%02d:%02d:%02d %02d-%02d-%04d", hh,mm,ss,dd,mo,yy);      Tekstprintln(sptext); }
}


//--------------------------------------------
// NTP print the NTP UTC time 
//--------------------------------------------
void PrintUTCtijd(void)
{
 time_t rawtime;
 struct tm *UTCtime;
 time(&rawtime); 
 gmtime_r(&rawtime, UTCtime );              // obsolete function.  UTCtime = gmtime(&rawtime );
 sprintf(sptext,"%02d:%02d:%02d %02d-%02d-%04d  ", 
     UTCtime->tm_hour,UTCtime->tm_min,UTCtime->tm_sec,
     UTCtime->tm_mday,UTCtime->tm_mon,UTCtime->tm_year+1900);
 Tekstprint(sptext);   
}
//--------------------------------------------
// RTC Fill sptext with time
//--------------------------------------------
void Print_tijd(){ Print_tijd(2);}                          // print with linefeed
void Print_tijd(byte format)
{
 sprintf(sptext,"%02d:%02d:%02d",timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec);
 switch (format)
 {
  case 0: break;
  case 1: Tekstprint(sptext); break;
  case 2: Tekstprintln(sptext); break;  
 }

}

//--------------------------------------------
// RTC Set time from global timeinfo struct
// Check if values are within range
//--------------------------------------------
void SetRTCTime(void)
{ 
 time_t t = mktime(&timeinfo);
 sprintf(sptext, "Setting time: %s", asctime(&timeinfo)); Tekstprintln(sptext);
 struct timeval now = { .tv_sec = t };
 settimeofday(&now, NULL);
// GetTijd(0);                                                                                  // Synchronize time with RTC clock
 Displaytime();
 Print_tijd();
}

//                                                                                            //
// ------------------- End  Time functions 

//--------------------------------------------
//  CLOCK Convert Hex to uint32
//--------------------------------------------
uint32_t HexToDec(String hexString) 
{
 uint32_t decValue = 0;
 int nextInt;
 for (uint8_t i = 0; i < hexString.length(); i++) 
  {
   nextInt = int(hexString.charAt(i));
   if (nextInt >= 48 && nextInt <= 57)  nextInt = map(nextInt, 48, 57, 0, 9);
   if (nextInt >= 65 && nextInt <= 70)  nextInt = map(nextInt, 65, 70, 10, 15);
   if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
   nextInt = constrain(nextInt, 0, 15);
   decValue = (decValue * 16) + nextInt;
  }
 return decValue;
}
//                                                                                            //
//--------------------------------------------
//  CLOCK Dutch clock display
//--------------------------------------------
void Dutch(void)
{
HET;                                                                                          // HET  is always on
 if (timeinfo.tm_hour == 12 && timeinfo.tm_min == 0 && random(2)==0) { IS; NOEN; return; }
 if (timeinfo.tm_hour == 00 && timeinfo.tm_min == 0 && random(2)==0) { IS; MIDDER; NACHT; return; } 
switch (timeinfo.tm_min)
 {
  case  0: IS;  PRECIES; break;
  case  1: IS;  break;
  case  2: 
  case  3: WAS; break;
  case  4: 
  case  5: 
  case  6: IS;  MVIJF; OVER; break;
  case  7: 
  case  8: WAS; MVIJF; OVER; break;
  case  9: 
  case 10: 
  case 11: IS;  MTIEN; OVER; break;
  case 12: 
  case 13: WAS; MTIEN; OVER; break;
  case 14: 
  case 15: 
  case 16: IS;  KWART; OVER; break;
  case 17: 
  case 18: WAS; KWART; OVER; break;
  case 19: 
  case 20: 
  case 21: IS;  MTIEN; VOOR; HALF; break;
  case 22: 
  case 23: WAS; MTIEN; VOOR; HALF; break;
  case 24: 
  case 25: 
  case 26: IS;  MVIJF; VOOR; HALF; break;
  case 27: 
  case 28: WAS; MVIJF; VOOR; HALF; break;
  case 29: IS;  HALF; break;
  case 30: IS;  PRECIES; HALF; break;
  case 31: IS;  HALF; break;
  case 32: 
  case 33: WAS; HALF; break;
  case 34: 
  case 35: 
  case 36: IS;  MVIJF; OVER; HALF; break;
  case 37: 
  case 38: WAS; MVIJF; OVER; HALF; break;
  case 39: 
  case 40: 
  case 41: IS;  MTIEN; OVER; HALF; break;
  case 42: 
  case 43: WAS; MTIEN; OVER; HALF; break;
  case 44: 
  case 45: 
  case 46: IS;  KWART; VOOR; break;
  case 47: 
  case 48: WAS; KWART; VOOR; break;
  case 49: 
  case 50: 
  case 51: IS;  MTIEN; VOOR;  break;
  case 52: 
  case 53: WAS; MTIEN; VOOR;  break;
  case 54: 
  case 55: 
  case 56: IS;  MVIJF; VOOR; break;
  case 57: 
  case 58: WAS; MVIJF; VOOR; break;
  case 59: IS;  break;
}
//if (timeinfo.tm_hour >=0 && hour <12) digitalWrite(AMPMpin,0); else digitalWrite(AMPMpin,1);

 sayhour = timeinfo.tm_hour;
 if (timeinfo.tm_min > 18 )  sayhour = timeinfo.tm_hour+1;
 if (sayhour == 24) sayhour = 0;

switch (sayhour)
 {
  case 13:  
  case 1: EEN; break;
  case 14:
  case 2: TWEE; break;
  case 15:
  case 3: DRIE; break;
  case 16:
  case 4: VIER; break;
  case 17:
  case 5: VIJF; break;
  case 18:
  case 6: ZES; break;
  case 19:
  case 7: ZEVEN; break;
  case 20:
  case 8: ACHT; break;
  case 21:
  case 9: NEGEN; break;
  case 22:
  case 10: TIEN; break;
  case 23:
  case 11: ELF; break;
  case 0:
  case 12: TWAALF; break;
 } 
 switch (timeinfo.tm_min)
 {
  case 59: 
  case  0: 
  case  1: 
  case  2: 
  case  3: UUR;  break; 
 }
}

//--------------------------------------------
//  CLOCK English clock display
//--------------------------------------------
void English(void)
{
 IT;                                                                                          // IT is always on
 if (timeinfo.tm_hour == 00 && timeinfo.tm_min == 0 && random(2)==0) { ISUK; MID; NIGHT; return; } 
 switch (timeinfo.tm_min)
 {
  case  0: ISUK;  EXACTUK; break;
  case  1: ISUK;  break;
  case  2: 
  case  3: WASUK; break;
  case  4: 
  case  5: 
  case  6: ISUK;  MFIVE; PAST; break;
  case  7: 
  case  8: WASUK; MFIVE; PAST; break;
  case  9: 
  case 10: 
  case 11: ISUK;  MTEN; PAST; break;
  case 12: 
  case 13: WASUK; MTEN; PAST; break;
  case 14: 
  case 15: 
  case 16: ISUK;  QUARTER; PAST; break;
  case 17: 
  case 18: WASUK; QUARTER; PAST; break;
  case 19: 
  case 20: 
  case 21: ISUK;  TWENTY; PAST; break;
  case 22: 
  case 23: WASUK; TWENTY; PAST; break;
  case 24: 
  case 25: 
  case 26: ISUK;  TWENTY; MFIVE; PAST; break;
  case 27: 
  case 28: WASUK; TWENTY; MFIVE; PAST; break;
  case 29: ISUK;  HALFUK; PAST; break;
  case 30: ISUK;  EXACTUK; HALFUK; PAST; break;
  case 31: ISUK;  HALFUK; PAST; break;
  case 32: 
  case 33: WASUK; HALFUK; PAST; break;
  case 34: 
  case 35: 
  case 36: ISUK;  TWENTY; MFIVE; TO; break;
  case 37: 
  case 38: WASUK; TWENTY; MFIVE; TO; break;
  case 39: 
  case 40: 
  case 41: ISUK;  TWENTY; TO; break;
  case 42: 
  case 43: WASUK; TWENTY; TO break;
  case 44: 
  case 45: 
  case 46: ISUK;  QUARTER; TO; break;
  case 47: 
  case 48: WASUK; QUARTER; TO; break;
  case 49: 
  case 50: 
  case 51: ISUK;  MTEN; TO;  break;
  case 52: 
  case 53: WASUK; MTEN; TO;  break;
  case 54: 
  case 55: 
  case 56: ISUK;  MFIVE; TO; break;
  case 57: 
  case 58: WASUK; MFIVE; TO; break;
  case 59: ISUK;  break;
}
//if (timeinfo.tm_hour >=0 && hour <12) digitalWrite(AMPMpin,0); else digitalWrite(AMPMpin,1);

 sayhour = timeinfo.tm_hour;
 if (timeinfo.tm_min > 33 ) sayhour = timeinfo.tm_hour+1;
 if (sayhour == 24) sayhour = 0;

switch (sayhour)
 {
  case 13:  
  case 1:  ONE; break;
  case 14:
  case 2:  TWO; break;
  case 15:
  case 3:  THREE; break;
  case 16:
  case 4:  FOUR; break;
  case 17:
  case 5:  FIVE; break;
  case 18:
  case 6:  SIXUK; break;
  case 19:
  case 7:  SEVEN; break;
  case 20:
  case 8:  EIGHT; break;
  case 21:
  case 9:  NINE; break;
  case 22:
  case 10: TEN; break;
  case 23:
  case 11: ELEVEN; break;
  case 0:
  case 12: TWELVE; break;
 } 
 switch (timeinfo.tm_min)
 {
  case 59: 
  case  0: 
  case  1: 
  case  2: 
  case  3: OCLOCK;  break; 
 }
}
//--------------------------------------------
//  CLOCK German clock display
//--------------------------------------------
void German(void)
{
  ES;                                                                                            // ES is always on
 if (timeinfo.tm_hour == 00 && timeinfo.tm_min == 0 && random(2)==0) {IST; MITTER; NACHTDE; return; } 
 switch (timeinfo.tm_min)
 {
  case  0: IST;  GENAU; break;
  case  1: IST; KURZ; NACH; break;
  case  2: 
  case  3: WAR; break;
  case  4: 
  case  5: 
  case  6: IST; MFUNF; NACH; break;
  case  7: 
  case  8: WAR; MFUNF; NACH; break;
  case  9: 
  case 10: 
  case 11: IST; MZEHN; NACH; break;
  case 12: 
  case 13: WAR; MZEHN; NACH; break;
  case 14: 
  case 15: 
  case 16: IST; VIERTEL; NACH; break;
  case 17: 
  case 18: WAR; VIERTEL; NACH; break;
  case 19: 
  case 20: 
  case 21: IST; MZEHN; VOR; HALB; break;
  case 22: 
  case 23: WAR; MZEHN; VOR; HALB; break;
  case 24: 
  case 25: 
  case 26: IST; MFUNF; VOR; HALB; break;
  case 27: 
  case 28: WAR; MFUNF; VOR; HALB; break;
  case 29: IST; KURZ;  VOR; HALB; break;
  case 30: IST; GENAU; HALB; break;
  case 31: IST; KURZ;  NACH; HALB; break;
  case 32: 
  case 33: WAR; HALB; break;
  case 34: 
  case 35: 
  case 36: IST; MFUNF; NACH; HALB; break;
  case 37: 
  case 38: WAR; MFUNF; NACH; HALB; break;
  case 39: 
  case 40: 
  case 41: IST; MZEHN; NACH; HALB; break;
  case 42: 
  case 43: WAR; MZEHN; NACH; HALB; break;
  case 44: 
  case 45: 
  case 46: IST; VIERTEL; VOR; break;
  case 47: 
  case 48: WAR; VIERTEL; VOR; break;
  case 49: 
  case 50: 
  case 51: IST; MZEHN; VOR;  break;
  case 52: 
  case 53: WAR; MZEHN; VOR;  break;
  case 54: 
  case 55: 
  case 56: IST; MFUNF; VOR; break;
  case 57: 
  case 58: WAR; MFUNF; VOR; break;
  case 59: IST;  break;
}
//if (timeinfo.tm_hour >=0 && hour <12) digitalWrite(AMPMpin,0); else digitalWrite(AMPMpin,1);

 sayhour = timeinfo.tm_hour;
 if (timeinfo.tm_min > 18 ) sayhour = timeinfo.tm_hour+1;
 if (sayhour == 24) sayhour = 0;

switch (sayhour)
 {
  case 13:  
  case 1: EINS; break;
  case 14:
  case 2: ZWEI; break;
  case 15:
  case 3: DREI; break;
  case 16:
  case 4: VIERDE; break;
  case 17:
  case 5: FUNF; break;
  case 18:
  case 6: SECHS; break;
  case 19:
  case 7: SIEBEN; break;
  case 20:
  case 8: ACHTDE; break;
  case 21:
  case 9: NEUN; break;
  case 22:
  case 10: ZEHN; break;
  case 23:
  case 11: ELFDE; break;
  case 0:
  case 12: ZWOLF; break;
 } 
 switch (timeinfo.tm_min)
 {
  case 59: 
  case  0: 
  case  1: 
  case  2: 
  case  3: UHR;  break; 
 }
}
//--------------------------------------------
//  CLOCK French clock display
//--------------------------------------------
void French(void)
{
 IL;                                                                                          // IL is always on
 switch (timeinfo.tm_min)
 {
  case  0: EST;   EXACT; DITLEHEURE; break;
  case  1: EST;   DITLEHEURE; break;
  case  2: 
  case  3: ETAIT; DITLEHEURE; break;
  case  4: 
  case  5: 
  case  6: EST;   DITLEHEURE; MCINQ; break;
  case  7: 
  case  8: ETAIT; DITLEHEURE; MCINQ; break;
  case  9: 
  case 10: 
  case 11: EST;   DITLEHEURE; MDIX;  break;
  case 12: 
  case 13: ETAIT; DITLEHEURE; MDIX;  break;
  case 14: 
  case 15: 
  case 16: EST;   DITLEHEURE; ET; QUART; break;
  case 17: 
  case 18: ETAIT; DITLEHEURE; ET; QUART; break;
  case 19: 
  case 20: 
  case 21: EST;   DITLEHEURE; VINGT; break;
  case 22: 
  case 23: ETAIT; DITLEHEURE; VINGT; break;
  case 24: 
  case 25: 
  case 26: EST;   DITLEHEURE; VINGT; MCINQ; break;
  case 27: 
  case 28: ETAIT; DITLEHEURE; VINGT; MCINQ; break;
  case 29: EST;   DITLEHEURE; ET; DEMI; break;
  case 30: EST;   EXACT; DITLEHEURE;  ET; DEMI; break;
  case 31: EST;   DITLEHEURE; ET; DEMI; break;
  case 32: 
  case 33: ETAIT; DITLEHEURE; ET; DEMI; break;
  case 34: 
  case 35: 
  case 36: EST;   DITLEHEURE; MOINS; VINGT; MCINQ; break;
  case 37: 
  case 38: ETAIT; DITLEHEURE; MOINS; VINGT; MCINQ; break;
  case 39: 
  case 40: 
  case 41: EST;   DITLEHEURE; MOINS; VINGT;  break;
  case 42: 
  case 43: ETAIT; DITLEHEURE; MOINS; VINGT;  break;
  case 44: 
  case 45: 
  case 46: EST;   DITLEHEURE; MOINS; LE; QUART; break;
  case 47: 
  case 48: ETAIT; DITLEHEURE; MOINS; LE; QUART; break;
  case 49: 
  case 50: 
  case 51: EST;   DITLEHEURE; MOINS; MDIX;   break;
  case 52: 
  case 53: ETAIT; DITLEHEURE; MOINS; MDIX;   break;
  case 54: 
  case 55: 
  case 56: EST;   DITLEHEURE; MOINS; MCINQ;  break;
  case 57: 
  case 58: ETAIT; DITLEHEURE; MOINS; MCINQ;  break;
  case 59: EST;   DITLEHEURE;  break;
 }
}

void DitLeHeure(void)
{
 byte sayhour = timeinfo.tm_hour;
 if (timeinfo.tm_min > 33 ) sayhour = timeinfo.tm_hour+1;
 if (sayhour == 24) sayhour = 0;

switch (sayhour)
 {
  case 13:  
  case 1:  UNE;    HEURE;  break;
  case 14:
  case 2:  DEUX;   HEURES;  break;
  case 15:
  case 3:  TROIS;  HEURES;  break;
  case 16:
  case 4:  QUATRE; HEURES; break;
  case 17:
  case 5:  CINQ;   HEURES;   break;
  case 18:
  case 6:  SIX;    HEURES;   break;
  case 19:
  case 7:  SEPT;   HEURES;  break;
  case 20:
  case 8:  HUIT;   HEURES; break;
  case 21:
  case 9:  NEUF;   HEURES; break;
  case 22:
  case 10: DIX;    HEURES; break;
  case 23:
  case 11: ONZE;   HEURES; break;
  case 0:  MINUIT; break;
  case 12: MIDI;   break;
 } 
}
//                                                                                            //

//-----------------------------
// BLE 
// SendMessage by BLE Slow in packets of 20 chars
// or fast in one long string.
// Fast can be used in IOS app BLESerial Pro
//------------------------------
void SendMessageBLE(std::string Message)
{
 if(deviceConnected) 
   {
    if (Mem.UseBLELongString)                                                                 // If Fast transmission is possible
     {
      pTxCharacteristic->setValue(Message); 
      pTxCharacteristic->notify();
      delay(10);                                                                              // Bluetooth stack will go into congestion, if too many packets are sent
     } 
   else                                                                                      // Packets of max 20 bytes
     {   
      int parts = (Message.length()/20) + 1;
      for(int n=0;n<parts;n++)
        {   
         pTxCharacteristic->setValue(Message.substr(n*20, 20)); 
         pTxCharacteristic->notify();
         delay(40);                                                                           // Bluetooth stack will go into congestion, if too many packets are sent
        }
     }
   } 
}

//-----------------------------
// BLE Start BLE Classes
//------------------------------
class MyServerCallbacks: public BLEServerCallbacks 
{
 void onConnect(BLEServer* pServer) {deviceConnected = true; };
 void onDisconnect(BLEServer* pServer) {deviceConnected = false;}
};

class MyCallbacks: public BLECharacteristicCallbacks 
{
 void onWrite(BLECharacteristic *pCharacteristic) 
  {
   std::string rxValue = pCharacteristic->getValue();
   ReceivedMessageBLE = rxValue + "\n";
//   if (rxValue.length() > 0) {for (int i = 0; i < rxValue.length(); i++) printf("%c",rxValue[i]); }
//   printf("\n");
  }  
};

//-----------------------------
// BLE Start BLE Service
//------------------------------
void StartBLEService(void)
{
 BLEDevice::init(Mem.BLEbroadcastName);                                                          // Create the BLE Device
 pServer = BLEDevice::createServer();                                                         // Create the BLE Server
 pServer->setCallbacks(new MyServerCallbacks());
 BLEService *pService = pServer->createService(SERVICE_UUID);                                 // Create the BLE Service
 pTxCharacteristic                     =                                                      // Create a BLE Characteristic 
     pService->createCharacteristic(CHARACTERISTIC_UUID_TX, NIMBLE_PROPERTY::NOTIFY);                 
 BLECharacteristic * pRxCharacteristic = 
     pService->createCharacteristic(CHARACTERISTIC_UUID_RX, NIMBLE_PROPERTY::WRITE);
 pRxCharacteristic->setCallbacks(new MyCallbacks());
 pService->start(); 
 BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
 pAdvertising->addServiceUUID(SERVICE_UUID); 
 pServer->start();                                                                            // Start the server  Nodig??
 pServer->getAdvertising()->start();                                                          // Start advertising
 TekstSprint("BLE Waiting a client connection to notify ...\n"); 
}
//                                                                                            //
//-----------------------------
// BLE  CheckBLE
//------------------------------
void CheckBLE(void)
{
 if(!deviceConnected && oldDeviceConnected)                                                   // Disconnecting
   {
    delay(500);                                                                               // Give the bluetooth stack the chance to get things ready
    pServer->startAdvertising();                                                              // Restart advertising
    TekstSprint("Start advertising\n");
    SetStatusLED(-1,-1,-1,-1, 0);                                                             // Turn off blue LED
    oldDeviceConnected = deviceConnected;
   }
 if(deviceConnected && !oldDeviceConnected)                                                   // Connecting
   { 
    SetStatusLED(-1,-1,-1,-1, 8);                                                             // Turn on blue LED
    oldDeviceConnected = deviceConnected;
    SWversion();
   }
 if(ReceivedMessageBLE.length()>0)
   {
    SendMessageBLE(ReceivedMessageBLE);
    String BLEtext = ReceivedMessageBLE.c_str();
    ReceivedMessageBLE = "";
    ReworkInputString(BLEtext); 
   }
}
//                                                                                            //


// -------------------------------------------                                                //
/* Avaiable functions for the ILI9341 display
// -------------------------------------------
 void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
 void fillScreen(uint16_t color);
 void setTextSize(uint8_t s);
 void setTextSize(uint8_t sx, uint8_t sy);
 void setFont(const GFXfont *f = NULL);
 void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
 void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y);
 virtual void setRotation(uint8_t r);
 virtual void invertDisplay(bool i);

 void setCursor(int16_t x, int16_t y)
 void setTextColor(uint16_t c, uint16_t bg)
 void setTextWrap(bool w) { wrap = w; }
 int16_t width(void) const { return _width; };
 int16_t height(void) const { return _height; }
 uint8_t getRotation(void) const { return rotation; }
 int16_t getCursorX(void) const { return cursor_x; }
 int16_t getCursorY(void) const { return cursor_y; };
*/
//--------------------------------------------
//  SCREEN Init screen
//--------------------------------------------
void InitScreen(void)
{
 tft.begin();
 SetBackLight(0XA0);   // Turn on the backlight 0 - 0xFF
 tft.setRotation(3);
 tft.fillScreen(ConvertRGB32toRGB16(C_ORANGE));                                         // Convert colors to RGB16, except C_BLACK (=0x000000)
 tft.setTextColor(C_BLACK, ConvertRGB32toRGB16(C_ORANGE));                              // Convert colors to RGB16, except C_BLACK (=0x000000)
 tft.setCursor(20, tft.height()/3);
 tft.setTextSize(2);
 tft.println("Starting");
}

//--------------------------------------------
//  SCREEN Cobvert 32 bit RGBW to 16 bit RGB
//--------------------------------------------
unsigned short ConvertRGB32toRGB16(uint32_t sourceColor)
{
  uint32_t red   = (sourceColor & 0x00FF0000) >> 16;
  uint32_t green = (sourceColor & 0x0000FF00) >> 8;
  uint32_t blue  =  sourceColor & 0x000000FF;
  return (red >> 3 << 11) + (green >> 2 << 5) + (blue >> 3);
}

//--------------------------------------------
//  SCREEN Make the the screen black
//--------------------------------------------
void ClearScreen(void) 
{ 
  tft.fillScreen(Mem.BackGround);
}
//--------------------------------------------
//  SCREEN Set intensity backlight (0 -255)
//--------------------------------------------
void SetBackLight(byte intensity)
{ 
 analogWrite(TFT_LED, intensity); 
}
//                                                                                            //
//--------------------------------------------
//  SCREEN 
//  Print characters on the display with black background
//--------------------------------------------
void ShowChars(void)
{
 int LEDnr = 0;
 for(int y = 0; y < MATRIX_HEIGHT; y++)
    for(int x = 0; x < MATRIX_WIDTH; x++, LEDnr++)
       {
        tft.drawChar(20 * x, 10 + 27 * y, Strippos[LEDnr].Character, 
                      ConvertRGB32toRGB16(Strippos[LEDnr].RGBColor), 
                            ConvertRGB32toRGB16(Mem.BackGround), 2); 
        CheckDevices();                                                                         // printing is slow, we need a check here too
       }     
}
//--------------------------------------------
//  SCREEN Print the digital time in screen
//--------------------------------------------
void PrintTimeInScreen(void) 
{
 tft.setTextColor(ConvertRGB32toRGB16(C_WHITE), C_BLACK);                                       // Convert colors to RGB16, except C_BLACK (=0x000000)
 GetTijd(0); 
// ClearScreen(); 
 tft.setCursor(20, 20);
 if(Mem.WIFIOnOff && !IP_Printed) { PrintIPaddressInScreen(); IP_Printed = true; }              // If WIFI is on print the IP-address
 sprintf(sptext,"%02d:%02d:%02d",timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec);
  tft.setCursor(20, 60);
 Displayprint(sptext); 
 if (Date_Printed)  return;
 sprintf(sptext,"%02d-%02d-%04d",timeinfo.tm_mday,timeinfo.tm_mon,timeinfo.tm_year+1900);
 tft.setCursor(20, 100);
 Displayprint(sptext);
 Date_Printed = true;
}
//--------------------------------------------
//  SCREEN 
// Print Web server IP address in screen
//--------------------------------------------
void PrintIPaddressInScreen()
{
 sprintf(sptext, "%d.%d.%d.%d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3] );
 Displayprintln(sptext);
}
//                                                                                            //
//--------------------------------------------
// WIFI WEBPAGE 
//--------------------------------------------
void StartWIFI_NTP(void)
{
 WiFi.mode(WIFI_STA);
 WiFi.begin (Mem.Ssid, Mem.Password);
 if (WiFi.waitForConnectResult() != WL_CONNECTED) 
      { 
       Displayprintln("WiFi Failed!");                                                         // Print the text on the display
       Tekstprintln("WiFi Failed!"); 
       WIFIConnected = 0;       
       return;
      }
 else {
       Tekstprint("Web page started\n");
       sprintf(sptext, "IP Address: %d.%d.%d.%d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3] );
       Displayprintln(sptext);
       Tekstprintln(sptext); 

       WIFIConnected = 1;
       Displayprintln("WIFI is On"); 
       if(Mem.NTPOnOff)
          {
           NTP.setTimeZone(Mem.Timezone);                                                    // TZ_Europe_Amsterdam); //\TZ_Etc_GMTp1); // TZ_Etc_UTC 
           NTP.begin ();                                                                     // https://raw.githubusercontent.com/nayarsystems/posix_tz_db/master/zones.csv
           Tekstprintln("NTP On"); 
           Displayprintln("NTP is On");                                                      // Print the text on the display
          }
       PrintIPaddressInScreen();
      }
 if(Mem.WIFIOnOff) WebPage();                                                                // Show the web page if WIFI is on
}

//--------------------------------------------
// WIFI WEBPAGE 
//--------------------------------------------
void WebPage(void) 
{
 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)                                  // Send web page with input fields to client
          { request->send_P(200, "text/html", index_html);  }    );
 server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request)                              // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
       { 
        String inputMessage;    String inputParam;
        if (request->hasParam(PARAM_INPUT_1))                                                 // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
           {
            inputMessage = request->getParam(PARAM_INPUT_1)->value();
            inputParam = PARAM_INPUT_1;
           }
        else 
           {
            inputMessage = "";    //inputMessage = "No message sent";
            inputParam = "none";
           }  
        sprintf(sptext,"%s",inputMessage);    Tekstprintln(sptext);
        ReworkInputString(inputMessage+"\n");
        request->send_P(200, "text/html", index_html);
       }   );
 server.onNotFound(notFound);
 server.begin();
}


void notFound(AsyncWebServerRequest *request) 
{
  request->send(404, "text/plain", "Not found");
}
//                                                                                            //
