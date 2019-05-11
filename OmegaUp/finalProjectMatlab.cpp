function flux()

%INICIA INTERFACE GRAFICA
promt = {'Criterio de convergencia: ', 'x1: ','x2: ', 'x3: ','x4: ','x5: ', 'x6: ', 'x7: ','Densidad de flujo kg*m^-3: ', 'Viscocidad dinámica (kg/m-s): ', 'Diametro interno de la tubería (mm): ','Rugosidad de la tubería (mm): ', 'Longitud del tubo 1: ','Longitud del tubo 2: ', 'Longitud del tubo 3: ','Longitud del tubo 4: ','Longitud del tubo 5: ', 'Longitud del tubo 6: ', 'Longitud del tubo 7: '};
title = 'Flujos';
dims = [0.9 50];
definput = {'0.1','1','1','1','1','1','1','1','997.08','0.0008937','154','0.046','100','300','1200','1200','300','1200','300'};
opts.Interpreter = 'tex';
answer = inputdlg(promt,title,dims,definput,opts);
%valores de entrada en GUI
C = str2double(answer{1});
x1 = str2double(answer{2});
x2 = str2double(answer{3});
x3 = str2double(answer{4});
x4 = str2double(answer{5});
x5 = str2double(answer{6});
x6 = str2double(answer{7});
x7 = str2double(answer{8});
p  = str2double(answer{9});
V  = str2double(answer{10});
d  = str2double(answer{11});
R  = str2double(answer{12});
L1 = str2double(answer{13});
L2 = str2double(answer{14});
L3 = str2double(answer{15});
L4 = str2double(answer{16});
L5 = str2double(answer{17});
L6 = str2double(answer{18});
L7 = str2double(answer{19});
xViejas = [x1;x2;x3;x4;x5;x6;x7];
longitudes = [L1;L2;L3;L4;L5;L6;L7];
flag = true;
%inicia ciclo while que itera hasta que el error de las ecuaciones sea menor al que se busca
iteracion = 0;
while(flag)
    [ReynoldsNumber1,factor1] = frictionFactor(p,V,d,R,x1);
    [ReynoldsNumber2,factor2] = frictionFactor(p,V,d,R,x2);
    [ReynoldsNumber3,factor3] = frictionFactor(p,V,d,R,x3);
    [ReynoldsNumber4,factor4] = frictionFactor(p,V,d,R,x4);
    [ReynoldsNumber5,factor5] = frictionFactor(p,V,d,R,x5);
    [ReynoldsNumber6,factor6] = frictionFactor(p,V,d,R,x6);
    [ReynoldsNumber7,factor7] = frictionFactor(p,V,d,R,x7);
    iteracion = iteracion + 1;
    X=[x1;x2;x3;x4;x5;x6;x7];
    
    %declaracion de matrices
    D = [
    1,-1,-1, 0, 0, 0, 0;
    0, 1, 0,-1,-1, 0, 0;
    0, 0,-1, 0,-1, 1, 0;
    0, 0, 0,-1, 0,-1, 1;

    0,-2*factor2*L2*x2,2*L3*factor3*x3,0,-2*L5*factor5*x5,0,0;
    0,0,0,-2*L4*factor4*x4,2*L5*factor5*x5,2*factor6*L6*x6,0;
    2*L1*factor1*x1,2*L2*factor2*x2,0,2*factor4*L4*x4,0,0,2*factor7*L7*x7;
    
    ];

    F=[
    x1-x2-x3;
    x2-x4-x5;
    x6-x5-x3;
    x7-x4-x6;

    (L3*factor3*(x3^2)-L5*factor5*(x5^2)-L2*factor2*(x2^2));
    (L5*factor5*(x5^2)+L6*factor6*(x6^2)-L4*factor4*(x4^2));
    (L7*factor7*(x7^2)+L1*factor1*(x1^2)+L2*factor2*(x2^2)+L4*factor4*(x4^2));%%checar el valor de la ultima constante
    
    ];

    X = (X - (D\F)); %calculo del metodo de manera eficiente sin utilizar inv()

    error1 = 100 * abs( 1 - x1 / X(1,1) );
    error2 = 100 * abs( 1 - x2 / X(2,1) );
    error3 = 100 * abs( 1 - x3 / X(3,1) );
    error4 = 100 * abs( 1 - x4 / X(4,1) );
    error5 = 100 * abs( 1 - x5 / X(5,1) );
    error6 = 100 * abs( 1 - x6 / X(6,1) );
    error7 = 100 * abs( 1 - x7 / X(7,1) );

    
    %no se detendra sino hasta que todos los errores sean menores que el
    %criterio de convergencia, asegurando asi que la cantidad de
    %iteraciones sera la indicada.
    if(error1 < C & error2 < C & error3<C & error4<C & error5 < C & error6<C & error7<C)
        flag = false;
    end

    %para evitar iteraciones extras al momento de imporimir, se evita usar
    %un for loop a continuacion, sacrificando memoria por tiempo de
    %ejecucion
    x1 = X(1,1);
    x2 = X(2,1);
    x3 = X(3,1);
    x4 = X(4,1);
    x5 = X(5,1);
    x6 = X(6,1);
    x7 = X(7,1);

    disp ("x1,x2,x3,x4,x5,x6,x7 en m^3 * s^-1 toman respectivamente los siguientes valores");
    disp (X);
    disp ("iteracion # " + iteracion);
