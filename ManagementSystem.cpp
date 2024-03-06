//
// Created by Student on 2/27/2024.
//
#include <limits>
#include "ManagementSystem.h"
#include <vector>
using namespace std;


ManagementSystem:: ManagementSystem(){

    employers = nullptr;
    candidates = nullptr;
    numOfEmp = 0;
    numOfCan = 0;
    numOfJobs = 0;
    getID();
    getEmp();
    getCan();

}

ManagementSystem:: ~ManagementSystem(){
    pushEmp();
    pushCan();
    pushID();
    delete [] employers;
    delete [] candidates;
}

void ManagementSystem:: getID(){
    ifstream idFile ("Id.txt");
    if (!idFile) {
        cout << "The system have a problem" << endl;
        return;
    }
    idFile >> ID ;
    idFile.close();
}

void ManagementSystem::pushID() {
    ofstream oId("Id.txt");
    if (!oId) {
        cout << "The system have a big problem" << endl;
    }
    oId << ID << endl;
    oId.close();
}

void ManagementSystem::getEmp() {
    char stam [20];
    char id [20];
    char pass [20];
    int q;
    char a[100];
    char f1 [200];
    char f2 [200];
    char f3 [200];
    char f4 [200];
    char f5 [200];
    int status;

    ifstream employersFile ("Employers.txt");
    if (!employersFile) {
        cout << "The system have a problem" << endl;
        return;
    }

    if(employersFile.eof())
        numOfEmp = 0;
    else
        employersFile >> numOfEmp;

    this->employers = new Employer[numOfEmp];

    for(int i = 0 ; i < numOfEmp; ++i) {
        employersFile >> id;
        employersFile >> pass;
        employersFile >> q;
        employersFile.getline(stam, 20);
        employersFile.getline(a, 100);

        Employer employer(id, pass, q, a);

        employersFile >> employer.jobsNum;
        numOfJobs += employer.jobsNum;
        employer.jobs = new Job[employer.jobsNum];

        for (int j = 0; j < employer.jobsNum; ++j){

            employersFile >> employer.jobs[j].id;

            employersFile.getline(stam, 20);

            employersFile.getline(f1, 200) ;
//            cout << f1 << endl;
            employer.jobs[j].setBusinessName(f1);

            employersFile.getline(f2, 200) ;
            employer.jobs[j].setAddress(f2);

            employersFile.getline(f3, 200) ;
            employer.jobs[j].setSalary(f3);

            employersFile.getline(f4, 200) ;
            employer.jobs[j].setAbout(f4);

            employersFile.getline(f5, 200) ;
            employer.jobs[j].setJobProfession(f5);

            employersFile >> employer.jobs[j].jobType ;
            employersFile >> employer.jobs[j].jobHours ;
            employersFile >> employer.jobs[j].experience ;
            employersFile >> employer.jobs[j].jobArea ;
            employersFile >> employer.jobs[j].age ;
            employersFile >> employer.jobs[j].jobFor ;
            employersFile >> employer.jobs[j].jobRange ;

            employersFile >> status;
            if(status == 1)
                employer.jobs[j].status = true ;
            else
                employer.jobs[j].status = false ;

            employersFile >> employer.jobs[j].numOfSub ;
            employer.jobs[j].idOfSub = new char* [employer.jobs[j].numOfSub];

            for (int k = 0; k < employer.jobs[j].numOfSub; ++k) {
                char id [20];

                employersFile >> id;
//                delete [] employer.jobs[j].idOfSub[k];
                employer.jobs[j].idOfSub[k] = new char [strlen(id)+1];
                strcpy(employer.jobs[j].idOfSub[k], id);
            }
        }
        employers[i] = employer;
    }
    employersFile.close();
}

