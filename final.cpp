#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
void reg();
void menu();
void book(long int a[]);
void pay();
long int a[10];
// Latitude of customer who needs a cab.
long double lat1d;
 string uName, pass, name, email, gender;
    string logname, logpass;
    string valname, valpass;
    int phone;
    float pa;
// Longitude of customer who needs a cab.
long double lon1d;
void disp(long int, string, double );
  
#define pi 3.14159265358979323846
#define earth_radius 6371.0
  
ifstream customer_list ("customers.json");
ofstream out ("answer.json");
  
// Function to convert degree to radian.
double degtorad(double deg)
{
    return ( deg * pi / 180);
}
  
// Function to calculate distance
// between 2 given locations 
// using Great Circle Distance Formula.
double distanceEarth(double lat2d, double lon2d)
{                 
    double lat1, lon1, lat2, lon2, 
           delta_lon, central_ang;
  
    lat1 = degtorad(lat1d);
    lon1 = degtorad(lon1d);
    lat2 = degtorad(lat2d);
    lon2 = degtorad(lon2d);
  
    delta_lon = lon2 - lon1;
      
    // great circle distance formula.
    central_ang = acos ( sin(lat1) *
                  sin(lat2) + cos(lat1) *
                  cos(lat2) * cos(delta_lon) ); 
                  
                  
                    
    return (earth_radius * central_ang);
}
  
// Structure which contains data and
// functions for accessing and processing
// data from the given customers.json file.
struct json
{
    
    long long int length, i, j, x, y, m,
                  n, f, fi, id[100000];
      
    char latitude_as_string[1000], 
         longitude_as_string[1000], 
         id_as_string[1000], name[1000];
      
    double lat2d, lon2d;
      
    // To get each line of customers.json
    // file as string.
    string line;
  
    // Function to check whether distance between
    // 2 points is less than 50km or not.
    void distance_calculator()
    {
        if (distanceEarth(lat2d, lon2d) <= 50.0000)
        {double y;
		y=distanceEarth(lat2d,lon2d);
            // Converting id to int format.
            id[i] = atoll(id_as_string);
            a[i]=id[i];
            i++;
            out << "{\"user_id\": " << id[i - 1] << 
                ", \"name\": " << name << "}" << endl;
            
            cout<<id[i-1]<<name;    
            disp(id[i-1],name, y);
            
        }
        

    }
  
    // Function to read various attributes
    // like latitude, longitude, name , id,
    // etc, from customers.json file. simplistic
    // approach is used to get JSON attributes.
    void json_parser()
    {                     
        if (customer_list.is_open())
        {
              
            while (getline(customer_list, line))
            {
                  
                f = 0; x = 0; y = 0; fi = 0; m = 0, n = 0;
                length = line.size();
  
                for (j = 0; j < length; j++)
                {
                      
                    if (line[j] == '"')
                        f++;
  
                    else if (line[j] == ':')
                        fi++;
                          
                    // To get latitude of the location.    
                    if (f == 3)
                    {
                        j++;
  
                        while (line[j] != '"')
                        {
                            latitude_as_string[x] = line[j];
                            x++; j++;
                        }
  
                        j--; latitude_as_string[x] = '\0';
                    }
                      
                    // To get longitude of the location.
                    else if (f == 13)
                    {
                        j++;
  
                        while (line[j] != '"')
                        {
                            longitude_as_string[y] = line[j];
                            y++; j++;
                        }
  
                        j--; longitude_as_string[y] = '\0';
                    }
                      
                    // To get id of the friend.
                    if (fi == 2)
                    {
                        j += 2;
  
                        while (line[j] != ',')
                        {
                            id_as_string[m] = line[j];
                            m++; j++;
                        }
  
                        j--; id_as_string[m] = '\0';
                        fi++;
                    }
                      
                    // To get name of the friend.
                    else if (fi == 4)
                    {
                        j += 2;
  
                        while (line[j] != ',')
                        {
                            name[n] = line[j];
                            n++; j++;
                        }
  
                        j--; name[n] = '\0';
                        fi++; f += 2;
                    }
                }
  
                // Converting latitude and longitude
                // in string to float.
                lat2d = atof(latitude_as_string);
                lon2d = atof(longitude_as_string);
                distance_calculator();
            }
        }
          
        // closing stream of customer's file.
        customer_list.close();
           
        // closing stream of answer's file.
        out.close();
    }
};
void disp(long int x, string name,double y){
	cout<<endl;
	cout<<"__________________"<<endl;
	cout<<"CAB DRIVER ID: "<<x<<endl;
	cout<<"CAB DRIVER NAME: "<<name<<endl;
	cout<<"DISTANCE FROM YOU: "<<y<<endl;
	cout<<"PRICE: "<<y*10<<"Rupees"<<endl;
	cout<<endl;
	
}
void login();
int main(){
	    char c;
    int choice;
    cout<<"		NEARBY CABS"<<endl;
    cout<<"**********************";
    cout<<"**************************"<<endl;
	
    cout<<"1.Register\t\t2.Login"<<endl;
    cout<<"Enter choice:"<<endl;
    
    cin>>choice;

    if (choice==1){ 
     
	reg();
	
	
	       

	
    }
    
    else if(choice==2){
        //  login
    login();}
    else {
        cout<<"Please enter a valid choice!"<<endl;
    }
    
    json obj;
      
    // To read customers.json file.
    obj.json_parser();
    book(a);
   
    return 0;
}
   void menu(){
   	cout<<"*CAB BOOKING*"<<endl;
    	
	
   cout<<"Enter your coodinates: "<<endl;
			cout<<"Lattitude: ";
			cin>>lat1d;
			cout<<"Longitude: ";
			cin>>lon1d;
			if((lat1d>11&&lat1d<13||lat1d<-9&&lat1d>-9.5678)&&(lon1d<78&&lon1d>76))
			{
			 
    json obj;}
	else{
		cout<<"Coordinates out of range"<<endl;
		
	}}
