
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void Led_Config(void);
void Buton_Config(void);


int main(void)
{
	Led_Config();
	Buton_Config();
  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
	  {
		  GPIO_ToggleBits(GPIOD, GPIO_Pin_All);
	  }
  }
}

void Led_Config(void)
{
	GPIO_InitTypeDef Led = {0};

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	Led.GPIO_Mode = GPIO_Mode_OUT;
	Led.GPIO_OType = GPIO_OType_PP;
	Led.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	Led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	Led.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &Led);
}


void Buton_Config(void)
{
	GPIO_InitTypeDef Button = {0};

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	Button.GPIO_Mode = GPIO_Mode_IN;
	Button.GPIO_OType = GPIO_OType_PP;
	Button.GPIO_Pin = GPIO_Pin_0;
	Button.GPIO_PuPd = GPIO_PuPd_DOWN;
	Button.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA, &Button);
}





/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
