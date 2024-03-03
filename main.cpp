#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ManagementSystem.h"
//#include "Employer.h"
#include <cmath>
using namespace std;
#include <limits>

int main() {
//    Employer e("1", "1", 1, "1");
//    Employer e1("6562", "szfdxgcvb", 2, "gfxcg5");
//    Employer e2("206999999", "903", 3 , "this");
//    int numOfEmp;
//    numOfEmp = 3;
//    Employer* employers = new Employer[3];
//    employers[0] = e;
//    employers[1] = e1;
//    employers[2] = e2;
//    ofstream oEmpFile("Employers.txt");
//    if (!oEmpFile) {
//        cout << "The system have a big problem" << endl;
//    }
//    oEmpFile << numOfEmp << endl;
//    for(int i = 0; i < numOfEmp; ++i){
//        oEmpFile << employers[i].id <<"\n";
//        oEmpFile << employers[i].password<<"\n";
//        oEmpFile << employers[i].forgetPassQ<<"\n";
//        oEmpFile << employers[i].forgetPassA<<"\n";
//        oEmpFile << employers[i].jobsNum<<"\n";
//        for(int j = 0; j < employers[i].jobsNum; ++j) {
//            oEmpFile << employers[i].jobs[j].id<<"\n";
//            oEmpFile << employers[i].jobs[j].businessName<<"\n";
//            oEmpFile << employers[i].jobs[j].jobProfession<<"\n";
//            oEmpFile << employers[i].jobs[j].address<<"\n";
//            oEmpFile << employers[i].jobs[j].salary<<"\n";
//            oEmpFile << employers[i].jobs[j].about<<"\n";
//            oEmpFile << employers[i].jobs[j].jobType<<"\n";
//            oEmpFile << employers[i].jobs[j].jobHours<<"\n";
//            oEmpFile << employers[i].jobs[j].experience<<"\n";
//            oEmpFile << employers[i].jobs[j].jobArea<<"\n";
//            oEmpFile << employers[i].jobs[j].age<<"\n";
//            oEmpFile << employers[i].jobs[j].jobFor<<"\n";
//            oEmpFile << employers[i].jobs[j].jobRange<<"\n";
//            oEmpFile << employers[i].jobs[j].status<<"\n";
//            oEmpFile << employers[i].jobs[j].numOfSub<<"\n";
//            for(int k = 0; k < employers[i].jobs[j].numOfSub; ++k){
//                oEmpFile << employers[i].jobs[j].idOfSub[k]<<"\n";
//            }
//        }
//    }
//    oEmpFile.close();

    Candidate c("1", "1", 1, "1", "1", "1", "1", "1", 1, "1", "1", "1");
    Candidate c1("2", "2", 2, "2", "2", "2", "2", "2", 2, "2", "2", "2");
    Candidate c2("2", "2", 2, "2", "2", "2", "2", "2", 2, "2", "2", "2");
    Candidate* candidates = new Candidate[3];
    int numOfCan = 3;
    candidates[0] = c;
    candidates[1] = c1;
    candidates[2] = c2;

//    c1.printDetails();
    candidates[0].printDetails();
    candidates[1].printDetails();
    candidates[2].printDetails();

//    cout << candidates[2].isCv;

    fstream oCanFile ("C:\\Users\\Student\\SERetreats\\jobSearch3\\cmake-build-debug\\Candidates.txt", ios::out);
//    ofstream oCanFile("Candidates.txt");
    if (!oCanFile.is_open()) {
        cout << "The system have a big problem" << endl;
    }
    oCanFile << numOfCan << endl;
    for(int i = 0; i < numOfCan; ++i){
        cout << i << endl;
        oCanFile << " hi\n";
        oCanFile << candidates[i].id << endl;
        if (oCanFile.fail()) {
            if (oCanFile.bad()) {
                // Fatal error occurred, like disk failure
                cout << "Fatal error occurred during file operation." << endl;
            } else if (oCanFile.fail()) {
                // Logical error occurred, like invalid data format
                cout << "Logical error occurred during file operation." << endl;
            } else if (oCanFile.eof()) {
                // End-of-file reached unexpectedly
                cout << "End-of-file reached unexpectedly." << endl;
            }
        }
        oCanFile << candidates[i].password<<endl;
        oCanFile << candidates[i].forgetPassQ<<"\n";
        oCanFile << candidates[i].forgetPassA<<"\n";
        oCanFile << candidates[i].fName<<"\n";
        cout << i << endl;
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
        candidates[i].printDetails();
        oCanFile.flush();
    }
    oCanFile.close();



////
//    e1.addJob(0);
//    e = e1;
//    e.addJob(1);
//
//    e1.addJob(2);

//
//    string s;
//    cin >> s;
//    cout << s;
//
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    getline(cin, s);
//    cout << s;
//

//
//
//    //Job* jobs = new Job [2];
//    char** n = new char * [1];
//    Job j1(n, 1, "e", 1, 1, "w", 1, 1, "w", 1, 1, 1, "10", "stam");
//    jobs[0] = j1;
//  //  Job j3 = j1;
//   // j2 = j1;
//    char businessName [20];
//
//    cout << "Enter business name:\n";
//    cin.get(businessName, 20);
//    cout << businessName;

//    ManagementSystem m;
//    m.print();
//    m.mainMenu();

//cin>>
//cin.get(c,c);


//char id [80];
//cin.getline(id,60);

//
//    int i = 0;
//    while (i != 2) {
//        if(!(cin >> i)) {
//            cin.clear();
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//
//void findJob(int id){
//    for(int i = 0; i< lenJ; ++i){
//        if(id == jobs[i].id) {
//            jobs[i].printForEmp();
//            return;
//        }
//    }
//}
//
//void searchJob(Job* jobs, int len){
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
//    int index = 1;
//
//    for (int i = 0; i < len ; ++i) {
//        if(jobs[i].status){
//            if((jobs[i].jobType == t || t == 0) && (jobs[i].age == age || age == 0) && (jobs[i].experience == e || e == 0)){
//                if((jobs[i].jobArea == a || a == 0) && (jobs[i].jobFor == s || s == 0) && (jobs[i].jobHours == h || h == 0) && (jobs[i].jobRange == r || r == 0)){
//                    cout << index << ".\n";
//                    jobs->printForCand();
//                    ++index;
//                }
//            }
//        }
//    }
//
//    if (index == 1)
//        cout << "No suitable jobs were found for you\n";
//
//}
//
