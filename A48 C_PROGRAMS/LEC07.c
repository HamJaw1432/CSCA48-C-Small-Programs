#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS_IN_COURSE 3
#define MAX_NAME_LENGTH 100
#define COURSE_LENGTH 7

typedef struct StudentRecord
{
	char name[MAX_NAME_LENGTH];
	//char program[3];
	//int StudentNum; //we choose int as it will take less space in memory than a char. ***better
	float gpa;
	
}Student;

typedef struct CourseRecord
{
	//char code[COURSE_LENGTH];
	int num_students;
	Student students[MAX_STUDENTS_IN_COURSE];
}Course;

Student top_studentf(Course input_class)
{
	float top_grade = 0.0;
	char top_student[MAX_NAME_LENGTH];
	int index_top_stu = 0;
	int i;
	//loop over all students
	for (i = 0; i < input_class.num_students; i++)
	{
		float current_grade = input_class.students[i].gpa;
		if (current_grade > top_grade)
		{
			top_grade = current_grade;
			strcpy(top_student, input_class.students[i].name);
			index_top_stu = i;
		}			
	}
	printf("%s is the top student\n", input_class.students[i]);
	return input_class.students[i];
}


int main()
{
	/* Student alice; // their is a memory box labeled alice st. it has enough space for 103 char and 1 int and 1 float
	Student bob;
	Student mark;
	
	strcpy(alice.name, "alice"); 
	strcpy(alice.program, "CSC");
	alice.StudentNum = 123456789;
	alice.gpa = 3.92;
	
	
	strcpy(bob.name, "bob");
	strcpy(bob.program, "CSC"); 
	bob.StudentNum = 123456790;
	bob.gpa = 3.65; */
	
	/* strcpy(mark.name, "mark");
	strcpy(mark.program, "CSC"); 
	mark.StudentNum = 123456791;
	mark.gpa = 2.50; */
	
	/* Course csca48;
	csca48.student[1] = alice;
	csca48.student[2] = bob; */
	
	char con = 'Y';
	char input_name[MAX_NAME_LENGTH];
	int count = 0;
	float input_grade;
	Student new_student;
	Course csca48;
	while (con == 'Y' && count < MAX_STUDENTS_IN_COURSE)
	{
		//ask for name
		printf("Input student Name:\n");
		fgets(input_name, MAX_NAME_LENGTH, stdin);
		
		//ask for grade
		printf("Enter Grade:\n");
		scanf("%f", &input_grade);
		getchar();
		
		//create student
		strcpy(new_student.name, input_name);
		new_student.gpa = input_grade;
		csca48.students[count] = new_student;
		
		//ask to continue
		printf("Do you want to continue? (Y/N)\n");
		scanf("%c", &con);
		getchar();
		count ++;
		
	}
	csca48.num_students = count;
	
	Student top_student;
	top_student = top_studentf(csca48);
	
	printf("%s is the top student\n", top_student.name);
	
	
	/* if (alice.gpa > bob.gpa)
	{
		printf("%d is smarter", alice.StudentNum);
	}else{
		printf("%d is smarter", bob.StudentNum);
	} */
	
	
	
	return 0;
}