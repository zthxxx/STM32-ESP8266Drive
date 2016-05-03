/**
  ******************************************************************************
  * @file    wifi_config.c
  * @author  fire
  * @version V1.0
  * @date    2014-xx-xx
  * @brief   WiFiģ��ӿ���������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ISO-STM32 ������
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
	*/

#include "wifi_config.h"
#include "bsp_SysTick.h"
#include "bsp_gpio.h"
#include "bsp_usart1.h"
#include "bsp_usart2.h"
#include "SPI.h"
#include "oled.h"

struct  STRUCT_USARTx_Fram strEsp8266_Fram_Record = { 0 };
struct  STRUCT_USART1_1_Fram str1_1esp8266 = {0} ;

bool IS_WIFI_LOG_DEBUG = true;

char WIFI_SSID_NAME[] = "Signal_Process_PandoraBox2.4";
char WIFI_PASSWORD[] = "zhanglaoshidianhuahaoma";//�˴���ʹ����������ip
char TCP_SERVER_IPADDRESS[] = "TIAN";
char TCP_SERVER_PORT[] = "31500";
char TCP_CILENT_IPADDRESS[] = "ESP_113AFD";
char TCP_CILENT_PORT[] = "50000";


/**
  * @brief  WiFi_Config wifi ��ʼ��
  * @param  ��
  * @retval ��
  */
void WiFi_Config( void )
{
	WiFi_RST_INIT();
}

void ESP8266_WIFI_GPIO_Config( void )
{		
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /*����GPIOA������ʱ��*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE ); 

    /* ����WiFiģ���Ƭѡ��CH������	��λ������RST������*/
    /*ѡ��Ҫ���Ƶ�GPIOA0��CH�����ź�GPIOA1��RST������*/															   
    GPIO_InitStructure.GPIO_Pin = WIFI_RST_GPIO_Pin;	

    /*��������ģʽΪͨ���������*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

    /*������������Ϊ50MHz */   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

    /*���ÿ⺯������ʼ��GPIOA*/
    GPIO_Init( WIFI_RST_GPIO_Port, &GPIO_InitStructure );	 

    /*	*/
    GPIO_ResetBits( WIFI_RST_GPIO_Port, WIFI_RST_GPIO_Pin );// ����WiFiģ��ĸ�λ��������	
}

/*********************************************************end of file**************************************************/