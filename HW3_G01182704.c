#include <stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#include<ctype.h>

char *getDateandTime()
{
	static char valar[100];
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	strcpy(valar,asctime(tm)); //This function gets the date and time and prints it out
	return valar;
}
	int getInteger(){
	char valuser[100];
	fgets(valuser, sizeof valuser, stdin);
	int i=atoi(valuser); // This is the first instance of the getter function
	if(valuser[0]=='x'&& !\
	(isdigit(valuser[1])||isalpha\
	(valuser[1])))
	
	{
		return -1; //The return statements will include -1 of there are none being returned
	}
	return i;
}

void decimalToBinary(int decValue,char binString[])
	{
		int numbival[100];
		int binval = 0;
		while (decValue > 0) //Given decimal to binary converter tweaked a little bit
		{
			numbival[binval] = decValue % 2;
			decValue = decValue / 2;
		binval++;
	}
		int valtot=0;
		for (int secval = binval - 1;  // new lines created for the comments to fit
		secval >= 0; secval--)
			binString[valtot++]\
			=numbival[secval]+'0';
}

void decimalToHex(int decValue,char hexString[])
	{
		char numval1[100];

		int compval = 0;
			while(decValue!=0 && decValue!=0)
	{
		int count = 0; //initializing count to 0 for return statement
		count = decValue % 16;
		if(count < 10)
	{
			numval1[compval] = count + 48; //decimal to hex converter used to create string and hex
		compval++;
	}
		else
	{
			numval1[compval] = count + 55;
		compval++;
	}

	decValue = decValue/16;
}
		int upnum=0;
		for(int k = compval-1; k >= 0; k--) //Creating for loop that determines how the 1 will be computed
			hexString[upnum++]=numval1[k];
}
void decimalToOct(int decValue,char octString[]){
	int numto8[100];
	int countval2 = 0;
	int countval = 0;
	while (decValue != 0 && decValue != countval2) 
	//While loop is used to store a countval int into the code
	{
		numto8[countval] = decValue % 8;
		decValue = decValue / 8;
		countval++;
	}
	int kfor=0;
	for (int val2 = countval - 1; val2 >= 0; val2--)
		octString[kfor++]=numto8[val2]+'0';
}

int main()

	{
   		char valoft[100];
   		int val3=0;
   		
		char *binary; // Main function will include this one as the choice
		binary = (char*)malloc((50+50)*sizeof(char));

		char *hex;
		hex = (char*)malloc((50+50)*sizeof(char));

		char *octal;
		octal = (char*)malloc((50+50)*sizeof(char));
		printf("Enter your Name: ");
		char Name[(10+10)]; //value of 20 would be stored that goes from string to integer
		fgets(Name, sizeof Name, stdin);

	do
	{
		printf("Enter an Integer (1-1000000) or type x to exit: ");
		val3=getInteger();
		if(val3==-1){
			printf("Goodbye!\n"); // goodbye is printed with a new line to exit the domain
		break;
	}
		else if(val3<1||val3>1000000){
			printf("Error: %d is out of range\n",val3);
		continue;
}

		decimalToBinary(val3,binary);
		decimalToHex(val3,hex);
		decimalToOct(val3,octal);
		printf("\n");
		printf("Decimal: %d\n",val3);
		printf("Hexadecimal: %s\n",hex);
		printf("Octal: %s\n", octal);
		printf("Binary: %s\n", binary); // Print statements given to print out different computations
		printf("\n");
		printf("Save to file?(y/n):");

		char file[(7+3)];
		fgets(file, (5+5), stdin);
		printf("\n");
		if(file[(10-10)]=='y') // Start of creating a file and saving each element in it
	
	{
		strcpy(valoft,getDateandTime());
		printf("Enter file Name: ");
		
	char fname[100];
		fgets(fname, 100, stdin); // This is the process where a file is written
		int inva=0;
		while (fname[inva] != '\0')
			inva++;
	char file_name[inva-1];
		for(int valval=0;valval<inva-1;valval++)
	
	{
			file_name[valval]=fname[valval];
    }

	FILE *fptr;
	fptr = fopen (file_name, "w");
	if(fptr == NULL) // If a misleading filename is given there will be an error
{
		printf("Error!");
	exit(1);
}
	fprintf(fptr,"Name: %s\n",Name);
	fprintf(fptr,"Today's date: %s\n\n",valoft);
	fprintf(fptr,"Decimal: %d\n",val3);
	fprintf(fptr,"Hexadecimal: %s\n",hex); //Final print statements to convert each number to its corresponding digit
	fprintf(fptr,"Octal: %s\n", octal);
	fprintf(fptr,"Binary: %s\n", binary);
	printf("File Saved.\n\n");
}

}	while(1);
//1 is true so while it is 1 the code should work
		return 0;
}