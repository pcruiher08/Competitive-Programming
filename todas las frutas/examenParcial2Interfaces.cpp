//pregunta 1

NTSTATUS  DispatchWrite(PDEVICE_OBJECT fdo, PIRP Irp) {
  PUCHAR pDato = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
  unsigned char dato;
  unsigned char control;
  unsigned char digitos[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,...,0x71};
  unsigned char i;
  PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(Irp);
  unsigned int contador = stack->Parameters.Read.Length;
  LARGE_INTEGER largeInteger; 
  control=READ_PORT_UCHAR((unsigned char *)0x37A);
  for (i=0;i<contador;i++) {
    dato=(UCHAR)*(pDato++); //para acceder cada posicion del array de una por una, mejor acumulamos en vez de usar la i
    control&=0xFE; //C0<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//hay que agregar el xor para las inversiones;
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato%16]);//hay que acceder al array para conseguir los numeros a mostrar
    control|=0x01; //C0<--1
    control&=0xFD; //C1<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//tambien faltaba la mascara para hacer xor
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato/16]); //tambien faltaba acceder al array
    control|=0x02; //C1<--1
    //hay que mandar el bit de control que se acababa de modificar
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);
    //hay que mandar el delay para la cadencia que se nos pide con un millon de microsegundos, o sea 1 segundo
    KeDelayExecutionThread(KernelMode,FALSE,1000000);
  }
  Irp->IoStatus.Status = STATUS_SUCCESS;
  //el contador esta bien
  Irp->IoStatus.Information = contador;
  return STATUS_SUCCESS;
}

//pregunta 2

//pregunta 1




NTSTATUS  DispatchWrite(PDEVICE_OBJECT fdo, PIRP Irp) {
  PUCHAR pDato = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
  unsigned char dato;
  unsigned char control;
  unsigned char digitos[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,...,0x71};
  unsigned char i;
  PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(Irp);
  unsigned int contador = stack->Parameters.Read.Length;
  LARGE_INTEGER largeInteger; 
  control=READ_PORT_UCHAR((unsigned char *)0x37A);
  for (i=0;i<contador;i++) {
    dato=(UCHAR)*(pDato++); //para acceder cada posicion del array de una por una, mejor acumulamos en vez de usar la i
    control&=0xFE; //C0<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//hay que agregar el xor para las inversiones;
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato%16]);//hay que acceder al array para conseguir los numeros a mostrar
    control|=0x01; //C0<--1
    control&=0xFD; //C1<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//tambien faltaba la mascara para hacer xor
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato/16]); //tambien faltaba acceder al array
    control|=0x02; //C1<--1
    //hay que mandar el bit de control que se acababa de modificar
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);
    //hay que mandar el delay para la cadencia que se nos pide con un millon de microsegundos, o sea 1 segundo
    KeDelayExecutionThread(KernelMode,FALSE,1000000);
  }
  Irp->IoStatus.Status = STATUS_SUCCESS;
  //el contador esta bien
  Irp->IoStatus.Information = contador;
  return STATUS_SUCCESS;
}




//pregunta 2




//pregunta 1




NTSTATUS  DispatchWrite(PDEVICE_OBJECT fdo, PIRP Irp) {
  PUCHAR pDato = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
  unsigned char dato;
  unsigned char control;
  unsigned char digitos[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,...,0x71};
  unsigned char i;
  PIO_STACK_LOCATION stack = IoGetNextIrpStackLocation(Irp);
  unsigned int contador = stack->Parameters.Read.Length;
  LARGE_INTEGER largeInteger; 
  control=READ_PORT_UCHAR((unsigned char *)0x37A);
  for (i=0;i<contador;i++) {
    dato=(UCHAR)*(pDato++); //para acceder cada posicion del array de una por una, mejor acumulamos en vez de usar la i
    control&=0xFE; //C0<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//hay que agregar el xor para las inversiones;
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato%16]);//hay que acceder al array para conseguir los numeros a mostrar
    control|=0x01; //C0<--1
    control&=0xFD; //C1<--0
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);//tambien faltaba la mascara para hacer xor
    WRITE_PORT_UCHAR((PUCHAR)0x378, digitos[dato/16]); //tambien faltaba acceder al array
    control|=0x02; //C1<--1
    //hay que mandar el bit de control que se acababa de modificar
    WRITE_PORT_UCHAR((PUCHAR)0x37A, control^mascaraControl);
    //hay que mandar el delay para la cadencia que se nos pide con un millon de microsegundos, o sea 1 segundo
    KeDelayExecutionThread(KernelMode,FALSE,1000000);
  }
  Irp->IoStatus.Status = STATUS_SUCCESS;
  //el contador esta bien
  Irp->IoStatus.Information = contador;
  return STATUS_SUCCESS;
}




//pregunta 2




