// Example sketch controlling GU20x8 display directly connected to Arduino Nano
//
// Pin connections:
// GU20x8 Address pins  A0..A5          <--> Arduino A0..A5
// GU20x8 Data pins     D0, D1, D2..D7  <--> Arduino RX0, TX1, D2..D7
// GU20x8 control pin   c/D             <--> Arduino D8
// GU20x8 control pin   WR              <--> Arduino D9
// GU20x8 control pin   BUSY            <--> Arduino D10
// GU20x8 control pin   EN              <--> Arduino D11
//

#include "Display.h"
#include "IConnection.h"

// Arduino PORTC = A0..A7
#define AddressPort PORTC
#define AddressPortDirection DDRC
#define AddressMask 0b00111111

// Arduino PORTD = RX0+TX1+D2..D7
#define DataPort PORTD
#define DataPortDirection DDRD
#define DataMask 0b11111111

// Arduino PORTB = D8..D13
#define ControlPort PORTB
#define ControlPortDirection DDRB
#define ControlPort_cD PORTB0
#define ControlPort_WR PORTB1
#define ControlPort_BUSY PORTB2
#define ControlPort_ENABLE PORTB3

#define SetBits(reg,value,valueMask) { (reg) = ((reg) & ~(valueMask)) | ((value) & (valueMask));}
#define SetBitPos(reg,pos,val) { if (val) (reg) |= (1<<(pos)); else (reg) &= ~(1 << (pos));}

class Connection : public GU20x8::IConnection
{
    virtual void ConfigureBus()
    {
        AddressPortDirection |= AddressMask;
        DataPortDirection |= DataMask;
        ControlPortDirection |= (1 << ControlPort_cD) | (1 << ControlPort_WR) | (1 << ControlPort_ENABLE);
        ControlPortDirection &= ~(1 << ControlPort_BUSY);
    }

    virtual void SetAddressBus(uint8_t address)
    {
        SetBits(AddressPort, address, AddressMask);
    }
    virtual void SetDataBus(uint8_t data)
    {
        SetBits(DataPort, data, DataMask);
    }
    virtual void SetCDBit(bool value)
    {
        SetBitPos(ControlPort, ControlPort_cD, value);
    }
    virtual void SetENBit(bool value)
    {
        SetBitPos(ControlPort, ControlPort_ENABLE, value);
    }
    virtual void SetWRBit(bool value)
    {
        SetBitPos(ControlPort, ControlPort_WR, value);
    }
    virtual bool GetBusyBit()
    {
        return ControlPort & ControlPort_BUSY;
    }
};

Connection connection;
GU20x8::Display vfd(connection);

void setup()
{
  
  
}

