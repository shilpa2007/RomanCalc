#include <stdio.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
 
int main() {
	// your code goes here
	int num;
	//--------------------------------ROMAN TO NUMBER
	
	char num2a[10];
char num2b[10];
char op='A';
int a, inp_value2a, inp_value2b, final_result, opt;
	printf("Enter 2 Roman numbers: ");
	scanf("%s", num2a);
	scanf("%s", num2b);
	printf("\nEnter Operation: '1' to add, '2' to subtract ");
	scanf("%i", &opt);

//	printf("\n Values entered: %s  & %s",num2a, num2b);
//	printf("\n Operation requested: %c",op);
 
//a=sizeof(num2a);
//printf("\nlenght of str:  %i",a);

    inp_value2a = RomanToNum(num2a);
    inp_value2b = RomanToNum(num2b);
 
    //printf("\n%c, %c, %c, %c,%c",num1[0],num1[1],num1[2],num1[3],num1[4]);
    printf("\n Converted First: %i",inp_value2a);
    printf("\n Converted Second: %i",inp_value2b);
   // opt=2;
    final_result=romcalc(inp_value2a,inp_value2b,opt);
   // printf("\n Final result: %i",final_result);
    
	
	
	//--------------------------------NUMBER TO ROMAN
    NumToRoman(final_result);
    printf("\n");
	return 0;
}


//------------------------------

int romcalc(int val2a, int val2b, int opint)
{
int cal_values;

//	if ((oper == 'A') || (oper == 'a'))
    if (opint == 1)
    {
        cal_values = val2a + val2b;
        printf("\n addition: %i",cal_values);
    }
    else
    {
        if (opint == 2)    //    	if ((oper == 'S') || (oper == 's'))
    	{
        	cal_values = val2a - val2b;
        	printf("\n subtraction: %i",cal_values);
    	}
    	else 
        { 
        	printf ("Invalid operation"); 
        }
    }
    return cal_values;
}

//----------------------------------------------
int RomanToNum(char num1[10])
{
    
//printf("\n Number received: %s", num1);
char inp_tk1, inp_tk2;
int loop1, loop2, loop1_end;
int chk, num_int, inp_arr[10];
int inp_value1 = 0;

for (loop1=0; loop1<9; loop1++)
{
//      printf("\n %i : %d",loop1,num1[loop1]);
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
//       printf("\n--------> %c ",inp_tk1);
//       printf("\n--------> %i ",num_int);

}

   for (loop2=(loop1_end-1);loop2>=0;loop2--)
       {
           if(loop2 == (loop1_end-1))
              {
//                  printf("\n %i A--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                inp_value1 = inp_value1 + inp_arr[loop2];
              }
           else
              {   
  
           if (inp_arr[loop2-1] >= inp_arr[loop2])
           {
              
              
               if (inp_arr[loop2] < inp_arr[loop2+1])
                 {
//                     printf("\n %i A1--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                  inp_value1 = inp_value1 - inp_arr[loop2];
                 }
                 else
                 {
//                     printf("\n %i A2--> %i >= %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
                     inp_value1 = inp_value1 + inp_arr[loop2];
                 }
               
              
              
           }
           
          // if (inp_arr[loop2-1] < inp_arr[loop2])
          else
           {
//                printf("\n %i B--> %i < %i",loop2, inp_arr[loop2-1],inp_arr[loop2]);
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
           

       }
       if (inp_value1 < 0)
       {inp_value1 *-1;}
    return inp_value1;
}


 NumToRoman(int fnum){
    int nums_con[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
    char * symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" }; 
    int dup,loop4 = 0; 
    printf("\n Final result : ");
    while (fnum){    
        dup=fnum/nums_con[loop4];                  
        while (dup--){      
            printf("%s",symbols[loop4]); 
        }
        fnum%=nums_con[loop4];
        loop4++;                     
    }
}
