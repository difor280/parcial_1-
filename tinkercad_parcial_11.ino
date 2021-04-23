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
       imagen();
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


  

void patron(int guardado[][8], int num_arre)
{	
   	int num,tamano=0, cifra, aux;
  	Serial.print("ingrese el numero que representan los leds de la fila: ");
  	Serial.print(num_arre);
    Serial.print("\n"); 
    while(Serial.available()==0){}
  	num=Serial.parseInt();
    while(num < 0)
    {Serial.print("ingrese el numero que representan los leds prendidos \n");
    while(Serial.available()==0){}
  	num=Serial.parseInt();
    }
  	aux= num;
  	while(num>0)
    {
      cifra= num % 10;
      if(cifra !=9 and cifra !=0)
      {
        tamano++;
      }
      num=num/10;
    }
  int espacios[tamano],ingresor[8]={0,0,0,0,0,0,0,0};

  	ingreso(espacios,aux,cifra);
  	orden(espacios,tamano,ingresor);
  	guardador(guardado,ingresor,num_arre);
}

void ingreso(int espacios[],int aux,int cifra )
{	int e=0;  
  	while(aux>0)
    {
      cifra = aux % 10;
      if (cifra !=9 and cifra !=0)
      {
        espacios[e]=cifra;
      	e++;
      }
      aux= aux / 10;
    }  
}

void grupo8(int cadena[])
{	//recorrer las filas dejando datos, pide una cadena de enteros 
	for(int e=0;e<8;e++)
    { 
    	digitalWrite(SER,*(cadena+e));
      	inicializacion();
    }
}  

void orden(int espacios[],int tamano,int fin[])
{ 
  int a;
	for(int i=0; i<tamano ;i++){
      a=espacios[i]-1;
      fin[a]=1;
    }  
}

void guardador(int arreglodarreglos[][8],int ingreso[],int num_arre)
{
	for(int i= 0 ; i <8;i++)
    {
      arreglodarreglos[num_arre][i]=*(ingreso+i);
    }	
}

void verificacion()
{//funcion que prende todos los leds para verificar que funcionan 
  for(int i=1;i<=64;i++)
  {
    digitalWrite(SER,1);
    inicializacion();  	 
  } 
}


void imagen()
{	int patronn[8][8];
  Serial.print("Menu de la funcion imagen\n");
  Serial.print(" presiona 1. para ingresar tu propio patron\n presiona 2. Para los patrones predefinidos y seleccionar alguno de ellos \n \n");
  while(Serial.available()==0){} 
  opciones=Serial.parseInt();
  
  switch(opciones)
  {
    case 1:
    	///Serial.print("ingrese el numero que representan los leds prendidos \n ");
    	//Serial.print("Ejemplo: si usted ingresa 1468, estara pidiendo que se enciendan los leds en la posicion 1,4,6,8");
    	
    	for(int i=0;i<8;i++)
        {
          patron(patronn,i);
          grupo8(patronn[i]);
        }
    	
    	
    break;
    case 2:
    Serial.print("Los patrones predefinidos son las letras del alfabeto mayusculo \n ingresa un numero como como te muestro a continuacion :");
    Serial.print("1 --> A \n 2 --> B \n 3 --> C \n 4 --> D \n 5 --> E \n 6 --> F \n 7 --> G \n 8 --> H \n 9 --> I \n 10 --> J \n 1 --> K \n 12 --> L \n 13 --> M \n 14 --> N \n 15 --> O \n 16 --> P \n 17 --> Q \n 18 --> R \n 19 --> S \n 20 --> T \n 21 --> U \n 22 --> V \n 23 --> W \n 24 --> X \n 25 --> Y \n 26 --> Z \n");
    while(Serial.available()==0){} 
    opciones=Serial.parseInt();  
    switch (opciones)
    {
      case 1:
      letra_A();
      break;}
      /*case 2:
      letra_B();
      break;
      case 3:
      letra_C();
      break;
      case 4:
      letra_D();
      break;
      case 5:
      letra_E();
      break;
      case 6:
      letra_F();
      break;
      case 7:
      letra_G();
      break;
      case 8:
      letra_H();
      break;
      case 9:
      letra_I();
      break;
      case 10:
      letra_J();
      break;
      case 11:
      letra_K();
      break;
      case 12:
      letra_L();
      break;
      case 13:
      letra_M();
      break;
      case 14:
      letra_N();
      break;
      case 15:
      letra_O();
      break;
      case 16:
      letra_P();
      break;
      case 17:
      letra_Q();
      break; 
      case 18:
      letra_R();
      break;
      case 19:
      letra_S();
      break;
      case 20:
      letra_T();
      break;
      case 21:
      letra_U();
      break;
      case 22:
      letra_V();
      break;
      case 23:
      letra_W();
      break;
      case 24:
      letra_X();
      break;
      case 25:
      letra_Y();
      break;
      case 26:
      letra_Z();
      break;
    }*/
    break;
  }
}
 
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

