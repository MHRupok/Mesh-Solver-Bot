
  void line_follow() {
    
    if (a == 24) {
      if (k < 0) {
        mos(-8 * sp , 8 * sp);
        delay(dt);
      }
      if (k > 0) {
        mos(8 * sp , -8 * sp);
        delay(dt);
      }
      k = 0;
      mos(10 * sp , 10 * sp);
    }
/////////////////////////////////

    if (a == 16) {
      mos(10 * sp , 9 * sp);
    }

    if (a == 48) {
      if (k > -2) {
        mos(8 * sp , -8 * sp);
        delay(dt);
      }
      k = -2;
      mos(10 * sp , 8 * sp);
    }

    if (a == 32) {
      if (k > -3) {
        mos(8 * sp, -8 * sp);
        delay(dt);
      }
      k = -3;
      mos(10 * sp, 7 * sp);
    }

    if (a == 96) {
      if (k > -4) {
        mos(8 * sp, -8 * sp);
        delay(dt);
      }
      k = -4;
      mos(10 * sp, 6 * sp);
    }

    if (a == 64 || a == 224) {
      if (k > -5) {
        mos(8 * sp, -8 * sp);
        delay(dt);
      }
      k = -5;
      mos(10 * sp, 4 * sp);
    }

    if (a == 192) {
      if (k > -6) {
        mos(8 * sp, -8 * sp);
        delay(dt);
      }
      k = -6;
      mos(6 * sp, -6 * sp);
    }

    if (a == 128) {
      if (k > -7) {
        mos(-8 * sp, -8 * sp);
        delay(dt);
      }
      k = -7;
      mos(8 * sp, -8 * sp);
    }

////////////////////////////////////////////////////////

    if (a == 8) {
      mos(9 * sp, 10 * sp);
    }

    if (a == 12) {
      if (k < 2) {
        mos(-8 * sp, 8 * sp);
        delay(dt);
      }
      k = 2;
      mos(8 * sp, 10 * sp);
    }

    if (a == 4) {
      if (k < 3) {
        mos(-8 * sp, 8 * sp);
        delay(dt);
      }
      k = 3;
      mos(7 * sp, 10 * sp);
    }
    if (a == 6) {
      if (k < 4) {
        mos(-8 * sp, 8 * sp);
        delay(dt);
      }
      k = 4;
      mos(6 * sp, 10 * sp);
    }

    if (a == 2 || a == 7) {
      if (k < 5) {
        mos(-8 * sp, 8 * sp);
        delay(dt);
      }
      k = 5;
      mos(4 * sp, 10 * sp);
    }

    if (a == 3) {
      if (k < 6) {
        mos(-8 * sp, 8 * sp);
        delay(dt);
      }
      k = 6;
      mos(-6 * sp, 6 * sp);
    }

    if (a == 1) {
      if (k < 7) {
        mos(-8 * sp, -8 * sp);
        delay(dt);
      }
      k = 7;
      mos(-8 * sp, 8 * sp);
    }




///////////////////////////////turn///////////
/*  if (a == 0b11110000 || a == 0b11100000 || a == 0b11111000)  ////////ulta dane
  {
    

    
    right_turn();
  }

    if (a == 0b00001111 || a == 0b00000111 || a == 0b00011111)  ////////ulta bame
  {
    

    
    left_turn();
  }*/

  }
