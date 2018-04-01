int R1 = 2;
int R2 = 3;

String cmd = "";
char data = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  digitalWrite(R1, 1);
  digitalWrite(R2, 1);
}

void loop()
{
  if(Serial.available() > 0){
    while(Serial.available() > 0)
    {
      char tmp = Serial.read();
      if(tmp == '#'){
        Serial.println(cmd);
        switchSocket(cmd);
        cmd = "";
      }else
        cmd += tmp;
    }   
  }
}

void switchSocket(String cmd){
  if(cmd == "1HIGH")
    digitalWrite(R1, 0);
  
  if(cmd == "1LOW")
    digitalWrite(R1, 1);

  if(cmd == "2HIGH")
    digitalWrite(R2, 0);

  if(cmd == "2LOW")
    digitalWrite(R2, 1);
}

