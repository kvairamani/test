/* simple code for string comparison
 *  if string is equal LED connected on the pin13  will ON
 *  and print valid command entered in the serial monitor
 *  if string is not equal LED is OFF and send a string to serial port as "to enter a valid command"
*/
int led =13;
void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println(" ENTER A VALID COMMAND TO BLINK LED");
}

void loop() 
{
  char serialdata[15];   
 int i=0; 
 delay(1000);
 
 if (Serial.available() > 0) 
 {             
      while (Serial.available() > 0) 
      {
        serialdata[i]=Serial.read(); //read data  
        i++;      
      }
      serialdata[i]='\0';
     validcommand(serialdata);
   }    
}

void validcommand(char valid[])
{
  if (!strcmp(valid,"valid"))
  commandvalid();
  else
  notvalid();
  
}
void commandvalid()
{
  digitalWrite(led,HIGH);
  Serial.println("valid command");
}
void notvalid()
{
  digitalWrite(led,LOW);
  Serial.println("enter a valid command");
  
}

