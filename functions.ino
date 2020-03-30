

/*
  void RUN(int lm, int rm) {

  if (lm > 0) {
    digitalWrite(lmf, HIGH);
    digitalWrite(lmb, LOW);
  }
  if (rm > 0) {
    digitalWrite(rmf, HIGH);
    digitalWrite(rmb, LOW);
  }
  if (lm < 0) {
    digitalWrite(lmf, LOW);
    digitalWrite(lmb, HIGH);
    lm = lm * -1;
  }
  if (rm < 0) {
    digitalWrite(rmf, LOW);
    digitalWrite(rmb, HIGH);
    rm = rm * -1;
  }

  analogWrite(lme, lm);
  analogWrite(rme, rm);
  }

  void cal()
  {
  RUN(200, -200);

  int i, val, a;

  for ( i = 0 ; i < NUM_SENSORS ; i++)
  {
    thres[i] = 0 ;
    thres_max[i] = 0;
    thres_min[i] = 1023;
  }

  unsigned long current_time = millis();
  unsigned long end_time = current_time + 4000;

  while (current_time < end_time)
  {
    // now update the current time
    current_time = millis();

    for ( i = 0; i < NUM_SENSORS; i++)
    {
      int val = analogRead(i);
      if ( thres_max[i] < val )
      {
        thres_max[i] = val;
      }

      if ( thres_min[i] > val )
      {
        thres_min[i] = val;
      }
    }
  }

  RUN(0, 0);

  for ( i = 0 ; i < NUM_SENSORS ; i++)
  {
    thres[i] = ( ( thres_max[i] + thres_min[i] )  /  2 ) / 5 ;
  }

  for ( a = 400, i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    EEPROM.write(a, thres_min[i]);
  }

  for ( a = 500, i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    EEPROM.write(a, thres[i]);
  }

  for ( a = 600, i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    EEPROM.write(a, thres_max[i]);
  }
  }

  void thres_read()
  {
  int i, a;
  for (a =  400 , i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    thres_min[i] = 5 *  EEPROM.read(a);
  }

  for (a =  500 , i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    thres[i] = 5 *  EEPROM.read(a);
  }

  for (a =  600 , i = 0 ; i < NUM_SENSORS ; i++, a++)
  {
    thres_max[i] = 5 *  EEPROM.read(a);
  }
  }


  void oled(int x, int y, int sz, String ln)
  {
  // display a line of text
  display.setTextSize(sz);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.print("ROBOSUST");

  display.setCursor(x, y);
  display.print(ln);

  // update display with all of the above graphics
  display.display();
  }

  void bulb(byte n1, byte n2 , byte n3)
  {
  if ( n1 == 1)
    digitalWrite(green, HIGH);
  else
    digitalWrite(green, LOW);

  if (n2 == 1)
    digitalWrite(yellow, HIGH);
  else
    digitalWrite(yellow, LOW);

  if (n3 == 1)
    digitalWrite(red, HIGH);
  else
    digitalWrite(red, LOW);

  }

  void robot_left_90()
  {
  RUN(-200, 200);
  delay(280);
  RUN(255, -255);
  delay(30);
  RUN(0, 0);
  }

  void robot_right_90()
  {
  RUN(200, -200);
  delay(280);
  RUN(-255, 255);
  delay(30);
  RUN(0, 0);
  }

  void robot_180()
  {
  RUN(200, -200);
  delay(480);
  RUN(-255, 255);
  delay(40);
  RUN(0, 0);
  }
  void robot_stop()
  {
  RUN(-255, -255);
  delay(30);
  RUN(0, 0);
  }

  void delay_follow_line(unsigned long n)
  {
  unsigned long current_time = millis();
  unsigned long end_time = current_time + n;

  while (current_time < end_time)
  {
    follow_the_damn_line();
    current_time = millis();
  }
  }

  ////////rupok's turn ///////////

  void right_turn()
  {
  delay(delay_before_turn);
  RUN(-255, -255);
  delay(50);
  RUN(0, 0);
  delay(50);
  RUN(150, -150);
  delay(180);
  while (1)
  {
    read_line();
    RUN(100, -100);
    bulb(0, 1, 1);
    if (LN == 0b00011000 || 0b00001100)
    {
      RUN(-255, 255);
      delay(50);
      robot_stop();
      delay(50);
      bulb(0, 0, 0);
      break;
    }

  }

  /*while(1)
    {
    RUN(100,-100);
    delay(50);
    if(LN==0b00011000 || 0b00001100)
    {
      RUN(-255,255);
      delay(50);
      robot_stop();
      delay(50);
      break;
    }

    }

  }

  /*void left_turn()
  {
  delay(delay_before_turn);
  RUN(-255, -255);
  delay(50);
  RUN(0, 0);
  delay(50);
  RUN(-150, 150);
  delay(180);
  while (1)
  {
    read_line();
    RUN(-100, 100);
    bulb(0, 1, 1);
    if (LN == 0b00011000 || 0b00110000)
    {
      RUN(255, -255);
      delay(50);
      robot_stop();
      delay(50);
      bulb(0, 0, 0);
      break;
    }

  }

  /*while(1)
    {
    RUN(100,-100);
    delay(50);
    if(LN==0b00011000 || 0b00001100)
    {
      RUN(-255,255);
      delay(50);
      robot_stop();
      delay(50);
      break;
    }

    }

  }*/


