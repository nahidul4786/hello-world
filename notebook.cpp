#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
class input_info
{
    int i;
    string date,srpersonal_sr;
    string information;
    string tt_time;
public:
    void input_new();
    void read_file();
}t;
//****** Input New Data Information save ******
void input_info::input_new()
{
    time_t ts1 = time(0);

    struct tm * now = localtime(&ts1);
    ofstream file;
    file.open("index.txt",ios_base::app);
    if(file.fail()){
        cerr<<"File Open File ! ";
    }

        cout<<"\tDate: "<<now->tm_mday<<"/"<<1+now->tm_mon<<"/"<<1900+now->tm_year<<endl;
        cout<<"Enter Note Today : ";
        cin.ignore();
        getline(cin,information);
        file<<"<Srpersonal>\t"<<now->tm_mday<<"/"<<1+now->tm_mon<<"/"<<1900+now->tm_year<<"\t"<<now->tm_hour<<":"<<now->tm_min<<":"<<now->tm_sec<<"\t"<<information<<endl; //New File Write
        cout<<now->tm_mday<<"/"<<1+now->tm_mon<<"/"<<1900+now->tm_year<<"\t"<<now->tm_hour<<":"<<now->tm_min<<":"<<now->tm_sec<<"\t"<<information<<endl;

}
//****** Read Data Information In Text File ******
void input_info::read_file()
{


    ifstream myfile;
    myfile.open("index.txt");
    if(myfile.fail()){
        cerr<<"File Open Fail ! ";
    }
    string name;
    int start=0;
    while(!myfile.eof()){
        myfile>>name;
        if(name == "<Srpersonal>" )
        start++;
    }

    ifstream myfile2;
    myfile2.open("index.txt");
    for(i=1;i<=start;i++){
    myfile2>>srpersonal_sr>>date>>tt_time;
    myfile2.ignore();
    getline(myfile2,information);
    cout<<"\t"<<date<<"\t"<<tt_time<<"\t"<<information<<endl;
    }
}
//****** Importance Contact Information *******
class importance_contact
{
    char name[10];
    string mobile,address,srpersonal_2;
public:
    void input_importance_contact();
    void see_all_contact_information();
}tt;
// Import New Contact Information and Number
void importance_contact::input_importance_contact()
{
    cout<<"\n\tName : ";cin>>name;
    cout<<"\n\tContact Number : "; cin>>mobile;
    cout<<"\n\tAddress : ";
    cin.ignore();
    getline(cin,address);
    ofstream myfile;
    myfile.open("contact.txt",ios_base::app);
    myfile<<"<Srpersonal>\t"<<name<<"\t"<<mobile<<"\t"<<address<<"\n";
}
//See Contact number
void importance_contact::see_all_contact_information()
{
    ifstream contact_file;
    contact_file.open("contact.txt");
    if(contact_file.fail()){
        cerr<<"File Open Fail ! ";
    }
    string name;
    int start=0;
    while(!contact_file.eof()){
        contact_file>>name;
        if(name == "<Srpersonal>" )
        start++;
    }

    ifstream contact_file_2;
    contact_file_2.open("contact.txt");
    int i;
    for(i=1;i<=start;i++){
    contact_file_2>>srpersonal_2>>name>>mobile>>address;
    contact_file_2.ignore();
    getline(contact_file_2,srpersonal_2);
    contact_file_2.ignore();
    getline(contact_file_2,address);
    cout<<"\t"<<name<<"\t"<<mobile<<"\t"<<address<<endl;
    }
}
//*******About Notebook*******
class aboutme
{
    string line_aboutme;
public:
    void read();
    void edit_me_full();
    void add_new_aboutme();
    friend class aboutme_2;
    void input_about_me_feature();
}t3;
class aboutme_2
{

