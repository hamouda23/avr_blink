// ---------Labo1----------------- //
//Creer par HAMOUDA Samir le 13 Mai 2021



#define F_CPU 8000000UL
#include <avr/io.h> /* inclure la librairie de base de définition des pins… */
#include <util/delay.h> /* inclure la librairie de temporisation */
#include <avr/sfr_defs.h>
int main(void) {
	// -------- Initialisation ------------------------------------------------ //
	
	DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2); //Programmer les bit PD0,PD1 et PD2 en sortie
	PORTD |=(1<<PD3)|(1<<PD4); //  active la resitance de rappel 
	
	//-----------------------------------------------------------------------
	
	      while (1){
		      
		      //aucun bouton appuyé
		      if (bit_is_set (PIND,PD3) && bit_is_set(PIND,PD4)) {
			      //allumer le rouge
			      PORTD &= ~(1<<PD0) ;
			      //eteindre VERT ET BLEU
			      PORTD |=  (1<<PD2);
			      PORTD |=  (1<<PD1);
			      
			     
		      }
			  
		      // BTN PD3 APPUYE 
		      if (bit_is_clear (PIND,PD4) && bit_is_set(PIND,PD3)) {
			      //allumer JAUNE
			      PORTD &= ~(1<<PD1);
			      //eteindre ROUGE ET BLEU
			      PORTD &= ~(1<<PD0);
			      PORTD |= (1<<PD2);
			      
		      }
			  
		      
		      //BTN BTN PD4 APPYE 
		      if (bit_is_clear(PIND,PD4) && bit_is_clear(PIND,PD3)) {
			      //allumer VERT
			      PORTD &= ~(1<<PD1) ;
			      //eteindre ROUGE ET BLEU
			      PORTD |= (1<<PD0);
			      PORTD |= (1<<PD1);
			      
			      
		      }
		      
		      //si BTN 1 et 2 appuyé allumer D4 et D2
		      if (bit_is_clear (PIND,PD4) && bit_is_clear(PIND,PD3)) {
			      //allumer BLEU
			      PORTD |= (1<<PD2) ;
			      //eteindre ROUGE ET VERT
			      PORTD &= ~ (1<<PD1);
			      PORTD &= ~ (1<<PD0);
			      
		      }
			  
		      
		      
		      } /* Fin du code */
		      
		      return (0);
	      }
