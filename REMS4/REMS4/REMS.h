//
//  REMS.h
//  REMS4
//
//  Created by BUTHAINA ISIHAKA SUDI on 04/11/2018.
//  Copyright © 2018 BUTHAINA ISIHAKA SUDI. All rights reserved.
//

#ifndef REMS_h
#define REMS_h
using namespace std;
struct payment
{
    int payID;
    double amount;
    payment *next;
};
void initPayment(payment *head, int n);
void makePayment(payment *head, int a);
void DisplayPaymentsSummary(payment *head);


struct race
{
    string racename;
    int raceno;
    int racefees;
    race *next;
};
void initRace(race *head, int n);
void CreateRace(race *head);
void DisplayAvailableRaces(race *head);
void SearchRaceCode(race *head);


struct runners
{
    string runnername;
    runners *next;
};
void iniRunners(runners *head, string n);
void RegisterandRun(runners *head);


struct managers
{
    string managername;
    int managerID;
    managers *next;
};
void iniManagers(managers *head, string n);
void SearchManager(managers *head);
void RegisterandCreateRace(managers *head);


#endif /* REMS_h */
