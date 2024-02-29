#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ManagementSystem.h"
#include "Employer.h"
#include <cmath>
using namespace std;
#include <limits>

int main() {

//    Employer e("1", "1", 1, "1");
//    e.addJob(0);
//    e.addJob(1);
//
//    ofstream oEmpFile("Employers.csv");
//    if (!oEmpFile) {
//        cout << "The system have a big problem" << endl;
//    }
//    oEmpFile << 1 << endl;
//    oEmpFile << e.id << ",";
//    oEmpFile << e.password << ",";
//    oEmpFile << e.forgetPassQ << ",";
//    oEmpFile << e.forgetPassA << ",";
//    oEmpFile << e.jobsNum << endl;
//    for(int j = 0; j < e.jobsNum; ++j) {
//        oEmpFile << e.jobs[j].id << ",";
//        oEmpFile << e.jobs[j].businessName << ",";
//        oEmpFile << e.jobs[j].jobProfession << ",";
//        oEmpFile << e.jobs[j].address << ",";
//        oEmpFile << e.jobs[j].salary << ",";
//        oEmpFile << e.jobs[j].about << ",";
//        oEmpFile << e.jobs[j].jobType << ",";
//        oEmpFile << e.jobs[j].jobHours << ",";
//        oEmpFile << e.jobs[j].experience << ",";
//        oEmpFile << e.jobs[j].jobArea << ",";
//        oEmpFile << e.jobs[j].jobRange << ",";
//        oEmpFile << e.jobs[j].status << ",";
//        oEmpFile << e.jobs[j].numOfSub << endl;
//    }
//    oEmpFile.close();
//    Employer e("1", "1", 1, "1");
//    e.addJob(0);
//    e.addJob(1);
//
//    ofstream oEmpFile("Employers.csv");
//    if (!oEmpFile) {
//        cout << "The system have a big problem" << endl;
//    }
//    oEmpFile << 1 << endl;
//    oEmpFile << e.id << "\n";
//    oEmpFile << e.password << "\n";
//    oEmpFile << e.forgetPassQ << "\n";
//    oEmpFile << e.forgetPassA << "\n";
//    oEmpFile << e.jobsNum << endl;
//    for(int j = 0; j < e.jobsNum; ++j) {
//        oEmpFile << e.jobs[j].id << "\n";
//        oEmpFile << e.jobs[j].businessName << "\n";
//        oEmpFile << e.jobs[j].jobProfession << "\n";
//        oEmpFile << e.jobs[j].address << "\n";
//        oEmpFile << e.jobs[j].salary << "\n";
//        oEmpFile << e.jobs[j].about << "\n";
//        oEmpFile << e.jobs[j].jobType << "\n";
//        oEmpFile << e.jobs[j].jobHours << "\n";
//        oEmpFile << e.jobs[j].experience << "\n";
//        oEmpFile << e.jobs[j].jobArea << "\n";
//        oEmpFile << e.jobs[j].jobRange << "\n";
//        oEmpFile << e.jobs[j].status << "\n";
//        oEmpFile << e.jobs[j].numOfSub << endl;
//    }
//    oEmpFile.close();




//    string s;
//    cin >> s;
//    cout << s;
//
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    getline(cin, s);
//    cout << s;

//    Employer e("206576977", "123", "why", "becouse");
//    Employer e2("206999999", "903", "what", "this");
//    lenE = 2;
//    emps[0] = e;
//    emps[1] = e2;

//    //Job* jobs = new Job [2];
//    char** n = new char * [1];
//    Job j1(n, 1, "e", 1, 1, "w", 1, 1, "w", 1, 1, 1, "10", "stam");
//    jobs[0] = j1;
//  //  Job j3 = j1;
//   // j2 = j1;
//    char businessName [20];

//    cout << "Enter business name:\n";
//    cin.get(businessName, 20);
//    cout << businessName;



    ManagementSystem m;
    m.mainMenu();


//
//    int i = 0;
//    while (i != 2) {
//        if(!(cin >> i)) {
//            cin.clear();
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        }
//    }



//    switch (i) {
//        case 1:
//            cout<< "1";
//            break;
//        case 2:
//            cout<< "2";
//            break;
//        default:
//            cout <<"bla\n";
//    }




//    char b [10];
//   cout <<"a\n";
//    cin >> b;
//    cout <<"a\n";
//    cout << b;
//    cout <<"a\n";
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
