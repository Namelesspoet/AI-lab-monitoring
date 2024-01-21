#define PIN_MOVE 5
#define PIN_0   1
#define PIN_1   2
#define PIN_2   3
#define PIN_3   4
#define PIN_4   5
#define PIN_5  6//аналоговый датчик температуры
#define PIN_6 7
#define PIN_7 8
#define PIN_8 9
#define PIN_9 10

#include <iarduino_DHT.h>
//#include <OneWire.h>

int Det2pState[5]={0};
//  iarduino_DHT HumTem5(PIN_5);//HumTem5.hum (%), HumTem5.tem (*C)
//   iarduino_DHT HumTem6(PIN_6);
//   iarduino_DHT HumTem7(PIN_7);
//   iarduino_DHT HumTem8(PIN_8);
//   iarduino_DHT HumTem9(PIN_9);



// struct Det3p {
//   float HumTem[4];
//   float TemHum[5];
//   float TempAnalog5;
// } pinMode(PIN_MOVE, INPUT);  //пин датчика движения на считывание

// pinMode(PIN_0, INPUT);
// pinMode(PIN_1, INPUT);
// pinMode(PIN_2, INPUT);
// pinMode(PIN_3, INPUT);
// pinMode(PIN_4, INPUT);
// pinMode(PIN_5, INPUT);
// pinMode(PIN_6, INPUT);
// pinMode(PIN_7, INPUT);
// pinMode(PIN_8, INPUT);
// pinMode(PIN_9, INPUT);

// void Det3pINI() {

//   for (int j = 5; j < 10; j++) {

//     if (sw[j] != 0) {
//       switch (type[j - 5])  //{"Temp det","Temp + humid det","IR led","IR det"}
//       {
//         case 0:  //Temp det
          
//           break;
//         case 1:  //Temp + humid det

//           break;
//         case 2:  //IR led

//           break;
//         case 3:  //IR det

//           break;
//       }
//     }
//   }
// }


int PinNum(int num) {
  int pin = -1;
  switch (num) {
    case 0: pin = PIN_0; break;
    case 1: pin = PIN_1; break;
    case 2: pin = PIN_2; break;
    case 3: pin = PIN_3; break;
    case 4: pin = PIN_4; break;
    case 5: pin = PIN_5; break;
    case 6: pin = PIN_6; break;
    case 7: pin = PIN_7; break;
    case 8: pin = PIN_8; break;
    case 9: pin = PIN_9; break;
  }
  return pin;
}
