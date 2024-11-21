
unsigned long previousTime = 0; //stores last time trigger was sent
const long LED_ON_time = 200; //total time (milliseconds) that each LED will be ON for each cycle of data collection
const long CMOS_trigger_time = 1; //total time (milliseconds) that the trigger is sent to the CMOS camera for image capture
const long channel_delay = 3000; //total time (milliseconds) between LED signals for LED1 and LED2, intended to eliminate channel cross-talk

// ***Set your desired time between data collection cycles here***
// ***Default is 10 minutes***
const long cycle_delay = 10; //minutes
//
//

const long interval = cycle_delay*60000 + LED_ON_time*2 + CMOS_trigger_time*2 + channel_delay; //interval that the trigger will occur, includes data collection timing

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); //allows the builtin LED on the Arduino board to indicate when an output is sent; useful for troubleshooting
  pinMode(11, OUTPUT); //sets digital pin 11 as an output to CMOS (camera) 1
  pinMode(10, OUTPUT); //sets digital pin 10 as an output to CMOS (camera) 2
  pinMode(3, OUTPUT); //sets digital pin 3 as an output to LED1
  pinMode(5, OUTPUT); //sets digital pin 5 as an output to LED2
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis(); //running current time since loop started
  
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;                    //resets loop running time
   
    digitalWrite(LED_BUILTIN, HIGH);               //turns on onboard LED to indicate active
    digitalWrite(3, HIGH);                         //sets pin 3 to ON, 5 V out, LED1 on
    delay(LED_ON_time/2);                          //waits half of LED ON time
    digitalWrite(11, HIGH);                        //sets pin 11 to ON, 5V out, trigger CMOS1 camera
    delay(CMOS_trigger_time);                      //waits for trigger to send to CMOS camera 
    digitalWrite(11, LOW);                         //sets pin 11 to OFF, 0V out, end trigger signal
    delay(LED_ON_time/2);                          //waits remaining half of LED ON time
    digitalWrite(3, LOW);                          //sets pin 3 to OFF, 0V out, LED1 off
    digitalWrite(LED_BUILTIN, LOW);                //turns off onboard LED to indicate inactive
    
    //End of data collection for upper channel

    delay(channel_delay); //break between upper and lower collection, typically delay of 3 seconds

    //Begin data collection for lower channel
    
    digitalWrite(LED_BUILTIN, HIGH);               //turns on onboard LED to indicate active
    digitalWrite(5, HIGH);                         //sets pin 5 to ON, 5 V out, LED2 on
    delay(LED_ON_time/2);                          //waits half of LED ON time
    digitalWrite(10, HIGH);                        //sets pin 10 to ON, 5V out, trigger CMOS2 camera
    delay(CMOS_trigger_time);                      //waits for trigger to send to CMOS camera
    digitalWrite(10, LOW);                         //sets pin 10 to OFF, 0V out, end trigger signal
    delay(LED_ON_time/2);                          //waits remaining half of LED ON time
    digitalWrite(5, LOW);                          //sets pin 5 to OFF, 0V out, LED2 off
    digitalWrite(LED_BUILTIN, LOW);                //turns off onboard LED to indicate inactive
  }
}
