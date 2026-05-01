/*
 * File:   Test_PWM.c
 * Author: Djelalli Larioumlil
 *
 * Created on 3 juin 2018, 22:41
 * 
 * Code C minimum activant les PWM et EPWM des broches RC2 et RD4
 * 
 * 
 *  
 */


#include <xc.h>

#pragma config OSC = HS // d´epend de l ? oscillateur utilisé
#pragma config WDT = OFF // pas de watchdog pour debug
#pragma config LVP = OFF // pas de lvp (Low Voltage Programming ) pour l?icd

#define _XTAL_FREQ 10000000

void main(void) {
   
   // Configuration des broches RC2 et RD4 comme sorties
   TRISC2 = 0; // sortie PWM sur pin RC2
   TRISD4 = 0; // sortie EPWM sur pin RD4
   
   // Configuration fréquence PWM1 (CCP1 ---> RC2) et PWM2 (ECCP1 ---> RD4)
   // PR2 = 249 pour Fosc = 10KHz; La fréquence est commune pour les 2 PWM
   PR2 = 249;                    // PR2 =((PWM Period * Fosc)/4) - 1
                                 // PR2 =(((1/10000) * 10000000)/4) - 1 = 249
   // La valeur du rapport cyclique peut varier entre 0 et PR2 : donc 0 < PR2 < 249
    
    
   // configuration des registres PWM et EPWM
   CCP1CON = 0b00001100 ;        // registre configuration PWM
   ECCP1CON = 0b00001100 ;       // registre configuration EPWM
    
   // Start de la fonction PWM et EPWM
   T2CONbits.TMR2ON = 1;         //start the PWM    
        
   while(1)
   {
       // boucle "for" pour faire varier de façon logiciel la valeur du rapport cyclique 
       for(int i=0; i<249; i++){ // 
           
           CCPR1L = i;  // CCPR1L : registre dans lequel on écrit la valeur du rapport cyclique de PWM1
           
           ECCPR1L = 249- i;  // ECCPR1L : registre dans lequel on écrit la valeur du rapport cyclique de PWM2
           
           __delay_ms(10);   // délai pour faire varier lentement le rapport cyclique        
       }
       
       for(int i=249; i>0; i--){ // 
           
           CCPR1L = i;
           ECCPR1L = 249- i;
           __delay_ms(100);           
       }
   }
}
