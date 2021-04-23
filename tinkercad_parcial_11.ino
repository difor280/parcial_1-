//nombre de los pines que estamos usando 
const int SER =5;
const int reloj_des=3;
const int reloj_salida=4;
//para el menu
int opciones =-1;


void setup()
{
  
  Serial.begin(9600);
  pinMode(SER,OUTPUT);
  pinMode(reloj_des,OUTPUT);
  pinMode(reloj_salida,OUTPUT);
  for(int i=3;i ==5;i++)
  {digitalWrite(i,0); }
  Serial.print("Bienvendio al menu programa del parcial");
  
}

void loop()
{
    //esto para que no pase de este campo sin el dato a ingregar
	Serial.print("bienvenido al menu del parcial 1 de info 2!!!\n");
    Serial.print(" presiona 1. para invocar la funcion verificacion\n presiona 2. para invocar la funcion imagen\n presiona 3. para la funcion  publik \n \n \n");
  	while(Serial.available()==0){} 
  	opciones=Serial.parseInt();
  	
     switch(opciones)
     {
      case 0:
        break;
      case 1:       
       verificacion();
       Serial.println("todos los leds funcion correctamente \n porfavor presione cualquier tecla para volver al menu principal \n \n \n");
       while(Serial.available()==0){}
  		break;
  	  case 2:
     	 break;
      case 3:
       break;
      default:
      Serial.println("el dato ingresado no se contempla en el menu \n \n \n");
    }
    
}

// funciones auxiliares 

void inicializacion()
{	// funcion para inicializar los relojes 
	digitalWrite(reloj_des,0);
  	digitalWrite(reloj_des,1);
  	digitalWrite(reloj_des,0);
  	
  	digitalWrite(reloj_salida,0);
    digitalWrite(reloj_salida,1);
   	digitalWrite(reloj_salida,0);
}

void apagar()
{ // apagar los leds despues de una ejecucion 
  for(int i=1; i <=64; i++)
  {
    digitalWrite (SER,0);
    
    inicializacion();
  }
  delay (10000);
}



void grupo8(int cadena[])
{	//recorrer las filas dejando datos, pide una cadena de enteros 
	for(int e=0;e<8;e++)
    { 
    	digitalWrite(SER,*(cadena+e));
      	inicializacion();
    }
}  

int orden(int espacios[],int cambios)
{
  int ordenar[8]={0,0,0,0,0,0,0,0};
	for(int i=0;i<cambios;i++)
    {
      ordenar[espacios[i]]=1;
    }
  return *ordenar;
}

void verificacion()
{//funcion que prende todos los leds para verificar que funcionan 
  for(int i=1;i<=64;i++)
  {
    digitalWrite(SER,1);
    
    inicializacion();  	 
  } 
}


/*void imagen()
{
  
}
 */
void publik()
{
  int tiempo=0;
  int num_patrones=0;
  
  
  Serial.println("Ingrese la cantidad de patrones que desea: ");
  while(Serial.available()==0){}
  num_patrones = Serial.parseInt();
  
  while (num_patrones < 0)
  {
    Serial.println("debes ingresar el numero de patrones que deseas mostrar");
    Serial.println("Ingrese la cantidad de patrones que desea: ");
    while(Serial.available()==0){}
    num_patrones = Serial.parseInt();
  }  
  int arreglos[num_patrones];
  
  Serial.println("Ingrese los milisegundos entre cada visualizacion entre patrones : ");
  while(Serial.available()==0){} 
  tiempo = Serial.read();
  while (tiempo < 0)
  {
  	Serial.println("Ingrese el tiempo de visualizacion entre cada patron :    ");
    while(Serial.available()==0){}
    tiempo = Serial.parseInt();
  }
  
  
  /*for(int i=0;i <= num_patrones; i++)
    { 
    	imagen();
    }*/
}

//catalogo de funciones prestablezidas 
void letra_A()
{
  int todo[8][8]={
	 {0,0,1,1,1,1,0,0}
	,{0,1,1,1,1,1,1,0}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,1,1,1,1,1,1}
	,{1,1,1,1,1,1,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}};
  	for(int i =0;i<8;i++ )
    {
    	grupo8(todo[i]);
    } 
	
}

void letra_B()
{
    int todo[8][8]={
      	 {1,1,1,1,1,1,1,0}
		,{1,1,0,0,0,0,1,1}
		,{1,1,0,0,0,0,1,1}
		,{1,1,1,1,1,1,1,0}
		,{1,1,1,1,1,1,1,1}
		,{1,1,0,0,0,0,1,1}
		,{1,1,0,0,0,0,1,1}
		,{1,1,1,1,1,1,1,0}
};
  	
  	for(int i =0;i<8;i++ )
    {
    	grupo8(todo[i]);
    } 
    
  	
  
}

void letra_C()
{
  int todo[8][8]={
     {0,1,1,1,1,1,1,0}
	,{1,1,1,1,1,1,1,1}
	,{1,1,0,0,0,0,0,0}
	,{1,1,0,0,0,0,0,0}
	,{1,1,0,0,0,0,0,0}
	,{1,1,0,0,0,0,0,0}
	,{1,1,1,1,1,1,1,1}
	,{0,1,1,1,1,1,1,0}
  };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }
 
}

void letra_D()
{
  int todo[8][8]={
	 {1,1,1,1,1,1,1,0}
	,{1,1,1,1,1,1,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,1,1,1,1,1,1}
	,{1,1,1,1,1,1,1,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }
 
}
