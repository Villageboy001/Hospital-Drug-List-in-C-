#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <ctime>
#include<sstream>

using namespace std;
//   string instrument="INSERT INTO Instrument (InstrumentID, InstrumentType, MakerName, YearMade) VALUES ( '"+instnum+"', '"+insttype+"', '"+maker+"', '"+year+"')";
bool insert_status;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES *res;
int qstate;
MYSQL* my()
{
conn = mysql_init(0);
conn = mysql_real_connect(conn,"localhost","root","","pharmaccutical_industry",0,NULL,0);
return conn;
}

bool var(string nu,string drugname,string manufacturer,string date_of_stock,string expiry_date,string detail){
string query="INSERT INTO ok(id,drugname,manufacturer,date_of_stock,expiry_date,detail) VALUES ('"+nu+"','"+drugname+"','"+manufacturer+"','"+date_of_stock+"','"+expiry_date+"','"+detail+"')";
const char* q = query.c_str();
qstate=mysql_query(my(),q);
if(!qstate){
     insert_status=true;
}else{
    insert_status=false;
}
   return insert_status;
}

int main()
{
MYSQL* conn=my();
if(conn)
{
    int n;
//cout<<"connected";
string query=" CREATE TABLE IF NOT EXISTS ok(id INT UNSIGNED ,drugname VARCHAR(40) NOT NULL,manufacturer VARCHAR(40) NOT NULL,date_of_stock VARCHAR(40) NOT NULL,expiry_date VARCHAR(40) NOT NULL,detail VARCHAR(40) NOT NULL) ";
const char* q = query.c_str();

cout<<mysql_error(conn);
cout<<"1) Press 1 to insert data to the database\n";
cout<<"2) Press 2 to display drugname registered on the database\n";
cout<<"3) Press 1 to update data in the database\n\n";
do{
cout<<"\nEnter choice\n";
cin>>n;

if((n==1)){
string stri;

cout<<"Enter the drug name you want to add to database:\n";
getline(cin,stri);
getline(cin,stri);
//cout<<stri;
string que="SELECT *FROM ok WHERE drugname ='"+stri+"'";

const char* qu = que.c_str();

qstate=mysql_query(conn, qu);
res = mysql_store_result(conn);
row=mysql_fetch_row(res);
if(row==0){
    time_t now = time(0);
   tm *ltm = localtime(&now);

        //cout<<"not in database";
   string manufacturer;
    cout<<"Enter the manufacturer of the drug:\n";
  getline(cin, manufacturer);

int x=ltm->tm_mday;
int y=ltm->tm_mon+1;
int z=ltm->tm_year+1900;
 stringstream ss;
  ss<<x;
  string s;
  ss>>s;
string x1=s;

 stringstream sos;

  sos<<y;
  sos>>s;
string y1=s;
 stringstream soso;

  soso<<z;
  soso>>s;


 string z1=s;
 //cout<<z1;
    string date_of_stock=x1+"/"+y1+"/"+z1;
    string expiry_date;
    cout<<"Enter the expiring date of the drug:\n";
  getline(cin, expiry_date);
    string detail;
    cout<<"Enter the details of the drug:\n";
  getline(cin, detail);
    string nu="6";

bool u=var(nu,stri,manufacturer,date_of_stock,expiry_date,detail);
if(u){
    cout<<"\ninserted";
}else{
    cout<<"\nnot inserted";
}


    //row=mysql_fetch_row(res);


  } else{
       cout<<"\nAready exist\n";



  }}else if(n==2){

  string que="SELECT *FROM ok ";
const char* qu = que.c_str();

qstate=mysql_query(conn, qu);
res = mysql_store_result(conn);
cout<<"Drugname "<<" \t Manufacturer"<<" \t Date of stock "<<"\t Expiry date "<<"\t Detail \n";

while(row=mysql_fetch_row(res)){
    cout<<row[1]<<"\t      "<<row[2]<<" \t"<<row[3]<<"  \t      "<<row[4]<<"    \t  "<<row[5]<<"\n";

};

  }
}while(n!=0);
   }  else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;

   // cout << "Hello world!" << endl;
    return 0;
}