void ManagementSystem::getCan() {
    char stam[200];
    char id [20];
    char pass [20];
    int q;
    char a[200];
    char f1 [200];
    char f2 [200];
    char f3 [200];
    char f4 [200];
    int age;
    char f5 [200];
    char f6 [200];
    char f7 [200];
    int status;
    char f9 [200];
    int idJ;
    char f8 [200];


    ifstream CandidateFile ("Candidates.txt");
    if (!CandidateFile) {
        cout << "The system have a problem" << endl;
        return;
    }
    if(CandidateFile.eof())
        numOfCan = 0;
    else
        CandidateFile >> numOfCan;
    this->candidates = new Candidate[numOfCan];
    for(int i = 0 ; i < numOfCan; ++i) {
        CandidateFile >> id;
        CandidateFile >> pass;
        CandidateFile >> q;
        CandidateFile.getline(stam, 200) ;
        CandidateFile.getline(a, 200) ;
        CandidateFile.getline(f1, 200) ;
        CandidateFile.getline(f2, 200) ;
        CandidateFile.getline(f3, 200) ;
        CandidateFile.getline(f4, 200) ;
        CandidateFile >> age;
        CandidateFile.getline(stam, 200) ;
        CandidateFile.getline(f5, 200) ;
        CandidateFile.getline(f6, 200) ;
        CandidateFile.getline(f7, 200) ;
//        CandidateFile >> f8 ;

        Candidate candidate(id, pass, q, a, f1,f2, f3, f4, age, f5, f6, f7);
        candidate.CV = NULL;

        CandidateFile >> status;
        if(status == 1)
            candidate.isCv = true ;
        else
            candidate.isCv = false ;
        if(candidate.isCv){
            CandidateFile >> f9;
            candidate.setCv(f9);
        }

        CandidateFile >> candidate.numOfSub;
        candidate.submissions = new Apply[candidate.numOfSub];
        for (int j = 0; j < candidate.numOfSub; ++j) {
            CandidateFile >> idJ;
            CandidateFile >> status;

            candidate.submissions[j].setStatus(status);
            candidate.submissions[j].setIdOfJob(idJ);
        }
        candidates[i] = candidate;
    }
    CandidateFile.close();
}

void ManagementSystem::pushEmp() {
//    this->print();
    ofstream oEmpFile("Employers.txt");
    if (!oEmpFile) {
        cout << "The system have a big problem" << endl;
    }
    oEmpFile << numOfEmp << endl;
    for(int i = 0; i < numOfEmp; ++i){
        oEmpFile << employers[i].id <<"\n";
        oEmpFile << employers[i].password<<"\n";
        oEmpFile << employers[i].forgetPassQ<<"\n";
        oEmpFile << employers[i].forgetPassA<<"\n";
        oEmpFile << employers[i].jobsNum<<"\n";
        for(int j = 0; j < employers[i].jobsNum; ++j) {
            oEmpFile << employers[i].jobs[j].id<<"\n";
            oEmpFile << employers[i].jobs[j].businessName<<"\n";
            oEmpFile << employers[i].jobs[j].jobProfession<<"\n";
            oEmpFile << employers[i].jobs[j].address<<"\n";
            oEmpFile << employers[i].jobs[j].salary<<"\n";
            oEmpFile << employers[i].jobs[j].about<<"\n";
            oEmpFile << employers[i].jobs[j].jobType<<"\n";
            oEmpFile << employers[i].jobs[j].jobHours<<"\n";
            oEmpFile << employers[i].jobs[j].experience<<"\n";
            oEmpFile << employers[i].jobs[j].jobArea<<"\n";
            oEmpFile << employers[i].jobs[j].age<<"\n";
            oEmpFile << employers[i].jobs[j].jobFor<<"\n";
            oEmpFile << employers[i].jobs[j].jobRange<<"\n";
            oEmpFile << employers[i].jobs[j].status<<"\n";
            oEmpFile << employers[i].jobs[j].numOfSub<<"\n";
            for(int k = 0; k < employers[i].jobs[j].numOfSub; ++k){
                oEmpFile << employers[i].jobs[j].idOfSub[k]<<"\n";
            }
        }
    }
    oEmpFile.close();
}

