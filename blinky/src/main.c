#include "stm8s.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Delay(uint16_t nCount);

void init()
{
#ifdef STM8S003
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
#endif

#ifdef STM8S103
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
#endif

#ifdef STM8S105
  GPIO_Init(GPIOE, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
#endif
}

void runloop()
{
  Delay(1000);

#ifdef STM8S003
  GPIOD->ODR ^= GPIO_PIN_3;
#endif

#ifdef STM8S103
  GPIOB->ODR ^= GPIO_PIN_5;
#endif

#ifdef STM8S105
  GPIOE->ODR ^= GPIO_PIN_5;
#endif
}

void main(void)
{
  init();
  
  while (1)
  {
    // Toggle a bit in the output data register to blink the LED
    runloop();
  }
}

void Delay(uint16_t nCount)
{
  uint8_t i;
  for(; nCount !=0 ; nCount--)
  {
    for(i=255;i!=0;i--) {}
  }
}

// This is called by some of the SPL files on error.
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  (void)file;
  (void)line;

  /* User can add their own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
