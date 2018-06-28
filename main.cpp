#include <iostream>
#include <stdlib.h>
using namespace std;
int graph[10][10];

void mutualFriends(int a,int b,int n){
    int mutual[10];
    int j=0;
    for(int i=0;i<n;i++){
        if(graph[a][i] !=0 && graph[b][i]!=0){
            mutual[j++]=i;
        }
    }
    if(j>0){
        cout<<"\nTotal Number of Mutual Friends are : "<<j<<endl;
        cout<<"\nMutual Friends are :";
        for(int i=0;i<j;i++){
                char ch = mutual[i]+65;
            cout<<ch <<"  ";
        }
        cout<<endl;
    }else
        cout<<"No Mutual Friends !!!\n";
}

// Use Recursion with Queue.
void friendLevel(int a,int n){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    visited[a]=true;

    int first[n];
    int second[n];
    int third[n];

    int f=0,s=0,t=0;
    for(int i=0;i<n;i++){
        if(graph[a][i]!=0){
            first[f++]=i;
            visited[i]=true;
        }
    }

    cout<<"\nFirst Level Friends are : ";
    for(int i=0;i<f;i++){
            char ch = first[i]+65;
        cout<<ch<<"  ";
    }
    cout<<"\n";


    for(int i=0;i<f;i++){
        for(int j=0;j<n;j++){
            if(graph[first[i]][j]!=0 && !visited[j]){
                second[s++]=j;
                visited[j]=true;
            }
        }
    }

   if(s>0){
        cout<<"\nSecond Level Friends are : ";
        for(int i=0;i<s;i++){
                char ch = second[i]+65;
            cout<<ch<< " ";
        }
        cout<<"\n";

        for(int i=0;i<s;i++){
            for(int j=0;j<n;j++){
                if(graph[second[i]][j]!=0 && !visited[j]){
                    third[t++]=j;
                    visited[j]=true;
                }
            }
        }

        if(t>0){
            cout<<"\nThird Level Mutual Friends are : ";
            for(int i=0;i<t;i++){
                    char ch = third[i]+65;
                cout<<ch<<"  ";
            }
            cout<<"\n";
        }else{
            cout<<"No THIRD Level Friends..!!";
        }
   }else{
    cout<<"No SECOND or THIRD Level Friends..!!!";
   }
}

void maxMinFriends(int n){

    int c[n];
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0){
                temp++;
            }
        }
        c[i]=temp;
    }

    int maxP=0,minP=0;
    for(int i=1;i<n;i++){
        if(c[i]>c[maxP])
            maxP=i;
        if(c[i]<c[minP])
            minP=i;
    }
    char ch1=maxP+65;
    char ch2=minP+65;
    cout<<"Node Having Maximum Friends are : "<<ch1<<" and number of friends are "<< c[maxP]<<endl;

    cout<<"Node Having Minimum Friends are : "<<ch2<<"and number of friends are "<< c[minP]<<endl;

}
bool visitedDFS[10];
void dfs(int node,int n){
    visitedDFS[node]=true;
    char ch = node+65;
    cout<<ch<<"  ";
    for(int i=0;i<n;i++){
        if(graph[node][i]!=0 && !visitedDFS[i]){
            dfs(i,n);
        }
    }
}

bool visitedBFS[10];
void bfs(int node, int n){
    int queues[n];
    int f=0,r=0;
    queues[r++]=node;
    while(f>r){
        node = queues[f++];
        char ch = node+65;
        cout<<ch<<"  ";
        visitedBFS[node]=true;
        for(int i=0;i<n;i++){
            if(graph[node][i]!=0 && !visitedBFS[i]){
                queues[r++]=i;
            }
        }
    }
}

int main()
{
    cout<<"enter dimension/ Number of persons."<<endl;
    int n;
    cin>>n;
    cout << "enter graph's adjacency matrix, with zero or 1" << endl;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];

    while(1){
    cout<<"\n1. to find the mutual friends of 2 nodes"<<"\n2. 1st level and 2nd level level friends"
    <<"\n3. max num and min number of fiends  \n4. DFS \n5.BFS \n6.Exit"<<endl;
    int ch;
    char a,b;
    cin>>ch;
    switch(ch){
    case 1: cout<<"\nEnter two nodes in CAPS(Starting from A, B, C): "<<endl;
            cin>>a>>b;

            mutualFriends(a-65,b-65,n);
            break;
    case 2: cout<<"Enter a node: ";
            cin>>a;
            friendLevel(a-65,n);
            break;
    case 3: maxMinFriends(n);
            break;
    case 4: cout<<"Enter the starting node: ";
            cin>>a;
            cout<< "DFS Traversal of the given node is : ";
            dfs(a-65,n);
            cout<<"\n";
            break;
    case 5: cout<<"Enter the starting node: ";
            cin>>a;
            cout<<"BFS Traversal of the given node is : ";
            visitedBFS[a-65]=true;
            bfs(a-65,n);
            cout<<"\n";
            break;
    case 6: exit(0);

    default: cout<<"enter correct choice"<<endl;

    }
    }
    return 0;
}
