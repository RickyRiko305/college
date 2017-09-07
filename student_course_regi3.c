#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
  int student_id;
  int course_id;
  struct Node *stud;
  struct Node *course;
};

/*
*****************************************************
fuction for course assignmen of the student
*****************************************************
*/
void Course_assign(int student_id,int course_id, struct Node **head){
  //printf("\nwelcome to function\n");
  typedef struct Node student;
  student *new,*new1;
  student*s;
  s=*head;
  student*c;
  c=*head;
  student*temp;
  student*temp1;
  //printf("%d %d\n",s->student_id,s->course_id);
//  printf("%d %d",c->student_id,c->course_id);
  while(s->student_id != student_id ){
    s = s->stud;
  }
//  printf("\n%d\n",s->student_id );
  temp = s;
  //temp1 =c;
  while(c != NULL){

      if(c->course_id == course_id){
        // temp1 = c;

        new=(student*)malloc(sizeof(student));
           new->course_id = course_id;
           new->student_id = student_id;

        while(temp != NULL){
          if(temp->course == NULL){
            temp->course = new;
            break;
          }
          temp = temp->course;
      //    printf("enter loop\n");
        }

          temp = new;

            break;
      }

      c = c->course;

  }
    temp->course = NULL;
    //temp1->stud = NULL;
  //  printf("\nnew input1\n%d\n%d",temp->student_id,temp->course_id);
    temp = s;
    int i =1;
    while (temp != NULL){
  //      printf("\nnew input(by student) %d\n%d\n%d",i,temp->student_id,temp->course_id);
        temp = temp->course;
        i++;
    }
    // connecting the course with the new input created

    c=*head;
    while(c != NULL){
      // printf("\nwhiel loop\n");
        if(c->course_id == course_id){
           temp1 = c;

           new=(student*)malloc(sizeof(student));
              new->course_id = course_id;
              new->student_id = student_id;
              while(temp1 != NULL){
                if(temp1->stud == NULL){
                  temp1->stud = new;
                  //printf("\ncourse1\n");
                  break;

                }
                temp1 = temp1->stud;
                //printf("\ncourse2\n");
              }
                temp1 = new;
                //if(temp1==new){printf("yess");}
                temp1->stud = NULL;
        }
        c = c->course;
    }
    temp1->stud = NULL;
    c =*head;
    while(c->course_id != course_id){c=c->course;}
    temp1 = c;
  //  printf("\nnew \n%d\n%d",temp1->student_id,temp1->course_id);
    temp1 = temp1->stud;
  //    printf("\nnew 1\n%d\n%d",temp1->student_id,temp1->course_id);
     /*i =1;
     temp1 = c;
    while (temp1 != NULL){
       printf("\nnew input(by course) %d\n%d\n%d",i,temp1->student_id,temp1->course_id);
       temp1 = temp1->stud;
       i++;
    }*/
}

/*
*****************************************************
fuction to count total number of student registered
*****************************************************
*/
void total_student(struct Node *head){
  int count=0;
  struct Node *temp;
  temp = head;
  temp = temp->stud;
  while(temp != NULL){
    count++;
    temp = temp->stud;
  }
  printf("\n********************\ntotal number of student= %d\n*******************\n",count);

}

/*
*****************************************************
fuction to count total number of courses available
*****************************************************
*/
void total_course(struct Node *head){
  int count=0;
  struct Node *temp;
  temp = head;
  temp = temp->course;
  while(temp != NULL){
    count++;
    temp = temp->course;
  }
  printf("\n********************\ntotal number of course= %d\n********************\n",count);

}

/*
*****************************************************
fuction to add new course to the matrix
*****************************************************
*/
void add_new_course(struct Node **head){
  struct Node *temp, *new;
  temp = *head;
  new = (struct Node*)malloc(sizeof(struct Node));
  printf("\nenter the new course_id\n");
  scanf("%d",&new->course_id);
  new->student_id = '\0';
  while(temp!= NULL){
    if(temp->course == NULL){
      temp->course = new;
      break;
    }
    temp = temp->course;
  }
  temp = new;
  temp->course = NULL;
}

/*
*****************************************************
fuction to add new student to the matrix
*****************************************************
*/
void add_new_student(struct Node **head){
  struct Node *temp, *new;
  temp = *head;
  new = (struct Node*)malloc(sizeof(struct Node));
  printf("\nenter new the student_id \n");
  scanf("%d",&new->student_id);
  new->course_id = '\0';
  while(temp!= NULL){
    if(temp->stud == NULL){
      temp->stud = new;
      break;
    }
    temp = temp->stud;
  }
  temp = new;
  temp->stud = NULL;
}

/*
*****************************************************
fuction to display the courses of perticular student
*****************************************************
*/
void display_course_of_student(int student_id,struct Node *head){
  struct Node *temp,*s;
  s = head;
  while(s->student_id != student_id){
    s = s->stud;
  }
  temp = s;
  temp = temp->course;
  printf("student %d courses are:",s->student_id);
  while(temp != NULL){
    printf("\n%d\n",temp->course_id);
    temp = temp->course;
  }
}

/*
*****************************************************
fuction to display the students of perticular course
*****************************************************
*/
void display_student_in_course(int course_id,struct Node *head){
  struct Node *temp,*c;
  c = head;
  while(c->course_id != course_id){
    c = c->course;
  }
  temp = c;
  temp = temp->stud;
  printf("\ncourse %d taken by :",c->course_id);
  while(temp != NULL){
    printf("\n%d\n",temp->student_id);
    temp = temp->stud;
  }
}