/*void letra_B()
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
void letra_E()
{
  int todo[8][8]={
    {1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_F()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_G()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_H()
{
  int todo[8][8]={
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_I()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}

void letra_J()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,1,1,1,0,0},
	{0,0,0,1,1,1,0,0},
	{0,0,0,1,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,0,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_K()
{
  int todo[8][8]={
	{1,1,0,0,0,1,1,1},
	{1,1,0,0,1,1,1,0},
	{1,1,0,1,1,1,0,0},
	{1,1,1,1,1,0,0,0},
	{1,1,1,1,1,0,0,0},
	{1,1,0,1,1,1,0,0},
	{1,1,0,0,1,1,1,0},
	{1,1,0,0,0,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_L()
{
  int todo[8][8]={
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_M()
{
  int todo[8][8]={
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,0,0,1,1},
	{1,1,0,1,1,0,1,1},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_N()
{
  int todo[8][8]={
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,0,1,1},
	{1,1,1,1,0,0,1,1},
	{1,1,0,1,1,0,1,1},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_O()
{
  int todo[8][8]={
	{0,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_P()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
}
void letra_Q()
{
  int todo[8][8]={
	{0,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,0,1,1,0},
	{1,1,0,1,0,1,1,0},
	{1,1,0,0,1,1,1,0},
	{1,1,0,0,0,1,1,0},
	{1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,0,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  } 
  
}
void letra_R()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,1,1,0,0},
	{1,1,0,0,0,1,1,0} 
	};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}

void letra_S()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_T()
{
  int todo[8][8]={
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,0,0},
	{0,0,1,1,1,1,0,0},
	{0,0,1,1,0,1,0,0},
	{0,0,1,1,1,1,0,0},
	{0,0,1,1,1,1,0,0} };
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_U()
{
  int todo[8][8]={
	{1,1,1,0,0,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,0}};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_W()
{
  int todo[8][8]={
	{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,0,0,0,1,1}
	,{1,1,0,1,1,0,1,1}
	,{1,1,0,1,1,0,1,1}
	,{1,1,0,1,1,0,1,1}
	,{0,1,1,0,0,1,1,0}};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_V()
{
  int todo[8][8]={
	{1,1,0,0,0,0,1,0}
	,{1,1,0,0,0,0,1,0}
	,{0,1,1,0,0,0,1,0}
	,{0,1,1,0,0,1,1,0}
	,{0,0,1,0,0,1,0,0}
	,{0,0,1,1,1,1,0,0}
	,{0,0,1,1,1,1,0,0}
	,{0,0,0,1,1,0,0,0}};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_X()
{
  int todo[8][8]={

 {1,1,0,0,0,0,1,1}
,{0,1,1,0,0,1,1,0}
,{0,0,1,1,1,1,0,0}
,{0,0,0,1,1,0,0,0}
,{0,0,1,1,1,1,0,0}
,{0,1,1,0,0,1,1,0}
,{0,1,1,0,0,1,1,0}
,{1,1,0,0,0,0,1,1}};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_Y()
{
  int todo[8][8]={

{1,1,0,0,0,0,1,1},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0}};
  for(int i=0;i<8;i++)
  {
    grupo8(todo[i]);
  }  
}
void letra_Z()
{
  int todo[8][8]={
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1},
{0,0,0,0,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,1,0,0,0,0},
{0,1,1,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1}};
  for(int i=0;i<8;i++){grupo8(todo[i]);}  
}
*/







