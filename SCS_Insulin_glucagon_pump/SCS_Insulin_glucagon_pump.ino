double G0=120;
double C =500;
double G1,G2,G,Gc;
double Iac = 1; // level 4
double Itre;
double Ire;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
}

void loop() {
  
  
  // put your main code here, to run repeatedly:
   G1 = G0-(0.005*G0);//
   Serial.print("G0=");
  Serial.println(G0);
  G0 = G1;
  G = G1;
   Serial.print("G1=");
  Serial.println(G1);
  Serial.print("G=");
  Serial.println(G);
 
  Gc = (0.16)*C;//(8/50)
  
  Serial.print("carbs intorduced=");
  Serial.println(C);
  Serial.print("carbs converted to glucose Gc=");
  Serial.println(Gc);
  delay(2000);
 /* if (digitalRead(2) == HIGH)
  {
    C = 60;
     Serial.print("C=");
      Serial.println(C);
  }
   if (analogRead(A1)== HIGH)
  {
    C = 500;
     Serial.print("C=");
      Serial.println(C);
  }
   if (analogRead(A2) == HIGH)
  {
    C = 300;
     Serial.print("C=");
      Serial.println(C);
  }*/
  
   if (C != 0) {
    
         Serial.println("some carbs intorduced ( food was taken)");
         G2 = G1-(0.0051*G1)+(0.0073*G1)+Gc;
         Serial.print("G2=");
         Serial.println(G2);
         G1 = G2;
       
         Serial.print("G1=");
         Serial.println(G1);
         G0 = G2;
         Serial.print("G0=");
         Serial.println(G0);
         G = G2;
         Serial.print("G");
         Serial.println(G);
         delay(2000);
         }
         if (G>=180)
         {
          Serial.println("Emergency");
         }
          if (C != 0)
          {
            Itre = (G*0.02);// Itre = (G/50);
            Ire = Itre-Iac; 
                 Serial.println("insulin required=");  Serial.print(Ire);
          }
          
          
           
            G2 = G1-(0.0051*G1)+(0.0073*G1)+Gc-((Ire*0.1)*Gc);
       
            G1 = G2;
            G = G2;
            Serial.print(G2);
            delay(1000);
            
           if (80>G<120 && (G <= 100 && G >= 80 ))
             {
             for (int i = 0; i<=20; i++) //  bulian shot body can give 20 bulian shots
             {
          
             Serial.println(" bolus shots are given ");
             G1 = G0-(0.005*G0)+1;
             Serial.println(G1);
             G0=G1;
             delay(1000);
             }
             G0=G1;
             Serial.print("G0");
             Serial.println(G0);
             G=G1;
             Serial.print("G");
             Serial.println(G);
             }
             
             
        // read carbs value here then check c value //  
     C = 0;
//----------------------no food inrorduced-----clubing units---------//
      if (C == 0) {
    
         Serial.println("no of carbs intorduced is 0 (no food was taken)");
         G1 = G0-(0.005*G0);
         Serial.print("G1");
         Serial.println(G1);
         G0 = G1;
         Serial.print("G0");
         Serial.println(G0);
         G = G1;
         Serial.print("G");
         Serial.println(G);
         if (80>G<120 && (G <= 100 && G >= 80 ))
             {
             for (int i = 0; i<=20; i++) //  bulian shot body can give 20 bulian shots
             {
          
             Serial.println("no of carbs intorduced is 0 and glucose is between 80 to 100 and lessthan 100 ");
             G1 = G0-(0.005*G0)+1;
             Serial.println(G1);
             G0=G1;
             delay(1000);
             }
             G0=G1;
             Serial.print("G0");
             Serial.println(G0);
             G=G1;
             Serial.print("G");
             Serial.println(G);
             
            

                for (int i = 0; i<=60; i++)
                     {
                     Serial.println("body don't have energy to give bulian shots then energy will decrease graduvally ");
                     G1 = G0-(0.005*G0);// after 20 bulian shots glucose will decrease
                     Serial.print("G0=");
                     Serial.println(G0);
                     G0 = G1;
                     G = G1;
                     Serial.print("G1=");
                     Serial.println(G1);
                     Serial.print("G=");
                     Serial.println(G);
                     delay(1000);
                     }
             }
           
             
             
                     
            else if (G<70)
                 {
                 Serial.println("Alarm low blood sugar level");// GLUCOGON INJECT PROGRAM
                 }
                  delay(2000);
         }
          
                  delay(2000);
   }
   
    
   
        