////////////

void auto_calibrate()
{


  mos(-250, 250);

  EEPROM.write(sn, (analogRead(sst) / 5));
  for (i = 0; i < sn; i++) {
    l[i] = analogRead(sst + i);
    r[i] = analogRead(sst + i);
  }
  for (j = 0; j < 1000; j++) {
    for (i = 0; i < sn; i++) {
      v[i] = analogRead(sst + i);
      if (v[i] < l[i]) l[i] = v[i];
      if (v[i] > r[i]) r[i] = v[i];
    }
    delay(1);
  }
  for (i = 0; i < sn; i++) {
    v[i] = (l[i] + r[i]) / 10;
    EEPROM.write(i, v[i]);
  }
  mos(0, 0);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);

  delay(5000);
}

void mos(int lm, int rm) {

  if (lm > 0) {
    digitalWrite(lmf, HIGH);
    digitalWrite(lmb, LOW);
  }
  if (rm > 0) {
    digitalWrite(rmf, HIGH);
    digitalWrite(rmb, LOW);
  }
  if (lm < 0) {
    digitalWrite(lmf, LOW);
    digitalWrite(lmb, HIGH);
    lm = lm * -1;
  }
  if (rm < 0) {
    digitalWrite(rmf, LOW);
    digitalWrite(rmb, HIGH);
    rm = rm * -1;
  }

  analogWrite(lme, lm);
  analogWrite(rme, rm);
}

void f()
{
  if (li == 0) for (i = 0; i < sn; i++) {
      if (analogRead(sst + i) > r[i])v[i] = 1;
      else v[i] = 0;
    }
  else for (i = 0; i < sn; i++) {
      if (analogRead(sst + i) < r[i])v[i] = 1;
      else v[i] = 0;
    }

  a = v[0] * 1 + v[1] * 2 + v[2] * 4 + v[3] * 8 + v[4] * 16 + v[5] * 32 + v[6] * 64 + v[7] * 128;
 // a=v[7]*1+v[6]*2+v[5]*4+v[4]*8+v[3]*16+v[2]*32+v[1]*64+v[0]*128;
  Serial.println(a);
  //lcd.print(a);
}

void right_turn()
{
  delay(delay_before_turn);
  mos(-255, -255);
  delay(70);
  mos(0, 0);
  delay(50);
  mos(150, -150);
  delay(180);
  while (1)
  {
    f();
    mos(100, -100);
    bulb(0, 1, 1);
    if (a == 0b00011000 || a==0b00001100)
    {
      mos(-255, 255);
      delay(50);
      mos(0,0);
      delay(50);
      bulb(0, 0, 0);
      break;
    }

  }

  /*while(1)
    {
    RUN(100,-100);
    delay(50);
    if(LN==0b00011000 || 0b00001100)
    {
      RUN(-255,255);
      delay(50);
      robot_stop();
      delay(50);
      break;
    }

    }*/

}

void left_turn()
{
  delay(delay_before_turn);
  
  mos(-255, -255);
  delay(70);
  mos(0, 0);
  delay(50);
  mos(-150, 150);
  delay(180);
  while (1)
  {
    f();
    mos(-100, 100);
    bulb(0, 1, 1);
    if (a == 0b00011000 || a== 0b00110000)
    {
      mos(255, -255);
      delay(50);
     mos(0,0);
      delay(50);
      bulb(0, 0, 0);
      break;
    }

  }

  /*while(1)
    {
    RUN(100,-100);
    delay(50);
    if(LN==0b00011000 || 0b00001100)
    {
      RUN(-255,255);
      delay(50);
      robot_stop();
      delay(50);
      break;
    }

    }*/

}

/*void lm(){
  digitalWrite(yellow, HIGH);

  mos( -10*sp, -10*sp);delay(50);

  mos( -10*sp, 10*sp);
  digitalWrite(yellow, LOW);
  delay(60);
  mos( -5*sp, 5*sp);
  for(i=0;i<=80;i++){
  f();
  if (a==24 ||a==16||a==48||a==32) {
  mos( 10*sp, -10*sp);
  delay(50);
  if(m3<300) delay(50);
  mos( 10*sp, 10*sp);
     break;}
     delay(5);}}

  void rm(){

  digitalWrite(red, HIGH);

  mos( -10*sp, -10*sp);delay(50);


  mos( 10*sp, -10*sp);
  digitalWrite(red, LOW);
  delay(60);
  mos( 5*sp, -5*sp);
  for(i=0;i<=80;i++){
  f();
  if (a==24 ||a==16||a==48||a==32) {
  mos( -10*sp, 10*sp);
  delay(50);
  if(m3<300) delay(50);
  mos( 10*sp, 10*sp);
     break;}
     delay(5);}}*/

void bulb(byte n1, byte n2 , byte n3)
{
  if ( n1 == 1)
    digitalWrite(green, HIGH);
  else
    digitalWrite(green, LOW);

  if (n2 == 1)
    digitalWrite(yellow, HIGH);
  else
    digitalWrite(yellow, LOW);

  if (n3 == 1)
    digitalWrite(red, HIGH);
  else
    digitalWrite(red, LOW);

}
