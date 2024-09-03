#include<iostream>
#include<string.h>
#include<climits>
#include<fstream>
#include<unistd.h>

using namespace std;
#define INF 999
int mindistance(float distance[],bool stat[])
{
	float minimum=INT_MAX;
    int ind;
	for(int k=0;k<25;k++)
	{
		if(stat[k]==false && distance[k]<=minimum)
		{
			minimum=distance[k];
			ind=k;
		}
	}
	return ind;
}



void dijkstra(float graph[25][25], int source, string stations[24]) {
    float distance[25];
    bool stat[25];
    int previous[25];  // To track the previous station for reconstructing the path

    for (int k = 0; k < 25; k++) {
        distance[k] = INT_MAX;
        stat[k] = false;
        previous[k] = -1;  // Initialize previous stations to -1
    }
    distance[source] = 0;

    for (int k = 0; k < 25; k++) {
        int m = mindistance(distance, stat);
        stat[m] = true;

        for (int k = 0; k < 25; k++) {
            if (!stat[k] && graph[m][k] && distance[m] != INT_MAX &&
                distance[m] + graph[m][k] < distance[k]) {
                distance[k] = distance[m] + graph[m][k];
                previous[k] = m;  // Track the previous station
            }
        }
    }

    cout << "\n\n\nMinimum Number of Stations from "
         << "[" << stations[source] << "]"
         << " To every station\n\n\n" << endl;

    for (int k = 0; k < 24; k++) {
        cout << "Enter " << k << " To Check Distance Between "
             << stations[source] << " To "
             << "[" << stations[k] << "] Station" << endl;
    }

    int n;
    cout << "Enter Station to check distance to Each other:" << endl;
    cin >> n;

    cout << "Total Distance from "
         << "[" << stations[source] << "]"
         << " To " << stations[n] << " are "
         << "[" << distance[n] << "] KM" << endl;

    // Calculate the number of intermediate stations
    int count = 0;
    int temp = n;
    while (previous[temp] != -1) {
        count++;
        temp = previous[temp];
    }
    cout << "Number of Intermediate Stations: " << count << endl;

    // Calculate the fare based on the distance
    int fare = 0;
    if (distance[n] <= 2)
        fare = 10;
    else if (distance[n] <= 5)
        fare = 20;
    else if (distance[n] <= 12)
        fare = 30;
    else if (distance[n] <= 21)
        fare = 40;
    else if (distance[n] <= 32)
        fare = 50;
    else
        fare = 60;

    cout << "Fare for the trip: Rs " << fare << "/-" << endl;

    cout << "Route: "<< endl;
   
    for(int k=source+1;k<=n;k++){
	
	cout<<stations[source]<<" -> "<<stations[k]<<" "<<"Station"<<"["<<distance[k]<<"]"<<"KM"<<endl;
    }
    cout << endl;

}

int login()
{
    char dum,u_name[30],name[30],g_pwd[30],pwd[30];
    int flag=0,s=1;
 cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO LOGIN*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    if(s==1){

cout<<"Enter your USER NAME  : "<<endl;
          string phrase = "Enter your USER NAME And PASSWORD: ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    cin>>name;
}

        cout<< "Enter the PASSWORD   : "<<endl;
//        string command = "espeak \"" + phrase + "\"";
//    const char *charCommand = command.c_str();
//        system(charCommand);
    cin>>pwd;
    fstream f;
    f.open("user_logins.txt",ios::in);
    f.seekg(0);
    while(f)
    {
        f.get(dum);
        f.get(u_name,30);
        f.get(dum);
        f.get(g_pwd,30);
        if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)==0)
        {
            flag=1;
             string phrase = "\n\t\t\tYou have Successfully LOGGED IN ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
            break;
        }
        else if(strcmp(u_name,name)==0&&strcmp(pwd,g_pwd)!=0)
        {
            do
            {
                 string phrase = "\t\t\t----INCORRECT PASSWORD!!!----";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
                
               
                           cout<<"Re-Enter the PASSWORD : "<<endl;
       
                cin>>pwd;
            }while(strcmp(pwd,g_pwd)!=0);
            
        string phrase = "\n\t\t\tYou have Successfully LOGGED IN";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n\t\t\tSORRY!!! USER NAME and PASSWORD does not Exist"<<endl;
    system("clear");
    f.close();
    return flag;
}

