
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//#include <stdbool.h>
 #include <iostream>
 #include <sstream>
 #include <algorithm>
  using namespace std;
    char** warehouseScalability(int input1_size, char** input1,int input2_size, char** input2,int* output_size)
    {
                //Write code here
		std::string  emplist;
		std::string joblist;
       // string joblist(*input2);
		
		std::string *emplist1= new string [input1_size];
		string *emplist2= new string [input1_size];
		string *emplist12= new string [input1_size];
		string *emplist22= new string [input1_size];
		int *emplistint= new int [input1_size];
		int *emplistint2= new int [input1_size];
		string *joblistskill= new string [input2_size];
		string *joblistpri= new string [input2_size];
		string *joblisttime= new string [input2_size];
		string *joblistid= new string [input2_size];
		int *joblistpriint= new int [input2_size];
		int *joblisttimeint= new int [input2_size];
		string *joblistskill2= new string [input2_size];
		string *joblistpri2= new string [input2_size];
		string *joblisttime2= new string [input2_size];
		string *joblistid2= new string [input2_size];
		int *joblistpriint2= new int [input2_size];
		int *joblisttimeint2= new int [input2_size];
		int pos1=0;
		int pos2=0;
		int len=0;
		stringstream ss1;

		for(int j=0;j<input1_size;j++){
			emplist= emplist+ string(input1[j]);
			}
		for(int j=0;j<input2_size;j++){
			joblist=joblist+ string(input2[j]);
			}
			int i=0;
			while((!(i>=input1_size)))
			{ 
				pos2=emplist.find("#",pos1);
			len=pos2-pos1;
			emplist1[i]=emplist.substr (pos1+1,len-1);
			emplistint[i]=atoi(emplist1[i].c_str());
			pos1=pos2+1;
			//i++;
			if(i<(input1_size-1)){
			pos2=emplist.find("W",pos1);
			len=pos2-pos1;
			emplist2[i]=emplist.substr (pos1,len);
			pos1=pos2;
			}
			else if(i==(input1_size-1)){
			pos2=emplist.length();
			len=pos2-pos1;
			emplist2[i]=emplist.substr (pos1,len);
			pos1=pos2;
			}
			i++;
			//pos1=0;
			//pos2=0;
			}
			pos1=0;
			pos2=0;
			i=0;
			while(/*(!(pos1>=joblist.length()))&&*/(!(i>=input2_size)))
			{ 
			pos2=joblist.find("#",pos1);
			len=pos2-pos1;
			joblistskill[i]=joblist.substr (pos1,len);
			
			pos1=pos2+1;
			pos2=joblist.find("#",pos1);
			len=pos2-pos1;
			joblistpri[i]=joblist.substr (pos1,len);
			joblistpriint[i]=atoi(joblistpri[i].c_str());
			pos1=pos2+1;
			pos2=joblist.find("#",pos1);
			len=pos2-pos1;
			joblisttime[i]=joblist.substr (pos1,len);
			joblisttimeint[i]=atoi(joblisttime[i].c_str());
			pos1=pos2+1;
			//i++;
			if(i<(input2_size-1)){
			pos2=joblist.find("S",pos1);
			len=pos2-pos1;
			joblistid[i]=joblist.substr (pos1,len);
			pos1=pos2;
			}
			else if(i==(input2_size-1)){
			pos2=joblist.length();
			len=pos2-pos1;
			joblistid[i]=joblist.substr (pos1,len);
			pos1=pos2;
			}
			i++;
			//pos1=0;
			//pos2=0;
			}
			int q=input1_size;
			*output_size=input1_size;
			string * output=new string[input1_size];
			
			for(int x=0;x<input1_size;x++){
			
				emplistint2[x]=emplistint[x];
			}
			sort(emplistint2,emplistint2+input1_size);
			stringstream ss;
			for(int x=0;x<input1_size;x++){
			    ss<<emplistint2[x];
				output[x]=string("W")+ ss.str();
				//cout<<output[x]<<" output "<<emplistint2[x]<<"\n";
				ss.str("");
			}
			int max=-1;
			int min=999;
			int y=0;
			int z=0;
			for(int p=0;p<input2_size;p++){
			for(int x=0;x<input2_size;x++){
			if(joblistpriint[x]>max){
			max=joblistpriint[x];
			y=x;
			
			}}
			 z=y;
			 //cout<<z<<" z1"<<"\n";
			for(int x=0;x<input2_size;x++){
			if((joblistpriint[x]==max)){
				if(joblisttimeint[x]<min){
			min=joblisttimeint[x];
			z=x;
						}
					
			/*else{
				z=y;
			}*/
			}
			}
			//cout<<z<<" z2"<<"\n";
			max=-1;
			min=999;
			joblistskill2[p]=joblistskill[z];
			joblistskill[z]="";
			joblistpri2[p]=joblistpri[z];
			joblistpri[z]="";
			joblistpriint2[p]=joblistpriint[z];
			joblistpriint[z]=-1;
			joblisttime2[p]=joblisttime[z];
			joblisttime[z]="";
			joblisttimeint2[p]=joblisttimeint[z];
			joblisttimeint[z]=999;
			joblistid2[p]=joblistid[z];
			//cout<<joblistid2[p]<<" jobid"<<"\n";
			joblistid[z]="";
			int y=0;
			int z=0;
			}
			min=999;
			y=0;
			 z =0;
			for(int p=0;p<input1_size;p++){
			for(int x=0;x<input1_size;x++){
			if(emplistint[p]==emplistint2[x]){
			z=x;
			}
			
			}
		
			emplist12[p]=emplist1[z];
			//cout<<emplist12[p]<<" emp"<<"\n";
			emplist1[z]="";

			emplist22[p]=emplist2[z];
			//cout<<emplist22[p]<<" emp2"<<"\n";
			emplist2[z]="";
			emplistint[z]=-1;
			}			
			int * emptime=new int [input1_size];
			int c=-1;
			for(int k=0;k<input1_size;k++){
			for(int h=0;h<input2_size;h++){
				c=-1;
				
				if(joblistskill2[h]==emplist22[k])
				{
					c=k;
					for(int t=0;t<input1_size;t++){
						if((emplist22[k]==emplist22[t])&&(k!=t)){
							if(emptime[k]>emptime[t]){
								c=t;
							}
							else if(((emptime[k]==emptime[t]))&&(k>t)){
								c=t;

							}
							else{
								c=k;
							}

						}
						
					}
					if(joblistid2[h]!=""){
						output[c]=output[c]+"#"+joblistid2[h];
						emptime[c]=emptime[c]+joblisttimeint2[h];
						joblistid2[h]="";
						joblisttimeint2[h]=0;
					}
				}

				}

				
			}
			string output2;
			
			char ** a=0;
			a = new char*[input1_size];

    
			for(int j=0;j<input1_size;j++){
				output2=output2+output[j];
			//	a=&output;
				a[j]=new char[9000];
			strcpy(a[j],output[j].c_str());
			}

return  a; 


    }




    




