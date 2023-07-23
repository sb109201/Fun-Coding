#include<iostream>
#include<fstream>
using namespace std;
int main () {
     fstream infile;//create aa object of fstream class
     infile.open("ex.txt", ios::in);
     if (!infile){
         printf("\nError to open the file\n");
         exit (1);
     }
     int n;
     infile>>n; //to read number of vertices from file
     int graph[10][10];
     int i,j;
     for(i=0;i<n;i++){
         for(j=0;j<n;j++){
             infile>>graph[i][j]; //read a graph from file
          }
     }
     for(i=0;i<n;i++){
         for(j=0;j<n;j++){
             printf("%3d",graph[i][j]); //read a graph from file
         }
         printf("\n");
     }
     infile.close (); //to close the file
     return 0;
}