void loop()
{

 vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b11000010, 0b00000000);
    vfd.WriteColumn( 1, 0b10100001, 0b00000000);
    vfd.WriteColumn( 2, 0b10010001, 0b00000000);
    vfd.WriteColumn( 3, 0b10010001, 0b00000000);
    vfd.WriteColumn( 4, 0b10001110, 0b00000000);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b11111110, 0b00000000);
    vfd.WriteColumn( 7, 0b00100000, 0b00000000);
    vfd.WriteColumn( 8, 0b01010000, 0b00000000);
    vfd.WriteColumn( 9, 0b10001000, 0b00000000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000100, 0b00000000);
    vfd.WriteColumn(12, 0b00000110, 0b00000000);
    vfd.WriteColumn(13, 0b11111111, 0b00000000);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b01110110, 0b00000000);
    vfd.WriteColumn(16, 0b10001001, 0b00000000);
    vfd.WriteColumn(17, 0b10001001, 0b00000000);
    vfd.WriteColumn(18, 0b10001001, 0b00000000);
    vfd.WriteColumn(19, 0b01110110, 0b00000000);
  delay(1000);

   vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b11000010);
    vfd.WriteColumn( 1, 0b00000000, 0b10100001);
    vfd.WriteColumn( 2, 0b00000000, 0b10010001);
    vfd.WriteColumn( 3, 0b00000000, 0b10010001);
    vfd.WriteColumn( 4, 0b00000000, 0b10001110);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b00000000, 0b11111110);
    vfd.WriteColumn( 7, 0b00000000, 0b00100000);
    vfd.WriteColumn( 8, 0b00000000, 0b01010000);
    vfd.WriteColumn( 9, 0b00000000, 0b10001000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000000, 0b00000100);
    vfd.WriteColumn(12, 0b00000000, 0b00000110);
    vfd.WriteColumn(13, 0b00000000, 0b11111111);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b01110110);
    vfd.WriteColumn(16, 0b00000000, 0b10001001);
    vfd.WriteColumn(17, 0b00000000, 0b10001001);
    vfd.WriteColumn(18, 0b00000000, 0b10001001);
    vfd.WriteColumn(19, 0b00000000, 0b01110110);
  delay(1000);

   vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b11000010, 0b11000010);
    vfd.WriteColumn( 1, 0b10100001, 0b10100001);
    vfd.WriteColumn( 2, 0b10010001, 0b10010001);
    vfd.WriteColumn( 3, 0b10010001, 0b10010001);
    vfd.WriteColumn( 4, 0b10001110, 0b10001110);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b11111110, 0b11111110);
    vfd.WriteColumn( 7, 0b00100000, 0b00100000);
    vfd.WriteColumn( 8, 0b01010000, 0b01010000);
    vfd.WriteColumn( 9, 0b10001000, 0b10001000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000100, 0b00000100);
    vfd.WriteColumn(12, 0b00000110, 0b00000110);
    vfd.WriteColumn(13, 0b11111111, 0b11111111);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b01110110, 0b01110110);
    vfd.WriteColumn(16, 0b10001001, 0b10001001);
    vfd.WriteColumn(17, 0b10001001, 0b10001001);
    vfd.WriteColumn(18, 0b10001001, 0b10001001);
    vfd.WriteColumn(19, 0b01110110, 0b01110110);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(2);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b11000010, 0b11000010);
    vfd.WriteColumn( 1, 0b10100001, 0b10100001);
    vfd.WriteColumn( 2, 0b10010001, 0b10010001);
    vfd.WriteColumn( 3, 0b10010001, 0b10010001);
    vfd.WriteColumn( 4, 0b10001110, 0b10001110);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b11111110, 0b11111110);
    vfd.WriteColumn( 7, 0b00100000, 0b00100000);
    vfd.WriteColumn( 8, 0b01010000, 0b01010000);
    vfd.WriteColumn( 9, 0b10001000, 0b10001000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000100, 0b00000100);
    vfd.WriteColumn(12, 0b00000110, 0b00000110);
    vfd.WriteColumn(13, 0b11111111, 0b11111111);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b01110110, 0b01110110);
    vfd.WriteColumn(16, 0b10001001, 0b10001001);
    vfd.WriteColumn(17, 0b10001001, 0b10001001);
    vfd.WriteColumn(18, 0b10001001, 0b10001001);
    vfd.WriteColumn(19, 0b01110110, 0b01110110);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(1);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b11000010, 0b11000010);
    vfd.WriteColumn( 1, 0b10100001, 0b10100001);
    vfd.WriteColumn( 2, 0b10010001, 0b10010001);
    vfd.WriteColumn( 3, 0b10010001, 0b10010001);
    vfd.WriteColumn( 4, 0b10001110, 0b10001110);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b11111110, 0b11111110);
    vfd.WriteColumn( 7, 0b00100000, 0b00100000);
    vfd.WriteColumn( 8, 0b01010000, 0b01010000);
    vfd.WriteColumn( 9, 0b10001000, 0b10001000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000100, 0b00000100);
    vfd.WriteColumn(12, 0b00000110, 0b00000110);
    vfd.WriteColumn(13, 0b11111111, 0b11111111);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b01110110, 0b01110110);
    vfd.WriteColumn(16, 0b10001001, 0b10001001);
    vfd.WriteColumn(17, 0b10001001, 0b10001001);
    vfd.WriteColumn(18, 0b10001001, 0b10001001);
    vfd.WriteColumn(19, 0b01110110, 0b01110110);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(0);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b11000010, 0b11000010);
    vfd.WriteColumn( 1, 0b10100001, 0b10100001);
    vfd.WriteColumn( 2, 0b10010001, 0b10010001);
    vfd.WriteColumn( 3, 0b10010001, 0b10010001);
    vfd.WriteColumn( 4, 0b10001110, 0b10001110);
    vfd.WriteColumn( 5, 0b00000000, 0b00000000);
    vfd.WriteColumn( 6, 0b11111110, 0b11111110);
    vfd.WriteColumn( 7, 0b00100000, 0b00100000);
    vfd.WriteColumn( 8, 0b01010000, 0b01010000);
    vfd.WriteColumn( 9, 0b10001000, 0b10001000);
    vfd.WriteColumn(10, 0b00000000, 0b00000000);
    vfd.WriteColumn(11, 0b00000100, 0b00000100);
    vfd.WriteColumn(12, 0b00000110, 0b00000110);
    vfd.WriteColumn(13, 0b11111111, 0b11111111);
    vfd.WriteColumn(14, 0b00000000, 0b00000000);
    vfd.WriteColumn(15, 0b01110110, 0b01110110);
    vfd.WriteColumn(16, 0b10001001, 0b10001001);
    vfd.WriteColumn(17, 0b10001001, 0b10001001);
    vfd.WriteColumn(18, 0b10001001, 0b10001001);
    vfd.WriteColumn(19, 0b01110110, 0b01110110);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011110, 0b00000000);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011110, 0b00000000);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);



     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  //   patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 1  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00010000, 0b00000000);
    vfd.WriteColumn(14, 0b00010000, 0b00000000);
    vfd.WriteColumn(15, 0b00010000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 2  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00010000, 0b00000000);
    vfd.WriteColumn(14, 0b00100000, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 3  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00010000, 0b00000000);
    vfd.WriteColumn(14, 0b00010000, 0b00000000);
    vfd.WriteColumn(15, 0b00010000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 3  copy patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 4  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000001);
    vfd.WriteColumn( 1, 0b00000000, 0b01000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000010);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00001000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b01000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000100);
    vfd.WriteColumn(18, 0b00000000, 0b00000001);
    vfd.WriteColumn(19, 0b00000000, 0b01000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 5  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110001, 0b00000001);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 6  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110010, 0b00000010);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 7  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110100, 0b00000100);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001001, 0b00000001);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 8  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00111000, 0b00001000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001010, 0b00000010);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000001, 0b00000001);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 9  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000001, 0b00000001);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011110, 0b00000000);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011110, 0b00000000);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00010000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001100, 0b00000100);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000010, 0b00000010);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 10  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000010, 0b00000010);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00100000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110001, 0b00000001);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00001000);
    vfd.WriteColumn(14, 0b00000101, 0b00000001);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000100, 0b00000100);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 11  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000100, 0b00000100);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b01110000, 0b01000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110010, 0b00000010);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00011000, 0b00010000);
    vfd.WriteColumn(14, 0b00000110, 0b00000010);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00001000, 0b00001000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 12  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00001000, 0b00001000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011101, 0b00000001);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b10110000, 0b10000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110100, 0b00000100);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00101000, 0b00100000);
    vfd.WriteColumn(14, 0b00000100, 0b00000100);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00010000, 0b00010000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000001, 0b00000001);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 13  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00010000, 0b00010000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011110, 0b00000010);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00111000, 0b00001000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b01001000, 0b01000000);
    vfd.WriteColumn(14, 0b00001100, 0b00001000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00100000, 0b00100000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000010, 0b00000010);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 14  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00100000, 0b00100000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000100);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00010000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b10001000, 0b10000000);
    vfd.WriteColumn(14, 0b00010100, 0b00010000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b01000000, 0b01000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000100, 0b00000100);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 15  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b01000000, 0b01000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00001000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00100000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00100100, 0b00100000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b10000000, 0b10000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00001000, 0b00001000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 16  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b10000000, 0b10000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00010000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b01110000, 0b01000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b01000100, 0b01000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00010000, 0b00010000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 17  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00111100, 0b00100000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b10110000, 0b10000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b10000100, 0b10000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00100000, 0b00100000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 18  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b01011100, 0b01000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b01000000, 0b01000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 19  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b10011100, 0b10000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b10000000, 0b10000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();

  // 20  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);

     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();


  // 21  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011110, 0b00000000);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011110, 0b00000000);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00010000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();


  // 22  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00001000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();


  // 23  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000100);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();


  // 24  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000010);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();



  // 25  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000001);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);


     vfd.Begin();
    vfd.ClearScreen() ;
    vfd.SetBrightness(3);
    vfd.EnableDisplay();


  // 26  patterns:         red         blue
    vfd.WriteColumn( 0, 0b00000000, 0b00000000);
    vfd.WriteColumn( 1, 0b00000000, 0b00000000);
    vfd.WriteColumn( 2, 0b00000101, 0b00000000);
    vfd.WriteColumn( 3, 0b00011010, 0b00000100);
    vfd.WriteColumn( 4, 0b00011100, 0b00000000);
    vfd.WriteColumn( 5, 0b00011010, 0b00000100);
    vfd.WriteColumn( 6, 0b01110101, 0b00000000);
    vfd.WriteColumn( 7, 0b00110000, 0b00000000);
    vfd.WriteColumn( 8, 0b01110000, 0b00000000);
    vfd.WriteColumn( 9, 0b00110000, 0b00000000);
    vfd.WriteColumn(10, 0b01110000, 0b00000000);
    vfd.WriteColumn(11, 0b00110000, 0b00000000);
    vfd.WriteColumn(12, 0b01110000, 0b00000000);
    vfd.WriteColumn(13, 0b00001000, 0b00000000);
    vfd.WriteColumn(14, 0b00000100, 0b00000000);
    vfd.WriteColumn(15, 0b00000000, 0b00000000);
    vfd.WriteColumn(16, 0b00000000, 0b00000000);
    vfd.WriteColumn(17, 0b00000000, 0b00000000);
    vfd.WriteColumn(18, 0b00000000, 0b00000000);
    vfd.WriteColumn(19, 0b00000000, 0b00000000);
  delay(1000);



}
