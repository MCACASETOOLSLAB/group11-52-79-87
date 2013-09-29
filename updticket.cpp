#include<stdio.h>
#include<windows.h>
int COUNTER[5]={1,2,3,4,5},TICKET[5]={1,1,1,1,1};

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void paint(int n)
{
   SetConsoleTextAttribute(h,n);
}

void call()
{
    int i;
    printf("\n\t*****RESOURCE DETAILS*****\n");
    printf("\nCOUNTERRS: ");
    for(i=0;i<5;i++)
    {
         printf("\t%d",COUNTER[i]);
    }
    printf("\n\nTICKETS: ");
    for(i=0;i<5;i++)
    {
       printf("\t%d",TICKET[i]);
    }
}
void signal(int a,int n)
{
    int choice;
  paint(a);
  for(n=1;n<7;n++)
  {
  switch(n)
  {
  	case 1:
  		MessageBox(NULL,"RESOURCE signalD BY COUNTER 1","STATUS",MB_OK|MB_ICONINFORMATION);
  		TICKET[0]=1;
  		call();
		break;
  	case 2:
  		MessageBox(NULL,"RESOURCE signalD BY COUNTER 2","STATUS",MB_OK|MB_ICONINFORMATION);
  		TICKET[1]=1;
  		call();
		break;
	case 3:
  		MessageBox(NULL,"RESOURCE signalD BY COUNTER 3","STATUS",MB_OK|MB_ICONINFORMATION);
  	    TICKET[2]=1;
  		call();
		break;

	case 4:
  		MessageBox(NULL,"RESOURCE signalD BY COUNTER 4","STATUS",MB_OK|MB_ICONINFORMATION);
  		TICKET[3]=1;
  		call();
		break;

	case 5:
  		MessageBox(NULL,"RESOURCE signalD BY COUNTER 5","STATUS",MB_OK|MB_ICONINFORMATION);
  		TICKET[4]=1;
  		call();
		break;
    case 6:
          
        exit(0);
  }
}
}

void wait(int a,int i)
{
  int flag=0;
  paint(a);
  for(i=1;i<6;i++)
  {
  switch(i)
     {
       case 1:
         if(TICKET[0]!=1)
            {
               MessageBox(NULL,"SORRY!!!COUNTER 1 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR COUNTER 1","STATUS",MB_OK|MB_ICONINFORMATION);

		 TICKET[0]=0;
         call();
         printf("\n\n\t\t\tCOUNTER 1 IS CURRENTLY WORKING....\n\n");
         flag=1;
         break;

       case 2:
         if(TICKET[1]!=1)
            {
               MessageBox(NULL,"SORRY!!!COUNTER 2 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR COUNTER 2","STATUS",MB_OK|MB_ICONINFORMATION);
         TICKET[1]=0;
         call();
         printf("\n\n\t\t\tCOUNTER 2 IS CURRENTLY WORKING....\n\n");
         flag=2;
         break;

	   case 3:
         if(TICKET[2]!=1)
            {
               MessageBox(NULL,"SORRY!!!COUNTER 3 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR COUNTER 3","STATUS",MB_OK|MB_ICONINFORMATION);
         TICKET[2]=0;//TICKET[1]=TICKET[3]=0;
         call();
         printf("\n\n\t\t\tCOUNTER 2 IS CURRENTLY WORKING....\n\n");
         flag=3;
         break;

	   case 4:
        if(TICKET[3]!=1)
            {
               MessageBox(NULL,"SORRY!!!COUNTER 4 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR COUNTER 4","STATUS",MB_OK|MB_ICONINFORMATION);
         TICKET[3]=0;
         call();
         printf("\n\n\t\t\tCOUNTER 4 IS CURRENTLY WORKING....\n\n");
         flag=4;
         break;

	   case 5:
         if(TICKET[4]!=1 )
            {
               MessageBox(NULL,"SORRY!!!COUNTER 5 IS IN BUSY WAIT","STATUS",MB_OK|MB_ICONERROR);
               break;
            }
		 MessageBox(NULL,"RESOURCE ALLOCATED FOR COUNTER 5","STATUS",MB_OK|MB_ICONINFORMATION);
         TICKET[4]=0;
         call();
         printf("\n\n\t\t\tCOUNTER 5 IS CURRENTLY WORKING....\n\n");
         flag=5;
         break;

       default:
	     printf("\n\n\t\tINVALID COUNTER  NO. ENTERED....\n\n");

     }
 }
}
int main()
{
	x:
   paint(10);
   int n,i,num,flag=0;
   call();
  do
   {
          for(n=1;n<4;n++)
          {
          switch(n)
          {
            case 1:
            	//printf("\n\tENTER THE COUNTER NO FOR TICKET BOOK");
            	//scanf("%d",&k);
            	i=1;
		        wait(9,i);
		        flag=1;
		        break;

			case 2:
				//printf("\n\n\tENTER THE COUNTER NO. FOR RELEASE THE SEAT COUNTER:");
                //scanf("%d",&num);
                num=1;
                if(flag==0)
                  {
                    MessageBox(NULL,"RESOURCE ALREADY AVAILABLE","STATUS",MB_OK|MB_ICONERROR);
                    break;
                  }

                if(num!=i)
                  {
                    MessageBox(NULL,"THIS COUNTER IS IN BUSY WAITING","STATUS",MB_OK|MB_ICONERROR);
                    break;
                  }
                signal(8,num);
                flag=0;
                break;
          }
          }
  }while(n!=3);
}
