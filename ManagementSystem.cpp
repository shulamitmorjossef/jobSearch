//
// Created by Student on 2/27/2024.
//

#include "ManagementSystem.h"

using namespace std;
ManagementSystem::ManagementSystem(){

    char is [10];
    char passs [10];
    int qs;
    char as[10];
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
        employersFile >> is;
        employersFile >> passs;
        employersFile >> qs;
        employersFile >> as;

        char *id = new char[strlen(is) + 1];
        strcpy(id, is);
        char *pass = new char[strlen(passs) + 1];
        strcpy(pass, passs);
        int q = qs;
        char *a = new char[strlen(as) + 1];
        strcpy(a, as);
        Employer employer(id, pass, q, a);
        employers[i] = employer;
        employers[i].printDetails();

    }
    employersFile.close();


//    ofstream oc_file("Candidate.txt");
//    char ic [10];
//    char pacss [10];
//    char qc[10];
//    char ac[10];
//
//    ifstream CandidateFile ("Candidate.txt");
//    if (!CandidateFile) {
//        cout << "The system have a problem" << endl;
//        return;
//    }
//    if(CandidateFile.eof())
//        numOfCan = 0;
//    else
//        CandidateFile >> numOfCan;
//    this->candidates = new Candidate[numOfCan];
//    for(int i = 0 ; i < numOfCan; ++i) {
//        CandidateFile >> ic;
//        CandidateFile >> pacss;
//        CandidateFile >> qc;
//        CandidateFile >> ac;
//
//        char *idC = new char[strlen(ic) + 1];
//        strcpy(idC, ic);
//        char *passC = new char[strlen(pacss) + 1];
//        strcpy(passC, pacss);
//        char *qC = new char[strlen(qc) + 1];
//        strcpy(qC, qc);
//        char *aC = new char[strlen(ac) + 1];
//        strcpy(aC, ac);
//        Candidate candidate(idC, passC, qC, aC);
//        candidates[i] = candidate;
//        candidates[i].printDetails();
//    }
//    candidates[0].printDetails();
//    CandidateFile.close();

}
ManagementSystem:: ~ManagementSystem(){

    ofstream oEmpFile("Employers.txt");
    if (!oEmpFile) {
        cout << "The system have a big problem" << endl;
        return;
    }
    oEmpFile << numOfEmp;
    for(int i = 0; i < numOfEmp; ++i){
        oEmpFile << employers[i].id <<" ";
        oEmpFile << employers[i].password;
        oEmpFile << employers[i].forgetPassQ;
        oEmpFile << employers[i].forgetPassA;
        oEmpFile << employers[i].jobsNum;
        for(int j = 0; j < employers[i].jobsNum; ++j) {
            oEmpFile << employers[i].jobs[j].id;
            oEmpFile << employers[i].jobs[j].businessName;
            oEmpFile << employers[i].jobs[j].jobProfession;
            oEmpFile << employers[i].jobs[j].address;
            oEmpFile << employers[i].jobs[j].salary;
            oEmpFile << employers[i].jobs[j].about;
            oEmpFile << employers[i].jobs[j].jobType;
            oEmpFile << employers[i].jobs[j].jobHours;
            oEmpFile << employers[i].jobs[j].experience;
            oEmpFile << employers[i].jobs[j].jobArea;
            oEmpFile << employers[i].jobs[j].jobRange;
            oEmpFile << employers[i].jobs[j].status;
            oEmpFile << employers[i].jobs[j].numOfSub;
            for(int k = 0; k < employers[i].jobs[j].numOfSub; ++k){
                oEmpFile << employers[i].jobs[j].idOfSub[k];

            }
        }
    }
    oEmpFile.close();

}

