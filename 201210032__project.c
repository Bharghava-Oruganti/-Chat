#include<stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
  char name[25],n1[1024],ch,path[128];
  int count_days = 0, count_attandence= 0,count_msgs=0,r,a,count_inactivel=0,count_moderatel=0,count_activel=0;
  float per;
  FILE* project;
	char n2[1024];

	printf("****************************************************************\n");
  printf("PLEASE ENTER THE FULL PATH OF TXT FILE : \n");
  scanf("%s",path);                                                                                                            // Promping User to Input the FILE path 
  project = fopen(path,"r");							
  
  while(!feof(project))
  {
	   fgets(n1,sizeof(n1),project);
	   
	   if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
	   {                                                                               					// Countig total NO_OF_DAYS in the given data file
	   	count_days++;

	   }
   
  }
  
 
	printf("\nAttendence/Messages data for %d days is found in the given TEXT file\n\n\n", count_days);
	for(;;){
	printf("                                         MENU\n\n\n\t1.]ATTENDANCE\n\t2.]NO_OF_MSGS\n\t3.]CLASS STATS\n\t4.]EXIT\n");                // PRINTING MENU
	printf("ENTER YOUR CHOICE\n");
	scanf("%d",&a);
        if(a==4)                                                                                                              // EXIT CONDITION
        break;	
	switch(a){
	case 1:
	printf("*******************************************************************\n");
	printf("\nPlease Enter the NO_OF Students\n");
       scanf("%d",&r);
       getc(stdin);
	for(int i=0;i<r;i++)
	{
		rewind(project);
		count_attandence = 0;
		
		fflush(stdin);
		printf("\nENTER TARGET NAME\t");
		int k = 0;
		fflush(stdin);
		//if(i == 0)
		//	getc(stdin); //To give a dummy read on the input buffer for white spaces
		for(;;)
		{
			char ch;
			scanf("%c",&ch);
			//ch = getc(stdin);
			if(ch != '\n')                                                                                      // CASE 1
				name[k++]=ch;
			else
			{
				name[k]='\0';
				break;
				}
	         //scanf("%s",name);
	         }
	         
	          
		for(int i =0; i<count_days; i++)
		 {
		   
			while(fgets(n1,sizeof(n1),project))
			{
			
				if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
				 	break;
				 	
			}
		   
		   	while(fgets(n1,sizeof(n1),project))

			{ 
				
			   	if(strstr(n1,name))
			   	{
			   		
			   		count_attandence++;
			   		break;
			   			   		
			   	}
			   	
		   	}
		   
		}
		
        per=((float)count_attandence/(float)count_days)*100;
	printf("\n%s is present %d days out of %d days\nPercentage of student is %.1f\n", name, count_attandence, count_days,per);    
	
	 
	
	rewind(project);
	}
          break;
          case 2:
          	printf("*******************************************************************\n");
	printf("\nPlease Enter the NO_OF Students\n");
       scanf("%d",&r);
       getc(stdin);
	for(int i=0;i<r;i++)
	{
		rewind(project);
		count_attandence = 0;
		
		fflush(stdin);
		printf("\nENTER TARGET NAME\t");
		int k = 0;
		fflush(stdin);
		
		//	getc(stdin);                                          //To give a dummy read on the input buffer for white spaces
		for(;;)
		{
			char ch;
			scanf("%c",&ch);
			//ch = getc(stdin);
			if(ch != '\n')
				name[k++]=ch;
			else
			{
				name[k]='\0';
				break;
		        }
	         //scanf("%s",name);
	         }
	         
	          
		for(int i =0; i<count_days; i++)
		 {
		   
			while(fgets(n1,sizeof(n1),project))
			{
			
				if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
				 	break;
				 	
			}
		   
		   	while(fgets(n1,sizeof(n1),project))

			{ 
				
			   	if(strstr(n1,name))
			   	{
			   		
			   		count_attandence++;
			   		break;
			   			   		
			   	}
			   	
		   	}
		   
		}
		
        
	rewind(project);
	printf("DATE\t\t\t NAME\t\t\t\t#MSGS\n");
	for(int i =0; i<count_days; i++)
	 {
	 	if(i != count_days-1)
		count_msgs=0;
		while(fgets(n1,sizeof(n1),project))
		{
		
			if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
			{
				n1[strlen(n1)-1]='\0';
			      	printf("%s\t\t",n1);
			 	break;
			 	}
			 	
		}

   	while(fgets(n1,sizeof(n1),project))

	{   	
		int p=0;
		for(p=0; p<strlen(name); p++)
		{
			if(n1[p] != name[p])
				break;
			
		}
		
		if(p == strlen(name) && n1[p]!=' '&& n1[p+2]==':')
			count_msgs++;
	   	/*if(strstr(n1, name))
	   	{ 
	   		count_msgs++;
	   		   		
	   	}
	   	*/
	   	else if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
	   	{
	   		n1[strlen(n1)-1]='\0';
	   	 	printf("%s\t\t\t%d\n%s\t\t",name, count_msgs, n1);
	   	 	if(i!=count_days-1)
	   	 	count_msgs=0;
	   	 	}
	   	
   	}

printf("%s\t\t\t%d\n",name, count_msgs);
break;
rewind(project);

}
  
  
  }
  break;
  
 	
    
    case 3:
    printf("*******************************************************************\n");
	printf("\nPlease Enter the NO_OF Students\n");
       scanf("%d",&r);
       getc(stdin);
	for(int i=1;i<=r;i++)
	{
		rewind(project);
		count_attandence = 0;
		
		fflush(stdin);
		printf("\nENTER TARGET NAME\t");
		int k = 0;
		fflush(stdin);
		//if(i == 0)
		//	getc(stdin); //To give a dummy read on the input buffer for white spaces
		for(;;)
		{
			char ch;
			scanf("%c",&ch);
			//ch = getc(stdin);
			if(ch != '\n')                                                                                      // CASE 1
				name[k++]=ch;
			else
			{
				name[k]='\0';
				break;
				}
	         //scanf("%s",name);
	         }
	         
	          
		for(int i =0; i<count_days; i++)
		 {
		   
			while(fgets(n1,sizeof(n1),project))
			{
			
				if(n1[2]=='-' && n1[5]=='-'&& strstr(n1, "-2021"))
				 	break;
				 	
			}
		   
		   	while(fgets(n1,sizeof(n1),project))

			{ 
				
			   	if(strstr(n1,name))
			   	{
			   		
			   		count_attandence++;
			   		break;
			   			   		
			   	}
			   	
		   	}
		   
		}
		
        per=((float)count_attandence/(float)count_days)*100; 
        if(per>=0 && per<=30)
         count_inactivel++;
         else if(per>30 && per<=75)
          count_moderatel++;
          else if(per>75 && per<=100)
           count_activel++;
  }

  rewind(project);
   printf("\n\n\n\t\t###CLASS STATS###\n\n\n");
   printf("INACTIVE\tMODERATE\tACTIVE\n");
   printf("   %d\t\t   %d\t\t   %d\n",count_inactivel,count_moderatel,count_activel);
   }
     count_inactivel=0,count_moderatel=0,count_activel=0;
  
  
  
  
  }
  
  }
 

