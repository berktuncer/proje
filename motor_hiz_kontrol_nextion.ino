int dokun=0;
int page;
int k=0;
void setup() {
Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {
dokun=Serial.read();
  if(page==0)
  {
    page = Serial.read(); // Serial Porttan değer okuma
    Serial.println("page: ");
    Serial.println(page,HEX);
     if(k<0)
      k=0;
    delay(100);
    if(page==0x02) // Led açma buton idsi
    {
      k=100;
      analogWrite(3,k);
      delay(50);
      Serial.println("Butona basildi motor calismaya basliyor");
      Serial.println("k=");
      Serial.println(k);
    }
    if(page==0x01)// led kapatma buton idsi
    {
      k=0;
      analogWrite(3,k);
      delay(50);
      Serial.println("Butona basildi motor duruyor");
      Serial.println("k=");
      Serial.println(k);
    }
    if(page==0x05) // Led açma buton idsi
  {
       k=k+20;
       if(k<0)
      k=0;
      analogWrite(3,k);
      delay(50);
      Serial.println("Butona basildi motor hizi arttiriliyor");
      Serial.println("k=");
      Serial.println(k);
    }
     if(page==0x06) // Led açma buton idsi
  {
      k=k-20;
      if(k<0)
      k=0;
      analogWrite(3,k);
      delay(50);
      Serial.println("Butona basildi motor hizi azaltiliyor");
      Serial.println("k=");
      Serial.println(k);
    }
    
  }
  else if(dokun==0x65) // ilk önce dokundu bilgisi alınıyor daha sonra komponent idsinise göre işlemler yapılıyor
    
  {
  Serial.println("Dokunuldu.");
  page=0;
  delay(100);
}
else if(page==0xFFFFFFFF)
{
  Serial.println("Ekrana Dokunulmuyor");
  delay(100);
  }

}