/*
*****************************************************
function to drop a course of a student
*****************************************************
*/
void drop_course(int student_id,int course_id,struct Node **head){
  struct Node *temp,*s,*c,*ptr;
  s = *head;
  c = *head;
//drop course from the student course list
  while(s->student_id != student_id ){
    s = s->stud;
  }
  temp = s;
  while(temp->course_id != course_id){

    if(temp->course->course_id == course_id ){
      printf("rock");
      break;
    }
    printf("rock");
    temp = temp->course;
  }
  printf("\n%d %d",temp->course_id,temp->student_id);
  ptr = temp;
  ptr = ptr->course;
  ptr = ptr->course;
  temp->course = ptr;
// drop student name from the course list
  while(c->course_id != course_id){
    c = c->course;
  }
  temp = c;
  while(temp->student_id != student_id){
    if(temp->stud->student_id == student_id){
      break;
    }
    temp = temp->stud;
  }
  printf("\n%d %d",temp->course_id,temp->student_id);
  ptr = temp;
  ptr = ptr->stud;
  printf("\n%d %d",ptr->course_id,ptr->student_id);
  ptr = ptr->stud;
  temp->course = ptr;
  if(ptr == NULL){
    temp->course = NULL;
    printf("\nyes\n");
  }

}
/*
*****************************************************
function to change the course of student
*****************************************************
*/

void change_course_of_student(int student_id,int course_id,struct Node **head){
   struct Node *temp;
   temp = *head;
   int j;
   drop_course(student_id,course_id,&temp);
   printf("\nenter the course you want to change to\n");
   scanf("%d",&j);
   Course_assign(student_id,j,&temp);
}

/*
*****************************************************
function to display the matrix diagram of student and course
*****************************************************
*/
int display(struct Node *head){
  struct Node *temp;
  temp = head;
  temp = temp->stud;
  printf("         matrix base display\n      ************************\n");
  printf("   ");
  while(temp != NULL){
    printf("%d ",temp->student_id);
    temp = temp->stud;
  }
  printf("\n");
  temp = head;
  temp = temp->course;
  while(temp != NULL){
    printf("%d\n",temp->course_id);
    temp = temp->course;
  }
}



int main(){
  struct Node *head,*temp,*new;
  int student_id,course_id;
    new =(struct Node*)malloc(sizeof(struct Node));
    new->student_id =1;
    new->course_id=1;
    head = temp =new;

  temp = head;

  new =(struct Node*)malloc(sizeof(struct Node));


  FILE *sfile;
  sfile = fopen("student.txt","r");
  int a[20],i,j;
  fscanf(sfile,"%d",&j );
  for( i=0 ; i<j; i++){
    fscanf(sfile,"%d",&a[i] );
    new = (struct Node*)malloc(sizeof(struct Node));
    new->student_id = a[i];
    new->course_id = '\0';
    temp->stud = new;
    temp = new;
    temp->course = NULL;
  }
  temp->stud = NULL;


  temp = head;

  FILE *ffile;
  ffile = fopen("subject.txt","r");
   fscanf(ffile,"%d",&j );
  for( i=0 ; i<j; i++){
    fscanf(ffile,"%d",&a[i] );
    new = (struct Node*)malloc(sizeof(struct Node));
    new->course_id = a[i];
    new->student_id = '\0';
    temp->course = new;
    temp = new;
    temp->stud = NULL;
  }
  temp->course = NULL;


  display(head);

  FILE *afile;
  afile = fopen("assign.txt","r");
   int x=1,q=1,z,w=2;
   for(i=0; i< 10; i++){

     if(q==1){
     fscanf(afile,"%d",&z);
     }

    // else if(temp > 1000){
       student_id = z;
        z = 100;
        if(w == 1){
          x=0;
        }

       while(z<1000){
         fscanf(afile,"%d",&z);
         if(z<1000){
           if (w==z){
             z=2000;
             break;
           }
             course_id = z;
             Course_assign(student_id,course_id,&head);
             w = z;
          }

       }
    // }
    //student_id = z;
     q=0;
    if(z == 1010){
      w = 1;
    }

   }

   /*total_course(head);
   total_student(head);
   add_new_course(&head);
   add_new_student(&head);
   total_course(head);
   total_student(head);
   display(head);
  // FILE *sfile;
   sfile = fopen("student.txt","r");
   //int a[20],i,j;
   fscanf(sfile,"%d",&j );
   for( i=0 ; i<j; i++){
     fscanf(sfile,"%d",&a[i] );
     display_course_of_student(a[i],head);
   }
   display_student_in_course(102,head);*/




      int n,ans=1;
do{
  printf("\n\n\nenter the number :");
  scanf("%d",&n);
  switch (n) {
    case 1 :
            total_course(head);
            break;
    case 2 :
            total_student(head);
            break;
    case 3 :
             printf("\nenter the student whose courses you want to see\n");
             scanf("%d",&n);
            display_course_of_student(n,head);
            break;
    case 4 :
            printf("\nenter the course to see which students appied\n ");
            scanf("%d",&n);
            display_student_in_course(n,head);
            break;
    case 5 :  add_new_course(&head);
            break;
    case 6 : add_new_student(&head);
             break;
    case 7 : printf("\nenter the student_id and course_id u want to drop \n");
             scanf("%d %d",&student_id,&course_id);
             drop_course(student_id,course_id,&head);
             break;
    case 8 : printf("\nenter the student_id and course_id u want to change\n");
             scanf("%d %d",&student_id,&course_id);
             change_course_of_student(student_id,course_id,&head);
             break;

  }
   printf("\nenter 1 if u want to countinue\n");
   scanf("%d",&ans);
}while(ans == 1);



  return 0;
}
