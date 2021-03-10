NTSTATUS DispatchRead(PDEVICE_OBJECT fdo, PIRP Irp)
    {                           // DispatchRead
    PAGED_CODE();
    PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION) fdo->DeviceExtension;

    PUCHAR pDato = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
    //Crear mascaras para seleccionar el bit correcto segun el nibble a cargar.
    unsigned char bit[] = {0x80, 0x20, 0x10, 0x08, 0x80, 0x20, 0x10, 0x08};
    unsigned char MASK_C = 0x0B;
    unsigned char MASK_S = 0x80;
    unsigned char dato = 0;
    unsigned char status, control;

    // Ciclo para recuperar bit por bit.
    for(int i = 0; i < 8; i++){
        if(i == 0){ //Cambiar a nibble bajo.
            //Apagar bit de control 3.
            control = READ_PORT_UCHAR((unsigned char*)0x37A) ^ MASK_C;
            control = control & 0xF7;
            WRITE_PORT_UCHAR((unsigned char*)0x37A, control ^ MASK_C);
            sleep(5);
        }else if(i == 4){ // Cambiar a nibble alto.
            //Prender bit de control 3.
            control = READ_PORT_UCHAR((unsigned char*)0x37A) ^ MASK_C;
            control = control | 0x08;
            WRITE_PORT_UCHAR((unsigned char*)0x37A, control ^ MASK_C);
            sleep(5);
        }
        //Leer el registro de status.
        status = READ_PORT_UCHAR((unsigned char *)0x379) ^ MASK_S;

        //Preguntar si el bit esta prendido.
        if((status & bit[i]) != 0){
            dato = dato | (1 << i);
        }
    }

    Irp->IoStatus.Status = STATUS_SUCCESS;
    Irp->IoStatus.Information = 1;
    //Cargar al buffer el dato leido.
    *pDato=dato;
    return STATUS_SUCCESS;
}                           
