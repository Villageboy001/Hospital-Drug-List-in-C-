#include <iostream>
#include <windows.h>
#include<mysql.h>

using namespace std;

int main()
{
    MYSQL* conn, con;
    MYSQL row;
    char *server ="localhost";
   char * user = "root";
    char *password = "";
    char *db = "cplusplus";
/*c++ database connection */

    conn = mysql_init(NULL);
    conn = mysql_real_connect(conn, server, user, password,db, 0 , NULL,0);
    if(conn/*mysql_real_connect(conn, server, user,password,db, 0 , NULL, 0*/){
        cout<<"Connect \n";
    }
    else{
        cout<<"Not connect \t";
    }

    cout << "Hello world!" << endl;
    string table =  "CREATE TABLE VILLAGE(ID INT(2))";
    const char *t = table.c_str();
    mysql_query(conn,t);
    if(t){
        cout<<"village boy \n";
    }else{
    cout<<"fail to create \t";
    }

    return 0;
}