int main() {
    int output_size;
    char** output;

    int ip1_size = 0;
    int ip1_i;
    scanf("%d\n", &ip1_size);
	//ip1_size=8;
    char* ip1[8];//ip1_size];
    for(ip1_i = 0; ip1_i < ip1_size; ip1_i++) {
        char* ip1_item;
        ip1_item = (char *)malloc(512000 * sizeof(char));
        scanf("\n%[^\n]",ip1_item);
        
        ip1[ip1_i] = ip1_item;
    }
    int ip2_size = 0;
    int ip2_i;
    scanf("%d\n", &ip2_size);
    char* ip2[8];//ip2_size];
    for(ip2_i = 0; ip2_i < ip2_size; ip2_i++) {
        char* ip2_item;
        ip2_item = (char *)malloc(512000 * sizeof(char));
        scanf("\n%[^\n]",ip2_item);
        
        ip2[ip2_i] = ip2_item;
    }
    output = warehouseScalability(ip1_size,ip1,ip2_size,ip2,&output_size);
    int output_i;
	//std::cout<<"hello";
    for(output_i=0; output_i < output_size; output_i++) {
    
        printf("%s\n", output[output_i]);
		//std::cout<<output[output_i];
		//std::cout<<"hello";
        
    }
	//char a;
	//std::cin>>a;
    return 0;
}