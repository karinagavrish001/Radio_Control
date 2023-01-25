#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
 
void delay(void);
	
int main(void)
{
  int i;
  GPIO_InitTypeDef  GPIO_InitStructure;
 
 
  // Enable PORTB Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
  
  GPIO_ResetBits(GPIOB, GPIO_Pin_10); // Set B10 to Low level ("0")
 
  /* Initialize Button input PA1 */
  // Enable PORTA Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  /* Configure the GPIO_BUTTON pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  while (1) {
 
     if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) != 0) {
		 /* Toggle LED which connected to PB10*/
		 GPIOB->ODR ^= GPIO_Pin_10; // Invert B10
		 /* delay */
		void delay(void);
		 /* Toggle LED which connected to PB10*/
		 GPIOB->ODR ^= GPIO_Pin_10;
		 /* delay */
		void delay(void); }
		 else { GPIO_SetBits(GPIOB, GPIO_Pin_10); }
		GPIO_SetBits(GPIOB, GPIO_Pin_10); 
		void delay(void);
		GPIO_ResetBits(GPIOB, GPIO_Pin_10); 
		void delay(void);
		GPIOB->ODR&=~GPIO_Pin_10;
		void delay(void);
		GPIOB->ODR|=GPIO_Pin_10;
		void delay(void);

  }
}
