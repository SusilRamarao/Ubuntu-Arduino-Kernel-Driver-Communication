i`nt a=7; //definition digital 7  pins as pin to control 'a' section(segment)`
`int b=6; //definition digital 6  pins as pin to control 'b' section(segment)`
`int c=4; //definition digital 4  pins as pin to control 'c' section(segment)`
`int d=11;//definition digital 11 pins as pin to control 'd' section(segment)`
`int e=10;//definition digital 10 pins as pin to control 'e' section(segment)`
`int f=8; //definition digital 8  pins as pin to control 'f' section(segment)`
`int g=9; //definition digital 9  pins as pin to control 'g' section(segment)`
`int dp=5;//definition digital 5  pins as pin to control 'dp' section(segment)`
`void digital_0(void) //Segment display digital 0`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,HIGH);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g, LOW);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_1(void) //Segment display digital 1`
`{`
  `digitalWrite(a,LOW);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,LOW);`
  `digitalWrite(e,LOW);`
  `digitalWrite(f,LOW);`
  `digitalWrite(g,LOW);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_2(void) //Segment display digital 2`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,LOW);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,HIGH);`
  `digitalWrite(f,LOW);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_3(void) //Segment display digital 3`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,LOW);`
  `digitalWrite(f,LOW);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_4(void) //Segment display digital 4`
`{`
  `digitalWrite(a,LOW);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,LOW);`
  `digitalWrite(e,LOW);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_5(void) //Segment display digital 5`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,LOW);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,LOW);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_6(void) //Segment display digital 6`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,LOW);`  
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,HIGH);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_7(void) //Segment display digital 7`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`  
  `digitalWrite(c,HIGH);`  
  `digitalWrite(d,LOW);` 
  `digitalWrite(e,LOW);`
  `digitalWrite(f,LOW);`
  `digitalWrite(g,LOW);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_8(void) //Segment display digital 8`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,HIGH);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void digital_9(void) //Segment display digital 9`
`{`
  `digitalWrite(a,HIGH);`
  `digitalWrite(b,HIGH);`
  `digitalWrite(c,HIGH);`
  `digitalWrite(d,HIGH);`
  `digitalWrite(e,LOW);`
  `digitalWrite(f,HIGH);`
  `digitalWrite(g,HIGH);`
  `digitalWrite(dp,LOW);`
`}`
`void setup()`
`{`
  `int i;             //Define variables`
  
  `Serial.begin(9600);  // Start serial communication at 9600 baud rate`

  `for(i=4;i<=11;i++)`
  `pinMode(i,OUTPUT); //Set up 4 ~ 11 pins to output mode`
`}`
`void loop()`
`{`
  `if (Serial.available()) {         // Check if there is serial data available`
    `char command = Serial.read();   // Read the command`
    `switch (command) {`
      `case '0':`
        `digital_0(); //Segment display digital 0`
        `break;`
      `case '1':`
        `digital_1(); //Segment display digital 0`
        `break;`
      `case '2':`
        `digital_2(); //Segment display digital 0`
        `break;`
      `case '3':`
        `digital_3(); //Segment display digital 0`
        `break;`
      `case '4':`
        `digital_4(); //Segment display digital 0`
        `break;`
      `case '5':`
        `digital_5(); //Segment display digital 0`
        `break;`
      `case '6':`
        `digital_6(); //Segment display digital 0`
        `break;`
      `case '7':`
        `digital_7(); //Segment display digital 0`
        `break;`
      `case '8':`
        `digital_8(); //Segment display digital 0`
        `break;`
      `case '9':`
        `digital_9(); //Segment display digital 0`
        `break;`
    `}`
  `}`

`}`