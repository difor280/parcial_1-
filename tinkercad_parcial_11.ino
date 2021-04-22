const int SER =5;
const int reloj_des=3;
const int reloj_salida=4;


void setup()
{
  
  Serial.begin(9600);
  pinMode(SER,OUTPUT);
  pinMode(reloj_des,OUTPUT);
  pinMode(reloj_salida,OUTPUT);
  for(int i=3;i ==5;i++)
  {digitalWrite(i,0); }
  
}

void loop()
{
	
 verificacion();
  	
}

void verificacion()
{	
  for(int i=0;)
  {digitalWrite(SER,1);
      
  	digitalWrite(reloj_des,0);
  	digitalWrite(reloj_des,1);
  	digitalWrite(reloj_des,0);
  	
  	digitalWrite(reloj_salida,0);
    digitalWrite(reloj_salida,1);
   digitalWrite(reloj_salida,0);
  }
}








