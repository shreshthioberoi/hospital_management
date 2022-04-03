#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<string.h>
#include<conio.h>
using namespace std;
struct patient
{
    char first_name[20];
    char last_name[20];
    char patient_add[200];
    char patient_phonenumber[10];
    int patient_age;
    char patient_gender[8];
    char patient_bloodtype[5];
    char patient_disease_pt[50];
    int patient_id;
    char patient_symptom[500];
    char patient_diagnosis[500];
    char patient_medicine[500];
    char patient_addmission[30];
    struct patient *next;
    bool diagnose_patient;
};
class security:public patient
{
    public:
        void security_patient()
      {
            int userId;

            a:
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
            cout<<"\n\t\t\t\t\t\t\tEnter Login Id = ";
            cin>>userId;
            cout<<"\t\t\t\t\t\t\t---------------------";
            if(userId!=1353)
            {
                cout<<"\nIncorrect Id\n";
                goto a;
            }
            else
            cout<<"\n\n\n\t\t\t\t\t\t welcome to hospital management system ,\n";
            b:
            string pwd="pass";
            string pass="";
            char c;
                cout<<"\n\n\n\t\t\t\t\t\t\tPassword = ";
                c:
                c=getch();
                cout<<"*";
                if(c!=13)
                {
                    pass=pass+c;
                    goto c;
                }

                {
                if(pass==pwd)
                {
                    cout<<"\n\n\t\t\t\t\t\t\tAccess Granted. Welcome to our system\n\n\n";
                    system("PAUSE");
                    system("CLS");

                }
                else
                {
                cout<<"\nWrong Password\n";
                goto b;
                }
            }
        }
};
struct patient *head,*tail;
bool checking=true;
int array[20]={0},v=0;
bool check_id(int ch)
{
        for(int y=0;y<v;y++)
        {
            if(ch==array[y])
            {
                return true;
            }
        }
        return false;
};
class Function
{
    public:
      void add()
      {

        patient *pat = new patient;
        pat->diagnose_patient=false;
        cout<<"Enter Patient ID"<<endl;
        cin>>pat->patient_id;
        cout<<"Enter Patient First Name"<<endl;
        cin>>pat->first_name;
        cout<<"Enter Patient Last name"<<endl;
        cin>>pat->last_name;
        cout<<"Enter Patient Age"<<endl;
        cin>>pat->patient_age;
        cout<<"Enter Patient Gender"<<endl;
        cin>>pat->patient_gender;
        cout<<"Enter Patient Blood Group"<<endl;
        cin>>pat->patient_bloodtype;
        cout<<"Enter Patient Contact "<<endl;
        cin>>pat->patient_phonenumber;
        fflush(stdin);
        cout<<"Enter Patient Address"<<endl;
        cin.getline(pat->patient_add,1000);

        pat->next=NULL;
        array[v]=pat->patient_id;

        v++;
        if(checking)
    {
        head=pat;
        tail=pat;
        checking=false;
    }
    else
    {
        tail->next=pat;
        tail=pat;
    }

  }
  void show()
  {
        //int z;
        patient *cur;
        cur=head;
        int input_id;
        cout<<"Enter Patient ID"<<endl;
        cin>>input_id;
        if(check_id(input_id))
        {
        while(cur->patient_id!=input_id)
        {
            cur=cur->next;
        }

        cout<<"Patient First Name"<<endl;
        cout<<cur->first_name<<endl;
        cout<<"Patient Last Name"<<endl;
        cout<<cur->last_name<<endl;
        cout<<"Patient ID"<<endl;
        cout<<cur->patient_id<<endl;
        cout<<"Patient Age"<<endl;
        cout<<cur->patient_age<<endl;
        cout<<"Patient Gender"<<endl;
        cout<<cur->patient_gender<<endl;
        cout<<"Patient Blood Type"<<endl;
        cout<<cur->patient_bloodtype<<endl;
        cout<<"Patient Contact "<<endl;
        cout<<cur->patient_phonenumber<<endl;
        cout<<"Patient Address"<<endl;
        cout<<cur->patient_add<<endl;
        cout<<"***********"<<endl;
        if(cur->diagnose_patient){
        cout<<"Symptoms"<<endl;
        cout<<cur->patient_symptom<<endl;
        cout<<"Diagnosis"<<endl;
        cout<<cur->patient_diagnosis<<endl;
        cout<<"Medicines"<<endl;
        cout<<cur->patient_medicine<<endl;
        cout<<"Admit Required to Hospital?"<<endl;
        cout<<cur->patient_addmission<<endl;
       }}
       else
       {
        cout<<"ID not present"<<endl;
       }
}
  void diagnosis()
  {
    patient *current_pat=new patient;

    current_pat=head;
    int change;
    cout<<"Enter Patient ID"<<endl;
    cin>>change;
    if(check_id(change)){
        while(current_pat->patient_id!=change )
        {
            current_pat=current_pat->next;
        }
        current_pat->diagnose_patient=true;
        cout<<"Enter Symptoms"<<endl;
        cin>>current_pat->patient_symptom;
        cout<<"Enter Diagnosis"<<endl;
        cin>>current_pat->patient_diagnosis;
        cout<<"Enter Medicines"<<endl;
        cin>>current_pat->patient_medicine;
        cout<<"Admit Required to Hospital?"<<endl;
        cin>>current_pat->patient_addmission;

    }

    else
        cout<<"ID is not Registered\n";

    }
void deleteList()
{
    patient *cur=NULL,*previous=NULL;

    previous=head;
    cur=head;
    int change;
    cout<<"Enter the ID: ";
    cin>>change;
    if(check_id(change)){

        while(cur->patient_id!=change)
        {
            previous=cur;
            cur=cur->next;
        }
        previous->next=cur->next;
        free(cur);


      for(int i=0;i<v;i++)
      {
        if(array[i]==change){
            for (int y=i;y<v;y++){
                array[y]=array[y+1];
              }
              v--;
          }
      }
    cout<<"Patient Record is Deleted\n";
    }
    else
       cout<<"ID not present"<<endl;
}
void update_menu()
{
        cout<<"press 1 Patient First Name"<<endl;
        cout<<"press 2 Patient Last Name"<<endl;
        cout<<"press 3 Patient ID"<<endl;
        cout<<"press 4 Patient Age"<<endl;
        cout<<"press 5 Patient Gender"<<endl;
        cout<<"press 6 Patient Blood Type"<<endl;
        cout<<"press 7 Patient Phone Number "<<endl;
        cout<<"press 9 Patient Address"<<endl;
        cout<<"***********"<<endl;
        cout<<"press 10 Symptoms"<<endl;
        cout<<"press 11 Diagnosis"<<endl;
        cout<<"press 12 Medicines"<<endl;
        cout<<"press 13 admit Required to Hospital?"<<endl;
}
void update_data(){
    patient *cur=NULL;
    cur=head;
    int patient_id,change;
    cout<<"Enter ID"<<endl;
    cin>>patient_id;
    if(check_id(patient_id)){
        while(cur->patient_id!=patient_id)
        {
            cur=cur->next;
        }
        update_menu();
        cout<<"Choose Number"<<endl;
        cin>>change;
        if(change==1){
            cout<<"Enter First Name"<<endl;
            cin>>cur->first_name;
          }
        else if(change==2){
            cout<<"Enter Second Name"<<endl;
            cin>>cur->last_name;
        }
        else if(change==3){
            cout<<"Enter ID"<<endl;
            cin>>cur->patient_id;
        }
        else if(change==4){
            cout<<"Enter Age"<<endl;
            cin>>cur->patient_age;
          }
        else if(change==5){
            cout<<"Enter Gender"<<endl;
            cin>>cur->patient_gender;
        }
        else if(change==6){
            cout<<"Enter Blood Type"<<endl;
            cin>>cur->patient_bloodtype;
        }
        else if(change==7){
            cout<<"Enter Phone Number"<<endl;
            cin>>cur->patient_phonenumber;
        }
        else if(change==9){
            cout<<"Enter Address"<<endl;
            cin>>cur->patient_add;
        }
        else if(change==10){
            cout<<"Enter 10 Symptoms"<<endl;
            cin>>cur->patient_symptom;
        }
        else if(change==11){
        cout<<"Enter 11 Diagnosis"<<endl;
        cin>>cur->patient_diagnosis;
        }
        else if(change==12){
        cout<<"Enter 12 Medicines"<<endl;
        cin>>cur->patient_medicine;
        }
        else if(change==13){
        cout<<"Admit 13 Required to Hospital?"<<endl;
        cin>>cur->patient_addmission;
    }
   }
   else
     cout<<"ID not present"<<endl;
}
void exit()
{
    _Exit(0);
}
};

