Process P1{
    P(semP4);
    P1;
    V(exclusionMutua);   
}

Process P2{
    P(exclusionMutua);
    P2;
    V(semP2P3);
    V(exclusionMutua);
}

Process P3{
    P(exclusionMutua)
    P3;
    V(semP2P3);
    V(exclusionMutua);
}

Process P5{
    P(semP2P3);
    P(semP2P3);
    P5;
    V(semP5);
}

Process P4{
    P(semP5);
    P4;
    V(semP4)
}

main(){
    initSem(semP2P3,0);
    initSem(semP4,1);
    initSem(semP5,0);
    initSem(exclusionMutua,0);

    parBegin;//concurrentes
        P1; P2; P3; P4; P5;
    parEnd;
}