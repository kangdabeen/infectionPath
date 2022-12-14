//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2

int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    
    int i;
    int num;
    int pnum = ifctdb_len();
    int anum = ifctdb_len();
    
    char place;
    int max_age; 
	int min_age;
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    
    //1-2. loading each patient informations
    while ( 3 == (fscanf(fp, "%d %d %d", &pIndex, &age, &time)))
    {
    	for (i=0; i<5; i++) 
		{
			fscanf(fp, "%d", &placeHist[i]);
		}
		ifct_element = ifctele_genElement(pIndex, age, time, placeHist);
		
		ifctdb_addTail(ifct_element);
	}
	
    
    //1-3. FILE pointer close
    fclose(fp);
    
    {
    	int place1, place2;
    	
		place1 = 3;
    	place2 = 15;
    	
    	printf("The first place is %s\n", ifctele_getPlaceName(place1)) ;
    	printf("The second place is %s\n", ifctele_getPlaceName(place2)) ;
	}
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
        
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                
                break;
                
            case MENU_PATIENT:			
                printf("Patient index : ");
                scanf("%d", &num);
            
                if (pIndex > num)
                {
                	ifctele_printElement (ifctdb_getData(num));
				}
                
                break;
                
            case MENU_PLACE:
                printf("Place name : ");
                scanf("%s", &place);
                
                for (i=0; i<100; i++)
                {
                	if (strcmp(place, ifctele_getPlaceName(ifctele_getHistPlaceIndex(ifctdb_getData(i), N_HISTORY-1))) == 0)
                	
                	ifctele_printElement(ifctdb_getData(i));
                	
                	else pnum --;
				}
                
                break;
                
            case MENU_AGE:
                printf("max age : ");
                scanf("%d", &max_age);
                
                printf("min age : ");
                scanf("%d", &min_age);
                
                for (i=0; i<5; i++)
                {
                	if(min_age <= ifctele_getAge(ifctdb_getData(i)) && max_age >= ifctele_getAge(ifctdb_getData(i)))
                	
                	ifctele_printElement(ifctdb_getData(i));
                	
                	else anum --;
				}
                
                break;
                
            case MENU_TRACK:
            	printf("Index : ");
            	scanf("%d", &pIndex);
            	
            	
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}

int pIndex;

present_patient = pIndex;

while (present_patient = who) ;
{
	spreader = trackInfecter(present_patient);
	
	if(spreader = present_patient)
	printf ("%i patient is infected by %i patient. \n", present_patient, spreader);
	
	else
	first_spreader = present_patient;
	present_patient = spreader;
}

int trackInfecter()
{
	int meettime;
	
	meettime = isMet(present_patient, i);
	if (meettime > 0)
	{
		if (meettime < 0 )
		{
			spreader = i;
		}
	}
	return spreader;
}


int isMet(a_patient, int b_patient)
{
	for (i=2; i<N_HISTORY; i++)
	
	return meettime;
}

int convertTimeToIndex(int time, int infectedTime)
{
	int index = -1;
	
	if (time <= infectedTime && time > infectedTime - N_HISTORY)
	{
		index = N_HISTORY - (infectedTime - time) - 1;
	}
	return index;
}