void ManagementSystem::mainMenu() {
    int choice = 0;
    while (choice != 1 && choice != 2) {
        cout << "signUp (1)\nlogIn (2)\n";
        cin >> choice;
    }
    int type = 0;
    while (type != 1 && type != 2) {
        cout << "Employer (1) \nCandidate (2)\n";
        cin >> type;
    }
    if(choice == 1){
        if(type == 1){
            signUpEmp();
        } else{
            signUpCan();
        }
    }
    else{
        logIn(type);
    }
}
void ManagementSystem:: signUpEmp(){
    char id [11];
    char pass [17];
    int Q ;
    char A [10];

    cout << "Enter ID:\n" ;
    cin >> id ;

    //todo checking if id exising

    cout << "Enter password - At least 1 uppercase letter, 1 lowercase letter, number:\n" ;
    cin >> pass;

    //todo Checking whether the password is according to the rules
    //todo input password again for verify

    cout << "Choose a question for safety:\n "
            "1 = The name of your paternal grandfather\n"
            "2 = Your favorite pet\n"
            "3 = Date of your birthday\n"
            "4 = Your favorite color\n"
            "5 = The date of your wedding anniversary\n";
    cin >> Q;
    while(Q < 1 || Q > 5){
        cout << "Enter your choose:\n" ;
        cin >> Q;
    }
    //todo print the question
    cout << "Enter your answer:\n";
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
    int Q ;
    char A [10];
    char fName [20] ;
    char lName [20];
    char email [40];
    char phone [11];
    char address [30];
    char profession [15];
    int age ;
    char about [200];

    cout << "Enter ID:\n" ;
    cin >> id ;

    //todo checking if id exising

    cout << "Enter password - At least 1 uppercase letter, 1 lowercase letter, number:\n" ;
    cin >> pass;

    //todo Checking whether the password is according to the rules
    //todo input password again for verify

    cout << "Choose a question for safety:\n "
            "1 = The name of your paternal grandfather\n"
            "2 = Your favorite pet\n"
            "3 = Date of your birthday\n"
            "4 = Your favorite color\n"
            "5 = The date of your wedding anniversary\n";
    cin >> Q;
    while(Q < 1 || Q > 5){
        cout << "Enter your choose:\n" ;
        cin >> Q;
    }
    //todo print the question
    cout << "Enter your answer:\n" <<endl;
    cin >> A;

    cout << "Your first name:" <<endl;
    cin >> fName;
    cout << "Your last name:" <<endl;
    cin >>lName ;
    cout << "Your email:" <<endl;
    cin >> email ;
    cout << "Your phone number:" <<endl;
    cin.get(phone,11);
    cout << "Your age:" <<endl;
    cin >> age;
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

    candidates = new Candidate[numOfCan];
    for(int i = 0; i< numOfCan; ++i){
        candidates[i] = tmp[i] ;
    }

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


//    char* pass = new char [strlen(passs)+1];
//    strcpy(pass, passs);


    if(type == 1) {
        for (int i = 0; i < numOfEmp; ++i) {
            if (strcmp(employers[i].id, id) == 0) {
                exists = true;
                index = i;
//                cout<< employers[i].id <<endl;
//                cout << employers[i].password<<endl;
//                cout << pass <<endl;
////                employers[i].printDetails();
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
                i = numOfCan;
                if (strcmp(candidates[i].password, pass) == 0) {
                    mainCan(candidates[i]);
                    return;
                }
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
        char *pass;
        if (type == 1) {
            char *A = new char[strlen(employers[index].forgetPassA)];
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
            cin.get(A, 10);
            if (strcmp(A, employers[index].forgetPassA) == 0) {
                cout << "Enter new password: \n";
                cin.get(pass, 17);
                employers[index].setPassword(pass);
                //todo verify of pass
                cout << "The password has been changed successfully\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
                mainMenu();
            }
        } else {
            char *A = new char[strlen(candidates[index].forgetPassA)];
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
            cin.get(A, 10);
            if (strcmp(A, candidates[index].forgetPassA) == 0) {
                cout << "Enter new password: \n";
                cin.get(pass, 17);
                candidates[index].setPassword(pass);
                //todo verify of pass
                cout << "The password has been changed successfully\n";
                mainMenu();
            } else {
                cout << "The authentication attempt failed\n";
                mainMenu();
            }
        }
    } else{
        cout << "User does not exist in the system\n";
        mainMenu();
    }
}
void ManagementSystem:: mainEmp(Employer employer) {
    int choice = 0;
    int choose;
    int index;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout << "Add job (1)\nJobs history from the old to the new (2)\nJobs history sorted by status (3)\n ";
        cin >> choice;
    }
    if (choice == 1)
        if (employer.addJob(numOfJobs)) {
            Job *tmp = new Job[numOfJobs + 1];
            for (int i = 0; i < numOfJobs; ++i)
                tmp[i] = jobs[i];
            tmp[numOfJobs] = employer.jobs[employer.jobsNum - 1];
            numOfJobs++;
            delete[] jobs;
            jobs = tmp;
            mainEmp(employer);
            return;
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
                char sec;
                cout << "Are you sure (y/n)?\n";
                cin >> sec;
                if (sec == 'y') {
                    if (employer.deleteJob(index)) {
                        Job *tmp = new Job[numOfJobs - 1];
                        for (int i = 0; i < numOfJobs; ++i)
                            if (jobs[i].id != employer.jobs[index].id) {
                                tmp[i] = jobs[i];
                                tmp[i].id = i + 1;
                            }
                        numOfJobs--;
                        delete[] jobs;
                        jobs = tmp;
                        mainEmp(employer);
                    }
                } else
                    mainEmp(employer);
            } else {
                employer.jobs[index].setStatus(false);
                for (int i = 0; i < numOfJobs; ++i)
                    if (jobs[i].id == employer.jobs[index].id)
                        jobs[i].status = false;
            }
        }
        else if (choice == 2) {
                employer.jobs[index].updateJob();
                for (int i = 0; i < numOfJobs; ++i)
                    if (jobs[i].id == employer.jobs[index].id)
                        jobs[i] = employer.jobs[index];
                mainEmp(employer);
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
void ManagementSystem:: mainCan(Candidate candidate){

}