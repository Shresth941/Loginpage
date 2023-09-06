#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"Security System" << endl;
    cout<<"_____________________________________" << endl<<endl;
    cout<<"|              1.Register            |" <<endl ;
    cout<<"|              2.Login               |" <<endl ;
    cout<<"|              3.Change password     |" <<endl ;
    cout<<"|              4.End Program         |" <<endl<<endl; 

    do {
        cout<<endl<<endl;
        cout<<"Enter your choice:-";
        cin>>a;

        switch(a) {
            case 1: {
                cout<<"______________________________"<<endl<<endl;
                cout<<"|----------1.Register-------- |" <<endl ;
                cout<<"|_____________________________|" <<endl<<endl;
                cout<<"| Please enter your username:-|" <<endl ;
                cin>>name;
                cout<<"| Please enter your password:-|" <<endl ;
                cin>>password0;
                cout<<"| Please enter your age:-     |" <<endl ;
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    of1<<age<<"\n";
                    cout<<"Registration successful"<<endl;
                }
                of1.close();
                break;
            } 
            case 2: {
                i=0;
                cout<<"______________________________"<<endl<<endl;
                cout<<"|-------------Login-----------|" <<endl ;
                cout<<"|_____________________________|" <<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                if(!of2.is_open()) {
                    cout<<"File not found"<<endl;
                    break;
                }

                cout<<"Please enter the username:-";
                cin>>user;
                cout<<"Please enter the password:-";
                cin>>pass;

                while(!of2.eof()) {
                    getline(of2, text);
                    istringstream iss(text);
                    iss >> word;

                    creds[i] = word;
                    i++;

                    if(i == 2) {
                        if(user == creds[0] && pass == creds[1]) {
                            cout<<"--Log in successfull--"<<endl<<endl;
                            cout<<"Details"<<endl;
                            cout<<"Username:- "<<user<<endl;
                            cout<<"Password:- "<<pass<<endl;
                            getline(of2, age);
                            cout<<"Age:- "<<age<<endl;
                            break;
                        } else {
                            i = 0;
                        }
                    }
                }

                if(i == 0) {
                    cout<<endl<<endl;
                    cout<<"Incorrect Credentials"<<endl;
                    cout<<"|     1.Press 2 to login             |"<<endl;
                    cout<<"|     2.Press 3 to change password   |"<<endl;
                }

                of2.close();
                break;
            }
            case 3: {
                i=0;
                cout<<"-------Change Password-------"<<endl;

                ifstream of0;
                of0.open("file.txt");

                if(!of0.is_open()) {
                    cout<<"File not found"<<endl;
                    break;
                }

                cout<<"Enter the old password:-";
                cin>>old;

                while(!of0.eof()) {
                    getline(of0, text);
                    istringstream iss(text);
                    iss>>word ;            cp[i] = word;
                i++;

                if(i == 2) {
                    if(old == cp[1]) {
                        of0.close();

                        ofstream of1;
                        of1.open("file.txt");
                        if(of1.is_open()){
                            cout<<"Enter your password:-";
                            cin>>password1;
                            cout <<"Enter your password again:-";
                            cin>>password2;

                            if(password1 == password2) {
                                of1<<cp[0]<<"\n";
                                of1<<password1<<"\n";
                                of1<<age<<"\n";
                                cout<<"Password changed successfully"<<endl;
                            } else {
                                of1<<cp[0]<<"\n";
                                of1<<old<<"\n";
                                of1<<age<<"\n";
                                cout<<"Passwords do not match"<<endl;
                            }

                            of1.close();
                        } else {
                            cout<<"File not found"<<endl;
                        }

                        break;
                    } else {
                        i = 0;
                    }
                }
            }

            if(i == 0) {
                cout<<"Please enter a valid password ";
            }

            of0.close();
            break;
        }
        case 4: {
            cout<<"__________THANK YOU__________";
            break;
        }
        default: {
            cout<<"Enter the valid choice ";
        }
    }
} while(a != 4);

return 0;
}
