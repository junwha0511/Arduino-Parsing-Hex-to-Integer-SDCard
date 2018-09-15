#include<SPI.h>
#include<SD.h>

File f;

void setup() {
  Serial.begin(115200);
  if(!SD.begin(4)){
    Serial.println("failfail");
    return;
  } 
  f = SD.open("1.txt",FILE_READ);
}

void loop() {
  Serial.println((uint8_t)parsingData());
}

int parsingData(){
  int num = 0;
  char c;
  //(c=f.read())!=',' and c!='\n'
  while(true){
    c=f.read();
    if(c=='x'){
      int num;
      int first = f.read();
      int second = f.read();
      if(second!=44){
        num+=hexToDec(first)*16+hexToDec(second);   
      }else{
        num+=hexToDec(first);
      }
      return num;
    }
  }
}
int hexToDec(char a){
  char arr[16] = {48,49,50,51,52,53,54,55,56,57,97,98,99,100,101,102}; //0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f
  for(int i=0;i<16;i++){
    if(a==arr[i]){
      return i;
    }
  }
  return -1;
}
