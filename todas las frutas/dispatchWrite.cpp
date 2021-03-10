NTSTATUS DispatchWrite(PDEVICE_OBJECT fdo, PIRP Irp)
    {                           // DispatchWrite
    PAGED_CODE();
    PDEVICE_EXTENSION pdx = (PDEVICE_EXTENSION) fdo->DeviceExtension;

    PUCHAR pDato = (PUCHAR)Irp->AssociatedIrp.SystemBuffer;
    unsigned char dato = (unsigned char)*pDato;
    //Mapeo de informacion a digitos.
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F.
    unsigned char digitos[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F, 0x77, 0x7F, 0x39, 0X3F, 0X71};

    // Mascara para leer del registro de control.
    unsigned char MASK_C = 0x0B;
    unsigned char control;

    // Cargar bit menos significativo.
    // Apagar bit de control 0.
    control = READ_PORT_UCHAR((unsigned char *)0x37A) ^ MASK_C;
    control = control & 0xFE;
    WRITE_PORT_UCHAR((unsigned char *)0x37A, control ^ MASK_C);
    sleep(5);

    //Mandar el dato al display.
    WRITE_PORT_UCHAR((unsigned char *)0x378, digitos[dato % 16]);
    sleep(5);

    //Prender bit de control 0 para generar flanco positivo.
    control = control | 0x01;
    WRITE_PORT_UCHAR((unsigned char *)0x37A, control ^ MASK_C);

    // Cargar bit mas significativo.
    // Apagar bit de control 1.
    control = READ_PORT_UCHAR((unsigned char *)0x37A) ^ MASK_C;
    control = control & 0xFD;
    WRITE_PORT_UCHAR((unsigned char *)0x37A, control ^ MASK_C);
    sleep(5);

    //Mandar el dato al display.
    WRITE_PORT_UCHAR((unsigned char *)0x378, digitos[dato / 16]);
    sleep(5);

    //Prender bit de control 1 para generar flanco positivo.
    control = control | 0x02;
    WRITE_PORT_UCHAR((unsigned char *)0x37A, control ^ MASK_C);

    Irp->IoStatus.Status = STATUS_SUCCESS;
    Irp->IoStatus.Information = 1;
    return STATUS_SUCCESS;
}                           
