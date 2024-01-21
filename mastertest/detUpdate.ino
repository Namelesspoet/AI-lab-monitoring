
void UpdateState2P(int *val,bool* sw) {
  val[0]=((sw[0]!=0) ? digitalRead(PIN_0):0); 
  val[1]=((sw[1]!=0) ? digitalRead(PIN_1):0); 
  val[2]=((sw[2]!=0) ? digitalRead(PIN_2):0); 
  val[3]=((sw[3]!=0) ? digitalRead(PIN_3):0); 
  val[4]=((sw[4]!=0) ? digitalRead(PIN_4):0); 
}

// Det3p DetState3P (int *sw, int *type)
// {
//   Det3p det;
//   int pin;
//   for (int i = 5; i < 10;i++)
//     {
      
//       if (sw[i]!=0)
//       {
//         switch(type[i-5])//{"Temp det","Temp + humid det","IR led","IR det"}
//         {
//           case 0://Temp det           
            

//             break;
//           case 1://Temp + humid det

//             break;
//           case 2://IR led

//             break;
//           case 3://IR det

//             break;
//         }
//       }
//     }

// }