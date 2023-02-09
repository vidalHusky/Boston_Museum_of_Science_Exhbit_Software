/*
  Final Project: Team 2 Museum Exhibit
  Written By: J. Vidal, A. Lamontagne, J.Ports, W. Rising

*/
#include <FastLED.h> //import FastLED library to controll strip LED's 

//actual pins that LEDS will go to
#define morning_LEDZ1 3
#define morning_LEDZ2 4

#define day_LEDZ1 5
#define day_LEDZ2 6

#define evening_LEDZ1 7
#define evening_LEDZ2 8

#define night_LEDZ1 9
#define night_LEDZ2 10

#define batteries_LEDZ 11
#define overUse_LEDZ 2

#define marioLED 13




//creating array to control LEDs, the # in brackets is the # of LEDS in the strip
CRGB morning_LED1_ARRAY[4];
CRGB morning_LED2_ARRAY[4];

CRGB day_LED1_ARRAY[3];
CRGB day_LED2_ARRAY[3];

CRGB evening_LED1_ARRAY[6];
CRGB evening_LED2_ARRAY[6];

CRGB night_LED1_ARRAY[2];
CRGB night_LED2_ARRAY[2];

CRGB batteries_LED_ARRAY[3];
CRGB overUse_LED_ARRAY[5];
CRGB mario_LED_ARRAY[2];


//initializes all the pins for the game board voltage readings and buttons
const int morning_LED = A0;
const int day_LED = A1;
const int evening_LED = A2;
const int night_LED = A3;
const int battery_LED = A4;
const int button = 12;
int buttonState;



void setup() {

  //initialize all the LED strips to their corresponding arrays and to their corresponding lengths in accordance to the FastLED library
  FastLED.addLeds<WS2812B, morning_LEDZ1, GRB>(morning_LED1_ARRAY, 4);
  FastLED.addLeds<WS2812B, morning_LEDZ2, GRB>(morning_LED2_ARRAY, 4);
  FastLED.addLeds<WS2812B, day_LEDZ1, GRB>(day_LED1_ARRAY, 3);
  FastLED.addLeds<WS2812B, day_LEDZ2, GRB>(day_LED2_ARRAY, 3);
  FastLED.addLeds<WS2812B, evening_LEDZ1, GRB>(evening_LED1_ARRAY, 6);
  FastLED.addLeds<WS2812B, evening_LEDZ2, GRB>(evening_LED2_ARRAY, 6);
  FastLED.addLeds<WS2812B, night_LEDZ1, GRB>(night_LED1_ARRAY, 2);
  FastLED.addLeds<WS2812B, night_LEDZ2, GRB>(night_LED2_ARRAY, 2);
  FastLED.addLeds<WS2812B, batteries_LEDZ, GRB>(batteries_LED_ARRAY, 3);
  FastLED.addLeds<WS2812B, overUse_LEDZ, GRB>(overUse_LED_ARRAY, 5);
  FastLED.addLeds<WS2812B, marioLED, GRB>(mario_LED_ARRAY, 2);
  FastLED.setBrightness(50);

  //intializes the button
  pinMode(button, INPUT_PULLUP);
  //pinMode(batteryLED_Pin, INPUT);
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}

