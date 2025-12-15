#include <stdio.h>
#include <string.h>
#define size 5

// *** stack smashing detected ***: terminated :  buffer overflow

/*
2. Create array of employees and search employee by
    empid
    name
*/
//1. Use a struct for an employee
//2. Create an array of employees
typedef struct employee{
    int empid;
    char name[20];
}employee_t;

int find_employee(int emp_id, char emp_name[], employee_t *emp);    // employee_t *emp = employee_t emp[]

int main()
{
    employee_t emp1[size] = {   // array of structures
        {101, "omkar"},
        {102, "Alice"},
        {103, "Bob"},
        {104, "Charlie"},
        {105, "healer"}
    };
    int emp_id;
    char emp_name[20] = "";

    printf("please enter emloyee name and emp_id: ");
    scanf("%s %d", emp_name, &emp_id);

    // in C, when an array is passed to a function, it automatically decays into a pointer to its first element.
    // So internally, what the function receives is: employee_t *emp
    int index = find_employee(emp_id, emp_name, emp1);

    if(index == -1)
    {
        printf("employee %s having employee ID: %d not found\n", emp_name, emp_id);
    }
    else{
        printf("employee %s having employee ID: %d found at index: %d\n", emp_name, emp_id, index);
    }


    return 0;
}

int find_employee(int emp_id, char emp_name[], employee_t *emp){
    for(int i=0; i<size; i++)
    {
        if(emp[i].empid == emp_id && !strcmp(emp[i].name, emp_name))
        {
            return i;
        }
    }
    return -1;

}