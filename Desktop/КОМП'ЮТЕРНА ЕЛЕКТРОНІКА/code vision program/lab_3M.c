#include <mega128.h>
#include <delay.h>
//����, �� ��������� �������������� ���
char decode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
char cdig;//����� ������������ ����� �� ������
char dig[4]={0,1,2,3};//����� �� ������

interrupt [TIM0_OVF] void timer0_ovf_isr(void){
    TCNT0=0xB0;    //���������� ���� ��� �����������
    if (cdig++==4) cdig=0;//���� �������� �����
    PORTD=~decode[dig[cdig]];//��������� ���� �����
    PORTB=PINB & 0xF0 | (1 << cdig); //��������� ��� ������ �����
    }

void main(void){
    PORTB=0x00;DDRB=0x0F;//���� ������ �����
    PORTC=0x00;DDRC=0x00;
    PORTD=0x00;DDRD=0xFF;//���� ���� �����
    //� ���������.������ TCCR0 � ��� ��� ����������. ��� ��������� �� 256
    TCCR0=0x04;TCNT0=0xB0;//��� ��� ����������� 
    
 TIMSK=0x02;
    #asm("sei")
    while (1){
    delay_ms(1000);
            dig[0]=2;dig[1]=4;dig[2]=8;dig[3]=0;}
    }