#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
HANDLE *device;
unsigned char datos[]={0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, ... 0x05, 0x04, 0x03, 0x02, 0x01, 0x00};
DWORD aux;
void main() {
   device=CreateFile("\\\\.\\NombreDeviceDriver", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
   if (device!=INVALID_HANDLE_VALUE) {


      //de forma general para poder hacer cualquier tipo de conteo y que se pueda reutilizar esta funcion sin fallas
      int tamanioDelArray = *(&datos + 1) - datos; 


      //la pregunta anterior ya tiene un ciclo que recorre lo que se le envie, en este caso solo haria falta 
      //enviar el array como dato y el tamanio del array para que este sea procesado
      
      WriteFile(device,&datos,tamanioDelArray,&aux,NULL);
      
      CloseHandle(device);
   }
}

//problema 3

Lo mas conveniente en este caso sería hacer un DispatchWrite primero para indicar en un selector el tipo de señal que se quiere leer en el DispatchRead.
Para esto es necesario primero agregar una variable nueva dentro de las driver variables para que se pueda compartir entre operaciones del dispositivo. En este caso con agregar un "int selector;" basta.
Ahora bien, una vez que se hace el DispatchWrite y dentro de este se indica en el selector cual es la señal que se desea leer, hay que salir del DispatchWrite y proceder a hacer el DispatchRead.
Dentro del DispatchRead se hace una operación condicional de tipo switch en donde se considera como valor al selector que se agregó en las variables de dispositivo y que se acaba de modificar previamente en el DispatchWrite.
Dentro de este switch simplemente se lee el arreglo que se este indicando con el selector. 
Al final se procede a hacer close del handle y no hay mas problema. 

Tal y como vimos en la tarea del DeviceIoControl, podemos utilizar esta funcion para enviar codigos de control
que seleccionen operaciones especificas para nuestras rutinas. En este caso sería conveniente definir codigos de control 
para seleccionar la señal que queremos leer. Una vez que utilicemos un DeviceIoControl que lleve como parametro nuestra señal, 
solo haria falta hacer el DispatchRead para traer la señal que esta guardada en los arreglos y utilizarla para los fines que mas convengan.


Lo mas conveniente en este caso sería hacer un DispatchWrite primero para indicar en un selector el tipo de señal que se quiere leer en el DispatchRead.
Para esto es necesario primero agregar una variable nueva dentro de las driver variables para que se pueda compartir entre operaciones del dispositivo. En este caso con agregar un "int selector;" basta.
Ahora bien, una vez que se hace el DispatchWrite y dentro de este se indica en el selector cual es la señal que se desea leer, hay que salir del DispatchWrite y proceder a hacer el DispatchRead.
Dentro del DispatchRead se hace una operación condicional de tipo switch en donde se considera como valor al selector que se agregó en las variables de dispositivo y que se acaba de modificar previamente en el DispatchWrite.
Dentro de este switch simplemente se lee el arreglo que se este indicando con el selector. 
Al final se procede a hacer close del handle y no hay mas problema. 




Otra opción que se podría tomar en este caso sería utilizar un DeviceIoControl con una señal de control creada especificamente para seleccionar una señal de las propuestas. Para esto simplemente se hace la llamada a un DeviceIoControl con un buffer de lectura y ahí se guarda la señal para proceder a utilizarla como más convenga. Sin embargo esta solución representa problemas con la implementación en el DispatchRead ya que habría que tener las señales en algún lugar de la memoria del dispositivo para poder acceder a ellas. 


Creo que es más viable la primera opción de agregar un selector en las variables de dispositivo, pero no me quería quedar sin mencionar la opción del DeviceIoControl por el peso de esta pregunta en la ponderación del examen.


//4
Tal y como vimos en la tarea, el DeviceIoControl es una función que permite enviar señales de control a un dispositivo para que este ejecute operaciones especificas. Dentro de los parametros de esta función se permite enviar también buffers de lectura y escritura de datos por si se indica hacer algo con ellos en la señal de control que se esté enviando. También se pueden hacer señales de control propias para poder ejecutar instrucciones diferentes a las convencionales. Cabe mencionar que se permite enviar un ultimo parametro que indique si la operación de DeviceIoControl se hará sincrónica o asincrónicamente. 

Ejemplo práctico #1 (y el ejemplo más clásico según la documentación de Microsoft que se revisó para la tarea): Asignar una letra a un disco. Para esto se debe saber las letras de los otros discos que estaban previamente conectados. 

Ejemplo práctico #2: Preguntar por algún atributo de un dispositivo que esté conectado. Por ejemplo, si conecto una impresora y quiero conocer el modelo, lo haría mediante un DeviceIoControl. También se aplica si quiero conocer el tipo de disco que estoy cargando o alguna versión o modelo de un dispositivo conectado.

Ejemplo adicional: Se pueden hacer implementaciones de escritura o lectura en dispositivos con diferentes threads si se hacen asincrónicamente. Esto puede ser útil si se está trabajando en una implementación con cómputo en paralelo. O bien, si simplemente los resultados de las operaciones son mutuamente excluyentes.

//5

STATUS_PENDING quiere decir que aun no acaba de procesar los datos, esto se puede dar cuando la función no ha recibido los datos.