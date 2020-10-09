#ifndef __banking_H__
#define __banking_H__

void menu();
int atm();
void close();
float interest(float t,float amount,int rate);
void fordelay(int j);

void new_account();
void view_info();
void edit(void);
void transact(void);
void erase(void);
void see(void);

void mainMenu();
void Balcheck(float balance);
float Deposit(float balance);
float Withdraw(float balance);
void menuExit();
void errorMessage();



#endif