void ManagementSystem::pushCan() {
//    this->print();
    ofstream oCanFile("Candidates.txt");
    if (!oCanFile.is_open()) {
        cout << "The system have a big problem" << endl;
    }
    oCanFile << numOfCan << endl;
    for(int i = 0; i < numOfCan; ++i){
        oCanFile << candidates[i].id << endl;
        oCanFile << candidates[i].password<<endl;
        oCanFile << candidates[i].forgetPassQ<<"\n";
        oCanFile << candidates[i].forgetPassA<<"\n";
        oCanFile << candidates[i].fName<<"\n";
        oCanFile << candidates[i].lName<<"\n";
        oCanFile << candidates[i].email<<"\n";
        oCanFile << candidates[i].phone<<"\n";
        oCanFile << candidates[i].age<<"\n";
        oCanFile << candidates[i].address<<"\n";
        oCanFile << candidates[i].profession<<"\n";
        oCanFile << candidates[i].about<<"\n";
        oCanFile << candidates[i].isCv<<"\n";
        if(candidates->isCv)
            oCanFile << candidates[i].CV<<"\n";
        oCanFile << candidates[i].numOfSub<<"\n";
        for(int j = 0; j < candidates[i].numOfSub; ++j) {
            oCanFile << candidates[i].submissions[j].idOfJob<<"\n";
            oCanFile << candidates[i].submissions[j].status<<"\n";
        }
    }
    oCanFile.close();
}

void ManagementSystem::mainMenu() {
    int choice = -2;

    while (choice != 0 && choice != 1 && choice != 2) {
        cout << "signUp (1)\nlogIn (2)\nExit (0)\n";
        if (!(cin >> choice)) {
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            choice = -2;
        }
    }

    if(choice == 0)
        return;
    int type = -2;
    while (type != 0 && type != 1 && type != 2) {
        cout << "Employer (1) \nCandidate (2)\nExit (0)\n";
        if(!(cin >> type)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            type = -2;
        }
    }
    if(type == 0)
        return;
    if(choice == 1){
        if(type == 1)
            signUpEmp();
        else
            signUpCan();
    }
    else
        logIn(type);
}

char* ManagementSystem::setPass() {
    char pass [17];
    char pass1[17];

    cout << "Enter password - At least 1 uppercase letter, 1 lowercase letter, number:\n" ;
    cin >> pass;

    bool ifValid= false;
    while (!ifValid){

        bool uppercase = false;
        bool lowercase = false;
        bool digit = false;
        for (int i=0;pass[i]!='\0';i++) {
            if (pass[i]>='A'&& pass[i]<='Z') {
                uppercase = true;
            }
            if (pass[i]>='a'&& pass[i]<='z') {
                lowercase = true;
            }
            if (pass[i]>='0' && pass[i]<='9') {
                digit = true;
            }
        }

        ifValid = uppercase && lowercase && digit;

        if (!ifValid) {
            cout << "Invalid password. Try again." << endl;
            cin>>pass;
        }

    }
    cout << "Confirm password: \n";
    cin >> pass1;
    while (strcmp(pass,pass1) != 0) {
        cout << "Passwords do not match. Please try again." << endl;
        cin>>pass1;
    }
    char* passs = new char [strlen(pass)+1];
    strcpy(passs, pass);
    return passs;

}

