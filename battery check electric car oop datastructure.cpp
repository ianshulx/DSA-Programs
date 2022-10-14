//Mohid Aamir 663-FET/BSEE/F19 personal code

#include <iostream>
#include <unistd.h>
using namespace std;

class Electric_Car                      // First based Class
{
protected:
    int Battery_Level;                  // Attribute

public:
    Electric_Car() : Battery_Level(0)               // No Arg Constructor
    {
        
    }
    Electric_Car(int charge) : Battery_Level(charge)        // One Arg Constructor
    {
        
    }
    void Recharge()
    {
    	 if(Battery_Level<=0)             //condition if battery is less than zero so exit
        {
            cout << "Battery is empty plz recharge" << endl; 
			exit (0);        
        }
        
        else if (Battery_Level < 100 && Battery_Level >= 0)   // If Battery level is b/w limit 
        {
            Battery_Level += 1;                      //increment battery level
        }
        
        else      //if greater than 100 
        {
            cout << "battery is Full" << endl;
        }
        
        
    }
    void Show_Bat()  //display battery level
    {
        cout << "Current Battery Level is: " << Battery_Level << endl;          // Displaying Battery Level
    }

};

class Petrol_Car        // Second based Class
{
protected:
    double Fuel_Level;      // Attribute

public:
    Petrol_Car() : Fuel_Level(0)           // No arg Constructor
    {
        
    }
    Petrol_Car(double petrol): Fuel_Level(petrol)                // one Arg Constructor
    {
        
    }
    void Fill_Up()
    {
    	if(Fuel_Level<=0)   //if fuel level is less than zero exit
        {
            cout << "fuel tank is empty plz refill" << endl; 
			exit (0);        
        }
        
       else  if (Fuel_Level < 50 && Fuel_Level >= 0)  //If Fuel_Level is b/w limit 
        {
            Fuel_Level += 0.5;   //increment fuel
        }
        
        else                         // if fuel level is greater than 50
        {
            cout << "Tank is Full" << endl;
        }
    }
    void Show_Fuel()
    {
        cout << "The Fuel is " << Fuel_Level << " Liters" << endl;          // Displaying Fuel Level
    }

};
class HybridCar: public Electric_Car, public Petrol_Car                     // multiple inheriting derived class from base classes
{
private:
    char Running_Mode;          // Attribute
public:
    HybridCar() : Electric_Car(), Petrol_Car()
    {
        // No arg Dervied Constructor
    }
    
    HybridCar(int charge, double petrol) : Electric_Car(charge), Petrol_Car(petrol)
    {
        // 2 arg child constructor
    }
    void Switch_Mode(char mod)      //switch mode to switch b/w battery and fuel
    {if (mod=='b'){
	
         Running_Mode = 'b'; 
     }
       {if (mod=='f'){
	
         Running_Mode = 'f'; 
     }
    }}
    void Run()        // decreasing values as car consumes battery and fuel while running
    {
        if (Running_Mode == 'b'){
		
         if(Battery_Level<=0||Battery_Level>100){
        	
		}
          else{
		  
			
                Battery_Level -= 1;}
            }
        if (Running_Mode == 'f')
            {if(Fuel_Level<=0||Fuel_Level>50){
        	
		}
		else	
			{
			
                Fuel_Level -= 0.5;}
  }
  }
};


int main()
{
int a=5,b=3;
while(0<1){         //infinte loop
	a--,b-=0.5;  //decrementing values so fuel or battery goes down
	
sleep(1); //delay program for better understanding
    HybridCar h(a, b);        // Intializing Object with 2 Arg constructor 
cout<<"____________________"<<endl;
    h.Show_Bat();
    h.Show_Fuel();
    cout<<"____________________"<<endl;
   cout<<"*********Battery mode ******** "<<endl;        //battery mode
    h.Switch_Mode('b');
    h.Run();                   
    sleep(2);
	h.Show_Bat();
    h.Run();                   
    sleep(2);
	h.Show_Bat();
    
    sleep(2);
    cout<<"*********Recharging********"<<endl; // recharging battery
    h.Recharge();
    
    h.Show_Bat();
    
    // Changing Mode
    sleep(1);
    h.Switch_Mode('f');        //fuel mode
    cout<<"*******Car is on fuel mode*******"<<endl;
    h.Run();                   
    sleep(2);
    h.Show_Fuel();
     h.Run();                    
    sleep(2);
    h.Show_Fuel();
    cout<<"*********Refueling*********"<<endl;         //refueling
    h.Fill_Up();
    
    h.Show_Fuel();
}
    return 0;
}
