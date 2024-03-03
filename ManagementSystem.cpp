//
// Created by Student on 2/27/2024.
//
#include <limits>
#include "ManagementSystem.h"

using namespace std;


ManagementSystem:: ManagementSystem(){

    employers = nullptr;
    candidates = nullptr;
    numOfEmp = 0;
    numOfCan = 0;
    numOfJobs = 0;

    getEmp();
    getCan();

}
ManagementSystem:: ~ManagementSystem(){
    pushEmp();
    pushCan();
    delete [] employers;
    delete [] candidates;
}
void ManagementSystem::getEmp() {
    char id [20];
    char pass [20];
    int q;
    char a[100];
    char f1 [20];
    char f2 [20];
    char f3 [20];
    char f4 [20];
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
        employersFile >> a;

        Employer employer(id, pass, q, a);

        employersFile >> employer.jobsNum;
        numOfJobs += employer.jobsNum;
        employer.jobs = new Job[employer.jobsNum];

        for (int j = 0; j < employer.jobsNum; ++j){

            employersFile >> employer.jobs[j].id;

            employersFile >> f1 ;
            cout << f1 << endl;
            employer.jobs[j].setBusinessName(f1);

            employersFile >> f2 ;
            employer.jobs[j].setAddress(f2);

            employersFile >> f3 ;
            employer.jobs[j].setSalary(f3);

            employersFile >> f4 ;
            employer.jobs[j].setAbout(f4);

            employersFile >> f5 ;
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
    char id [20];
    char pass [20];
    int q;
    char a[100];
    char f1 [20];
    char f2 [20];
    char f3 [20];
    char f4 [20];
    int age;
    char f5 [200];
    char f6 [20];
    char f7 [20];
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
        CandidateFile >> a;
        CandidateFile >> f1 ;
        CandidateFile >> f2 ;
        CandidateFile >> f3 ;
        CandidateFile >> f4 ;
        CandidateFile >> age;
        CandidateFile >> f5 ;
        CandidateFile >> f6 ;
        CandidateFile >> f7 ;
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
//        if (oCanFile.fail()) {
//            if (oCanFile.bad()) {
//                // Fatal error occurred, like disk failure
//                cout << "Fatal error occurred during file operation." << endl;
//            } else if (oCanFile.fail()) {
//                // Logical error occurred, like invalid data format
//                cout << "Logical error occurred during file operation." << endl;
//            } else if (oCanFile.eof()) {
//                // End-of-file reached unexpectedly
//                cout << "End-of-file reached unexpectedly." << endl;
//            }
//        }
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
//        candidates[i].printDetails();
//        oCanFile.flush();
    }
    oCanFile.close();
}
void ManagementSystem::mainMenu() {
    int choice = 3;
    while (choice != 0 && choice != 1 && choice != 2) {
        cout << "signUp (1)\nlogIn (2)\nExit (0)\n";
        if(!(cin >> choice)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if(choice == 0)
        return;
    int type = 0;
    while (type != 1 && type != 2) {
        cout << "Employer (1) \nCandidate (2)\n";
        if(!(cin >> type)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if(choice == 1){
        if(type == 1)
            signUpEmp();
        else
            signUpCan();
    }
    else
        logIn(type);
}
void ManagementSystem:: signUpEmp(){
    char id [11];
    char pass [17];
    char pass1[17];
    int Q ;
    char A [10];

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
    //todo checking if id exising

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
    //todo Checking whether the password is according to the rules
    //todo input password again for verify

    cout << "Choose a question for safety:\n "
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

    //todo print the question
    cout << "Enter your answer:" <<endl;
    cin >> A;

    Employer e(id, pass, Q, A);
    Employer* tmp = new Employer[numOfEmp+1];
    for(int i = 0; i< numOfEmp; ++i){
        tmp[i] = employers[i];
    }
    tmp[numOfEmp] = e;
    numOfEmp++;
    delete [] employers;
    employers = tmp;
    mainMenu();
}
void ManagementSystem:: signUpCan(){
    char id [11];
    char pass [17];
    char pass1[17];
    int Q ;
    char A [10];
    char fName [20] ;
    char lName [20];
    char email [40];
    char phone [12];
    char address [30];
    char profession [15];
    int age ;
    char about [200];

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
    //todo checking if id exising

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
    //todo Checking whether the password is according to the rules
    //todo input password again for verify

    cout << "Choose a question for safety:\n "
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

    //todo print the question
    cout << "Enter your answer:" <<endl;
    cin >> A;

    cout << "Your first name:" <<endl;
    cin >> fName;
    cout << "Your last name:" <<endl;
    cin >>lName ;
    cout << "Your email:" <<endl;
    cin >> email ;
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

    cout << "Your address:" <<endl;
    cin >> address ;
    cout << "Your profession:" <<endl;
    cin >> profession ;
    cout << "Tell a little about yourself:" <<endl;
    cin >> about;

    Candidate c(id, pass, Q, A, fName, lName, email, phone, age, address, profession, about);
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
        char A [17];
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
            cin >> A ;
            if (strcmp(A, employers[index].forgetPassA) == 0) {
                cout << "Enter new password: \n";
                cin >> pass ;
                employers[index].setPassword(pass);
                //todo verify of pass
                cout << "The password has been changed successfully\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
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
            cin >> A ;
            if (strcmp(A, candidates[index].forgetPassA) == 0) {
                cout << "Enter new password: \n";
                cin >>pass ;
                candidates[index].setPassword(pass);
                //todo verify of pass
                cout << "The password has been changed successfully\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
                mainMenu();
            }
        }
    }
    else{
        cout << "User does not exist in the system\n";
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
        return;
    }
    if (choice == 1) {
        if (employer.addJob(numOfJobs)) {
            numOfJobs++;
            mainEmp(employer);
        }
    }
    else if (choice == 2)
            employer.printJobs();
    else if (choice == 3)
            employer.sortJobs();
    while (index <= 0 || index > numOfJobs){
        cout << "Enter number of job or 0 to exit:\n";
        if(!(cin>>index)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (index == 0) {
        mainEmp(employer);
        return;
    }
    else {
        index--;
        choice = 4;
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Delete job (1)\nUpdate job (2)\nSee candidate's profiles (3)\nExit (0)\n";
            if(!(cin>>choice)){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if (choice == 0) {
            mainEmp(employer);
            return;
        }
        if (choice == 1) {
            while (choose != 1 && choose != 2 && choose != 0) {
                cout << "Do you want to delete the job permanently (1) or temporarily (2)?\nExit (0)\n";
                if(!(cin>>choose)){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            if (choose == 0) {
                mainEmp(employer);
                return;
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
                    return;
                }
                if (safe == 1)
                    employer.deleteJob(index);
                mainEmp(employer);
            }
            else if(choose == 2)
                employer.jobs[index].setStatus(false);
        }
        else if (choice == 2)
                employer.jobs[index].updateJob();
        else if (choice == 3) {
            int prof = -1;
            employer.jobs[index].printSubPro(candidates, numOfCan);

            while (prof <0 || prof > employer.jobs[index].numOfSub) {
                cout << "Enter number of profile to reject his request\nExit (0)";
                if (!(cin >> prof)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            if(prof == 0){
                mainEmp(employer);
                return;
            }

            prof--;
            for(int i = 0 ; i < numOfCan; ++i)
                if(strcmp(candidates[i].id, employer.jobs[index].idOfSub[prof]) == 0)
                    for(int j = 0; j < candidates[i].numOfSub; ++i)
                        if(candidates[i].submissions[j].idOfJob == employer.jobs[index].id)
                            candidates[i].submissions[j].setStatus(false);

            char** tmp = new char* [employer.jobs[index].numOfSub - 1];
            for(int i = 0; i < prof; ++i)
                strcpy(tmp[i], employer.jobs[index].idOfSub[i]);
            for(int i = prof+1; i < employer.jobs[index].numOfSub; ++i)
                strcpy(tmp[i - 1], employer.jobs[index].idOfSub[i]);
            delete [] employer.jobs[index].idOfSub;
            employer.jobs[index].idOfSub = tmp;
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
        int *arrId;
        int sum = searchJob(arrId);
        if (sum == 0)
            mainCan(candidate);
        while (index < 0 || index >= sum) {
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
            for (int i = 0; i < numOfEmp; ++i)
                for (int j = 0; j < employers[i].jobsNum; ++j)
                    if (arrId[index] == employers[i].jobs[j].id) {
                        candidate.addApply(arrId[index]);
                        employers[i].jobs[j].addSub(candidate.id);
                        i = numOfEmp;
                    }
        }
    }
    else if(choice == 4){
        candidate.updateDetails();
    }
    else{
        if(choice == 2){
            candidate.printSub();
        }
         else if (choice == 3) {
            candidate.printSortSub();
        }
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
            if(safe == 2)
                mainCan(candidate);
            else {
//                todo delete sub
                choose--;
                int id = candidate.deleteApply(choose);
                for (int i = 0; i < numOfEmp; ++i)
                    for (int j = 0; j < employers[i].jobsNum; ++j) {
                        if (employers[i].jobs[j].id == id)
                            employers[i].jobs[j].deleteSub(candidate.id);
                    }
            }
        }
    }
}
int ManagementSystem:: searchJob(int* arr){
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

    int index = 0;

    for (int i = 0; i < numOfEmp ; ++i) {
        for (int j = 0; j < employers[i].jobsNum; ++j)
            if(employers[i].jobs[j].status)
                if((employers[i].jobs[j].jobType == t || t == 0) && (employers[i].jobs[j].age == age || age == 0) && (employers[i].jobs[j].experience == e || e == 0))
                    if((employers[i].jobs[j].jobArea == a || a == 0) && (employers[i].jobs[j].jobFor == s || s == 0) && (employers[i].jobs[j].jobHours == h || h == 0) && (employers[i].jobs[j].jobRange == r || r == 0)){
                        cout << index + 1 << ".\n";
                        employers[i].jobs[j].printForCand();
                        ++index;
                        int* tmp = new int[index];
                        for(int k = 0; k < index -1; ++k)
                            tmp[k] = arr[k];
                        tmp[index-1] = employers[i].jobs[j].id;
                        delete [] arr;
                        arr = tmp;
                        }
    }

    if (index == 0)
        cout << "No suitable jobs were found for you\n";
    return index;
}
void ManagementSystem::print() {
    for (int i = 0; i < numOfEmp; ++i) {
        employers[i].printDetails();
    }

    for (int i = 0; i < numOfCan; ++i) {
        candidates[i].printDetails();
    }

}