void reg(){
      ofstream output;
        output.open("record.txt");
        cout<<endl<<"      REGISTERATION"<<endl;
        cout<<"Enter username: "<<endl;
        cin>>uName;
        cout<<"Enter password: "<<endl;
        cin>>pass;
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter email: "<<endl;
        cin>>email;
        cout<<"Enter gender: "<<endl;
        cin>>gender;
        cout<<"Enter phone number: "<<endl;
        cin>>phone;

        output<<uName<<" "<<pass<<" "<<name<<" "<<email<<" "<<gender<<" "<<phone<<endl;
        output.close();
        cout<<"Registration complete!"<<endl;
		login();
		}
		
        void login(){
	    ifstream input("record.txt");

        if(!input) {
            cout<<"Error creating file!";
        }
		cout<<endl<<"	LOGIN"<<endl;
        cout<<"Enter username:"<<endl;
        cin>>logname;
        cout<<"Enter password:"<<endl;
        cin>>logpass;
        if (input >> uName && input >> pass &&     // check if reading was successfull
        uName == logname && pass == logpass) { //input??uName trying to get to the file and read the already entered uName and match with the current entered name by user, same with pass
            cout<<"Login successful"<<endl;
	menu();

        }
        else {
            cout<<"Login failed!"<<endl;exit(1);
        }

        input.close();
    
    
}
void book(long int a[]){
	int flag;
	cout<<"Enter the CAB DRIVER ID for booking: ";
	long int x;
	cin>>x;
	for(int i=0;i<10;i++){
		if(x==a[i]){
			cout<<"Cab Booked!!"<<endl;
			
			flag=1;
			
		}
		
		
}pay();}
void pay(){
	cout<<endl<<"*****BILL PAYMENT*****"<<endl;
	cout<<"1.BY CARD			 2.BY CASH"<<endl;
	cout<<"Enter Choice: ";
	int m;
	cin>>m;
switch(m)
	{case 2: 
		cout<<"PAY "<<"AMOUNT"<<endl;
		cout<<"THANK YOU!PLEASE COME BACK AGAIN!!"<<endl;
		break;
	
	case 1:
		cout<<"ENTER CARD DETAILS: "<<endl;
		cout<<"CARD NUMBER: ";
		int n;
		cin>>n;
		cout<<"ENTER CVV NUMBER: "<<endl;
		int cvv;
		cin>>cvv;
		cout<<"AMOUNT PAID!!"<<endl;
		cout<<"THANK YOU! PLEASE COME BACK AGAIN!!"<<endl;
		break;
		default:
			cout<<"CAB CANCELLED!!"<<endl;
}
	
	}

