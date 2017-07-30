
String voice  ;
int 
led1 = 2, //Konek LED 1 Ke Pin #2 
led2 = 3, //Konek LED 1 Ke Pin #3 
led3 = 4, //Konek LED 1 Ke Pin #4  
led4 = 5, //Konek LED 1 Ke Pin #5 
led5 = 6, //Konek LED 1 Ke Pin #6 
led6 = 7, //Konek LED 1 Ke Pin #7 
led7 = 8; //Konek LED 1 Ke Pin #8 


void semuanyala(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH);
     digitalWrite(led5, LOW);
     digitalWrite(led6, LOW);
      
      
}
void semuamati(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
     digitalWrite(led5, LOW);
}

void setup() {
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT); 
  pinMode(led6, OUTPUT); 
  pinMode(led7, OUTPUT); 
char *txt = "nyalakan lampu";
char *pat = ("lampu") ;
KMPSearch(pat, txt);

 
}
  void KMPSearch(char *pat, char *txt)
{
   Serial.begin(9600);
  int M = strlen(pat);
  int N = strlen(txt);

  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  int lps[M];

  // Preprocess the pattern (calculate lps[] array)
  computeLPSArray(pat, M, lps);

  int i = 0; // index for txt[]
  int j = 0; // index for pat[]
  while (i < N)
  {
    if (pat[j] == txt[i])
    {
      j++;
      i++;
    }

    if (j == M)
    {
      int x = i- j;
     Serial.println("Found pattern at index %d n");Serial.println(x);
 if (x == 0)
    {
    semuanyala();
    }else if(x == 6){semuamati();}
      j = lps[j-1];
    }

    // mismatch after j matches
    else if (i < N && pat[j] != txt[i])
    {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j-1];
      else
        i = i+1;
    }
  }
}

void computeLPSArray(char *pat, int M, int *lps)
{
  // length of the previous longest prefix suffix
  int len = 0;

  lps[0] = 0; // lps[0] is always 0

  // the loop calculates lps[i] for i = 1 to M-1
  int i = 1;
  while (i < M)
  {
    if (pat[i] == pat[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else // (pat[i] != pat[len])
    {
      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar 
      // to search step.
      if (len != 0)
      {
        len = lps[len-1];

        // Also, note that we do not increment
        // i here
      }
      else // if (len == 0)
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}



void loop() {

 while (Serial.available()){  ///men cek ketersediaan byte untuk dibaca
    char c = Serial.read(); //perhitungan serial read
    voice += c; //Shorthand untuk voice = voice + c
    delay(10); //Delay untuk stable 
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
    //-----------------------------------------------------------------------//    
    //----------mengontrol banyak lampu/ LEDs----------//  
    if(voice == "lampu nyala") {semuanyala();}  //nyalakan semua pin (memanggil funsi semuanyala)
    else if(voice == "lampu mati"){semuamati();} //matikan semua pin (memanggil funsi semuamati)
  
    //----------menyalakan lampu satu-satu----------//
     else if(voice == "nyalakan lampu tamu") {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      }
    else if(voice == "nyalakan lampu tamu 1") {digitalWrite(led1, HIGH);} 
    else if(voice == "nyalakan lampu tamu 2") {digitalWrite(led2, HIGH);}
    else if(voice == "nyalakan lampu tidur") {
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      
      }
    else if(voice == "nyalakan lampu tidur satu") {
      digitalWrite(led5, LOW);
      digitalWrite(led3, HIGH);
    }
    else if(voice == "nyalakan lampu tidur 2") {
      digitalWrite(led4, HIGH);
      digitalWrite(led6, LOW);
 
    }
    else if(voice == "redupkan lampu tidur") {
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
    }
    else if(voice == "redupkan lampu tidur satu") 
    {
      digitalWrite(led5, HIGH);
      digitalWrite(led3, LOW);
    }
    else if(voice == "redupkan lampu tidur 2") 
    {
      digitalWrite(led6, HIGH);
      digitalWrite(led4, LOW);
    }
    //----------mematikan lampu satu-satu----------// 
    else if(voice == "matikan lampu tamu") {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      }
    
    else if(voice == "matikan lampu tamu 1") {digitalWrite(led1, LOW);} 
    else if(voice == "matikan lampu tamu 2") {digitalWrite(led2, LOW);}
    else if(voice == "matikan lampu tidur") {
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      }
    else if(voice == "matikan lampu tidur satu") 
    {
      digitalWrite(led3, LOW);
      digitalWrite(led5, LOW);
    }
    else if(voice == "matikan lampu tidur 2") 
    {
      digitalWrite(led4, LOW);
      digitalWrite(led6, LOW);
    }

//-----------------------------------------------------------------------//   
  voice="";//Reset variabel setelah inisiasi
  }
} 




