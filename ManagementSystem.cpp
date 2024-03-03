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
    char f8 [200];
    int status;
    char f9 [200];

    int idJ;


    ifstream CandidateFile ("Candidate.csv");
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
        int age;
        CandidateFile >> f5 ;
        CandidateFile >> f6 ;
        CandidateFile >> f7 ;
        CandidateFile >> f8 ;


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
    this->print();
    ofstream oCanFile("Candidates.txt");
    if (!oCanFile) {
        cout << "The system have a big problem" << endl;

    }
    oCanFile << numOfCan << endl;
    for(int i = 0; i < numOfCan; ++i){
        oCanFile << candidates[i].id <<"\n";
        oCanFile << candidates[i].password<<"\n";
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
    int choice = 0;
    while (choice != 1 && choice != 2) {
        cout << "signUp (1)\nlogIn (2)\n";
        if(!(cin >> choice)){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
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
    int choose;
    int index;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
        cout << "Add job (1)\nJobs history from the old to the new (2)\nJobs history sorted by status (3)\nExit (0)\n ";
        cin >> choice;
    }
    if(choice == 0)
        return;
    if (choice == 1) {
//        if (employer.addJob(numOfJobs)) { //todo send id
//            cout <<"xcvgh\n";
//            Job *tmp = new Job[numOfJobs + 1];
//            cout <<"xcvgh\n";
//            for (int i = 0; i < numOfJobs; ++i)
//                tmp[i] = jobs[i];
//            cout <<"xcvgh\n";
//            tmp[numOfJobs] = employer.jobs[employer.jobsNum - 1];
//            cout <<"xcvgh\n";
//            numOfJobs++;
//            cout <<"xcvgh\n";
//            delete[] jobs;
//            cout <<"xcvgh\n";
//            jobs = tmp;
//            cout <<"xcvgh\n";
//            mainEmp(employer);
//            cout <<"xcvgh\n";
//        }
        mainEmp(employer);
    }
    else if (choice == 2)
            employer.printJobs();  //todo fix printforcand
    else if (choice == 3)
            employer.sortJobs();
    cout << "Enter number of job or 0 to exit:\n";
    cin >> index;
    if (index == 0) {
        mainEmp(employer);
        return;
    }
    else {
        index--;
        choice = 0;
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Delete job (1)\nUpdate job (2)\nSee candidate's profiles (3)\n";
            cin >> choice;
        }
        if (choice == 1) {
            cout << "Do you want to delete the job permanently (1) or temporarily (2)?\n";
            cin >> choose;
            if (choose == 1) {
                int sec;
                cout << "Are you sure? (yes (1)/no (2))\n";
                cin >> sec;
                if (sec == 1) {
                    if(employer.deleteJob(index)) {
//                        Job *tmp = new Job[numOfJobs - 1];
//                        for (int i = 0; i < numOfJobs; ++i) {
//                            if (jobs[i].id != employer.jobs[index].id) {
//                                tmp[i] = jobs[i];
//                                tmp[i].id = i + 1;
//                            } ///else
//
//                        }
//                        numOfJobs--;
//                        delete[] jobs;
//                        jobs = tmp;
                        mainEmp(employer);
                    }
                }
                else
                    mainEmp(employer);
            }
            else {
//                employer.jobs[index].setStatus(false);   todo chang status of job
//                for (int i = 0; i < numOfJobs; ++i)
//                    if (jobs[i].id == employer.jobs[index].id)
//                        jobs[i].status = false;
//                mainEmp(employer);
            }
        }
        else if (choice == 2) {
                employer.jobs[index].updateJob();
//                for (int i = 0; i < numOfJobs; ++i)
//                    if (jobs[i].id == employer.jobs[index].id)
//                        jobs[i] = employer.jobs[index];
//                mainEmp(employer);
            }
        else if (choice == 3) {
            int prof;
            employer.jobs[index].printSubPro(candidates, numOfCan);
            cout << "Enter number of profile to reject his request\n";
            cin >> prof;
            prof--;

            char** tmp = new char * [employer.jobs[index].numOfSub - 1];
            for(int i = 0; i < employer.jobs[index].numOfSub; ++i)
                if(i != prof)
                    strcpy(tmp[i], employer.jobs[index].idOfSub[i]);
            delete [] employer.jobs[index].idOfSub;
            employer.jobs[index].idOfSub = tmp;


            for(int i = 0 ; i < numOfCan; ++i)
                if(strcmp(candidates[i].id, employer.jobs[index].idOfSub[prof]) == 0)
                    for(int j = 0; j < candidates[i].numOfSub; ++i)
                        if(candidates[i].submissions[j].idOfJob == employer.jobs[index].id)
                            candidates[i].submissions->status = false;
        }

    }
}
void ManagementSystem:: mainCan(Candidate& candidate){
    int choice = 0;
    int choose = -1;
    int index = -1;
    int safe = 0;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout << "Search job (1)\nSubmission history (2)\nSubmission history by status (3)\nUpdate your profile (4)\n ";
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if(choice == 1){
        int sum = 0;// searchJob();
        while (index <= 0 || index >= sum) {
            cout << "Enter ID of job to apply or 0 to exit:\n";
            if (!(cin >> index)) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if(index == 0)
            mainCan(candidate);
        else{
//            todo add apply
//            for (int i = 0; i < numOfJobs; ++i) {
//                if (jobs[i].id == index) {
//                    candidate.addApply(index);
//                    jobs[i].addSub(candidate.id);
//                    i = numOfJobs;
//                }
//            }
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
                cout << "Are you sure? (yes (1)/no (2))\n";
                if (!(cin >> safe)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            if(safe == 2)
                mainCan(candidate);
            else {
//                todo delete sub
//                choose--;
//                int id = candidate.deleteApply(choose);
//                for (int i = 0; i < numOfJobs; ++i) {
//                    if (jobs[i].id == id)
//                        jobs[i].deleteSub(candidate.id);
//                }
            }
        }
    }
}
//int ManagementSystem:: searchJob(){
//    int t, h, e, a, age, s, r;
//
//    cout << "For each field select the desired filter, if you do not want to filter this field, press 0\n";
//
//    cout<< "Are you interested in a full-time (1) or part-time (2) job? (1/2)\n";
//    cin >> t;
//    if(t != 1 && t != 2)
//        t = 0;
//    cout<< "Are you interested in a morning (1) or evening (2) job? (1/2)\n";
//    cin >> h;
//    if(h != 1 && h != 2)
//        h = 0;
//    cout<< "Are you interested in a job that requires no experience (1), "
//           "requires little experience (less than three years) (2)"
//           " or requires more than 3 years of experience (3)? (1/2/3)\n";
//    cin >> e;
//    if(e != 1 && e != 2 && e != 3)
//        e = 0;
//    cout<< "Are you interested in a job in the north (1), south (2) or center (3)? (1/2/3)\n";
//    cin >> a;
//    if(a != 1 && a != 2 && a != 3)
//        a = 0;
//    cout<< "You are interested in a job for ages up to 18 (1), 18-24 (2) or over 24 (3)?  (1/2/3)\n";
//    cin >> age;
//    if(age != 1 && age != 2 && age != 3)
//        age = 0;
//    cout<< "Are you interested in a job for a specific audience (soldier (1) /student (2) /pupil (3))? (1/2/3)\n";
//    cin >> s;
//    if(s != 1 && s != 2 && s != 3)
//        s = 0;
//    cout<< "Are you interested in a short (1) or long (2) term job? (1/2)\n";
//    cin >> r;
//    if(r != 1 && r != 2)
//        r = 0;
//
//    int index = 0;
//
//    for (int i = 0; i < numOfJobs ; ++i) {
//        if(jobs[i].status){
//            if((jobs[i].jobType == t || t == 0) && (jobs[i].age == age || age == 0) && (jobs[i].experience == e || e == 0)){
//                if((jobs[i].jobArea == a || a == 0) && (jobs[i].jobFor == s || s == 0) && (jobs[i].jobHours == h || h == 0) && (jobs[i].jobRange == r || r == 0)){
//                    cout << index + 1 << ".\n";
//                    jobs->printForCand();
//                    ++index;
//                }
//            }
//        }
//    }
//    if (index == 0)
//        cout << "No suitable jobs were found for you\n";
//    return index;
//}
void ManagementSystem::print() {
    for (int i = 0; i < numOfEmp; ++i) {
        candidates[i].printDetails();
    }

    for (int i = 0; i < numOfCan; ++i) {
        candidates[i].printDetails();
    }

}