void ManagementSystem:: signUpEmp(){
    char id [20];
    int Q ;
    char A [100];
    bool exist = false;

    cout << "Enter ID:\n" ;
    cin >> id ;

    for (int i = 0; id[i] != '\0'; i++) {
        if (id[i] < '0' || id[i] > '9'||strlen(id) != 9 || cin.fail()) {
            cout << "Invalid input. Please enter your ID including a check digit:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> id;
            i = -1;
        }
    }

    for (int i = 0; i < numOfEmp; ++i) {
        if(strcmp(employers[i].id, id) == 0)
            exist = true;
    }
    if(exist){
        cout << "User already exists in the system,\n"
                "Try logging in or registering with a different ID\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        mainMenu();
    }

    char* pass = setPass();

    cout << "Choose a question for safety:\n "
            "1 - The name of your paternal grandfather\n"
            "2 - Your favorite pet\n"
            "3 - Date of your birthday\n"
            "4 - Your favorite color\n"
            "5 - The date of your wedding anniversary\n";
    cin >> Q;

    while (Q < 1 || Q > 5 || cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Try again, enter your choose:\n" ;
        cin >> Q;
    }

    switch (Q) {
        case 1:
            cout << "What name of your paternal grandfather?\n";
            break;
        case 2:
            cout << "What is your favorite pet?\n";
            break;
        case 3:
            cout << "What the date of your birth?\n";
            break;
        case 4:
            cout << "What is your favorite color?\n";
            break;
        case 5:
            cout << "What the date of your wedding anniversary?\n";
            break;
    }

    cout << "Enter your answer:" <<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(A,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(A, 100);
    }

    Employer e(id, pass, Q, A);
    Employer* tmp = new Employer[numOfEmp+1];
    for(int i = 0; i< numOfEmp; ++i){
        tmp[i] = employers[i];
    }
    tmp[numOfEmp] = e;
    numOfEmp++;
    delete [] employers;
    employers = tmp;

    cout <<" The registration was successful\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";

    mainMenu();
}

void ManagementSystem:: signUpCan(){
    char id [11];
    int Q ;
    char A [100];
    char fName [200] ;
    char lName [200];
    char email [200];
    char phone [12];
    char address [200];
    char profession [200];
    int age ;
    char about [500];
    bool exist = false;


    cout << "Enter ID:\n" ;
    cin >> id ;

    for (int i = 0; id[i] != '\0'; i++) {
        if (id[i] < '0' || id[i] > '9'||strlen(id) != 9 || cin.fail()) {
            cout << "Invalid input. Please enter your ID including a check digit:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> id;
            i = -1;
        }
    }

    for (int i = 0; i < numOfCan; ++i) {
        if(strcmp(candidates[i].id, id) == 0)
            exist = true;
    }
    if(exist){
        cout << "User already exists in the system,\n"
                "Try logging in or registering with a different ID\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        mainMenu();
    }

    char* pass = setPass();

    cout << "Choose a question for safety:\n"
            "1 = The name of your paternal grandfather\n"
            "2 = Your favorite pet\n"
            "3 = Date of your birthday\n"
            "4 = Your favorite color\n"
            "5 = The date of your wedding anniversary\n";
    cin >> Q;

    while (Q < 1 || Q > 5 || cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Try again, enter your choose:\n" ;
        cin >> Q;
    }
    switch (Q) {
        case 1:
            cout << "What name of your paternal grandfather?\n";
            break;
        case 2:
            cout << "What is your favorite pet?\n";
            break;
        case 3:
            cout << "What the date of your birth?\n";
            break;
        case 4:
            cout << "What is your favorite color?\n";
            break;
        case 5:
            cout << "What the date of your wedding anniversary?\n";
            break;
    }
    cout << "Enter your answer:" <<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(A,100);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(A, 100);
    }

    cout << "Your first name:" <<endl;
    cin.getline(fName,200);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(fName, 200);
    }


    cout << "Your last name:" <<endl;
    cin.getline(lName,200);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(lName, 200);
    }

    cout << "Enter your email:"<<endl;
    cin.get(email, 20);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool isValid = false;

    while (!isValid) {
        bool hasAt = false;
        bool hasDot = false;
        bool noSpaces = true;

        for (int i = 0; email[i] != '\0'; ++i) {
            if (email[i] == '@') {
                hasAt = true;
            }
            if (email[i] == '.') {
                hasDot = true;
            }
            if (email[i] == ' ') {
                noSpaces = false;
            }
        }

        isValid = hasAt && hasDot && noSpaces;

        if (!isValid) {
            cout << "Invalid email. Try again:" << endl;
            cin.get(email, 20);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    cout << "Your phone number:" <<endl;
    cin>>phone;

    for (int i = 0; phone[i] != '\0'; i++) {
        if (phone[i] < '0' || phone[i] > '9'||strlen(phone) != 10 || cin.fail()) {
            cout << "Invalid input. Please enter your phone:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> phone;
            i = -1;
        }
    }
    cout << "Your age:" <<endl;
    cin>>age;
    while (age< 0 || age>200 || cin.fail()) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Try again, Your age:" <<endl;
        cin >> age;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Your address:" <<endl;
    cin.getline(address,200);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(address, 200);
    }


    cout << "Your profession:" <<endl;
    cin.getline(profession,200);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(profession, 200);
    }


    cout << "Tell a little about yourself:" <<endl;
    cin.getline(about,500);
    while (cin.fail()){
        cout<< "Invalid input, Try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(about, 500);
    }

    Candidate c(id, pass, Q, A, fName, lName, email, phone, age, address, profession, about);

    string cv;
    cout << "If you want to submit your (or press Enter to skip): \n";
    getline(cin, cv);
    if(!cv.empty()) {
        delete [] c.CV;
        c.CV = new char[cv.size() + 1];
        strcpy(c.CV, cv.c_str());
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        c.isCv= true;
    }

    Candidate* tmp = new Candidate[numOfCan+1];
    for(int i = 0; i< numOfCan; ++i){
        tmp[i] = candidates[i];
    }
    tmp[numOfCan] = c;
    numOfCan++;
    delete [] candidates;
    candidates = tmp;

    mainMenu();
}

