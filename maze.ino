
/*void LHR()
{
  int i,flag, a;
  unsigned long current_time,end_time;
  int check_delay = 100;
  int stop_delay = 2000;

  for(i = 1000; i <= 1500; i++)
  {
    EEPROM.write(i, 255);
  }

  delay(1000);
  read_line();
  while(node > 0)
  {
    RUN(LHS,RHS);
    read_line();
  }
  
  lcd.clear();
  i=0;
  a = 1000;
  while(1)
  {
     read_line();
     bulb(0,0,0);

     //cross or T or finish node
     if(node == 0b11 )
     {
       bulb(1,0,0);
       RUN(LHS,RHS);
       delay(check_delay);
       
       robot_stop();
       delay(stop_delay);
       read_line();

       if(node == 0b11)// finish
       {
         maze[i] = 0;
         lcd.setCursor(i%15 , i / 15);
         lcd.print(maze[i]);
         i++;
         EEPROM.write(a, 0);
         a++;
         break;
       }

       else // cross or T
       {
         maze[i] = 1; //left
         lcd.setCursor(i%15 , i / 15);
         lcd.print(maze[i]);
         i++;
         EEPROM.write(a, 1);
         a++;
         
         robot_left_90();
         robot_stop();
         delay(stop_delay);
       }
     }

     // left or T or cross or finish
     else if(node == 0b10)
     {
         current_time = millis();
         end_time = current_time + check_delay;

          flag = 0;
          while (current_time < end_time)
          {
            RUN(LHS,RHS);
            current_time = millis();

            read_line();
            if(node == 0b11 || node == 0b01) flag = 1;
          }

          robot_stop();
          delay(stop_delay);

          read_line();
          if(node == 0b11) // end
          {
              bulb(1,0,0);
               maze[i] = 0;
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 0);
                a++;
               break;
          }

          else if(flag == 1) // T or cross
          {
                bulb(1,0,0);
               maze[i] = 1; //left
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 1);
               a++;
               robot_left_90();
               robot_stop();
               delay(stop_delay);
          }

          else
          {
            if(pos == 0 || pos == 7000) //left 90
            {
              robot_left_90();
              delay(stop_delay);
            }

            else //junction
            {
               bulb(1,0,0);
                maze[i] = 1; //left
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 1);
                a++;
               robot_left_90();
               robot_stop();
               delay(stop_delay);
            }
          }
     }

     // right or T or cross or finish
     else if(node == 0b01)
     {
         current_time = millis();
         end_time = current_time + check_delay;

          flag = 0;
          while (current_time < end_time)
          {
            RUN(LHS,RHS);
            current_time = millis();

            read_line();
            if(node == 0b11 || node == 0b10) flag = 1;
          }

          robot_stop();
          delay(stop_delay);

          read_line();
          if(node == 0b11) // end
          {
               bulb(1,0,0);
               maze[i] = 0;
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 0);
               a++;
               break;
          }

          else if(flag == 1) // T or cross
          {
               bulb(1,0,0);
               maze[i] = 1; //left
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 1);
                 a++;
               robot_left_90();
               robot_stop();
               delay(stop_delay);
          }

          else
          {
            if(pos == 0 || pos == 7000) //right 90
            {
              robot_right_90();
              delay(stop_delay);
            }

            else //junction
            {
               bulb(1,0,0);
                maze[i] = 2; //straight
               lcd.setCursor(i%15 , i / 15);
               lcd.print(maze[i]);
               i++;
               EEPROM.write(a, 2);
               a++;
               delay_follow_line(50);
            }
          }
     }

     
     else if(pos == 0 || pos == 7000)
     {
      RUN(LHS,RHS);
      delay(stop_delay+10);
      robot_180();

       maze[i] = 4; //back
       lcd.setCursor(i%15 , i / 15);
       lcd.print(maze[i]);
       i++;
       EEPROM.write(a, 4);
       a++;

       delay(stop_delay);
     }

     

     else follow_the_damn_line();

  }
 
  while(1)
  {
    RUN(0,0);
    bulb(1,0,0);
    delay(100);
    
    bulb(0,1,0);
    delay(100);
    
    bulb(0,0,1);
    delay(100);
  }
}*/