end

disp ("x1,x2,x3,x4,x5,x6,x7 en m^3 * s^-1 terminan respectivamente con los siguientes valores");
disp (X);


disp ("los valores iniciales fueron respectivamente para x1,x2,x3,x4,x5,x6,x7");
disp (xViejas);

disp ("los valores iniciales fueron respectivamente para L1,L2,L3,L4,L5,L6,L7");
disp (longitudes);

disp("El numero de iteraciones fue: " + iteracion);
disp("El criterio de convergencia utilizado fue: " + C);
disp("La densidad de flujo utilizada: " + p + " kg*m^-3");
disp("La Viscocidad dinámica utilizada: " + V + " kg/m-s");
disp("El diametro interno de la tuberia utilizado: " + d + " mm");
disp("La rugosidad de la tuberia utilizada: " + R + " mm");
end

function [Y] = equation(f,e,D,Nr) 
    Y = -2 * log10((e/(3.7*D)) + (2.51/Nr*(f^(1/2))))-1/(f^(1/2));
end

function [finalValue] = bisectionNumericalMeethod(e,D,Nr)
    firstValue = 0.1;
    secondValue = 1; 
    for i = 0:100
        firstSign = sign(equation(firstValue,e,D,Nr));
        secondSign = sign(equation(secondValue,e,D,Nr)); 
        newXValue = ((firstValue+secondValue)/2);
        newSign = sign(equation(newXValue,e,D,Nr));
        if(newSign == 1)
            if(firstSign == -1)
                secondValue = newXValue;
            end
            if(secondSign == -1)
                firstValue = secondValue; 
                secondValue = newXValue;
            end
        end
        if(newSign == -1)
            if(firstSign == 1)
                firstValue = newXValue; 
                secondValue = firstValue;
            end
            if(secondSign == 1)
                firstValue = newXValue;
            end
        end
    end
    finalValue = newXValue;
end

function [ReynoldsNumber, fricFact] = frictionFactor(p,V,D,R,F)
    ReynoldsNumber = ((p*D* (F/((3.141592653589/4)*D^2)) )/V);
    
    if (ReynoldsNumber <= 2100)
        fricFact = 64 / ReynoldsNumber;
    end
    
    if (ReynoldsNumber > 2100 & ReynoldsNumber < 4000)
        fricFact = ReynoldsNumber;
    end
    
    if (ReynoldsNumber >= 4000)
        fricFact = bisectionNumericalMeethod(R,D,ReynoldsNumber);
    end
end
