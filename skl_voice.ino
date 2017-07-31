
String voice;
int 
led1 = 2, //Konek LED 1 Ke Pin #2 
led2 = 3, //Konek LED 1 Ke Pin #3 
led3 = 4, //Konek LED 1 Ke Pin #4  
led4 = 5, //Konek LED 1 Ke Pin #5 
led5 = 6, //Konek LED 1 Ke Pin #6 
led6 = 7, //Konek LED 1 Ke Pin #7 
led7 = 8; //Konek LED 1 Ke Pin #8 
//--------------------------Call A Function-------------------------------//  
void semuanyala(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);
      
      
}
int find_text(String needle, String haystack) {
  int foundpos = -1;
  for (int i = 0; i <= haystack.length() - needle.length(); i++) {
    if (haystack.substring(i,needle.length()+i) == needle) {
      foundpos = i;
    }
  }
  return foundpos;
}
void semuamati(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);
}
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
  pinMode(led6, OUTPUT); 
  pinMode(led7, OUTPUT); 
}
//-----------------------------------------------------------------------//  
void loop() {
  while (Serial.available()){  ///men cek ketersediaan byte untuk dibaca
    char c = Serial.read(); //perhitungan serial read
    voice += c; //Shorthand untuk voice = voice + c
    delay(10); //Delay untuk stable 
  }  
  
  
  if (voice.length() > 0) {
    voice = voice+" keren";
    int senyap = find_text("senyap",voice);
    int redup = find_text("redup",voice);
    int satuangka = find_text("1",voice);
    int duaangka = find_text("2",voice);
    int mati2 = find_text("Mati", voice);
    int mati = find_text("mati", voice);
    int padam = find_text("padam", voice);
    int nyala = find_text("nyala", voice);
    int nyala2 = find_text("Nyala", voice);
    int hidup= find_text("hidup", voice);
    int tamu = find_text("tamu", voice);
    int tidur = find_text("tidur", voice);
    int dua = find_text("dua", voice);
    int satu = find_text("satu", voice);
    int on = find_text("on",voice);
    int off = find_text("off",voice);
    int of = find_text("of",voice);

   
     if(nyala != -1 or on != -1 or nyala2 != -1 or hidup !=-1){
      if(tamu != -1){
        if(satu != -1 or satuangka != -1){
          Serial.println("lampu tamu 1 nyala");
          digitalWrite(led1, HIGH);
        }else if(dua != -1 or duaangka != -1){
          Serial.println("lampu tamu 2 nyala");
          digitalWrite(led2, HIGH);
        }else{
          Serial.println("lampu tamu nyala");
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
        }
      }else if(tidur != -1){
        if(satu != -1 or satuangka != -1){
          Serial.println("lampu tidur 1 nyala");
          digitalWrite(led5, LOW);
          digitalWrite(led3, HIGH);
        }else if(dua != -1 or duaangka != -1){
          Serial.println("lampu tidur 2 nyala");
          digitalWrite(led4, HIGH);
          digitalWrite(led6, LOW);
        }else{
          Serial.println("lampu tidur nyala");
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
        }
      }else{
        Serial.println("semua lampu nyala"); 
        semuanyala(); 
      }
    }
    else if(mati != -1 or mati2 != -1 or of != -1 or padam != -1 or off != -1){
      if(tamu != -1){
        if(satu != -1 or satuangka != -1){
          Serial.println("lampu tamu 1 mati");
          digitalWrite(led1, LOW);
        }else if(dua != -1 or duaangka != -1){
          Serial.println("lampu tamu 2 mati");
          digitalWrite(led2, LOW);
        }else{
          Serial.println("lampu tamu mati");
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
        }
      }else if(tidur != -1){
        if(satu != -1 or satuangka != -1){
          Serial.println("lampu tidur 1 mati");
          digitalWrite(led3, LOW);
          digitalWrite(led5, LOW);
        }else if(dua != -1 or duaangka != -1){
          Serial.println("lampu tidur 2 mati");
          digitalWrite(led4, LOW);
          digitalWrite(led6, LOW);
        }else{
          Serial.println("lampu tidur mati");
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
        }
      }else{
        Serial.println("semua lampu mati");
        semuamati();  
      }
    }
    else if(redup != -1 or senyap !=-1){
        if(satu != -1 or satuangka != -1){
          Serial.println("lampu tidur 1 redup");
          digitalWrite(led5, HIGH);
          digitalWrite(led3, LOW);
        }else if(dua != -1 or duaangka != -1){
          Serial.println("lampu tidur 2 redup");
          digitalWrite(led6, HIGH);
          digitalWrite(led4, LOW);
        }else{
          Serial.println("lampu tidur redup");
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
        }
    }
  voice="";//Reset variabel setelah inisiasi
  }
} 

