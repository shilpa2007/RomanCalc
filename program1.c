#include <stdio.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int main(void) {
	// your code goes here

//string inp1 = "XLVM";	
 
char num2[10] = "XLV";
int a, inp_value2;

	
//printf("value to be test: %s", num1);	

	printf("Enter Roman numbers: ");
	scanf("%s", num2);
	printf("\n Values entered: %s",num2);
 
//a = int(num1[0]);
 

a=sizeof(num2);
printf("\nlenght of str:  %i",a);

inp_value2 = RomanToNum(num2);
 
//printf("\n%c, %c, %c, %c,%c",num1[0],num1[1],num1[2],num1[3],num1[4]);
printf("\n Converted : %i",inp_value2);

	return 0;
}

int RomanToNum(char num1[10])
{
    
printf("\n Number received: %s", num1);
char inp_tk1, inp_tk2;
int loop1, loop2, loop1_end;
int chk, num_int, inp_arr[10];
int inp_value1 = 0;

for (loop1=0; loop1<9; loop1++)
{
      printf("\n %i : %d",loop1,num1[loop1]);
      chk = (int)num1[loop1];
      inp_tk1 = num1[loop1];
      if (chk == 0)
       {
//        printf("blank");  
        loop1_end=loop1;
        loop1=9;
       }
       
       else
       {
           switch (inp_tk1)
           {
               case 'I':
                     num_int = 1;
                     break;
                     
                case 'V':
                     num_int = 5;
                     break;
                case 'X':
                     num_int = 10;
                     break;
                case 'L':
                     num_int = 50;
                     break;     
                case 'C':
                     num_int = 100;
                     break;
                case 'D':
                     num_int = 500;
                     break;     
                case 'M':
                     num_int = 1000;
                     break;
            }
       }
       inp_arr[loop1] = num_int;
       printf("\n--------> %c ",inp_tk1);
       printf("\n--------> %i ",num_int);

}

   for (loop2=(loop1_end-1);loop2>=0;loop2--)
       {
           if(loop2 == (loop1_end-1))
              {
                  printf("\n %i A--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                inp_value1 = inp_value1 + inp_arr[loop2];
              }
           else
              {   
  
           if (inp_arr[loop2-1] >= inp_arr[loop2])
           {
              
              
               if (inp_arr[loop2] < inp_arr[loop2+1])
                 {
                     printf("\n %i A1--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                  inp_value1 = inp_value1 - inp_arr[loop2];
                 }
                 else
                 {
                     printf("\n %i A2--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                     inp_value1 = inp_value1 + inp_arr[loop2];
                 }
               
              
              
           }
           
          // if (inp_arr[loop2-1] < inp_arr[loop2])
          else
           {
                printf("\n %i B--> %i < %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                if (inp_arr[loop2] >= inp_arr[loop2+1])
                 {
                  inp_value1 = inp_value1 + inp_arr[loop2];
                 }
                 else
                 {
                     inp_value1 = inp_value1 - inp_arr[loop2];
                 }
                 
           }
              }
           
           printf("\n :  %i",inp_value1);
            
       }
       if (inp_value1 < 0)
       {inp_value1 *-1;}
    return inp_value1;
}
