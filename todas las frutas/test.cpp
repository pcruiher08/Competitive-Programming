Process Ping{
    P(semaforoPapas);
    Ping();
    V(semaforoPing);
}

Process Pong{
    P(semaforoPing);
    Pong();
    V(semaforoPong);
}

Process Papas{
    P(semaforoPong);
    Papas();
    V(semaforoPapas);
}

main(){
    initSem(semaforoPong,0);
    initSem(semaforoPing,0);
    initSem(semaforoPapas,1);
    parBegin; //concurrente 
        Pong;
        Papas;
        Ping;
    parEnd;
}


