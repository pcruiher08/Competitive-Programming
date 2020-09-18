buscador{
    P(semBorrador)
    buscadorEnAccion;
    V(semBuscador)
}


creador{
    P(semBorrador)
    P(semCreador)
    creadorEnAccion;
    V(semCreador)
}


borrador{
    P(semCreador)
    P(semBuscador)
    P(semBorrador)
    borradorEnAccion;
    V(semBorrador)
}

main{
    initsem(semBuscador,0)
    initSem(semCreador,0)
    initSem(semBorrador,1)

    CONCURRENTES_BEGIN
        borrador, creador, buscador;
    

}