void ManagementSystem:: logIn(int type){
    int ch = 0;
    char pass [17];
    char id [11];
    bool exists = false;
    int index;
    cout << "Enter your ID:\n";
    cin >> id;
    cout << "Enter your password:\n";
    cin >> pass ;

    if(type == 1) {
        for (int i = 0; i < numOfEmp; ++i) {
            if (strcmp(employers[i].id, id) == 0) {
                exists = true;
                index = i;
                if (strcmp(employers[i].password, pass) == 0) {
                    mainEmp(employers[i]);
                    return;
                }
                i = numOfEmp;
            }
        }
    }
    else{
        for(int i = 0; i < numOfCan; ++i) {
            if (strcmp(candidates[i].id, id) == 0) {
                exists = true;
                index = i;
                if (strcmp(candidates[i].password, pass) == 0) {
                    mainCan(candidates[i]);
                    return;
                }
                i = numOfCan;
            }
        }
    }
    while (ch != 1 && ch != 2) {
        cout << "One of the credentials is incorrect\nTry again (1)\nForget password (2)\n";
        cin >> ch;
    }
    if(ch == 1)
        logIn(type);
    else
        forgetPassword(type, exists, index);
}

bool ManagementSystem:: forgetPassword(int type, bool exists, int index) {

    if (exists) {
        char pass [17];
        char A [100];
        if (type == 1) {
            switch (employers[index].forgetPassQ) {
                case 1:
                    cout << "What name of your paternal grandfather?\n";
                    break;
                case 2:
                    cout << "What is your favorite pet?\n";
                    break;
                case 3:
                    cout << "What the date of your birth?\n";
                    break;
                case 4:
                    cout << "What is your favorite color?\n";
                    break;
                case 5:
                    cout << "What the date of your wedding anniversary?\n";
                    break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(A,100);
            while (cin.fail()){
                cout<< "Invalid input, Try again:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.getline(A, 100);
            }
            if (strcmp(A, employers[index].forgetPassA) == 0) {
                employers[index].setPassword(setPass());
                cout << "The password has been changed successfully\n";
                cout << "--------------------------------------------------------------------------------------------------------------\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
                cout << "--------------------------------------------------------------------------------------------------------------\n";

                mainMenu();
            }
        } else {
            switch (candidates[index].forgetPassQ) {
                case 1:
                    cout << "What name of your paternal grandfather?\n";
                    break;
                case 2:
                    cout << "What is your favorite pet?\n";
                    break;
                case 3:
                    cout << "What the date of your birth?\n";
                    break;
                case 4:
                    cout << "What is your favorite color?\n";
                    break;
                case 5:
                    cout << "What the date of your wedding anniversary?\n";
                    break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(A,100);
            while (cin.fail()){
                cout<< "Invalid input, Try again:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.getline(A, 100);
            }
            if (strcmp(A, candidates[index].forgetPassA) == 0) {
                candidates[index].setPassword(setPass());
                cout << "The password has been changed successfully\n";
                cout << "--------------------------------------------------------------------------------------------------------------\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
                cout << "--------------------------------------------------------------------------------------------------------------\n";
                mainMenu();
            }
        }
    }
    else{
        cout << "User does not exist in the system\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        mainMenu();
    }
}

void ManagementSystem:: mainEmp(Employer& employer) {
    int choice = 4;
    int choose = -2;
    int index = -2;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
        cout << "Add job (1)\nJobs history from the old to the new (2)\nJobs history sorted by status (3)\nExit (0)\n ";
        cin >> choice;
    }
    if(choice == 0) {
        mainMenu();
    }
    if (choice == 1) {
        if (employer.addJob(ID)) {
            numOfJobs++;
            ID++;
            mainEmp(employer);
        }
    }
    else if (choice == 3) {
        employer.sortJobs();
        mainEmp(employer);
    }
    else if (choice == 2){
            employer.printJobs();
            while (index < 0 || index > numOfJobs) {
                cout << "Enter number of job or 0 to exit:\n";
                if (!(cin >> index)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    index = -3;
                }
            }
            if (index == 0) {
                mainEmp(employer);
            }
            else {
                index--;
                choice = 4;
                while (choice != 1 && choice != 2 && choice != 3) {
                    cout << "Delete job (1)\nUpdate job (2)\nSee candidate's profiles (3)\nExit (0)\n";
                    if (!(cin >> choice)) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                if (choice == 0) {
                    mainEmp(employer);
                }
                if (choice == 1) {
                    while (choose != 1 && choose != 2 && choose != 0) {
                        cout << "Do you want to delete the job permanently (1) or temporarily (2)?\nExit (0)\n";
                        if (!(cin >> choose)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    if (choose == 0) {
                        mainEmp(employer);
                    }
                    if (choose == 1) {
                        int safe = 0;
                        while (safe != 1 && safe != 2 && safe != 0) {
                            cout << "Are you sure? (yes (1)/no (2))\nExit (0)\n";
                            if (!(cin >> safe)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        }
                        if (safe == 0) {
                            mainEmp(employer);
                        }
                        if (safe == 1) {
                            employer.deleteJob(index);
                            numOfJobs--;
                        }
                        else
                            cout << "The job was not deleted\n";
                        mainEmp(employer);
                    } else if (choose == 2)
                        employer.jobs[index].setStatus(false);
                }
                else if (choice == 2) {
                    employer.jobs[index].updateJob();
                    mainEmp(employer);
                }
                else if (choice == 3) {
                    int prof = -1;
                    employer.jobs[index].printSubPro(candidates, numOfCan);

                    while (prof < 0 || prof > employer.jobs[index].numOfSub) {
                        cout << "Enter number of profile to reject his request\nExit (0)";
                        if (!(cin >> prof)) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    if (prof == 0) {
                        mainEmp(employer);
                    }
                    prof--;
                    for (int i = 0; i < numOfCan; ++i)
                        if (strcmp(candidates[i].id, employer.jobs[index].idOfSub[prof]) == 0)
                            for (int j = 0; j < candidates[i].numOfSub; ++i)
                                if (candidates[i].submissions[j].idOfJob == employer.jobs[index].id)
                                    candidates[i].submissions[j].setStatus(false);

                    char **tmp = new char *[employer.jobs[index].numOfSub - 1];
                    for (int i = 0; i < prof; ++i)
                        strcpy(tmp[i], employer.jobs[index].idOfSub[i]);
                    for (int i = prof + 1; i < employer.jobs[index].numOfSub; ++i)
                        strcpy(tmp[i - 1], employer.jobs[index].idOfSub[i]);
                    delete[] employer.jobs[index].idOfSub;
                    employer.jobs[index].idOfSub = tmp;

                    cout<<"You have successfully rejected the request, the candidate will receive your reply as soon as possible\n";
                    cout << "--------------------------------------------------------------------------------------------------------------\n";
                }
        }
    }
}

void ManagementSystem:: mainCan(Candidate& candidate){
    int choice = -1;
    int choose = -1;
    int index = -1;
    int safe = -1;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0 ) {
        cout << "Search job (1)\nSubmission history (2)\nSubmission history by status (3)\nUpdate your profile (4)\nExit (0)\n";
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if(choice == 0) {
        mainMenu();
        return;
    }
    if(choice == 1) {
        searchJob(candidate);
    }
    else if(choice == 4){
        candidate.updateDetails();
        mainCan(candidate);
    }
    else{
        if(choice == 2){
            printSubOfCan(candidate);
        }
        else if (choice == 3) {
            printSortSub(candidate);
        }
        if(candidate.numOfSub!=0){
            while (choose < 0 || choose > candidate.numOfSub) {
                cout << "Enter number of submission to delete it or 0 to exit:\n";
                if (!(cin >> choose)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            if(choose == 0)
                mainCan(candidate);
            else{
                while (safe != 1 && safe != 2) {
                    cout << "Are you sure? (yes (1)/no (2)):\n";
                    if (!(cin >> safe)) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                if(safe == 2) {
                    cout << "The submission was not deleted\n";
                    cout << "--------------------------------------------------------------------------------------------------------------\n";
                    mainCan(candidate);
                }
                else {
                    choose--;
                    int id = candidate.deleteApply(choose);
                    for (int i = 0; i < numOfEmp; ++i)
                        for (int j = 0; j < employers[i].jobsNum; ++j) {
                            if (employers[i].jobs[j].id == id)
                                employers[i].jobs[j].deleteSub(candidate.id);
                        }
                    cout << "The submission has been successfully deleted, your profile is no longer available to the employer\n";
                    cout << "--------------------------------------------------------------------------------------------------------------\n";
                    mainCan(candidate);
                }
            }
        }
        mainCan(candidate);
    }
}

void ManagementSystem:: searchJob(Candidate& candidate){
    Job* arr = new Job[numOfJobs];
    int index = 0;
    for(int i = 0; i < numOfEmp; ++i){
        for (int j = 0; j < employers[i].jobsNum; ++j) {
            if(employers[i].jobs[j].status)
                arr[index] =  employers[i].jobs[j];
                ++index;
        }
    }
    int t = -1, h = -1, e = -1, a = -1, age = -1, s = -1, r = -1;

    cout << "For each field select the desired filter, if you do not want to filter this field, press 0:\n";

    while (t != 0 && t != 1 && t != 2) {
        cout<< "Are you interested in a full-time (1) or part-time (2) job? (1/2)\n";
        if(!(cin >> t)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (h != 0 && h != 1 && h != 2) {
        cout<< "Are you interested in a morning (1) or evening (2) job? (1/2)\n";
        if(!(cin >> h)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (e != 0 && e != 1 && e != 2 && e != 3) {
        cout<< "Are you interested in a job that requires no experience (1), "
               "requires little experience (less than three years) (2)"
               " or requires more than 3 years of experience (3)? (1/2/3)\n";
        if(!(cin >> e)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (a != 0 && a != 1 && a != 2 && a != 3) {
        cout<< "Are you interested in a job in the north (1), south (2) or center (3)? (1/2/3)\n";
        if(!(cin >> a)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (age != 0 && age != 1 && age != 2 && age != 3) {
        cout<< "You are interested in a job for ages up to 18 (1), 18-24 (2) or over 24 (3)?  (1/2/3)\n";
        if(!(cin >> age)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (s != 0 && s != 1 && s != 2 && s != 3) {
        cout<< "Are you interested in a job for a specific audience (soldier (1) /student (2) /pupil (3))? (1/2/3)\n";
        if(!(cin >> s)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (r != 0 && r != 1 && r != 2 ) {
        cout<< "Are you interested in a short (1) or long (2) term job? (1/2)\n";
        if(!(cin >> r)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int index1 = 0;

    for (int i = 0; i < index; ++i) {
        if((arr[i].jobType == t || t == 0) &&
        (arr[i].age == age || age == 0) &&
        (arr[i].experience == e || e == 0) &&
        (arr[i].jobArea == a || a == 0) &&
        (arr[i].jobFor == s || s == 0) &&
        (arr[i].jobHours == h || h == 0) &&
        (arr[i].jobRange == r || r == 0)){
            cout << index1 + 1 << ".\n";
            arr[i].printForCand();
            ++index1;
        }
    }

    if (index1 == 0) {
        cout << "No suitable jobs were found for you\n";
        mainCan(candidate);
    }
    addApply(arr, index, candidate);
}

void ManagementSystem::addApply(Job *jobs, int sum, Candidate& candidate) {
    int index = -1;
    while (index < 0 || index > sum) {
        cout << "Enter number of job to apply or 0 to exit:\n";
        if (!(cin >> index)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (index == 0)
        mainCan(candidate);
    else {
        index--;
        candidate.addApply(jobs[index].id);
        for (int i = 0; i < numOfEmp; ++i) {
            for (int j = 0; j < employers[j].jobsNum; ++j) {
                if (jobs[index].id == employers[i].jobs[j].id) {
                    employers[i].jobs[j].addSub(candidate.id);
                    i = numOfEmp;
                }
            }
        }
    }
    cout << "\nWe have submitted your request,\n"
            "The employer will contact you soon!\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";

    delete [] jobs;
    mainCan(candidate);
}

void ManagementSystem::printSubOfCan(Candidate& candidate) {
    if(candidate.numOfSub == 0)
        cout << "You have not applied yet\n";
    else
        for(int i = 0; i < candidate.numOfSub; ++i){
            cout << i +1 << ".\n";
            printSub(candidate.submissions[i]);
        }
}

void ManagementSystem::printSortSub(Candidate& candidate){
    if(candidate.numOfSub == 0){
        cout<<"You have no submissions \n";
        return;
    }

    cout << "The apply In process: \n";
    for (int i = 0; i < candidate.numOfSub ; ++i) {
        if (candidate.submissions[i].isStatus()) {
            printSub(candidate.submissions[i]);
        }
    }
    cout << "The apply Postponed: \n";
    for (int i = 0; i < candidate.numOfSub ; ++i) {
        if (!candidate.submissions[i].isStatus()) {
            printSub(candidate.submissions[i]);
        }
    }
}

void ManagementSystem:: printSub(Apply& sub){
    Job* arr = new Job[numOfJobs];
    int index = 0;
    for(int i = 0; i < numOfEmp; ++i){
        for (int j = 0; j < employers[i].jobsNum; ++j) {
            if(employers[i].jobs[j].status) {
                arr[index] = employers[i].jobs[j];
                ++index;
            }
        }
    }
    cout << "Status: ";
    if(sub.status) {
        cout << "In process\n";
    }
    else{
        cout << "Postponed\n";
    }
    cout << "Job details: \n";
    for (int i = 0; i < numOfJobs; ++i) {
        if(arr[i].id == sub.idOfJob){
            arr[i].printForCand();
            i = numOfEmp;
        }
    }
}