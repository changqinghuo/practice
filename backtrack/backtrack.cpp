// backtrack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Permulation.h"

int main(int argc, char* argv[])
{
	vector<int> ary;
// 	for(int i=0; i<3; i++)
// 	{
// 		ary.push_back(i);
// 	}
	ary.push_back(1);
	ary.push_back(1);
	ary.push_back(2);
	ary.push_back(2);
	
	Permulation per(ary);
	per.Run();
	printf("Hello World!\n");
	return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// 
// // Fake boolean values
// #define TRUE    (1)
// #define FALSE   (0)
// 
// // Candidates used at every recursive call
// #define MAX_CANDIDATES 2
// 
// // Define the "bool" type using "short int"
// typedef short int  BOOL;
// static BOOL finished = FALSE;
// 
// bool reject(int* curr_sol, int curr_sol_size, int input) {
//     return FALSE; // EMPTY for now
// }
// 
// bool accept(int* curr_sol, int curr_sol_size, int input) {
//     return (curr_sol_size == input);
// }
// 
// void output(int* curr_sol, int curr_sol_size, int input) {
//     static int i;
//     printf("[ ");
//     for ( i = 1; i <= curr_sol_size; ++i ) {
//         printf("%d ", i);
//     }
//     printf("]\n");
// }
// 
// void extend_solution(int* curr_sol, int curr_sol_size, int input, int* candidates, int* num_candidates) {
// //     // Only 2 possibilities: the element is take or not taken
// //     candidates[0] = TRUE;
// //     candidates[1] = FALSE;
// //     *num_candidates = 2;
// 	bool* res = new bool[input];
// 	for(int i=1; i <= input; i++)
// 	{		
// 		res[i] = false;
// 	}
// 
// 	for(int j=1; j<=curr_sol_size; j++)
// 	{
// 		res[curr_sol[j]] = true;
// 	}
// 	 int count = 0;
// 	 
// 	 for(int k=1; k <=input; k++)
// 	 {
// 		 if(!res[k])
// 		 {
// 			 candidates[count++] = k;
// 		 }
// 	 }
// 	 *num_candidates = count;
// 
// 
// 
// }
// 
// void make_move(int *curr_sol, int curr_sol_size, int input) {
//     // EMPTY for now
// }
// 
// void revert(int *curr_sol, int curr_sol_size, int input) {
//     // EMPTY for now
// }
// 
// void backtrack(int *curr_sol, int curr_sol_size, int input) {
//    
// 	
//     if ( reject(curr_sol, curr_sol_size, input) ) {
//         return; // Not worth completing
//     }
//     
//     if ( accept(curr_sol, curr_sol_size, input) ) {
//         output(curr_sol, curr_sol_size, input); // Found! Print it
//     } else {
//         ++curr_sol_size; // Increase solution size
// 		int* candidates = new int[input+1];
// 		int num_candidates;
// 		int i;
//         
//         // Generate solution extension
//         extend_solution(curr_sol, curr_sol_size, input, candidates, &num_candidates);
//         // Try every candidates just generated
//         for ( i = 0; i < num_candidates; ++i ) {
//             curr_sol[curr_sol_size] = candidates[i];
//             
//             make_move(curr_sol, curr_sol_size, input);
//             
//             backtrack(curr_sol, curr_sol_size, input);
//             
//             revert(curr_sol, curr_sol_size, input);
//             
//             if ( finished ) return; // Early termination
//         }
// 		delete[] candidates;
//     }
// }
// 
// void print_all_subset_from_1_to(int n) {
//     int *sol= new int[n+1];
//      
//     backtrack(sol, 0, n);
//     delete[]  sol;
// }
// 
// int main(int argc, char** argv) {
//     int input = 4;
//     //if ( argc == 2 ) input = atoi(argv[1]); else return (EXIT_FAILURE);    
// 
//     print_all_subset_from_1_to(input);
// 	return 0;
// }