void loop() {

  //    float voltage = getVoltage(night_LED);
  //    Serial.println(voltage);
  //    Serial.println("--------------------------------------");
  //    delay(1000);

  //
  //
  //  //initialize all LED's to be white color
  for (int i = 0; i < 2; i++) {
    mario_LED_ARRAY[i] = CRGB(255, 255, 255);
  }


  for (int i = 0; i < 4; i++) {
    morning_LED1_ARRAY[i] = CRGB(255, 255, 255);
    morning_LED2_ARRAY[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
  for (int i = 0; i < 3; i++) {
    day_LED1_ARRAY[i] = CRGB(255, 255, 255);
    day_LED2_ARRAY[i] = CRGB(255, 255, 255);
    batteries_LED_ARRAY[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
  for (int i = 0; i < 6; i++) {
    evening_LED1_ARRAY[i] = CRGB(255, 255, 255);
    evening_LED2_ARRAY[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
  for (int i = 0; i < 2; i++) {
    night_LED1_ARRAY[i] = CRGB(255, 255, 255);
    night_LED2_ARRAY[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
  for (int i = 0; i < 5; i++) {
    overUse_LED_ARRAY[i] = CRGB(255, 255, 255);
  }

  FastLED.show();//displays LEDs


  //true statement to keep while loop running
  bool win = true;
  //counters to be used when checking voltages for the morning, day, evening, and night, and batteries
  int batteryLED;
  int solarMorning = 0;
  int windMorning = 0;
  int nuclearMorning = 0;

  int solarDay = 0;
  int windDay = 0;
  int nuclearDay = 0;

  int solarEvening = 0;
  int windEvening = 0;
  int nuclearEvening = 0;

  int solarNight = 0;
  int windNight = 0;
  int nuclearNight = 0;
  bool GREAT_TRUTH = false;

  while (win == true) { //while true do this stuff
    //CHECK MORNING FIRST
    float voltage = getVoltage(morning_LED); //the comments on the side indicate what types of blocks are being placed in accordance to the read voltages the same is done for day, evening, and night
    if (voltage >= 701 && voltage <= 790) { //  s/s/s ---> s = solar / w---> wind / n---> nuclear
      solarMorning = 3;
      windMorning = 0;
      nuclearMorning = 0;
    }
    else if (voltage >= 685 && voltage <= 700) { //  s/s/w
      solarMorning = 2;
      windMorning = 1;
      nuclearMorning = 0;
    }
    else if (voltage >= 565 && voltage <= 590) { // s/w/w
      solarMorning = 1;
      windMorning = 2;
      nuclearMorning = 0;

    }
    else if (voltage >= 677 && voltage <= 683) { // s/s/n
      solarMorning = 2;
      windMorning = 0;
      nuclearMorning = 1;
    }
    else if (voltage >= 543 && voltage <= 564) { // s/w/n
      solarMorning = 1;
      windMorning = 1;
      nuclearMorning = 1;
    }
    else if (voltage >= 300 && voltage <= 330) { // w/w/w
      windMorning = 3;
      solarMorning = 0;
      nuclearMorning = 0;
    }

    else if (voltage >= 240 && voltage <= 260) { // w/w/n
      windMorning = 2;
      nuclearMorning = 1;
      solarMorning = 0;
    }
    else if (voltage >= 650 && voltage <= 676) { // s/s
      solarMorning = 2;
      windMorning = 0;
      nuclearMorning = 0;
    }
    else if (voltage >= 519 && voltage <= 542) { // s/w
      solarMorning = 1;
      windMorning = 1;
      nuclearMorning = 0;
    }
    else if (voltage >= 510 && voltage <= 518) { // s/n
      solarMorning = 1;
      nuclearMorning = 1;
      windMorning = 0;
    }
    else if (voltage >= 150 && voltage <= 165) { // w/n
      windMorning = 1;
      nuclearMorning = 1;
      solarMorning = 0;
    }

    else if (voltage >= 200 && voltage <= 235) { // w/w
      windMorning = 2;
      solarMorning = 0;
      nuclearMorning = 0;

    }

    else if (voltage >= 490 && voltage <= 509) { // s
      solarMorning = 1;
      nuclearMorning = 0;
      windMorning = 0;
    }
    else if (voltage >= 125 && voltage <= 140) { // w
      windMorning = 1;
      solarMorning = 0;
      nuclearMorning = 0;
    }
    else if (voltage >= 10 && voltage <= 100) { // n
      nuclearMorning = 1;
      solarMorning = 0;
      windMorning = 0;
    }
    else {
      nuclearMorning = 0;
      solarMorning = 0;
      windMorning = 0;
    }

    //
    //CHECK DAY
    //--------------------------------------------------------
    voltage = getVoltage(day_LED);
    if (voltage >= 701 && voltage <= 790) { //  s/s/s
      solarDay = 3;
      windDay = 0;
      nuclearDay = 0;
    }
    else if (voltage >= 689 && voltage <= 700) { //  s/s/w
      solarDay = 2;
      windDay = 1;
      nuclearDay = 0;
    }
    else if (voltage >= 565 && voltage <= 590) { // s/w/w
      solarDay = 1;
      windDay = 2;
      nuclearDay = 0;
    }

    else if (voltage >= 679 && voltage <= 685) { // s/s/n
      solarDay = 2;
      windDay = 0;
      nuclearDay = 1;
    }
    else if (voltage >= 545 && voltage <= 550) { // s/w/n
      solarDay = 1;
      windDay = 1;
      nuclearDay = 1;
    }
    else if (voltage >= 300 && voltage <= 330) { // w/w/w
      windDay = 3;
      solarDay = 0;
      nuclearDay = 0;
    }

    else if (voltage >= 240 && voltage <= 260) { // w/w/n
      windDay = 2;
      nuclearDay = 1;
      solarDay = 0;
    }
    else if (voltage >= 640 && voltage <= 678) { // s/s
      solarDay = 2;
      windDay = 0;
      nuclearDay = 0;
    }
    else if (voltage >= 520 && voltage <= 543) { // s/w
      solarDay = 1;
      windDay = 1;
      nuclearDay = 0;
    }
    else if (voltage >= 510 && voltage <= 516) { // s/n
      solarDay = 1;
      nuclearDay = 1;
      windDay = 0;
    }
    else if (voltage >= 150 && voltage <= 165) { // w/n
      windDay = 1;
      nuclearDay = 1;
      solarDay = 0;
    }

    else if (voltage >= 220 && voltage <= 235) { // w/w
      windDay = 2;
      solarDay = 0;
      nuclearDay = 0;

    }

    else if (voltage >= 480 && voltage <= 509) { // s
      solarDay = 1;
      nuclearDay = 0;
      windDay = 0;
    }
    else if (voltage >= 125 && voltage <= 140) { // w
      windDay = 1;
      solarDay = 0;
      nuclearDay = 0;
    }
    else if (voltage >= 10 && voltage <= 100) { // n
      nuclearDay = 1;
      solarDay = 0;
      windDay = 0;
    }
    else {
      nuclearDay = 0;
      solarDay = 0;
      windDay = 0;
    }

    //CHECK EVENING
    //--------------------------------------------------------
    voltage = getVoltage(evening_LED);
    if (voltage >= 300 && voltage <= 350) { // w/w/w
      windEvening = 3;
      solarEvening = 0;
      nuclearEvening = 0;
    }


    else if (voltage >= 240 && voltage <= 260) { // w/w/n
      windEvening = 2;
      nuclearEvening = 1;
      solarEvening = 0;
    }


    else if (voltage >= 150 && voltage <= 165) { // w/n
      windEvening = 1;
      nuclearEvening = 1;
      solarEvening = 0;
    }
    else if (voltage >= 220 && voltage <= 239) { // w/w
      windEvening = 2;
      nuclearEvening = 0;
      solarEvening = 0;
    }


    else if (voltage >= 120 && voltage <= 149) { // w
      windEvening = 1;
      nuclearEvening = 0;
      solarEvening = 0;
    }
    else if (voltage >= 10 && voltage <= 60) { // n
      nuclearEvening = 1;
      windEvening = 0;
      solarEvening = 0;
    }
    else {
      nuclearEvening = 0;
      windEvening = 0;
      solarEvening = 0;
    }
    //CHECK NIGHT
    //--------------------------------------------------------
    voltage = getVoltage(night_LED);
    if (voltage >= 300 && voltage <= 330) { // w/w/w
      windNight = 3;
      solarNight = 0;
      nuclearNight = 0;
    }


    else if (voltage >= 246 && voltage <= 290) { // w/w/n
      windNight = 2;
      nuclearNight = 1;
      solarNight = 0;
    }


    else if (voltage >= 154 && voltage <= 200) { // w/n
      windNight = 1;
      nuclearNight = 1;
      solarNight = 0;
    }
    else if (voltage >= 225 && voltage <= 245) { // w/w
      windNight = 2;
      solarNight = 0;
      nuclearNight = 0;
    }


    else if (voltage >= 125 && voltage <= 153) { // w
      windNight = 1;
      solarNight = 0;
      nuclearNight = 0;

    }
    else if (voltage >= 30 && voltage <= 100) { // n
      nuclearNight = 1;
      solarNight = 0;
      windNight = 0;
    }
    else {
      nuclearNight = 0;
      solarNight = 0;
      windNight = 0;
    }

    //calls the checkBatteries function as only one variable has to be sent back meaning it can be used as a funciton rather than in the void loop setup
    batteryLED = checkBattery(battery_LED);

    //all these serial pritns were used to debug the code
    Serial.print("Voltage Morning: ");
    Serial.println(getVoltage(morning_LED));
    Serial.print("Voltage Day: ");
    Serial.println(getVoltage(day_LED));
    Serial.print("Voltage Evening: ");
    Serial.println(getVoltage(evening_LED));
    Serial.print("Voltage Night: ");
    Serial.println(getVoltage(night_LED));
    Serial.print("Voltage Battery: ");
    Serial.println(getVoltage(battery_LED));
    Serial.println("---------------------------------------");
    Serial.print("SOLAR MORNING: ");
    Serial.println(solarMorning);
    Serial.print("WIND MORNING: ");
    Serial.println(windMorning);
    Serial.print("NUCLEAR MORNING: ");
    Serial.println(nuclearMorning);

    Serial.print("SOLAR DAY: ");
    Serial.println(solarDay);
    Serial.print("WIND DAY: ");
    Serial.println(windDay);
    Serial.print("NUCLEAR DAY: ");
    Serial.println(nuclearDay);

    Serial.print("SOLAR EVENING: ");
    Serial.println(solarEvening);
    Serial.print("WIND EVENING: ");
    Serial.println(windEvening);
    Serial.print("NUCLEAR EVENING: ");
    Serial.println(nuclearEvening);

    Serial.print("SOLAR NIGHT: ");
    Serial.println(solarNight);
    Serial.print("WIND NIGHT ");
    Serial.println(windNight);
    Serial.print("NUCLEAR NIGHT: ");
    Serial.println(nuclearNight);

    Serial.print("BATTERY : ");
    Serial.println(batteryLED);
    Serial.println("---------------------------------------");

    //calls turn on LED's, if it returns false make the GREAT_Truth true; ie if there has bee over 5 overflow than the game should fail no matter what
    if (turnOnLeds(solarMorning, windMorning, nuclearMorning, solarDay,  windDay,  nuclearDay,  solarEvening,  windEvening,  nuclearEvening,  solarNight,  windNight,  nuclearNight,  batteryLED) == false) {
      GREAT_TRUTH = true;
    }

    if (digitalRead(button) == LOW) { //if the button has been presed break the while loop
      break;
    }

  }
  //if passing in all the types of blocks used and the great truth returns true than call score and store it in a score variable
  if (checkWin(solarMorning, windMorning, nuclearMorning, solarDay,  windDay,  nuclearDay,  solarEvening,  windEvening,  nuclearEvening,  solarNight,  windNight,  nuclearNight, GREAT_TRUTH) == true) {
    int score = calculateScore(solarMorning, windMorning, nuclearMorning, solarDay,  windDay,  nuclearDay,  solarEvening,  windEvening,  nuclearEvening,  solarNight,  windNight,  nuclearNight, batteryLED);
    Serial.println("Congrats you have completed the day");
    Serial.print("Your score is: ");
    Serial.println(score);
    Serial.println(" points");
    endProgram(); //callls end program that delays the game for 10 seconds from which everything will be reset

  }
  else { // if checkWin returns false than you loose and sets 3-D Mario lamp to red
    Serial.println("You have not created enough energy for The Mushroom Kingdom");
    Serial.println("GAME OVER");
    for (int i = 0; i < 2; i++) {
      mario_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
    FastLED.show(); //shows LEDs
    endProgram();

  }
}

int checkBattery(int pin) { //works as the if, else if statements above. checks voltages and then returns the number of batteries present according to the recorded voltage
  int numberOfBatteries = 0;
  float voltage = getVoltage(pin);
  if (voltage >= 900 && voltage <= 989) { //if 1 battery
    numberOfBatteries = 1;
  }
  else if (voltage >= 990 && voltage <= 1002) { //if 2 battery
    numberOfBatteries = 2;
  }
  else if (voltage >= 1003 && voltage <= 1010) { //if 3 battery
    numberOfBatteries = 3;
  }
  else {
    numberOfBatteries = 0;
  }
  return numberOfBatteries;
}

bool turnOnLeds(int solarMorning, int windMorning, int nuclearMorning, int solarDay, int windDay, int nuclearDay, int solarEvening, int windEvening, int nuclearEvening, int solarNight, int windNight, int nuclearNight, int battery) {



  //counts up all the morning blocks and holds them in a counter, does the same for all day, evening, night counters
  int morningCounter = solarMorning + (windMorning * 2) + (nuclearMorning * 3);
  int dayCounter = solarDay + (windDay * 2) + (nuclearDay * 3);
  int eveningCounter = solarEvening + (windEvening * 2) + (nuclearEvening * 3);
  int nightCounter = solarNight + (windNight * 2) + (nuclearNight * 3);

  //over use counter to be used later to hold how many over use power their is
  int overUseCounter = 0;
  //used as tools so that the right number of LED's will be turned on. Ie if the bounds for the LEDS is greater than the actual amount of LED's than weird stuff happens.
  int toolMorning = 0;
  int toolDay = 0;
  int toolEvening = 0;
  int toolNight = 0;
  int toolOverUse = 0;

  //
  bool overFlowUse = true;

  if (morningCounter > 4) { //if statements to count how much energy each time of day is over
    overUseCounter = overUseCounter + (morningCounter - 4);
    morningCounter = 4;
    toolMorning = 1;
  }
  if (dayCounter > 3) {
    overUseCounter = overUseCounter + (dayCounter - 3);
    dayCounter = 3;
    toolDay = 1;
  }
  if (eveningCounter > 6) {
    overUseCounter = overUseCounter + (eveningCounter - 6);
    eveningCounter = 6;
    toolEvening = 1;
  }
  if (nightCounter > 2) {
    overUseCounter = overUseCounter + (nightCounter - 2);
    nightCounter = 2;
    toolNight = 1;
  }

  //printing to debug
  Serial.println(morningCounter);
  Serial.println(dayCounter);
  Serial.println(eveningCounter);
  Serial.println(nightCounter);



  //intial for loop turns lights greeen depending on if they have been powered based on the corresponding counter
  for (int i = 0; i < morningCounter; i++) { //turns on lights for the morning
    morning_LED1_ARRAY[i] = CRGB(0, 255, 0); //turns them green for now depending on morning counter
    morning_LED2_ARRAY[i] = CRGB(0, 255, 0);


  }

  //if statement catches if there are leftover LED's that are not being powered and changes them back to white
  if (toolMorning != 1) {
    for (int i = morningCounter; i < 4; i++) {
      morning_LED1_ARRAY[i] = CRGB(255, 255, 255);
      morning_LED2_ARRAY[i] = CRGB(255, 255, 255);

    }
  }

  for (int i = 0; i < dayCounter; i++) {
    day_LED1_ARRAY[i] = CRGB(0, 255, 0);
    day_LED2_ARRAY[i] = CRGB(0, 255, 0);
  }
  if (toolDay != 1) {
    for (int i = dayCounter; i < 3; i++) {
      day_LED1_ARRAY[i] = CRGB(255, 255, 255);
      day_LED2_ARRAY[i] = CRGB(255, 255, 255);
    }
  }


  for (int i = 0; i < eveningCounter; i++) {
    evening_LED1_ARRAY[i] = CRGB(0, 255, 0);
    evening_LED2_ARRAY[i] = CRGB(0, 255, 0);
  }
  if (toolEvening != 1) {
    for (int i = eveningCounter; i < 6; i++) {
      evening_LED1_ARRAY[i] = CRGB(255, 255, 255);
      evening_LED2_ARRAY[i] = CRGB(255, 255, 255);
    }
  }

  for (int i = 0; i < nightCounter; i++) {
    night_LED1_ARRAY[i] = CRGB(0, 255, 0);
    night_LED2_ARRAY[i] = CRGB(0, 255, 0);
  }
  if (toolNight != 1) {
    for (int i = nightCounter; i < 2; i++) {
      night_LED1_ARRAY[i] = CRGB(255, 255, 255);
      night_LED2_ARRAY[i] = CRGB(255, 255, 255);
    }
  }


  for (int i = 0; i < battery; i++) {
    batteries_LED_ARRAY[i] = CRGB(0, 255, 0);
  }

  if (battery == 1 && overUseCounter == 0) {
    for (int i = 0; i < 1; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery == 2 && overUseCounter == 0) {
    for (int i = 0; i < 2; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery == 3 && overUseCounter == 0) {
    for (int i = 0; i < 3; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery == 2 && overUseCounter == 1) {
    for (int i = 1; i < 2; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery == 3 && overUseCounter == 1) {
    for (int i = 1; i < 3; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery == 3 && overUseCounter == 2) {
    for (int i = 2; i < 3; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 0, 0);
    }
  }
  if (battery < 3) {
    for (int i = battery; i < 3; i++) {
      batteries_LED_ARRAY[i] = CRGB(255, 255, 255);
    }
  }

  //if overflow is over the amount of LEDs present
  if (overUseCounter > 5) {
    overFlowUse = false; //make the fucntion return false causing the game to fail the user if they press the button
    overUseCounter = 5; //resets back to 5 so that no weird stuff happens to the LED's
  }



  if (overUseCounter < battery) {//if there are more batteries than wasted energy
    overUseCounter = 0;
  }

  for (int i = 0; i < overUseCounter - battery; i++) {
    //turns over use LED's red depending on the counter and the amount of batteries being used
    overUse_LED_ARRAY[i] = CRGB(255, 0, 0);
  }
  if (overUseCounter < 5) { //turns all over use LEDs red up to 5 so that no weird stuff happens
    for (int i = overUseCounter - battery; i < 5; i++) {
      overUse_LED_ARRAY[i] = CRGB(255, 255, 255);
    }
  }

  FastLED.show();//shows leds
  return overFlowUse;
}

bool checkWin(int solarMorning, int windMorning, int nuclearMorning, int solarDay, int windDay, int nuclearDay, int solarEvening, int windEvening, int nuclearEvening, int solarNight, int windNight, int nuclearNight, bool GREAT_TRUTH) {
  bool win = false;
  //counts up all the LEDS that are being turned on based on the blocks
  int morningCounter = solarMorning + (windMorning * 2) + (nuclearMorning * 3);
  int dayCounter = solarDay + (windDay * 2) + (nuclearDay * 3);
  int eveningCounter = solarEvening + (windEvening * 2) + (nuclearEvening * 3);
  int nightCounter = solarNight + (windNight * 2) + (nuclearNight * 3);



  //if all LED's are being made green and there are less than 6 wasted energy than you complete the game
  if (GREAT_TRUTH == false) {
    if (morningCounter >= 4) {
      if (dayCounter >= 3) {
        if (eveningCounter >= 6) {
          if (nightCounter >= 2) {
            win = true;
          }
        }
      }
    }
    return win;
  }
}

int calculateScore(int solarMorning, int windMorning, int nuclearMorning, int solarDay, int windDay, int nuclearDay, int solarEvening, int windEvening, int nuclearEvening, int solarNight, int windNight, int nuclearNight, int battery) {


  //counts up all the LEDS that are being turned on based on the blocks
  int morningCounter = solarMorning + (windMorning * 2) + (nuclearMorning * 3);
  int dayCounter = solarDay + (windDay * 2) + (nuclearDay * 3);
  int eveningCounter = solarEvening + (windEvening * 2) + (nuclearEvening * 3);
  int nightCounter = solarNight + (windNight * 2) + (nuclearNight * 3);
  int overUseCounter = 0;
  int score = 0;


  if (morningCounter > 4) { //if statements to count how much energy each time of day is over
    overUseCounter = overUseCounter + (morningCounter - 4);
  }
  if (dayCounter > 3) {
    overUseCounter = overUseCounter + (dayCounter - 3);
  }
  if (eveningCounter > 6) {
    overUseCounter = overUseCounter + (eveningCounter - 6);
  }
  if (nightCounter > 2) {
    overUseCounter = overUseCounter + (nightCounter - 2);
  }



  //the basics of what this is doing is making it more beneficial score wise to power all the batteries being placed rather than leaving them empty
  if (battery > overUseCounter) {//if the battery holds more than the over use column than dont include overUseCounter - (battery * 6) into the score
    score =  (solarMorning * 2) + (solarDay * 2) + (solarEvening * 2) + (solarNight * 2) + (windMorning * 5) + (windDay * 5) + (windEvening * 5) + (windNight * 5) + (nuclearMorning * 6) + (nuclearDay * 6) + (nuclearEvening * 6) + (nuclearNight * 6) + (battery * 5);
  }

  else {
    score =  (solarMorning * 2) + (solarDay * 2) + (solarEvening * 2) + (solarNight * 2) + (windMorning * 5) + (windDay * 5) + (windEvening * 5) + (windNight * 5) + (nuclearMorning * 6) + (nuclearDay * 6) + (nuclearEvening * 6) + (nuclearNight * 6) + (battery * 5) + (overUseCounter - (battery * 6));
  }

  //takes the ranges of the scores and makes the 3-D Mario Lamp glow according to the score
  if (score >= 35 && score < 41) {
    for (int i = 0; i < 2; i++) {
      mario_LED_ARRAY[i] = CRGB(0, 0, 255);
    }
  }
  else if (score >= 41 && score < 47) {
    for (int i = 0; i < 2; i++) {
      mario_LED_ARRAY[i] = CRGB(0, 255, 0);
    }
  }
  else if (score >= 47 && score <= 55) {
    for (int i = 0; i < 2; i++) {
      mario_LED_ARRAY[i] = CRGB(255, 234, 0);
    }
  }
  FastLED.show();

  return score;

}

float getVoltage(int pin) //gets the voltage from pin
{

  return (analogRead(pin)); //return voltage

}

void endProgram() {
  delay(10000); //delay 10secs
  //  while (true) {
  //    if (digitalRead(button) == LOW) {
  //      break;
  //    }
  //  }
}