void signup()
{
 cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO SIGNUP*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    char name[30],pwd[30],check_pwd[30];
    fstream f;
    f.open("user_logins.txt",ios::in);
    char g_name[30],g_pwd[30],dum;
    int flag;
    cout<<"Enter the USER NAME : ";
     string phrase = "Enter your USER NAME And PASSWORD: ";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    cin>>name;
    do
    {
        f.seekg(0);
        while(f)
        {
            flag=1;
            f.get(dum);
            f.get(g_name,30);
            f.get(dum);
            f.get(g_pwd,30);
            if(strcmp(g_name,name)==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t----SORRY! USER-NAME ALREADY EXIST----"<<endl;
            cout<<"Enter the USER NAME : ";
            cin>>name;
        }
    }while(flag==0);
    f.close();
    f.open("user_logins.txt",ios::out|ios::app);
    cout<<"Enter your PASSWORD : ";
    cin>>pwd;
    cout<<"Re-Enter your PASSWORD : ";
    cin>>check_pwd;
    while(strcmp(pwd,check_pwd)!=0)
    {
        cout<<"\t\t\t----INCORRECT PASSWORD!!!----"<<endl;
        cout<<"Enter your PASSWORD : ";
        cin>>pwd;
        cout<<"Re-Enter your PASSWORD : ";
        cin>>check_pwd;
    }
    f<<endl<<name<<endl<<pwd;
 cout<<"\n\t\t\t\t\t  YOUR NEW ID IS CREATING PLEASE WAIT";
	for(int i=0;i<6;i++)
	{
		cout<<".";
		sleep(1);
    }
	cout<<"\n\n\t\t\t\t\t\aCONGRATULATION!!!YOUR ID CREATED SUCCESSFULL....Please wait";
	sleep(1);
	system("clear");
    f.close();
}
int main()
{
	float graph[25][25]={
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1.1, 0, 0.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0},
{0, 0, 0, 0, 0.7, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1.1, 0, 2.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 2.3, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1.1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 3.8, 0, 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 0.9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.9, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 2.5, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.5, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.5, 0, 1.2, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 1.3, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.3, 0, 1.1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 0.5, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 3.5}};
	int source;
	 int n,W,ch,flag;
    char s;
    cout<<"\t\t\t\t\t\t----------------------------------------WELCOME TO Orange Line Metro Distance Counter----------------------------------------\n\n";
    do
    {
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t_\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_\xdb\xdb\xdb\xdb\xdb\xdb \n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 1) LOGIN    \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 2) REGISTER \xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb 3) EXIT     \xdb\xdb\xdb\xdb\xdb\xdb\n";
         cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"\t\t\t\t\t\t\t \t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb_\xdb\xdb\xdb\xdb\xdb\xdb\n";
        cout<<"Enter your Choice : ";
        cin>>ch;
        system("clear");
        switch(ch)
        {
            case 1:
                flag=login();
                break;
            case 2:
                signup();
                cout<<"Do you want to LOGIN (Y/N)? : ";
                cin>>s;
                if(s=='y'||s=='Y')
                    flag=login();
                else
                {
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                    cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|_|\n";
                    exit(1);
                }
                break;
            case 3:
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                cout<<"\t\t\t\t\t\t\t \t\t\t\t\t|_|\n";
                exit(0);
                break;
            default:
                cout<<"\t\t\t----INCORRECT CHOICE!!!----"<<endl;
                break;
        }
    }while(flag!=1);
    if(flag==1)
    {
	string stations[24]={"ROHINI SECTOR - 18, 19","KASHMERE GATE","CHAWRI BAZAR","NEW DELHI","RAJIV CHOWK","PATEL CHOWK","UDYOG BHAWAN"
	,"LOK KALYAN MARG","JOR BAGH","DILLI HAAT - INA","AIIMS","GREEN PARK ","MALVIYA NAGAR",
	"SAKET","QUTAB MINAR","CHHATARPUR","SULTANPUR","GHITORNI","ARJAN GARH","GURU DRONACHARYA","SIKANDERPUR","M.G. ROAD ","IFFCO CHOWK","MILLENNIUM CITY CENTRE GURUGRAM"};

	 char x;
	      cout<<"\n\n\n\n\n\n\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
    cout<<"\t\t\t\t\t\t*WELLCOME TO Yellow Line Metro Distance Counter*"<<endl;
    cout<<"\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb "<<endl;
             string phrase = "WELLCOME TO Orange Line Metro Distance Counter";
        string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
        system(charCommand);
    do
    {
    		for(int i=0;i<24;i++)
	{
		cout<<"Enter "<<" "<<i<<" "<<" for "<<stations[i]<<endl;
	}
    	cout<<"Enter the source station"<<endl;
    	cin>>source;
    	system("clear");
	dijkstra(graph,source,stations);

 cout<<"Do you want to continue (Y/N)? : ";

                cin>>x;
                	system("clear");
	}while(x=='y'||x=='Y');
	return 0;
}
}