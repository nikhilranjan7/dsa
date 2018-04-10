struct employee{
    char* name;
    long long int empID;
};

typedef struct employee* emp;

typedef emp* emp_arr;

emp newEmp(char* n, long long int e);

emp_arr init(long long int n);

emp_arr loadData();
