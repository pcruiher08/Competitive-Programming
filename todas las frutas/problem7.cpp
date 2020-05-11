Process mujer_entra_baño{
    if(mujeres == 0){
        P(vacio);
        mujerEntra;
        V(cuantasMujeresHay);
        mujeres += 1; 
    }else{
        mujerEntra;
        V(cuantasMujeresHay);
        mujeres += 1;
    }
}

Process mujer_sale_baño{
    P(cuantasMujeresHay);
    mujerSale;
    mujeres -= 1;
    if(hombres == 0 && mujeres == 0){
        V(vacio);
    }
}

Process hombre_entra_baño{
    if(hombres == 0){
        P(vacio);
        hombreEntra;
        V(cuantosHombresHay);
        hombres += 1;
    }else{
        hombreEntra;
        V(cuantosHombresHay);
        hombres += 1;
    }
}

Process hombre_sale_baño{
    P(cuantosHombresHay);
    hombreSale;
    hombres -= 1;
    if(hombres == 0 && mujeres == 0){
        V(vacio);
    }
}


main(){
    initSem(cuantasMujeresHay,0);
    initSem(cuantosHombresHay,0);
    initSem(vacio);
    int mujeres = 0;
    int hombres = 0;
    parBegin; //concurrente
        hombre_sale_baño; hombre_entra_baño;
        mujer_entra_baño; mujer_sale_baño;
    parEnd;
}