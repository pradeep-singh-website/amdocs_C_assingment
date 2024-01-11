/******************************************************************************
 
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <stdio.h>
 
/******************************************************************************
 
Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.
 
*******************************************************************************/
#include <stdio.h>
 
#include <stdbool.h>
#include <stdlib.h>
 
#include <string.h>
 
 
 
struct Date
{
 
  int dd, mm, yy;
 
};
 
 
 
struct Employee
{
 
  int Empno;
 
  char EmpName[50];
 
  struct Date hiredate;
 
  float BasicSalary;
 
  char city[20];
 
};
 
 
 
void
addrecord (struct Employee *employee, int index)
{
 
  printf ("Enter Employee Number: ");
 
  scanf ("%d", &employee[index].Empno);
 
 
  printf ("Enter Employee Name: ");
 
  scanf ("%s", employee[index].EmpName);
 
 
  printf ("Enter Hire Date (dd mm yy): ");
 
  scanf ("%d %d %d", &employee[index].hiredate.dd,
&employee[index].hiredate.mm, &employee[index].hiredate.yy);
 
 
  printf ("Enter Basic Salary: ");
 
  scanf ("%f", &employee[index].BasicSalary);
 
  printf ("Enter City: ");
 
  scanf ("%s", employee[index].city);
 
}
 
 
 
float
calculateNetPay (float BasicSalary)
{
 
 
  const float DA_PERCENTAGE = 40.0;
 
  const float TA_PERCENTAGE = 10.0;
 
  const float PF_PERCENTAGE = 5.0;
 
 
 
  float DA = (DA_PERCENTAGE / 100) * BasicSalary;
 
  float TA = (TA_PERCENTAGE / 100) * BasicSalary;
 
  float PF = (PF_PERCENTAGE / 100) * BasicSalary;
 
 
  // Calculate net pay
 
  float netPay = BasicSalary + DA + TA - PF;
 
 
  return netPay;
 
}
 
 
 
