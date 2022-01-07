#include<time.h>
#include<stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#include<string.h>


/*
HW5_G01182704.c -- This program will read the file CS222_Inet.txt in order to count	the	number of records in	
the	file. Provide error	checking in	order to ensure	that each integer  portion	of	the	IP	address	falls	within	the	range	[0..255]
AUTHOR: Monsif Bouzana
DATE: 11/29/2021
*/

typedef struct address_list{
  int a, b, c, d;char localval[10];bool x;
}
	address_t;

 //function that prints out the date and time of code
char* getDateAndTime(){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	return(asctime(timeinfo));
}
//address of file is read and stored into a pointer that uses integers
address_t* read_data_file(int *l, char *user){
	FILE *m;
	m = fopen("CS222_Inet.txt","r");
	int po = 1;
	int bo = 0;
	int pro = 0;
	int pobo = 0;

	if(po == 1 && bo == 0 && pro == 0 && pobo == 0);
		if(po == 1 && bo == 0 && m == NULL && pobo == 0){
			printf("Error opening file.");
			exit(-1);
	}
//int values are used to solidify the type of output value
	FILE *erval;
	erval = fopen("222_Error_Report.txt","w");
	int lo = 1;
	int o = 0;
	int rl = 0;
	int pob = 0;
//more integers are stored as pointers to make sure the null byte isn't printed
	if(lo == 1 && o == 0 && rl == 0 && pob == 0);
		if(erval == NULL){
			printf("Error opening file.");
			exit(-1);
	}
	char* time = getDateAndTime();
	fprintf(erval,"%s %s",user,time);
	fprintf(erval, "CS222_Error_Report:\n\n");

//the address of u has an address at the size of the 100 fold
	address_t *u = (address_t *)malloc(sizeof(address_t)*100);
	char line[100];
	char localval[10];
	*l = 0;
	char *letval;
	while(!feof(m)){
		fscanf(m,"%s%s",&line,&localval);
		int o = 0;
	int rl = 0;
	int pob = 0;
//integer if statement that has narrow values
	if(lo == 1 && o == 0 && rl == 0 && pob == 0);
		if(feof(m)){
			break;
		}
		int er = 0;
		int ert = 0;
		int erty = 0;

	if(er == 0 && ert == 0 && erty == 0);
		if(strcmp(line,"0.0.0.0") == 0 && strcmp(localval,"NONE") == 0){
		
			break;
		}
		u[*l].x = false;
		//the error file that prints out is decided on these values
		strcpy(u[*l].localval,localval);
		letval = strtok(line,".");
		
		if(letval != NULL){
			u[*l].a = atoi(letval); 
			if(u[*l].a>255 || u[*l].a<0){
				u[*l].x=true;
			}
		}
		letval = strtok(NULL,".");
		if(letval != NULL){
			u[*l].b = atoi(letval);
			if(u[*l].b>255 || u[*l].b<0){
				u[*l].x=true;
			}
		}
		//values that are over 255 will be stored in the error file
		letval = strtok(NULL,".");
		if(letval != NULL){
			u[*l].c = atoi(letval);
			if(u[*l].c>255 || u[*l].c<0){
				u[*l].x=true;
			}
		}
		letval = strtok(NULL,".");
		if(letval != NULL){
			u[*l].d = atoi(letval);
			if(u[*l].d>255 || u[*l].d<0){
				u[*l].x=true;
			}
		}

		if(u[*l].x == true){
			fprintf(erval, "%i.%i.%i.%i ", u[*l].a, u[*l].b, u[*l].c, u[*l].d);
			fprintf(erval, "%s", &u[*l].localval);
			fprintf(erval, "\n");
		}

		*l = *l + 1;
	}
	//the file would close after each error was stored inside

	fclose(erval);
	fclose(m);
	return u;
}

int get_unique_locality(int valloc_o[100][2],address_t *data,int l){
	int i,j,c=0;
	int a,b;
	int st;
	for(i=0;i<l;i++){
		a = data[i].a;
		b = data[i].b;
		st = 0;
		if(data[i].x != true){
			for(j = 0;j<c;j++){
			if(valloc_o[j][0] == a && valloc_o[j][1] == b){
				st = 1;
				break;
			}
			}
			if(st == 0){
			valloc_o[c][0] = a;
			valloc_o[c][1] = b;
			c++;
			}
		}
	}
	//the locality report has true values if it is printed 

	return c;
}

void generate_locality_report(address_t *data,int l,int valloc_o[100][2],int upval,char *user){
	FILE *m;
	m = fopen("CS222_Locality_Report.txt","w");
	if(m == NULL){
		printf("Error opening file.");
		exit(-1);
	}
	//if the report is correct and the file was used correctly, the locality report prints
	char* time = getDateAndTime();
	fprintf(m,"%s %s",user,time);
	fprintf(m,"%s","CS222 Network Locality Report");
	int i,j;
	for(i = 0;i<upval;i++){
		fprintf(m,"\n\n%d.%d\n",valloc_o[i][0],valloc_o[i][1]);
		for(j = 0;j<l;j++){
		if(data[j].a == valloc_o[i][0] && data[j].b == valloc_o[i][1]){
			fprintf(m,"\n%s",data[j].localval);
		}
		}
	}
	fclose(m);
}
//swap uses each data value and inputs it into its respective counterpart
void swap(address_t *infoswitch1,address_t *infoswitch2){
	address_t u;
	strcpy(u.localval,infoswitch1->localval);
	u.a = infoswitch1->a;
	u.b = infoswitch1->b;
	u.c = infoswitch1->c;
	u.d = infoswitch1->d;
	infoswitch1->a = infoswitch2->a;
	infoswitch1->b = infoswitch2->b;
	infoswitch1->c = infoswitch2->c;
	infoswitch1->d = infoswitch2->d;
	strcpy(infoswitch1->localval,infoswitch2->localval);
	infoswitch2->a = u.a;
	infoswitch2->b = u.b;
	infoswitch2->c = u.c;
	infoswitch2->d = u.d;
	strcpy(infoswitch2->localval,u.localval);
}
//the alias sort has char values of 0 inputted
void sortByAlias(address_t *data,int l){
	int i,j;
	for(i=0;i<l;i++){
		for(j = i+1;j<l;j++){
		if(strcmp(data[i].localval,data[j].localval) > 0){
			swap(&data[i],&data[j]);
			
			//the loop ends when strcmp has no output
			
		}
		}
	}
}

//main function prints out everything that was coded on top
int main(){
	address_t *data_eval;
	int l = 0;
	int valloc_o[100][2];
	int upval;
	char *user = (char *)malloc(sizeof(char)*100);
	printf("\nEnter User Name: ");
	fgets(user,100,stdin);
	user[strlen(user)-1] = '\0';
	data_eval = read_data_file(&l, user);
	upval = get_unique_locality(valloc_o,data_eval,l);
	generate_locality_report(data_eval,l,valloc_o,upval,user);
}