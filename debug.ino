/*

void motor_test()
{
  RUN(250, 250);
  delay(1000);
  RUN(-250, -250);
  delay(1000);
  
}

void debug_readline()
{
  while(1)
  {
    Serial.println("raw values");
    for(int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(analogRead(sensor_pin[i]));
      Serial.print(" "); 
    }
    Serial.println();
    
     read_line();
    Serial.println("sensor values");
    for(int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(sensor_val[i]);
      Serial.print(" "); 
    }
    Serial.println();

    Serial.println("x values");
    for(int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(x[i]);
      Serial.print(" "); 
    }
    Serial.println();

    Serial.println("w values");
    for(int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(w[i]);
      Serial.print(" "); 
    }
    Serial.println();

    Serial.print("x_sum = ");
    Serial.println(x_sum);
    
    Serial.print("w_sum = ");
    Serial.println(w_sum);
    
    Serial.print("pos = ");
    Serial.println(pos);
    
    //delay(1000);
  }
}*/
