
camiones{
    P(semaforo1)
    if(!cuantosAlumnos){
        camionEnRuta;
    }else{
        while(alumnos--){
            //para que suban de uno por uno hasta ser 20 (o menos si es que no hay 20)
            alumnosEnElCamion++;
            if(alumnosEnElCamion >= 20){
                break;
            }
        }
    }
    camionEnRuta;
    V(semaforo3)
    V(semaforo1)
}

alumnos{
    P(semaforo3)
    P(semaforo2)
    alumnos = alumnos + 1;
    alumnosSube;
    V(semaforo2)
}


main{
    initSem(semaforo1,1);
    initSem(semaforo2,1);
    initSem(semaforo3,0);

    CONCURRENTES_BEGIN
        camiones, alumnos;
}