void display_menu()
{
        cout <<"\t\t\t\t\t\t\t" <<char(218);      for(int i=0; i<31; i++){cout << char(196);}      cout << char(191) << endl;

        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[1] Add New Patient Record     " << char(179) << endl;
        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[2] Add Patient Prescription   " << char(179) << endl;
        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[3] Full History of the Patient" << char(179) << endl;
        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[4] Delete Patient Record      " << char(179) << endl;
        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[5] Update Patient Record      " << char(179) << endl;
        cout <<"\t\t\t\t\t\t\t"<<char(179) << "[6] Exit                       " << char (179)<<endl;

        cout <<"\t\t\t\t\t\t\t"<<char(192);for(int i=0; i<31; i++){cout << char(196);}      cout << char(217) << endl;

}
int main()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
            console_color , 5);
    /*
    0 Black
    1 Blue
    2 Green
    3 Aqua
    4 Red
    5 Purple
    6 Yellow
    7 White
    8 Gray
    9 Light Blue
    A Light Green
    B Light Aqua
    C Light Red
    D Light Pruple
    E Light Yellow
    F Bright White
  */

    struct patient* head;
    head=NULL;
    security obj1;
    obj1.security_patient();
    Function m;
    int v=0;
    do{
    display_menu();
    cin>>v;
    if(v==1)
    m.add();
    else if(v==2)
    m.diagnosis();
    else if(v==3)
    m.show();
    else if(v==4)
    m.deleteList();
    else if(v==5)
    m.update_data();
    else if(v==6)
    m.exit();
    }while(1);
    return 0;
}

