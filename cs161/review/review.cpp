artA.cpp
 * ** Author: Shuhuai Wang
 *  * ** Date: 05/12/2019
 *   * ** Description:Homework 4 Part A
 *    * ******************************************************/
 
#include<iostream>
#include<string>
 
 using namespace std;
 
 int chance(int a){
    	a = a + 1;
		return a;
		 }//record player chance.

int rule (int c){
   	cout << "Game Begin!" << endl;
		cout << "This is a 5 letter-long word." << endl;
			cout << "You have 6 times to guess this word." << endl;
}//show the rules

int main(){
   	int b = 0,c;
		int p,o,u,t;
			char s1[6] = "-----";
				string s2;
					char s3[50];
						int a;
							rule(c);
								do{
								   		cout << "Please enter letter to guess this word." << endl;
												cin >> s2;
														for ( int i = 0; i < s2.length(); i++){
														   			if ( s2[i] == 'H' || s2[i] == 'h'){
																	   				s1[0] = 'H';
																									p = 1;
																												}
																				if ( s2[i] == 'e' || s2[i] == 'E'){
																				   				s1[1] = 'e';
																												o = 1;
																															}
																							if ( s2[i] == 'l' || s2[i] =='L'){
																							   				s1[2] = 'l';
																															s1[3] = 'l';
																																			u = 1;
																																						}
																										if ( s2[i] == 'o' || s2[i] == 'O'){
																										   				s1[4] = 'o';
																																		t = 1;
																																					}
																													if ( s2[i] != 'H' && s2[i] != 'h' && s2[i] != 'e' && s2[i] != 'l' && s2[i] != 'o' && s2[i] != 'E' && s2[i] != 'L' && s2[i] != 'O'){
																													   				s3[b] = s2[i];
																																					b++;
																																								}
																															}//mha
