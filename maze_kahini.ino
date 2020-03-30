void left_hand()
{
  f();
  line_follow();

  if (a == 0b11110000 || a == 0b11100000 || a == 0b11111000)
  {
    delay(delay_before_turn);
    f();
    if (a != 0)
    {
      line_follow();
    }
    else
    {
      right_turn();
    }
  }

  if (a == 0b00001111 || a == 0b00000111 || a == 0b00011111)  ////////ulta bame
  {


    
    left_turn();
  }
  if(a==0)
  {
    delay(30);
    right_turn();
  }
}
