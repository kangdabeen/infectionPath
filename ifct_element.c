//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};


typedef struct ifs_ele {
	int index;	//번호 정수  
	int age;	//나이 정수 
	int detected_time;	//감염시점 정수   
	int place_h[N_HISTORY];	//감염직전 이동경로 장소  enum 배열 선언 구조체 선언하고 정수배열 사이즈는 N_HISTORY 
} ifs_ele_t;
	
	// linked list 활용   database.c에 들어있다. 
	
	
void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
{
	ifs_ele_t* ptr = NULL;
	ptr = (ifs_ele_t*)malloc(sizeof(ifs_ele_t));
	
	ptr-> index = index; 
	ptr-> age = age;
	ptr-> detected_time = detected_time;
	
	int i;
	for (i=0; i<N_HISTORY; i++)
	ptr->place_h[i] = history_place[i];
	
	return ptr; 
}

	
	
int ifctele_getAge(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;  
	
	return ptr -> age; 
}

int ifctele_getHistPlaceIndex(void* obj, int index)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr -> place_h[index];
}


unsigned int ifctele_getinfestedTime(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr -> detected_time;
}


void ifctele_printElement(void *obj)
{	
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
		
	printf("Index : %i\n", ptr-> index);//pirnt elements
	printf("Age : %i\n", ptr->age);
	printf("Detected_time : %i\n", ptr->detected_time);
	printf("Infection path : \n");
	
	int i;
	for (i=0; i<5; i++)
	{
		printf("%s", ifctele_getPlaceName);
	}		
} 


char* ifctele_getPlaceName (int placeIndex)
{
	return countryName [placeIndex];
}





	