    char option;
public:
    void input_line_about_2();

}tt3;
//********* All Feature ************
void aboutme::input_about_me_feature(){
    cout<<"\t-->> You can use this software very easily. This is a license free software.\n ";
    cout<<"\t-->> First release 02 March 2019 form DIU,Shukrabad,Dhaka. \n ";
}
void aboutme_2::input_line_about_2()
{
    string adminname,password;
    cout<<"\n \t Go To Admin mood or Exist (press 'A' or 'x' ) : ";
    cin>>option;
    if(option == 'a' || option == 'A'){
        cout<<"User Name : ";cin>>adminname;
        cout<<"Password  : ";cin>>password;
        if(adminname == "admin" && password == "admin123"){
    cout<<"Option\n";
                char adminplan;
                cout<<">>> A. Full Edit About \n";
                cout<<">>> B. Added New Feature \n";
                cout<<"Select Option ('A' or 'B' ) : ";cin>>adminplan;
    if(adminplan == 'a' || adminplan == 'A'){
    t3.edit_me_full();
    }
    else if(adminplan == 'b' || adminplan == 'B'){
    t3.add_new_aboutme();}
    else
        cout<<"error selection !! ";
    }
    else
        cout<<"\n\t Don't Match Username and Password ! \n\n";
    }
    else if(option >= 'b' || option>='B' && option<='z' || option<='z' ){
        cout<<"\n Thanks For Use My Notebook \n \n";
    }
}
void aboutme::read()
{
    int i;
    ifstream readme;
    readme.open("aboutme.txt");
    for(i=1;i<=5;i++){
    readme>>line_aboutme;
    getline(readme,line_aboutme);
    cout<<"\t"<<line_aboutme<<endl;
    }
}
void aboutme::edit_me_full()
{
    cout<<"\nEnter Information Here : ";
    cin>>line_aboutme;
    getline(cin,line_aboutme);
    ofstream edit_me_file;
    edit_me_file.open("aboutme.txt");
    edit_me_file<<line_aboutme;

}
void aboutme::add_new_aboutme()
{
    cout<<"\nEnter New Future Here : ";
    cin>>line_aboutme;
    getline(cin,line_aboutme);
    ofstream edit_me_file;
    edit_me_file.open("aboutme.txt",ios_base::app);
    edit_me_file<<endl<<"-->> -->>"<<line_aboutme<<endl;

}
//******* Main Function *******
main()
{
    char ch;
    char contact_option; //Contract Menu Selection
    cout<<"\n\tWelcome To My Notebook 1.0 \n \n";
    // ***** Clock *************
    time_t t1 = time(0);
    struct tm * now = localtime(&t1);
    cout<<"\tTime :"<<now->tm_hour<<":"
        <<now->tm_min<<":"
        <<now->tm_sec
        <<endl;
    cout<<"\t"<<"Year : "<<1900+now->tm_year<<endl;
    //***** Menu Option Choose ******
    while(1){
    cout<<"\tA . Add New Information \n";
    cout<<"\tB . Read All Information  \n";
    cout<<"\tC . Contact     \n";
    cout<<"\tD . About Notebook     \n";
    cout<<"\tE . Exit     \n";

    cout<<"\tSelect Option : ";
    cin>>ch;
    if( ch=='f'|| ch=='F' ){
        cout<<"\n \t Wrong Choose !\n\n";
    }
    else if(ch == 'a' || ch =='A'){
        cout<<"\n\tAdd New Information\n";
        t.input_new();
    }
    else if(ch == 'b' || ch =='B'){
        cout<<"\n\t All Data Information \n";
        t.read_file();
        cout<<endl;
    }
    //    ******** Select Option C *********
    else if(ch == 'C' || ch == 'c'){
        cout<<"\n\t Importance Contact Number  \n";
        cout<<"\n\t******Add New Information******* \n";

        cout<<"\t*******Contact Menu*****\n";
        cout<<"\tA . See All Contract Number \n ";
        cout<<"\tB. Add New Contact Number \n";
        cout<<"\tChoose Option : ";cin>>contact_option;
        if(contact_option == 'b' || contact_option == 'B'){
            tt.input_importance_contact();
        }
        else if(contact_option == 'a' || contact_option == 'A'){
        cout<<"\n\tName"<<"\t"<<"Mobile \t"<<"\tAddress \n";
        cout<<"\tNahidul Islam"<<"\t"<<"01521473910\t"<<"Shukrabad Dhaka. \n";
        tt.see_all_contact_information();
        cout<<"\n\n";
        }

    }

    //    ******** Select Option E *********
    else if(ch == 'D' || ch == 'd'){
        cout<<"\n\t\tWelcome To My Notebook   \n";
            t3.input_about_me_feature();
            t3.read();
            tt3.input_line_about_2();

    }
    else if(ch == 'E' || ch == 'e'){
        cout<<"Thank You ";
        return 0;
    }
    else
    {
        cout<<" \n \t Wrong Selection ! ";
        cout<<"You Select Wrong Option . Notebook Close :( ";
    }

    }

}
