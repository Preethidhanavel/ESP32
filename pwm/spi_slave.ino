#include <REG51.H>
#include <string.h>

#define LCD_PORT P2
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

#define SPI_MISO P1^6 // Connect to MOSI of master
#define SPI_MOSI P1^5 // Connect to MISO of master
#define SPI_SCK  P1^7
#define SPI_SS   P1^4

unsigned char receive[7];

// Dummy delay
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void LCD_CMD(char cmd)
{
    LCD_PORT = cmd;
    RS = 0; RW = 0; EN = 1;
    delay_ms(2);
    EN = 0;
    delay_ms(5);
}

void LCD_INIT()
{
    LCD_CMD(0x38); // 8-bit mode
    LCD_CMD(0x0C); // Display on, cursor off
    LCD_CMD(0x06); // Increment cursor
    LCD_CMD(0x01); // Clear display
    LCD_CMD(0x80); // Cursor to first line
}

void LCD_CHAR(char ch)
{
    LCD_PORT = ch;
    RS = 1; RW = 0; EN = 1;
    delay_ms(2);
    EN = 0;
    delay_ms(5);
}

void LCD_STRING(char* str)
{
    while(*str)
    {
        LCD_CHAR(*str++);
    }
}

// SPI Slave Init (For 8051 with SPI peripheral like AT89S8253 or similar)
void SPI_Init()
{
    SPCON = 0xC0;  // Enable SPI (bit6), Slave mode (bit5), CPOL=0, CPHA=0
    SPSTA = 0x00;  // Clear SPI status
}

// SPI receive function
unsigned char SPI_Receive()
{
    while(!(SPSTA & 0x80));  // Wait for SPIF
    return SPDAT;
}

// SPI send function (send dummy or reply data)
void SPI_Send(unsigned char ch)
{
    SPDAT = ch;
    while(!(SPSTA & 0x80)); // Wait for SPIF
}

void main()
{
    unsigned char rx;
    unsigned int i = 0, j = 0, k = 0;

    SPI_Init();
    LCD_INIT();
    LCD_STRING("Slave Receive");

    // Wait for master to send 0x01
    while(SPI_Receive() != 0x01);

    while(k != 16)
    {
        do
        {
            rx = SPI_Receive();
            receive[j++] = rx;
        } while (rx != 0);

        LCD_CMD(0xC0); // Move to second line
        for(i = 0; i < j - 1; i++)
        {
            LCD_CHAR(receive[i]);
        }
        j = 0;
        memset(receive, 0, 7);
        k++;
    }

    while(1);
}
