#include <C:\Users\jabre\AppData\Local\Energia15\packages\energia\hardware\tivac\1.0.4\cores\tivac\wiring_analog.c>
#define saida PD_0
#define saida2 PD_1
int pot1 = A5;
int pot2 = A4;
int pot3 = A2;
int pot4 = A1;
float teta;
int a = 620 ;
int a2 = 620;
int f = 60;
float w=2*PI*f;
int d,x;
float v,i;
long int t, ta, ta2;
int td = 500000;
int th = 500;
int leitura1;
int leitura2;
int leitura3;
int leitura4;
unsigned long int P,Q,S;
int am=2000;
float tetai, tetav;
int Imax = am/7;

void setup() {
  Serial.begin(115200);
 // P = am*am;
  //Q = P/4;
}

void loop() {
  leitura1 = analogRead(pot1);
  leitura2 = analogRead(pot2);
  leitura3 = analogRead(pot3);
  leitura4 = analogRead(pot4);
  a = leitura1 * am / 4095.0;
  tetav = leitura2 * (2*PI) / 4095.0;
  P = (leitura3*leitura3)/4;
  Q = (leitura4*leitura4)/4;
  t = micros();
  
  if(t-ta > th){
    ta=t;
    v = a*sin((w*t)/1000000+tetav)+2048;
   // Serial.println(teta);
    i = a2*sin(((w*t)/1000000) + tetai)+2048;
    d = v;
    x=i;
    PWMWrite(saida,4096,d,50000);
    PWMWrite(saida2,4096,i,50000);
 //Serial.print(d);
 //Serial.print("\t");
   //Serial.println(x);
  }
  if(t-ta2 > td){
    ta2=t;
    Serial.println(P);
    Serial.println(Q);
    S = sqrt((P*P)+(Q*Q));
    Serial.println(S);
    teta = atan((Q*1.0)/(P*1.0));
    Serial.println(teta);
    tetai= tetav - teta; 
    Serial.println(tetai);
    a2 = S/a;
    if(a2 > Imax){
      a2 = Imax;
    }
    Serial.println(a2);
    Serial.println(a);
    Serial.println("");

  }
  }