void
showEmployee (struct Employee *employee, int index)
{
 
float netPay = calculateNetPay (employee[index].BasicSalary);
//   printf ("\nEmployee Number: %d\n", employee[index].Empno);
     printf("%d\t\t",employee[index].Empno);
     printf("%s\t\t",employee[index].EmpName);
     printf("%02d-%02d-%02d\t\t",employee[index].hiredate.dd,
	  employee[index].hiredate.mm, employee[index].hiredate.yy);
	  printf("%.2f\t\t\t",employee[index].BasicSalary);
      printf("%.2f\t\t",netPay);
      printf("  %s\t\t",employee[index].city);
//   printf ("Employee Name: %s\n", employee[index].EmpName);
 
//   printf ("Hire Date: %02d-%02d-%02d\n", employee[index].hiredate.dd,
// 	  employee[index].hiredate.mm, employee[index].hiredate.yy);
 
//   printf ("Basic Salary: %.2f\n", employee[index].BasicSalary);
 
 
 
  
//   printf("%d\t\t%s\t\t%s\t\t%02d-%02d-%02d\t\t%.2f\t\t%.2f\t\t%s",employee[index].Empno,employee[index].EmpName, employee[index].hiredate.dd,
// 	  employee[index].hiredate.mm, employee[index].hiredate.yy,employee[index].BasicSalary,netPay,employee[index].city);
//   printf ("Net Salary: %.2f\n", netPay);
 
}
void resetEmployee(struct Employee *employee,int index) {
    employee[index].Empno = 0;
    strcpy(employee->EmpName, "");
    employee[index].hiredate.dd = 0;
    employee[index].hiredate.mm = 0;
    employee[index].hiredate.yy = 0;
    employee[index].BasicSalary = 0.0;
    strcpy(employee->city, "");
}
void
deleterecord (struct Employee *employee, int index)
{
  printf ("Enter Employee no. which you want to delete\n");
  bool t = true;
  while (t)
    {
      int empno;
 
      scanf ("%d", &empno);
 
      for (int i = 0; i < index; i++)
	{
	  if (employee[i].Empno == empno)
	    {
	      for (int j = i; j < index - 1; j++)
		{
		  employee[j]=employee[j+1];
		}
	     resetEmployee(employee,index);
 
	      t = false;
	      break;
	    }
	}
      if (t == true)
	{
	  printf ("Wrong input!!! try again\n");
	}
    }
}
 
 
void
modifyrecord (struct Employee *employee, int index)
{
  bool t = true;
  int up_index = 0;
  while (t)
    {
      int empno;
      printf("Enter Emp ID\n");
      scanf ("%d", &empno);
 
      for (int i = 0; i < index; i++)
	{
	   if(employee[i].Empno == empno)
	    {
	      up_index = i;
	      t = false;
	      break;
	    }
	}
       if (t == true)
	    {
	     printf ("Wrong input!!! try again\n");
     	}
    }
  if (t == false)
    {
      int n1;
      printf ("Enter Choice which you want to edit\n");
      printf ("\t 1 for Name\n");
      printf ("\t 2 for basic pay\n");
      printf ("\t 3 for city\n");
      scanf ("%d", &n1);
    switch (n1)
	{
	case 1:
	  {
	    char name[50];
	    printf ("Enter name\n");
	    scanf ("%s",&name);
	    printf("Name of Employee is changed\n");
	    for(int i=0;i<strlen(name);i++)
	    {
	        employee[up_index].EmpName[i]=name[i];
	    }
	   // strcpy (employee[up_index].EmpName, name);
	   // printf("dav\n");
	    break;
	  }
	case 2:
	  {
	    float sal;
	    printf ("Enter basic salary\n");
	    scanf ("%f", &sal);
	    employee[up_index].BasicSalary = sal;
         break;
	  }
	case 3:
	  {
	    char city1[20];
	    printf ("Enter City\n");
	    scanf ("%s", &city1);
	     printf("City of Employee is changed\n");
	    for(int i=0;i<strlen(city1);i++)
	    {
	        employee[up_index].city[i]=city1[i];
	    }
	   // strcpy (employee[up_index].city, city1);
	    break;
	  }
	default:
	  printf ("Wrong input\n");
	   break;
	}
    }
}
 
 
int
main ()
{
 
  struct Employee emp[100];
  int index = 0;
 
 
  // // Accept employee data
 
  // acceptEmployee(&emp);
 
 
  // // Display employee data
 
  //  showEmployee(&emp);
  int cont = 1;
  while (cont>0)
    {
      printf("\n**********************************************\n");
       printf("EMPLOYEE RECORD SYSTEM");
      printf("\n**********************************************\n");
      printf ("\n1. ADD EMPLOYEE RECORD\n");
      printf ("\n2. DELETE RECORD\n");
      printf ("\n3. DISPLAY RECORDS\n");
      printf ("\n4. MODIFY RECORD\n");
      printf ("\n5. EXIT\n");
      printf ("\nENTER YOUR CHOICE...\n");
      fflush (stdin);
      int choice;
      scanf ("%d", &choice);
 
     
      switch (choice)
	{
	case 1:
 
	  
	  addrecord (emp, index);
	  printf("Data Added Successfully!\n");
	  index++;
	  break;
 
	case 2:
 
	 
	  if(index==0)
	  {
	      printf("No data\n");
	      break;
	  }
	  deleterecord (emp, index);
	  printf("Data Deleted Successfully!\n");
	  index--;
	  break;
 
	case 3:
 
	  {
	  if(index==0)
	  {
	      printf("No data\n");
	      break;
	  }
	  printf("*************************************************************\n");
	  printf("\t\tEMPLOYEES DATA\t\t\n");
	  printf("*************************************************************\n");
	  printf("\nEmpID\t\tEmpName\t\tHireDate\t\tBasicSalary\t\tNetSalary\t City\n");
	  for (int i = 0; i < index; i++)
	    {
	      showEmployee (emp, i);
	      printf("\n");
	    }
	  break;
	  }
	case 4:
      if(index==0)
	  {
	      printf("No data\n");
	      break;
	  }
	  modifyrecord (emp, index);
	  printf("Data modified Succesfully!\n");
	  break;
 
	case 5:{
           return;
	  break;}
 
	default:
	  printf ("\nINVALID CHOICE...\n");
	}

    }
 
  
  return 0;
 
}
 