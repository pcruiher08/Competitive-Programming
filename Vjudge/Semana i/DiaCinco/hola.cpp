RADIX	DEC
    PROCESSOR	18F45K50
    #INCLUDE	<P18F45K50.INC>
    
    AUX EQU 0x32
 
 VARIABLE1   EQU	    0
VARIABLE2   EQU	    1
 
    org 0x00
    goto start
   
    start:
    movlb 15
    clrf ANSELB,BANKED
    clrf ANSELA,BANKED
    clrf TRISB
    ;SETF TRISC
    MOVLW b'11111111'
    MOVWF TRISC
    ;setf LATA
    clrf LATB
    clrf AUX
    
    
    
    RutinaInicial:
    BTFSS PORTA,0
    GOTO TMRUNO
    NOP
    BTFSS PORTA,1
    GOTO TMRDOS
    NOP
    BTFSS PORTA,2
    GOTO TMRTRES
    NOP
    BTFSS PORTA,3
    GOTO TMRCUATRO
    NOP
    
    GOTO RutinaInicial

    
    ;TEMPORIZADOR 50MS
    TMRUNO:
    
    BTFSS PORTA,0
    GOTO TMRUNO
    NOP
    BTFSS PORTA,1
    GOTO TMRDOS
    NOP
    BTFSS PORTA,2
    GOTO TMRTRES
    NOP
    BTFSS PORTA,3
    GOTO TMRCUATRO
    NOP
    
    movlw b'01000111'
    movwf T0CON,A
    movlw d'60'
    movwf TMR0L,A
    bsf T0CON,7,A
    bsf AUX,0
    movff AUX,LATB
    CaLL DELAY
    
    loop1:
    btfss INTCON,2,A
    goto loop1
    bcf INTCON,2,A
;    clrf LATB
    goto TMRUNO
    
    
    ;TEMPORIZADOR 250MS
    TMRDOS:
    
    BTFSS PORTA,0
    GOTO TMRUNO
    NOP
    BTFSS PORTA,1
    GOTO TMRDOS
    NOP
    BTFSS PORTA,2
    GOTO TMRTRES
    NOP
    BTFSS PORTA,3
    GOTO TMRCUATRO
    NOP
    
    
    btfss PORTA,1
    goto TMRDOS
    movlw b'00000001'
    movwf T0CON,A
    movlw d'3036'
    movwf TMR0H,A
    bsf T0CON,7,A
    bsf AUX,0
    movff AUX,LATB
    
    loop2:
    btfss INTCON,2,A
    goto loop2
    bcf INTCON,2,A
    goto TMRDOS
    
    ;TEMPORIZADOR 500MS
    TMRTRES:
    
    BTFSS PORTA,0
    GOTO TMRUNO
    NOP
    BTFSS PORTA,1
    GOTO TMRDOS
    NOP
    BTFSS PORTA,2
    GOTO TMRTRES
    NOP
    BTFSS PORTA,3
    GOTO TMRCUATRO
    NOP
    
    
    btfss PORTA,2
    goto TMRTRES
    movlw b'00000010'
    movwf T0CON,A
    movlw d'3036'
    movwf TMR0H,A
    bsf T0CON,7,A
    bsf AUX,0
    movff AUX,LATB
    
    loop3:
    btfss INTCON,2,A
    goto loop3
    bcf INTCON,2,A
    goto TMRTRES
   
    
    ;TEMPORIZADOR 1SEG
    TMRCUATRO:
    
     BTFSS PORTA,0
    GOTO TMRUNO
    NOP
    BTFSS PORTA,1
    GOTO TMRDOS
    NOP
    BTFSS PORTA,2
    GOTO TMRTRES
    NOP
    BTFSS PORTA,3
    GOTO TMRCUATRO
    NOP
    
    btfss PORTA,3
    goto TMRCUATRO
    movlw b'00000011'
    movwf T0CON,A
    movlw d'3036'
    movwf TMR0H,A
    bsf T0CON,7,A
    bsf AUX,0
    movff AUX,LATB
    
    loop4:
    btfss INTCON,2,A
    goto loop4
    bcf INTCON,2,A
    goto TMRCUATRO
    
    
    DELAY:
    MOVLW   0x7F
    MOVWF   VARIABLE1
    MOVWF   VARIABLE2
    
LOOP1:
    DECFSZ  VARIABLE2
    GOTO    LOOP1
    DECFSZ  VARIABLE1
    GOTO    LOOP1
    RETURN

    
  ;CONFIG1L
  CONFIG  PLLSEL = PLL4X        ; PLL Selection (4x clock multiplier)
  CONFIG  CFGPLLEN = OFF        ; PLL Enable Configuration bit (PLL Disabled (firmware controlled))
  CONFIG  CPUDIV = NOCLKDIV     ; CPU System Clock Postscaler (CPU uses system clock (no divide))
  CONFIG  LS48MHZ = SYS24X4     ; Low Speed USB mode with 48 MHz system clock (System clock at 24 MHz, USB clock divider is set to 4)

; CONFIG1H
  CONFIG  FOSC = INTOSCIO       ; Oscillator Selection (Internal oscillator)
  CONFIG  PCLKEN = ON           ; Primary Oscillator Shutdown (Primary oscillator enabled)
  CONFIG  FCMEN = OFF           ; Fail-Safe Clock Monitor (Fail-Safe Clock Monitor disabled)
  CONFIG  IESO = OFF            ; Internal/External Oscillator Switchover (Oscillator Switchover mode disabled)

; CONFIG2L
  CONFIG  nPWRTEN = OFF         ; Power-up Timer Enable (Power up timer disabled)
  CONFIG  BOREN = SBORDIS       ; Brown-out Reset Enable (BOR enabled in hardware (SBOREN is ignored))
  CONFIG  BORV = 190            ; Brown-out Reset Voltage (BOR set to 1.9V nominal)
  CONFIG  nLPBOR = OFF          ; Low-Power Brown-out Reset (Low-Power Brown-out Reset disabled)

; CONFIG2H
  CONFIG  WDTEN = OFF           ; Watchdog Timer Enable bits (WDT disabled in hardware (SWDTEN ignored))
  CONFIG  WDTPS = 32768         ; Watchdog Timer Postscaler (1:32768)

; CONFIG3H
  CONFIG  CCP2MX = RC1          ; CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
  CONFIG  PBADEN = ON           ; PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
  CONFIG  T3CMX = RC0           ; Timer3 Clock Input MUX bit (T3CKI function is on RC0)
  CONFIG  SDOMX = RB3           ; SDO Output MUX bit (SDO function is on RB3)
  CONFIG  MCLRE = ON            ; Master Clear Reset Pin Enable (MCLR pin enabled; RE3 input disabled)

; CONFIG4L
  CONFIG  STVREN = ON           ; Stack Full/Underflow Reset (Stack full/underflow will cause Reset)
  CONFIG  LVP = ON              ; Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
  CONFIG  ICPRT = OFF           ; Dedicated In-Circuit Debug/Programming Port Enable (ICPORT disabled)
  CONFIG  XINST = OFF
  
  FINAL:
  
  
  END